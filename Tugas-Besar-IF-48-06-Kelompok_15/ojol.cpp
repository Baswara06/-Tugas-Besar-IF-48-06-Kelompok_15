#include "ojol.h"
#include <iostream>
using namespace std;

void createListOjol(elemenOjol &L) {
    L.first = nullptr;
    L.last = nullptr;
}

adrOjol newOjol(string id, string nama) {
    adrOjol P
    p = new ojol;
    P->id = id;
    P->nama = nama;
    P->prev = nullptr;
    P->next = nullptr;
    return P;
}

void insertFirstOjol(elemenOjol &L, adrOjol P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void inserLastOjol(elemenOjol &L, adrOjol P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void deleteFirstOjol(elemenOjol &L, adrOjol &P) {
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

void deleteLastOjol(elemenOjol &L, adrOjol &P) {
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

void deleteByIdOjol(elemenOjol &L, string id) {
    adrOjol P = findPenumpang(L, id);
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

adrPenumpang findOjol(elemenOjol L, string id) {
    adrOjol P = L.first;
    while (P != nullptr) {
        if (P->id == id) return P;
        P = P->next;
    }
    return nullptr;
}

void showOjol(elemenOjol L) {
    adrOjol P = L.first;
    while (P != nullptr) {
        cout << "ID: " << P->id << " | Nama: " << P->nama << endl;
        P = P->next;
    }
}


