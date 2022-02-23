LIB=../../../lib/libcifib.a

OBJS=attachment.o base64.o credential.o errorresolver.o forcedsecuresmtpclient.o htmlmessage.o \
	messageaddress.o message.o opportunisticsecuresmtpclient.o plaintextmessage.o securesmtpclientbase.o \
	smtpclientbase.o smtpclient.o stringutils.o

CXXFLAGS += -I../include

.PHONY: compile

compile: $(OBJS)
	$(AR) -s $(LIB)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<
	$(AR) -r $(LIB) $@

