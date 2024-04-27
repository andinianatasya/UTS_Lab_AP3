#include <iostream>
using namespace std;

int main(){
    string nomor_kartu;                                         //deklarasi variabel nomor kartu adalah string krna memakai length dan substr
    cout << "Masukkan angka kartu: "; cin >> nomor_kartu;       //input angka kartu, disimpan di variabel nomor kartu
    cout << "Nomor kartu anda: " << nomor_kartu << endl;        //output nomor kartu

    int jumlah = 0;                                             //inisialisasi variabel jumlah awal = 0
    int digit2 = 0;                                             //inisialisasi variabel digit2 awal = 0
    for (int i = nomor_kartu.length()-1; i>=0; i--){            //panjang no kartu - 1 brrti dimulai dari nomor paling kanan kartu; perulangan akan terus berjalan selama i lebihbesar sm dgn 0; setiap selesai prulangan i akan dikurang 1 decrement shngga perulngan bergerak ke kiri no kartu
    int digit = nomor_kartu[i] - '0';                           //inisialisasi digit menjadi integer, mengambil nomor kartu,-0 agar hasilnya sesuai/menjadi bil bulat
    
    if (digit2){                                                //jika digit2 true/1 maka
        digit *= 2;                                             //digit dikali 2 untk menggandakan digit ke2 dari kanan
        if (digit > 9){                                         //jk hasil digit yg dikali 2 lebih besar 9 maka
            digit = digit / 10 + digit % 10;                    //akn membuat 2 digit terpisah
        }
    }
    jumlah += digit;                                            //nilai digit ditambahkan ke jumlah
    digit2 =  1 - digit2;                                       //mengubah digit2 menjadi 1/0
    }
    
    if (jumlah % 10 == 0){                                      //jika jumlah mod 10 = 0 maka
        if (nomor_kartu.length() == 16 &&(                      //jika panjang nomor kartu 16 dan
        nomor_kartu.substr(0, 2) == "51" ||                     //2 angka awal kartu angka 51 atau
        nomor_kartu.substr(0, 2) == "52" ||                     //2 angka awal kartu angka 52 atau
        nomor_kartu.substr(0, 2) == "53" ||                     //2 angka awal kartu angka 53 atau
        nomor_kartu.substr(0, 2) == "54" ||                     //2 angka awal kartu angka 54 atau
        nomor_kartu.substr(0, 2) == "55" ))                     //2 angka awal kartu angka 55 maka
        {
            cout << "Tipe kartu anda: MASTERCARD" << endl;      //tipe kartu termasuk MASTERCARD
        } else if ((nomor_kartu.length() == 13 ||               //jika panjang no kartu 13 atau
        nomor_kartu.length() == 16) &&                          //panjang no kartu 16 dan
        nomor_kartu.substr(0, 1) == "4"){                       //1 angka awal kartu adalah angka 4 maka
            cout << "Tipe kartu anda: VISA" << endl;            //tipe kartu termasuk VISA
        } else {                                                //jika nomor kartu tdk termasuk jenis MASTERRCARD/VISA maka
            cout << "Tipe kartu anda: TIDAK DIKETAHUI" << endl; //tipe kartu tidak diketahui
        }
    } else {                                                    //jika jumlah mod 10 != 0 maka
        cout << "Tipe kartu anda: TIDAK VALID" << endl;         //tipe kartu tidak valid
    }

    cout << "Checksum: " << jumlah << endl;                     //menampilkan hasil checksum jumlah

    return 0;
}

