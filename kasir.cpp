
/*
Nama	: Hilmi Firdaus Abdillah
Kelas   : 2E
Nim     : 22041087
*/

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct buku
{
    int kode;
    string judul;
    int stok;
    int harga;
};

struct tipe
{
    buku lama;
    buku baru;
};

tipe listbuku[100];
int i, n, kode, pilihan, idx, idx2, jumlah;
string nama, nim, kelas;
char jawab;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void idprogram()
{
    system("cls");
    cout << "\t-----------------------------------\n";
    cout << "\t|     Program Kasir Toko Buku     |\n";
    cout << "\t-----------------------------------\n";
    cout << endl;
}

void tabel(string keterangan, int baris)
{
    idprogram();
    cout << keterangan << endl;
    cout << "======================================================\n";
    cout << "| Kode Buku | Nama Buku       | Stok  | Harga Satuan |\n";
    cout << "======================================================\n";

    for (int i = 0; i < baris; i++)
    {
        gotoxy(0, 8 + i);
        cout << "|           |                 |       |              |";
    }
    gotoxy(0, 8 + baris);
    cout << "------------------------------------------------------\n\n";
}

void list(int data)
{
    if (data == 1)
    {

        for (int i = 0; i < n; i++)
        {
            gotoxy(2, 8 + i);
            cout << listbuku[i].lama.kode;
            gotoxy(14, 8 + i);
            cout << listbuku[i].lama.judul;
            gotoxy(32, 8 + i);
            cout << listbuku[i].lama.stok;
            gotoxy(40, 8 + i);
            cout << "Rp " << listbuku[i].lama.harga << endl << endl;
        }
    }
    else if (data == 2)
    {
        for (int i = 0; i < n; i++)
        {
            gotoxy(2, 8 + i);
            cout << listbuku[i].baru.kode;
            gotoxy(14, 8 + i);
            cout << listbuku[i].baru.judul;
            gotoxy(32, 8 + i);
            cout << listbuku[i].baru.stok;
            gotoxy(40, 8 + i);
            cout << "Rp " << listbuku[i].baru.harga << endl << endl;
        }
    }
}

void inputdata()
{
    idprogram();
    tabel("Input Data Buku", 10);
    int b = 0;
    do
    {
        gotoxy(2, 8 + b);
        cin >> listbuku[i].lama.kode;
        gotoxy(14, 8 + b);
        cin.ignore();
        getline(cin, listbuku[i].lama.judul);
        gotoxy(32, 8 + b);
        cin >> listbuku[i].lama.stok;
        gotoxy(40, 8 + b);
        cout << "Rp ";
        cin >> listbuku[i].lama.harga;
        gotoxy(32, 4);
        cout << "Isi Data Lagi (Y/T): ";
        cin >> jawab;
        gotoxy(32, 4);
        cout << "                      ";
        listbuku[i].baru = listbuku[i].lama;
        i++;
        b++;
    } while (b < 10 && (jawab == 'Y' || jawab == 'y'));
    n = i;
}

void tampil()
{
    idprogram();
    int pilihan;
    cout << "Tampilkan data:\n";
    cout << "1. Data Sebelum Sorting\n";
    cout << "2. Data Setelah Sorting\n";
    do
    {
        gotoxy(13, 7);
        cout << "    ";
        gotoxy(0, 7);
        cout << "Pilih (1-2): ";
        cin >> pilihan;

        if (pilihan == 1)
        {
            tabel("Data Buku Sebelum Sorting", n);
            list(1);
        }
        else if (pilihan == 2)
        {
            tabel("Data Buku Setelah Sorting", n);
            list(2);
        }
        else
        {
            cout << "Pilihan tidak valid. Silahkan coba lagi\n";
        }
    } while (pilihan > 2 || pilihan < 1);
}

void sorting()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (listbuku[j].baru.kode > listbuku[j + 1].baru.kode)
            {
                buku temp = listbuku[j].baru;
                listbuku[j].baru = listbuku[j + 1].baru;
                listbuku[j + 1].baru = temp;
            }
        }
    }
    tabel("Data Buku Setelah Sorting", n);
    list(2);
}

int cari(int data)
{
    if (data == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (listbuku[i].lama.kode == kode)
            {
                return i;
            }
        }
        return -1;
    }
    else if (data == 2)
    {
        for (int i = 0; i < n; i++)
        {
            if (listbuku[i].baru.kode == kode)
            {
                return i;
            }
        }
        return -1;
    }
}

