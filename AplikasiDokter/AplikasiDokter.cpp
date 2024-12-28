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
void insertFirstDokter(listDokter &lDokter, adrDokter aDokter) {
    /*
        I.S Terdapat list Dokter yang mungkin kosong dan elemen dokter yang dimasukkan
        F.S Element dokter dimasukkan ke bagian pertama dalam list dokter
    */
    if(isEmptyDokter(lDokter)) {
        first(lDokter) = aDokter;
        last(lDokter) = aDokter;
    } else {
        next(aDokter) = first(lDokter);
        prev(first(lDokter)) = aDokter;
        first(lDokter) = aDokter;
    }
}

void insertLastDokter(listDokter &lDokter, adrDokter aDokter) {
    /*
        I.S Terdapat list Dokter yang mungkin kosong dan elemen dokter yang dimasukkan
        F.S Element dokter dimasukkan ke bagian terakhir dalam list dokter
    */
    if (isEmptyDokter(lDokter)) {
        first(lDokter) = aDokter;
        last(lDokter) = aDokter;
    } else {
        prev(aDokter) = last(lDokter);
        next(last(lDokter)) = aDokter;
        last(lDokter) = aDokter;
    }
}

void insertAfterDokter(listDokter &lDokter, adrDokter prec, adrDokter aDokter) {
    /*
        I.S Terdapat list Dokter yang akan diisi sebuah elemen
        F.S Element dokter dimasukkan ke bagian yang ditentukan dalam list
    */
    if (isEmptyDokter(lDokter)) {
        cout << "Error, List kosong!" << endl;
    } else if (prec == last(lDokter)) {
        insertLastDokter(lDokter, aDokter);
    } else {
        next(aDokter) = next(prec);
        prev(aDokter) = prec;
        prev(next(prec)) = aDokter;
        next(prec) = aDokter;
    }
}

// Procedure insert Element Pasien
void insertFirstPasien(listPasien &lPasien, adrPasien aPasien) {
    /*
        I.S Terdapat list Pasien yang mungkin kosong dan elemen Pasien yang dimasukkan
        F.S Element Pasien dimasukkan ke bagian pertama dalam list Pasien
    */
    if(isEmptyPasien(lPasien)) {
        first(lPasien) = aPasien;
    } else {
        next(aPasien) = first(lPasien);
        first(lPasien) = aPasien;
    }
}

void insertLastPasien(listPasien &lPasien, adrPasien aPasien) {
    /*
        I.S Terdapat list Pasien yang mungkin kosong dan elemen Pasien yang dimasukkan
        F.S Element Pasien dimasukkan ke bagian terakhir dalam list Pasien
    */
    adrPasien q = first(lPasien);
    if (q == nullptr) {
        first(lPasien) = aPasien;
    } else {
        while (next(q) != nullptr) {
            q = next(q);
        }
        next(q) = aPasien;
    }
}
void insertAfterPasien(listPasien &lPasien, adrPasien prec, adrPasien aPasien) {
    /*
        I.S Terdapat list Pasien yang akan diisi sebuah elemen
        F.S Element Pasien dimasukkan ke bagian yang ditentukan dalam list
    */
    if (prec == nullptr) {
        cout << "Maaf, prec tidak ditemukan" << endl;
    } else {
        next(aPasien) = next(prec);
        next(prec) = aPasien;
    }
}

// Procedure insert Element Relasi
void insertFirstRelasi(listRelasi &lRelasi, adrRelasi aRelasi) {
    /*
        I.S Terdapat list Relasi yang mungkin kosong dan elemen relasi yang dimasukkan
        F.S Element Relasi dimasukkan ke bagian pertama dalam list relasi
    */
    if(isEmptyRelasi(lRelasi)) {
        first(lRelasi) = aRelasi;
    } else {
        next(aRelasi) = first(lRelasi);
        first(lRelasi) = aRelasi;
    }
}

