#include <iostream>
#include "AplikasiDokter.h"

using namespace std;

int main()
{
    listDokter lDokter;
    listPasien lPasien;
    listRelasi lRelasi;

    createListDokter(lDokter);
    createListPasien(lPasien);
    createListRelasi(lRelasi);

    insertDataDokter(lDokter);

    for (int i = 0; i < 2; i++){
        insertDataPasien(lPasien, lDokter, lRelasi);
    }

    showDataDokter(lDokter);
    cout << endl;
    showDataPasien(lPasien);
    cout << endl;

    searchDataDokter(lDokter, lRelasi);
    cout << endl;
    searchDataPasien(lPasien);
    cout << endl;

    showAllData(lDokter, lPasien, lRelasi);
}
