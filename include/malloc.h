/*
** malloc.h for PSU_2015_malloc in /home/tixado_d/epitech/rendu/PSU_2015_malloc/src
**
** Made by tixador
** Login   <tixado_d@epitech.net>
**
** Started on  Tue Feb 02 13:50:59 2016 tixador
** Last update Sun Feb 14 16:16:17 2016 Dany Tixador
*/

#ifndef _MALLOC_H_
#define _MALLOC_H_

#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

/*
** linked list
*/

#define META_SIZE sizeof(struct s_block)
#define DATA_SIZE_BYTE (12)

struct			s_block
{
  size_t		size;
  struct s_block	*next;
  struct s_block	*prev;
  int			free;
  char			data[1];
};

typedef struct s_block	*t_block;

t_block			g_base;
extern pthread_mutex_t	g_mutex;

/*
** prototype
*/

void		*malloc(size_t size);
void		free(void *ptr);
void		*realloc(void *ptr, size_t size);
void		*calloc(size_t nelem, size_t elsize);

void		*tools_malloc(size_t size);
t_block		get_block_ptr(void *ptr);
t_block		search_first_fit(t_block *last, size_t size);
t_block		request_space(t_block last, size_t size);
void		show_alloc_mem();

#endif /* !MALLOC_H_ */
