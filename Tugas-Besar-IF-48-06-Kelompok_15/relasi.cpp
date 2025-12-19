#include "Apk.h"
typedef Relasi* adrRelasi;

Relasi* createRelasi(adrPenumpang C){
    Relasi *R = new Relasi;
    R->penumpang = C;
    R->next = NULL;
    return R;
}

void tambahRelasi(adrOjol P, adrPenumpang C){
    adrRelasi R ;
    adrRelasi X ;
    R = createRelasi(C);

    if(P->relasiHead == NULL){
            P->relasiHead = R;
    }else{
        X = P->relasiHead;
        while(X->next != NULL){
            X = X->next;
        }
        X->next = R;
}
}


void hapusRelasi(adrOjol P, string idPenumpang){
    adrRelasi prec = NULL, R = P->relasiHead;
    while(R != NULL && R->penumpang->idPenumpang != idPenumpang){
    prec = R;
    R = R->next;
}
    if(R != NULL){
        if(prec == NULL){
                P->relasiHead = R->next;
        }else {
            prec->next = R->next;
        }
}
}


void tampilRelasi(adrOjol P){
    cout << "\nRelasi milik " << P->nama << ":\n";
    adrRelasi R = P->relasiHead;
    while(R != NULL){
        cout << "- Penumpang: " << R->penumpang->nama << endl;
        R = R->next;
}
}

