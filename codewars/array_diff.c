#include <stdlib.h>
//#include <stdio.h>
//Your goal in this kata is to implement a difference function, which subtracts one list from another and returns the result.
//It should remove all values from list a, which are present in list b keeping their order.

//  return a dynamically allocated array
//  assign the length of this array to *z
//  memory will be freed by the test suite
int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int			*ret;
	int			*tmp;

	tmp = malloc(sizeof(int) * n1);
	if (n2 == 0)
	{
		i = 0;
		while (i < n1)
		{
			tmp[i] = arr1[i];
			i++;
		}
		*z = n1;
		return (tmp);
	}
	i = 0;
	j = 0;
	k = 0;
	while (j < n2)
	{
		if (i == n1)
			break ;
		if (arr1[i] == arr2[j])
		{
			i++;
			j = 0;
			continue ;
		}
		j++;
		if (j == n2)
		{
			tmp[k] = arr1[i];
			k++;
			i++;
			j = 0;
		}
	}
	i = 0;
	ret = malloc(sizeof(int) * k);
	while (i < k)
	{
		ret[i] = tmp[i];
		i++;
	}
	free(tmp);
	*z = k;
	return (ret);
}
/*
int main(void)
{
	const int arr1[5] = {4, 3, 4, 5, 4};
  const int arr2[4] = {3, 1, 4, 5};
  //const int expected[1] = {1};   
	int			*ret;
	size_t	*z;
	size_t	i;

	i = 0;
	z = malloc(sizeof(size_t));
	ret = array_diff(arr1, 5, arr2, 4, z);
	printf("z: %lu\n", *z);
	while (i < *z)
	{
		printf("ret[%lu]: %d\n", i, ret[i]);
		i++;
	}

	return (0);
}*/
