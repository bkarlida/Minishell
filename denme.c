int		find_helper(char **p, char *a)
{
	int i;
	int k;
	int flag;

	i = 0;
	while (p[i])
	{
		k = 0;
		flag = 0;
		while (p[i][k])
		{
			flag = 1;
			if (p[i][k] == a[k])
			{
				k++;
			}
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			return(1);
		i++;
	}
	return(0);
}

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char **p;
    char *a;
    int i = 0;

    p = malloc(sizeof(char *) * 3);
    p[0] = malloc(sizeof(char) * 10);   
    p[1] = malloc(sizeof(char) * 10);   
    p[2] = malloc(sizeof(char) * 10);
    p[0] = "burak krldg 23";
    p[1] = "42 istanbul kocaeli";
    p[2] = "fenerbahçe champ aag";
    printf("%d\n", find_helper(p, "burak krldg 23"));
}