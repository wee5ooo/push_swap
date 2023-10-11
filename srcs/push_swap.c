/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:02:47 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/11 10:55:42 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

char	**get_array(int ac, char **av)
{
	char	*str;
	char	**array;

	str = NULL;
	array = NULL;
	str = ft_strjoin_sp(ac, av);
	array = ft_split(str, ' ');
	free (str);
	str = NULL;
	if (ft_array_size(array) <= 1)
		exit (0);
	return (array);
}

// t_list	*init_stack_a(char **str_arr)
// {
// 	t_list	*head;
// 	int		i;

// 	head = NULL;
// 	head = malloc(sizeof(t_list));
// 	if (!head)
// 		exit (1);
// 	head->data = ft_atoi(str_arr[0]);
// 	head->distance = 0;
// 	head->index = -1;
// 	head->next = NULL;
// 	i = 1;
// 	while(str_arr[i])
// 	{
// 		head = ft_lstadd_back(head, ft_atoi(str_arr[i]));
// 		//printf("lstadd_back\n");
// 		i++;
// 	}
// 	return (head);
// }

void	init_stacks(int ac, char **av, t_list *stack_a, t_list *stack_b)
{
	char	**array_str;

	array_str = get_array(ac, av);
	stack_a = init_stack_a(array_str);
	if (ft_is_sorted(stack_a) == 0)
	{
		ft_free_array(array_str);
		exit (0);
	}
	// printf("ft_lstsize(stack_a) == %d\n", ft_lstsize(stack_a));
	// printf("lstsize: %d\n", ft_lstsize(stack_a));
	else if (ft_lstsize(stack_a) == 2)
		sa(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		three_nodes_sort(&stack_a);
	else if (ft_lstsize(stack_a) == 4 || ft_lstsize(stack_a) == 5 || ft_lstsize(stack_a) == 6)
		fvs_nodes_sort(&stack_a, &stack_b, array_str);

	//printf("stack_a:\n");
	//t_list	*curr = stack_a;
	//while (curr != NULL)
	//{
	//	printf("%d\n", curr->data);
	//	curr = curr->next;
	//}

	ft_free_array(array_str);
}

int main (int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac != 1)
	{
		parse_args(ac, av);
		init_stacks(ac, av, stack_a, stack_b);
		ft_deallocate_lst(stack_a);
		ft_deallocate_lst(stack_b);
	}
	return (0);
}
