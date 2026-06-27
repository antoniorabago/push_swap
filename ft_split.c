
#include "push_swap.h"

static unsigned int	ft_word_size(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static unsigned int	ft_count_words(char const *s, char c)
{
	unsigned int	words;
	unsigned int	i;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

static void	ft_free(char **s, unsigned int pos)
{
	while (pos > 0)
	{
		pos--;
		free(s[pos]);
	}
	free(s);
}

static int	ft_fill_array(char const *s, char c, char **res)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	word_len;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word_len = ft_word_size(s + i, c);
			res[j] = ft_substr(s, i, word_len);
			if (!res[j])
			{
				ft_free(res, j);
				return (0);
			}
			j++;
			i += word_len;
		}
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	res[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (s == NULL)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!res)
		return (NULL);
	if (!ft_fill_array(s, c, res))
		return (NULL);
	return (res);
}