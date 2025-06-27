# 💬 ft_irc: A Custom C++ IRC Server

![Language: C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Standard: C++98](https://img.shields.io/badge/Standard-C%2B%2B98-orange.svg)
![Network: TCP/IP](https://img.shields.io/badge/Network-TCP%2FIP-red.svg)
![Sync: non-blocking I/O](https://img.shields.io/badge/Sync-non--blocking_I%2FO-blueviolet.svg)
![School: 42 Paris](https://img.io/badge/School-42_Paris-orange.svg)
![Grade: 125/100](https://img.io/badge/Grade-125/100-brightgreen.svg)
![Team Project](https://img.shields.io/badge/Team_Project-Yes-blue.svg)

## ✨ Overview

`ft_irc` is an advanced and highly complex networking project from 42 Paris, focused on **reproducing the core functionality of an Internet Relay Chat (IRC) server** according to the RFC 2812 standard. This project required building a robust, non-blocking IRC server from scratch in C++, capable of managing multiple client connections, parsing IRC commands, and handling real-time communication.

As a **team project**, it honed skills in collaborative development, architectural design, and strict protocol implementation. Achieving all bonuses further demonstrated extended functionalities like file transfer and basic bot integration.

## 🌟 Key Features & Implementation Details

This project implements a fully functional IRC server, designed to be tested with a standard IRC client.

### **1. Core Server Functionality (Mandatory Part)**

*   **TCP/IP Networking:** Implemented a non-blocking TCP/IP server using sockets (`socket`, `bind`, `listen`, `accept`, `send`, `recv`) to manage multiple concurrent client connections.
*   **Event-Driven I/O:** Utilized an I/O multiplexing mechanism (e.g., `poll()` or `select()`) to efficiently handle simultaneous input/output operations from multiple clients without blocking.
*   **RFC 2812 Compliance:** Parsed and responded to a mandatory subset of IRC commands and protocol rules, including:
    *   **User Management:** `PASS`, `NICK`, `USER` for client identification.
    *   **Channel Management:** `JOIN`, `PART`, `TOPIC` for channel creation and interaction. Includes managing channel operators and basic channel modes (e.g., invite-only, key, user limit).
    *   **Messaging:** `PRIVMSG` for private and channel messages.
    *   **Client Management:** `QUIT` to disconnect clients.
*   **Command Parsing:** Implemented a robust parser to reconstruct full commands from fragmented network packets.
*   **Error Handling:** Comprehensive error management for network operations, invalid commands, and client states.

### **2. Advanced Features (Bonus Part - Achieved All)**

*   **File Transfer Capability:** Implemented a mechanism allowing clients to **send files to other clients via the IRC server**. This involved handling the transfer protocol and managing file data through the server.
*   **Simplistic Bot Integration:** Developed a **basic bot** integrated into the server, capable of responding to specific commands or events. This demonstrated extending server functionality beyond standard user interaction.

## 🛠️ Technologies Used

*   **Language:** C++ (C++98 Standard)
*   **Build System:** Makefile
*   **Networking:** POSIX Sockets (TCP/IP), Non-blocking I/O (e.g., `poll()`), Network System Calls (`socket`, `bind`, `listen`, `accept`, `send`, `recv`).
*   **Concurrency:** Event-driven architecture (single-threaded for main loop), not multi-threaded.
*   **Data Structures:** Custom data structures for client management, channels, and message queues.
*   **Protocol Parsing:** Custom parser for RFC 2812 commands.
*   **Memory Management:** Explicit memory handling for dynamic data.

## 🚀 How to Use

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/yourusername/ft_irc.git
    cd ft_irc
    ```
2.  **Compile the server:**
    ```bash
    make
    # This will generate the 'ircserv' executable.
    ```
3.  **Run the IRC server:**
    ```bash
    ./ircserv <port> <password>
    # Example: ./ircserv 6667 my_secret_password
    ```
4.  **Connect with a standard IRC client:**
    Use any official IRC client (e.g., `irssi`, `mIRC`, `HexChat`) to connect to `localhost:<port>` using the specified password.
    *   **Example with `irssi`:**
        ```bash
        /connect localhost 6667
        /nick your_nickname
        /user your_username 0 * :Your Real Name
        /msg NickServ identify my_secret_password
        /join #mychannel
        /msg #mychannel Hello World!
        ```
    *   **Testing bonus features:** (Specific commands/syntax would depend on your implementation)
        *   Try using your file transfer command.
        *   Interact with your bot (e.g., `/msg MyBot help`).

## 🎓 Learning Outcomes

This project significantly enhanced my expertise in:

*   **Network Programming:** Deep understanding of TCP/IP sockets, non-blocking I/O, and server architecture.
*   **Protocol Implementation:** Rigorous parsing and adherence to complex text-based protocols (RFC 2812).
*   **Event-Driven Architecture:** Designing and managing a server to handle concurrent client requests efficiently.
*   **Concurrency Management:** Implementing non-blocking I/O to manage multiple connections within a single thread.
*   **Data Serialization/Deserialization:** Reconstructing commands from raw network streams.
*   **C++ Systems Programming:** Proficient use of C++ for low-level system interactions.
*   **Extended Server Functionality:** Implementing custom features like **file transfer and basic bot logic**.
*   **Collaborative Development:** Effectively working in a team on a large and complex codebase.

---
