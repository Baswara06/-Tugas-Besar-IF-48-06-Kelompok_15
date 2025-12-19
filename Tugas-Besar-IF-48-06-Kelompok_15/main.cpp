#include <iostream>
#include "Apk.h"
using namespace std;


int main() {
    ListOjol LO;
    ListPenumpang LP;

    cout << "=====================================================" << endl;
    cout << "||           PROGRAM TRANSAKSI OJEK ONLINE         ||" << endl;
    cout << "||                        BY                       ||" << endl;
    cout << "||                    AZMI HANIF                   ||" << endl;
    cout << "||               RAIHAN WENDRA BASWARA             ||" << endl;
    cout << "=====================================================" << endl;
    createListOjol(LO);
    createListPenumpang(LP);

    mainMenu(LO, LP);

    return 0;
}
