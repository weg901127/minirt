#include "minirt.h"

int check_int(char *s)
{
	if (*s == '-')
		s++;
	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
			return (-1);
		s++;
	}
	return (0);
}

int check_double(char *s)
{
	if (*s == '-')
		s++;
	while (*s != '\0' && *s != '.')
	{
		if (*s < '0' || *s > '9')
			return (-1);
		s++;
	}
	if (*s == '.')
	{
		s++;
		while (*s != '\0')
		{
		if (*s < '0' || *s > '9')
			return (-1);
		s++;
		}
	}	
	return (0);
}

int check_id(t_list *list)
{
	if (count_node(list, "R") != 1 || count_node(list, "A") != 1)
	{
		return (-1);
	}
	return (0);
}