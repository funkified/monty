#include "monty.h"

void file_exec(FILE *file)
{

	unsigned int line_number = 0;
	char *line = NULL;
	char *opcode = NULL;
	char *arg = NULL;
	size_t size = 0;
	stack_t *stack;

	while (getline(&line, &size, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n\t\r");
		/*printf("opcode antes de:%s\n", opcode);*/
		if (opcode == NULL || strchr(opcode, '#') != NULL)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			/*printf("opcode push:%s\n", opcode);*/
			arg = strtok(NULL, " \n");
			if (arg != NULL)
			{
				push(&stack, line_number);
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free(opcode);
				free_stack(&stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
		}
		else
		{	
			/*printf("opcode difpush:%s\n", opcode);*/
			opcode_func(opcode, &stack, line_number);
		}
	}
	free(opcode);
	free_stack(&stack);
}

