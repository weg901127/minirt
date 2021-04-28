#include "minirt.h"

static void put_err()
{
	write(1, "Error\n", 6);
	//free split, line
}

int split_put_data(char **split, t_rt_info data, t_list *list)
{
	int cnt;
	cnt = count_split(split);
	if (ft_strcmp(*split, "R") == 0 && cnt == 3)
		return (add_r(split, data, list));
	else if (ft_strcmp(*split, "A") == 0 && cnt == 3)
		return (add_a(split, data, list));
	else if (ft_strcmp(*split, "c") == 0 && cnt == 4)
		return (add_c(split, data, list));
	else if (ft_strcmp(*split, "l") == 0 && cnt == 4)
		return (add_l(split, data, list));    
	else if (ft_strcmp(*split, "sp") == 0 && cnt == 4)
		return (add_sp(split, data, list));
	else if (ft_strcmp(*split, "pl") == 0 && cnt == 4)
		return (add_pl(split, data, list));
	else if (ft_strcmp(*split, "sq") == 0 && cnt == 5)
		return (add_sq(split, data, list));    
	else if (ft_strcmp(*split, "cy") == 0 && cnt == 6)
		return (add_cy(split, data, list));
	else if (ft_strcmp(*split, "tr") == 0 && cnt == 5)
		return (add_tr(split, data, list));
	else if (ft_strcmp(*split, "") == 0)
		return (0);
	return (-1);
}

int set_list(t_list *list /*, char *argv*/)
{
	int fd;
	char *line;
	char **split;
	t_rt_info data;

	fd = open(/*argv[1]*/ "mini.rt", O_RDWR);
		while (get_next_line(fd, &line) > 0)
		{
			if (*line != '\0')
			{
				split = ft_split(line, ' ');
				if (split_put_data(split, data, list) < 0)
				{
					put_err();
					return(-1);
				}
				printf("%s\n",list->tail->data.id);
				split = allo_free(split);
			}
			free(line);
		}
		if (check_id(list) == -1)
		{
			put_err();
			return (-1);
		}
	close(fd);
	return (0);
}

int main(/*int argc, char *argv[]*/void) {
	t_list *list;

	init_list(&list);

	//if (argc == 2 && strcmp(argv[1] + strlen(argv[1]) - 3,".rt") == 0)
		set_list(list);
	//else
	//	put_err();
	
	//list 사용 다 끝난 후
	del_node(&list);

	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked | rm -rf leaks_result_temp");
	return (0);
}