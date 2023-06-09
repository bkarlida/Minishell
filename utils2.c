#include "minishell.h"

// key == 0; run pwd. key == 1; run env
void	ft_pwd(int key)
{
	char	*p;
	int		i;

	i = 0;
	cd_func(-1);
	if (key == 0)
	{
		p = get_pwd(0, 1);
		printf("%s\n", p);
		return ;
	}
	else if (key == 1)
	{
		while (i < g_var.env_size)
		{
			if (g_var.env[i][0] == 'P' &&
				g_var.env[i][1] == 'W' &&
				g_var.env[i][2] == 'D' &&
				g_var.env[i][3] == '=')
				break ;
			i++;
		}
		free(g_var.env[i]);
		p = get_pwd(0, 1);
		g_var.env[i] = ft_strjoin("PWD=", p);
	}
}

void	ft_env(void)
{
	int i;

	i = 0;
	ft_pwd(1);
	while (g_var.env[i])
    {
		printf("%s\n", g_var.env[i++]);
    }
	//printf("%d\n", g_var.env_size);
}