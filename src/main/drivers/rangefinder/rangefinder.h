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
#include "common/time.h"

#include "drivers/bus.h" // XXX
#include "drivers/exti.h"
struct rangefinderDev_s;

typedef void (*rangefinderOpFuncPtr)(struct rangefinderDev_s * hum);
typedef bool (*rangefinderOpGetFuncPtr)(struct rangefinderDev_s * hum);
typedef void (*rangefinderCalculateFuncPtr)(int32_t *humidity, int32_t *temperature);

typedef struct rangefinderDev_s {
    extDevice_t dev;
    extiCallbackRec_t exti;
    bool combined_read;
    uint32_t ut_delay;
    uint32_t up_delay;
    rangefinderOpFuncPtr start_ut;
    rangefinderOpGetFuncPtr read_ut;
    rangefinderOpGetFuncPtr get_ut;
    rangefinderOpFuncPtr start_up;
    rangefinderOpGetFuncPtr read_up;
    rangefinderOpGetFuncPtr get_up;
    rangefinderCalculateFuncPtr calculate;
} rangefinderDev_t;

extern int16_t rangefinderMaxRangeCm;
extern int16_t rangefinderMaxAltWithTiltCm;
extern int16_t rangefinderCfAltCm;
