/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabu-bak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:57:26 by zabu-bak          #+#    #+#             */
/*   Updated: 2025/02/07 14:20:18 by zabu-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack_x)
{
	t_list	*current;
	int		a;
	int		b;
	int		c;

	current = stack_x->top;
	a = *(int *)current->content;
	b = *(int *)current->next->content;
	c = *(int *)current->next->next->content;
	if (a > b && b < c && a < c)
		swap(stack_x, "sa");
	else if (a > b && b > c && a > c)
	{
		swap(stack_x, "sa");
		r_rotate(stack_x, "rra");
	}
	else if (a > b && b < c && a > c)
		rotate(stack_x, "ra");
	else if (a < b && b > c && a < c)
	{
		swap(stack_x, "sa");
		rotate(stack_x, "ra");
	}
	else if (a < b && b > c && a > c)
		r_rotate(stack_x, "rra");
}

void	sort_three_decending(t_stack *stack_x)
{
	t_list	*current;
	int		a;
	int		b;
	int		c;

	current = stack_x->top;
	a = *(int *)current->content;
	b = *(int *)current->next->content;
	c = *(int *)current->next->next->content;
	if (a < b && b > c && a < c)
		swap(stack_x, "sa");
	else if (a < b && b < c && a < c)
	{
		swap(stack_x, "sa");
		r_rotate(stack_x, "rra");
	}
	else if (a < b && b > c && a < c)
		rotate(stack_x, "ra");
	else if (a > b && b < c && a > c)
	{
		swap(stack_x, "sa");
		rotate(stack_x, "ra");
	}
	else if (a > b && b < c && a < c)
		r_rotate(stack_x, "rra");
}

void	init_var(t_data *data)
{
	data->max = 4;
	data->min = 0;
}

static void sort_push(t_stack *a, t_stack *b)
{
	sort_three_decending(b);
	sort_three_decending(b);
	push(a, b, 'a');
	push(a, b, 'a');
	push(a, b, 'a');
}

void	sort_five(t_stack *a, t_stack *b, t_data *data)
{
	int flag;

	flag = 0;
	init_var(data);
	normalize_stack_range(a);
	while(a->top)
	{
		if (*(int *)a->top->content == data->max || *(int *)a->top->content == data->min)
			rotate(a, "ra");
		else
			push(a,b, 'b');
		if (ft_lstsize(a->top) == 2)
			break;
	}
	if (*(int *)a->top->content == data->max)
		flag = 1;
	else
		rotate(a, "ra");
	sort_push(a, b);
	if(flag = 1)
		r_rotate(a, "rra");
	else
		rotate(a, "ra");
}
