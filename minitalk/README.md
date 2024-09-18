# MINITALK
    
## INTRODUCTION:

Minitalk is a project in wich you have to processes,- a **server** and a **client** - that comunicate with each other. The idea is that the server when initilized must display its PID (*Process Identifier*). The client then using the server PID can send a message to server. At last the server displays the clients message. 

The ./client in order to work properly has to be launched as:

            >./client <PID> <MESSAGE>


Errors must be handled thoroughly and server can not take too long to print the characters. 


## SOLUTION:

In general lines, server is initialized and displays its PID. Client then is launched, possible errors are checked, and the message is sent to server. 
Each character from the message is turned into its representation in bytes. Every bit is sent to server as a signal (SIGUSR1 for 1's and SIGUSR2 for 0's). Server receives the signals, build the bytes and transforms them back to characters, printing charracter by character. Server sends back a signal to client, to let client knows that the signal was successfully received and client can now send a new signal - this avoid overlapping, building wrong characters.

