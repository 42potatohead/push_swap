/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabu-bak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:57:29 by zabu-bak          #+#    #+#             */
/*   Updated: 2025/02/08 12:49:51 by zabu-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_size(char *snum)
{
	int				i;
	long long int	num;

	i = 0;
	num = 0;
	if (snum[0] == '-' && snum[1] == '\0')
		ft_close("- Error");
	if (snum[0] == '-')
		i++;
	while (snum[i] == '0')
		i++;
	if (i < 1)
		if (ft_strlen(snum) > 11)
			ft_close("number is out of INT range");
	while (snum[i])
	{
		num = num * 10 + (snum[i] - '0');
		i++;
	}
	if (num > INT_MAX || num < INT_MIN)
		ft_close("number is out of INT range");
}

void	check_av(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' ' && av[i][j] != '-')
			{
				ft_printf("Error\nInvalid argument\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		check_size(av[i]);
		i++;
	}
}

void	clean_array(char **arr)
{
	int	i;

	i = 0;
	if (arr != NULL)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}

void	init_stack(t_stack *stack_x, char **av)
{
	int	*k_ptr;
	int	k;
	int	i;

	i = 1;
	while (av[i])
	{
		k = ft_atoi(av[i]);
		k_ptr = malloc(sizeof(int));
		*k_ptr = k;
		ft_lstadd_back(&stack_x->top, ft_lstnew(k_ptr));
		i++;
	}
}
