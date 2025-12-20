#include "Apk.h"


void createListOjol(ListOjol &L){
  L.first = NULL;
}

adrOjol createOjol(string id, string nama) {
  adrOjol P = new Ojol;
  P->idOjol = id;
  P->nama = nama;
  P->next = NULL;
  P->relasiHead = NULL;
  return P;
}


void insertOjolFirst(ListOjol &L, adrOjol P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertOjolLast(ListOjol &L, adrOjol P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        adrOjol Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}


adrOjol searchOjol(ListOjol L, string id){
adrOjol P = L.first;
while(P != NULL && P->idOjol != id){
  P = P->next;
}
return P;
}

void deleteOjolFirst(ListOjol &L) {
    if (L.first == NULL) {
        return; // list kosong
    }

    adrOjol P = L.first;
    L.first = P->next;
    P->next = NULL;
    delete P;
}

void deleteOjolLast(ListOjol &L) {
    if (L.first == NULL) {
        return; // list kosong
    }

    if (L.first->next == NULL) {
        // apus 1 saja
        delete L.first;
        L.first = NULL;
    } else {
        adrOjol Q = L.first;
        while (Q->next->next != NULL) {
            Q = Q->next;
        }
        delete Q->next;
        Q->next = NULL;
    }
}

void tampilOjol(ListOjol L){
  cout << "\nDaftar Ojol:\n";
  adrOjol P = L.first;
  while(P != NULL){
      cout << "- " << P->idOjol << " | " << P->nama << endl;
      P = P->next;
  }
}

void driverTergiat(ListOjol L) {
    adrOjol P = L.first;
    adrOjol maxOjol = NULL;
    int maxRelasi = 0;

    while (P != NULL) {
        int count = 0;
        Relasi *R = P->relasiHead;

        while (R != NULL) {
            count++;
            R = R->next;
        }

        if (count > maxRelasi) {
            maxRelasi = count;
            maxOjol = P;
        }
        P = P->next;
    }

    if (maxOjol != NULL) {
        cout << "Driver Tergiat:\n";
        cout << "ID   : " << maxOjol->idOjol << endl;
        cout << "Nama : " << maxOjol->nama << endl;
        cout << "Jumlah Penumpang: " << maxRelasi << endl;
    } else {
        cout << "Data ojol kosong.\n";
    }
}
