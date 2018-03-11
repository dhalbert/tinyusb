/**************************************************************************/
/*!
    @file     hal.h
    @author   hathach (tinyusb.org)

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2013, hathach (tinyusb.org)
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    INCLUDING NEGLIGENCE OR OTHERWISE ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    This file is part of the tinyusb stack.
*/
/**************************************************************************/

#ifndef _TUSB_HAL_H_
#define _TUSB_HAL_H_

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------------------------+
// INCLUDES
//--------------------------------------------------------------------+
#include "tusb_option.h"
#include <stdbool.h>
#include <stdint.h>

#include "common/tusb_errors.h"
#include "common/compiler/compiler.h"

//--------------------------------------------------------------------+
// HAL API
//--------------------------------------------------------------------+
/** \ingroup group_mcu
 * \defgroup group_hal Hardware Abtract Layer (HAL)
 * Hardware Abstraction Layer (HAL) is an abstraction layer, between the physical hardware and the tinyusb stack.
 * Its function is to hide differences in hardware from most of MCUs, so that most of the stack code does not need to be changed to
 * run on systems with a different MCU.
 * HAL are sets of routines that emulate some platform-specific details, giving programs direct access to the hardware resources.
 *  @{ */

/** \brief    Initialize USB controller hardware
 * \returns   true if succeedded
 * \note      This function is invoked by \ref tusb_init as part of the initialization.
 */
bool tusb_hal_init(void);

/** \brief 			Enable USB Interrupt on a specific USB Controller
 * \param[in]		port	is a zero-based index to identify USB controller's ID
 * \note        Some MCUs such as NXP LPC43xx has multiple USB controllers. It is necessary to know which USB controller for
 *              those MCUs.
 */
void tusb_hal_init_enable(uint8_t port);

/** \brief 			Disable USB Interrupt on a specific USB Controller
 * \param[in]		port	is a zero-based index to identify USB controller's ID
 * \note        Some MCUs such as NXP LPC43xx has multiple USB controllers. It is necessary to know which USB controller for
 *              those MCUs.
 */
void tusb_hal_init_disable(uint8_t port);

uint32_t tusb_hal_tick_get(void);

// for debug only, halt mcu if assert/verify is failed if debugger is attached
void tusb_hal_dbg_breakpoint(void) ATTR_WEAK;

#ifdef __cplusplus
 }
#endif

#endif /* _TUSB_HAL_H_ */

/** @} */