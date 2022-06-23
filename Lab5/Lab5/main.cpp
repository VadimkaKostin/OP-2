#include "Header.h"

int main()
{
	Tree* root = NULL;

	root = readFile();

	cout << "\nTree:" << endl;

	displayTree(root,0);

	cout << endl;

	system("pause");
}