#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *str)
{
	int n;

	if (!str)
		return(0);
	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

void	*ft_memcpy(void *ptr, const void *src, unsigned int n)
{
	const void	*d;

	d = ptr;
	if (!ptr && !src)
		return (NULL);
	while (n--)
		*((unsigned char *)d++) = *((unsigned char *)src++);
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t s_length;
	size_t i;

	s_length = 0;
	i = 0;
	if (dst == 0 || src == 0)
	{
		return (0);
	}
	while (src[s_length] != 0)
		s_length++;
	if (size != 0)
	{
		while (src[i] != 0 && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (s_length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len1;
	size_t		len2;
	char		*result;

	if (s1 == 0 && s2 == 0)
		return (NULL);
	if (s1 == 0)
		return(ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(result = malloc(len1 + len2 + 1)))
		return (NULL);
	ft_memcpy(result, s1, len1);
	ft_memcpy(result + len1, s2, len2);
	result[len1 + len2] = '\0';
	return (result);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	int		len;
	size_t	i;

	if(!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	result = malloc(len);
	if (!(result))
		return (NULL);
	i = ft_strlcpy(result, s, len);
	return (result);
}