void transaksi()
{
    tabel("Transaksi", 10);
    gotoxy(54, 5);
    cout << "==========================";
    gotoxy(54, 6);
    cout << " Jumlah  | Total         |";
    gotoxy(54, 7);
    cout << "==========================";
    for (int i = 0; i < 10; i++)
    {
        gotoxy(63, 8 + i);
        cout << "|               |";
        gotoxy(0, 18);
        cout << "--------------------------------------------------------------------------------\n";
        cout << "|                                                     DISCOUNT |               |\n";
        cout << "|                                                TOTAL BELANJA |               |\n";
        cout << "|                                                        BAYAR |               |\n";
        cout << "|                                                      KEMBALI |               |\n";
        cout << "--------------------------------------------------------------------------------\n";
    }

    bool lanjut = true;
    int b = 0, total = 0, discount = 0, jumlah, bayar;

    while (lanjut)
    {
        bool ditemukan = false;

        while (!ditemukan)
        {
            gotoxy(2, 8 + b);
            cin >> kode;

            idx = cari(1);
            idx2 = cari(2);
            if (idx != -1)
            {
                ditemukan = true;
                break;
            }
            else
            {
                gotoxy(44, 4);
                cout << "Kode tidak ditemukan. Lanjut (Y/T): ";
                cin >> jawab;
                gotoxy(44, 4);
                cout << "                                     ";
                gotoxy(2, 8 + b);
                cout << "          ";
                if (jawab != 'Y' && jawab != 'y')
                {
                    lanjut = false;
                    break;
                }
            }
        }

        if (!lanjut)
        {
            break;
        }

        gotoxy(14, 8 + b);
        cout << listbuku[idx].lama.judul;
        gotoxy(32, 8 + b);
        cout << listbuku[idx].lama.stok;
        gotoxy(40, 8 + b);
        cout << "Rp " << listbuku[idx].lama.harga;
        gotoxy(55, 8 + b);
        cin >> jumlah;

        while (jumlah > listbuku[idx].lama.stok)
        {
            gotoxy(47, 4);
            cout << "Stok tidak cukup. Lanjut (Y/T): ";
            cin >> jawab;
            gotoxy(47, 4);
            cout << "                                 ";
            gotoxy(55, 8 + b);
            cout << "        ";
            if (jawab != 'Y' && jawab != 'y')
            {
                gotoxy(0, 8 + b);
                cout << "|           |                 |       |              |";
                lanjut = false;
                break;
            }
            gotoxy(55, 8 + b);
            cin >> jumlah;
        }

        if (!lanjut)
        {
            break;
        }

        int ttl = listbuku[idx].lama.harga * jumlah;
        total += ttl;
        gotoxy(65, 8 + b);
        cout << "Rp " << ttl;
        b++;
        listbuku[idx].lama.stok -= jumlah;
        listbuku[idx2].baru.stok -= jumlah;

        gotoxy(65, 4);
        cout << "Lanjut (Y/T): ";
        cin >> jawab;
        gotoxy(65, 4);
        cout << "               ";
        if (jawab != 'Y' && jawab != 'y')
        {
            lanjut = false;
        }
    }

    if (total > 100000 || total < 500000)
    {
        discount = 0.10 * total;
    }
    if (total > 500000)
    {
        discount = 0.20 * total;
    }
    else
    {
        discount = 0;
    }
    int tb = total - discount;
    gotoxy(65, 19);
    cout << "Rp " << discount;
    gotoxy(65, 20);
    cout << "Rp " << tb;
    gotoxy(65, 21);
    cout << "Rp ";
    cin >> bayar;
    while (bayar < tb)
    {
        gotoxy(68, 20);
        cout << "           ";
        gotoxy(43, 4);
        cout << "Uang bayar kurang. Silahkan coba lagi";
        gotoxy(68, 20);
        cin >> bayar;
    }
    gotoxy(43, 4);
    cout << "                                     ";
    int kembalian = bayar - tb;
    gotoxy(65, 22);
    cout << "Rp " << kembalian;
    cout << endl << endl;
}

void menu()
{
    idprogram();
    cout << "Menu:\n";
    cout << "1. Input Data Buku\n";
    cout << "2. Tampil Data Buku\n";
    cout << "3. Sorting Data Buku\n";
    cout << "4. Transaksi\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu (1-5): ";
}

int main()
{
    idprogram();
    cout << "Nama	: ";
    getline(cin, nama);
    cout << "NIM	: ";
    cin >> nim;
    cout << "Kelas	: ";
    cin >> kelas;

    do
    {
        menu();
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            inputdata();
            break;
        case 2:
            tampil();
            getch();
            break;
        case 3:
            sorting();
            getch();
            break;
        case 4:
            transaksi();
            getch();
            break;
        case 5:
            idprogram();
            cout << "Nama	: " << nama << endl;
            cout << "NIM	: " << nim << endl;
            cout << "Kelas	: " << kelas << endl;
            cout << "Terima kasih.\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
            getch();
            break;
        }
    } while (pilihan != 5);

    return 0;
}
