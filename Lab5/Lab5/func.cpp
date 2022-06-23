#include "Header.h"

Tree* readFile()
{
	Tree* root = NULL;
	ifstream outFile("Program.txt");

	if (!outFile) cout << "Cannot open the file!" << endl;

	cout << "Program:" << endl;

	int i = 1;

	while (!outFile.eof())
	{
		string str;
		string name;
		bool write = false;
		getline(outFile, str);
		cout << setw(2) << i << " " << str << endl;
		if (str.find("int ") < str.length() && str != "int main()" && str != "int main(){")
		{
			if (str.find('=') < str.length()) name = str.substr(str.find("int ") + 4, str.find('=') - 5 - str.find("int "));
			else name = str.substr(str.find("int ") + 4,str.length() - 5 - str.find("int "));
			write = true;
		}
		if (str.find("float ") < str.length())
		{
			if (str.find('=') < str.length()) name = str.substr(str.find("float ") + 6, str.find('=') - 7 - str.find("float "));
			else name = str.substr(str.find("float ") + 6, str.length() - 7 - str.find("float "));
			write = true;
		}
		if (str.find("double ") < str.length())
		{
			if (str.find('=') < str.length()) name = str.substr(str.find("double ") + 7, str.find('=') - 8 - str.find("double "));
			else name = str.substr(str.find("double ") + 7, str.length() - 8 - str.find("double "));
			write = true;
		}
		if (str.find("string ") < str.length())
		{
			if (str.find('=') < str.length()) name = str.substr(str.find("string ") + 7, str.find('=') - 8 - str.find("string "));
			else name = str.substr(str.find("string ") + 7, str.length() - 8 - str.find("string "));
			write = true;
		}
		if (str.find("bool ") < str.length())
		{
			if (str.find('=') < str.length()) name = str.substr(str.find("bool ") + 5, str.find('=') - 6 - str.find("bool "));
			else name = str.substr(str.find("bool ") + 5, str.length() - 6 - str.find("bool "));
			write = true;
		}

		if (write)
			if (str.find("const") < str.length()) insert(root, name, i, -1);
			else insert(root, name, i, 1);

		i++;
	}

	outFile.close();
	return root;
}

void insert(Tree*& current, string name, int line, int branch)
{
	if (current == NULL) current = new Tree(name,line);
	else
	{
		if (branch < 0) insert(current->right, name, line, branch);
		else insert(current->left, name, line, branch);
	}
}

void displayTree(Tree* current, int count = 0)
{
	if (current != NULL)
	{
		string space = " ";
		for (int i = 0; i < count; i++)
		{
			space += "   ";
		}
		displayTree(current->right, count + 1);
		cout << space << current->line << ") " << current->data << endl;
		displayTree(current->left, count + 1);
	}
}