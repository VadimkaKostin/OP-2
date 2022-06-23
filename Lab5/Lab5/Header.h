#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct Tree
{
	string data;

	int line;

	Tree* left;
	Tree* right;

	Tree(string d, int n, Tree* l = NULL, Tree* r = NULL):data(d), line(n), left(l), right(r) {}
};

Tree* readFile();

void insert(Tree*&, string, int, int);

void displayTree(Tree*, int);