/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabu-bak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:15:06 by zabu-bak          #+#    #+#             */
/*   Updated: 2025/02/10 13:44:09 by zabu-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_close(char *err)
{
	ft_printf("%s\n", err);
	exit(EXIT_FAILURE);
}

void	check_args(char **av, t_stack *stack_x)
{
	check_av(av);
	init_stack(stack_x, av);
}

void	del(void *content)
{
	if (content)
		free(content);
}

int	is_sorted(t_stack *a)
{
	t_list	*current;

	if (!a->top || !a->top->next)
		return (1);
	current = a->top;
	while (current->next != NULL)
	{
		if (*(int *)current->content > *(int *)current->next->content)
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	t_data	data;

	a.top = NULL;
	b.top = NULL;
	if (ac == 1)
		return (0);
	check_args(av, &a);
	if (has_duplicates(&a) == 1)
	{
		ft_lstclear(&a.top, del);
		ft_close("Error\nDuplicates");
	}
	if (!is_sorted(&a) && ft_lstsize(a.top) == 3)
	{
		sort_three(&a);
		sort_three(&a);
	}
	if (!is_sorted(&a) && ft_lstsize(a.top) == 5)
		sort_five(&a, &b, &data);
	else if (!is_sorted(&a))
		algo(&a, &b);
	ft_lstclear(&b.top, del);
	ft_lstclear(&a.top, del);
}
