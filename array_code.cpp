#include <iostream>
#include <string>
using namespace std;

void garis(){
    cout << string(40,'=') << endl;
}

void masukanAngka(int angka[],int n){
    for(int i = 0; i < n; i++){
        cout << i + 1 << ". Masukan angka: ";
        cin >> angka[i];
    }
}

void sebelum(int angka[], int n){
    garis();
    cout << "SEBELUM DI SORTING" << endl;
    garis();
    for(int i = 0; i < n; i++){
        cout << "Array ke-" << i + 1 << " : " << angka[i] << endl;
    }
    garis();
}

void bubbleSort(int angka[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(angka[j] > angka[j + 1]){
                int temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }
}

void sesudah(int angka[], int n){
    garis();
    cout << "SESUDAH DI SORTING" << endl;
    garis();
    for(int i = 0; i < n; i++){
        cout << "Array ke-" << i + 1 << " : " << angka[i] << endl;
    }
    garis();
}

int binarySearch(int angka[], int n, int cari){
    int kiri = 0;
    int kanan = n - 1;

    while(kiri <= kanan){
        int tengah = (kiri + kanan) / 2;

        if(angka[tengah] == cari){
            return tengah;
        } else if(angka[tengah] > cari){
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }
    return -1;
}

int main(){
    int n;
    garis();
    cout << "PROGRAM ARRAY" << endl;
    garis();
    cout << "Masukan jumlah elemen: ";
    cin >> n;

    int* angka = new int[n];

    garis();
    cout << endl;
    garis();
    cout << "INPUT ANGKA" << endl;
    garis();
    masukanAngka(angka,n);
    garis();
    cout << endl;
    sebelum(angka,n);
    bubbleSort(angka,n);
    cout << endl;
    sesudah(angka,n);
    cout << endl;

    int cari;

    garis();
    cout << "CARI ARRAY" << endl;
    garis();
    cout << "Masukan angka yang ingin dicari: ";
    cin >> cari;
    garis();

    int hasil = binarySearch(angka,n,cari);

    if(hasil != -1){
        cout << "Angka ditemuka di index ke-" << hasil << endl;
    } else {
        cout << "Angka tidak ditemukan" << endl;
    }
    garis();

    delete[] angka;
    return 0;
}