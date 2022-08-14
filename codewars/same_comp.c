#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//Given two arrays a and b write a function comp(a, b) (orcompSame(a, b)) that checks whether the two arrays have the "same" elements,
//with the same multiplicities (the multiplicity of a member is the number of times it appears). 
//"Same" means, here, that the elements in b are the elements in a squared, regardless of the order.
bool comp(const int *a, const int *b, size_t n)
{
	size_t	i;
	size_t	j;

	if (!a || !b)
		return (false);
	i = 0;
	j = 0;
	while (i < n)
	{	
		printf("a[%lu] = %d e b[%lu] = %d\n", i, a[i],i,  b[i]);
		i++;
	}
	i = 0;
	while (i < n)
	{
		if (a[i] == b[j] || b[j] == (a[i] * a[i]))
		{
			i = 0;
			j++;
			if (j == n)
				break ;
			continue ;
		}
		else
			i++;
		if (i == n)
			return (false);
	}
	return (true);
}

int main(void)
{
	int a[8] = {121, 144, 19, 161, 19, 144, 19, 11};
  int b[8] = {14641, 20736, 361, 25921, 361, 20736, 362, 121};
	bool	ret;
	ret = comp(a, b, 8);
	printf("%d\n", ret);

	return (0);
}
