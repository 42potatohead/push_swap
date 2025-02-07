/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabu-bak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:20:37 by zabu-bak          #+#    #+#             */
/*   Updated: 2025/02/07 18:29:37 by zabu-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list *stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = stack;
	max = *(int *)head->content;
	max_bits = 0;
	while (head)
	{
		if (*(int *)head->content > max)
			max = *(int *)head->content;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static t_list	*get_next_min(t_list *stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = stack;
	while (head)
	{
		if ((head->index == -1) && (!has_min
				|| *(int *)head->content < *(int *)min->content))
		{
			min = head;
			has_min = 1;
		}
		head = head->next;
	}
	return (min);
}

void	normalize_stack_range(t_stack *stack)
{
	t_list	*head;
	int		index;

	head = stack->top;
	while (head)
	{
		head->index = -1;
		head = head->next;
	}
	index = 0;
	head = get_next_min(stack->top);
	while (head)
	{
		head->index = index;
		*(int *)head->content = index++;
		head = get_next_min(stack->top);
	}
}

void	algo(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	normalize_stack_range(a);
	i = 0;
	size = ft_lstsize(a->top);
	max_bits = get_max_bits(a->top);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((*(int *)a->top->content >> i) & 1) == 1)
				rotate(a, "ra");
			else
				push(a, b, 'b');
		}
		while (ft_lstsize(b->top) != 0)
			push(a, b, 'a');
		if (is_sorted(a))
			break ;
		i++;
	}
}
