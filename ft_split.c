
#include "push_swap.h"

static int	ft_split_count_words(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

static void	free_mem(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

static char	*ft_split_words(char const *s, char c, char **words, int w)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	len = i;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
	{
		free_mem(words, w - 1);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		i;
	int		w;

	if (!s)
		return (NULL);
	words = malloc(sizeof(char *) * (ft_split_count_words(s, c) + 1));
	if (!words)
		return (NULL);
	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			words[w] = ft_split_words(&s[i], c, words, w);
			w++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	words[w] = NULL;
	return (words);
}