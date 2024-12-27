#ifndef APLIKASIDOKTER_H_INCLUDED
#define APLIKASIDOKTER_H_INCLUDED

#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define dokter(P) P->dokter
#define pasien(P) P->pasien

#define first(L) ((L).first)
#define last(L) ((L).last)

using namespace std;

// define struct info pada list Dokter dan Pasien
typedef struct infoDokter infotypeDokter;
typedef struct infoPasien infotypePasien;

// define elementList menjadi address
typedef struct elmtListDokter *adrDokter;
typedef struct elmtListPasien *adrPasien;
typedef struct elmtListRelasi *adrRelasi;

// struct infoDokter
struct infoDokter{
    int NIP;
    string namaDokter;
    string jenisKelamin;
    string spesialisDokter;
};

// struct infoPasien
struct infoPasien{
    int noAntrian;
    int umurPasien;
    string namaPasien;
    string jenisKelamin;
    string jenisPenyakit;
    string dokterTujuan;
};

// struct element List Dokter
struct elmtListDokter{
    infoDokter info;
    adrDokter prev;
    adrDokter next;
};

// struct element List Pasien
struct elmtListPasien{
    infoPasien info;
    adrPasien next;
};

// struct element List Relasi
struct elmtListRelasi{
    adrRelasi next;
    adrPasien pasien;
    adrDokter dokter;
};

// struct List Dokter
struct listDokter{
    adrDokter first;
    adrDokter last;
};

// struct List Pasien
struct listPasien{
    adrPasien first;
};

// struct List Relasi
struct listRelasi{
    adrRelasi first;
};

// Procedure untuk mengecek list kosong
bool isEmptyDokter(listDokter lDokter);
bool isEmptyPasien(listPasien lPasien);
bool isEmptyRelasi(listRelasi lRelasi);

// Procedure untuk membuat list
void createListDokter(listDokter &lDokter);
void createListPasien(listPasien &lPasien);
void createListRelasi(listRelasi &lRelasi);

// Function untuk membuat element
adrDokter createNewElementDokter(infoDokter data);
adrPasien createNewElementPasien(infoPasien data);
adrRelasi createNewElementRelasi();

// Procedure insert Element Dokter
void insertFirstDokter(listDokter &lDokter, adrDokter aDokter);
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
void deleteFirstDokter(listDokter &lDokter, adrDokter aDokter);
void deleteLastDokter(listDokter &lDokter, adrDokter aDokter);
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

void showDetailDataDokter(listDokter lDokter, listRelasi lRelasi, string namaDokter);
void showDetailDataPasien(listPasien lPasien, string namaPasien);
void showAllData(listDokter lDokter, listPasien lPasien, listRelasi lRelasi);

// Procedure searching data
void searchDataDokter(listDokter lDokter, listRelasi lRelasi);
void searchDataPasien(listPasien lPasien);

// Function untuk menghitung data
int dokterCounter(listDokter lDokter);
int pasienCounter(listPasien lPasien);
int countPasienFromDokter(listDokter lDokter, listPasien lPasien, listRelasi lRelasi);

// Procedure untuk Menu
void mainMenu();
#endif // APLIKASIDOKTER_H_INCLUDED
