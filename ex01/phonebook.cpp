/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:27:57 by tecker            #+#    #+#             */
/*   Updated: 2024/09/17 15:11:53 by tecker           ###   ########.fr       */
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

    std::cout << "options:      SEARCH | ADD | EXIT\nchoose one: ";
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

    while(flag)
    {
        std::cout << "first name: ";
        getline(std::cin, this->Contacts[this->index]->first_name);
        if (!check_input(this->Contacts[this->index]->first_name, 1))
            flag = false;
    }
    
    while(!flag)
    {
        std::cout << "last name: ";
        getline(std::cin, this->Contacts[this->index]->last_name);
        if (!check_input(this->Contacts[this->index]->last_name, 1))
            flag = true;
    }

    while(flag)
    {
        std::cout << "nick-name: ";
        getline(std::cin, this->Contacts[this->index]->nickname);
        if (!check_input(this->Contacts[this->index]->nickname, 2))
            flag = false;
    }

    while(!flag)
    {
        std::cout << "phonenumber: ";
        getline(std::cin, this->Contacts[this->index]->phonenumber);
        if (!check_input(this->Contacts[this->index]->phonenumber, 0))
            flag = true;
    }
    
    while(flag)
    {
        std::cout << "darkest secret: ";
        getline(std::cin, this->Contacts[this->index]->darkest_secret);
        if (!check_input(this->Contacts[this->index]->darkest_secret, 2))
            flag = false;
    }

    if (this->index == 8)
        this->index = 0;
    else
        this->index++;
}

std::string truncate(std::string    input)
{
    if (input.length() > 10)
        return (input.substr(0, 9) + '.');
    else
        return (input);
}

void    PhoneBook::display_contact(int index)
{
    std::string input;
    std::cout << "first name: " << this->Contacts[index]->first_name << std::endl;
    std::cout << "last name: " << this->Contacts[index]->last_name << std::endl;
    std::cout << "nick name: " << this->Contacts[index]->nickname << std::endl;
    std::cout << "phonenuber: " << this->Contacts[index]->phonenumber << std::endl;
    std::cout << "darkest secret: " << this->Contacts[index]->darkest_secret << std::endl;

    std::cout << "\n\npress space to go back to menue" << std::endl;
    getline(std::cin, input);
    if (!input.empty() && input[0] == ' ')
    {
        return ;
    }
}

void    PhoneBook::search(void)
{
    bool valid_input = false;
    int input;
    std::cout << std::right << std::setw(10) << "index";
    std::cout << " | " << std::setw(10) << std::right << "first name";
    std::cout << " | " << std::setw(10) << std::right << "last name";
    std::cout << " | " << std::setw(10) << std::right << "nick name\n" << std::endl;

    for (int i = 0; i < 8; i++)
    {
        std::cout << std::setw(10) << std::right << i;
        if (i < this->index)
        {
            std::cout << " | " << std::setw(10) << std::right << truncate(this->Contacts[i]->first_name);
            std::cout << " | " << std::setw(10) << std::right << truncate(this->Contacts[i]->last_name);
            std::cout << " | " << std::setw(10) << std::right << truncate(this->Contacts[i]->nickname);
        }
        else
            for (int i = 0; i < 3; i++)
                std::cout << " | " << std::setw(10) << ' ';
        std::cout << std::endl;
    }
    while (!valid_input)
    {
        std::cout << "enter index: ";
        std::cin >> input;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer." << std::endl;
        }
        else
        {
            if (input < 0 || input > 7)
                std::cout << "invalid index" << std::endl;
            else
                valid_input = true;
        }
    }
    this->display_contact(input);
}
