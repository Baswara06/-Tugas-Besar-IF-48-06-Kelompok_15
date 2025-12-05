#ifndef PENUMPANG_H_INCLUDED
#define PENUMPANG_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct PenumpangNode *adrPenumpang;

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
