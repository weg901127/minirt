#include "../minirt.h"

int parse(int argc, char **argv, t_list **list)
{
	int			fd;
	char		*line;
	char		**split;

//	if (argc == 2 && strcmp(argv[1] + strlen(argv[1]) - 3,".rt") == 0)
//	{
		init_list(list);
//		fd = open(argv[1],O_RDWR);
		fd = open("mini.rt",O_RDWR);
		while(get_next_line(fd, &line) >= 0)
		{
			if (*line != 0)
			{
				split = ft_split(line, ' ');
				if (check_split(&split) || check_var(&split, list))
					return (put_err(&line, fd, list, &split));
				free_split(&split);
			}
				free(line);
		}
		free(line);
		close(fd);
//	}
//	else
//		return (write(1, "Error\n", 6));
	return (DONE);
}
