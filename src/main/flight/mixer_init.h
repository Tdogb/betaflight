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

#include "platform.h"

#include "flight/mixer.h"


typedef struct mixerRuntime_s {
    uint8_t motorCount;
    motorMixer_t currentMixer[MAX_SUPPORTED_MOTORS];
#ifdef USE_LAUNCH_CONTROL
    motorMixer_t launchControlMixer[MAX_SUPPORTED_MOTORS];
#endif
    bool feature3dEnabled;
    float motorOutputLow;
    float motorOutputHigh;
    float disarmMotorOutput;
    float deadbandMotor3dHigh;
    float deadbandMotor3dLow;
#ifdef USE_DYN_IDLE
    float dynIdleMaxIncrease;
    float idleThrottleOffset;
    float dynIdleMinRps;
    float dynIdlePGain;
    float prevMinRps;
    float dynIdleIGain;
    float dynIdleDGain;
    float dynIdleI;
    float minRpsDelayK;
#endif
#if defined(USE_BATTERY_VOLTAGE_SAG_COMPENSATION)
    float vbatSagCompensationFactor;
    float vbatFull;
    float vbatRangeToCompensate;
#endif
#if defined(USE_RPM_LIMITER)
    float rpm_limiterExpectedThrottleLimit;
    float rpm_limiterAccelerationLimit;
    float rpm_limiterDecelerationLimit;
    float prevAverageRPM;
    float rpm_limiterPreviousSmoothedRPMError;
    float minRPMDelayK;
    float rpm_limiterI;
    float rpm_limiterPGain;
    float rpm_limiterIGain;
    float rpm_limiterDGain;
    float rpm_limiterPreviousSmoothedRPM;
    float rpm_limiterPreviousRPMLimit;
    float rpm_limiterDelayK;
    float rpm_limiterLearningThrottleK;
    bool rpm_limiter_init;
#endif
} mixerRuntime_t;

extern mixerRuntime_t mixerRuntime;
