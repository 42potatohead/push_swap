/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opperations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabu-bak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:18:05 by zabu-bak          #+#    #+#             */
/*   Updated: 2025/02/04 16:30:24 by zabu-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *a, t_stack *b, char op)
{
	t_list	*temp;

	if (op == 'a')
	{
		if (b->top == NULL)
			return ;
		ft_printf("pa\n");
		ft_lstadd_front(&a->top, ft_lstnew(b->top->content));
		temp = b->top->next;
		free(b->top);
		b->top = temp;
	}
	if (op == 'b')
	{
		if (a->top == NULL)
			return ;
		ft_printf("pb\n");
		ft_lstadd_front(&b->top, ft_lstnew(a->top->content));
		temp = a->top->next;
		free(a->top);
		a->top = temp;
	}
}

void	rotate(t_stack *x, char *op)
{
	if (x->top == NULL || x->top->next == NULL)
		return ;
	ft_printf("%s\n", op);
	t_list *last = x->top;
	while (last->next)
		last = last->next;
	last->next = x->top;
	x->top = x->top->next;
	last->next->next = NULL;
}

void	r_rotate(t_stack *x, char *op)
{
	t_list	*tmp;

	if (x->top == NULL || x->top->next == NULL)
		return ;
	ft_printf("%s\n", op);
	t_list *last = x->top;
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	tmp->next = x->top;
	last->next = NULL;
	x->top = tmp;
}

void	swap(t_stack *stack_x, char *op)
{
	void	*temp;

	if (!stack_x->top || !stack_x->top->next)
		return ;
	ft_printf("%s\n", op);
	temp = stack_x->top->content;
	stack_x->top->content = stack_x->top->next->content;
	stack_x->top->next->content = temp;
}
