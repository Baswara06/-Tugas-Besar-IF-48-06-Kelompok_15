#include <iostream>
#include "test.h"
using namespace std;

int main() {
    ListPenumpang L;
    createListPenumpang(L);

    int pilihan = -1;
    string id, nama;
    adrPenumpang P;

    while (pilihan != 0) {
        cout << "\n=== MENU PENUMPANG ===\n";
        cout << "1. Tambah Penumpang Diawal \n"; // ini insert first
        cout << "2. Tambah Penumpang Diakhir \n"; // ini insert last
        cout << "3. Hapus Penumpang Pertama\n";
        cout << "4. Hapus Penumpang Terakhir\n";
        cout << "5. Hapus Penumpang berdasarkan ID\n";
        cout << "6. Cari Penumpang\n";
        cout << "7. Tampilkan Semua Penumpang\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {

            cout << "Masukkan ID   : ";
            cin >> id;
            cout << "Masukkan Nama : ";
            cin >> nama;
            P = newPenumpang(id, nama);
            insertFirstPenumpang(L, P);

        } else if (pilihan == 2) {

            cout << "Masukkan ID   : ";
            cin >> id;
            cout << "Masukkan Nama : ";
            cin >> nama;
            P = newPenumpang(id, nama);
            insertLastPenumpang(L, P);

        } else if (pilihan == 3) {

            deleteFirstPenumpang(L, P);
            if (P != nullptr) {
                cout << "Data dihapus: " << P->id << " - " << P->nama << endl;
                delete P;
            } else {
                cout << "List kosong!\n";
            }

        } else if (pilihan == 4) {

            deleteLastPenumpang(L, P);
            if (P != nullptr) {
                cout << "Data dihapus: " << P->id << " - " << P->nama << endl;
                delete P;
            } else {
                cout << "List kosong!\n";
            }

        } else if (pilihan == 5) {

            cout << "Masukkan ID yang ingin dihapus: ";
            cin >> id;
            deleteByIDPenumpang(L, id);
            cout << "Proses delete selesai.\n";

        } else if (pilihan == 6) {

            cout << "Masukkan ID yang dicari: ";
            cin >> id;
            P = findPenumpang(L, id);
            if (P != nullptr) {
                cout << "Ditemukan -> " << P->id << " | " << P->nama << endl;
            } else {
                cout << "Tidak ditemukan.\n";
            }

        } else if (pilihan == 7) {

            cout << "\n=== LIST PENUMPANG ===\n";
            showPenumpang(L);

        } else if (pilihan == 0) {

            cout << "Keluar program...\n";

        } else {

            cout << "Pilihan tidak valid!\n";

        }
    }

    return 0;
}s
