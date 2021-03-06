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
