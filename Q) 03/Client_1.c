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
    int C_Socket;
    struct sockaddr_in C_Address;
    struct message client_data;
    int CHECK_ERROR;

    C_Socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_socket == -1)
    {
        printf("Error creating socket.");
        exit(1);
    }

    C_Address.sin_family = AF_INET;
    C_Address.sin_port = htons(9002);
    C_Address.sin_addr.s_addr = INADDR_ANY;

    printf("Enter a floating point number:\n");
    scanf("%f", &client_data.floatnum);

    CHECK_ERROR = sendto(C_Socket, &client_data, sizeof(client_data), 0, (struct sockaddr *)&C_Address, sizeof(C_Address));
    if (CHECK_ERROR == -1)
    {
        printf("Error sending message.\n");
        exit(1);
    }

    close(C_Socket);
    return 0;
}