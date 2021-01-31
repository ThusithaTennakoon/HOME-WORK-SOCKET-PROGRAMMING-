Compile the files server.c, client1.c and client2.c using :
gcc server.c -o server
gcc client1.c -o client1
gcc client2.c -o client2
Open three terminals, run server, client1 and client2 in the same order. Make sure to run server first and client2 only after client1 has completed its function.
./server (terminal 1)
./client1 (terminal 2)
send data from client1
./client2 (terminal 3)