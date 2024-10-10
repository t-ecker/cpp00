/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:27:57 by tecker            #+#    #+#             */
/*   Updated: 2024/10/10 21:19:03 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

int check_prompt(std::string    prompt)
{
    int length = prompt.length();
    for (int i = 0; i < length; i++)
    {
        if (std::isupper(prompt[i]))
            prompt[i] = std::tolower(prompt[i]);
    }
    if (prompt == "add")
        return (1);
    if (prompt == "exit")
        return (-1);
    if (prompt == "search")
        return (2);
    else
        return (0);
}

int check_cin(void)
{
    if (std::cin.eof())
    {
        std::cout << "End of input detected. Exiting..." << std::endl;
        exit(1);
    }
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        return (0);
    }
    return (1);
}

int PhoneBook::std_prompt(void)
{
    std::string prompt;

    std::cout << "\033[2J\033[H" << "options:      SEARCH | ADD | EXIT\nchoose one: ";
    getline(std::cin, prompt);
    if (!check_cin())
        return (0);
    return (check_prompt(prompt));
}

int check_input(std::string input, int flag)
{
    int len = input.length();
    if (!check_cin())
        return (1);
    if (input.empty())
        return (1);
    for (int i = 0; i < len; i++)
    {
        if (flag == 1 && !std::isalpha(input[i]))
            return (1);
        if (flag == 2 && (!std::isalpha(input[i]) && !std::isspace(input[i])))
            return (1);
        if (!flag && !std::isdigit(input[i]))
            return (1);
    }
    return (0);
}

void    PhoneBook::add(void)
{
    bool flag = true;
    std::string input;

    if (index >= 8)
        index = 0;

    while(flag)
    {
        std::cout << "\033[2J\033[H" << "first name: ";
        getline(std::cin, input);
        if (!check_input(input, 1))
        {
            Contacts[index].set_fn(input);
            flag = false;
        }
    }
    
    while(!flag)
    {
        std::cout << "\033[2J\033[H" << "last name: ";
        getline(std::cin, input);
        if (!check_input(input, 1))
        {
            Contacts[index].set_ln(input);
            flag = true;
        }
    }

    while(flag)
    {
        std::cout << "\033[2J\033[H" << "nick-name: ";
        getline(std::cin, input);
        if (!check_input(input, 2))
        {
            Contacts[index].set_nn(input);
            flag = false;
        }
    }

    while(!flag)
    {
        std::cout << "\033[2J\033[H" << "phonenumber: ";
        getline(std::cin, input);
        if (!check_input(input, 0))
        {
            Contacts[index].set_phone(input);
            flag = true;
        }
    }
    
    while(flag)
    {
        std::cout << "\033[2J\033[H" << "darkest secret: ";
        getline(std::cin, input);
        if (!check_input(input, 2))
        {
            Contacts[index].set_ds(input);
            flag = false;
        }
    }
    index++;
    if (index > max_index)
        max_index = index;
}

std::string truncate(std::string    input)
{
    if (input.length() > 9)
        return (input.substr(0, 9) + '.');
    else
        return (input);
}

std::string check_contact(std::string s)
{
    if (s.empty())
        return ("-");
    else
        return (s);
}

void    PhoneBook::display_contact(int index)
{
    std::string input;

    std::cout << "\033[2J\033[H" << "first name        : " << check_contact(Contacts[index].get_fn()) << std::endl;
    std::cout << "last name         : " << check_contact(Contacts[index].get_ln()) << std::endl;
    std::cout << "nick name         : " << check_contact(Contacts[index].get_nn()) << std::endl;
    std::cout << "phonenuber        : " << check_contact(Contacts[index].get_phone()) << std::endl;
    std::cout << "darkest secret    : " << check_contact(Contacts[index].get_ds()) << std::endl;

    std::cout << "\n";

    while (1)
    {
        std::cout << "press return to go back to menue";
        getline(std::cin, input);
        check_cin();
        if (input.empty())
            break;        
    }
}

void    PhoneBook::search(void)
{
    bool valid_input = false;
    std::string input;
    int dig;

    std::cout << "\033[2J\033[H" << std::right << std::setw(10) << "index";
    std::cout << " | " << std::setw(10) << std::right << "first name";
    std::cout << " | " << std::setw(10) << std::right << "last name";
    std::cout << " | " << std::setw(10) << std::right << "nick name" << std::endl;

    for (int i = 0; i < 8; i++)
    {
        std::cout << std::setw(10) << std::right << i;
        if (i < max_index)
        {
            std::cout << " | " << std::setw(10) << std::right << truncate(Contacts[i].get_fn());
            std::cout << " | " << std::setw(10) << std::right << truncate(Contacts[i].get_ln());
            std::cout << " | " << std::setw(10) << std::right << truncate(Contacts[i].get_nn());
        }
        else
            for (int i = 0; i < 3; i++)
                std::cout << " | " << std::setw(10) << ' ';
        std::cout << std::endl;
    }
    std::cout << std::endl;
    while (!valid_input)
    {
        std::cout << "enter index: ";
        getline(std::cin, input);
        if (check_input(input, 0) || input.empty())
            std::cout << "Invalid input. Please enter an integer." << std::endl;
        else
        {
            dig = std::stoi(input);
            if (dig < 0 || dig > 7)
                std::cout << "invalid index" << std::endl;
            else
                valid_input = true;
        }
    }
    display_contact(dig);
}