void insertLastRelasi(listRelasi &lRelasi, adrRelasi aRelasi) {
     /*
        I.S Terdapat list Relasi yang mungkin kosong dan elemen relasi  yang dimasukkan
        F.S Element Relasi dimasukkan ke bagian terakhir dalam list relasi
    */
    adrRelasi r = first(lRelasi);
    if (r == nullptr) {
        first(lRelasi) = aRelasi;
    } else {
        while (next(r) != nullptr) {
            r = next(r);
        }
        next(r) = aRelasi;
    }
}
void insertAfterRelasi(listRelasi &lRelasi, adrRelasi prec, adrRelasi aRelasi) {
    /*
        I.S Terdapat list Relasi yang akan diisi sebuah elemen
        F.S Element Relasi dimasukkan ke bagian yang ditentukan dalam list
    */
    if (prec == nullptr) {
        cout << "Maaf, prec tidak ditemukan" << endl;
    } else {
        next(aRelasi) = next(prec);
        next(prec) = aRelasi;
    }
}


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
void insertDataDokter(listDokter &lDokter){
    /*
        I.S Data dokter belum dimasukkan
        F.S Data dokter dimasukkan dalam jumlah tertentu
    */

    int totalDokter = 0;
    infoDokter dataDokter;
    adrDokter newDokter;
    adrDokter explorer = first(lDokter);

    cout << "=======================================================================" << endl;
    cout << "Masukkan Total Dokter : ";
    cin >> totalDokter;
    cout << "=======================================================================" << endl;
    for (int i = 0; i < totalDokter; i++){
        cout << "NIP Dokter: ";
        cin >> dataDokter.NIP;
        cout << "Nama Dokter: ";
        cin >> dataDokter.namaDokter;
        cout << "Jenis Kelamin: ";
        cin >> dataDokter.jenisKelamin;
        cout << "Spesialisasi Dokter: ";
        cin >> dataDokter.spesialisDokter;

        newDokter = createNewElementDokter(dataDokter);

        // Melakukan insert elemen ke dalam list Dokter secara ascending diurutkan melalui NIP

        while (explorer != nullptr && info(explorer).NIP > info(newDokter).NIP){
            explorer = next(explorer);
        }

        if (explorer == first(lDokter)){
            insertFirstDokter(lDokter, newDokter);
        } else if (explorer == nullptr){
            insertLastDokter(lDokter, newDokter);
        } else {
            insertAfterDokter(lDokter, explorer, newDokter);
        }
    }
}


void insertDataPasien(listPasien &lPasien){
    /*
        I.S Data Pasien belum dimasukkan
        F.S Data Pasien dimasukkan
    */

    infoPasien dataPasien;
    adrPasien newPasien;
    adrPasien explorer = first(lPasien);

     cout << "=======================================================================" << endl;
     cout << "No Antrian: ";
     cin >> dataPasien.noAntrian;
     cout << "Nama Pasien: ";
     cin >> dataPasien.namaPasien;
     cout << "Umur Pasien: ";
     cin >> dataPasien.umurPasien;
     cout << "Jenis Kelamin: ";
     cin >> dataPasien.jenisKelamin;
     cout << "Jenis Penyakit: ";
     cin >> dataPasien.jenisPenyakit;
     cout << "Dokter yang dituju: ";
     cin >> dataPasien.dokterTujuan;

     newPasien = createNewElementPasien(dataPasien);

     // Melakukan insert data pasien secara ascending menurut nomor antrian
     while (explorer != nullptr && info(explorer).noAntrian > info(newPasien).noAntrian){
        explorer = next(explorer);
     }

     if (explorer == first(lPasien)){
        insertFirstPasien(lPasien, newPasien);
     } else if (explorer == nullptr){
        insertLastPasien(lPasien, newPasien);
     } else {
        insertAfterPasien(lPasien, explorer, newPasien);
     }

    relationBrige(lDokter, lPasien, lRelasi, info(newPasien).dokterTujuan, info(newPasien).namaPasien);
}

// Procedure penghubungan list Dokter dengan list Pasien
void relationBrige(listDokter &lDokter, listPasien &lPasien, listRelasi &lRelasi, string namaDokter, string namaPasien){
    adrRelasi newRelasi;
    adrDokter dokterFounder = searchElementDokter(lDokter, namaDokter);
    adrPasien pasienFounder = searchElementPasien(lPasien, namaPasien);

    newRelasi = createNewElementRelasi();
    dokter(newRelasi) = dokterFounder;
    pasien(newRelasi) = pasienFounder;

    insertLastRelasi(lRelasi, newRelasi);
}


void showDataPasien(listPasien lPasien){
    /*
        I.S Terdapat masukkan list Pasien
        F.S Menampilkan data seluruh Pasien
    */

    adrPasien printer = first(lPasien);

    cout << "===================================================================" << endl;

    while (printer != nullptr){
        cout << "Nomor Antrian: " << info(printer).noAntrian << endl;
        cout << "Nama Pasien: " << info(printer).namaPasien << endl;
        cout << "Umur Pasien: " << info(printer).umurPasien << endl;
        cout << "Jenis Kelamin: " << info(printer).jenisKelamin << endl;
        cout << "Jenis Penyakit: " << info(printer).jenisPenyakit << endl;
        cout << "===============================================================" << endl;
        printer = next(printer);
    }
}

void showDataDokter(listDokter lDokter){
    /*
        I.S Terdapat masukkan list Dokter
        F.S Menampilkan data seluruh Dokter
    */

    adrDokter printer = first(lDokter);

    while (printer != nullptr){
        cout << "NIP: " << info(printer).NIP << endl;
        cout << "Nama Dokter: " << info(printer).namaDokter << endl;
        cout << "Jenis Kelamin: " << info(printer).jenisKelamin << endl;
        cout << "Spesialisasi : " << info(printer).spesialisDokter << endl;
        cout << "===============================================================" << endl;
        printer = next(printer);
    }
}

