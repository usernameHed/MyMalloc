/*
** free.c for PSU_2015_malloc in /home/tixado_d/epitech/rendu/PSU_2015_malloc/src
**
** Made by tixador
** Login   <tixado_d@epitech.net>
**
** Started on  Thu Feb 04 15:16:07 2016 tixador
** Last update Sun Feb 14 16:09:23 2016 Dany Tixador
*/

#include "../include/malloc.h"

t_block		get_block_ptr(void *ptr)
{
  return ((t_block)ptr - 1);
}

void		free(void *ptr)
{
  t_block	block_ptr;

  if (!ptr)
    return;
  block_ptr = get_block_ptr(ptr);
  block_ptr->free = 1;
}
