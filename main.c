#include "monty.h"

/**
 * main - Entry point
 * @argc: num arguments
 * @argv: array with argumente
 * Description:  return success
 * Return: int
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	file_exec(file);
	/*read_file(argv[1], &stack);*/
	fclose(file);
	exit(EXIT_SUCCESS);
}
/*void read_file(char *file, stack_t **stack)
{
	size_t len;
	ssize_t read_line;
	unsigned int num = 0;
	char *line = NULL;
	char *command;
	FILE *fd;

	fd = fopen(file, "r");
	if (!fd)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while ((read_line = getline(&line, &len, fd)) != -1)
	{
		command = strtok(line, "\n");
		num++;

		if (command)
			parse_command(stack, command, num);
			opcode_func(command, stack, num);
	}

	if (line)
		free(line);
	fclose(fd);
}
*/
