#include <iostream>
#include "AplikasiDokter.h"

using namespace std;

int main()
{
    listDokter lDokter;
    listPasien lPasien;
    listRelasi lRelasi;
    string namaDokter;


    createListDokter(lDokter);
    createListPasien(lPasien);
    createListRelasi(lRelasi);

    insertDataDokter(lDokter);
    insertDataPasien(lPasien, lDokter, lRelasi);


    showDataDokter(lDokter);
    cout << endl;
    showDataPasien(lPasien);
    cout << endl;

    searchDataDokter(lDokter, lRelasi);
    cout << endl;
    searchDataPasien(lPasien);
    cout << endl;

    showAllData(lDokter, lPasien, lRelasi);

    cout << "Total Dokter : " << dokterCounter(lDokter) << endl;
    cout << "Total Pasien : " << pasienCounter(lPasien) << endl;

    cout << "Masukkan Nama Dokter: ";
    cin >> namaDokter;
    cout << "Total Pasien dari dokter " << namaDokter << ": " << countPasienFromDokter(lDokter, lPasien, lRelasi, namaDokter);
}

