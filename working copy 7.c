/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabu-bak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:27:28 by ataan             #+#    #+#             */
/*   Updated: 2025/02/01 20:13:20 by zabu-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void print_stack(t_stack *stack_x)
{
    t_list *current = stack_x->top;
    while (current) {
        printf("%d ", *(int *)current->content);
        current = current->next;
    }
    printf("\n\n");
}

void ft_close(char *err)
{
    printf("%s\n",err);
    exit(EXIT_FAILURE);
}

void check_size(char *snum)
{
    int i = 0;
    long long int num = 0;
    while(snum[i])
    {
        num = num * 10 + (snum[i] - '0');
        i++;
    }
    if(num >= INT_MAX)
        ft_close("int is larger than max");
}

void check_av(char **av)
{
    int i;
    int j;
    i = 1;
    while (av[i])
    {
        j = 0;
        while(av[i][j])
        {
            if (!ft_isdigit(av[i][j]) && av[i][j] != ' ' && av[i][j] != '-')
                ft_close("its not a digit");
            j++;
        }
        check_size(av[i]);
        // printf("%s\n", av[i]);
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

void ft_stack(t_stack *stack_x, int ac, char **av)
{
    char **nums;
    int i = 0;
    if (ac == 2)
    {
        nums = ft_split(av[1], ' ');
        while (nums[i])
        {
            int nnums = ft_atoi(nums[i]);
            int *nnnums = malloc(sizeof(int));
            *nnnums = nnums;
            ft_lstadd_back(&stack_x->top, ft_lstnew(nnnums));
            i++;
        }
        clean_array(nums);
    }
    else
    {
        i = 1;
        while(av[i])
        {
            int k = ft_atoi(av[i]);
            int *k_ptr = malloc(sizeof(int));
            *k_ptr = k;
            // printf("k = %d\n", k);
            // stack_x->top = ft_lstnew(&k);
            // printf("test : %d\n", *(int *)stack_x->top->content);
            // t_list *tmp = ft_lstnew(&k);
            // printf("tmp = %d\n", *(int *)tmp->content);
            ft_lstadd_back(&stack_x->top, ft_lstnew(k_ptr));
            i++;
        }
    }

}

void check_args(int ac, char **av, t_stack *stack_x)
{
    if (ac == 1)
        exit(EXIT_FAILURE);
    check_av(av);
    ft_stack(stack_x, ac, av);

    // if (ac == 2)
    //     ft_init_stack(stack_x, 's');
    // if (ac > 2)
    //     ft_init_stack(stack_x, 'm');
}
void del(void *content)
{
    if (content)
        free(content);  // Free the dynamically allocated content
}

// int is_sorted(t_stack *stack) {
//     t_list *current;

//     if (!stack->top || !stack->top->next)
//         return (1); // Empty or single element stack is considered sorted

//     current = stack->top;
//     int max = *(int *)current->content;
//     while (current->next) {
//         if (*(int *)current->content > max )
//             return (0); // Found pair out of order
//         max = *(int *)current->content;
//         current = current->next;
//     }
//     return (1); // Stack is sorted
// }
int is_sorted(t_stack *a)
{
    if (!a->top || !a->top->next)
        return (1);

    t_list *current;
    current = a->top;

    while (current->next != NULL)
    {
        if (*(int *)current->content < *(int *)current->next->content)
        {
            // printf("not sorted\n");
            return (0);  // Not sorted
        }
        current = current->next;
    }
    return (1);  // Sorted
}

// void sort_small(t_stack *a)
// {
//     if (!a->top || !a->top->next)
//         return;
//     if (*(int *)a->top->content > *(int *)a->top->next->content)
//         swap(a, "sa", 1, data);
// }

// void algo3(t_stack *a, t_stack *b)
// {
//     if (is_sorted(a) || !a->top || !a->top->next)
//         return;

//     // Handle 2-3 elements
//     if (!a->top->next->next || !a->top->next->next->next)
//     {
//         sort_small(a);
//         return;
//     }

//     // Partition phase - non recursive
//     int pivot = *(int *)a->top->content;
//     int pushed = 0;
//     int rotated = 0;

//     // Single pass partition
//     while (a->top && rotated < 1 * ft_lstsize(a->top))
//     {
//         if (*(int *)a->top->content < pivot)
//         {
//             push(a, b, 'b');
//             pushed++;
//         }
//         else
//         {
//             rotate(a, "ra", 1);
//             rotated++;
//         }

//         // Keep B sorted
//         if (b->top && b->top->next &&
//             *(int *)b->top->content < *(int *)b->top->next->content)
//             swap(b, "sb", 1);
//     }

//     // Sort remaining A elements
//     sort_small(a);

//     // Merge phase - non recursive
//     while (b->top)
//     {
//         if (!a->top || *(int *)b->top->content < *(int *)a->top->content)
//             push(a, b, 'a');
//         else if (a->top)
//             rotate(a, "ra", 1);
//     }

//     // Final cleanup if needed
//     if (!is_sorted(a))
//         algo(a,b);
// }


// get max and min before algo

static int get_max_bits(t_list *stack)
{
    t_list *head;
    int max;
    int max_bits;

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
    return max_bits;
}

static int get_max_value(t_list *stack)
{
    t_list *head;
    int max;

    head = stack;
    max = *(int *)head->content;
    while (head)
    {
        if (*(int *)head->content > max)
            max = *(int *)head->content;
        head = head->next;
    }
    return max;
}

void normalize_stack_range(t_stack *stack)
{
    t_list *current;
    int min_value, max_value, size;
    double scale;

    // Find the minimum and maximum values in the stack
    min_value = get_min_value(stack->top);
    max_value = get_max_value(stack->top);

    // Calculate the size of the stack
    size = ft_lstsize(stack->top);

    // Calculate the scale factor
    scale = (double)(size - 1) / (max_value - min_value);

    // Normalize the stack values
    current = stack->top;
    while (current)
    {
        *(int *)current->content = (int)((*(int *)current->content - min_value) * scale);
        current = current->next;
    }
}

static int get_min_value(t_list *stack)
{
    t_list *head;
    int min;

    head = stack;
    min = *(int *)head->content;
    while (head)
    {
        if (*(int *)head->content < min)
            min = *(int *)head->content;
        head = head->next;
    }
    return min;
}

void normalize_stack(t_stack *stack, int shift)
{
    t_list *current = stack->top;
    while (current)
    {
        *(int *)current->content += shift;
        current = current->next;
    }
}

void denormalize_stack(t_stack *stack, int shift)
{
    t_list *current = stack->top;
    while (current)
    {
        *(int *)current->content -= shift;
        current = current->next;
    }
}

void algo(t_stack *a, t_stack *b, t_data *data)
{
    int i;
    int j;
    int size;
    int max_bits;
    int min_value;
    int shift;

    // Find the minimum value in the stack
    min_value = get_min_value(a->top);
    shift = (min_value < 0) ? -min_value : 0;

    // Normalize the stack values
    normalize_stack(a, shift);

    i = 0;
    size = ft_lstsize(a->top);
    max_bits = get_max_bits(a->top);
    while (i < max_bits)
    {
        j = 0;
        while (j++ < size)
        {
            if (((*(int *)a->top->content >> i) & 1) == 1)
                rotate(a, "ra", 1, data);
            else
                push(a, b, 'b', data);
        }
        while (ft_lstsize(b->top) != 0)
            push(a, b, 'a', data);
        if (is_sorted(a))
            break;
        i++;
    }

    // Denormalize the stack values
    denormalize_stack(a, shift);
}

void post_processing(t_data *data)
{
    char *before;
    char *after;
    char *start;

    start = ft_strnstr(data->operations, "sa\nsb",ft_strlen(data->operations));
    before = ft_substr(data->operations, 0, (start- data->operations));
    before = ft_strjoin(before, "ss");
    after = ft_substr(data->operations, (start- data->operations) + 5, (ft_strlen(data->operations) - (start- data->operations) + 5));
    data->operations = ft_strjoin(before, after);
    if(ft_strnstr(data->operations,"sb\nsa", ft_strlen(data->operations)) == 0)
    {
        return;
    }
    start = ft_strnstr(data->operations, "sb\nsa",ft_strlen(data->operations));
    before = ft_substr(data->operations, 0, (start- data->operations));
    before = ft_strjoin(before, "ss");
    after = ft_substr(data->operations, (start- data->operations) + 5, (ft_strlen(data->operations) - (start- data->operations) + 5));
    data->operations = ft_strjoin(before, after);
    if(ft_strnstr(data->operations,"sa\nsb", ft_strlen(data->operations)) == 0)
    {
        return;
        }
    post_processing(data);
}

int main(int ac, char **av)
{
    t_stack a = {NULL};
    t_stack b = {NULL};
    t_data data;

    int i = 0;
    data.operations = ft_strdup("");
    check_args(ac, av, &a);

    algo(&a,&b, &data);
    // post_processing(&data);
    printf("%s",data.operations);
                printf("stack a from top = ");
                print_stack(&a);
                printf("stack b from top = ");
                print_stack(&b);
    ft_lstclear(&b.top, del);
    ft_lstclear(&a.top, del);
}
