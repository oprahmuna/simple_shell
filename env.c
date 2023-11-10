#include "shell.h"

/**
 * display_list - print the contents of the linked list
 * @current: The current node in the linked list.
 */
void display_list(struct Node *current)
{
	while (current != NULL)
	{
		write(STDOUT_FILENO, current->data, _strlen(current->data));
		write(STDOUT_FILENO, "\n", 1);
		current = current->next;
	}
}

/**
 * release_memory - free up memory allocated for each node in the linked list.
 * @start: The starting node of the linked list.
 */
void release_memory(struct Node *start)
{
	struct Node *temp;

	while (start != NULL)
	{
		temp = start;
		start = start->next;
		free(temp);
	}
}

/**
 * show_environment - print environment variables.
 *
 * Return: Always 0.
 */
int show_environment(void)
{
	char **env_ptr;
	struct Node *list_head = NULL;
	for (env_ptr = environ; *env_ptr != NULL; env_ptr++)
	{
		add_to_list(&list_head, create_node(*env_ptr));
	}

	display_list(list_head);
	release_memory(list_head);
	return (0);
}

/**
 * set_environment_variable - set an environment variable.
 * @var_name: The name of the environment variable.
 * @var_value: The value to be set.
 *
 * Return: Always 0.
 */
int set_environment_variable(const char *var_name, const char *var_value)
{
	char **env_ptr;
	struct Node *list_head = NULL;

	for (env_ptr = environ; *env_ptr != NULL; env_ptr++)
	{
		add_to_list(&list_head, create_node(*env_ptr));
	}

	modify_environment_variable(&list_head, var_name, var_value);
	update_environment(list_head);
	release_memory(list_head);
	return (0);
}

/**
 * unset_environment_variable - delete an environment variable.
 * @target_name: The name of the environment variable to be deleted.
 *
 * Return: 0 on success, -1 on failure.
 */
int unset_environment_variable(const char *target_name)
{
	char **current;
	char **env_ptr;
	size_t len = _strlen(target_name);

	for (env_ptr = environ; *env_ptr != NULL; env_ptr++)
	{
		if (_strncmp(*env_ptr, target_name, len) == 0 && (*env_ptr)[len] == '=')
		{
			for (current = env_ptr; *current != NULL; current++)
			{
				*current = *(current + 1);
			}
			return (0);
		}
	}
	return (-1);
}

