/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */

/*! \file async_shell_cmd.hpp
   \brief We still use some unix commands for convenience, and we did not have
   to replace them by system calls \ Instead of calling C system(...) that can
   take a lot of time (creation of a process, etc), in many cases \ it doesn't
   hurt to do this asynchronously, may be we must tweak thread priority, pin it
   to a CPU, etc (TODO later) \author  Lionel GAUTHIER \date 2017 \email:
   lionel.gauthier@eurecom.fr
*/

#ifndef FILE_ASYNC_SHELL_CMD_HPP_SEEN
#define FILE_ASYNC_SHELL_CMD_HPP_SEEN

#include "itti_msg.hpp"
#include "thread_sched.hpp"
#include <string>
#include <thread>

namespace util {

class async_shell_cmd {
 private:
  std::thread::id thread_id;
  std::thread thread;

 public:
  explicit async_shell_cmd(util::thread_sched_params& sched_params);
  ~async_shell_cmd() {}
  async_shell_cmd(async_shell_cmd const&) = delete;
  void operator=(async_shell_cmd const&) = delete;

  int run_command(
      const task_id_t sender_itti_task, const bool is_abort_on_error,
      const char* src_file, const int src_line, const std::string& cmd_str);
};

}  // namespace util
#endif /* FILE_ASYNC_SHELL_CMD_HPP_SEEN */
