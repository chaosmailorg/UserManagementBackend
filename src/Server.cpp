#include <memory>
#include <array>
#include <cstdlib>
#include <iostream>

#include "RPCObjectI.h"

using namespace UserManagementInterface;
using namespace odb::core;
using namespace std;

int main(int argc, char* argv[]) {
  statuscode status = SUCCESS;
  Ice::CommunicatorPtr ic;

  try {
    ic = Ice::initialize(argc, argv);
    Ice::ObjectAdapterPtr adapter = ic->createObjectAdapterWithEndpoints("UserManagementInterfaceAdapter", "default -p 10000");
    Ice::ObjectPtr object = new RPCObjectI();
    adapter->add(object, ic->stringToIdentity("UserManagementInterface"));
    adapter->activate();
    ic->waitForShutdown();
  } catch (const Ice::Exception& e) {
    std::cerr << e << std::endl;
    status  = FAILURE;
  } catch (const char* msg) {
    std::cerr << msg << std::endl;
    status = FAILURE;
  }

  if (ic)
  {
    try {
      ic->destroy();
    } catch (const Ice::Exception& e) {
      std::cerr << e << std::endl;
      status = FAILURE;
    }
  }

  if (status == FAILURE)
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}
