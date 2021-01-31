#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

int main()
{
    int server_socket;
    int CHECK_ERROR;
    char S_Message[256];
    char ping[10];
    struct sockaddr_in C_Address;
    socklen_t client_len;
    
    client_len = sizeof(C_Address);

    server_socket = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in S_Address;
    S_Address.sin_family = AF_INET;
    S_Address.sin_port = htons(9002);
    S_Address.sin_addr.s_addr = INADDR_ANY;

    CHECK_ERROR = bind(server_socket, (struct sockaddr *) &S_Address, sizeof(S_Address));
    if(CHECK_ERROR == -1)
    {
        printf("Error while binding\n");
        exit(1);
    }

    // get message from client 1
    CHECK_ERROR = recvfrom(server_socket,S_Message,sizeof(S_Message),0, (struct sockaddr *) &C_Address, &client_len);
    if(CHECK_ERROR == -1)
    {
        printf("error receiving message from client.\n");
        exit(1);
    }

    printf("Client sent character: %s\n", S_Message);
    
    // process the message and decrement the character sent by client 1
    if(S_Message[0] == 'a')
    {
        S_Message[0] = 'z';
    }
    else if (S_Message[0] == 'A')
    {
        S_Message[0] == 'Z';
    }
    else
    {
        S_Message[0] = S_Message[0] - 1;
    }

    // client 2 pings so that its ip address and port can be known and response can be sent.
    CHECK_ERROR = recvfrom(server_socket,ping,sizeof(ping),0, (struct sockaddr *) &C_Address, &client_len);
    if(CHECK_ERROR == -1)
    {
        printf("error receiving message from client.\n");
        exit(1);
    }

    CHECK_ERROR = sendto(server_socket, S_Message, sizeof(S_Message), 0, (struct sockaddr *) &C_Address, client_len);
    if(CHECK_ERROR == -1)
    {
        printf("Error while sending message.\n");
        exit(1);
    }

    printf("Server says I am done.\n");

    close(server_socket);
    return 0;
}