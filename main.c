#include "minirt.h"

/*
static void put_err()
{
  write(1, "Error\n", 6);
}
*/
static void set_R(char **split, t_list **list, t_rt_info *data)
{
	char	**tmp;

	tmp = split;
	data->id = "R";
	tmp++;
	data->resolution.width = ft_atoi(*tmp);
	tmp++;
	data->resolution.height = ft_atoi(*tmp);
	add_node(*list, *data);
}

static void check_var(char ***split, t_list **list, t_rt_info *data)
{
	int		k;
	char	**tmp;

	k = 0;
	tmp = *split;
	while (*tmp++)
		k++;
	if (***split == 'R' && k == 3)
		set_R(*split, list, data);
	/*
	else if(**split == '')
	else if(**split == '')
	else if(**split == '')
	else if(**split == '')
	*/
}

int main()
//int main(int argc, char *argv[])
{
	char		*line;
	char		**split;
	t_list		*list;
	t_rt_info	data;
	int			k;

	init_list(&list);
//	if (argc == 2 && strcmp(argv[1] + strlen(argv[1]) - 3,".rt") == 0)
//	{
//		int fd = open(argv[1],O_RDWR);
	int fd = open("mini.rt",O_RDWR);

	while(get_next_line(fd, &line) && *line != 0)
	{
		split = ft_split(line, ' ');
		check_var(&split, &list, &data);
		k = 0;
		while(*(split + k) != 0)
			free(*(split + k++));
		free(split);
		free(line);
	}
	printf("%s %d %d",list->head->data.id, list->head->data.resolution.width, list->head->data.resolution.height);
	close(fd);
	//free(line);
	free_node(&list);
//	}
//	else
//	put_err();
	while(1);
	return 0;
}


//R, A는 필수(1개)
//c, cy 구분
//필요한 요소만 정확히 들어왔는지(슬데없는 값이 추가로 있지 않은지)
//값 범위 유효성검사


//단방향
//초기화
//삽입, 탐색
/*

char *id
s_xyz coordinates1
s_xyz coordinates2
s_xyz coordinates3
s_xyz 3d normalized orientation vector.(-1 ~ 1)
s_color color
un int view_degree (0 ~ 180)
un float brightness
un float diameter
un float side_size

*/
