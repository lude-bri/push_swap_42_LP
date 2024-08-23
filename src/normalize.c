/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:25:35 by luigi             #+#    #+#             */
/*   Updated: 2024/08/08 11:41:03 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int to_rank(t_stack *stack)
{
    t_stack *sorted_stack;
    t_stack *current;
    int size;
    int idx;

    // Count the number of nodes in the circular linked list
    size = stack->size;

    // Create a new sorted stack (circular linked list)
    sorted_stack = NULL;
    current = stack;
    idx = 0;
    while (idx < size)
    {
        put_node(&sorted_stack, current->num);
        current = current->next;
        idx++;
    }

    // Sort the circular linked list
    quick_sort_stack(&sorted_stack, 0, size - 1);

    // Check for duplicates
    if (!duplicate_check_stack(sorted_stack, size))
    {
        free_stack(sorted_stack);
        return (0);
    }

    // Replace the numbers in the original stack with their normalized ranks
    current = stack;
    idx = 0;
    while (idx < size)
    {
        current->num = binary_search_stack(sorted_stack, current->num, 0, size);
        current = current->next;
        idx++;
    }

    free_stack(sorted_stack);
    return (1);
}

void quick_sort_stack(t_stack **stack, int low, int high)
{
    if (low < high)
    {
        int pi = partition_stack(stack, low, high);

        quick_sort_stack(stack, low, pi - 1);
        quick_sort_stack(stack, pi + 1, high);
    }
}

int partition_stack(t_stack **stack, int low, int high)
{
    t_stack *pivot_node = get_node_at_index(*stack, high);
    int pivot = pivot_node->num;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        t_stack *current = get_node_at_index(*stack, j);
        if (current->num <= pivot)
        {
            i++;
            swap_nodes(stack, i, j);
        }
    }
    swap_nodes(stack, i + 1, high);
    return (i + 1);
}

t_stack *get_node_at_index(t_stack *stack, int index)
{
    t_stack *current = stack;
    for (int i = 0; i < index; i++)
        current = current->next;
    return current;
}

void swap_nodes(t_stack **stack, int i, int j)
{
    t_stack *node_i = get_node_at_index(*stack, i);
    t_stack *node_j = get_node_at_index(*stack, j);

    int temp = node_i->num;
    node_i->num = node_j->num;
    node_j->num = temp;
}

int duplicate_check_stack(t_stack *stack, int size)
{
    t_stack *current = stack;
    for (int i = 0; i < size; i++)
    {
        t_stack *runner = current->next;
        for (int j = i + 1; j < size; j++)
        {
            if (current->num == runner->num)
                return (0);
            runner = runner->next;
        }
        current = current->next;
    }
    return (1);
}

int binary_search_stack(t_stack *stack, int target, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        t_stack *mid_node = get_node_at_index(stack, mid);

        if (mid_node->num == target)
            return mid;
        else if (mid_node->num < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

