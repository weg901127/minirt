/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 02:21:56 by gilee             #+#    #+#             */
/*   Updated: 2021/04/27 02:21:58 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pb;
	unsigned char	pc;

	pb = b;
	pc = c;
	while (len-- > 0)
		*pb++ = pc;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void *rest;

	if (!(rest = (void *)malloc(count * size)))
		return (NULL);
	ft_memset(rest, 0, (count * size));
	return (rest);
}

void  init_list(t_list **list)
{
  *list = (t_list *)ft_calloc(1, sizeof(t_list));
  (*list)->cur = NULL;
  (*list)->head = NULL;
  (*list)->tail = NULL;
}

void  add_node(t_list *list, t_rt_info *data)
{
  t_node  *new_node;

  new_node = (t_node *)ft_calloc(1, sizeof(t_node));
  new_node->data = *data;
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

void free_node(t_list **list)
{
  t_node *tmp;

  (*list)->cur = (*list)->head;
  while ((*list)->cur)
  {
    tmp = (*list)->cur->next;
    free((*list)->cur);
    (*list)->cur = tmp;
  }
  free(*list);
}
