# a conditional check is used below to differentiate beween the two types of invocation:
# 1 - (default) - this code is compiled as a cifib sub-module and thus no Makefile target is provided
# 2 - compiled as a stand-alone project (need to run: make compile)

ifeq ($(MAKECMDGOALS),compile)
  LIB=libsmtp.a
else  
  LIB=../../../lib/libcifib.a
endif

OBJS=attachment.o base64.o credential.o errorresolver.o forcedsecuresmtpclient.o htmlmessage.o \
	messageaddress.o message.o opportunisticsecuresmtpclient.o plaintextmessage.o securesmtpclientbase.o \
	smtpclientbase.o smtpclient.o stringutils.o

CXXFLAGS += -I../include -std=c++14

.PHONY: compile default clean

default: compile-as-cifib-submodule

compile-as-cifib-submodule: $(OBJS)
	$(AR) -s $(LIB)

compile: $(OBJS)
	$(AR) -s $(LIB)
	
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<
	$(AR) -r $(LIB) $@

clean:
	rm -f *.o
	rm -f *.a
