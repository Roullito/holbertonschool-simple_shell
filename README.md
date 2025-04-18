<p align="center">
   <img src="https://github.com/user-attachments/assets/7d564981-cb81-43e7-819a-25ffcfc5bd72" width=40% height=40%/>
</p>

# C - Simple Shell

## 📚 Description

This project consists of creating a simple UNIX command interpreter, similar to `/bin/sh`, capable of executing commands both in interactive and non-interactive modes.

---

## 📑 Table of Contents

- [Learning Objectives](#learning-objectives)
- [Requirements](#requirements)
- [Allowed Functions and System Calls](#allowed-functions-and-system-calls)
- [Usage](#usage)
  - [Interactive Mode](#interactive-mode)
  - [Non-Interactive Mode](#non-interactive-mode)
  - [Example with `cat`](#example-with-cat)
- [Project Files](#project-files)
  - [1. _memcpy.c](#memcpyc)
  - [2. _strcpy.c](#strcpyc)
  - [3. _strdup.c](#strdup)
  - [4. _strncmp.c](#strncmp)
  - [5. builtin.c](#builtin)
  - [6. executor.c](#executor)
  - [7. find.c](#find)
  - [8. input.c](#input)
  - [9. main.c](#main)
  - [10. main.h](#mainh)
  - [11. parser.c](#parser)
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

## 🛠️[Allowed Functions and System Calls](#allowed-functions-and-system-calls)

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

## ⚙️[Usage](#usage)

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

## 🗂️[Project Files](#project-files)

### [1. _memcpy.c](#memcpyc)
- **Description**: Implements the `_memcpy` function that copies a memory area from one location to another.
- **Purpose**: Used for copying a block of memory from the source to the destination.

### [2. _strcpy.c](#strcpyc)
- **Description**: Implements the `_strcpy` function that copies the string pointed to by `src` to the buffer pointed by `dest`.
- **Purpose**: Essential for copying strings within the shell's operations.

### [3. _strdup.c](#strdup)
- **Description**: Implements the `_strdup` function that creates a duplicate of a string by allocating new memory.
- **Purpose**: Useful when we need to duplicate strings, particularly for handling environment variables or command arguments.

### [4. _strncmp.c](#strncmp)
- **Description**: Implements the `_strncmp` function that compares up to `n` characters of two strings.
- **Purpose**: A custom comparison function to avoid using the standard `strncmp` for matching strings, often used for commands in the shell.

### [5. builtin.c](#builtin)
- **Description**: Implements the `handle_builtin` function that manages built-in shell commands like `exit`.
- **Purpose**: Allows the shell to execute internal commands directly without needing to invoke an external process.

### [6. executor.c](#executor)
- **Description**: Implements the `execute` function, which creates a child process to execute commands.
- **Purpose**: Handles the creation of processes for running commands within the shell.

### [7. find.c](#find)
- **Description**: Implements the `_which` function that finds the full path of a command using the `PATH` environment variable.
- **Purpose**: Determines the location of executable files, helping the shell find and execute commands.

### [8. input.c](#input)
- **Description**: Implements the `_getline` function that reads a line of input from a file descriptor (typically `stdin`).
- **Purpose**: Handles user input in the shell, enabling interaction with the program.

### [9. main.c](#main)
- **Description**: Implements the `main` function, which is the entry point of the custom shell.
- **Purpose**: Initializes and runs the shell, managing user input, command parsing, and execution.

### [10. main.h](#mainh)
- **Description**: Implements the header file `main.h`, which contains all necessary prototypes for the shell's functions.
- **Purpose**: Ensures proper function declaration and code organization throughout the shell program.

### [11. parser.c](#parser)
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






