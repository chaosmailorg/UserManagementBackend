#include "RPCObjectI.h"

namespace UserManagementInterface {

/*
 * TODO: Fix datetime format and datatype (boost?)
 */
  statuscode RPCObjectI::addUser(const std::string& username, const std::string& name, const std::string& password, const std::string& domain, long quota, bool active , const Ice::Current&){
      const char* local_part = "hans.acker";
      boost::posix_time::ptime t(boost::posix_time::second_clock::universal_time());
      boost::posix_time::ptime created = t;
      boost::posix_time::ptime modified = t;
      std::string maildir = "/maildir/";
      std::unique_ptr<database> db(new odb::mysql::database(dbuser, dbpassword, dbname));
      User user(username, password, name, maildir, quota, local_part, domain, created, modified, true);
      addUser(user, db);
    return SUCCESS;
  }

  statuscode RPCObjectI::changeUserPassword(const std::string& username, const std::string& newpassword ,const Ice::Current&) {
    std::cout << "RPCObjectI::changeUserPassword " << username << " " << newpassword << std::endl;
    return SUCCESS;
  }

  statuscode RPCObjectI::changeUserQuota(const std::string& username, long quota ,const Ice::Current&) {
    std::cout << "RPCObjectI::changeUserQuota " << username << " " << quota << std::endl;
    return SUCCESS;
  }

  bool RPCObjectI::existsUser(const std::string& username ,const Ice::Current&) {
    std::cout << "RPCObjectI::existsUser " << username << std::endl;
    return true;
  }

  Ice::Int RPCObjectI::userCount(const Ice::Current&) {
    std::cout << "RPCObjectI::userCount" << std::endl;
    return SUCCESS;
  }

}
