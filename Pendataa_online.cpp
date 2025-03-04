#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

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

string nama;
char ulang,beli,isi,editlagi;
int pilihan, edit, input, banyak_data = 0, p = 0;

jualan barang[100];
pembeli orang[100];

void menu_beli(), tampilkan_barang(int i), menu_aplikasi(), input_barang(), edit_barang(), edit_toko(), hapus_barang(), cari_barang(),cari_barang(), ubahkapital(string& str);

int main(){
    do{
    menu_aplikasi(); 
    cout<<"Masukkan Pilihan : ";
    cin>>pilihan; 
    switch (pilihan){
        case 1:edit_toko();break;
        case 2:menu_beli();break;
        case 3:
            for(int i = 0; i<banyak_data;i++){
                tampilkan_barang(i);
            }break;
        default:cout<<"Pilihan Tidak Tersedia";break;  
        }
    cout<<"Ingin Memilih Menu Lagi (y/n) : ";
    cin>>ulang;
    }while (ulang == 'y' || ulang == 'Y');
}
    
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
void menu_aplikasi(){
    system("cls");
    cout<<"================================"<<endl;
    cout<<"-------Daftar Menu Pilihan------"<<endl;
    cout<<"================================"<<endl;
    cout<<"1. Penjual"<<endl;
    cout<<"2. Pembeli"<<endl;
    cout<<"3. Tampilkan Barang"<<endl;
    cout<<"================================"<<endl;
}
void menu_beli(){
    cout<<"Silahkan Isi Identitas Diri Anda"<<endl;
    cout<<"Nama Anda : ";
    cin.ignore();
    cin>>orang[p].nama;
    cout<<"Masukan Alamat Anda : ";
    cin.ignore();
    cin>>orang[p].alamat;
    cout<<"Masukan Nomor Telepon Anda : ";
    cin>>orang[p].nomor_telp;
}
void tampilkan_barang(int i){
        cout<<"Nama Barang : "<<barang[i].nama<<endl;
        cout<<"Harga Barang : "<<barang[i].harga<<endl;
        cout<<"Stok Barang : "<<barang[i].stok<<endl;
        cout<<"Deskripsi Barang : "<<barang[i].deskripsi<<endl;
        cout<<endl;
}
void edit_toko(){
    do{
    system("cls");
    cout<<"===== EDIT BARANG PENJUALAN ====="<<endl;
    cout<<"1. Input Barang Jualan"<<endl;
    cout<<"2. Edit Barang Jualan"<<endl;
    cout<<"3. Hapus Barang Jualan"<<endl;
    cout<<"4. Tampilkan Barang Jualan"<<endl;
    cout<<"5. Cari Barang Jualan"<<endl;
    cout<<"================================="<<endl;
    cout<<"Masukan Pilihan Anda (1-2) : ";
    cin>>edit;
    
        switch(edit){
            case 1:input_barang();break;
            case 2:edit_barang();break;
            case 3:hapus_barang();break;
            case 4:for(int i = 0; i<banyak_data;i++){
                tampilkan_barang(i);
            }break;
            case 5:cari_barang();break;
            default:cout<<"Pilihan Tidak Tersedia"<<endl;
        }
        cout<<"Apakah Anda Masih Ingin Di Dalam Menu Edit Barang Penjualan? (y/t) : ";
        cin>>editlagi;
    }while(editlagi == 'y' || editlagi == 'Y');
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
        tampilkan_barang(i);
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
            tampilkan_barang(i);
        }
    }
}
void hapus_barang(){
    string nama;
    cout<<"Masukan Nama Barang Yang Ingin Di Hapus : ";
    cin>>nama;
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


void ubahkapital(string& str) {
    for (char& c : str) {
        c = toupper(c);
    }
}
