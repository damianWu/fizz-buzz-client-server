# fizz-buzz-client-server
Client-server application that can be used for playing the Fizz-Buzz game. Implemented using Asio library. The client sends numbers to the server that answers according to the game rules. Communication between the client and the server is done over TCP.

-------------------
Project contains two programs: a **server** and a **client**.

_The server_ accepts TCP connections on a particular port, opens a connected socket, and starts reading on the socket. When it reads something from the socket, it interprets it as a number for the Fizz-Buzz game, writes back
the answer, and continues to wait for another input.

_The client_ connects to a host on a particular port, sends a number read from the console, and then waits to receive an answer from the server before printing it to the console.