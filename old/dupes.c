/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabu-bak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:57:52 by zabu-bak          #+#    #+#             */
/*   Updated: 2025/02/08 12:43:08 by zabu-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicates(t_stack *stack)
{
	t_list	*outer;
	t_list	*inner;

	if (!stack || !stack->top)
		return (1);
	outer = stack->top;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (*(int *)(outer->content) == *(int *)(inner->content))
				return (1);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (0);
}
