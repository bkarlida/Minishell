/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:05:05 by bkarlida          #+#    #+#             */
/*   Updated: 2023/06/06 19:21:24 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// "0" pwd değiştirme isteği, "0"dan farklı değer pwd çekme isteği
static char *get_pwd(char *path, int key)
{
    static char *pwd = -1;
    
    if (key == 0)
    {
        if (pwd == -1)
        {
            pwd = (char *)malloc(sizeof(char) * 256);
            ft_strlcpy(pwd, path, ft_strlen(path));
            return (0);
        }
        ft_strlcpy(pwd, path, ft_strlen(path));
        return (0);
    }
    return (pwd);
}

static char *cut_helper(const char *str)
{
	int i;
	char *rstr;
	
	i = ft_strlen(str) - 1;
	rstr = (char *)malloc(i + 2);
	if (str[i] == '/')
		i--;
	while (i >= 0 && str[i] != '/')
		i--;
	ft_strlcpy(rstr, str, i + 1);
	if (ft_strlen(rstr) < 2)
		ft_strlcpy(rstr, "/", 2);
	return (rstr);
}

static void cd_back(char *path)
{
	char *p;

	p = cut_helper(path);
	printf("cut_back: %s\n", p);
	if (chdir(p) != -1)
		get_pwd(p, 0);
}

static void cd_next(char *path, char *next)
{
	char *p;

	p = ft_strdup("/");
	p = ft_strjoin(path, p);
	p = ft_strjoin(p, next);
	if (chdir(p) != -1)
		get_pwd(p, 0);
}

static void home_helper(char *path, char *home)
{
	int i;
	int key;
	
	i = 0;
	key = 0;
	while (path[i] && key != 2)
	{
		home[i] = path[i];
		if (path[i] == '/')
			key++;
		i++;
	}
}

int cd_func(int i)				// PWD DURMU YAPILACAK EKSİK VAR!!
{    
	char *path;
	char *home;
	static int flag = -1;
	
	if (flag == -1) // pwd'ye başlangıç konumunu atıyorum
	{
		flag = 1;
		home = (char *)malloc(32);
		path = find_in_env("PWD") + 4;
		home_helper(path, home);
		get_pwd(path, 0);
	}
	path = get_pwd(0, 1);
	if (g_var.str[i + 1])
	{
		if (strequal(g_var.str[i + 1], ".."))
		cd_back(path);
		else if (strequal(g_var.str[i + 1], "~")) // sadece cd yazdığında ana dizine çıkma eklenecek
		printf("test tilde: %d\n", chdir(home));
		else if (g_var.str[i + 1])
		cd_next(path, g_var.str[i + 1]);
	}
	return (0);
}
