
# MiniTalk

Minitalk is a small inter-process communication (IPC) project that uses Unix signals (SIGUSR1, SIGUSR2) to send messages from a client to a server process.
The project is a 42 school project designed to explore Unix signal handling by implementing a simple client-server communication system. 
The client sends a message to the server, one bit at a time, using Unix signals (SIGUSR1 and SIGUSR2).



## Usage

Use the Makefile to compile:
```javascript
make
```

Start the server:
```javascript
./server
```
The server will output its Process ID (PID), which will be used to send messages from the client.

start client to send a message to the server:
```javascript
./client <PID> "Hello kedi"
```


## Authors

- [@Joana Wardenga](https://www.github.com/YunShenMiao)

