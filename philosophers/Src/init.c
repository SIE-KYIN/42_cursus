/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:46:39 by kyujlee           #+#    #+#             */
/*   Updated: 2022/05/10 22:46:41 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philo.h"

void init_time(t_info *info)
{
	struct timeval  tv;

	gettimeofday(&tv, NULL);
	info->time.start_time_s = tv.tv_sec;
	info->time.start_time_us = tv.tv_usec;
}

void init_rules(t_info *info, char **argv)
{
	info->rules.philo_num = ft_atoi(argv[1]);
	info->rules.time_to_die = ft_atoi(argv[2]);
	info->rules.time_to_eat = ft_atoi(argv[3]);
	info->rules.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] == NULL)
		info->rules.least_eat = -1;
	else
		info->rules.least_eat = ft_atoi(argv[5]);
}

void init_pointer(t_info *info)
{
	int	i;

	i = -1;
	info->philos = (t_philo *)malloc(sizeof(t_philo) * info->rules.philo_num);
	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->rules.philo_num);
	info->state = (int *)malloc(sizeof(int) * info->rules.philo_num);
	while (++i < info->rules.philo_num)
		pthread_mutex_init(&info->forks[i], NULL);
}

void init_philos(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->rules.philo_num)
	{
		if (i % 2 || i == info->rules.philo_num - 1)
			info->state[i] = 0;
		else
			info->state[i] = 1;
		info->philos[i].id = i;
		info->philos[i].eat_cnt = 0;
		info->philos[i].left_fork = &(info->forks[i]);
		info->philos[i].right_fork = &(info->forks[(i + 1) % info->rules.philo_num]);
		info->philos->info = info;
	}
}