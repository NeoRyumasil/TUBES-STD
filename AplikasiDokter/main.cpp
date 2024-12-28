#include <iostream>
#include "AplikasiDokter.h"

using namespace std;

int main()
{
    listDokter lDokter;
    listPasien lPasien;
    listRelasi lRelasi;
    string namaDokter;
    int choice;

    createListDokter(lDokter);
    createListPasien(lPasien);
    createListRelasi(lRelasi);

    start:
         cout << "===============================================================" << endl;
         cout << "                   APLIKASI PASIEN DAN DOKTER                  " << endl;
         cout << "===============================================================" << endl;
         cout << "Total Dokter: " << dokterCounter(lDokter) << endl;
         cout << "Total Pasien: " << pasienCounter(lPasien) << endl;
         choice = mainMenu();

}

