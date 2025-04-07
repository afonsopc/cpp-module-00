/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:32:11 by afpachec          #+#    #+#             */
/*   Updated: 2025/04/07 22:20:33 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "contact.hpp"

# ifndef PHONEBOOK_CONTACT_SIZE
#  define PHONEBOOK_CONTACT_SIZE 8
# endif

class PhoneBook {
    public:
        Contact  contacts[PHONEBOOK_CONTACT_SIZE];
    
        bool    add(Contact contact);
};

#endif