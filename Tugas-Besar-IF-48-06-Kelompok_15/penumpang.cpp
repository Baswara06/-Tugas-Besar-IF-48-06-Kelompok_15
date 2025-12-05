#include "penumpang.h"

void createListPenumpang(ListPenumpang &L) {
    L.first = nullptr;
    L.last = nullptr;
}

adrPenumpang newPenumpang(string id, string nama) {
    adrPenumpang P = new PenumpangNode;
    P->id = id;
    P->nama = nama;
    P->prev = nullptr;
    P->next = nullptr;
    return P;
}

void insertFirstPenumpang(ListPenumpang &L, adrPenumpang P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastPenumpang(ListPenumpang &L, adrPenumpang P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void deleteFirstPenumpang(ListPenumpang &L, adrPenumpang &P) {
    if (L.first == nullptr) {
        P = nullptr;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        P = L.first;
        L.first = L.first->next;
        L.first->prev = nullptr;
        P->next = nullptr;
    }
}

void deleteLastPenumpang(ListPenumpang &L, adrPenumpang &P) {
    if (L.first == nullptr) {
        P = nullptr;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        P = L.last;
        L.last = L.last->prev;
        L.last->next = nullptr;
        P->prev = nullptr;
    }
}

void deleteByIDPenumpang(ListPenumpang &L, string id) {
    adrPenumpang P = findPenumpang(L, id);
    if (P == nullptr) return;

    if (P == L.first) {
        adrPenumpang temp;
        deleteFirstPenumpang(L, temp);
    } else if (P == L.last) {
        adrPenumpang temp;
        deleteLastPenumpang(L, temp);
    } else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
        P->next = nullptr;
        P->prev = nullptr;
    }
}

adrPenumpang findPenumpang(ListPenumpang L, string id) {
    adrPenumpang P = L.first;
    while (P != nullptr) {
        if (P->id == id) return P;
        P = P->next;
    }
    return nullptr;
}

void showPenumpang(ListPenumpang L) {
    adrPenumpang P = L.first;
    while (P != nullptr) {
        cout << "ID: " << P->id << " | Nama: " << P->nama << endl;
        P = P->next;
    }
}


