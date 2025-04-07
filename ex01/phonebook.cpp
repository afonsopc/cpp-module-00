/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:19:25 by afpachec          #+#    #+#             */
/*   Updated: 2025/04/07 22:36:19 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static bool append_contact(PhoneBook &phonebook, Contact contact) {
    for (int i = 0; i < PHONEBOOK_CONTACT_SIZE; i++) {
        if (!phonebook.contacts[i].first_name.empty())
            continue ;
        phonebook.contacts[i] = contact;
        return (true);
    }
    return (false);
}

static  bool    shift_and_add(PhoneBook &phonebook, Contact contact) {
    for (int i = PHONEBOOK_CONTACT_SIZE - 1; i > 0; i--)
        phonebook.contacts[i] = phonebook.contacts[i - 1];
    phonebook.contacts[0] = contact;
    return (true);
}

bool    PhoneBook::add(Contact contact) {
    if (contact.darkest_secret.empty() || contact.first_name.empty()
        || contact.last_name.empty() || contact.nickname.empty())
        return (false);
    if (contacts[7].first_name.empty())
        return (append_contact(*this, contact));
    return (shift_and_add(*this, contact));
}
