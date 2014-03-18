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

#ifndef RPCOBJECTI_INCLUDED__
#define RPCOBJECTI_INCLUDED__

#include <iostream>
#include <cstdlib>
#include <memory>
#include <array>
#include <string>

#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/mysql/database.hxx>

#include <Ice/Ice.h>

#include "user.hxx"
#include "user-odb.hxx"
#include "databaseexception.h"
#include "UserManagementInterface.h"
#include "defines.h"

using namespace odb::core;

namespace UserManagementInterface {

  class RPCObjectI : public RPCObject {
    private:

      static bool isUserInDB(User & user, std::unique_ptr<database> & db) {
        transaction t(db->begin());
        result<User> r(db->query<User>(query<User>::username == user.username()));
        auto it = r.begin();
        bool exists = false;

        if (it != r.end())
          exists = true;

        return exists;
      }

      static void addUser(User & user, std::unique_ptr<database> & db) {
        transaction t(db->begin());
        result<User> r(db->query<User>(query<User>::username == user.username()));
        auto it = r.begin();
        if (it != r.end())
        {
          t.commit();
          throw DatabaseException("User already in databse");
          return;
        }

        db->persist(user);

        t.commit();
      }


    public:
      /* add user */
      virtual statuscode addUser(const std::string& username,const std::string& name, const std::string& password, const std::string& domain, long quota, bool active ,const Ice::Current&);

      /* change user password */
      virtual statuscode changeUserPassword(const std::string& usernam, const std::string& newpassword ,const Ice::Current&);

      /* change user quota */
      virtual statuscode changeUserQuota(const std::string& username, long quota ,const Ice::Current&);

      /* returns true if user exists */
      virtual bool existsUser(const std::string& username ,const Ice::Current&);

      /* returns number of useraccounts */
      virtual Ice::Int userCount(const Ice::Current&);
  };

}

#endif
