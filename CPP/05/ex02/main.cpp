/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:05:53 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/08 19:18:18 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try 
    {
        Bureaucrat b("kyujin", 100);
        ShrubberyCreationForm ft("42seoulSHRU");
        ft.beSigned(b);
        b.executeForm(ft);
    } 
    catch (std::exception& e)
    {
        std::cerr << e.what() << "\n\n";
    }

    std::cout << std::endl;

    try 
    {
        Bureaucrat b("kyujin", 40);
        RobotomyRequestForm ft("42seoulROBOT");
        ft.beSigned(b);
        b.executeForm(ft);
    } 
    catch (std::exception& e)
    {
        std::cerr << e.what() << "\n\n";
    }

    std::cout << std::endl;

    try 
    {
        Bureaucrat b("kyujin", 1);
        PresidentialPardonForm ft("42seoulPARDON");
        ft.beSigned(b);
        b.executeForm(ft);
    } 
    catch (std::exception& e)
    {
        std::cerr << e.what() << "\n\n";
    }
}