/*
** calloc.c for PSU_2015_malloc in /home/tixado_d/epitech/rendu/PSU_2015_malloc/src
**
** Made by tixador
** Login   <tixado_d@epitech.net>
**
** Started on  Thu Feb 04 15:18:43 2016 tixador
** Last update Sun Feb 14 16:12:53 2016 Dany Tixador
*/

#include "../include/malloc.h"

void		*calloc(size_t size_n, size_t size_el)
{
  void		*ptr;

  if ((ptr = malloc(size_n * size_el)) == NULL)
    return (NULL);
  memset(ptr, 0, size_n * size_el);
  return (ptr);
}
