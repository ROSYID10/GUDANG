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
int pilihan, selesai_beli, edit, siapa, pilih, input, pilihbeli, tambah, banyak_keranjang = 0   , banyak_data = 0, p = 0, index = 0;
string namapengguna, alamatpengguna, no_hppengguna, sementara;
jualan barang[100], isikeranjang[100];
pembeli orang[100];


void menu_beli(), login(), buatakun(), tampilkan_barang(jualan* data, int index),  input_barang(), edit_barang(), edit_toko(), hapus_barang(), cari_barang(), ubahkapital(string& str), tampilkan_data_diri(pembeli* data), sorting_data(jualan* barang), taruhfiledatadiri(), taruhinputbarang(), simpanfiledatadiri(), simpaninputbarang(), simpanbanyakbarang(), ubahinputbarang(),beli_barang(int beli), beli_langsung(), tambahkan_keranjang(), tampilkanisikeranjang();

// ===========================================================================================================================================================================================================================================
// Bagian Keseluruhan deklarasi

int main(){
    do{
        system("cls");
        taruhfiledatadiri();
        taruhinputbarang();
        cout    <<"1. Buat Akun"<<endl;
        cout    <<"2. Login"<<endl;
        cout    <<"Masukan pilihan anda : ";
        cin     >>   pilih;
        switch  (pilih){  
            case 1: buatakun();break;
            case 2: login();break;
            case 3: cout<<"Terima Kasih"<<endl; system("exit");
            default:cout<<"inputan anda tidak tersedia"<<endl;
        }
    }while(pilih == 1 || pilih == 2 || pilih == 3);
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
    cout<<"6. Sorting Barang"<<endl;
    cout<<"7. Keluar"<<endl;
    cout<<"================================="<<endl;
    cout<<"Masukan Pilihan Anda (1-7) : ";
    cin>>edit;
    
        switch(edit){
            case 1:system("cls");input_barang();break;
            case 2:system("cls");edit_barang();break;
            case 3:system("cls");hapus_barang();break;
            case 4:system("cls");tampilkan_barang(barang, index);break;
            case 5:system("cls");cari_barang();break;
            case 6:system("cls");sorting_data(barang);break;
            case 7:system("cls");break;   
            default:cout<<"Pilihan Tidak Tersedia"<<endl;
        }
        if(edit == 7){break;}
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
        cin.ignore();
        system("cls");
        cout<<"Masukkan Nama Barang : ";
        getline(cin,barang[banyak_data].nama);
        ubahkapital(barang[banyak_data].nama);
        cout<<"Masukkan Harga Barang : ";
        cin>>barang[banyak_data].harga;
        cout<<"Masukkan Stok Barang : ";
        cin>>barang[banyak_data].stok;
        cin.ignore();
        cout<<"Masukkan Deskripsi Barang :";
        getline(cin, barang[banyak_data].deskripsi);
        simpaninputbarang();
        banyak_data++;
        
    }
    simpanbanyakbarang();
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
        cout<<"4. Deskripsi"<<endl;
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
            getline(cin, barang[i].deskripsi);
            break;
        }
        cout<<endl;
        ubahinputbarang();
        tampilkan_barang(barang, index);
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
        cout<<"Nama Barang  : "<<barang[i].nama<<endl;
        cout<<"Harga Barang : "<<barang[i].harga<<endl;
        cout<<"Stok Barang  : "<<barang[i].stok<<endl;
        cout<<"Deskripsi Barang : "<<barang[i].deskripsi<<endl;
        }
    }
}
void hapus_barang(){
    cout<<"Masukan Nama Barang Yang Ingin Di Hapus : ";
    cin>>nama;
    ubahkapital(nama);
    for(int i=0; i<=banyak_data ; i++){
        if(nama == barang[i].nama){
            for(int j = i; j < banyak_data ; j++){
                barang[j] = barang[j+1];
            }
            banyak_data--;
            ubahinputbarang();
            simpanbanyakbarang();
            
            cout<<"Data Berhasil diHapus"<<endl;

            break;
        }if(i==banyak_data && nama != orang[i].nama){
            cout<<"Data Tidak Ditemukan"<<endl;
        }
    }
}
// ==========================================================================================================================================================

// MENU YANG TERSEDIA BAGI PEMBELI
// ==========================================================================================================================================================


void tampilkan_data_diri(pembeli* data){
    system("cls");
    cout<<"Nama : "<<data[p].nama<<endl;
    cout<<"Alamat : "<<data[p].alamat<<endl;
    cout<<"Nomor Telepon :"<<data[p].nomor_telp<<endl;
}

