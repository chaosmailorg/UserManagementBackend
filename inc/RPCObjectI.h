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
