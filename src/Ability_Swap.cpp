#include "header/Ability_Swap.hpp"
#include "header/Poker.hpp"

// Untuk sementara ini parameter aku ganti ke Poker dulu soalnya yg Game blm beres implementasinya
void Swap::useAbility(const Poker& poker) {
    if (!this->getStatus()) {
        cout << "Oops, kartu ability swapmu telah dimatikan sebelumnya :(" << endl
             << "Silahkan lakukan perintah lain.";
    }
    else {
        int jumlahPemain; // Ini harusnya dapetnya dari poker.players.size(), tapi players nya protected
        int pemain1, pemain2;
        int kartuTerpilihPemain1, kartuTerpilihPemain2;

        try {
            cout << "Silahkan pilih pemain yang kartunya ingin anda tukar: " << endl;
            for (int i = 1; i < jumlahPemain; i++) {
                // if poker.players[i] != pemain yang panggil command ini: 
                    cout << i << ". <nama_pemain_ke-i>" << endl;
            }
            
            cout << "< " << endl;
            cin >> pemain1;

            cout << "Silahkan pilih pemain lain yang kartunya ingin anda tukar: " << endl;
            for (int i = 1; i < jumlahPemain; i++) {
                // if poker.players[i] != pemain yang panggil command ini &&
                // i != pemain 1: 
                    cout << i << ". <nama_pemain_ke-i>" << endl;
            }

            cout << "Silakan pilih kartu kanan/kiri <nama_pemain_1>" << endl;
            cout << "1. Kanan \n2. Kiri" << endl;
            cin >> kartuTerpilihPemain1;
            cout << "Silakan pilih kartu kanan/kiri <nama_pemain_2>" << endl;
            cout << "1. Kanan \n2. Kiri" << endl;
            cin >> kartuTerpilihPemain2;

            // Swap kartu pemain_1 dengan pemain_2
        }

        catch(...) {
            cout << "Masukan tidak valid" << endl;
        } 
    }
}

void Swap::printCard() {
    cout << "Nama : " << "Swap" << endl;
    cout << "Status : ";
    this->getStatus() ? cout << "Belum digunakan" : cout << "Sudah digunakan";
    cout << endl;
    cout << "Info : Jika kamu memakai Ability Card ini, kamu bisa memilih dua pemain" << endl
         <<  "yang akan menukarkan masing-masing satu kartu secara acak" << endl; 
}