#include "Apk.h"

using namespace std;

// menu utama
void mainMenu(ListOjol &LO, ListPenumpang &LP) {
    int menu = -1;
    while (menu != 0) {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Admin\n";
        cout << "2. Studi Kasus\n";
        cout << "0. Exit\n";
        cout << "Pilih: ";
        cin >> menu;

        if (menu == 1) {
            menuAdmin(LO, LP);
        }
        else if (menu == 2) {
            menuStudiKasus(LO, LP);
        }
    }
}

// menu admin
void menuAdmin(ListOjol LO, ListPenumpang LP) {
    cout << "\n=== MENU ADMIN ===\n";
    tampilOjol(LO);
    cout << endl;
    tampilPenumpang(LP);
    cout << endl;
    penumpangRelasiTerbanyak(LO, LP);
    cout << endl;
    driverTergiat(LO);



    cout << "\nTekan apa saja untuk kembali...";
    cin.ignore();
    cin.get();
}

// study case
void menuStudiKasus(ListOjol &LO, ListPenumpang &LP) {
    int menu = -1;
    while (menu != 0) {
        cout << "\n=== MENU STUDI KASUS ===\n";
        cout << "1. Menu Ojol\n";
        cout << "2. Menu Penumpang\n";
        cout << "3. Menu Relasi\n";
        cout << "0. Kembali\n";
        cout << "Pilih: ";
        cin >> menu;

        if (menu == 1) {
            int m;
            cout << "\n1. Tambah Driver\n2. Hapus Driver\n3. Tampil Driver\n4. Driver Tergiat\n5. Cari Driver\nPilih: ";
            cin >> m;

            if (m == 1) {
                string id, n;
                cout << "Masukkan id dan nama ojol: ";
                cin >> id >> n;
                insertOjol(LO, createOjol(id, n));
            }
            else if (m == 2) {
                string id;
                cout << "Masukkan id Driver: ";
                cin >> id;
                deleteOjol(LO, id);
            }
            else if (m == 3) {
                tampilOjol(LO);
            }
            else if(m==4){
                cout << "\n=== Driver Tergiat ===\n";
                driverTergiat(LO);
            }
            else if(m==5){
                string id;
                cout << "Masukkan id Driver: ";
                cin >> id;
                searchOjol(LO, id);
            }
        }
        else if (menu == 2) {
            int m;
            cout << "\n1. Tambah Penumpang\n2. Hapus Penumpang\n3. Tampil Penumpang\n4. Penumpang Paling Setia\n5. Cari Penumpang\nPilih: ";
            cin >> m;

            if (m == 1) {
                string id, n;
                cout << "Masukkan id dan nama penumpang: ";
                cin >> id >> n;
                insertPenumpang(LP, createPenumpang(id, n));
            }
            else if (m == 2) {
                string id;
                cout << "Masukkan id penumpang: ";
                cin >> id;
                deletePenumpang(LP, id);
            }
            else if (m == 3) {
                tampilPenumpang(LP);
            }
            else if(m==4){
                cout << "\n=== Penumpang Paling Setia ===\n";
                penumpangRelasiTerbanyak(LO, LP);
            }
            else if(m==5){
                string id;
                cout << "Masukkan id Penumpang: ";
                cin >> id;
                searchPenumpang(LP, id);
            }
        }
        else if(menu==3){
            int m;
             cout << "1. Tambah Relasi\n2. Hapus Relasi\n3. Tampil Relasi\nPilih: ";
             cin >> m;

                if(m == 1){
                string idP, idC;
                cout << "Masukan id ojol dan penumpang:" ;
                cin >> idP >> idC;
                tambahRelasi(searchOjol(LO,idP), searchPenumpang(LP,idC));


            } else if(m == 2){
                string idP, idC;
                cout << "Masukan id ojol dan penumpang:" ;
                cin >> idP >> idC;
                hapusRelasi(searchOjol(LO,idP), idC);


            } else if(m == 3){
                string idP;
                cout << "Masukan id ojol: ";
                cin >> idP;

                tampilRelasi(searchOjol(LO,idP));
            }
        }

    }

    }




