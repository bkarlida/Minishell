#include "minishell.h"

/*                     test edilecek **********
char    *cut_helper_test(const char *str)
{
    int     i;
	int		j;
    char    *rstr;

	j = 0;
    i = ft_strlen(str) - 1;
    rstr = (char *)malloc(i + 2);
    if (str[i] == '/')
        i--;
    while (i >= 0 && str[i] != '/')
        i--;
	i++;
	while (str[i] && str[i] != '/')
		rstr[j++] = str[i++];
	rstr[j] = 0;
    printf("---> rstr test: %s\n", rstr);
    return (rstr);
}
*/

char    *cut_helper(const char *str)
{
    int     i;
    char    *rstr;

    i = ft_strlen(str) - 1;
    rstr = (char *)malloc(i + 2);
    if (str[i] == '/')
        i--;
    while (i >= 0 && str[i] != '/')
        i--;
    ft_strlcpy(rstr, str, i + 1);
    printf("---> rstr: %s\n", rstr);
    return (rstr);
}

int	cd_func(int i)
{
    char	path[256];
    char	*p;

    if (getcwd(path, sizeof(path)) == NULL)
        printf("---> Path error\n");
    else if (strequal(g_var.str[i], "pwd"))
        printf("%s\n", path);
    else if (strequal(g_var.str[i + 1], ".."))
    {
		printf("---> path %s\n", path);
        p = cut_helper(path);
		//(void)cut_helper_test(path);
        chdir(p);
    }
    
    return 0;
}
