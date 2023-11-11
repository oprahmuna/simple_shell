#include "shell.h"

/**
* cd - change directory
* @path: path to change to
*
* Return: 0 on success, 1 on failure
*/
int cd(const char *path)
{
	char *home = _getenv("HOME");
	char *oldpwd = _getenv("OLDPWD");
	char *pwd = _getenv("PWD");
	char cwd[1024];
	int chdir_ret;
	char *dir;

	if (path == NULL)
	{
		if (chdir(home) != 0)
		{
			perror("chdir");
			return (1);
		}
		setenv("OLDPWD", pwd, 1);
		setenv("PWD", home, 1);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
	{
		chdir_ret = chdir(info->argv[1]);
		if (chdir_ret == -1)
		{
			print_error(info, "can't cd to ");
			_eputs(info->argv[1]), _eputchar('\n');

		}
		else
		{
			_setenv(info, "OLDPWD", _getenv(info, "PWD="));
			_setenv(info, "PWD", getcwd(buffer, 1024));
		}
	}
	return (0);
}
