LIB-CIFIB-SUBMODULE=../../../lib/libcifib.a
LIB=libsmtp.a

OBJS=attachment.o base64.o credential.o errorresolver.o forcedsecuresmtpclient.o htmlmessage.o \
	messageaddress.o message.o opportunisticsecuresmtpclient.o plaintextmessage.o securesmtpclientbase.o \
	smtpclientbase.o smtpclient.o stringutils.o

CXXFLAGS += -I../include -std=c++14

.PHONY: compile default clean

default: compile-as-cifib-submodule

compile-as-cifib-submodule: $(OBJS)
	$(AR) -s $(LIB-CIFIB-SUBMODULE)

compile: $(OBJS)
	$(AR) -s $(LIB)
	
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<
	$(AR) -r $(LIB) $@

clean:
	rm -f *.o
	rm -f *.a
