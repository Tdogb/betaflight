/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#include "platform.h"

#ifndef USE_RANGEFINDER
#define USE_RANGEFINDER
#endif
#ifndef USE_RANGEFINDER_TF
#define USE_RANGEFINDER_TF
#endif

#ifdef USE_RANGEFINDER

#include "build/build_config.h"
#include "build/debug.h"

#include "common/maths.h"
#include "common/time.h"
#include "common/utils.h"

#include "config/config.h"
#include "config/feature.h"

#include "drivers/io.h"
#include "drivers/rangefinder/rangefinder.h"
#include "drivers/rangefinder/rangefinder_SHT45.h"
#include "drivers/time.h"
#include "drivers/bus.h"
#include "drivers/bus_i2c_busdev.h"
#include "drivers/bus_spi.h"
#include "drivers/io.h"

#include "fc/runtime_config.h"

#include "pg/pg.h"
#include "pg/pg_ids.h"

#include "scheduler/scheduler.h"

#include "sensors/sensors.h"
#include "sensors/rangefinder.h"
#include "sensors/battery.h"

rangefinder_t rangefinder;
PG_REGISTER_WITH_RESET_FN(rangefinderConfig_t, rangefinderConfig, PG_RANGEFINDER_CONFIG, 4);

void pgResetFn_rangefinderConfig(rangefinderConfig_t *rangefinderConfig) {
    rangefinderConfig->rangefinder_hardware = 3;
    rangefinderConfig->rangefinder_busType = BUS_TYPE_I2C;
    rangefinderConfig->rangefinder_i2c_device = I2C_DEV_TO_CFG(I2C_DEVICE);
    rangefinderConfig->rangefinder_i2c_address = 0x44;
}

static bool rangefinderDetect(rangefinderDev_t *rangefinderDev, uint8_t num) {
    UNUSED(num);
    extDevice_t *dev = &rangefinderDev->dev;
    i2cBusSetInstance(dev, rangefinderConfig()->rangefinder_i2c_device);
    dev->busType_u.i2c.address = rangefinderConfig()->rangefinder_i2c_address;
    rangefinderSHT45Detect(rangefinderDev);
    sensorsSet(SENSOR_RANGEFINDER);
    return true;
}

static bool rangefinderReady = false;

void rangefinderInit(void) {
    rangefinderReady = rangefinderDetect(&rangefinder.dev, rangefinderConfig()->rangefinder_hardware);
}

typedef enum {
    RANGEFINDER_STATE_HUMIDITY_START,
    RANGEFINDER_STATE_HUMIDITY_READ,
    RANGEFINDER_STATE_HUMIDITY_SAMPLE,
    RANGEFINDER_STATE_COUNT
} rangefinderState_e;

uint32_t rangefinderUpdate(timeUs_t currentTimeUs) {
    static timeUs_t rangefinderStateDurationUs[RANGEFINDER_STATE_COUNT];
    static rangefinderState_e state = RANGEFINDER_STATE_HUMIDITY_START;
    rangefinderState_e oldState = state;
    timeUs_t executeTimeUs;
    timeUs_t sleepTime = 1000; // Wait 1ms between states
    if (busBusy(&rangefinder.dev.dev, NULL)) {
        // If the bus is busy, simply return to have another go later
        schedulerIgnoreTaskStateTime();
        return sleepTime;
    }
    switch (state) {
        default:
        case RANGEFINDER_STATE_HUMIDITY_START:
            rangefinder.dev.start_up(&rangefinder.dev);
            state = RANGEFINDER_STATE_HUMIDITY_READ;
            sleepTime = rangefinder.dev.up_delay;
            break;

        case RANGEFINDER_STATE_HUMIDITY_READ:
            // // if (rangefinder.dev.read_up(&rangefinder.dev)) {
            state = RANGEFINDER_STATE_HUMIDITY_SAMPLE;
            // // } else {
            //     // No action was taken as the read has not completed
            schedulerIgnoreTaskExecTime();
            // // }
            break;

        case RANGEFINDER_STATE_HUMIDITY_SAMPLE:
            if (!rangefinder.dev.get_up(&rangefinder.dev)) {
                // No action was taken as the read has not completed
                schedulerIgnoreTaskExecTime();
                break;
            }

            // update rangefinder data
            rangefinder.dev.calculate(&rangefinder.humidity, &rangefinder.temperature);

            // DEBUG_SET(DEBUG_RANGEFINDER, 1, lrintf(rangefinder.humidity));   
            // DEBUG_SET(DEBUG_RANGEFINDER, 2, rangefinder.temperature);                 // c°C
            // DEBUG_SET(DEBUG_RANGEFINDER, 3, 69);                 

            state = RANGEFINDER_STATE_HUMIDITY_START;
            break;
    }

    // Where we are using a state machine call schedulerIgnoreTaskExecRate() for all states bar one
    if (state != RANGEFINDER_STATE_HUMIDITY_START) {
        schedulerIgnoreTaskExecRate();
    }

    executeTimeUs = micros() - currentTimeUs;

    if (executeTimeUs > rangefinderStateDurationUs[oldState]) {
        rangefinderStateDurationUs[oldState] = executeTimeUs;
    }

    schedulerSetNextStateTime(rangefinderStateDurationUs[state]);

    return sleepTime;
}
bool rangefinderIsHealthy(void) {
    return rangefinderReady;
}

int32_t rangefinderGetLatestHumidity(void) {
    return rangefinder.humidity;
}
int32_t rangefinderGetLatestTemperature(void) {
    return rangefinder.temperature;
}

#endif