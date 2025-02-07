/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabu-bak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:57:52 by zabu-bak          #+#    #+#             */
/*   Updated: 2025/02/07 12:57:53 by zabu-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	has_duplicates(t_stack *stack)
{
	t_list	*outer;
	t_list	*inner;

	if (!stack || !stack->top)
		ft_close("Error\nNo stack", stack);
	outer = stack->top;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (*(int *)(outer->content) == *(int *)(inner->content))
				ft_close("Error\nDupes", stack);
			inner = inner->next;
		}
		outer = outer->next;
	}
}
