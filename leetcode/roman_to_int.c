#include <stdio.h>

int dict_roman_to_digit(char s)
{
	if (s == 'M')
		return (1000);
	if (s == 'D')
		return (500);
	if (s == 'C')
		return (100);
	if (s == 'L')
		return (50);
	if (s == 'X')
		return (10);
	if (s == 'V')
		return (5);
	if (s == 'I')
		return (1);
	return (0);
}

int romanToInt(char * s){
    int ret;
		int digit1;
		int digit2;
		int	i;

		i = 0;
		ret = 0;
		while (s[i] && s[i + 1])
		{
			digit1 = dict_roman_to_digit(s[i]);
			digit2 = dict_roman_to_digit(s[i + 1]);
			if (digit1 < digit2)
			{
				digit1 = digit2 - digit1;
				i++;
			}
			printf("digit1: %d\n", digit1);
			ret += digit1;
			i++;
		}
		digit1 = dict_roman_to_digit(s[i]);
		ret += digit1;
    return (ret);
}

int main(void)
{
	char s[] = "MCMXCIV";
	int number;

	printf("'%s'\n", s);

	number = romanToInt(s);
	printf("%d\n", number);

	return (0);
}
