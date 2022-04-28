#include "Header.h"

int main() {
    setlocale(LC_ALL, ".866");
    const char* fileName = "Katalog.txt";
    createFile(fileName);
    outputFile(fileName);
    outputFirstListOfWorkers(fileName);
    outputSecondListOfWorkers(fileName);
    changeFile(fileName);
    outputFile(fileName);

    fileName = nullptr;

    system("pause");
}