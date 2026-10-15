################################################################################
# SPDX-License-Identifier: LicenseRef-CSSL-1.0
################################################################################
set(ITTI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/itti)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/itti)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/msg)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

add_library(3GPP_COMMON_TYPES STATIC
)


