#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int     ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (str1[i] || str2[i]))
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

int		ft_lenght(int num)
{
	int count;

	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		count++;
		num *= -1;
	}
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		l;
	char	*str;
	long	num;

	num = n;
	l = ft_lenght(num);
	str = (char *)malloc(sizeof(char) * (l));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	if (num == 0)
		str[0] = '0';
	str[l] = '\0';
	while (num)
	{
		str[l - 1] = (num % 10) + '0';
		num /= 10;
		l--;
	}
	return (str);
}