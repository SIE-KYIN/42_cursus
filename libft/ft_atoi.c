/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:24:36 by kyujlee           #+#    #+#             */
/*   Updated: 2021/05/12 00:12:42 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	skip(const char *str, int *i, int *sign)
{
	while ((9 <= str[*i] && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

int			ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	ret;

	i = 0;
	sign = 1;
	ret = 0;
	skip(str, &i, &sign);
	while ('0' <= str[i] && str[i] <= '9' && str[i])
	{
		if ((ret = ret * 10 + str[i] - '0') > 2147483647)
		{
			if (ret == 2147483648)
				return (-2147483648);
			else
			{
				if (sign == -1)
					return (0);
				else
					return (-1);
			}
		}
		i++;
	}
	return (sign * (int)ret);
}
