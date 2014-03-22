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

#include "RPCObjectI.h"

namespace UserManagementInterface {

/*
 * TODO: validate inputs
 */
  statuscode RPCObjectI::addUser(const std::string& username, const std::string& name, const std::string& password, long quota, bool active , const Ice::Current&){
      std::stringstream ss(username);
      std::string segment;
      std::vector<std::string> seglist;

      while(std::getline(ss, segment, '@'))
        seglist.push_back(segment);

      if (seglist.size() != 2)
        return FAILURE;

      const std::string local_part = seglist[0];
      const std::string domain = seglist[1];
      const std::string maildir = username + "/";

      boost::posix_time::ptime t(boost::posix_time::second_clock::universal_time());
      boost::posix_time::ptime created = t;
      boost::posix_time::ptime modified = t;
      std::unique_ptr<database> db(new odb::mysql::database(dbuser, dbpassword, dbname));
      User user(username, password, name, maildir, quota, local_part, domain, created, modified, true);
      addUser(user, db);
    return SUCCESS;
  }

  /*
   * not implemented
   */
  statuscode RPCObjectI::changeUserPassword(const std::string& username, const std::string& newpassword ,const Ice::Current&) {
    std::cout << "RPCObjectI::changeUserPassword " << username << " " << newpassword << std::endl;
    return SUCCESS;
  }

  /*
   * not implemented
   */
  statuscode RPCObjectI::changeUserQuota(const std::string& username, long quota ,const Ice::Current&) {
    std::cout << "RPCObjectI::changeUserQuota " << username << " " << quota << std::endl;
    return SUCCESS;
  }

  /*
   * not implemented
   */
  bool RPCObjectI::existsUser(const std::string& username ,const Ice::Current&) {
    std::cout << "RPCObjectI::existsUser " << username << std::endl;
    return true;
  }

  /*
   * not implemented
   */
  Ice::Int RPCObjectI::userCount(const Ice::Current&) {
    std::cout << "RPCObjectI::userCount" << std::endl;
    return SUCCESS;
  }

}
