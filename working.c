/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <ataan@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:27:28 by ataan             #+#    #+#             */
/*   Updated: 2025/01/09 13:10:45 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void algo_alaa_after_stalin(t_stack *a, t_stack *b, int min, int max);

void print_stack(t_stack *stack_x)
{
    t_list *current = stack_x->top;
    while (current) {
        printf("%d ", *(int *)current->content);
        current = current->next;
    }
    printf("\n");
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
            // ft_printf("k = %d\n", k);
            // stack_x->top = ft_lstnew(&k);
            // printf("test : %d\n", *(int *)stack_x->top->content);
            // t_list *tmp = ft_lstnew(&k);
            // ft_printf("tmp = %d\n", *(int *)tmp->content);
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

void algo(t_stack *a, t_stack *b)
{
    int mina = *(int *)a->top->content;
    int maxa = *(int *)a->top->content;
    while(a->top != NULL && a->top->next != NULL)
    {
        if (*(int *)a->top->content < *(int *)a->top->next->content)
            swap(a, "sa", 1);
        else
            push(a, b, 'b');
        // if(b->top->next != NULL)
        // {
            if (b->top != NULL && b->top->next != NULL && *(int *)b->top->content > *(int *)b->top->next->content)
                swap(b, "sb", 1);
        // }
    }
    int last = *(int *)a->top->content;
    push(a, b, 'b');
    printf("last %d\n", last);
    int min = *(int *)b->top->content;
    int max = *(int *)b->top->content;
    while(b->top != NULL && b->top->next != NULL)
    {
        // if(*(int *)b->top->content < min)
        // {
        //     rotate(b, "rrb", 1);
        //     min = *(int *)b->top->content;
        // }
        if(*(int *)b->top->content > max)
        {
            r_rotate(b, "rrb", 1);
            max = *(int *)b->top->content;
        }
        // if (*(int *)b->top->content < min)
        // {
        //     rotate(b, "rb", 1);
        //     min = *(int *)b->top->content;
        // }
        if (*(int *)b->top->content > *(int *)b->top->next->content)
            swap(b, "sb", 0);
        else
            push(a, b, 'a');
        if (a->top != NULL && (*(int *)b->top->content < *(int *)a->top->content))
        {
            // printf("<push_swap>\n");
            push(a, b, 'a');
            swap(a,"sa", 1);
            // printf("</push_swap>\n");
        }
        if (a->top != NULL && a->top->next != NULL && *(int *)a->top->content < *(int *)a->top->next->content)
            swap(a, "sa", 0);
        // ft_printf("current value  = %d,\n" ,*(int *)b->top->content);
    }
    push(a, b, 'a');
    while (b->top != NULL)
    {
        push(a, b, 'a');
        if (a->top != NULL && a->top->next != NULL && *(int *)a->top->content < *(int *)a->top->next->content)
            swap(a, "sa", 0);
    }
    
}

/*sorts 3 or 4 numbers in descending order*/
void algo_alaa(t_stack *a, t_stack *b)
{
    int min = *(int *)a->top->content;
    while(a->top != NULL)
    {
        if (b->top == NULL)
            push(a, b, 'b');
        else
        {
            if (*(int *)a->top->content < *(int *)b->top->content)
            {
                if(*(int *)a->top->content < min)
                {
                    min = *(int *)a->top->content;
                    push(a, b, 'b');
                    rotate(b, "rb", 1);
                }
                else
                {
                    push(a, b, 'b');
                    swap(b, "sb", 1);
                }
            }
            else
                push(a, b, 'b');
        }
    }
}

void algo_alaa_5(t_stack *a, t_stack *b)
{
    int min = *(int *)a->top->content;
    while(a->top != NULL)
    {
        if (b->top == NULL)
            push(a, b, 'b');
        else
        {
            if (*(int *)a->top->content < *(int *)b->top->content)
            {
                if(*(int *)a->top->content < min)
                {
                    min = *(int *)a->top->content;
                    push(a, b, 'b');
                    rotate(b, "rb", 1);
                }
                else
                {
                    // ft_printf("min = %d\n", min);
                    // ft_printf("a->top = %d\n", *(int *)a->top->content);
                    // ft_printf("b->top = %d\n", *(int *)b->top->content);
                    // it is not a new min we need to find it a nice place!!
                    if ((*(int *)a->top->content - min) > (*(int *)b->top->content - *(int *)a->top->content))
                    {
                        //it is closer to the top
                        push(a, b, 'b');
                        swap(b, "sb", 1);
                    }
                    else
                    {
                        //it closer to the min
                        r_rotate(b, "rrb", 1);
                        push(a, b, 'b');
                        rotate(b, "rb", 1);
                        rotate(b, "rb", 1);                                                
                    }
                }
            }
            else
                push(a, b, 'b');
        }
    }
}

