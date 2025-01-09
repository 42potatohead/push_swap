#include <stdio.h>
#include <stdlib.h>

// Define your stack structure
typedef struct s_stack {
    int *arr;   // Array to hold stack values
    int top;    // Index of the top element
    int size;   // Total size of the stack
} t_stack;

// Function prototypes
void pb(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rra(t_stack *a);
int choose_pivot(t_stack *a, int size);
void quick_sort_push_swap(t_stack *a, t_stack *b, int size);

// Stack operations
void pb(t_stack *a, t_stack *b) {
    if (a->top >= 0) {
        b->arr[++b->top] = a->arr[a->top--];
    }
}

void pa(t_stack *a, t_stack *b) {
    if (b->top >= 0) {
        a->arr[++a->top] = b->arr[b->top--];
    }
}

void ra(t_stack *a) {
    if (a->top > 0) {
        int first = a->arr[0];
        for (int i = 0; i < a->top; i++) {
            a->arr[i] = a->arr[i + 1];
        }
        a->arr[a->top] = first;
    }
}

void rra(t_stack *a) {
    if (a->top > 0) {
        int last = a->arr[a->top];
        for (int i = a->top; i > 0; i--) {
            a->arr[i] = a->arr[i - 1];
        }
        a->arr[0] = last;
    }
}

// Helper function to choose a pivot (median approximation)
int choose_pivot(t_stack *a, int size) {
    return a->arr[a->top]; // Use the top element as the pivot
}


// Quicksort-inspired implementation for Push Swap
void quick_sort_push_swap(t_stack *a, t_stack *b, int size) {
    int partition_stack[size]; // Stack to track partition sizes
    int partition_count = 0;

    // Push the initial partition size (entire stack A)
    partition_stack[partition_count++] = size;

    while (partition_count > 0) {
        int current_size = partition_stack[--partition_count];

        // Skip if the partition is trivially sorted
        if (current_size <= 1) continue;

        // Choose a pivot
        int pivot = choose_pivot(a, current_size);
        printf("pivot = %d\n", pivot);
        int smaller_count = 0;

        // Partition the elements
        for (int i = 0; i < current_size; i++) {
            if (a->arr[a->top] < pivot) {
                pb(a, b); // Push smaller elements to B
                smaller_count++;
            } else {
                ra(a); // Rotate larger elements in A
            }
        }

printf("Stack A: ");
for (int i = 0; i <= a->top; i++) printf("%d ", a->arr[i]);
printf("\n");
printf("Stack B: ");
for (int i = 0; i <= b->top; i++) printf("%d ", b->arr[i]);
printf("\n");

        // Push larger partition size (remaining in A)
        partition_stack[partition_count++] = current_size - smaller_count;

        // Push smaller partition size (moved to B)
        partition_stack[partition_count++] = smaller_count;
printf("Stack A: ");
for (int i = 0; i <= a->top; i++) printf("%d ", a->arr[i]);
printf("\n");
printf("Stack B: ");
for (int i = 0; i <= b->top; i++) printf("%d ", b->arr[i]);
printf("\n");

        // Move smaller elements back from B to A
        for (int i = 0; i < smaller_count; i++) {
            pa(a, b);
        }
    }
printf("Stack A: ");
for (int i = 0; i <= a->top; i++) printf("%d ", a->arr[i]);
printf("\n");
printf("Stack B: ");
for (int i = 0; i <= b->top; i++) printf("%d ", b->arr[i]);
printf("\n");

}


// Example usage
int main() {
    // Initialize stacks
    t_stack a, b;
    int size = 5;

    a.arr = (int *)malloc(size * sizeof(int));
    b.arr = (int *)malloc(size * sizeof(int));

    a.top = size - 1;
    b.top = -1;
    a.size = size;
    b.size = size;

    // Example input
    a.arr[0] = 4;
    a.arr[1] = 2;
    a.arr[2] = 8;
    a.arr[3] = 1;
    a.arr[4] = 5;

    // Print initial state
    printf("Initial stack A: ");
    for (int i = 0; i <= a.top; i++) printf("%d ", a.arr[i]);
    printf("\n");

    // Sort using quicksort-inspired method
    quick_sort_push_swap(&a, &b, size);

    // Print final sorted stack
    printf("Sorted stack A: ");
    for (int i = 0; i <= a.top; i++) printf("%d ", a.arr[i]);
    printf("\n");

    // Free memory
    free(a.arr);
    free(b.arr);

    return 0;
}
