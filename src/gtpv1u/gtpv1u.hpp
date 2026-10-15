/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */

/*! \file gtpv1u.hpp
  \brief
  \author Lionel Gauthier
  \company Eurecom
  \email: lionel.gauthier@eurecom.fr
*/
#ifndef FILE_GTPV1U_HPP_SEEN
#define FILE_GTPV1U_HPP_SEEN

#include "3gpp_29.281.hpp"
#include "itti.hpp"
#include "msg_gtpv1u.hpp"
#include "thread_sched.hpp"
#include "udp.hpp"

#include <iostream>
#include <map>
#include <memory>
#include <stdint.h>
#include <string>
#include <system_error>
#include <thread>
#include <utility>
#include <vector>

namespace gtpv1u {

static const uint16_t default_port = 2152;

class gtpu_l4_stack : public udp_application {
#define GTPV1U_T3_RESPONSE_MS 1000
#define GTPV1U_N3_REQUESTS 5
#define GTPV1U_PROC_TIME_OUT_MS                                                \
  ((GTPV1U_T3_RESPONSE_MS) * (GTPV1U_N3_REQUESTS + 1))

 protected:
  uint32_t id;
  bool send_ext_hdr;
  udp_server udp_s;

  // seems no need for std::atomic_uint32_t
  uint32_t seq_num;
  uint32_t restart_counter;

  static bool check_initial_message_type(const uint8_t initial);
  static bool check_triggered_message_type(
      const uint8_t initial, const uint8_t triggered);

  uint32_t get_next_seq_num();

 public:
  static const uint8_t version = 1;
  gtpu_l4_stack(
      const struct in_addr& address, const uint16_t port_num,
      const util::thread_sched_params& sched_params, const bool send_ext_hdr);
  gtpu_l4_stack(
      const struct in6_addr& address, const uint16_t port_num,
      const util::thread_sched_params& sched_params, const bool send_ext_hdr);
  gtpu_l4_stack(
      char* ip_address, const uint16_t port_num,
      const util::thread_sched_params& sched_params, const bool send_ext_hdr);
  virtual void handle_receive(
      char* recv_buffer, const std::size_t bytes_transferred,
      const endpoint& r_endpoint);
  void handle_receive_message_cb(
      const gtpv1u_msg& msg, const struct sockaddr_storage& r_endpoint,
      const socklen_t& r_endpoint_addr_len, const task_id_t& task_id,
      bool& error, uint64_t& gtpc_tx_id);

  void send_g_pdu(
      const struct sockaddr_in& peer_addr, const teid_t teid,
      const char* payload, const ssize_t payload_len, uint8_t qfi);
  void send_g_pdu(
      const struct sockaddr_in6& peer_addr, const teid_t teid,
      const char* payload, const ssize_t payload_len);

  void send_response(const gtpv1u_echo_response& gtp_ies);
  void send_indication(const gtpv1u_error_indication& gtp_ies);
  void stop() { udp_s.stop(); };
};
}  // namespace gtpv1u

#endif /* FILE_GTPV1U_HPP_SEEN */
