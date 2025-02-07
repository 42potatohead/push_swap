#include "push_swap.h"

void	check_size(char *snum)
{
	int				i;
	long long int	num;

	i = 0;
	num = 0;
	while (snum[i])
	{
		num = num * 10 + (snum[i] - '0');
		i++;
	}
	if (num >= INT_MAX)
	{
		ft_printf("Error\nNumber is larger than int max\n");
		exit(EXIT_FAILURE);
	}
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
void multi_args(t_stack *stack_x, int ac, char **av)
{
	int		*k_ptr;
	int		k;
	int		i;

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

void	init_stack(t_stack *stack_x, int ac, char **av)
{
	char	**nbr_array;
	int		i;
	int		nbr;
	int		*nbr_ptr;


	i = 0;
	if (ac == 2)
	{
		nbr_array = ft_split(av[1], ' ');
		while (nbr_array[i])
		{
			nbr = ft_atoi(nbr_array[i]);
			nbr_ptr = malloc(sizeof(int));
			*nbr_ptr = nbr;
			ft_lstadd_back(&stack_x->top, ft_lstnew(nbr_ptr));
			i++;
		}
		clean_array(nbr_array);
	}
	else
		multi_args(stack_x, ac, av);
}
