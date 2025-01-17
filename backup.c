void algo(t_stack *a, t_stack *b)
{
	int max = 0;
	int min = INT_MAX;
	int start = *(int *)a->top->content;
	if (is_sorted(a)) // Check if already sorted
        return;
    while(a->top != NULL && a->top->next != NULL)
    {
		if (*(int *)a->top->content > max)
			max = *(int *)a->top->content;
		if (*(int *)a->top->content < min)
			min = *(int *)a->top->content;
		// if(*(int *)a->top->content > (*(int*)a->top->next->content/3))
		// 	rotate(a, "ra", 1);
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
	push(a, b, 'b');
    while(b->top != NULL && b->top->next != NULL)
    {
        // if(*(int *)b->top->content < min)
        // {
        //     rotate(b, "rrb", 1);
        //     min = *(int *)b->top->content;
        // }
        // if(*(int *)b->top->content < *(int *)b->top->next->content )
        // {
        //     r_rotate(b, "rrb", 1);
        //     // max = *(int *)b->top->content;
        // }
        // if (*(int *)b->top->content < min)
        // {
        //     rotate(b, "rb", 1);
        //     // min = *(int *)b->top->content;
        // }
        if (*(int *)b->top->content > *(int *)b->top->next->content)
            swap(b, "sb", 1);
        else
            push(a, b, 'a');
        // if (a->top != NULL && (*(int *)b->top->content < *(int *)a->top->content))
        // {
        //     // printf("<push_swap>\n");
        //     push(a, b, 'a');
        //     swap(a,"sa", 1);
        //     // printf("</push_swap>\n");
        // }
        if (a->top != NULL && a->top->next != NULL && *(int *)a->top->content < *(int *)a->top->next->content)
            swap(a, "sa", 1);
    }
    push(a, b, 'a');
	if (is_sorted(a)) // Check if already sorted
        return;
	else
		algo(a,b);
}


void algo(t_stack *a, t_stack *b, t_data *data)
{
	int max = 100;
	int min = INT_MAX;
	int start = *(int *)a->top->content;
	if (is_sorted(a)) // Check if already sorted
        return;
    while(a->top != NULL && a->top->next != NULL)
    {
		if(*(int *)a->top->content < (*(int*)a->top->next->content/3))
			rotate(a, "ra", 1, data);
        if (*(int *)a->top->content < *(int *)a->top->next->content)
            swap(a, "sa", 1, data);
        else if(is_sorted(a))
        {
            break;
        }
        // else
            push(a, b, 'b', data);
        // if(b->top->next != NULL)
        // {
            if (b->top != NULL && b->top->next != NULL && *(int *)b->top->content > *(int *)b->top->next->content)
                swap(b, "sb", 1, data);
        // }
    }
	// push(a, b, 'b');
    while(b->top != NULL && b->top->next != NULL)
    {
        if(*(int *)b->top->content > (*(int *)b->top->next->content + 30))
            rotate(b, "rb", 1, data);
        // if(*(int *)b->top->content > 50)
        //     rotate(b, "rb", 1);
        if (*(int *)b->top->content > *(int *)b->top->next->content)
            swap(b, "sb", 1, data);
        else if(b->top == NULL)
            break;
        push(a, b, 'a', data);
        if (a->top != NULL && a->top->next != NULL && *(int *)a->top->content < *(int *)a->top->next->content)
            swap(a, "sa", 1, data);
    }
    push(a, b, 'a', data);
	if (is_sorted(a))
        return;
	else
		algo(a,b, data);
}
