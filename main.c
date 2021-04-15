#include <stdio.h>
#include <fcntl.h>
#include "gnl/get_next_line.h"
#include "minirt.h"
#include <string.h>

static void put_err()
{
  write(1, "Error\n", 6);
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
    get_next_line(fd, &line);
    //A R
    //해상도 예외처리 --> 0보다는 무조건 커야한다 (width, height)
    //각각 요소들의 필수 (R 1920 1080) --> split  하면 3덩어리 나온다..
    // 방법 1 
    // 처음에 split으로 잘라서 str 개수를 카운팅
    // split한 결과를 또 split
    split = ft_split(line, ' ');
    int k;
    char **tmp = split;
    while (*tmp++)
      k++;
    if (**split == 'R')
    {

        data.id = "R";
        split++;
        data.resolution.width = ft_atoi(*split);
        split++;
        data.resolution.height = ft_atoi(*split);
        add_node(list, data);
    }
    printf("%s %d %d",list->head->data.id, list->head->data.resolution.width, list->head->data.resolution.height);
    //
    

    close(fd);
    free(line);
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
