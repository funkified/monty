#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

extern char *args;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_t *add_dnodeint(stack_t **head, const int);
void push(stack_t **stack, unsigned int n);
void pall(stack_t **stack, unsigned int line);
void pop(stack_t **stack, unsigned int line);
void opcode_func(char *opcode, stack_t **stack, unsigned int line);
void file_exec(FILE *file);
void pint(stack_t **stack, unsigned int line);
void free_stack(stack_t **stack);
void read_file(char *file, stack_t **stack);
bool find_arg(char *arg);
void swap(stack_t **stack, unsigned int line);
void add(stack_t **stack, unsigned int line);
void nop(stack_t **stack, unsigned int line);
void sub(stack_t **stack, unsigned int line);
void _div(stack_t **stack, unsigned int line);
void mul(stack_t **stack, unsigned int line);

#endif
