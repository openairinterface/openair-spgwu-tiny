################################################################################
# SPDX-License-Identifier: LicenseRef-CSSL-1.0
################################################################################
add_library(GTPV1U STATIC
    3gpp_29.281.cpp
    gtpv1u.cpp
    )

include_directories(${SRC_TOP_DIR}/common)
include_directories(${SRC_TOP_DIR}/common/msg)
include_directories(${SRC_TOP_DIR}/common/utils)
include_directories(${SRC_TOP_DIR}/itti)
include_directories(${SRC_TOP_DIR}/gtpv1u)
include_directories(${SRC_TOP_DIR}/udp)
include_directories(${SRC_TOP_DIR}/${MOUNTED_COMMON}/logger)
