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

// Procedure delete Element Dokter
void deleteFirstDokter(listDokter &lDokter, adrDokter aDokter){
    /*
        I.S Terdefinisi lisr dokter yang mungkin kosong
        F.S Elemen Pertama dalam list dokter terhapus
    */

     if (isEmptyDokter(lDokter)){
        cout << "List Dokter Kosong" << endl;
     } else {
        if (first(lDokter) != last(lDokter)){
            first(lDokter) = next(aDokter);
            next(aDokter) = nullptr;
            prev(first(lDokter)) = nullptr;
        } else {
            first(lDokter) = nullptr;
            last(lDokter) = nullptr;
        }
     }
}

void deleteLastDokter(listDokter &lDokter, adrDokter aDokter){
    /*
        I.S Terdefinisi list dokter yang mungkin Kosong
        F.S Elemen Terakhir dalam list dokter terhapus
    */

    if(isEmptyDokter(lDokter)){
        cout << "List Dokter Kosong" << endl;
    } else {
        if(first(lDokter) != last(lDokter)){
            aDokter = last(lDokter);
            last(lDokter) = prev(last(lDokter));
            prev(aDokter) = nullptr;
            next(last(lDokter)) = nullptr;
        } else {
            first(lDokter) = nullptr;
            last(lDokter) = nullptr;
        }
    }
}

void deleteAfterDokter(listDokter &lDokter, adrDokter prec, adrDokter aDokter){
    /*
        I.S Terdefinisi list dokter yang mungkin kosong dan elemen tertentu sebagai prec
        F.S Next dari elemen prec dalam list dokter akan terhapus
    */

    if(isEmptyDokter(lDokter)){
        cout << "List Dokter Kosong" << endl;
    } else {
        aDokter = next(prec);
        next(prec) = next(aDokter);
        prev(next(aDokter)) = prec;
        prev(aDokter) = nullptr;
        next(aDokter) = nullptr;
    }
}

// Procedure delete Element Pasien
void deleteFirstPasien(listPasien &lPasien, adrPasien aPasien){
    /*
        I.S Terdefinisi lisr Pasien yang mungkin kosong
        F.S Elemen Pertama dalam list pasien terhapus
    */

     if (isEmptyPasien(lPasien)){
        cout << "List Pasien Kosong" << endl;
     } else {
        if (next(first(lPasien)) == nullptr){
            aPasien = first(lPasien);
            first(lPasien) = nullptr;
        } else {
            aPasien = first(lPasien);
            first(lPasien) = next(aPasien);
            next(aPasien) = nullptr;
        }
     }
}

void deleteLastPasien(listPasien &lPasien, adrPasien aPasien){
    /*
        I.S Terdefinisi list Pasien yang mungkin Kosong
        F.S Elemen Terakhir dalam list Pasien terhapus
    */

    adrPasien last = first(lPasien);

    if(isEmptyPasien(lPasien)){
        cout << "List Pasien Kosong" << endl;
    } else {
        if(next(first(lPasien)) = nullptr){
            aPasien = first(lPasien);
            first(lPasien) = nullptr;
        } else {
            while(next(next(last))!= nullptr){
                last = next(last);
            }
            aPasien = next(last);
            next(last) = nullptr;
        }
    }
}

void deleteAfterPasien(listPasien &lPasien, adrPasien prec, adrPasien aPasien){
     /*
        I.S Terdefinisi list pasien yang mungkin kosong dan elemen tertentu sebagai prec
        F.S Next dari elemen prec dalam list pasien akan terhapus
    */

    if(isEmptyPasien(lPasien)){
        cout << "List Pasien Kosong" << endl;
    } else {
        aPasien = next(prec);
        next(prec) = next(aPasien);
        next(aPasien) = nullptr;
    }
}

// Procedure delete Element Relasi
void deleteFirstRelasi(listRelasi &lRelasi, adrRelasi aRelasi){
    /*
        I.S Terdefinisi list Relasi yang mungkin kosong
        F.S Elemen Pertama dalam list relasi terhapus
    */

     if (isEmptyRelasi(lRelasi)){
        cout << "List Relasi Kosong" << endl;
     } else {
        if (next(first(lRelasi)) == nullptr){
            aRelasi = first(lRelasi);
            first(lRelasi) = nullptr;
        } else {
            aRelasi = first(lRelasi);
            first(lRelasi) = next(aRelasi);
            next(aRelasi) = nullptr;
        }
     }
}

void deleteLastRelasi(listRelasi &lRelasi, adrRelasi aRelasi){
    /*
        I.S Terdefinisi list Relasi yang mungkin Kosong
        F.S Elemen Terakhir dalam list Relasi terhapus
    */

    adrRelasi last = first(lRelasi);

    if(isEmptyRelasi(lRelasi)){
        cout << "List Relasi Kosong" << endl;
    } else {
        if(next(first(lRelasi)) = nullptr){
            aRelasi = first(lRelasi);
            first(lRelasi) = nullptr;
        } else {
            while(next(next(last))!= nullptr){
                last = next(last);
            }
            aRelasi = next(last);
            next(last) = nullptr;
        }
    }
}

void deleteAfterRelasi(listRelasi &lRelasi, adrRelasi prec, adrRelasi aRelasi){
    /*
        I.S Terdefinisi list Relasi yang mungkin kosong dan elemen tertentu sebagai prec
        F.S Next dari elemen prec dalam list Relasi akan terhapus
    */

    if(isEmptyRelasi(lRelasi)){
        cout << "List Relasi Kosong" << endl;
    } else {
        aRelasi = next(prec);
        next(prec) = next(aRelasi);
        next(aRelasi) = nullptr;
    }
}

// Function melakukan searching element data
adrDokter searchElementDokter(listDokter lDokter, string namaDokter){
    /*
        I.S Terdefinisi list dokter yang mungkin kosong, dan nama dokter yang akan dicari
        F.S Mengembalikan address yang berisi informasi tentang dokter yang dicari
    */

    // Pencarian menggunakan penelusuran mundur
    adrDokter searcher = last(lDokter);

    while(info(searcher).namaDokter != namaDokter && searcher != nullptr){
        searcher = prev(searcher);
    }

    return searcher;
}

adrPasien searchElementPasien(listPasien lPasien, string namaPasien){
    /*
        I.S Terdefinisi list Pasien yang mungkin kosong dan nama pasien yang akan dicari
        F.S Mengembalikan address yang berisi informasi tentang pasien yang dicari
    */

    adrPasien searcher = first(lPasien);

    while(info(searcher).namaPasien != namaPasien && searcher != nullptr){
        searcher = next(searcher);
    }

    return searcher;
}

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

