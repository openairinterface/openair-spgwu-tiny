################################################################################
# SPDX-License-Identifier: LicenseRef-CSSL-1.0
################################################################################
cmake_minimum_required (VERSION 3.0.2)
# Override options for SPGW
set (  PACKAGE_NAME                    "S/P-GW-U" )
set (  STATIC_LINKING                   False )
#############################################
# Base directories, compatible with legacy OAI building
################################################
set (OPENAIRCN_DIR   $ENV{OPENAIRCN_DIR})
set (BUILD_TOP_DIR   ${OPENAIRCN_DIR}/build)
set (SRC_TOP_DIR     $ENV{OPENAIRCN_DIR}/src)

################################################
# For common-src usage
################################################
set (  NF_TARGET                        spgwu )
set (  MOUNTED_COMMON                   common-src)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../src/oai_spgwu/CMakeLists.txt)

ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/../../src/spgwu ${CMAKE_CURRENT_BINARY_DIR}/spgw_u)
