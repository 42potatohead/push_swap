/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabu-bak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:18:05 by ataan             #+#    #+#             */
/*   Updated: 2025/02/04 16:21:48 by zabu-bak         ###   ########.fr       */
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

typedef struct s_stack
{
    t_list *top;
} t_stack;


int is_sorted(t_stack *a);
void del(void *content);
void push(t_stack *a, t_stack *b, char op);
void rotate(t_stack *x, char *op);
void algo(t_stack *a, t_stack *b);
void	init_stack(t_stack *stack_x, int ac, char **av);
void multi_args(t_stack *stack_x, int ac, char **av);
void	clean_array(char **arr);
void	check_av(char **av);
void	check_size(char *snum);
void	ft_close(char *err, t_stack *a);
void	r_rotate(t_stack *x, char *op);
void	swap(t_stack *x, char *op);
void sort_three(t_stack *stack_x);
void	sort_five(t_stack *a, t_stack *b);
void	normalize_stack_range(t_stack *stack);
void has_duplicates(t_stack *stack);

#endif
