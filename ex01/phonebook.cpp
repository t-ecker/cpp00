/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:27:57 by tecker            #+#    #+#             */
/*   Updated: 2024/09/19 15:06:48 by tecker           ###   ########.fr       */
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

int PhoneBook::std_prompt(void)
{
    std::string prompt;

    std::cout << "\033[2J\033[H" << "options:      SEARCH | ADD | EXIT\nchoose one: ";
    getline(std::cin, prompt);
    return (check_prompt(prompt));
}

int check_input(std::string input, int flag)
{
    int len = input.length();
    
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

    if (this->index >= 8)
        this->index = 0;

    while(flag)
    {
        std::cout << "\033[2J\033[H" << "first name: ";
        getline(std::cin, this->Contacts[this->index].first_name);
        if (!check_input(this->Contacts[this->index].first_name, 1))
            flag = false;
    }
    
    while(!flag)
    {
        std::cout << "\033[2J\033[H" << "last name: ";
        getline(std::cin, this->Contacts[this->index].last_name);
        if (!check_input(this->Contacts[this->index].last_name, 1))
            flag = true;
    }

    while(flag)
    {
        std::cout << "\033[2J\033[H" << "nick-name: ";
        getline(std::cin, this->Contacts[this->index].nickname);
        if (!check_input(this->Contacts[this->index].nickname, 2))
            flag = false;
    }

    while(!flag)
    {
        std::cout << "\033[2J\033[H" << "phonenumber: ";
        getline(std::cin, this->Contacts[this->index].phonenumber);
        if (!check_input(this->Contacts[this->index].phonenumber, 0))
            flag = true;
    }
    
    while(flag)
    {
        std::cout << "\033[2J\033[H" << "darkest secret: ";
        getline(std::cin, this->Contacts[this->index].darkest_secret);
        if (!check_input(this->Contacts[this->index].darkest_secret, 2))
            flag = false;
    }
    this->index++;
    if (this->index > this->max_index)
        this->max_index = this->index;
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

    std::cout << "\033[2J\033[H" << "first name        : " << check_contact(this->Contacts[index].first_name) << std::endl;
    std::cout << "last name         : " << check_contact(this->Contacts[index].last_name) << std::endl;
    std::cout << "nick name         : " << check_contact(this->Contacts[index].nickname) << std::endl;
    std::cout << "phonenuber        : " << check_contact(this->Contacts[index].phonenumber) << std::endl;
    std::cout << "darkest secret    : " << check_contact(this->Contacts[index].darkest_secret) << std::endl;

    std::cout << "\n";

    while (1)
    {
        std::cout << "press return to go back to menue";
        getline(std::cin, input);
        if (input.empty())
            break;        
    }
}

void    PhoneBook::search(void)
{
    bool valid_input = false;
    std::string input;
    int dig;

    std::cout << std::right << std::setw(10) << "index";
    std::cout << " | " << std::setw(10) << std::right << "first name";
    std::cout << " | " << std::setw(10) << std::right << "last name";
    std::cout << " | " << std::setw(10) << std::right << "nick name\n" << std::endl;

    for (int i = 0; i < 8; i++)
    {
        std::cout << std::setw(10) << std::right << i;
        if (i < this->max_index)
        {
            std::cout << " | " << std::setw(10) << std::right << truncate(this->Contacts[i].first_name);
            std::cout << " | " << std::setw(10) << std::right << truncate(this->Contacts[i].last_name);
            std::cout << " | " << std::setw(10) << std::right << truncate(this->Contacts[i].nickname);
        }
        else
            for (int i = 0; i < 3; i++)
                std::cout << " | " << std::setw(10) << ' ';
        std::cout << std::endl;
    }
    while (!valid_input)
    {
        std::cout << "enter index: ";
        getline(std::cin, input);
        if (input.empty() || check_input(input, 0))
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
    this->display_contact(dig);
}
