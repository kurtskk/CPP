#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}


void Harl::debug()
{
	std::cout << "Tem um catálogo dos catálogos do jogo, que incrível. E tem um monte de 'Ai', e o catálogo das armas, ai que irado. Meu Deussss eu tô passando mal." << std::endl;
}

void Harl::info()
{
	std::cout << "Eu jogo Resident Evil desde o 1. Eu joguei todos, ok? Todos! "
			  << "Essa é a diferença de um fã pra um fanboy, certo? "
			  << "Aqui a diferença de um fã pra um fanboy: "
			  << "eu sou fã de Resident Evil, joguei todos, zerei todos, "
			  << "tanto os principais quanto os spin-offs."
			  << std::endl;
}

void Harl::warning()
{
	std::cout << "Vou começar a história com Leon Kennedy. Só um disclaimer: "
			  << "eu não joguei, não zerei o Resident Evil 2 na época que lançou. "
			  << "Eu nunca zerei o Resident Evil 2, então pra mim é tudo novidade."
			  << std::endl;
}

void Harl::error()
{
	std::cout << "Vai conseguir medir as reações das pessoas, ondas cerebrais." << std::endl;
}

void Harl::complain( std::string level )
{
	const char *name[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*ptr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i = 0;
	while(i < 4)
	{
		if(name[i] == level)
		{
			return (this->*ptr[i])();
		}
		i += 1;
	}
}