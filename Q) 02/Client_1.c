#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

struct message
{
    
    int integer;
    
};

int main()
{
    int C_SOCKET;
    struct sockaddr_in C_Address;
    struct message client_data;
    int CHECK_ERROR;

    C_SOCKET = socket(AF_INET, SOCK_DGRAM, 0);
    if (C_SOCKET == -1)
    {
        printf("Creating Error socket.");
        exit(1);
    }

    C_Address.sin_family = AF_INET;
    C_Address.sin_port = htons(9002);
    C_Address.sin_addr.s_addr = INADDR_ANY;

    printf("Please enter an integer here?:\n");
    scanf("%d", &client_data.integer);
    
    CHECK_ERROR = sendto(C_SOCKET, &client_data, sizeof(client_data), 0, (struct sockaddr *)&C_Address, sizeof(C_Address));
    if (CHECK_ERROR == -1)
    {
        printf(" sending Error message.\n");
        exit(1);
    }

    close(C_SOCKET);
    return 0;
}