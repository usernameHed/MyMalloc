/*
** malloc_tools.c for  in /home/tixado_d/epitech/rendu/PSU_2015_malloc/src
** 
** Made by Dany Tixador
** Login   <tixado_d@epitech.net>
** 
** Started on  Sun Feb 14 15:41:41 2016 Dany Tixador
** Last update Sun Feb 14 16:14:09 2016 Dany Tixador
*/

#include "../include/malloc.h"

void		show_alloc_mem()
{
  t_block	tmp;
  size_t	s;

  tmp = g_base;
  printf("break : %p\n", sbrk(0));
  while (tmp)
    {
      s = (size_t)(tmp->size);
      printf("%p - %p : %lu bytes\n", tmp + META_SIZE, tmp + META_SIZE + s, s);
      tmp = tmp->next;
    }
}

t_block		search_first_fit(t_block *last, size_t size)
{
  t_block	current;

  current = g_base;
  while (current != NULL && !(current->free && current->size >= size))
    {
      *last = current;
      current = current->next;
    }
  return (current);
}

t_block		request_space(t_block last, size_t size)
{
  t_block	block;

  if ((block = sbrk(size + META_SIZE)) == NULL)
    return (NULL);
  if (last)
    last->next = block;
  block->size = size;
  block->next = NULL;
  block->free = 0;
  return (block);
}
