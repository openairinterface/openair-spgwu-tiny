/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */

/*! \file 3gpp_commons.h
  \brief
  \author Lionel Gauthier
  \company Eurecom
  \email: lionel.gauthier@eurecom.fr
*/

#ifndef FILE_3GPP_COMMONS_SEEN
#define FILE_3GPP_COMMONS_SEEN

#include <stdint.h>

// 8.2 Recovery
typedef struct recovery_s {
  uint8_t restart_counter;
} recovery_t;

#endif /* FILE_3GPP_COMMONS_SEEN */
