#include <stdio.h>
#include <fcntl.h>
#include "gnl/get_next_line.h"
#include "minirt.h"
#include <string.h>

static void put_err()
{
  write(1, "Error\n", 6);
}

int add_r(char **split, t_rt_info data, t_list *list)
{
  data.id = "R";
  split++;
  data.resolution.width = ft_atoi(*split);
  split++;
  data.resolution.height = ft_atoi(*split);
  if (data.resolution.width == 0 || data.resolution.height == 0)
    return (0);
  add_node(list, data);
  return (1);
}
int add_a(char **split, t_rt_info data, t_list *list)
{
  char **tmp;
  data.id = "A";
  split++;
  data.brightness = atof(*split);
  split++;
  tmp = ft_split(*split, ',');
  data.color.red = atoi(*tmp);
  tmp++;
  data.color.green = atoi(*tmp);
  tmp++;
  data.color.blue = atoi(*tmp);
  //tmp = allo_free(tmp);
  add_node(list, data);
  return (1);
}

int add_c(char **split, t_rt_info data, t_list *list)
{
  char **coordinate;
  char **normal_vector;
  data.id = "c";
  split++;
  coordinate = ft_split(*split, ',');
  data.coor1.x = atoi(*coordinate);
  coordinate++;  
  data.coor1.y = atoi(*coordinate);
  coordinate++;  
  data.coor1.z = atoi(*coordinate);
  split++;
  normal_vector = ft_split(*split, ',');
  data.normalized_vector.x = atof(*normal_vector);
  normal_vector++;
  data.normalized_vector.y = atof(*normal_vector);
  normal_vector++;
  data.normalized_vector.z = atof(*normal_vector);
  split++;
  data.view_degree = atoi(*split);
  //allo_free(coordinate);
  //allo_free(normal_vector);
  add_node(list, data);
  return (1);
}

int add_l(char **split, t_rt_info data, t_list *list)
{
  char **coordinate;
  char **color;
  data.id = "l";
  split++;
  coordinate = ft_split(*split, ',');
  data.coor1.x = atof(*coordinate);
  coordinate++;
  data.coor1.y = atof(*coordinate);
  coordinate++;
  data.coor1.z = atof(*coordinate);
  split++;
  data.brightness = atof(*split);
  split++;
  color = ft_split(*split, ',');
  data.color.red = atoi(*color);
  color++;
  data.color.green = atoi(*color);
  color++;
  data.color.blue = atoi(*color);
  //color = allo_free(color);
  add_node(list, data);
  return (1);
}

int add_sp(char **split, t_rt_info data, t_list *list)
{
  char **coordinate;
  char **color;

  data.id = "sp";
  split++;
  coordinate = ft_split(*split, ',');
  data.coor1.x = atof(*coordinate);
  coordinate++;
  data.coor1.y = atof(*coordinate);
  coordinate++;
  data.coor1.z = atof(*coordinate);
  split++;
  data.diameter = atof(*split);
  split++;
  color = ft_split(*split, ',');
  data.color.red = atoi(*color);
  color++;
  data.color.green = atoi(*color);
  color++;
  data.color.blue = atoi(*color);
  add_node(list, data);
  return (1);
}
int add_pl(char **split, t_rt_info data, t_list *list)
{
  char **coordinate;
  char **color;
  char **normal_vector;

  data.id = "pl";
  split++;
  coordinate = ft_split(*split, ',');
  data.coor1.x = atof(*coordinate);
  coordinate++;
  data.coor1.y = atof(*coordinate);
  coordinate++;
  data.coor1.z = atof(*coordinate);
  split++;
  normal_vector = ft_split(*split, ',');
  data.normalized_vector.x = atof(*normal_vector);
  normal_vector++;
  data.normalized_vector.y = atof(*normal_vector);
  normal_vector++;
  data.normalized_vector.z = atof(*normal_vector);
  split++;
  color = ft_split(*split, ',');
  data.color.red = atoi(*color);
  color++;
  data.color.green = atoi(*color);
  color++;
  data.color.blue = atoi(*color);
  add_node(list, data);
  return (1);
}

