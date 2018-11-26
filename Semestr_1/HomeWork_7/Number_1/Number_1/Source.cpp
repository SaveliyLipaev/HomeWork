#include "InteractiveWindow.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!test())
	{
		cout << "���� �� �������\n";
		return 1;
	}
	
	auto tree = createBST();
	interactiveWindows(tree);

	deleteBST(tree);
	return 0;
}