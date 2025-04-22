#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

void prompt_display(void);
char *read_line(void);
char **split_line(char *line);
void execute_command(char *command, char **argv);
void _puts(char *str);
int _strlen(char *s);
void print_error(char *name, char *cmd);

#endif
