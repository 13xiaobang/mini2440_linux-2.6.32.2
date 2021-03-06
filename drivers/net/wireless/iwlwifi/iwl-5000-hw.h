/******************************************************************************
 *
 * This file is provided under a dual BSD/GPLv2 license.  When using or
 * redistributing this file, you may do so under either license.
 *
 * GPL LICENSE SUMMARY
 *
 * Copyright(c) 2007 - 2009 Intel Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110,
 * USA
 *
 * The full GNU General Public License is included in this distribution
 * in the file called LICENSE.GPL.
 *
 * Contact Information:
 *  Intel Linux Wireless <ilw@linux.intel.com>
 * Intel Corporation, 5200 N.E. Elam Young Parkway, Hillsboro, OR 97124-6497
 *
 * BSD LICENSE
 *
 * Copyright(c) 2005 - 2009 Intel Corporation. All rights reserved.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name Intel Corporation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *****************************************************************************/
/*
 * Please use this file (iwl-5000-hw.h) only for hardware-related definitions.
 * Use iwl-5000-commands.h for uCode API definitions.
 */

#ifndef __iwl_5000_hw_h__
#define __iwl_5000_hw_h__

#define IWL50_RTC_INST_LOWER_BOUND		(0x000000)
#define IWL50_RTC_INST_UPPER_BOUND		(0x020000)

#define IWL50_RTC_DATA_LOWER_BOUND		(0x800000)
#define IWL50_RTC_DATA_UPPER_BOUND		(0x80C000)

#define IWL50_RTC_INST_SIZE (IWL50_RTC_INST_UPPER_BOUND - \
				IWL50_RTC_INST_LOWER_BOUND)
#define IWL50_RTC_DATA_SIZE (IWL50_RTC_DATA_UPPER_BOUND - \
				IWL50_RTC_DATA_LOWER_BOUND)

/* EEPROM */
#define IWL_5000_EEPROM_IMG_SIZE			2048

#define IWL50_CMD_FIFO_NUM                 7
#define IWL50_NUM_QUEUES                  20
#define IWL50_NUM_AMPDU_QUEUES		  10
#define IWL50_FIRST_AMPDU_QUEUE		  10

/* 5150 only */
#define IWL_5150_VOLTAGE_TO_TEMPERATURE_COEFF	(-5)

static inline s32 iwl_temp_calib_to_offset(struct iwl_priv *priv)
{
	u16 *temp_calib = (u16 *)iwl_eeprom_query_addr(priv,
						       EEPROM_5000_TEMPERATURE);
	/* offset =  temperature -  voltage / coef */
	s32 offset = (s32)(temp_calib[0] - temp_calib[1] / IWL_5150_VOLTAGE_TO_TEMPERATURE_COEFF);
	return offset;
}

/* Fixed (non-configurable) rx data from phy */

/**
 * struct iwl5000_schedq_bc_tbl scheduler byte count table
 * 	base physical address of iwl5000_shared
 * 	is provided to SCD_DRAM_BASE_ADDR
 * @tfd_offset  0-12 - tx command byte count
 *	       12-16 - station index
 */
struct iwl5000_scd_bc_tbl {
	__le16 tfd_offset[TFD_QUEUE_BC_SIZE];
} __attribute__ ((packed));


#endif /* __iwl_5000_hw_h__ */

