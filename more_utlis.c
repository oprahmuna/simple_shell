#include "shell.h"

/**
* trim_spaces - Removes trailing and leading spaces from a string.
* @str: String to modify.
*/
void trim_spaces(char *str)
{
	size_t len = _strlen(str);
	size_t start = 0;
	size_t i;

/* Remove trailing spaces */
	if (len > 0)
	{
		while (len > 0 && str[len - 1] == ' ')
			len--;
		str[len] = '\0';
	}

/* Find the starting position after removing trailing spaces */
	while (str[start] == ' ')
		start++;

/* Shift the string to remove leading spaces */
	if (start > 0)
	{
		i = 0;
		while (str[start + i] != '\0')
		{
			str[i] = str[start + i];
			i++;
		}
		str[i] = '\0';
	}
}

/**
* tokenize_string - Splits a string into an array of tokens.
* @input: String to tokenize.
* @tokens: Array to store tokens.
*/
void tokenize_string(char *input, char *tokens[MAX_TOKENS])
{
	char *token;
	int i = 0;

	token = custom_strtok(input, " ");
	while (token != NULL)
	{
		tokens[i++] = token;
		token = custom_strtok(NULL, " ");
	}
	tokens[i] = NULL;
}

/**
* count_arguments - Counts the number of arguments in an array of strings.
* @args: Array of arguments.
* Return: Number of arguments.
*/
int count_arguments(char *args[])
{
	int count = 0;

	while (args[count] != NULL)
		count++;

	return (count);
}

/**
* _atoi - Converts a string to an integer.
* @str: String to convert.
* Return: Integer value of the string.
*/
int _atoi(const char *str)
{
	int i, num = 0;
	int sign = 1;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '-')
			sign = -1;
		else if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + (str[i] - '0');
		else
			break;
	}

	return (num * sign);
}

/**
* _1exit - Exits the program with a specified status code.
* @status: Status code to exit with.
* @command_count: Count of the command.
* @shell_name: Name of the shell.
* @command_args: String of input command arguments.
* Return: Exit code.
*/
int _1exit(char *status __attribute__((unused)), int command_count, char *shell_name, char **command_args)
{
	int exit_code = ex_code;
	int i;

	if (status != NULL)
	{
		i = 0;
		while (status[i])
		{
			if (!(status[i] >= '0' && status[i] <= '9'))
			{
				print_error(shell_name, command_count, command_args[0], command_args[1]);
				ex_code = 2;
				return (500);
			}
			i++;
		}
		exit_code = custom_atoi(status);
	}
	return (exit_code);
}