void showDetailDataDokter(listDokter lDokter, listRelasi lRelasi, string namaDokter){
    adrDokter dokterPrinter = searchElementDokter(lDokter, namaDokter);
    adrRelasi bridge = first(lRelasi);

    if (dokterPrinter != nullptr){
        cout << "NIP: " << info(dokterPrinter).NIP << endl;
        cout << "Nama Dokter: " << info(dokterPrinter).namaDokter << endl;
        cout << "Jenis Kelamin: " << info(dokterPrinter).jenisKelamin << endl;
        cout << "Spesialisasi : " << info(dokterPrinter).spesialisDokter << endl;
        cout << "List Pasien yang ditangani : " << endl;

        int listNumber = 0;
        while(bridge != nullptr){
            if (info(pasien(bridge)).dokterTujuan == namaDokter){
                listNumber++;
                cout << listNumber << ". " << info(pasien(bridge)).namaPasien << endl;
            }
            bridge = next(bridge);
        }
    } else {
        cout << "Dokter tidak ditemukan" << endl;
    }
    cout << "===============================================================" << endl;
}

void showDetailDataPasien(listPasien lPasien, string namaPasien){
    adrPasien printer = searchElementPasien(lPasien, namaPasien);

    if (printer != nullptr){
        cout << "Nomor Antrian: " << info(printer).noAntrian << endl;
        cout << "Nama Pasien: " << info(printer).namaPasien << endl;
        cout << "Umur Pasien: " << info(printer).umurPasien << endl;
        cout << "Jenis Kelamin: " << info(printer).jenisKelamin << endl;
        cout << "Jenis Penyakit: " << info(printer).jenisPenyakit << endl;
        cout << "Dokter Tujuan: " << info(printer).dokterTujuan << endl;
    } else {
        cout << "Pasien tidak ditemukan" << endl;
    }

    cout << "===============================================================" << endl;
}

void showAllData(listDokter lDokter, listPasien lPasien, listRelasi lRelasi){
    adrDokter dokterPrinter = first(lDokter);
    adrPasien pasienPrinter = first(lPasien);
    adrRelasi relationPrinter = first(lRelasi);
    int counter = 0;

  cout << "DATA DOKTER" << endl;
    cout << "===============================================================" << endl;
    while(dokterPrinter != nullptr){
        counter++;
        cout << counter << ". ";
        showDetailDataDokter(lDokter,lRelasi,info(dokterPrinter).namaDokter);
        dokterPrinter = next(dokterPrinter);
    }

    counter = 0;
    cout << "DATA PASIEN" << endl;
    cout << "===============================================================" << endl;
    while (pasienPrinter != nullptr){
        counter++;
        cout << counter << ". ";
        showDetailDataPasien(lPasien,info(pasienPrinter).namaPasien);
        pasienPrinter = next(pasienPrinter);
    }
}

// Procedure searching data
void searchDataDokter(listDokter lDokter, listRelasi lRelasi){
    string namaDokter;

    cout << "Masukkan nama Dokter yang ingin dicari: ";
    cin >> namaDokter;

    showDetailDataDokter(lDokter, lRelasi, namaDokter);
}

void searchDataPasien(listPasien lPasien){
    string namaPasien;

    cout << "Masukkan nama Pasien yang ingin dicari: ";
    cin >> namaPasien;

    showDetailDataPasien(lPasien, namaPasien);
}

// Function untuk menghitung data
int dokterCounter(listDokter lDokter){
    adrDokter explorer = first(lDokter);
    int counter = 0;

    while(explorer != nullptr){
        counter++;
        explorer = next(explorer);
    }

    return counter;
}

int pasienCounter(listPasien lPasien){
    adrPasien explorer = first(lPasien);
    int counter = 0;

    while (explorer != nullptr){
        counter++;
        explorer = next(explorer);
    }

    return counter;
}

int countPasienFromDokter(listDokter lDokter, listPasien lPasien, listRelasi lRelasi, string namaDokter){
    adrRelasi explorer = first(lRelasi);
    int counter = 0;

    while(explorer != nullptr){
        if (info(dokter(explorer)).namaDokter == namaDokter){
            if(pasien(explorer) != nullptr){
                counter++;
            }
        }
        explorer = next(explorer);
    }

    return counter;
}

// Procedure Delete Some Data
void deletePasien(listPasien &lPasien, listRelasi &lRelasi);
void deleteDokter(listDokter &lDokter, listRelasi &lRelasi);
void deleteAllPasienFromDokter(listDokter &lDokter, listPasien &lPasien, listRelasi &lRelasi);

// Procedure untuk Menu
int mainMenu(){
    int output;

    cout << "1. Masukkan Data Dokter" << endl;
    cout << "2. Masukkan Data Pasien" << endl;
    cout << "3. Lihat Semua Data Dokter" << endl;
    cout << "4. Lihat Semua Data Pasien" << endl;
    cout << "5. Cari data Dokter" << endl;
    cout << "6. Cari data Pasien" << endl;
    cout << "7. Hapus data dokter" << endl;
    cout << "8. Hapus data pasien" << endl;
    cout << "9. Lihat Semua Data" << endl
    cout << "0. Exit" << endl;
    cout << "===============================================================" << endl;
    cout << "Masukkan Pilihan Menu: ";
    cin >> output;

    return output;

}


