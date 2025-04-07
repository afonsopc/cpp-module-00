/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:19:52 by afpachec          #+#    #+#             */
/*   Updated: 2025/04/07 22:45:01 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
    public:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        int phone_number;
        std::string darkest_secret;

        Contact(void);
};

#endif