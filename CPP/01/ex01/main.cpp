/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:58:26 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/30 16:43:30 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zom;
    int idx = 4;

    zom = zombieHorde(idx, "kyujlee");
    for(int i = 0; i < idx ; i++)
        zom[i].announce();
    delete []zom;
    
}