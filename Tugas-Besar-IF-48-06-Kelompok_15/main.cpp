#include <iostream>
#include "Apk.h"
using namespace std;

int main() {
ListOjol LP;
ListPenumpang LC;
createListOjol(LP);
createListPenumpang(LC);


int menu = -1;
while(menu != 0){
    cout << "\n==== MENU ====\n";
    cout << "1. Menu Ojol \n";
    cout << "2. Menu Penumpang\n";
    cout << "3. Menu Relasi\n";
    cout << "0. Keluar\nPilih: ";
    cin >> menu;


    if(menu == 1){
        int m;
        cout << "1. Tambah Ojol\n2. Hapus Ojol\n3. Tampil Ojol\nPilih: ";
        cin >> m;
        if(m == 1){
            string id,n;
            cout << "Masukan id dan nama ojol :" ;
            cin >> id >> n;
            insertOjol(LP, createOjol(id,n));
            } else if(m == 2){
            string id;
            cout << "Masukan id ojol yang mau di hapus :" ;
            cin >> id;
            deleteOjol(LP,id);
            } else if(m == 3){ tampilOjol(LP); }


    } else if(menu == 2){
        int m;
        cout << "1. Tambah Penumpang \n2. Hapus Penumpang\n3. Tampil Penumpang\nPilih: ";
        cin >> m;
    if(m == 1){
        string id,n;
        cout << "Masukan id dan nama penumpang :" ;
        cin >> id >> n;
        insertPenumpang(LC, createPenumpang(id,n));
    } else if(m == 2){
        string id;
        cout << "Masukan id penumpang yang mau dihapus :" ;
        cin >> id;
        deletePenumpang(LC,id);
    } else if(m == 3){ tampilPenumpang(LC); }


    } else if(menu == 3){
        int m;
        cout << "1. Tambah Relasi\n2. Hapus Relasi\n3. Tampil Relasi\nPilih: ";
        cin >> m;


    if(m == 1){
        string idP, idC;
        cout << "Masukan id ojol dan penumpang:" ;
        cin >> idP >> idC;
        tambahRelasi(searchOjol(LP,idP), searchPenumpang(LC,idC));


    } else if(m == 2){
        string idP, idC;
        cout << "Masukan id ojol dan penumpang:" ;
        cin >> idP >> idC;
        hapusRelasi(searchOjol(LP,idP), idC);


    } else if(m == 3){
        string idP;
        cout << "Masukan id ojol: ";
        cin >> idP;

        tampilRelasi(searchOjol(LP,idP));
}
}
}
    return 0;
}
