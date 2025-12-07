#ifndef PENUMPANG_H_INCLUDED
#define PENUMPANG_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct PenumpangNode *adrPenumpang;
typedef struct elemenOjol *adrOjol;

struct PenumpangNode {
    string id;
    string nama;
    adrPenumpang prev;
    adrPenumpang next;
};

struct ListPenumpang {
    adrPenumpang first;
    adrPenumpang last;
};

struct ojol {
    string id;
    string nama;
    adrOjol next;
};

struct elemenOjol {
    ojol info;
    adrOjol next;
};

// ojol
void createListOjol(elemenOjol &L);
adrOjol newOjol(string id, string nama);
void insertFirstOjol(elemenOjol &L, adrOjol P);
void insertLastOjol(elemenOjol &L, adrOjol P);
void deleteFirstOjol(elemenOjol &L, adrOjol &P);
void deleteLastOjol(elemenOjol &L, adrOjol &P);
void deleteByIdOjol(elemenOjol &L, string id);
adrPenumpang findOjol(elemenOjol L, string id);

// penumpang
void createListPenumpang(ListPenumpang &L);
adrPenumpang newPenumpang(string id, string nama);
void insertFirstPenumpang(ListPenumpang &L, adrPenumpang P);
void insertLastPenumpang(ListPenumpang &L, adrPenumpang P);
void deleteFirstPenumpang(ListPenumpang &L, adrPenumpang &P);
void deleteLastPenumpang(ListPenumpang &L, adrPenumpang &P);
void deleteByIDPenumpang(ListPenumpang &L, string id);
adrPenumpang findPenumpang(ListPenumpang L, string id);
void showPenumpang(ListPenumpang L);


#endif // PENUMPANG_H_INCLUDED
