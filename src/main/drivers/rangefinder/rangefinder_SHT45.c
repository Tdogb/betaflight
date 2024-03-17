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

#include "platform.h"
#ifndef USE_RANGEFINDER_TF
#define USE_RANGEFINDER_TF
#endif


#include "build/debug.h"
#include "build/build_config.h"

#include "drivers/time.h"
#include "drivers/rangefinder/rangefinder.h"
#include "drivers/rangefinder/rangefinder_SHT45.h"
#include <string.h>
#include "common/utils.h"

#include "drivers/io.h"
#include "drivers/bus.h"
#include "drivers/bus_spi.h"
#include "drivers/time.h"
#include "drivers/resource.h"
#include "build/debug.h"
#include "common/crc.h"
#include "common/maths.h"

#define SHT4x_DEFAULT_ADDR 0x44 /**< SHT4x I2C Address */
#define SHT4x_NOHEAT_HIGHPRECISION                                             \
  0xFD /**< High precision measurement, no heater */
#define SHT4x_NOHEAT_MEDPRECISION                                              \
  0xF6 /**< Medium precision measurement, no heater */
#define SHT4x_NOHEAT_LOWPRECISION                                              \
  0xE0 /**< Low precision measurement, no heater */

#define SHT4x_HIGHHEAT_1S                                                      \
  0x39 /**< High precision measurement, high heat for 1 sec */
#define SHT4x_HIGHHEAT_100MS                                                   \
  0x32 /**< High precision measurement, high heat for 0.1 sec */
#define SHT4x_MEDHEAT_1S                                                       \
  0x2F /**< High precision measurement, med heat for 1 sec */
#define SHT4x_MEDHEAT_100MS                                                    \
  0x24 /**< High precision measurement, med heat for 0.1 sec */
#define SHT4x_LOWHEAT_1S                                                       \
  0x1E /**< High precision measurement, low heat for 1 sec */
#define SHT4x_LOWHEAT_100MS                                                    \
  0x15 /**< High precision measurement, low heat for 0.1 sec */

#define SHT4x_READSERIAL 0x89 /**< Read Out of Serial Register */
#define SHT4x_SOFTRESET 0x94  /**< Soft Reset */

static uint8_t buf[6];
static float temperature = 0;
static float humidity = 0;

static void sht45StartUP(rangefinderDev_t *rangefinder)
{
  if (busBusy(&rangefinder->dev, NULL)) {
  } else {
    busReadRegisterBufferStart(&rangefinder->dev, 0xFD, buf, 6);
  }
}

static bool sht45ReadUP(rangefinderDev_t *rangefinder) {
  UNUSED(rangefinder);
  return true;
}

#define POLYGEN_SHT 0x31

static uint8_t CRC8_SHT(const uint8_t *data, const int8_t len)
{
    uint8_t crc = 0xFF; /* start with 0 so first byte can be 'xored' in */
    uint8_t currByte;

    for (int i = 0 ; i < len ; i++) {
        currByte = data[i];

        crc ^= currByte; /* XOR-in the next input byte */

        for (int i = 0; i < 8; i++) {
            if ((crc & 0x80) != 0) {
                crc = (uint8_t)((crc << 1) ^ POLYGEN_SHT);
            } else {
                crc <<= 1;
            }
        }
    }
    return crc;
}

static bool sht45GetUP(rangefinderDev_t *rangefinder) {
  UNUSED(rangefinder);
  // static uint8_t test_buf[] = {0xBE,0xEF}; //should equal 0x92=146
  // DEBUG_SET(DEBUG_RANGEFINDER, 3, CRC8_SHT(test_buf,2));
  DEBUG_SET(DEBUG_RANGEFINDER, 0, buf[0]);
  DEBUG_SET(DEBUG_RANGEFINDER, 1, buf[1]);
  DEBUG_SET(DEBUG_RANGEFINDER, 2, buf[2]);
  DEBUG_SET(DEBUG_RANGEFINDER, 3, 69);
  if (buf[2] != CRC8_SHT(buf, 2) ||
      buf[5] != CRC8_SHT(buf + 3, 2))
    // DEBUG_SET(DEBUG_RANGEFINDER, 0, -1);
    return false;
  float t_ticks = (uint16_t)buf[0] * 256 + (uint16_t)buf[1];
  float rh_ticks = (uint16_t)buf[3] * 256 + (uint16_t)buf[4];
  temperature = -45 + 175 * t_ticks / 65535;
  humidity = -6 + 125 * rh_ticks / 65535;

  humidity = MIN(MAX(humidity, 0.0f), 100.0f);
  return true;
}

static void deviceCalculate(int32_t *_humidity, int32_t *_temperature) {
  static uint16_t i_count = 0;
  i_count++;
  if (humidity) {
    *_humidity = humidity;
  }
  if (temperature) {
    *_temperature = temperature;
  }
  DEBUG_SET(DEBUG_RANGEFINDER, 3, i_count);
  // DEBUG_SET(DEBUG_RANGEFINDER, 2, humidity);
  // DEBUG_SET(DEBUG_RANGEFINDER, 3, temperature);
}

static bool deviceConfigure(const extDevice_t *dev)
{
  UNUSED(dev);
  return true;
}

#define DETECTION_MAX_RETRY_COUNT   5
static bool deviceDetect(const extDevice_t *dev)
{
    UNUSED(dev);
    for (int retry = 0; retry < DETECTION_MAX_RETRY_COUNT; retry++) {
        busRawWriteRegister(dev,0x94,0);
    //     uint8_t chipId[1];
        delay(100);

    //     bool ack = busReadBuf(dev, SHT4x_SOFTRESET, chipId, 1);

    //     if (ack && chipId[0] == SHT45_ID_REV_AND_PROD_ID) {
    //         return true;
    //     }
    };
    // // return false;
    // busReadRegisterBuffer
    return true;
}

// static void sht45StartUT(rangefinderDev_t *rangefinder)
// {
//     UNUSED(rangefinder);
// }

// static bool sht45ReadUT(rangefinderDev_t *rangefinder)
// {
//     UNUSED(rangefinder);

//     return true;
// }

// static bool sht45GetUT(rangefinderDev_t *rangefinder)
// {
//     UNUSED(rangefinder);

//     return true;
// }

static void deviceInit(const extDevice_t *dev, resourceOwner_e owner)
{
  UNUSED(dev);
  UNUSED(owner);
}

static void deviceDeInit(const extDevice_t *dev)
{
    UNUSED(dev);
}

bool rangefinderSHT45Detect(rangefinderDev_t *rangefinder)
{
    extDevice_t *dev = &rangefinder->dev;
    deviceInit(&rangefinder->dev, OWNER_RANGEFINDER);

    dev->busType_u.i2c.address = SHT4x_DEFAULT_ADDR;

    if (!deviceDetect(dev)) {
        deviceDeInit(dev);
        return false;
    }

    if (!deviceConfigure(dev)) {
        deviceDeInit(dev);
        return false;
    }

    busDeviceRegister(dev);

    rangefinder->up_delay = 10000; // 0.01s delay
    rangefinder->start_up = sht45StartUP;
    rangefinder->read_up = sht45ReadUP;
    rangefinder->get_up = sht45GetUP;

    rangefinder->calculate = deviceCalculate;

    return true;
}