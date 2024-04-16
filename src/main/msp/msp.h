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

#include "common/streambuf.h"

#define MSP_V2_FRAME_ID         255

typedef enum {
    MSP_V1          = 0,
    MSP_V2_OVER_V1  = 1,
    MSP_V2_NATIVE   = 2,
    MSP_VERSION_COUNT
} mspVersion_e;

#define MSP_VERSION_MAGIC_INITIALIZER { 'M', 'M', 'X' }

// return positive for ACK, negative on error, zero for no reply
typedef enum {
    MSP_RESULT_ACK = 1,
    MSP_RESULT_ERROR = -1,
    MSP_RESULT_NO_REPLY = 0,
    MSP_RESULT_CMD_UNKNOWN = -2,   // don't know how to process command, try next handler
} mspResult_e;

typedef enum {
    MSP_DIRECTION_REPLY = 0,
    MSP_DIRECTION_REQUEST = 1
} mspDirection_e;

typedef struct mspPacket_s {
    sbuf_t buf;         // payload only w/o header or crc
    int16_t cmd;
    int16_t result;
    uint8_t flags;      // MSPv2 flags byte. It looks like unused (yet?).
    uint8_t direction;  // It also looks like unused and might be deleted.
} mspPacket_t;

typedef int mspDescriptor_t;

typedef struct _temp_mavlink_tornado_sensors_t
{
 uint32_t time_msec; /*<  Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 uint16_t humidity; /*<  Humidity*/
 uint16_t temp_sht30; /*<  SHT30 Temp*/
 uint32_t static_pressure; /*<  Static Pressure*/
 uint16_t temp_lps; /*<  LPS Temp*/
 uint16_t temp_ds18b20; /*<  DS18B20 Temp*/
 uint32_t diff_pressure_forward; /*<  Diff Pressure Forward*/
 uint16_t temp_forward_ms4425; /*<  MS4425 Forward Temp*/
 uint32_t diff_pressure_up; /*<  Diff Pressure Up*/
 uint16_t temp_up_ms4425; /*<  MS4425 Up Temp*/
 uint32_t diff_pressure_side; /*<  Diff Pressure Side*/
 uint16_t temp_side_ms4425; /*<  MS4425 Side Temp*/
} temp_mavlink_tornado_sensors_t;

temp_mavlink_tornado_sensors_t get_tornado_sensors_msp_storage(void);
struct serialPort_s;
typedef void (*mspPostProcessFnPtr)(struct serialPort_s *port); // msp post process function, used for gracefully handling reboots, etc.
typedef mspResult_e (*mspProcessCommandFnPtr)(mspDescriptor_t srcDesc, mspPacket_t *cmd, mspPacket_t *reply, mspPostProcessFnPtr *mspPostProcessFn);
typedef void (*mspProcessReplyFnPtr)(mspPacket_t *cmd);


void mspInit(void);
mspResult_e mspFcProcessCommand(mspDescriptor_t srcDesc, mspPacket_t *cmd, mspPacket_t *reply, mspPostProcessFnPtr *mspPostProcessFn);
void mspFcProcessReply(mspPacket_t *reply);

mspDescriptor_t mspDescriptorAlloc(void);