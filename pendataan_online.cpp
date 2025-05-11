#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <string>
using namespace std;

// Bagian Keseluruhan deklarasi
// ==========================================================================================================================================================================================================================================
typedef struct{
    string nama;
    string alamat;
    int nomor_telp;
} pembeli;
typedef struct{
    string nama;
    int harga;
    int stok;
    string deskripsi;
}jualan;
string nama,password,username,peran,verifikasiusername,verifikasipassword,verifikasiperan;
char ulang,beli,isi,editlagi,yakin;
int pilihan, edit, siapa, pilih, input, banyak_data = 0, p = 0;
string namapengguna, alamatpengguna, no_hppengguna;
jualan barang[100];
pembeli orang[100];

void menu_beli(), login(), buatakun(), tampilkan_barang(),  input_barang(), edit_barang(), edit_toko(), hapus_barang(), cari_barang(),cari_barang(), ubahkapital(string& str), tampilkan_data_diri (), sorting_data();

// ===========================================================================================================================================================================================================================================
// Bagian Keseluruhan deklarasi

int main(){
    system("cls");
    cout    <<"1. Buat Akun"<<endl;
    cout    <<"2. Login"<<endl;

    cout    <<"Masukan pilihan anda : ";
    cin     >>   pilih;
    switch  (pilih)
    {  
        case 1:buatakun();break;
        case 2:login();break;
    }
}

//menu yang tersedia di main
void edit_toko(){
    do{
    system("cls");
    cout<<"===== EDIT BARANG PENJUALAN ====="<<endl;
    cout<<"1. Input Barang Jualan"<<endl;
    cout<<"2. Edit Barang Jualan"<<endl;
    cout<<"3. Hapus Barang Jualan"<<endl;
    cout<<"4. Tampilkan Barang Jualan"<<endl;
    cout<<"5. Cari Barang Jualan"<<endl;
    cout<<"6. Sorting Data Berdasarkan Harga"<<endl;
    cout<<"7. Kembali"<<endl;
    cout<<"================================="<<endl;
    cout<<"Masukan Pilihan Anda (1-6) : ";
    cin>>edit;
    
        switch(edit){
            case 1:system("cls");input_barang();break;
            case 2:system("cls");edit_barang();break;
            case 3:system("cls");hapus_barang();break;
            case 4:system("cls");tampilkan_barang();break;
            case 5:system("cls");cari_barang();break;
            case 6:system("cls");sorting_data();break;
            case 7:system("cls");break;   
            default:cout<<"Pilihan Tidak Tersedia"<<endl;
        }
        cout<<"Apakah Anda Masih Ingin Di Dalam Menu Edit Barang Penjualan? (y/t) : ";
        cin>>editlagi;
    }while(editlagi == 'y' || editlagi == 'Y');
}
// ==========================================================================================================================================================

//MENU YANG TERSEDIA BAGI PENJUAL
// ==========================================================================================================================================================
void input_barang(){
    system("cls");
    cout<<"Masukkan Jumlah Barang yang ingin diinput : ";
    cin>>input;

    for(int i = 0; i < input; i++){
        system("cls");
        cout<<"Masukkan Nama Barang : ";
        cin.ignore();
        cin>>barang[banyak_data].nama;
        ubahkapital(barang[banyak_data].nama);
        cout<<"Masukkan Harga Barang : ";
        cin>>barang[banyak_data].harga;
        cout<<"Masukkan Stok Barang : ";
        cin>>barang[banyak_data].stok;
        cout<<"Masukkan Deskripsi Barang :";
        cin>>barang[banyak_data].deskripsi;
        banyak_data++;
    }
    cout<<"Data Barang Sudah Tersimpan"<<endl;
}
void edit_barang(){
    system("cls");
    cout<<"Masukan Nama Barang Yang Ingin Di Edit :";
    cin>>nama;
    ubahkapital(nama);
    for(int i = 0; i<banyak_data; i++){
        if(nama==barang[i].nama){
        cout<<"1. Nama"<<endl;
        cout<<"2. Harga"<<endl;
        cout<<"3. Stok"<<endl;
        cout<<endl;
        cout<<"Hal Apa Yang Ingin Di Edit : ";
        int edit;
        cin>>edit;
        switch(edit){
            case 1:
            cout<<"Masukan Nama Baru Barang : ";
            cin>>barang[i].nama;
            ubahkapital(barang[i].nama);
            break;
            case 2:
            cout<<"Masukan Harga Baru Barang : ";
            cin>>barang[i].harga;
            break;
            case 3:
            cout<<"Masukan Stok Baru : ";
            cin>>barang[i].stok;
            break;
            case 4:
            cout<<"Masukan Deskripsi Barang : ";
            cin>>barang[i].deskripsi;
            break;
        }
        cout<<endl;
        tampilkan_barang();
        cout<<endl;
        cout<<"Barang Berhasil Di Edit"<<endl;
        cout<<endl;
        }
        if(i==banyak_data && nama != barang[i].nama){
            cout<<"Barang Yang Anda Maksud Tidak Terdapat Dalam Data"<<endl;
        }
    }
}
void cari_barang(){
    string nama;
    cout<<"Masukan Nama Barang Yang Ingin Di Cari : ";
    cin>>nama;
    ubahkapital(nama);
    for(int i = 0; i<banyak_data; i++){
        if(nama==barang[i].nama){
            tampilkan_barang();
        }
    }
}
void hapus_barang(){
    cout<<"Masukan Nama Barang Yang Ingin Di Hapus : ";
    cin>>nama;
    ubahkapital(nama);
    for(int i=0; i<=banyak_data ; i++){
        if(nama == barang[i].nama){
            for(int j = i; j<=banyak_data ; j++){
                orang[j] = orang[j+1];
                if(j==banyak_data){
                    banyak_data--;
                    cout<<"Data Berhasil diHapus"<<endl;
                    break;
                }
            }
            break;
        }if(i==banyak_data && nama != orang[i].nama){
            cout<<"Data Tidak Ditemukan"<<endl;
        }
    }
}
// ==========================================================================================================================================================

