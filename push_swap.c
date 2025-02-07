/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabu-bak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:15:06 by zabu-bak          #+#    #+#             */
/*   Updated: 2025/02/04 16:30:06 by zabu-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack_x)
{
	t_list	*current;

	current = stack_x->top;
	while (current)
	{
		ft_printf("%d ", *(int *)current->content);
		current = current->next;
	}
	ft_printf("\n\n");
}

void	ft_close(char *err, t_stack *a)
{
	ft_printf("%s\n", err);
	ft_lstclear(&a->top, del);
	exit(EXIT_FAILURE);
}

void	check_args(int ac, char **av, t_stack *stack_x)
{
	if (ac == 1)
		exit(EXIT_FAILURE);
	check_av(av);
	init_stack(stack_x, ac, av);
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
    t_stack a = {NULL};
    t_stack b = {NULL};
	int		i;

	i = 0;
	check_args(ac, av, &a);
	has_duplicates(&a);
	if (!is_sorted(&a) && ft_lstsize(a.top) == 3)
		sort_three(&a);
	if (!is_sorted(&a) && ft_lstsize(a.top) == 5)
		sort_five(&a, &b);
	else if (!is_sorted(&a))
		algo(&a, &b);
	ft_printf("stack a from top = ");
	print_stack(&a);
	ft_printf("stack b from top = ");
	print_stack(&b);
	ft_lstclear(&b.top, del);
	ft_lstclear(&a.top, del);
}
