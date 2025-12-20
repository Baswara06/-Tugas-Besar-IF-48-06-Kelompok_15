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


void insertPenumpang(ListPenumpang &L, adrPenumpang C){
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


void deletePenumpang(ListPenumpang &L, string id){
    adrPenumpang C = searchPenumpang(L, id);
    if (C == NULL) {
        return;
    }
    if (C == L.first) {
        L.first = C->next;
        if (L.first != NULL) {
            L.first->prev = NULL;
        }
    }else {
        C->prev->next = C->next;
        if (C->next != NULL) {
            C->next->prev = C->prev;
        }
    }
    C->next = NULL;
    C->prev = NULL;
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
