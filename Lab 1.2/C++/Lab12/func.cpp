#include "Header.h"

void createFile(const char* name) {
    int k;
    cout << "Enter the number of workers: "; cin >> k;
    ofstream outFile(name, ios::binary);
    if (!outFile.is_open()) cout << "Cannot open the file!" << endl;
    cin.ignore();
    for (int i = 0; i < k; i++)
    {
        worker b;
        cout << "\n\nWorker #" << i + 1 << endl;
        cout << "Enter name: "; getline(cin, b.name);
        cout << "Enter the date of birth: "; cin >> b.birth.day >> b.birth.mongth >> b.birth.year;
        cout << "Enter the date of hiring: "; cin >> b.hiring.day >> b.hiring.mongth >> b.hiring.year;
        cin.ignore();
        if(checkDate(b))
            outFile.write((char*)&b, sizeof(worker));
    }
    outFile.close();
}

bool checkDate(worker b) {
    SYSTEMTIME st;
    GetLocalTime(&st);
    if (b.birth.day <= 0 || b.birth.day > 31 || b.birth.mongth <= 0 || b.birth.mongth > 12 || b.birth.year > st.wYear)
        return false;
    if (b.hiring.day <= 0 || b.hiring.day > 31 || b.hiring.mongth <= 0 || b.hiring.mongth > 12 || b.hiring.year > st.wYear)
        return false;
    return true;
}

void outputFile(const char* name) {
    cout << "\nContaining of the file \"" << name << "\":" << endl;
    worker b;
    ifstream inFile(name, ios::binary);
    if (!inFile.is_open()) cout << "Cannot open the file!" << endl;
    while (inFile.read((char*)&b, sizeof(worker))) {
        cout << b.name << endl;
        cout << b.birth.day << " " << b.birth.mongth << " " << b.birth.year << endl;
        cout << b.hiring.day << " " << b.hiring.mongth << " " << b.hiring.year << endl << endl;
    }
    inFile.close();
}

int amountOfYears(int day, int mongth, int year) {
    SYSTEMTIME st;
    GetLocalTime(&st);
    int Year = st.wYear, Mongth = st.wMonth, Day = st.wDay;
    int amount = Year - year;
    if (Mongth < mongth) { amount--; }
    else if (Mongth == mongth && Day < day) { amount--; }
    return amount;
}

void outputFirstListOfWorkers(const char* name) {
    cout << "\nWorkers older then 40:" << endl;
    worker b;
    ifstream inFile(name, ios::binary);
    if (!inFile.is_open()) cout << "Cannot open the file!" << endl;
    while (inFile.read((char*)&b, sizeof(worker))) {
        if (amountOfYears(b.birth.day, b.birth.mongth, b.birth.year) >= 40)
            cout << b.name << endl;
    }
    inFile.close();
}

void outputSecondListOfWorkers(const char* name) {
    cout << "\nWorkers who works more then 20 years:" << endl;
    worker b;
    ifstream inFile(name, ios::binary);
    if (!inFile.is_open()) cout << "Cannot open the file!" << endl;
    while (inFile.read((char*)&b, sizeof(worker))) {
        if (amountOfYears(b.hiring.day, b.hiring.mongth, b.hiring.year) >= 20)
            cout << b.name << endl;
    }
    inFile.close();
}

void changeFile(const char* name) {
    worker b;
    ifstream inFile(name, ios::binary);
    ofstream outFile("copy.dat", ios::binary);
    if (!inFile.is_open() || !outFile.is_open()) cout << "Cannot open the file!" << endl;
    while (inFile.read((char*)&b, sizeof(worker))) {
        if (amountOfYears(b.hiring.day, b.hiring.mongth, b.hiring.year) >= 1)
            outFile.write((char*)&b, sizeof(worker));
    }
    inFile.close();
    outFile.close();
    if (remove(name) == 0)
        if (rename("copy.dat", name) == 0)
            cout << "\nFile successfully changed" << endl;
        else cout << "Cannot change the file!" << endl;
    else cout << "Cannot change the file!" << endl;
}