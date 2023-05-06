#include "Utils.h"

void Utils::clearInputBuffer()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Utils::pause()
{
	std::system("pause");	// esto imprime un mensaje de "Presione una tecla para continuar..." y unicamente sirve en Windows
}

void Utils::clearScreen()
{
	std::system("cls");
}
