/*
** realloc.c for PSU_2015_malloc in /mnt/62401A64401A3F6B/Dropbox/HED/ALL/epitech/rendu/PSU/PSU_2015_malloc/src
**
** Made by Hed
** Login   <ugo@epitech.net>
**
** Started on  Thu Feb 04 14:22:23 2016 Hed
** Last update Sun Feb 14 15:41:23 2016 Dany Tixador
*/

#include "../include/malloc.h"

void		*realloc(void *ptr, size_t size)
{
  t_block	block_ptr;
  void		*new_ptr;

  if (!ptr)
    return (malloc(size));
  block_ptr = get_block_ptr(ptr);
  if (block_ptr->size >= size)
    return (ptr);
  new_ptr = malloc(size);
  if (!new_ptr)
    return (NULL);
  memcpy(new_ptr, ptr, block_ptr->size);
  free(ptr);
  return (new_ptr);
}
