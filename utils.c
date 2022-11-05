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

/*int main()
{
	t_list	*a = NULL;
	int i = 1;
	int n;

	if(!a)
		a = lstnew(i++);
	while (i < 4)
		lstadd_end(&a, lstnew(i++));
	while (a != NULL)
	{
		printf("%d ", a->content);
		if (a->next == NULL)
			break ;
		a = a->next;
	}
	a = firstelement(&a);
	n = get_sizelst(&a);
	printf("\n valeur de n : %d\n", n);
	return 0;
}*/
