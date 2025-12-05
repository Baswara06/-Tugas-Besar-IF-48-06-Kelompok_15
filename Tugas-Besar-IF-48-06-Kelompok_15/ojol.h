#ifndef OJOL_H_INCLUDED
#define OJOL_H_INCLUDED

using namespace std;

#include <iostream>

using namespace std;

typedef struct elemenOjol *adrOjol;

struct ojol {
    string id;
    string nama;
    adrOjol next;
};

struct elemenOjol {
    ojol info;
    adrOjol next;
};

void createListOjol(elemenOjol &L);
adrOjol newOjol(string id, string nama);
void insertFirstOjol(elemenOjol &L, adrOjol P);
void insertLastOjol(elemenOjol &L, adrOjol P);
void deleteFirstOjol(elemenOjol &L, adrOjol &P);
void deleteLastOjol(elemenOjol &L, adrOjol &P);
void deleteByIdOjol(elemenOjol &L, string id);
adrPenumpang findOjol(elemenOjol L, string id);


#endif // OJOL_H_INCLUDED
