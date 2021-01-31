#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>

int main()
{
    int C_SOCKET;
    int CHECK_ERROR;
    struct sockaddr_in C_Address;
    socklen_t server_len;
    char C_Message[1024];

    server_len = sizeof(C_Address);

    C_SOCKET = socket(AF_INET, SOCK_DGRAM, 0);
    if(C_SOCKET == -1)
    {
        printf("Creating error in socket\n");
        exit(1);
    }

    C_Address.sin_family = AF_INET;
    C_Address.sin_port = htons(9002);
    C_Address.sin_addr.s_addr = INADDR_ANY;
    
    CHECK_ERROR = sendto(C_SOCKET, C_Message, sizeof(C_Message),0, (struct sockaddr *) &C_Address, server_len);
    if(CHECK_ERROR == -1)
    {
        printf("sending error message\n");
        exit(1);
    }

    CHECK_ERROR = recvfrom(C_SOCKET, C_Message, sizeof(C_Message), 0, (struct sockaddr *) &C_Address, &server_len);
    if(CHECK_ERROR == -1)
    {
        printf("reciveing error message\n");
        exit(1);
    }
    printf("following charachter send by the server:\n");
    printf("%s\n", C_Message);

    close(C_SOCKET);

    return 0;
}