void tampilkan_barang(jualan* data, int index){
    if(banyak_data == 0)cout<<"Belum Ada Barang Yang Diinputkan"<<endl;
    if(index == banyak_data)return;
    if(index < banyak_data){
        cout    <<"=================="<<index + 1<<"==================="<<endl;
        cout    <<"Nama Barang  : "<<data[index].nama<<endl;
        cout    <<"Harga Barang : "<<data[index].harga<<endl;
        cout    <<"Stok Barang  : "<<data[index].stok<<endl;
        cout    <<"Deskripsi Barang : "<<data[index].deskripsi<<endl;
        cout    <<"======================================="<<endl;
        cout    <<endl;
        tampilkan_barang(data, index + 1);
    }
}

// MENU YANG MEMBANTU DALAM PEMBUATAN PROGRAM
// ==========================================================================================================================================================
void ubahkapital(string& str) {
    for (char& c : str) {
        c = toupper(c);
    }
}
void sorting_data(jualan* barang){
    if (banyak_data == 0) {
        cout << "Belum ada data yang bisa diurutkan.\n";
        return;
    }

    int pilih;
    cout<<"1. Nama "<<endl;
    cout<<"2. Harga "<<endl;
    cout<<"3. Stok "<<endl;
    cout<<"======================="<<endl;
    cout<<"Anda Ingin Mengurutkan Berdasarkan Apa : ";
    cin >> pilih;
    for(int i = 0; i < banyak_data - 1; i++){
        for(int j = 0; j < banyak_data - 1; j++){
            bool ganti = false;

            switch(pilih){
                case 1:if(barang[j].nama  > barang[j+1].nama)ganti = true;
                break;
                
                case 2:if(barang[j].harga > barang[j+1].harga)ganti = true;
                break;
                
                case 3:if(barang[j].stok  > barang[j+1].stok)ganti = true;
                break;
                
                default:
                break;
            }
            if(ganti == true){
                swap(barang[j], barang[j+1]);
            }
    
    
    // // Bubble sort berdasarkan harga
    
            
        }
    }

    
    cout << "\nData barang berhasil diurutkan ascending:\n";
    tampilkan_barang(barang, index);
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
    
    cout    <<"Masukan Username Anda : ";
    cin     >>username;
    cout    <<"Masukan Password Anda : ";
    cin     >>password;
    
    ofstream akun;
    akun.open("akun1", ios::app);
    akun    << username;
    akun    << endl;
    akun    << password;
    akun    << endl;
    akun    << peran;
    akun    << endl;
    akun.close();
    
    if(siapa == 1){
        do{
            cout    <<"Silahkan Isi Identitas Diri Anda"<<endl;
            cout    <<"Nama Anda : ";
            cin.ignore();
            getline(cin, orang[p].nama);
            akun    << orang[p].nama;
            
            cout    <<"Masukan Alamat Anda : ";
            getline(cin, orang[p].alamat);
            akun    << orang[p].alamat;
            
            cout    <<"Masukan Nomor Telepon Anda : ";
            cin     >>orang[p].nomor_telp;          
            tampilkan_data_diri(orang);

            cout    <<"Apakah data diri anda sudah benar? (y/t) : ";
            cin     >>yakin;
        }while(yakin == 't' || yakin == 'T');
        
        simpanfiledatadiri();
    }
    cout<<"Selamat Anda Berhasil Membuat Akun"<<endl;
    cout<<"Silahkan Lanjut ke Menu login"<<endl;
    system("pause");
    login();
}
void login(){
    system("cls");
    bool berhasil = false;
    int kesempatan = 3;
    for(int i = 3; i >= kesempatan ;i--){
        system("cls");
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
                cout<<endl<<"anda berhasil login"<<endl<<endl;
                berhasil = true;
                system("pause");
                break;
            }
        }

        if((kesempatan == 0) && (!berhasil)){
            cout<<"Kesempatan Login anda Habis, Silahkan Coba Kembali Lain Kali"<<endl;
            exit(0);
        }else if(!berhasil){
            cout<<"Username atau Password anda salah"<<endl;
            cout<<"Anda Masih memiliki "<< kesempatan <<" kesempatan lagi"<<endl;
            cout<<"Silahkan mengisi kembali"<<endl;
            cout<<endl;
            kesempatan--;
            system("pause");
        }
        akun.close();
        
    }while(!berhasil);
    if(verifikasiperan == "pembeli")menu_beli();
    else if(verifikasiperan == "penjual")edit_toko(); 
}
// ==========================================================================================================================================================

void taruhfiledatadiri(){
    ifstream datadiri;
    ifstream Myfile;
    Myfile.open("datadiri");
    datadiri.open("BanyakDataDiri");
    datadiri >> p;
    for(int i = 0; i <= p; i++){
    Myfile  >> orang[p].nama;
    Myfile  >> orang[p].alamat;
    Myfile  >> orang[p].nomor_telp;
}
Myfile.close();
datadiri.close();
}

