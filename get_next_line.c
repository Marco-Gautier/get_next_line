/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** __description__
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int my_strlen(char const *str, char c)
{
	if (str == NULL)
		return (-1);
	for (int i = 0; str[i] != '\0' || str[i] == c; i++) {
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

char *my_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int len;
	char *tmp;

	if (src == NULL)
		return (NULL);
	len = my_strlen(dest , '\0') + n + 2;
	if (!(tmp = malloc(sizeof(char) * len)))
		return (NULL);
	for (; dest && dest[i] != '\0'; i++)
		tmp[i] = dest[i];
	for (int t = 0; src && src[t] != '\0' && t < n; t++) {
		tmp[i] = src[t];
		i++;
	}
	tmp[i] = '\0';
	if (my_strlen(dest, '\0') > 0)
		free(dest);
	return (tmp);
}

char *my_strndup(const char *str, int n)
{
	int i = 0;
	char *tmp;

	if (!(tmp = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	for (; i < n; i++)
		tmp[i] = str[i];
	tmp[i] = '\0';
	return (tmp);
}

char *get_next_line(int fd)
{
	static char *tmp = NULL;
	char buffer[READ_SIZE + 1] = {0};
	char *str = NULL;
	int n = 0;
	int pos;

	while (my_strlen(tmp, '\n') == -1) {
		n = read(fd, buffer, READ_SIZE);
		if (n <= 0) {
			str = tmp;
			tmp = NULL;
			return (str);
		}
		tmp = my_strncat(tmp, buffer, n);
	}
	pos = my_strlen(tmp, '\n');
	str = my_strndup(tmp, pos);
	tmp = my_strndup(tmp + pos + 1, my_strlen(tmp + pos + 1, '\0'));
	return (str);
}
