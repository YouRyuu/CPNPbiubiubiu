all:client server
.PHONY:all
HEADERS=error_handler.o warpfunc.o
CLIENT=chat_client.o
SERVER=chat_server.o
client:$(HEADERS) $(CLIENT)
	g++ -o client $(HEADERS) $(CLIENT)
server:$(HEADERS) $(SERVER)
	g++ -o server $(HEADERS) $(SERVER)
$(CLIENT):chat_client.cpp hchat.h
	g++ -c chat_client.cpp
$(SERVER):chat_server.cpp hchat.h
	g++ -c chat_server.cpp
error_handler.o:error_handler.cpp hchat.h
	g++ -c error_handler.cpp
warpfunc.o:warpfunc.cpp hchat.h
	g++ -c warpfunc.cpp
clean:
	rm $(HEADERS) $(CLIENT) $(SERVER)