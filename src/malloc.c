/*
** malloc.c for PSU_2015_malloc in /home/tixado_d/epitech/rendu/PSU_2015_malloc/src
**
** Made by tixador
** Login   <tixado_d@epitech.net>
**
** Started on  Tue Feb 02 14:14:52 2016 tixador
** Last update Sun Feb 14 16:18:49 2016 Dany Tixador
*/

#include "../include/malloc.h"

pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

int		the_first_time(t_block block, size_t size)
{
  block = request_space(NULL, size);
  if (!block)
    return (0);
  g_base = block;
  return (1);
}

void		*tools_malloc(size_t size)
{
  t_block	block;

  if (!g_base)
    {
      if (!(block = request_space(NULL, size)))
        return (NULL);
      g_base = block;
    }
  else
    {
      t_block	last;

      last = g_base;
      block = search_first_fit(&last, size);
      if (!block)
      	{
      	  block = request_space(last, size);
      	  if (!block)
      	    return (NULL);
      	}
      else
      	block->free = 0;
    }
  pthread_mutex_unlock(&g_mutex);
  return (block + 1);
}

void		*malloc(size_t size)
{
  if (size <= 0)
    return (NULL);
  pthread_mutex_lock(&g_mutex);
  return (tools_malloc(size));
}
