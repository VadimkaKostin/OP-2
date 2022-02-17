#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> createText();

void createFile(string,vector<string>);

void outputFile(string);

void createSecondFile(vector<string>,string);

char findCharecter(string);

int main(){
    string Name1="File1.txt", Name2="File2.txt";
    vector<string> Text;

    Text=createText();
    createFile(Name1,Text);
    outputFile(Name1);

    createSecondFile(Text,Name2);
    outputFile(Name2);

    system("pause");
}

vector<string> createText(){
    cout<<"While input the text press Enter \
    \nto input new line and \
    \nCtrl+D to finish input "<<endl;
    cout<<"\nEnter texr:"<<endl;
    string str;
    int code=4;
    vector<string> text;
    while(int(str[0])!=code){
        getline(cin,str);
        text.push_back(str);
    }
    return text;
}

void createFile(string name,vector<string> text){
    ofstream outFile(name, ios::trunc);

    if(!outFile.is_open()) cout<<"Cannot create the File!"<<endl;

    for (int i = 0; i < text.size()-1; i++)
    {
        outFile<<text[i]<<endl;
    }
    
    outFile.close();
}

void outputFile(string name){
    cout<<"\nFile \""<<name<<"\":"<<endl;

    ifstream inFile(name);
    if(!inFile.is_open()) cout<<"Cannot open the File!"<<endl;
    string str;

    while(!inFile.eof()){
        getline(inFile,str);
        cout<<str<<endl;
    }

    inFile.close();
}

void createSecondFile(vector<string> text, string name2){
    ofstream outFile(name2, ios::trunc);

    string str;

    if(!outFile.is_open()) cout<<"Cannot create the file!"<<endl;
    for(int i=0;i<text.size()-1;i++){
        str=text[i];
        str = str + ' ' + findCharecter(str);
        outFile<<str<<endl;
    }

    outFile.close();
}

char findCharecter(string str){
    int pos=0;
    for (int i = 0; str[i]!=' '; i++)
    {
        pos++;
    }
    return str[--pos];
}