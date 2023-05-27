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
    printf("---> rstr: %s\n", rstr); //? yeni konum
    return (rstr);
}

int	cd_func(int i)
{
    char	path[256];
    char	*a;
    char	*p;

    if (getcwd(path, sizeof(path)) == NULL)
        printf("---> Path error\n");
    else if (strequal(g_var.str[i], "pwd"))
        printf("%s\n", path);
    else if (strequal(g_var.str[i + 1], ".."))
    {
		printf("---> path %s\n", path); //? eski konum
        p = cut_helper(path);
		//(void)cut_helper_test(path);
        chdir(p);
        // aşşağıdaki kodları her cd  komutuna düzenleyip koyman lazım
        free(g_var.pwd_new);
        a = malloc(5);

        g_var.pwd_new = ft_strjoin(a, p);
        printf("%s\n",g_var.pwd_new); // pwd çalışdığında yeniden dizayn etmek için kullanıyoruz
        // ve dikkat et cd ile ileri gittiğinde env de fazladan yer ayırman gerekebilir pwd için
    }
	else if (g_var.str[i + 1])
	{
		p = ft_strjoin(path, "/");
		p = ft_strjoin(p, g_var.str[i + 1]);
		printf("yeni dizin: %s\n", p);
		chdir(p);
		free(p);
	}
	else
		printf("%d\n", chdir("~")); //! seg hatası var çözülecek
	printf("** cd işlem sonucu: %s\n", getcwd(path, sizeof(path)));
    //Eksik var cd ile geri gidildiğinde en sona geldiğinde / atılmaıs lazım bizde ise boş atıyor
    return 0;
}
