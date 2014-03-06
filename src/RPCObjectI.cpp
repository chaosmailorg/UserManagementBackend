#include "RPCObjectI.h"

namespace UserManagementInterface {

  statuscode RPCObjectI::addUser(const std::string& username, const std::string& password, const std::string& domain, long quota,     bool active ,const Ice::Current&){
    std::cout << "RPCObjectI::addUser " << username << " " << password << " " << domain << " " << quota << " " << active << std::endl;
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
