/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <ataan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:18:00 by ataan             #+#    #+#             */
/*   Updated: 2025/01/03 19:28:08 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void ft_print_stack (t_stack stack_x)
{
    t_node *start_node;
    t_node *current_node;

    start_node = stack_x.top;
    current_node = stack_x.top;

    while(1)
    {
        printf("%d\n", current_node->data);
        current_node = current_node->next;
        if(current_node == start_node)
            break;
    }
    // printf("%d\n", stack_a.top->data);
    // stack_a.top = a1.next;
  
    // while(stack_a.top != &a1)
    // {
    //     printf("%d\n", stack_a.top->data);
    //     stack_a.top = stack_a.top->next;
    // }

}

void ft_swap_stack (t_stack *stack_x, char *op)
{
    // if(stack_x.top == NULL)
    //     return;
    // else if (stack_x.top->next == stack_x.top)
    //     return;
    // else
    // {
        printf("%s\n", op);
        t_node *node1;
        t_node *node2;

        node1 = stack_x->top;
        node2 = stack_x->top->next;
        

        // stack_x->top = stack_x->top->next;
        // //  ----> top = a2
        // stack_x->top->next = stack_x->top->previous;
        // // ---->  a2.next = a2.prev = a1
        // stack_x->top->previous = stack_x->top->next->previous;
        // // ----> a2.prev = a1.prev = a3

        // stack_x->top->next->next = stack_x->top->next->previous;
        // stack_x->top->next->previous = stack_x->top;
    // }   
    
}

int main(/*int ac, char **av*/)
{
    t_stack stack_a;
    t_stack stack_b;
    t_node a1;
    t_node a2;
    t_node a3;

    a1.data = 2;
    a1.next = &a2;
    a1.previous = &a3;

    a2.data = 1;
    a2.next = &a3;
    a2.previous = &a1;

    a3.data = 3;
    a3.previous = &a2;
    a3.next = &a1;

    stack_a.top = &a1;
    stack_b.top = NULL;

    if(stack_a.top->data > stack_a.top->next->data)
        ft_swap_stack(&stack_a, "sa");
    ft_print_stack(stack_a);


}

