/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:53:35 by luigi             #+#    #+#             */
/*   Updated: 2024/09/05 12:02:25 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_a, t_stack *stack_b, t_stack_root *stack_root)
{
	t_stack		*current;
	int			i;

	i = -1;
	current = stack_a;
	(void)(*stack_b);
	if (stack_root->size_b != 0)
		return (0);
	while (++i < stack_root->size_a - 1)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

int is_a_sorted(t_stack **stack, t_stack_root **stack_root, int size)
{
    t_stack *current;
    int i;

    if (!*stack)
        return (0);  // Stack is empty, return false
    if (size > (*stack_root)->size_a)
        return (0);  // Invalid size, return false
    if (size <= 1)
        return (1);  // Trivially sorted

    current = *stack;  // Start with the top of the stack
    i = 1;
    while (i < size)
    {
        if (current->prev->num < current->num)  // Check if elements are in ascending order
            return (0);  // If the order is violated, return false
        current = current->prev;  // Move to the next element
        i++;
    }
    return (1);  // Stack is sorted, return true
}


int is_b_sorted(t_stack **stack, t_stack_root **stack_root, int size)
{
    t_stack *current;
    int i;

    // Initial checks
    if (!*stack)
        return (0);  // Stack is empty, return false
    if (size > (*stack_root)->size_b)
        return (0);  // Requested size is larger than the size of stack B
    if (size <= 1)
        return (1);  // A stack with 1 or 0 elements is trivially sorted

    // Set the current element to the top of the stack
    current = *stack;
    i = 1;

    // Traverse the stack and check if each element is in descending order
    while (i < size)
    {
        // Compare the current element with the next one
        if (current->next->num > current->num)  // It should be in descending order
            return (0);  // Return false if the order is violated
        current = current->next;  // Move to the next element
        i++;
    }
    return (1);  // Stack is sorted, return true
}

// int	is_b_sorted(t_stack **stack, t_stack_root **stack_root, int size)
// {
// 	t_stack		*current;
// 	int			value;
// 	int			i;
//
// 	if (!*stack)
// 		return (0);
// 	if (size > (*stack_root)->size_b)
// 		return (0);
// 	if (size <= 1)
// 		return (1);
//
// 	current = (*stack)->next;
// 	value = (*stack)->num;
// 	i = 0;
// 	while (++i < size)
// 	{
// 		current = current->next;
// 		if (current->num != --value)
// 			return (0);
// 	}
// 	return (1);
// }
//
