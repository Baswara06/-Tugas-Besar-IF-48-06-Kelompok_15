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
    cout << "\n1. Tambah Driver Pertama"
         << "\n2. Tambah Driver Terakhir"
         << "\n3. Hapus Driver"
         << "\n4. Tampil Driver"
         << "\n5. Driver Tergiat"
         << "\n6. Cari Driver"
         << "\nPilih: ";
    cin >> m;

    if (m == 1) {
        string id, n;
        cout << "Masukkan id dan nama ojol: ";
        cin >> id >> n;
        insertOjolFirst(LO, createOjol(id, n));
    }
    else if (m == 2) {
        string id, n;
        cout << "Masukkan id dan nama ojol: ";
        cin >> id >> n;
        insertOjolLast(LO, createOjol(id, n));
    }
    else if (m == 3) {
        int d;
        cout << "\n1. Hapus Driver Pertama\n2. Hapus Driver Terakhir\nPilih: ";
        cin >> d;

        if (d == 1) {
            deleteOjolFirst(LO);
        }
        else if (d == 2) {
            deleteOjolLast(LO);
        }
    }
    else if (m == 4) {
        tampilOjol(LO);
    }
    else if (m == 5) {
        driverTergiat(LO);
    }
    else if (m == 6) {
        string id;
        cout << "Masukkan id Driver: ";
        cin >> id;
        adrOjol P = searchOjol(LO, id);
        if (P != NULL)
            cout << "Driver ditemukan: " << P->idOjol << " | " << P->nama << endl;
        else
            cout << "Driver tidak ditemukan\n";
    }
}
       else if (menu == 2) {
            int m;
            cout << "\n1. Tambah Penumpang Pertama"
         << "\n2. Tambah Penumpang Terakhir"
         << "\n3. Hapus Penumpang"
         << "\n4. Tampil Penumpang"
         << "\n5. Penumpang Paling Setia"
         << "\n6. Cari Penumpang"
         << "\nPilih: ";
    cin >> m;

    if (m == 1) {
        string id, n;
        cout << "Masukkan id dan nama penumpang: ";
        cin >> id >> n;
        insertPenumpangFirst(LP, createPenumpang(id, n));
    }
    else if (m == 2) {
        string id, n;
        cout << "Masukkan id dan nama penumpang: ";
        cin >> id >> n;
        insertPenumpangLast(LP, createPenumpang(id, n));
    }
    else if (m == 3) {
    int d;
    cout << "\n1. Hapus Penumpang Pertama\n2. Hapus Penumpang Terakhir\nPilih: ";
    cin >> d;

    if (d == 1) {
        deletePenumpangFirst(LP);
    } else if (d == 2) {
        deletePenumpangLast(LP);
    }
    }
    else if (m == 4) {
        tampilPenumpang(LP);
    }
    else if (m == 5) {
        penumpangRelasiTerbanyak(LO, LP);
    }
    else if (m == 6) {
        string id;
        cout << "Masukkan id Penumpang: ";
        cin >> id;
        adrPenumpang C = searchPenumpang(LP, id);
        if (C != NULL)
            cout << "Penumpang ditemukan: " << C->idPenumpang << " | " << C->nama << endl;
        else
            cout << "Penumpang tidak ditemukan\n";
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
