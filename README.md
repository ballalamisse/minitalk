# MiniTalk

A client-server communication project written in C using UNIX signals (`SIGUSR1` and `SIGUSR2`).

## Author

**Lamisse Balla**

Electrical Engineering Student – École Mohammadia d'Ingénieurs (EMI)

GitHub: https://github.com/ballalamisse

---

## Description

MiniTalk is a lightweight communication program that allows a client to send messages to a server using only UNIX signals.

The project demonstrates low-level inter-process communication (IPC), bitwise operations, signal handling, and process synchronization.

---

## Features

- Client/Server architecture
- Communication using SIGUSR1 and SIGUSR2
- Bit-by-bit message transmission
- Bonus version included
- Error handling
- Fast and reliable communication

---

## Project Structure

```
.
├── client.c
├── client_bonus.c
├── server.c
├── server_bonus.c
├── tools.c
├── minitalk.h
├── Makefile
└── README.md
```

---

## Compilation

Compile the mandatory version:

```bash
make
```

Compile the bonus version:

```bash
make bonus
```

Clean object files:

```bash
make clean
```

Remove all generated files:

```bash
make fclean
```

Recompile everything:

```bash
make re
```

---

## Usage

Start the server:

```bash
./server
```

The server prints its PID.

Send a message from the client:

```bash
./client <SERVER_PID> "Hello World"
```

Example:

```bash
./client 4242 "Hello EMI!"
```

---

## Concepts Used

- UNIX Signals
- Process Management
- Bit Manipulation
- Signal Handling
- Inter-Process Communication (IPC)
- Makefile
- C Programming

---

## Requirements

- GCC
- Linux/macOS
- Make

---

## License

This project is provided for educational purposes.
