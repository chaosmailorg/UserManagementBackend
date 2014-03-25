/*
 *  Copyright (C) 2014 by Alexander Fischer <alexander.fischer@chaosmail.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef DEFINES_DEFINED__
#define DEFINES_DEFINED__

#include <array>

namespace UserManagementInterface {

  static const char* const dbuser = "odb_test";
  static const char* const dbpassword = "";
  static const char* const dbname = "odb_test";

  static const int pw_length = 24;

  static const std::array<const std::string,1> valid_domains = { "chaosmail.org" };

  // name regex
  static const std::string name_regex = R"([\w ]{3,60})";

  // mail regex
  static const std::string mail_regex_pos = R"([a-zA-Z0-9]+[\-a-zA-Z0-9\._]{1,56}[a-zA-Z0-9]+@[a-zA-Z0-9]+[\-a-zA-Z0-9\._]*[a-zA-Z0-9]+\.[a-zA-Z0-9]{2,})";
  static const std::string mail_regex_neg = R"(.*[\._\-]{2,}.*)";

}

#endif