// MENU YANG TERSEDIA BAGI PEMBELI
// ==========================================================================================================================================================
void menu_beli(){
    
}
void tampilkan_data_diri(){
    system("cls");
    cout<<"Nama : "<<orang[p].nama<<endl;
    cout<<"Alamat : "<<orang[p].alamat<<endl;
    cout<<"Nomor Telepon :"<<orang[p].nomor_telp<<endl;
}

void tampilkan_barang(){
    for(int i = 0; i<=banyak_data; i++){
        if(banyak_data == 0){
            cout<<"Belum Ada Data Yang Di Input"<<endl;
            break;
        }else{
        cout<<"Nama Barang  : "<<barang[i].nama<<endl;
        cout<<"Harga Barang : "<<barang[i].harga<<endl;
        cout<<"Stok Barang  : "<<barang[i].stok<<endl;
        cout<<"Deskripsi Barang : "<<barang[i].deskripsi<<endl;
        cout<<endl;
        }
    }
}

// MENU YANG MEMBANTU DALAM PEMBUATAN PROGRAM
// ==========================================================================================================================================================
void ubahkapital(string& str) {
    for (char& c : str) {
        c = toupper(c);
    }
}
void sorting_data(){
    if (banyak_data == 0) {
        cout << "Belum ada data yang bisa diurutkan.\n";
        return;
    }

    // Bubble sort berdasarkan harga
    for(int i = 0; i < banyak_data - 1; i++){
        for(int j = 0; j < banyak_data - i - 1; j++){
            if(barang[j].harga > barang[j + 1].harga){
                swap(barang[j], barang[j + 1]);
            }
        }
    }

    cout << "\nData barang berhasil diurutkan berdasarkan harga secara ascending:\n";
    tampilkan_barang();
}
//===========================================================================================================================================================

// MENU LOGIN DAN PEMBUATAN AKUN
// ==========================================================================================================================================================
void buatakun(){
    system("cls");
    cout<<"Jenis Peran"<<endl;
    cout<<"1. Pembeli"<<endl;
    cout<<"2. Penjual"<<endl;
    cout<<"-----------------"<<endl;
    cout<<"Siapakah Anda : ";
    cin>>siapa;
    if(siapa == 1 )peran = "pembeli";
    else if(siapa == 2)peran = "penjual";

    cout<<"Masukan Username Anda : ";
    cin>>username;
    cout<<"Masukan Password Anda : ";
    cin>>password;
    ofstream akun;
    akun.open("akun1", ios::app);
    akun << username;
    akun << endl;
    akun << password;
    akun << endl;
    akun << peran;
    akun << endl;
    akun.close();
    if(siapa == 1){
    ofstream Myfile;
    Myfile.open(("datadiri" + username), ios::app);
        do{
        cout    <<"Silahkan Isi Identitas Diri Anda"<<endl;
        cout    <<"Nama Anda : ";
        cin.ignore();
        getline(cin, orang[p].nama);

        akun    << orang[p].nama;
        cout    <<"Masukan Alamat Anda : ";
        getline(cin, orang[p].alamat);

        akun    << orang[p].nama;
        cout    <<"Masukan Nomor Telepon Anda : ";
        cin     >>orang[p].nomor_telp;          
        tampilkan_data_diri();
        cout    <<"Apakah data diri anda sudah benar? (y/t) : ";
        cin     >>yakin;
        }while(yakin == 't' || yakin == 'T');
    Myfile << orang[p].nama;
    Myfile << endl; 
    Myfile << orang[p].alamat;
    Myfile << endl;
    Myfile << orang[p].nomor_telp;
    Myfile.close();
    }
    
    

    cout<<"Selamat Anda Berhasil Membuat Akun"<<endl;
    cout<<"Silahkan Lanjut ke Menu login"<<endl;
    system("pause");
    login();
}
void login(){
    system("cls");
    bool berhasil = false;
    do{
    cout<<"Masukan Username Anda : ";
    cin>>username;
    cout<<"Masukan Password Anda : ";
    cin>>password;
    ifstream akun;
    akun.open("akun1");
    while(!akun.eof()){
        akun >> verifikasiusername;
        akun >> verifikasipassword;
        akun >> verifikasiperan;
        if((verifikasiusername == username) && (verifikasipassword == password)){
            cout<<"anda berhasil login"<<endl;
            berhasil = true;
            system("pause");
            break;
        }
    }
    if(verifikasiperan == "pembeli")menu_beli();
    else if(verifikasiperan == "penjual")edit_toko(); 
    akun.close();
    }while(!berhasil);
}
// ==========================================================================================================================================================