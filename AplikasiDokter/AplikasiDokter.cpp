#include <iostream>
#include "AplikasiDokter.h"

// Procedure untuk mengecek list kosong
bool isEmptyDokter(listDokter lDokter){
    /*
        I.S Masukkan sebuah list Dokter
        F.S Mengeluarkan true apabila list kosong
    */

    return first(lDokter) == nullptr;
}

bool isEmptyPasien(listPasien lPasien){
    /*
        I.S Masukkan sebuah list Pasien
        F.S Mengeluarkan true apabila list kosong
    */

    return first(lPasien) == nullptr;
}


bool isEmptyRelasi(listRelasi lRelasi){
    /*
        I.S Masukkan sebuah list Relasi
        F.S Mengeluarkan true apabila list kosong
    */

    return first(lRelasi) == nullptr;
}


// Procedure untuk membuat list
void createListDokter(listDokter &lDokter){
    /*
        I.S Masukkan sebuah variable yang akan dijadikan list
        F.S variable sudah menjadi list
    */

    first(lDokter) = nullptr;
    last(lDokter) = nullptr;
}

void createListPasien(listPasien &lPasien){
    /*
        I.S Masukkan sebuah variable yang akan dijadikan list
        F.S variable sudah menjadi list
    */

    first(lPasien) = nullptr;
}

void createListRelasi(listRelasi &lRelasi){
     /*
        I.S Masukkan sebuah variable yang akan dijadikan list
        F.S variable sudah menjadi list
    */

    first(lRelasi) = nullptr;
}

// Function untuk membuat element
adrDokter createNewElementDokter(infoDokter data){
    /*
        I.S Masukkan sebuah variable yang berisi info mengenai identitas dokter
        F.S Mengembalikan elemen yang berisi info dokter
    */

    adrDokter newElement = new elmtListDokter;

    info(newElement) = data;
    next(newElement) = nullptr;
    prev(newElement) = nullptr;
    relasi(newElement) = nullptr;

    return newElement;
}

adrPasien createNewElementPasien(infoPasien data){
     /*
        I.S Masukkan sebuah variable yang berisi info mengenai identitas pasien
        F.S Mengembalikan elemen yang berisi info pasien
    */

    adrPasien newElement = new elmtListPasien;

    info(newElement) = data;
    next(newElement) = nullptr;
    relasi(newElement) = nullptr;

    return newElement;
}

adrRelasi createNewElementRelasi(){
    /*
        I.S
        F.S Mengembalikan elemen relasi
    */

    adrRelasi newElement = new elmtListRelasi;

    next(newElement) = nullptr;
    dokter(newElement) = nullptr;
    pasien(newElement) = nullptr;

    return newElement;

}

// Procedure insert Element Dokter
void insertFirstDokter(listDokter &lDokter, adrDokter aDokter){}
void insertLastDokter(listDokter &lDokter, adrDokter aDokter);
void insertAfterDokter(listDokter &lDokter, adrDokter prec, adrDokter aDokter);

// Procedure insert Element Pasien
void insertFirstPasien(listPasien &lPasien, adrPasien aPasien);
void insertLastPasien(listPasien &lPasien, adrPasien aPasien);
void insertAfterPasien(listPasien &lPasien, adrPasien prec, adrPasien aPasien);

// Procedure insert Element Relasi
void insertFirstRelasi(listRelasi &lRelasi, adrRelasi aRelasi);
void insertLastRelasi(listRelasi &lRelasi, adrRelasi aRelasi);
void insertAfterRelasi(listRelasi &lRelasi, adrRelasi prec, adrRelasi aRelasi);

// Procedure delete Element Dokter
void deleteFirstDokter(listDokter &lDokter, adrDokter aDokter){
    /*
        I.S Terdefinisi lisr dokter yang mungkin kosong
        F.S Elemen Pertama dalam list dokter terhapus
    */

     if (isEmptyDokter(lDokter)){
        cout << "List Kosong" << endl;
     } else {
        if (next(first(lDokter)) == nullptr){
            aDokter = first(lDokter);
            first(lDokter) = nullptr;
        } else {
            aDokter = first(lDokter);
            first(lDokter) = next(aDokter);
            next(aDokter) = nullptr;
        }
     }
}

void deleteLastDokter(listDokter &lDokter, adrDokter aDokter){
    /*
        I.S Terdefinisi list dokter yang mungkin Kosong
        F.S Elemen Terakhir dalam list dokter terhapus
    */
    adrDokter last = first(lDokter);

    if(isEmptyDokter(lDokter)){
        cout << "List Kosong" << endl;
    } else {
        if(next(first(lDokter)) = nullptr){
            aDokter = first(lDokter);
            first(lDokter) = nullptr;
        } else {
            while(next(next(last))!= nullptr){
                last = next(last);
            }
            aDokter = next(last);
            next(last) = nullptr;
        }
    }
}
void deleteAfterDokter(listDokter &lDokter, adrDokter prec, adrDokter aDokter);

// Procedure delete Element Pasien
void deleteFirstPasien(listPasien &lPasien, adrPasien aPasien);
void deleteLastPasien(listPasien &lPasien, adrPasien aPasien);
void deleteAfterPasien(listPasien &lPasien, adrPasien prec, adrPasien aPasien);

// Procedure delete Element Relasi
void deleteFirstRelasi(listRelasi &lRelasi, adrRelasi aRelasi);
void deleteLastRelasi(listRelasi &lRelasi, adrRelasi aRelasi);
void deleteAfterRelasi(listRelasi &lRelasi, adrRelasi prec, adrRelasi aRelasi);

// Function melakukan searching element data
adrDokter searchElementDokter(listDokter lDokter, string namaDokter);
adrPasien searchElementPasien(listPasien lPasien, string namaPasien);

// Procedure insert data
void insertDataDokter(listDokter &lDokter);
void insertDataPasien(listPasien &lPasien);

// Procedure penghubungan list Dokter dengan list Pasien
void relationBrige(listDokter &lDokter, listPasien &lPasien, listRelasi &lRelasi);

// Procedure show data list
void showDataPasien(listPasien lPasien);
void showDataDokter(listDokter lDokter);

// Procedure untuk Menu
void mainMenu();

