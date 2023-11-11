#include "shell.h"

/**
* _memcpy - Copy memory from source to destination.
* @dest: Destination pointer.
* @src: Source pointer.
* @n: Number of bytes to copy.
* Return: Pointer to destination.
*/
void *_memcpy(void *dest, const void *src, size_t n)
{
	char *cdest = (char *)dest;
	const char *csrc = (const char *)src;

	for (size_t i = 0; i < n; i++)
	{
		cdest[i] = csrc[i];
	}

	return (dest);
}

/**
* _realloc - Reallocate memory for a pointer.
* @ptr: Pointer to be reallocated.
* @size: New size of the memory.
* Return: New pointer.
*/
void *_realloc(void *ptr, size_t size)
{
	if (ptr == NULL)
	{
		return (malloc(size));
	}

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

void *new_ptr = malloc(size);

if (new_ptr == NULL)
{
	return (NULL);
}

_memcpy(new_ptr, ptr, size);
free(ptr);

return (new_ptr);
}

/**
* _strdup - Duplicate a string.
* @s: Input string.
* Return: Pointer to the duplicated string.
*/
char *_strdup(const char *s)
{
	size_t len = _strlen(s) + 1;
	char *new_str = malloc(len);

	if (new_str == NULL)
	{
		return (NULL);
	}

	_memcpy(new_str, s, len);

	return (new_str);
}

/**
* _strcat - Concatenate two strings.
* @dest: Destination string.
* @src: Source string.
* Return: Pointer to the concatenated string.
*/
char *_strcat(char *dest, const char *src)
{
	char *p = dest;
	int i = 0;

	while (*p)
	{
		p++;
	}

	while (*src)
	{
		*p++ = *src++;
	}

	*p = '\0';

	return (dest);
}

/**
* _strchr - Locate a character in a string.
* @str: Input string.
* @character: Character to find.
* Return: Pointer to the first occurrence of the character in the string,
*         or NULL if the character is not found.
*/
char *_strchr(const char *str, int character)
{
	while (*str)
	{
		if (*str == character)
		{
			return ((char *)str);
		}
		str++;
	}

	return (NULL);
}
