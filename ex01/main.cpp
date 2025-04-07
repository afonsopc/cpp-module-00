/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:18:23 by afpachec          #+#    #+#             */
/*   Updated: 2025/04/07 23:29:38 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

static void    handle_add(PhoneBook &phonebook) {
    std::string phone_number_str;
    Contact contact;

    std::cout << "Enter the first name: ";
    std::getline(std::cin, contact.first_name);
    std::cout << "Enter the last name: ";
    std::getline(std::cin, contact.last_name);
    std::cout << "Enter the nickname name: ";
    std::getline(std::cin, contact.nickname);
    std::cout << "Enter the phone number: ";
    std::getline(std::cin, phone_number_str);
    if (phone_number_str.length() > 10) {
        std::cout << "Phone number is too long." << std::endl;
        return ;
    }
    contact.phone_number = std::atoi(phone_number_str.c_str());
    std::cout << "Enter the darkest secret: ";
    std::getline(std::cin, contact.darkest_secret);
    if (phonebook.add(contact))
        std::cout << "Contact added successfully!" << std::endl;
    else
        std::cout << "Failed to add contact." << std::endl;
}

static std::string truncate_string(const std::string &str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

static void print_contact(const Contact &contact) {
    std::cout << "First Name: " << contact.first_name << std::endl;
    std::cout << "Last Name: " << contact.last_name << std::endl;
    std::cout << "Nickname: " << contact.nickname << std::endl;
    std::cout << "Phone Number: " << contact.phone_number << std::endl;
    std::cout << "Darkest Secret: " << contact.darkest_secret << std::endl;
}

static void    handle_search(PhoneBook &phonebook) {
    int index;
    std::string index_str;

    std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
    for (int i = 0; i < PHONEBOOK_CONTACT_SIZE; i++)
    {
        if (phonebook.contacts[i].first_name.empty())
            continue ;
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncate_string(phonebook.contacts[i].first_name) << "|";
        std::cout << std::setw(10) << truncate_string(phonebook.contacts[i].last_name) << "|";
        std::cout << std::setw(10) << truncate_string(phonebook.contacts[i].nickname) << std::endl;
    }
    std::cout << "Select a contact index: ";
    std::getline(std::cin, index_str);
    index = std::atoi(index_str.c_str());
    if (index < 0 || index >= PHONEBOOK_CONTACT_SIZE)
    {
        std::cout << "Invalid index." << std::endl;
        return ;
    }
    if (phonebook.contacts[index].first_name.empty())
    {
        std::cout << "Contact not found." << std::endl;
        return ;
    }
    print_contact(phonebook.contacts[index]);
}

int main(void) {
    PhoneBook phonebook;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (command == "EXIT")
            break ;
        else if (command == "ADD")
            handle_add(phonebook);
        else if (command == "SEARCH")
            handle_search(phonebook);
    }
}
