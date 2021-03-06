#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

struct message
{
    float floatnum;
};

int main()
{
    int server_socket;
    struct sockaddr_in S_Address;
    struct sockaddr_in C_Address;
    socklen_t client_len;
    struct message server_data;
    int CHECK_ERROR;
    int ping;
    int ping2;

    client_len = sizeof(client_address);

    server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_socket == -1)
    {
        printf("Error creating socket.");
    }

    S_Address.sin_family = AF_INET;
    S_Address.sin_port = htons(9002);
    S_Address.sin_addr.s_addr = INADDR_ANY;

    CHECK_ERROR = bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    CHECK_ERROR = recvfrom(server_socket, &server_data, sizeof(server_data), 0, (struct sockaddr *)&C_Address, &client_len);
    if (CHECK_ERROR == -1)
    {
        printf("Error while receving message.\n");
        exit(1);
    }

    CHECK_ERROR = recvfrom(server_socket, &ping, sizeof(ping), 0, (struct sockaddr *)&C_Address, &client_len);
    if (CHECK_ERROR == -1)
    {
        printf("Error while receving ping.\n");
        exit(1);
    }

    server_data.floatnum = server_data.floatnum * 1.5;

    CHECK_ERROR = sendto(server_socket, &server_data, sizeof(server_data), 0, (struct sockaddr *)&C_Address, client_len);
    if (CHECK_ERROR == -1)
    {
        printf("Error while sending message.\n");
        exit(1);
    }



    printf("Server says I am done.\n");

    close(server_socket);
}