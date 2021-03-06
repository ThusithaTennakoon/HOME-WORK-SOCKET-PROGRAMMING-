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
    socklen_t client_len;
    int ping = 1;
    int CHECK_ERROR;

    client_len = sizeof(C_Address);
    C_SOCKET = socket(AF_INET, SOCK_DGRAM, 0);

    if (C_SOCKET == -1)
    {
        printf("Error creating socket.");
        exit(1);
    }

    C_Address.sin_family = AF_INET;
    C_Address.sin_port = htons(9002);
    C_Address.sin_addr.s_addr = INADDR_ANY;

    CHECK_ERROR = sendto(C_SOCKET, &ping, sizeof(ping), 0, (struct sockaddr *)&C_Address, sizeof(C_Address));
    if (CHECK_ERROR == -1)
    {
        printf("Error sending message.\n");
        exit(1);
    }

    CHECK_ERROR = recvfrom(C_SOCKET, &client_data, sizeof(client_data), 0, (struct sockaddr *)&C_Address, &client_len);
    if (CHECK_ERROR == -1)
    {
        printf("Error sending message.\n");
        exit(1);
    }

    printf("Server sent the following data:\n");
    printf("Integer: %d\n", client_data.integer);
    
    close(client_socket);
    return 0;
}