#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
//For AF_INET
#include <netinet/in.h>
#include <arpa/inet.h>

#define TRUE 1

int main(int argc, char *argv[])
{
	int server_socket, client_socket; //socket handle
	int server_len, client_len; 
	struct sockaddr_in server_address, client_address;
	int ret; //return value
	
	/* 1. Create socket for server */
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	/* 2. Set name and assign address to server socket */
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htonl(INADDR_ANY); //Allow any IP to connect
	server_address.sin_port = htons(9734); //Listen on port 9734
	
	server_len = sizeof(server_address);
	
	/* 3. Bind the name to socket */
	bind(server_socket, (struct sockaddr *) &server_address, server_len);
	
	/* 4. Open queue to listen connections, max 5 connections */
	ret = listen(server_socket, 5);
	
	if(ret == 0)
	{
		printf("Listen successfully\n");
	}
	else
	{
		printf("Listen failed\n");
		exit(EXIT_FAILURE);
	}
	
	/* 5. Forever loop to wait and serve connections from client */
	printf("Server is waiting...\n");
	while(TRUE)
	{
		//printf("Server is waiting...\n");
		char char_tmp[100];
		
		/* 6. Wait and accept the result, create a temp socket */
		client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_len);
		printf("Accepted. Ready to receive and send data:\n");		

		/* 7. Read the data from client*/
		recv(client_socket, char_tmp, sizeof(char_tmp), 0);
		printf("Server received: %s\n", char_tmp);
		
		/* Send data to client */
		printf("[Server] Enter the message: ");
		gets(char_tmp);
		send(client_socket, char_tmp, sizeof(char_tmp), 0);

		/* Close the socket */
		close(client_socket);
	}

	exit(EXIT_SUCCESS);
}




