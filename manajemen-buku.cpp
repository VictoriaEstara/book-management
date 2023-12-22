#include <algorithm> // Lib untuk algoritma
#include <iostream>  // Lib untuk memberikan akses ke berbagai fungsi
#include <iomanip>	 // Lib untuk memanipulasi letak interface
#include <string>	 // Lib untuk memberikan akses ke pemrosesan string
#include <vector>	 // Lib untuk mengatur struktur data sejumlah elemen
#include <limits>	 // Lib untuk memvalidasi input dan tipe input

using namespace std;

// Struktur data untuk merepresentasikan informasi buku
struct Buku {
    string judul;
    string pengarang;
    int tahun;
    double harga;
    string genre;
};

// Prototipe fungsi
void tambahBuku(vector<Buku> &persediaan);
void cariBuku(const vector<Buku> &persediaan);
void editBuku(vector<Buku> &persediaan);
void tampilkanPersediaan(const vector<Buku> &persediaan);
void urutkanBuku(vector<Buku> &persediaan);

int main() {
    // Vektor untuk menyimpan buku-buku dalam persediaan
    vector<Buku> persediaan;

    // Variabel untuk menyimpan pilihan pengguna
    int pilihan;

    // Loop utama program
    do {
        // Menampilkan menu utama
        cout << "\nDeFajar-Inventory Book\n";
        cout << "1. Menambahkan Buku Baru\n";
        cout << "2. Mencari Buku\n";
        cout << "3. Mengedit Buku\n";
        cout << "4. Menampilkan Persediaan Buku\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan Anda (1-5): ";
        
        // Menerima input pilihan pengguna
        cin >> pilihan;

        // Switch untuk menangani pilihan pengguna
        switch (pilihan) {
            case 1:
                tambahBuku(persediaan);
                break;
            case 2:
                cariBuku(persediaan);
                break;
            case 3:
                editBuku(persediaan);
                break;
            case 4:
            	urutkanBuku(persediaan);
                tampilkanPersediaan(persediaan);
                break;
            case 5:
                cout << "\nKeluar dari program. Selamat tinggal!\n";
                break;
            default:
                cout << "\nPilihan tidak valid. Harap masukkan angka antara 1 dan 5.\n";
        }
    } while (pilihan != 5);

    return 0;
}

// Fungsi untuk menambahkan buku baru ke dalam persediaan
void tambahBuku(vector<Buku> &persediaan) {
    // Membuat objek buku baru
    Buku bukuBaru;
    cout << "Masukkan Informasi Buku Baru :\n";
    cout << "Judul : ";
    cin.ignore();
    getline(cin, bukuBaru.judul);

    cout << "Pengarang : ";
    getline(cin, bukuBaru.pengarang);

    cout << "Tahun : ";
    while (!(cin >> bukuBaru.tahun) || bukuBaru.tahun < 0) {
        cout << "Input tidak valid. Harap masukkan tahun yang valid: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Harga : $";
    while (!(cin >> bukuBaru.harga) || bukuBaru.harga < 0) {
        cout << "Input tidak valid. Harap masukkan harga yang valid: $";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Genre : ";
    cin.ignore();
    getline(cin, bukuBaru.genre);

    // Menambahkan buku ke dalam vektor persediaan
    persediaan.push_back(bukuBaru);

    cout << "Buku ditambahkan ke persediaan.\n";
}

// Fungsi untuk mencari buku berdasarkan judul
void cariBuku(const vector<Buku> &persediaan) {
    string judulCari;
    cout << "Masukkan judul buku yang dicari : ";
    cin.ignore();
    getline(cin, judulCari);

    bool ditemukan = false;
    for (int i = 0; i < persediaan.size(); ++i) {
        const Buku &buku = persediaan[i];
        if (buku.judul == judulCari) {
            cout << "Buku Anda Ditemukan!\n";
            cout << "Judul : " << buku.judul << "\n";
            cout << "Pengarang : " << buku.pengarang << "\n";
            cout << "Tahun : " << buku.tahun << "\n";
            cout << "Harga : $" << fixed << setprecision(2) << buku.harga << "\n";
            cout << "Genre : " << buku.genre << "\n";
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Buku tidak ditemukan dalam persediaan.\n";
    }
}

// Fungsi untuk mengedit informasi buku
void editBuku(vector<Buku> &persediaan) {
    string judulEdit;
    cout << "Masukkan judul buku yang ingin diedit: ";
    cin.ignore();
    getline(cin, judulEdit);

    bool ditemukan = false;
    for (int i = 0; i < persediaan.size(); ++i) {
        Buku &buku = persediaan[i];
        if (buku.judul == judulEdit) {
            cout << "Masukkan informasi baru untuk buku :\n";
            cout << "Judul : ";
            getline(cin, buku.judul);

            cout << "Pengarang : ";
            getline(cin, buku.pengarang);

            cout << "Tahun : ";
            while (!(cin >> buku.tahun) || buku.tahun < 0) {
                cout << "Input tidak valid. Harap masukkan tahun yang valid: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Harga : $";
            while (!(cin >> buku.harga) || buku.harga < 0) {
                cout << "Input tidak valid. Harap masukkan harga yang valid: $";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Genre : ";
            cin.ignore();
            getline(cin, buku.genre);

			cout << "\n-------------------------------------";
            cout << "\nInformasi buku diperbarui.\n";
            cout << "-------------------------------------\n";
            
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
    	cout << "\n-------------------------------------";
        cout << "\nBuku tidak ditemukan dalam persediaan.\n";
        cout << "-------------------------------------\n";
    }
}

// Fungsi untuk menampilkan persediaan buku
void tampilkanPersediaan(const vector<Buku> &persediaan) {
    if (persediaan.empty()) {
    	cout << "\n-------------------------------------";
        cout << "\nPersediaan kosong.\n";
        cout << "-------------------------------------\n";
    } else {
    	int jumlahBuku = 0; // Tambahkan penghitung jumlah buku
        cout << "\nPersediaan Buku:\n";
        for (int i = 0; i < persediaan.size(); ++i) {
            const Buku &buku = persediaan[i];
            cout << "Judul : " << buku.judul << "\n";
            cout << "Pengarang : " << buku.pengarang << "\n";
            cout << "Tahun : " << buku.tahun << "\n";
            cout << "Harga : $" << fixed << setprecision(2) << buku.harga << "\n";
            cout << "Genre : " << buku.genre << "\n";
            cout << "\n";
            jumlahBuku++; // Tambahkan jumlah buku
        }
        cout << "\n-------------------------------------";
        cout << "\nJumlah Buku dalam Persediaan: " << jumlahBuku << "\n";
        cout << "-------------------------------------\n";
    }
}

// Fungsi untuk mengurutkan buku berdasarkan judul
void urutkanBuku(vector<Buku> &persediaan) {
    int n = persediaan.size();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (persediaan[j].judul > persediaan[j + 1].judul) {
                // Tukar posisi buku jika urutan salah
                swap(persediaan[j], persediaan[j + 1]);
            }
        }
    }
}
