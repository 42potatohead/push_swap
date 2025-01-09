#include "push_swap.h"

void swap(t_stack *stack_x, char *op,int flag)
{
    if (!stack_x->top || !stack_x->top->next)
        return;
    if (flag = 1)
        ft_printf("%s\n", op);
    void *temp;
    temp = stack_x->top->content;
    stack_x->top->content = stack_x->top->next->content;
    stack_x->top->next->content = temp;
}

void ss(t_stack *a, t_stack *b)
{
    printf("ss\n");
    swap(a, "", 0);
    swap(b, "", 0);
}

void push(t_stack *a, t_stack *b, char op)
{
    if(op == 'a')
    {
        if(b->top == NULL)
            return;
        ft_printf("pa\n");
        ft_lstadd_front(&a->top, ft_lstnew(b->top->content));
        t_list *temp = b->top->next;
        free(b->top);
        b->top = temp;
    }
    if(op == 'b')
    {
        if(a->top == NULL)
            return;
        ft_printf("pb\n");
        ft_lstadd_front(&b->top, ft_lstnew(a->top->content));
        t_list *temp = a->top->next;
        free(a->top);
        a->top = temp;
    }
}
// void rotate(t_stack *x, char *op)
// {
//     ft_printf("%s\n", op) ;

//     t_list  temp;
//     temp.content = x->top->content;

//     *(int *)x->top->content = *(int *)x->top->next->content;
    
//     x->top->next->content = temp.content;
// }

void rotate(t_stack *x, char *op, int flag)
{
        if(x->top == NULL || x->top->next == NULL)
            return;
        if (flag == 1)
            ft_printf("%s\n", op);
        t_list *last = x->top; // stack a
        while(last->next)
            last = last->next; // 9
        
        last->next = x->top; // NULL -> 1 234567891
        x->top = x->top->next; // 1 -> 2 23456789
        last->next->next = NULL; // element 10, 11 = NULL;
}

void rr(t_stack *a, t_stack *b)
{
    ft_printf("rr\n");
    rotate(a, "" , 0);
    rotate(b, "" , 0);
}

void r_rotate(t_stack *x, char *op, int flag)
{
        if(x->top == NULL || x->top->next == NULL)
            return;
        if (flag == 1)
            ft_printf("%s\n", op);
        t_list *last = x->top; // stack a
        t_list *tmp;
        while(last->next->next)
            last = last->next; // 9
        tmp = last->next; //4 
        tmp->next = x->top;
        last->next = NULL; // 3 -> NULL
        x->top = tmp;
}

void rrr(t_stack *a, t_stack *b, char op)
{
    ft_printf("rrr\n");
    r_rotate(a, "", 0);
    r_rotate(b, "", 0);
}