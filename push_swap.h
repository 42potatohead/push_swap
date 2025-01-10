/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabu-bak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:18:05 by ataan             #+#    #+#             */
/*   Updated: 2025/01/10 19:07:07 by zabu-bak         ###   ########.fr       */
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

// typedef struct s_node
// {
//     int data;
//     struct s_node *next;
// } t_node;

typedef struct s_stack
{
    t_list *top;
} t_stack;

void ft_swap_stack (t_stack *stack_x, char *op);
void del(void *content);
void push(t_stack *a, t_stack *b, char op);
void rotate(t_stack *x, char *op, int flag);
void r_rotate(t_stack *x, char *op, int flag);
void rr(t_stack *a, t_stack *b);
void swap(t_stack *stack_x, char *op,int flag);
void ss(t_stack *a, t_stack *b);
void algo(t_stack *a, t_stack *b);
void algo3(t_stack *a, t_stack *b);

#endif
