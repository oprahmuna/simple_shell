#include "shell.h"

/**
 * print_list - Print the contents of the linked list.
 * @head: The head of the linked list.
 */
void print_list(struct Node *head)
{
	while (head != NULL)
	{
		write(STDOUT_FILENO, head->str, _strlen(head->str));
		write(STDOUT_FILENO, "\n", 1);
		head = head->next;
	}
}

/**
 * free_list - Free up memory allocated for each node in the linked list.
 * @head: The head of the linked list.
 */
void free_list(struct Node *head)
{
	struct Node *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _setenv - Set an environment variable.
 * @name: The name of the environment variable.
 * @value: The value to be set.
 *
 * Return: Always 0.
 */
int _setenv(const char *name, const char *value)
{
	char **env;
	struct Node *head = NULL;
	/*extern char **environ;*/

	for (env = environ; *env != NULL; env++)
	{
		add_node(&head, new_node(*env));
	}

	add_env_var(&head, name, value);

	update_environ(head);

	free_list(head);
	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
