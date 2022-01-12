#include <unistd.h>

int ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

char	*ft_strchr(char *s, int c)
{
	int	ssize;

	ssize = ft_strlen(s) + 1;
	while (ssize-- > 0)
	{
		if (*s == (char) c)
			return (s);
		s++;
	}
	return (NULL);
}

void ft_inter(char *s1, char *s2)
{
	char	nstr[ft_strlen(s1) + 1];
	int		index;

	s1--;
	index = 0;
	while (*s1++)
		if (!ft_strchr(nstr, *s1) && ft_strchr(s2, *s1))
			nstr[index++] = *s1;
	nstr[index] = '\0';
	ft_putstr(nstr);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