int add_sq(char **split, t_rt_info data, t_list *list)
{
  char **coordinate;
  char **normal_vector;
  char **color;

  data.id = "sq";
  split++;
  coordinate = ft_split(*split, ',');
  data.coor1.x = atof(*coordinate);
  coordinate++;
  data.coor1.y = atof(*coordinate);
  coordinate++;
  data.coor1.z = atof(*coordinate);
  split++;
  normal_vector = ft_split(*split, ',');
  data.normalized_vector.x = atof(*normal_vector);
  normal_vector++;
  data.normalized_vector.y = atof(*normal_vector);
  normal_vector++;
  data.normalized_vector.z = atof(*normal_vector);
  split++;
  data.side_size = atof(*split);
  split++;
  color = ft_split(*split, ',');
  data.color.red = atoi(*color);
  color++;
  data.color.green = atoi(*color);
  color++;
  data.color.blue = atoi(*color);
  add_node(list, data);
  return (1);
}
int add_cy(char **split, t_rt_info data, t_list *list)
{
  char **coordinate;
  char **normal_vector;
  char **color;

  data.id = "cy";
  split++;
  coordinate = ft_split(*split, ',');
  data.coor1.x = atof(*coordinate);
  coordinate++;
  data.coor1.y = atof(*coordinate);
  coordinate++;
  data.coor1.z = atof(*coordinate);
  split++;
  normal_vector = ft_split(*split, ',');
  data.normalized_vector.x = atof(*normal_vector);
  normal_vector++;
  data.normalized_vector.y = atof(*normal_vector);
  normal_vector++;
  data.normalized_vector.z = atof(*normal_vector);
  split++;
  data.diameter = atof(*split);
  split++;
  data.side_size = atof(*split);
  split++;
  color = ft_split(*split, ',');
  data.color.red = atoi(*color);
  color++;
  data.color.green = atoi(*color);
  color++;
  data.color.blue = atoi(*color);
  add_node(list, data);
  return (1);
}
int add_tr(char **split, t_rt_info data, t_list *list)
{
  char **coordinate1;
  char **coordinate2;
  char **coordinate3;  
  char **color;

  data.id = "tr";
  split++;
  coordinate1 = ft_split(*split, ',');
  data.coor1.x = atof(*coordinate1);
  coordinate1++;
  data.coor1.y = atof(*coordinate1);
  coordinate1++;
  data.coor1.z = atof(*coordinate1);
  split++;
  coordinate2 = ft_split(*split, ',');
  data.coor2.x = atof(*coordinate2);
  coordinate2++;
  data.coor2.y = atof(*coordinate2);
  coordinate2++;
  data.coor2.z = atof(*coordinate2);
  split++;
  coordinate3 = ft_split(*split, ',');
  data.coor3.x = atof(*coordinate3);
  coordinate3++;
  data.coor3.y = atof(*coordinate3);
  coordinate3++;
  data.coor3.z = atof(*coordinate3);
  split++;
}

int split_put_data(char **split, t_rt_info data, t_list *list)
{
  if (strcmp(*split, "R") == 0)
    return (add_r(split, data, list));
  else if (strcmp(*split, "A") == 0)
    return (add_a(split, data, list));
  else if (strcmp(*split, "c") == 0)
    return (add_c(split, data, list));
  else if (strcmp(*split, "l") == 0)
    return (add_l(split, data, list));    
  else if (strcmp(*split, "sp") == 0)
    return (add_sp(split, data, list));
  else if (strcmp(*split, "pl") == 0)
    return (add_pl(split, data, list));
  else if (strcmp(*split, "sq") == 0)
    return (add_sq(split, data, list));    
  else if (strcmp(*split, "cy") == 0)
    return (add_cy(split, data, list));
  else if (strcmp(*split, "tr") == 0)
    return (add_tr(split, data, list));
  else if (strcmp(*split, "") == 0)
    return (1);
  return (0);
}

int main(int argc, char *argv[]) {
  char *line;
  char **split;
  t_list *list;
  t_rt_info data;

  init_list(&list);


  if (argc == 2 && strcmp(argv[1] + strlen(argv[1]) - 3,".rt") == 0)
  {
    int fd = open(argv[1],O_RDWR);
    while (get_next_line(fd, &line) != 0)
    {
      if (strcmp(line, "") == 0)
        *split = "";
      else
        split = ft_split(line, ' ');
      if (split_put_data(split, data, list) == 0)
      {
        put_err();
        break;
      }
      printf("%s\n",list->tail->data.id);
      //split = allo_free(split);
      free(line);
      
    }
    
    //
    close(fd);
    }
  else
    put_err();
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
