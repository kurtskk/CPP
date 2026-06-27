#include <iostream>
#include <cctype>
#include <string>

void megaphone_string(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		std::cout << (char)std::toupper(str[i]);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
			megaphone_string(argv[i]);
		std::cout << std::endl;
	}
	return 0;
}