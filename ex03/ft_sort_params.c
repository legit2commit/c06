#include <unistd.h>
void	swap(char **a, char **b)
{
	char	*x;

	x = *a;
	*a = *b;
	*b = x;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && (*s1 || *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	print_params(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			write(1, &av[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{	
	int	arg;

	arg = 1;
	while (arg < ac - 1)
	{
		if (ft_strcmp(av[arg + 1], av[arg]) < 0)
		{
			swap(&av[arg + 1], &av[arg]);
			arg = 1;
		}
		else
			arg++;
	}
	print_params(ac, av);
	return (0);
}
