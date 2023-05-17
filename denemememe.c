int	new_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*str;

	c = (unsigned char)c;
	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (c == 0)
		return (i);
	return (0);
}
char    *ms_parser(char *line)
{
	char *str;
	int	i;
	int	k;
	int	s;
	int	j;

	j = 0;
	str = malloc(sizeof(char) * (s + 1));
	i = new_strchr(line, '"');
	s = new_strchr((i + line + 1), '"');
	//printf("%d", s);
	if (i == 0 || s == 0)
	{
		perror("---------------");
		printf("%s\n", "error");
		return(0);
	}
	
	//printf("%d\n", i);
	k = i;
	g_var.lparse_int_value = (s + i + 1);
	while (k <= (s + i + 1))
	{
		str[j] = line[k];
		j++;
		k++;
	}
	return(str);
	//printf("%s\n", str);
}
void	quot_parse(char *line)
{
	char **str;
	int i;
	int	k;
	int	j;
	int	count;

	k = 0;
	j = 0;
	count = 0;
	str = malloc(sizeof(char *) * 100);
	while (line[k])
	{
		if (line[k] == '"')
		{
			count++;
		}
		k++;
	}
	k = 0;
	i = 0;
	j = 0;
	if (count % 2 == 0 && count != 0)
	{
		while (line[i])
		{
			j = 0;
			str[k] = malloc(sizeof(char) * 100);
			if (line[i] == '"')
			{
				str[k][j] = line[i];
				j++;
				i++;
				if (line[i] != '"')
				{
				
					while(line[i] && line[i] != '"')
					{
						str[k][j++] = line[i++];
					}
					if (line[i] == '"')
					{
						str[k][j] = line[i];
						j++;
						i++;
					}
				}
				else
				{
					str[k][j] = line[i];
					i++;
					j++;
				}
			}
			else
			{
				while (line[i] && line[i] != '"')
				{
					str[k][j++] = line[i++];
				}
				
			}
			str[k][j] = 0;
			k++;
		}
		
	}
	else
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == '>')
			{
				
			}
			
		}
		
	}
	//str[k][0] = '\0';
	k = 0;
	while (str[k])
	{
		printf("--%s--\n", str[k]);
		k++;
	}
}

void	rdr_parse(char *line)
{
	int i;
	int k;
	int j;
	int flag;
	char **str;

	k = 0;
	flag = 0;
	i = 0;
	j = 0;
	str = malloc(sizeof(char *) * ft_strlen(line));
	while (line[i])
	{
		j = 0;
		if (line[i] == '>')
		{
			if (line[i + 1] == '>')
			{
				str[k] = malloc(sizeof(char) * 2);
				str[k][j] = line[i];
				str[k][j + 1] = line[i + 1];
				i++;
			}	
			else if (line[i + 1] == '<')
			{
				printf("%s\n", "error");
				i++;
				break;
			}
			else
			{
				str[k] = malloc(sizeof(char) * 1);
				str[k][j] = line[i];
				i++;
			}
		}
		/*else if (line[i] == ' ')
		{
			i++;
			//while (line[i] != ' ' && line[i] != '|' && line[i] != '>' && line[i] != '<' && line[i])
			//{
			//	str[k][j++] = line[i++];
			//}
			
		}*/
		
		else if (line[i] == '<')
		{
			if (line[i + 1] == '<')
			{
				str[k] = malloc(sizeof(char) * 2);
				str[k][j] = line[i];
				str[k][j + 1] = line[i + 1];
				i++;
			}	
			else if (line[i + 1] == '>')
			{
				printf("%s\n", "error");
				i++;
				break;
			}
			else
			{
				str[k] = malloc(sizeof(char) * 2);
				str[k][j] = line[i];
				i++;
			}
		}
		else if (line[i] == '|')
		{
			if (line[i + 1] != '|' && line[i + 1] != '>' && line[i + 1] != '<')
			{
				str[k] = malloc(sizeof(char) * 1);
				str[k][j] = line[i];
				i++;
			}	
			if (line[i + 1] == '|' || line[i + 1] == '>' || line[i + 1] == '<')
			{
				printf("%s\n", "error");
				i++;
				break;
			}
		}
		else
		{
			str[k] = malloc(sizeof(char) * ft_strlen(line));
			while (line[i] && (line[i] != '>' && line[i] != '<' && line[i] != '|'))
			{
				printf("***%c***\n", line[i]);
				if (line[i] == ' ')
				{
					printf("--%c---%c-----\n", line[i - 1],line[i]);
					i++;
					printf("-----%c-----\n",line[i]);

					break;
				}
				if (line[i] != ' ')
					str[k][j++] = line[i++];	
			}	
		}
		k++;
	}
	k = 0;
		printf("%s\n", str[0]);
		printf("%s\n", str[1]);
		printf("%s\n", str[2]);
		printf("%s\n", str[3]);
		printf("%s\n", str[4]);
		printf("----------------");

	while (str[k])
	{
		printf("%s\n", str[k++]);
	}
	
}