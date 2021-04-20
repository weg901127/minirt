#include "minirt.h"

void  init_list(t_list **list)
{
  *list = (t_list *)malloc(sizeof(t_list));
  (*list)->cur = NULL;
  (*list)->head = NULL;
  (*list)->tail = NULL;
}

void  add_node(t_list *list, t_rt_info data)
{
  t_node  *new_node;

  new_node = (t_node *)malloc(sizeof(t_node));
  new_node->data = data;
  new_node->next = NULL;
  if (list->head == NULL && list->tail == NULL)
  {
    list->head = new_node;
    list->tail = new_node;
  }
  else
  {
    list->tail->next = new_node;
    list->tail = new_node;
  }
}
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
	return (0);
}

void search_node(t_list *list, char *s)
{
  while (list->cur != 0)
  {
    if(ft_strcmp(list->cur->data.id, s) == 0)
    {
      return ;
    }
    else
      list->cur = list->cur->next;
  }
}

void del_node(t_list *list)
{
  while (list->cur != 0)
  {
    free(list->cur);
    list->cur = list->cur->next;
  }
  free(list);
}

/*
int main()
{
  t_list    *list;
  t_rt_info data;
  t_rt_info data1;
  t_rt_info data2;
  t_rt_info data3;

  init_list(&list);
  data.id = "aa";
  data.brightness = 1;
  data.color.red = 255;
  data.color.green = 255;
  data.color.blue = 255;
  add_node(list, data);
  
  data1.id = "bb";
  data2.id = "cc";
  data3.id = "dd";
  add_node(list, data1);
  add_node(list, data2);
  add_node(list, data3);

  list->cur = list->head;
  search_node(list, "cc");
  printf("%s", list->cur->data.id);
  free(list);
  return (0);
}
*/