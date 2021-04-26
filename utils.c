#include "minirt.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int			i;

	i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	//while (s1[i] == s2[i] && s1[i] && s2[i])
 	//	i++;
 	//return ((unsigned char)s1[i] - (unsigned char)s2[i]);

	return (s1[i] - s2[i]);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dst == 0 || src == 0)
		return (0);
	while (src[i] != '\0')
		i++;
	while (src[j] != '\0' && j < dstsize - 1 && dstsize != 0)
	{
		dst[j] = src[j];
		j++;
	}
	if (dstsize > 0)
		dst[j] = '\0';
	return (i);
}

int count_split(char **split)
{
	int i = 0;
	while (*split++ != 0)
		i++;
	return (i);
}