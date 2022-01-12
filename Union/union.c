#include <unistd.h>

int	ft_strlen(char *str)
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

int	ft_subunion(char *dst, int index, char *src)
{
	src--;
	while (*src++)
		if (!ft_strchr(dst, *src))
			dst[index++] = *src;
	return (index);
}

void	ft_union(char *s1, char *s2)
{
	char nstr[ft_strlen(s1) + ft_strlen(s2)];
	int	index;

	index = 0;
	index = ft_subunion(nstr, index, s1);
	index = ft_subunion(nstr, index, s2);
	nstr[index] = '\0';
	ft_putstr(nstr);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
