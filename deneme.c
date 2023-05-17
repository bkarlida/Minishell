void    ms_parser(char *line)
{
    char **str;
	char *ptr;   
    int i;
    int flag;
    int k;
    int j;
    int m;
    int z;
	int count;

    k = 0;
	z = 0;
    j = 0;
    m = 0;
	flag = 0;
    i = 0;
	count = 0;
    while (line[i])
    {
      if (line[i] == '"')
	  {
		count++;
		k = i;
		k++;
		while (line[k])
		{
			if (line[k] == '"')
			{
				count++;
				z = k;
				flag = 1;
				break;
			}
			k++;
		}
		k = i;
		if (count == 1)
		{
			printf("%s", "errror");
			break;
		}
		
		if (flag == 1)
		{
			
			
			while ((z != (k +1)) && line[k])
			{
					str[j][m] =line[k];
					k++;
					m++;
				
			}
			i = z + 1;
			j++;
			m = 0;
		}
		flag = 0;
		
	  }
	  else
	  	i++;
	  
    }
	if (count == 1)
	{
		printf("%s", "errorr");
	}
	while (str[j])
	{
		m = 0;
		while (str[j][m])
		{
			printf("%c", m);
			m++;
		}
		j++;
	}
	
}

void	str_parse(char *line)
{
	char **str;
	int i;
	int k;
	int j;

	i = 0;
	j = 0;
	k = 0;
	str = malloc(sizeof(char *) * 100);
	if (!ms_parser(line))
	{
		while (line[j])
		{
			if (line[j] != '"')
			{
				while (line[j] != '"')
				{
					str[i][k] = line[j];
					k++;
					j++;
				}
				i++;
			}
			else
			{
				str[i] = ms_parser(j + line);
				j = g_var.lparse_int_value;
				i++;
				j++;
			}
			
		}
		
	}
	i = 0;
	j = 0;
	
	while (str[i])
	{
	perror("a");
		while (str[i][j])
		{
			perror("drhd");
			printf("%s\n", str[0]);
			printf("%c", str[i][j]);
			j++;
		}
		i++;
	}
	

}

int main ()
{
    char s[20] = "burak krlkrnmg"
}


