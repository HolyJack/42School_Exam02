#include "get_next_line.h"

int ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

void	ft_strcpy(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
}

char	*ft_strdup(char *s)
{
	const int	slen = ft_strlen(s);
	char		*tmp;

	tmp = (char *) malloc(sizeof(char) * (slen + 1));
	ft_strcpy(tmp, s);
	return (tmp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	const int	lens1 = ft_strlen(s1);
	const int	lens2 = ft_strlen(s2);
	char		*nstr;

	nstr = malloc(sizeof(char) * (lens1 + lens2 + 1));
	nstr[lens1 + lens2] = '\0';
	ft_strcpy(nstr, s1);
	ft_strcpy(nstr + lens1, s2);
	return (nstr);
}

int get_next_line(char **line)
{
	char	*tmp;
	char	*buf;
	int		rdlen;

	buf = malloc(sizeof(char) * 2);
	*line = NULL;
	while ((rdlen = read(0, buf, 1)) > 0)
	{
		buf[rdlen] = '\0';
		if (*buf == '\n')
			break;
		if (!*line)
			*line = ft_strdup(buf);
		else
		{
			tmp = *line;
			*line = ft_strjoin(*line, buf);
			free(tmp);
		}
	}
	free(buf);
	if (rdlen < 0)
		return (-1);
	if (rdlen == 0 && !*line)
		return (0);
	return (1);
}
