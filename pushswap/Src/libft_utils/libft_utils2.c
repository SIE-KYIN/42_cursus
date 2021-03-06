/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:58:32 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/15 12:58:34 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Inc/pushswap.h"

static int	cnt_word(char const *s, char c)
{
	size_t	i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (*(s + i))
	{
		if (!ft_isdigit(*(s + i)))
			if (*(s + i) != c && *(s + i) != '-')
				return (-1);
		if (*(s + i) == c)
			i++;
		else
		{
			cnt++;
			while (*(s + i) != c && *(s + i))
				i++;
		}
	}
	return (cnt);
}

static int	cut_str(char const *s, char c, char **ret, size_t word)
{
	size_t	idx1;
	size_t	idx2;

	idx1 = 0;
	while (*(s + idx1))
	{
		if (*(s + idx1) == c)
			idx1++;
		else
		{
			idx2 = 0;
			while (*(s + idx1 + idx2) != c && *(s + idx1 + idx2))
				idx2++;
			*(ret + word) = (char *)malloc(idx2 + 1);
			ft_memcpy(*(ret + word), s + idx1, idx2);
			*(*(ret + word) + idx2) = 0;
			idx1 += idx2;
			word++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		cnt;
	char	**ret;

	if (!s)
		return ((void *)0);
	cnt = cnt_word(s, c);
	if (cnt == -1)
		return ((void *)0);
	ret = (char **)malloc(sizeof(char *) * (cnt + 1));
	*(ret + cnt) = 0;
	if (!cut_str(s, c, ret, 0))
		return (0);
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_1;
	size_t	len_2;
	char	*ret;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	ret = (char *)malloc(len_1 + len_2 + 2);
	*(ret + len_1 + len_2 + 1) = 0;
	ft_memcpy(ret, s1, len_1);
	ret[len_1] = ' ';
	ft_memcpy(ret + len_1 + 1, s2, len_2);
	return (ret);
}
