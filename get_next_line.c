/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** __description__
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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

	if (dest == NULL || src == NULL)
		return (NULL);
	len = my_strlen(dest , '\0') + n + 2;
	if (!(tmp = malloc(sizeof(char) * len)))
		return (NULL);
	for (; dest[i] != '\0'; i++)
		tmp[i] = dest[i];
	for (int t = 0; src[t] != '\0' && t < n; t++) {
		tmp[i] = src[t];
		i++;
	}
	tmp[i] = '\0';
	if (my_strlen(dest, '\0') > 0)
		free(dest);
	return (tmp);
}

int get_n_pos(char const *str)
{
	if (str == NULL)
		return (-1);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '\n')
			return (i);
	}
	return (-1);
}

char *get_next_line(int fd)
{
	static char buffer[READ_SIZE + 1] = {0};
	static size_t wtf = 0;
	char *tmp = "";
	int i = 0;
	int n = 0;
	int pos;

	while (my_strlen(buffer, '\n') == -1) {
		n = read(fd, buffer, READ_SIZE);
		if (n <= 0)
			return ((wtf++) ? NULL : buffer);
		if (my_strlen(buffer, '\n') == -1)
			tmp = my_strncat(tmp, buffer, n);
	}
	pos = my_strlen(buffer, '\n');
	tmp = my_strncat(tmp, buffer, pos);
	for (i = 0; i < my_strlen(buffer, '\0'); i++)
		buffer[i] = buffer[pos + i + 1];
	for (; buffer[i] != '\0'; buffer[i++] = '\0');
	return (tmp);
}
