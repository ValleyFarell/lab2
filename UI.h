#pragma once
#include"Sequence.h"
#include"ArraySequence.h"
#include"ListSequence.h"
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

void printFromFile(const string& fileName) {
    ifstream fin(fileName);
    string strh;
    while(!fin.eof()){
        getline(fin, strh);
        cout << strh;
        cout << "\n";
    }
}

int getUserChoice(int mn, int mx) {
    cout << " >>> ";
    int choice; cin >> choice;
    while(1)
        if (choice < mn || choice > mx) cout << "Не знаю такой команды! Заново!\n";
        else break;
    return choice;
}

void menu() {
    printFromFile("./templates/menu.txt");
}

void structCreate() {
    printFromFile("./templates/structCreate.txt");
}

void typeCreate() {
    printFromFile("./templates/typeChoice.txt");
}

void mainLoop() {
    Sequence<int>* intSeq;
    Sequence<double>* doubleSeq;
    Sequence<string>* stringSeq;

    Sequence<int>* intSeqC;
    Sequence<double>* doubleSeqC;
    Sequence<string>* stringSeqC;

    int type, structSeq;

    while(1) {
        menu();
        int userChoice = getUserChoice(1, 3);
        switch (userChoice)
        {
        case 1:
            typeCreate();
            userChoice = getUserChoice(1, 4);
            if (userChoice == 4) break;
            type = userChoice;
            structCreate();
            userChoice = getUserChoice(1, 3);
            if (userChoice == 3) break;
            structSeq = userChoice;
            printFromFile("./templates/typeChoice.txt");
            if (type == 1) {
                if (structSeq == 1) {
                    intSeq = new ArraySequence<int>;
                }
                if (structSeq == 2) {
                    intSeq = new ListSequence<int>;
                }
            }
            if (type == 2) {
                if (structSeq == 1) {
                    doubleSeq = new ArraySequence<double>;
                }
                if (structSeq == 2) {
                    doubleSeq = new ListSequence<double>;
                }
            }
            if (type == 2) {
                if (structSeq == 1) {
                    stringSeq = new ArraySequence<string>;
                }
                if (structSeq == 2) {
                    stringSeq = new ListSequence<string>;
                }
            }
            switch (structSeq)
            {
            case 1:
                printFromFile("./templates/arrayMenu.txt");
                break;
            case 2:
                printFromFile("./templates/listMenu.txt");
                break;
            }
        case 2:
            /* code */
            break;
        case 3:
            exit(0);
            break;
        case -1:
            /* code */
            break;
        }
    }
}
