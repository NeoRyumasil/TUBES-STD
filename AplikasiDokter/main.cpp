#include <iostream>
#include "AplikasiDokter.h"

using namespace std;

int main()
{
    listDokter lDokter;
    listPasien lPasien;
    listRelasi lRelasi;
    string namaDokter;
    int select;

    createListDokter(lDokter);
    createListPasien(lPasien);
    createListRelasi(lRelasi);

    start:
         cout << "===============================================================" << endl;
         cout << "                   APLIKASI PASIEN DAN DOKTER                  " << endl;
         cout << "===============================================================" << endl;
         cout << "Total Dokter: " << dokterCounter(lDokter) << endl;
         cout << "Total Pasien: " << pasienCounter(lPasien) << endl;
         select = mainMenu();

        switch(select){
        case 1:
            insertDataDokter(lDokter);
            break;
        case 2:
            insertDataPasien(lPasien, lDokter, lRelasi);
            break;
        case 3:
            showDataDokter(lDokter);
            break;
        case 4:
            showDataPasien(lPasien);
            break;
        case 5:
            searchDataDokter(lDokter, lRelasi);
            break;
        case 6:
            searchDataPasien(lPasien);
            break;
        case 7:
            deleteDokter(lDokter, lRelasi, lPasien);
            break;
        case 8:
            deletePasien(lPasien, lRelasi);
            break;
        case 9:
            showAllData(lDokter, lPasien, lRelasi);
            break;
        }

        if (select > 0 && choice <= 9){
           goto start;
        }
}

