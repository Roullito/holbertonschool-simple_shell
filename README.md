<p align="center">
   <img src="https://github.com/user-attachments/assets/7d564981-cb81-43e7-819a-25ffcfc5bd72" width=40% height=40%/>
</p>

# C - Simple Shell

## 📚 Description

This project consists of creating a simple UNIX command interpreter, similar to `/bin/sh`, capable of executing commands both in interactive and non-interactive modes.

---

## 🛠 Architecture Overview
Here is a flowchart illustrating the internal workflow of the Simple Shell:

![Simple Shell Flowchart](assets/flowchart.png)

---
## 📑 Table of Contents

- [Learning Objectives](#learning-objectives)
- [Requirements](#requirements)
- [Allowed Functions and System Calls](#allowed-functions-and-system-calls)
- [Usage](#usage)
  - [Interactive Mode](#interactive-mode)
  - [Non-Interactive Mode](#non-interactive-mode)
  - [Example with `cat`](#example-with-cat)
- [Installation](#installation)
- [Project Files](#project-files)
  - [1. _memcpy.c](#1-memcpyc)
  - [2. _strcpy.c](#2-strcpyc)
  - [3. _strdup.c](#3-strdupc)
  - [4. _strncmp.c](#4-strncmpc)
  - [5. builtin.c](#5-builtinc)
  - [6. executor.c](#6-executorc)
  - [7. find.c](#7-findc)
  - [8. input.c](#8-inputc)
  - [9. main.c](#9-mainc)
  - [10. main.h](#10-mainh)
  - [11. parser.c](#11-parserc)
- [Testing](#testing)
- [GitHub](#github)
- [Authors](#authors)
- [License](#license)

---

## 🎯[Learning Objectives](#learning-objectives)

- Understand the history of Unix and its key contributors.
- Know who designed the original Unix operating system and the UNIX shell.
- Discover the B programming language and its creator.
- Understand who Ken Thompson is.
- Learn how a shell works internally.
- Understand process concepts: `pid` and `ppid`.
- Manage environment variables within a process.
- Distinguish between functions and system calls.
- Create new processes (`fork`) and execute programs (`execve`).
- Use the PATH environment variable to locate executable programs.
- Wait for process termination (`wait`).
- Handle "end-of-file" (EOF) conditions.

---

## 📋[Requirements](#requirements)

- Allowed editors: `vi`, `vim`, `emacs`
- Compilation on **Ubuntu 20.04 LTS** with:
  ```bash
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89
  ```
- A `README.md` file must be present at the root of the project.
- Code must follow the **Betty coding style**.
- No memory leaks are allowed.
- Maximum **5 functions per file**.
- Header files must be **include guarded**.
- Use **system calls only when necessary**.

---

## 🛠[Allowed Functions and System Calls](#allowed-functions-and-system-calls)

You are allowed to use the following C standard functions and system calls:

- Standard C library functions from `string.h`
- `access`, `chdir`, `close`, `closedir`, `execve`, `exit`, `_exit`
- `fflush`, `fork`, `free`, `getcwd`, `getline`, `getpid`, `isatty`, `kill`
- `malloc`, `open`, `opendir`, `perror`
- `printf`, `fprintf`, `vfprintf`, `sprintf`, `putchar`
- `read`, `readdir`, `signal`
- `stat`, `lstat`, `fstat`
- `strtok`, `wait`, `waitpid`, `wait3`, `wait4`
- `write`

---

## ⚙[Usage](#usage)

### [Interactive Mode](#interactive-mode)

```bash
$ ./hsh
($) /bin/ls
file1 file2 shell.c
($) exit
$
```

### [Non-Interactive Mode](#non-interactive-mode)

Execute commands from input without an interactive prompt.

```bash
$ echo "/bin/ls" | ./hsh
file1 file2 shell.c
```

### [Example with `cat`](#example-with-cat)

Running multiple commands through a file:

```bash
$ cat commands.txt | ./hsh
file1 file2 shell.c
file1 file2 shell.c
```

---

## 📥[Installation](#installation)

### 1. Clone the repository

Clone the repository by running the following command:

```bash
git clone https://github.com/Roullito/holbertonschool-simple_shell.git
cd your-repo-name
```
Replace `YourUsername/your-repo-name` with the actual path to this repository.

### 2. Install the man page

We provide a script to automatically install the custom man page for our Simple Shell.

Run the following command:

```bash
./install_manpage.sh
```
This will:

- Copy `shell.1` to your local man directory (`/usr/local/share/man/man1/`).
- Update the man database.
- Allow you to type `man shell` from anywhere to access the manual.

**Note:**  
You might need `sudo` permissions to install the man page, depending on your system configuration.

---

## 🗂[Project Files](#project-files)

### 1. _memcpy.c <a name="1-memcpyc"></a>
- **Description**: Implements the `_memcpy` function that copies a memory area from one location to another.
- **Purpose**: Used for copying a block of memory from the source to the destination.

### 2. _strcpy.c <a name="2-strcpyc"></a>
- **Description**: Implements the `_strcpy` function that copies the string pointed to by `src` to the buffer pointed by `dest`.
- **Purpose**: Essential for copying strings within the shell's operations.

### 3. _strdup.c <a name="3-strdupc"></a>
- **Description**: Implements the `_strdup` function that creates a duplicate of a string by allocating new memory.
- **Purpose**: Useful when we need to duplicate strings, particularly for handling environment variables or command arguments.

### 4. _strncmp.c <a name="4-strncmpc"></a>
- **Description**: Implements the `_strncmp` function that compares up to `n` characters of two strings.
- **Purpose**: A custom comparison function to avoid using the standard `strncmp` for matching strings, often used for commands in the shell.

### 5. builtin.c <a name="5-builtinc"></a>
- **Description**: Implements the `handle_builtin` function that manages built-in shell commands like `exit`.
- **Purpose**: Allows the shell to execute internal commands directly without needing to invoke an external process.

### 6. executor.c <a name="6-executorc"></a>
- **Description**: Implements the `execute` function, which creates a child process to execute commands.
- **Purpose**: Handles the creation of processes for running commands within the shell.

### 7. find.c <a name="7-findc"></a>
- **Description**: Implements the `_which` function that finds the full path of a command using the `PATH` environment variable.
- **Purpose**: Determines the location of executable files, helping the shell find and execute commands.

### 8. input.c <a name="8-inputc"></a>
- **Description**: Implements the `_getline` function that reads a line of input from a file descriptor (typically `stdin`).
- **Purpose**: Handles user input in the shell, enabling interaction with the program.

### 9. main.c <a name="9-mainc"></a>
- **Description**: Implements the `main` function, which is the entry point of the custom shell.
- **Purpose**: Initializes and runs the shell, managing user input, command parsing, and execution.

### 10. main.h <a name="10-mainh"></a>
- **Description**: Implements the header file `main.h`, which contains all necessary prototypes for the shell's functions.
- **Purpose**: Ensures proper function declaration and code organization throughout the shell program.

### 11. parser.c <a name="11-parserc"></a>
- **Description**: Implements the `_strtok` function, a custom version of the `strtok` function used to tokenize strings.
- **Purpose**: Used to break down commands and arguments into tokens for easier processing by the shell.

## 🧪[Testing](#testing)

Your program must replicate the exact behavior of `/bin/sh`, including error messages.

Error messages must reference the name provided by `argv[0]`.

### Example with `/bin/sh`

```bash
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
```

### Example with your shell
```bash
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
```

A checker will be provided near the project deadline.

It is strongly recommended to create a full test suite covering both normal and edge cases.

## 🚀[GitHub](#github)

Only one repository per group is allowed.

Forking or cloning another group's repository before the deadline may result in a 0% grade.

## 🧑‍💻[Authors](#authors)

[Roullito - GitHub](https://github.com/Roullito)  
[P-Y74 - GitHub](https://github.com/P-Y74)

## 📝[License](#license)

This project is part of the curriculum at Holberton School and is intended for educational purposes only.






