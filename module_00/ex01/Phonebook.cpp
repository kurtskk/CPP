#include "Phonebook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	count = 0;
}

std::string PhoneBook::getInput(std::string prompt)
{
	std::string input;

	while(true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			exit(0);
		}

		if(!input.empty())
			return input;
		
		std::cout << "Field cannot be empty!" << std::endl;
	}
}

void  PhoneBook::addContact()
{
	Contact newContact;

	newContact.setFirstName(getInput("Enter first name: "));
	newContact.setLastName(getInput("Enter last name: "));
	newContact.setNickName(getInput("Enter nickname: "));
	newContact.setPhoneNumber(getInput("Enter phone number: "));
	newContact.setDarkestSecret(getInput("Enter darkest secret: "));

	contacts[index] = newContact;

	index++;

	if (index == 8)
		index = 0;
	if (count < 8)
		count++;

	std::cout <<  "Contact saved! ✅" <<  std::endl;
}

std::string PhoneBook::formatField(std::string str)
{
	if(str.length() > 10)
		return str.replace(9, str.length() - 9, ".");
	return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::displayContactsTable()
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for(int i = 0; i < count; i++)
	{
		std::cout << "|"
				  << std::setw(10) << i << "|"
				  << formatField(contacts[i].getFirstName()) << "|"
				  << formatField(contacts[i].getLastName()) << "|"
				  << formatField(contacts[i].getNickName()) << "|"
				  << std::endl;
	}
}

void PhoneBook::askContactIndexAndDisplay()
{
	while(true)
	{
		std::cout << "--> To more details, input the contact's index:\n";
		std::cout << "--> To return to menu type -1:\n" << std::endl;

		std::string input;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			exit(0);
		}

		if (input == "-1")
			return ;
		bool valid = true;
		for(size_t i = 0; i < input.length(); i++)
		{
			if (!std::isdigit(input[i]))
			{
				valid = false;
				break;
			}
			continue;
		}
		if (!valid)
		{
			std::cout << "Invalid index!" << std::endl;
			continue;
		}
		int index = std::atoi(input.c_str());
		if (index < 0 || index >= count)
		{
			std::cout << "Invalid index!" << std::endl;
    		continue;
		}
		std::cout << std::endl;
		std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
		std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
	}
}

void PhoneBook::searchContact()
{
	if (count == 0)
	{
		std::cout << "No contacts available." << std::endl;
		return;
	}
	displayContactsTable();
    askContactIndexAndDisplay();
}
