/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */

/*! \file spgwu_app.hpp
   \author  Lionel GAUTHIER
   \date 2018
   \email: lionel.gauthier@eurecom.fr
*/

#ifndef FILE_SPGWU_APP_HPP_SEEN
#define FILE_SPGWU_APP_HPP_SEEN

#include "common_root_types.h"

#include "itti_msg_sxab.hpp"
#include "itti_msg_s1u.hpp"

#include <boost/atomic.hpp>

#include <map>
#include <string>
#include <thread>
#include <memory>
#include <map>
#include <set>

namespace spgwu {

class spgwu_app {
 private:
  std::thread::id thread_id;
  std::thread thread;

 public:
  explicit spgwu_app(const std::string& config_file);
  ~spgwu_app();
  spgwu_app(spgwu_app const&) = delete;
  void operator=(spgwu_app const&) = delete;

  teid_t generate_s5s8_up_teid();

  void handle_itti_msg(std::shared_ptr<itti_s1u_echo_request> m);

  //  void handle_itti_msg (itti_sxab_heartbeat_request& m);
  //  void handle_itti_msg (itti_sxab_heartbeat_response& m);
  //  void handle_itti_msg (itti_sxab_pfcp_pfd_management_request& m);
  //  void handle_itti_msg (itti_sxab_pfcp_pfd_management_response& m);
  //  void handle_itti_msg (itti_sxab_pfcp_association_setup_request& m);
  //  void handle_itti_msg (itti_sxab_pfcp_association_setup_response& m);
  //  void handle_itti_msg (itti_sxab_pfcp_association_update_request& m);
  //  void handle_itti_msg (itti_sxab_pfcp_association_update_response& m);
  //  void handle_itti_msg (itti_sxab_pfcp_association_release_request& m);
  //  void handle_itti_msg (itti_sxab_pfcp_association_release_response& m);
  //  void handle_itti_msg (itti_sxab_pfcp_version_not_supported_response& m);
  //  void handle_itti_msg (itti_sxab_pfcp_node_report_request& m);
  //  void handle_itti_msg (itti_sxab_pfcp_node_report_response& m);
  void handle_itti_msg(
      std::shared_ptr<itti_sxab_session_establishment_request> m);
  void handle_itti_msg(
      std::shared_ptr<itti_sxab_session_modification_request> m);
  void handle_itti_msg(std::shared_ptr<itti_sxab_session_deletion_request> m);
  //  void handle_itti_msg (itti_sxab_session_deletion_response& m);
  //  void handle_itti_msg (itti_sxab_session_report_request& m);
  void handle_itti_msg(std::shared_ptr<itti_sxab_session_report_response> m);
};
}  // namespace spgwu
#endif /* FILE_SPGWU_APP_HPP_SEEN */
