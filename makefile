
# This is a template Makefile generated by rpcgen

# Parameters

CLIENT = bomba
SERVER = centro

SOURCES_CLNT.c =  ListaServidor.c
SOURCES_CLNT.h = bomba.h ListaServidor.h
SOURCES_SVC.c =
SOURCES_SVC.h = centro.h
SOURCES.x = proyecto.x
SOURCES.c = errors.c
SOURCES.h = errors.h

TARGETS_SVC.c = proyecto_svc.c proyecto_server.c   
TARGETS_CLNT.c = proyecto_clnt.c proyecto_client.c   
TARGETS = proyecto.h proyecto_clnt.c proyecto_svc.c proyecto_client.c proyecto_server.c

OBJECTS_CLNT = $(SOURCES_CLNT.c:%.c=%.o) $(TARGETS_CLNT.c:%.c=%.o)
OBJECTS_SVC = $(SOURCES_SVC.c:%.c=%.o) $(TARGETS_SVC.c:%.c=%.o)
# Compiler flags 

CFLAGS += -g 
LDLIBS += -lnsl
RPCGENFLAGS = 
TFLAG = -pthread

# Targets 

all : $(CLIENT) $(SERVER)

# $(TARGETS) : $(SOURCES.x) 
# 	rpcgen $(RPCGENFLAGS) $(SOURCES.x)

$(OBJECTS_CLNT) : $(SOURCES_CLNT.c) $(SOURCES_CLNT.h) $(TARGETS_CLNT.c) 

$(OBJECTS_SVC) : $(SOURCES_SVC.c) $(SOURCES_SVC.h) $(TARGETS_SVC.c) 

$(CLIENT) : $(OBJECTS_CLNT) 
	$(LINK.c) -o $(CLIENT) $(OBJECTS_CLNT) $(SOURCES.c) $(SOURCES.h) $(LDLIBS) 

$(SERVER) : $(OBJECTS_SVC) 
	$(LINK.c) -o $(SERVER) $(TFLAG) $(OBJECTS_SVC) $(SOURCES.c) $(SOURCES.h) $(LDLIBS)

 clean:
	 $(RM) core *.o $(CLIENT) $(SERVER)