void simpanfiledatadiri(){
    ofstream Myfile;
    ofstream datadiri;
    datadiri.open("BanyakDataDiri", ios::trunc);
    Myfile.open(("datadiri" + username), ios::app);
    Myfile << orang[p].nama;
    Myfile << endl; 
    Myfile << orang[p].alamat;
    Myfile << endl;
    Myfile << orang[p].nomor_telp;
    p++;
    datadiri << p;
    datadiri.close();
    Myfile.close();
}

void taruhinputbarang(){
    ifstream data;
    ifstream banyak;
    data.open("databarang");
    banyak.open("banyakbarang");
    banyak >> banyak_data;
    for(int i = 0 ; i < banyak_data ; i++){
        if(banyak_data == 0 )break;
        getline(data >> ws, barang[i].nama);
        data >> barang[i].harga;
        data >> barang[i].stok;
        getline(data >> ws, barang[i].deskripsi);
    }
    data.close();
    banyak.close();
}

void simpaninputbarang(){
    ofstream data;
    
    data.open("databarang", ios::app);
    data << barang[banyak_data].nama;
    data << endl;
    data << barang[banyak_data].harga;
    data << endl;
    data << barang[banyak_data].stok;
    data << endl;
    data << barang[banyak_data].deskripsi;
    data << endl;
    data.close();
    
}

void simpanbanyakbarang(){
    ofstream banyak;
    banyak.open("banyakbarang", ios::trunc);
    banyak << banyak_data;
    banyak.close();
}

void ubahinputbarang(){
    ofstream risetdata;
    
    risetdata.open("databarang", ios::trunc);
    risetdata.close();
    
    ofstream data;
    data.open("databarang", ios::app);
    for(int i = 0 ; i < banyak_data; i++){
        data << barang[i].nama;
    data << endl;
    data << barang[i].harga;
    data << endl;
    data << barang[i].stok;
    data << endl;
    data << barang[i].deskripsi;
    data << endl;
}
data.close();

}





void menu_beli(){
    char belilagi;
    do{
        cout<<endl;
        cout<<"==========PILIHAN MENU=========="<<endl;
        cout<<"1. Beli "<<endl;
        cout<<"2. Lihat Isi Keranjang"<<endl;
        cout<<"3. Mengurutkan barang"<<endl;
        cout<<"4. Keluar"<<endl;
        cout<<"================================"<<endl;
        cout<<"Masukan Pilihan Anda : ";
        cin>>pilihbeli;
        
        switch(pilihbeli){
            case 1:beli_langsung();
            break;
            
            case 2:tampilkanisikeranjang();
            break;
            
            case 3:sorting_data(barang);
            break;
            
            case 4:cout<<"Terima Kasih Anda Sudah Berbelanja"<<endl;
                    system("pause");
            break;
            
            default:
            break;
        }
        if(pilihbeli == 4)break;
        cout<<"Apakah anda ingin kembali berbelanja? : ";
        cin>>belilagi;
        
    }while(belilagi == 'y' || belilagi == 'Y');   
}

void beli_langsung(){
    do{
        system("cls");
        tampilkan_barang(barang, index);
        cout<<endl;
        cout<<"Barang Nomor Berapa Yang Ingin Anda Beli : ";
        cin>>selesai_beli;
        selesai_beli--;
        if(selesai_beli <= banyak_data){
            cout<<"Barang yang anda pilih tidak ada di etalase"<<endl;
            cout<<"Silahkan pilih kembali"<<endl;
        }
    }while(selesai_beli >= banyak_data);
    
    do{
    int membeli;
    cout<<"1. Beli langsung"<<endl;
    cout<<"2. Masukan Ke keranjang"<<endl;
    cout<<"============================"<<endl;
    cout<<"Masukkan pilihan Anda : ";
    cin>>membeli;
    switch(membeli){
        case 1: beli_barang(selesai_beli);
        break;

        case 2: tambahkan_keranjang();
        break;

        default:
        break;
    }
    system("pause");
    }while(beli == 1 || beli == 2);
}

void beli_barang(int beli){

    

}

void tambahkan_keranjang(){
    ofstream keranjang;
    keranjang.open("keranjang" + username, ios::app);

    keranjang << barang[selesai_beli].nama;
    keranjang << endl;
    keranjang << barang[selesai_beli].harga;
    keranjang << endl;
    keranjang << barang[selesai_beli].deskripsi;
    keranjang << endl;

    if(!keranjang){
        cout<<"Terjadi Kesalahan barang anda gagal di tambahkan"<<endl;
    }
    if(keranjang){
        cout<<"Barang Anda berhasil di tambahkan"<<endl;
    }

    keranjang.close();
}

void tampilkanisikeranjang(){
    ifstream isikeranjang;
    isikeranjang.open("Keranjang" + username);
    while(!isikeranjang.eof()){
    isikeranjang >> sementara;
    isikeranjang >> sementara;
    isikeranjang >> sementara;
    }
}


    






