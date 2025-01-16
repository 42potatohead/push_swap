/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabu-bak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:18:05 by ataan             #+#    #+#             */
/*   Updated: 2025/01/14 17:05:26 by zabu-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <limits.h>
#include <stdio.h>
#include "./libft/libft.h"

typedef struct s_node
{
	int			*content;
	struct s_node	*next;
}	t_node;

typedef struct s_data
{
	char *operations;
} t_data;

typedef struct s_stack
{
    t_list *top;
} t_stack;

void ft_swap_stack (t_stack *stack_x, char *op);
void del(void *content);
void push(t_stack *a, t_stack *b, char op, t_data *data);
void rotate(t_stack *x, char *op, int flag, t_data *data);
void r_rotate(t_stack *x, char *op, int flag, t_data *data);
void rr(t_stack *a, t_stack *b, t_data *data);
void swap(t_stack *stack_x, char *op,int flag, t_data *data);
void ss(t_stack *a, t_stack *b, t_data *data);
void algo(t_stack *a, t_stack *b, t_data *data);
void post_processing(t_data *data);
int compare(const void *a, const void *b);
int find_median(t_stack *a);

#endif
