#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct date {
    int day,
        mongth,
        year;
};

struct worker {
    string name;
    date birth;
    date hiring;
};

void createFile(const char*);
bool checkDate(worker);
void outputFile(const char*);
void outputFirstListOfWorkers(const char*);
void outputSecondListOfWorkers(const char*);
int amountOfYears(int, int, int);
void changeFile(const char*);