#include "Apk.h"

using namespace std;

// ================= MAIN MENU =================
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

// ================= MENU ADMIN =================
void menuAdmin(ListOjol LO, ListPenumpang LP) {
    cout << "\n=== MENU ADMIN ===\n";
    tampilOjol(LO);
    tampilPenumpang(LP);


    cout << "\nTekan apa saja untuk kembali...";
    cin.ignore();
    cin.get();
}

// ================= MENU STUDI KASUS =================
void menuStudiKasus(ListOjol &LO, ListPenumpang &LP) {
    int menu = -1;
    while (menu != 0) {
        cout << "\n=== MENU STUDI KASUS ===\n";
        cout << "1. Menu Ojol\n";
        cout << "2. Menu Penumpang\n";
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

    }
    }
}

