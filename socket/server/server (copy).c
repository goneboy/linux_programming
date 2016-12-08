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
	int server_sockfd, client_sockfd; //Socket handle
	int server_len, client_len;
	int ret;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;

	//Create socket for server
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("server_sockfd = %d\n", server_sockfd);
	
	//Set name & assign address to socket
	server_address.sin_family = AF_INET; 
	server_address.sin_addr.s_addr = htonl(INADDR_ANY); //Allow any IP to connect
	server_address.sin_port = htons(9734); //Listen on port 9734

	server_len = sizeof(server_address);	

	//Bind the name to socket
	bind(server_sockfd, (struct sockaddr *) &server_address, server_len);
	
	//Open queue to listen connections, max 5 connections
	ret = listen(server_sockfd, 5);
	
	if(ret == 0)
	{
		printf("Listen successfully\n");
	}
	else
	{
		printf("Listen failed\n");
	}
	
	//Forever loop to wait and serve connections from client

	while(TRUE)
	{
		char ch[1000];
		printf("Server waiting...\n");
		
		//Wait and accept the result, create a tmp socket
		client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_address, &client_len);
		//printf("client_sockfd = %d\n", client_sockfd);
		
		//Read the data from client
		read(client_sockfd, ch, sizeof(ch));
		printf("Server received: %s\n", ch);
		//ch++;
			
		//Send data to client
		//write(client_sockfd, &ch, 1);	
		char character[1000];
		
		printf("[Server] Enter the message: ");
		gets(character);
		write(client_sockfd, character, sizeof(character));	
	
		//printf("Server received %c\n", ch);

		//Close client socket
		close(client_sockfd);
	}

	exit(EXIT_SUCCESS);
}
