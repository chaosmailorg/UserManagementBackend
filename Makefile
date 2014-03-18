# =============================================================================
# 
# Date:      02.03.2014
# License:   GPLv2
# Author:    alexander.fischer@chaosmail.org
# 
# =============================================================================

CXX = g++
CPPFLAGS = $(FLAGS_FAST)
CPPFLAGS += $(FLAGS_HARDENED)
CPPFLAGS += -std=c++0x
INCLUDES = -I$(ICE_HOME)/include -I./inc
LIBS = -L$(ICE_HOME)/lib -lIce -lIceUtil -lodb-mysql -lodb -lodb-boost

# =============================================================================

%.o: ./src/%.cpp ./inc/%.h
	$(CXX) $(CPPFLAGS) -c $(INCLUDES) -o $@ $<

%.o: ./src/%.cpp
	$(CXX) $(CPPFLAGS) -c $(INCLUDES) -o $@ $<

%.o: ./src/%.cxx ./inc/%.hxx
	$(CXX) $(CPPFLAGS) -c $(INCLUDES) -o $@ $<

%.o: ./src/%.cxx
	$(CXX) $(CPPFLAGS) -c $(INCLUDES) -o $@ $<

# =============================================================================
# TARGETS
# =============================================================================

all: server client

server: UserManagementInterface.o user.o user-odb.o RPCObjectI.o Server.o
	$(CXX) $(CPPFLAGS) $(INCLUDES) UserManagementInterface.o user.o user-odb.o RPCObjectI.o Server.o -o Server.run $(LIBS)

client: UserManagementInterface.o RPCObjectI.o Client.o
	$(CXX) $(CPPFLAGS) $(INCLUDES) UserManagementInterface.o Client.o -o Client.run $(LIBS)

# =============================================================================

.PHONY: clean

clean:
	rm -f *.o

# =============================================================================
