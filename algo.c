/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:09:13 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/03 15:29:20 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorting(t_list **lst)
{
	t_list	*tmp;

	tmp = NULL;
	while ((*lst)->next != NULL)
	{
		tmp = (*lst)->next;
		while (tmp->next != NULL)
		{
			if ((*lst)->index > tmp->index)
				return (0);
			tmp = tmp->next;
		}
		if ((*lst)->index > tmp->index)
			return(0);
		*lst = (*lst)->next;
	}
	return (1);
}

void	get_index(t_list *a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = a;
	while (tmp1 != NULL)
	{
		tmp1->index = 1;
		tmp1 = tmp1->next;
	}
	tmp1 = a;
	tmp2 = a->next;
	while (tmp1 != NULL)
	{
		while (tmp2 != NULL)
		{
			if (tmp1->content < tmp2->content)
				tmp2->index += 1;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		tmp2 = a;
	}
}

void	sort_three_nb(t_list **a)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (!(*a) || (*a)->next == NULL || (*a)->next->next == NULL)
		return ;
	tmp1 = *a;
	tmp2 = (*a)->next;
	tmp3 = (*a)->next->next;
	if (tmp1->index < tmp2->index && tmp3->index == 3)
		return ;
	if (tmp1->index == 3)
		rotate_a(a);
	else if (tmp2->index == 3)
		rev_rot_a(a);
	tmp1 = *a;
	tmp2 = (*a)->next;
	if (tmp1->index > tmp2->index)
		swap_a(a);
}

void	sort_five_nb(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = (*a)->next;
	while ((*a)->index < 6)
	{
		if ((*a)->index != 1 || (*a)->index != 2)
			rotate_a(a);
		if ((*a)->index == 1 || (*a)->index == 2)
		{
			push_b(a, b);
			(*a)->before = NULL;
			*a = tmp;
		}
	}
	if (!check_sorting(a))
		sort_three_nb(a);
	if (check_sorting(b))
		swap_b(b);
	if (check_sorting(a) && !(check_sorting(b)))
	{
		while ((*b)->next != NULL)
		{
			push_a(a, b);
			*b = (*b)->next;
		}
	}
}

/*void	sort_nb(t_list *a, t_list *b)
{
	
}*/

int main(int argc, char **argv)
{
	t_list	*test = NULL;;
	int i = 1;

	if (!test)
		test = lstnew(ft_atoi(argv[i++]));
	while (i < argc)
		lstadd_end(&test, lstnew(ft_atoi(argv[i++])));
	while (test != NULL)
	{
		printf("%d ", test->content);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	test = firstelement(&test);
	get_index(test);
	printf("\n GET INDEX : \n");
	while (test != NULL)
	{
		printf("%d ", test->index);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	test = firstelement(&test);
	printf("\n SORT THREE NB : \n");
	test = firstelement(&test);
	sort_three_nb(&test);
	test = firstelement(&test);
	while (test != NULL)
	{
		printf("%d ", test->content);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	lstclear(&test);
	return (0);
}
