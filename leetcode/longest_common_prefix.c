#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    char    *ret;
    int     i;
    int     j;
    int     k;
    char    c;
    
    if (strsSize < 1)
        return (NULL);
    i = 0;
	j = 0;
    k = 0;
    while(strs[k][j])
    {
        c = strs[k][j];
        while (k < strsSize)
        {
            if (c == strs[k][j])
                k++;
            else
                break ;
        }
        if (k == strsSize && c == strs[k - 1][j])
        {
            i++;
            j++;
            k = 0;
        }
        else
            break;
    }
    if (i > 0)
        ret = malloc((sizeof(char) * i) + 1);
    else
        return ("");
    if (ret == NULL)
        return ("");
    j = 0;
    while (j < i)
    {
        ret[j] = strs[0][j];
        j++;
    }
    ret[j] = '\0';
    return (ret);
}

/*int main(void)
{
	char	*ret;
	char	**param;

	param = malloc(sizeof(char *) * 3);
	param[0] = malloc(sizeof(char) * 7);
	strncpy(param[0], "flower\0", 7);
	param[1] = malloc(sizeof(char) * 5);
	strncpy(param[1], "flow\0", 5);
	param[2] = malloc(sizeof(char) * 7);
	strncpy(param[2], "flight\0", 7);
	ret = longestCommonPrefix(param, 3);
	printf("%s\n", ret);
	return (0);
}*/