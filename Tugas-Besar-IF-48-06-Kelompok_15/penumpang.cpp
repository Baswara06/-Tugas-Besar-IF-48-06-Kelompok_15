#include "Apk.h"


void createListPenumpang(ListPenumpang &L){
  L.first = NULL;
}


adrPenumpang createPenumpang(string id, string nama){
  adrPenumpang C = new Penumpang;
  C->idPenumpang = id;
  C->nama = nama;
  C->next = NULL;
  C->prev = NULL;
  return C;
}

void insertPenumpangFirst(ListPenumpang &L, adrPenumpang C){
    if (L.first == NULL) {
        L.first = C;
    } else {
        C->next = L.first;
        L.first->prev = C;
        L.first = C;
    }
}

void insertPenumpangLast(ListPenumpang &L, adrPenumpang C){
    if (L.first == NULL) {
        L.first = C;
    } else {
        adrPenumpang Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = C;
        C->prev = Q;
    }
}


adrPenumpang searchPenumpang(ListPenumpang L, string id){
  adrPenumpang C ;
  C = L.first;
  while(C != NULL && C->idPenumpang != id){
    C = C->next;
  }
  return C;
}

void deletePenumpangFirst(ListPenumpang &L) {
    if (L.first == NULL) {
        return;
    }

    adrPenumpang P = L.first;
    L.first = P->next;

    if (L.first != NULL) {
        L.first->prev = NULL;
    }

    P->next = NULL;
    delete P;
}

void deletePenumpangLast(ListPenumpang &L) {
    if (L.first == NULL) {
        return;
    }

    adrPenumpang P = L.first;

    while (P->next != NULL) {
        P = P->next;
    }

    if (P->prev != NULL) {
        P->prev->next = NULL;
    } else {
        L.first = NULL;
    }

    P->prev = NULL;
    delete P;
}

void tampilPenumpang(ListPenumpang L){
  cout << "\nDaftar Penumpang:\n";
  adrPenumpang C ;
  C = L.first;
  while(C != NULL){
    cout << "- " << C->idPenumpang << " | " << C->nama << endl;
    C = C->next;
  }
}

void penumpangRelasiTerbanyak(ListOjol LO, ListPenumpang LP) {
    adrPenumpang C = LP.first;
    adrPenumpang maxPenumpang = NULL;
    int maxRelasi = 0;

    while (C != NULL) {
        int count = 0;
        adrOjol P = LO.first;

        while (P != NULL) {
            Relasi *R = P->relasiHead;
            while (R != NULL) {
                if (R->penumpang == C) {
                    count++;
                }
                R = R->next;
            }
            P = P->next;
        }

        if (count > maxRelasi) {
            maxRelasi = count;
            maxPenumpang = C;
        }
        C = C->next;
    }

    if (maxPenumpang != NULL) {
        cout << "Top Penumpang\n";
        cout << "ID   : " << maxPenumpang->idPenumpang << endl;
        cout << "Nama : " << maxPenumpang->nama << endl;
        cout << "Jumlah Poin: " << maxRelasi << endl;
    } else {
        cout << "Data penumpang kosong.\n";
    }
}
