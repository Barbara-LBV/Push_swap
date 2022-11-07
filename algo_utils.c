#include "push_swap.h"

int	get_sizelst(t_list **b)
{
	int	i;
	
	i = 1;
	if ((*b) == NULL)
		return (0);
	while ((*b)->next != NULL)
	{
		*b = (*b)->next;
		i++;
	}
	return (i);
}

int	get_highest(t_list **a)
{
	int	cur_index;
	int	highest;
	t_list	*tmp;

	if ((*a) == NULL)
		return (0);
	tmp = *a;
	highest = 0;
	while (tmp != NULL)
	{
		cur_index = tmp->index;
		tmp = tmp->next;
		if (cur_index < tmp->index && highest < tmp->index)
			highest = tmp->index;
		else
		{
			if (highest < cur_index)
				highest = cur_index;
		}
		if (tmp->next == NULL)
			break ;
	}
	return (highest);
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

int	check_sorting(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp = *lst;
	if (!(*lst))
		return (1);
	while (tmp->next != NULL)
	{
		tmp1 = tmp->next;
		while (tmp1->next != NULL)
		{
			if (tmp->index > tmp1->index)
				return (0);
			tmp1 = tmp1->next;
		}
		if (tmp->index > tmp1->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	neg;

	i = 0;
	nb = 0;
	neg = 1;
	if (*str == '-')
	{
		neg *= -1;
		str++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i++] - '0';
	}
	nb *= neg;
	return (nb);
}

/*int main(int ac, char **av)
{
	t_list	*a = NULL;
	int i = 1;
	int n;

	if(!a)
		a = lstnew(ft_atoi(av[i++]));
	while (i < ac)
		lstadd_end(&a, lstnew(ft_atoi(av[i++])));
	print_list(&a);
	a = firstelement(&a);
	get_index(a);
	printf(" GET INDEX\n");
	a = firstelement(&a);
	while (a != NULL)
	{
		printf("index : %d , value : %d\n", a->index, a->content);
		if (a->next == NULL)
			break ;
		a = a->next;
	}
	a = firstelement(&a);
	n = get_highest(&a);
	printf("\n valeur de highest : %d\n", n);
	return 0;
}*/
