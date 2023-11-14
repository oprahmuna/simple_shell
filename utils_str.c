#include "shell.h"

/**
* _c_strcmp - compare 2 strings
* @str1: first string
* @str2: second string
* Return: 0 if equal, otherwise the difference of first differing characters
*/
int _c_strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (str1[i] - str2[i]);
}

/**
* _c_strncmp - compare 2 strings
* @s1: first string
* @s2: second string
* @n: size limit
* Return: 0 if equal, otherwise the difference of first differing characters
*/
int _c_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}

	if (i < n)
	{
		return (s1[i] - s2[i]);
	}

	return (0);
}

/**
* _c_strlen - string length
* @str: string
* Return: length of the string
*/
int _c_strlen(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
* _c_strncpy - copy string up to a specified limit
* @dest: destination
* @src: source string
* @size: number of characters to be copied
* Return: size of characters copied
*/
int _c_strncpy(char *dest, char *src, int size)
{
	int i = 0;

	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return (i);
}

/**
* _c_strcpy - string copy
* @dest: destination
* @src: source string
* Return: size of characters copied
*/
int _c_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return (i);
}

