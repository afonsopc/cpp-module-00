/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:58:28 by afpachec          #+#    #+#             */
/*   Updated: 2025/04/07 21:15:59 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }

    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        std::transform(arg.begin(), arg.end(), arg.begin(), ::toupper);
        std::cout << arg;
    }
    std::cout << std::endl;
}
