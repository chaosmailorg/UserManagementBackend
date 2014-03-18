#include <Ice/Ice.h>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include "UserManagementInterface.h"

using namespace UserManagementInterface;

std::vector<std::string> getCommand() {
  char cstr_command[1024];
  std::cin.getline(cstr_command,1024);
  std::string command(cstr_command);

  std::istringstream iss(command);
  std::vector<std::string> tokens;
  std::copy(std::istream_iterator<std::string>(iss),
      std::istream_iterator<std::string>(),
      std::back_inserter<std::vector<std::string> >(tokens));

  return tokens;
}




int main(int argc, char* argv[]) {

  int conStatus = 0;
  Ice::CommunicatorPtr ic;

  try {
    ic = Ice::initialize(argc, argv);
    Ice::ObjectPrx base = ic->stringToProxy("UserManagementInterface:tcp -h 192.168.0.104 -p 10000");
    RPCObjectPrx rpcobject = RPCObjectPrx::checkedCast(base);
    if (!rpcobject)
      throw "Invalid proxy";

    std::cout << "### Interactive ###" << std::endl;

    std::vector<std::string> command;
    do {
      command = getCommand();
      statuscode status = FAILURE;

      if (command.size() == 0)
        continue;
      if (command[0].compare(std::string("EXIT")) == 0)
        break;

      if (command[0].compare(std::string("ADDUSER")) == 0)
      {
        if (command.size() != 7)
          status = FAILURE;
        else
          status = rpcobject->addUser(command[1],command[2],command[3],command[4],atoi(command[5].c_str()),( command[6].compare("TRUE") == 0 ? true : false));
      } else {

        if (command[0].compare(std::string("CHANGEUSERPASSWORD")) == 0)
        {
          if (command.size() != 3)
            status = FAILURE;
          else
            status = rpcobject->changeUserPassword(command[1],command[2]);
        } else {

          if (command[0].compare(std::string("CHANGEUSERQUOTA")) == 0)
          {
            if (command.size() != 3)
              status = FAILURE;
            else
              status = rpcobject->changeUserQuota(command[1],atoi(command[2].c_str()));
          } else {

            if (command[0].compare(std::string("EXISTSUSER")) == 0)
            {
              if (command.size() != 2)
                status = FAILURE;
              else
              {
                bool exists = rpcobject->existsUser(command[1]);
                if (exists)
                  std::cout << "USER " << command[1] << " EXISTS IN DATABASE" << std::endl;
                else
                  std::cout << "USER " << command[1] << " DOES NOT EXIST IN DATABASE" << std::endl;
                status = SUCCESS;
              }
            } else {

              if (command[0].compare(std::string("USERCOUNT")) == 0)
              {
                if (command.size() != 1)
                  status = FAILURE;
                else
                {
                  int count = rpcobject->userCount();
                  std::cout << count << " USER IN DATABASE" << std::endl;
                  status = SUCCESS;
                }
              }
            }
          }
        }
      }

      if (status == SUCCESS)
        std::cout << "***SUCCESS***" << std::endl;
      else
        std::cout << "***FAIL***" << std::endl;
    } while(true);

  } catch (const Ice::Exception& ex) {
    std::cerr << ex << std::endl;
    conStatus = 1;
  } catch (const char* msg) {
    std::cerr << msg << std::endl;
    conStatus = 1;
  }

  if (ic)
    ic->destroy();

  if(conStatus == 0)
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}
