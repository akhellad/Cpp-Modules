/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 03:29:36 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/31 03:30:05 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv) 
{
    if (argc < 2) 
	{
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i) 
	{
        for (int j = 0; argv[i][j]; ++j) 
		{
            std::cout << (char)toupper(argv[i][j]);
        }
        if (i < argc - 1) 
		{
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return (0);
}