/*take 4500 moves to sort 100 numbers, uses pb, rb, rrb only*/
void algo_alaa_4500(t_stack *a, t_stack *b)
{
    int min = *(int *)a->top->content;
    int c;
    
    while(a->top != NULL)
    {
        if (b->top == NULL)
            push(a, b, 'b');
        else
        {
            if (*(int *)a->top->content < *(int *)b->top->content)
            {
                if(*(int *)a->top->content < min)
                {
                    min = *(int *)a->top->content;
                    push(a, b, 'b');
                    rotate(b, "rb", 1);
                }
                else
                {
                    c = 0;
                    while(*(int *)b->top->content > *(int *)a->top->content)
                    {
                        rotate(b, "rb", 1);
                        c++;
                    }
                    push(a, b, 'b');
                    while(c > 0)
                    {
                       r_rotate(b, "rrb", 1);
                       c--;
                    }
                }
            }       
            else
                push(a, b, 'b');
        }
    }
}
/*trying a stalin sort, takes 2900 per 100 numbers */
void algo_alaa_stalin(t_stack *a, t_stack *b)
{
    int min = *(int *)a->top->content;
    int max = *(int *)a->top->content;
    int b_count = 0;
    int a_count = 0;
    int start = *(int *)a->top->content;
    // ft_printf("start = %d\n", start);
        // ft_printf("stack a from top = ");
        // print_stack(a);
        // ft_printf("stack b from top = ");
        // print_stack(b);
    
    rotate(a, "ra", 1);
    
        // ft_printf("stack a from top = ");
        // print_stack(a);
        // ft_printf("stack b from top = ");
        // print_stack(b);
    while(a->top != NULL && *(int *)a->top->content != start)
    {
        a_count++;
        if(*(int *)a->top->content > max) //correct order keep it in a
        {
            // ft_printf("correct\n");
            max = *(int *)a->top->content;
            // ft_printf("max = %d\n", max);
            rotate(a, "ra", 1);
        }
        else
        {
            // TODO: try to order b from here too
            // ft_printf("wrong\n");
            push(a, b, 'b');
            b_count++;
        }
    }
        ft_printf("stack a from top = ");
        print_stack(a);
        ft_printf("found max = %d\n", max);
        ft_printf("found min = %d\n", min);
        ft_printf("stack b from top = ");
        print_stack(b);
    // if(b_count > a_count)
        algo_alaa_after_stalin(a, b, min, max);
    // else   
    //     algo_alaa_after_stalin(b, a, min, max);

}
/*after a stalin sort */
void algo_alaa_after_stalin(t_stack *a, t_stack *b, int min, int max)
{
    int c;
    ft_printf("after_stalin\n");
    while(b->top != NULL)
    {   
        if(*(int *)b->top->content < min)
        {
            min = *(int *)b->top->content;
            push(a, b, 'a');
            // rotate(a, "ra", 1);
                // ft_printf("stack a from top = ");
                // print_stack(a);
                // ft_printf("stack b from top = ");
                // print_stack(b);
        }
        else 
        {
            if(*(int *)b->top->content - min < max - *(int *)b->top->content)
            {
                // ft_printf("closer to min, b->top = %d, min=%d, max=%d\n", *(int *)b->top->content, min, max);
                c = 0;
                while(*(int *)a->top->content < *(int *)b->top->content)
                {
                    rotate(a, "ra", 1);
                    c++;
                }
                push(a, b, 'a');
                while(c > 0)
                {
                r_rotate(a, "rra", 1);
                c--;
                }
            }
            else
            {
                // ft_printf("closer to max\n");
                r_rotate(a, "rra", 1);
                c = 0;
                while(*(int *)a->top->content > *(int *)b->top->content)
                {
                    r_rotate(a, "rra", 1);
                    c++;
                }
                rotate(a, "ra", 1);
                push(a, b, 'a');
                rotate(a, "ra", 1);
                while(c > 0)
                {
                    rotate(a, "ra", 1);
                    c--;
                }
            }
        }
    }
}

void algo_alaa_quick(t_stack *a, t_stack *b)
{
    int min = *(int *)a->top->content;
    int pivot = *(int *)a->top->content;
    int max = *(int *)a->top->content;
    int b_count = 0;
    int a_count = 0;
    int start = *(int *)a->top->content;
    // ft_printf("start = %d\n", start);
        // ft_printf("stack a from top = ");
        // print_stack(a);
        // ft_printf("stack b from top = ");
        // print_stack(b);
    
    rotate(a, "ra", 1);
    
    while(a->top != NULL && *(int *)a->top->content != start)
    {
        a_count++;
        if(*(int *)a->top->content > pivot) //greater than pivot stays in a
        {
            // ft_printf("correct\n");
            if(*(int *)a->top->content > max)
                max = *(int *)a->top->content;
            // ft_printf("max = %d\n", max);
            rotate(a, "ra", 1);
        }
        else
        {
            // TODO: try to order b from here too
            // ft_printf("wrong\n");
            if((b->top == NULL) || (*(int *)a->top->content > *(int *)b->top->content))
                push(a, b, 'b');
            else
            {
                push(a, b, 'b');
                swap(b, "sb", 1);
            }
            b_count++;
        }
    }
        ft_printf("stack a from top = ");
        print_stack(a);
        ft_printf("found max = %d\n", max);
        ft_printf("found min = %d\n", min);
        ft_printf("stack b from top = ");
        print_stack(b);
}

int main(int ac, char **av)
{
    t_stack a = {NULL};
    t_stack b = {NULL};
    
    check_args(ac, av, &a);
    
    algo_alaa_quick(&a, &b);
    rotate(&b, "rb", 1);
    algo_alaa_quick(&b, &a);
    
                // ft_printf("stack a from top = ");
                // print_stack(&a);
                // ft_printf("stack b from top = ");
                // print_stack(&b);

    ft_lstclear(&b.top, del);
    ft_lstclear(&a.top, del); 
}