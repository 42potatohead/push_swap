#include "push_swap.h"

void sort_three(t_stack *stack_x)
{
	t_list *current = stack_x->top;
	int a = *(int *)current->content;
	int b = *(int *)current->next->content;
	int c = *(int *)current->next->next->content;

	if (a > b && b < c && a < c)
		swap(stack_x, "sa");
	else if (a > b && b > c && a > c)
	{
		swap(stack_x, "sa");
		r_rotate(stack_x, "rra");
	}
	else if (a > b && b < c && a > c)
		rotate(stack_x, "ra");
	else if (a < b && b > c && a < c)
	{
		swap(stack_x, "sa");
		rotate(stack_x, "ra");
	}
	else if (a < b && b > c && a > c)
		r_rotate(stack_x, "rra");
}

void sort_three_decending(t_stack *stack_x)
{
	t_list *current = stack_x->top;
	int a = *(int *)current->content;
	int b = *(int *)current->next->content;
	int c = *(int *)current->next->next->content;

	if (a < b && b > c && a < c)
		swap(stack_x, "sa");
	else if (a < b && b < c && a < c)
	{
		swap(stack_x, "sa");
		r_rotate(stack_x, "rra");
	}
	else if (a < b && b > c && a < c)
		rotate(stack_x, "ra");
	else if (a > b && b < c && a > c)
	{
		swap(stack_x, "sa");
		rotate(stack_x, "ra");
	}
	else if (a > b && b < c && a < c)
		r_rotate(stack_x, "rra");
}

void sort_five(t_stack *a, t_stack *b)
{
	int max = 4;
	int min = 0;
	int flag = 0;
	normalize_stack_range(a);
	while(a->top)
	{
		if (*(int *)a->top->content == max || *(int *)a->top->content == min)
			rotate(a, "ra");
		else
			push(a,b, 'b');
		if (ft_lstsize(a->top) == 2)
			break;
	}
	if (*(int *)a->top->content == max)
		flag = 1;
	else
		rotate(a, "ra");
	sort_three_decending(b);
	push(a, b, 'a');
	push(a, b, 'a');
	push(a, b, 'a');
	if(flag = 1)
		r_rotate(a, "rra");
	else
		rotate(a, "ra");
}
