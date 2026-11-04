################################################################################
# SPDX-License-Identifier: LicenseRef-CSSL-1.0
################################################################################
include_directories(${SRC_TOP_DIR}/common)
include_directories(${SRC_TOP_DIR}/common/msg)
include_directories(${SRC_TOP_DIR}/common/utils)
include_directories(${SRC_TOP_DIR}/itti)
include_directories(${SRC_TOP_DIR}/gtpv1u)
include_directories(${SRC_TOP_DIR}/gtpv2c)
include_directories(${SRC_TOP_DIR}/oai_spgwu)
include_directories(${SRC_TOP_DIR}/pfcp)
include_directories(${SRC_TOP_DIR}/spgwu)
include_directories(${SRC_TOP_DIR}/udp)
include_directories(${SRC_TOP_DIR}/${MOUNTED_COMMON}/logger)

add_library (SPGW_SWITCH STATIC
  pfcp_far.cpp
  pfcp_pdr.cpp
  pfcp_session.cpp
  pfcp_switch.cpp
  spgwu_s1u.cpp
  )
  
