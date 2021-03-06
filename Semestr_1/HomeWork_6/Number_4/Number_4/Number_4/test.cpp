#include "ListFor6.4.h"
#include <fstream>

bool test()
{
	std::fstream file("Phonebook.txt");
	if (!file.is_open())
	{
		return false;
	}

	auto list = createList();

	while (!file.eof())
	{
		std::string nameBuffer;
		std::string numberBuffer;

		getline(file, nameBuffer);
		getline(file, numberBuffer);

		push(list, nameBuffer, numberBuffer);
	}
	file.close();

	mergeSort(list, true);

	if (!checkSort(list, true))
	{
		deleteList(list);
		return false;
	}

	mergeSort(list, false);

	if (!checkSort(list, false))
	{
		deleteList(list);
		return false;
	}

	deleteList(list);
	return true;
}