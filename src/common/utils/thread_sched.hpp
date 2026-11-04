/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */

/*! \file thread_sched.hpp
  \brief
  \company Eurecom
  \email: lionel.gauthier@eurecom.fr
*/

#ifndef FILE_THREAD_SCHED_HPP_SEEN
#define FILE_THREAD_SCHED_HPP_SEEN

#include <sched.h>
#include "logger.hpp"

namespace util {

class thread_sched_params {
 public:
  thread_sched_params()
      : cpu_id(0),
        sched_policy(SCHED_FIFO),
        sched_priority(84),
        thread_pool_size(1) {}
  int cpu_id;
  int sched_policy;
  int sched_priority;
  unsigned int thread_pool_size;
  void apply(const int task_id, const oai::logger::printf_logger& logger) const;
};

}  // namespace util
#endif /* FILE_THREAD_SCHED_HPP_SEEN */
