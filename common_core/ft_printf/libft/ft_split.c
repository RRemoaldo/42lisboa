/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasoares <rasoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:17:37 by rasoares          #+#    #+#             */
/*   Updated: 2024/05/03 12:51:09 by rasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	wc;
	int	i;

	wc = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			wc++;
			while (s[i] != c && s[i])
				i++;
		}
		else
		{
			while (s[i] == c && s[i])
				i++;
		}
	}
	return (wc);
}

int	check_memory(char **split, int j)
{
	if (split[j] == NULL)
	{
		while (j >= 0)
		{
			free(split[j]);
			j--;
		}
		free (split);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		start;
	int		j;

	split = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!split || s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			split[j] = ft_substr(s, start, i - start);
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}

/*
#include "libft.h"

int main(void) {
    char const *str = NULL;
    char **split = ft_split(str, 'z');

    if (!split) {
        printf("Erro ao dividir a string.\n");
        return 1;
    }
    for (int i = 0; split[i] != NULL; i++) {
        printf("Palavra %d: %s\n", i + 1, split[i]);
    }
    for (int i = 0; split[i] != NULL; i++) {
        free(split[i]);
    }
    free(split);

    return 0;
}
*/
