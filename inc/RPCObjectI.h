#ifndef RPCOBJECTI_INCLUDED__
#define RPCOBJECTI_INCLUDED__

// DEBUG ->
#include <iostream>
// <- DEBUG

#include <Ice/Ice.h>
#include <string>
#include "UserManagementInterface.h"


namespace UserManagementInterface {

  class RPCObjectI : public RPCObject {
  public:

      /* add user */
      virtual statuscode addUser(const std::string& username, const std::string& password, const std::string& domain, long quota, bool active ,const Ice::Current&);

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
