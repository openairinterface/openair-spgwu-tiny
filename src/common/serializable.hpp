/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */

/*! \file serializable.hpp
  \brief
  \author Lionel Gauthier
  \company Eurecom
  \email: lionel.gauthier@eurecom.fr
*/

#ifndef FILE_SERIALIZABLE_HPP_SEEN
#define FILE_SERIALIZABLE_HPP_SEEN

#include <string>
#include <iostream>

class stream_serializable {
 public:
  virtual void dump_to(std::ostream& os)   = 0;
  virtual void load_from(std::istream& is) = 0;
  // virtual ~serializable() = 0;
};

#endif /* FILE_SERIALIZABLE_HPP_SEEN */
