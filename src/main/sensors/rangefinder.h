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

#pragma once

#include "pg/pg.h"
#include "drivers/rangefinder/rangefinder.h"


typedef enum {
    RANGEFINDER_NONE        = 0,
    RANGEFINDER_HCSR04      = 1,
    RANGEFINDER_TFMINI      = 2,
    RANGEFINDER_TF02        = 3,
} rangefinderType_e;

typedef struct rangefinderConfig_s {
    uint8_t rangefinder_hardware;
    uint8_t rangefinder_busType;
    // uint8_t rangefinder_spi_device;
    // ioTag_t rangefinder_spi_csn;                   // Also used as XCLR (positive logic) for BMP085
    uint8_t rangefinder_i2c_device;
    uint8_t rangefinder_i2c_address;
    // uint8_t rangefinder_hardware;                  // rangefindermeter hardware to use
    // ioTag_t rangefinder_eoc_tag;
    // ioTag_t rangefinder_xclr_tag;
} rangefinderConfig_t;

PG_DECLARE(rangefinderConfig_t, rangefinderConfig);

typedef struct rangefinder_s {
    rangefinderDev_t dev;
    float altitude;
    int32_t temperature;                    // Use temperature for telemetry
    int32_t humidity;   
} rangefinder_t;

extern rangefinder_t rangefinder;
void rangefinderInit(void);

int32_t rangefinderGetLatestHumidity(void);
int32_t rangefinderGetLatestTemperature(void);

uint32_t rangefinderUpdate(timeUs_t currentTimeUs);
bool rangefinderIsHealthy(void);