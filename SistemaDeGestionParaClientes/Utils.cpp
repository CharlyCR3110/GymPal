#include "Utils.h"

void Utils::clearInputBuffer()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Utils::pause()
{
	std::cout << "Presione enter para continuar...";
	std::system("pause");
}

void Utils::clearScreen()
{
	std::system("cls");
}
