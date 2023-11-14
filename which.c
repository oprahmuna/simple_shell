#include "shell.h"

/**
* findExecutablePath - find the executable path for a given command
* @command: command
* Return: path to executable, or NULL if not found
*/
char *findExecutablePath(char *command)
{
	char *path = _getenv("PATH");
	char *path_copy;
	char *dir;

	if (path == NULL)
	{
		return (NULL);
	}
	path_copy = _strdup(path);
	dir = _strtok(path_copy, ":");

	while (dir != NULL)
	{
		char full_path[1024];

		_custom_strcpy(full_path, dir);
		_custom_strcat(full_path, "/");
		_custom_strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (_strdup(full_path));
		}
		dir = _strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/**
* displayAllAliases - display all aliases
* @aliases: aliases
*/
void displayAllAliases(alias_t *aliases)
{
	alias_t *alias;

	for (alias = aliases; alias; alias = alias->next)
		displayAlias(alias);
}
