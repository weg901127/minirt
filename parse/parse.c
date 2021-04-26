#include "../minirt.h"
/*
int main()
//int main(int argc, char *argv[])
{
	int			res;
	char		*line;
	char		**split;
	t_list		*list;

	init_list(&list);
//	if (argc == 2 && strcmp(argv[1] + strlen(argv[1]) - 3,".rt") == 0)
//	{
//		int fd = open(argv[1],O_RDWR);
	int fd = open("mini.rt",O_RDWR);

	while(get_next_line(fd, &line) >= 0)
	{
		if (*line != 0)
		{
			split = ft_split(line, ' ');
			res = check_var(&split, &list);
			free_split(&split);
			if (res)
				return (put_err(&line, fd, &list));	
		}
			free(line);
	}
	free(line);
	list->cur = list->head;
	while (list->cur)
	{
		printf("id : %s",list->cur->data.id);
		if (list->cur->data.resolution.width + list->cur->data.resolution.height)
			printf("\nresolution.width : %d, %d",list->cur->data.resolution.width,list->cur->data.resolution.height);
		if (list->cur->data.coor1.x + list->cur->data.coor1.y + list->cur->data.coor1.z)
			printf("\ncoor1.xyz : %f, %f, %f",list->cur->data.coor1.x,list->cur->data.coor1.y,list->cur->data.coor1.z);
		if (list->cur->data.coor2.x + list->cur->data.coor2.y + list->cur->data.coor2.z)
			printf("\ncoor2.xyz : %f, %f, %f",list->cur->data.coor2.x,list->cur->data.coor2.y,list->cur->data.coor2.z);
		if (list->cur->data.coor3.x + list->cur->data.coor3.y + list->cur->data.coor3.z)
			printf("\ncoor3.xyz : %f, %f, %f",list->cur->data.coor3.x,list->cur->data.coor3.y,list->cur->data.coor3.z);
		if (list->cur->data.normalized_vector.x + list->cur->data.normalized_vector.y + list->cur->data.normalized_vector.z)
			printf("\nvec.xyz : %f, %f, %f",list->cur->data.normalized_vector.x,list->cur->data.normalized_vector.y,list->cur->data.normalized_vector.z);
		if (list->cur->data.color.red + list->cur->data.color.green + list->cur->data.color.blue)
			printf("\ncolor.rgb : %f, %f, %f",list->cur->data.color.red,list->cur->data.color.green,list->cur->data.color.blue);
		if (list->cur->data.view_degree)
			printf("\nview_degree : %d",list->cur->data.view_degree);
		if (list->cur->data.brightness)
			printf("\nbrightness : %f",list->cur->data.brightness);
		if (list->cur->data.diameter)
			printf("\ndiameter : %f",list->cur->data.diameter);
		if (list->cur->data.side_size)
			printf("\nside_size : %f",list->cur->data.side_size);
		printf("\n--------------------------\n");
		list->cur = list->cur->next;
	}
	close(fd);
	free_node(&list);
//	}
//	else
//	put_err();
	//while(1);
	return 0;
}
*/

int parse(int argc, char **argv, t_list **list)
{
	int			fd;
	char		*line;
	char		**split;
	//t_list		*list;

	if (argc == 2 && strcmp(argv[1] + strlen(argv[1]) - 3,".rt") == 0)
	{
		init_list(list);
		fd = open(argv[1],O_RDWR);
		while(get_next_line(fd, &line) >= 0)
		{
			if (*line != 0)
			{
				split = ft_split(line, ' ');
				if (check_var(&split, list))
					return (put_err(&line, fd, list, &split));
				free_split(&split);
			}
				free(line);
		}
		free(line);
		close(fd);
		free_node(list); //밖에서..
	}
	else
		return (write(1, "Error\n", 6));
	return DONE;
}
