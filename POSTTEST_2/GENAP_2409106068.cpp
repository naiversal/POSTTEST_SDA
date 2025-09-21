#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

struct Jadwal {
    string kodePenerbangan;
    string tujuan;
    string status;
    Jadwal *next;
};

Jadwal *head = nullptr;
int counterKode = 0;

bool isEmpty() {
    return head == nullptr;
}

string intToString(int num) {
    string result = "";
    if (num == 0) return "0";
    while (num > 0) {
        char digit = (num % 10) + '0';
        result = digit + result;
        num /= 10;
    }
    return result;
}

string generateKode() {
    string base = "JT-068-";
    counterKode++;
    return base + intToString(counterKode);
}

void clearScreen() {
    system("cls");
    SetConsoleOutputCP(CP_UTF8);
}



void tampilkanJadwal() {
    cout << "╭──────────────────────────────────────────────────────────────╮" << endl;
    cout << "│                    TAMPILKAN SEMUA JADWAL                    │" << endl;
    cout << "├──────┬──────────────┬───────────────────┬────────────────────┤" << endl;
    cout << "│ No   │ Kode         │ Tujuan            │ Status             │" << endl;
    cout << "├──────┼──────────────┼───────────────────┼────────────────────┤" << endl;
    if (isEmpty()) {
        cout << "│      │ --           │ Belum ada jadwal  │ --                 │" << endl;
    } else {
        Jadwal *temp = head;
        int no = 1;
        while (temp != nullptr) {
            cout << "│ " << setw(4) << left << no++
                 << " │ " << setw(12) << left << temp->kodePenerbangan
                 << " │ " << setw(17) << left << temp->tujuan
                 << " │ " << setw(18) << left << temp->status << " │" << endl;
            temp = temp->next;
        }
    }
    cout << "╰──────┴──────────────┴───────────────────┴────────────────────╯" << endl;
}









string pilihStatus() {
    int opsi;
    cout << "Pilih Status:" << endl;
    cout << "1. Scheduled" << endl;
    cout << "2. Delayed" << endl;
    cout << "3. Departed" << endl;
    cout << "4. Arrived" << endl;
    cout << "Pilihan: ";
    cin >> opsi;
    cin.ignore();
    switch (opsi) {
        case 1: return "Scheduled";
        case 2: return "Delayed";
        case 3: return "Departed";
        case 4: return "Arrived";
        default: return "Scheduled";
    }
}

void tambahJadwal() {
    cout << "╭──────────────────────────────────────────────────────────────╮" << endl;
    cout << "│                  TAMBAH JADWAL PENERBANGAN                   │" << endl;
    cout << "├──────┬──────────────┬───────────────────┬────────────────────┤" << endl;
    cout << "│ No   │ Kode         │ Tujuan            │ Status             │" << endl;
    cout << "├──────┼──────────────┼───────────────────┼────────────────────┤" << endl;
    if (isEmpty()) {
        cout << "│      │ --           │ Belum ada jadwal  │ --                 │" << endl;
    } else {
        Jadwal *temp = head;
        int no = 1;
        while (temp != nullptr) {
            cout << "│ " << setw(4) << left << no++
                 << " │ " << setw(12) << left << temp->kodePenerbangan
                 << " │ " << setw(17) << left << temp->tujuan
                 << " │ " << setw(18) << left << temp->status << " │" << endl;
            temp = temp->next;
        }
    }
    cout << "╰──────┴──────────────┴───────────────────┴────────────────────╯" << endl;
    
    string tujuan;
    cout << "Masukkan tujuan: ";
    getline(cin, tujuan);
    string status = pilihStatus();
    
    Jadwal *baru = new Jadwal;
    baru->kodePenerbangan = generateKode();
    baru->tujuan = tujuan;
    baru->status = status;
    baru->next = nullptr;
    if (head == nullptr) head = baru;
    else {
        Jadwal *temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = baru;
    }
    cout << "Jadwal berhasil ditambahkan: " << baru->kodePenerbangan << endl;
}

void sisipJadwal() {
    cout << "╭──────────────────────────────────────────────────────────────╮" << endl;
    cout << "│                 SISIPKAN JADWAL PENERBANGAN                  │" << endl;
    cout << "├──────┬──────────────┬───────────────────┬────────────────────┤" << endl;
    cout << "│ No   │ Kode         │ Tujuan            │ Status             │" << endl;
    cout << "├──────┼──────────────┼───────────────────┼────────────────────┤" << endl;
    if (isEmpty()) {
        cout << "│      │ --           │ Belum ada jadwal  │ --                 │" << endl;
        cout << "╰──────┴──────────────┴───────────────────┴────────────────────╯" << endl;
        cout << "Tidak ada jadwal untuk disisipkan" << endl;
        return;
    } else {
        Jadwal *temp = head;
        int no = 1;
        while (temp != nullptr) {
            cout << "│ " << setw(4) << left << no++
                 << " │ " << setw(12) << left << temp->kodePenerbangan
                 << " │ " << setw(17) << left << temp->tujuan
                 << " │ " << setw(18) << left << temp->status << " │" << endl;
            temp = temp->next;
        }
    }
    cout << "╰──────┴──────────────┴───────────────────┴────────────────────╯" << endl;
    
    string tujuan;
    cout << "Masukkan tujuan: ";
    getline(cin, tujuan);
    string status = pilihStatus();
    
    int digitTerakhir = 8;
    int posisi = digitTerakhir + 1;
    Jadwal *baru = new Jadwal;
    baru->kodePenerbangan = generateKode();
    baru->tujuan = tujuan;
    baru->status = status;
    baru->next = nullptr;
    Jadwal *current = head;
    int count = 1;
    while (current != nullptr && count < posisi - 1) {
        current = current->next;
        count++;
    }
    if (current == nullptr) {
        cout << "Posisi tidak valid" << endl;
        delete baru;
    } else {
        baru->next = current->next;
        current->next = baru;
        cout << "Jadwal berhasil disisipkan di posisi " << posisi << endl;
    }
}

void hapusAwal() {
    cout << "╭──────────────────────────────────────────────────────────────╮" << endl;
    cout << "│                   HAPUS JADWAL PALING AWAL                   │" << endl;
    cout << "├──────┬──────────────┬───────────────────┬────────────────────┤" << endl;
    cout << "│ No   │ Kode         │ Tujuan            │ Status             │" << endl;
    cout << "├──────┼──────────────┼───────────────────┼────────────────────┤" << endl;
    if (isEmpty()) {
        cout << "│      │ --           │ Belum ada jadwal  │ --                 │" << endl;
        cout << "╰──────┴──────────────┴───────────────────┴────────────────────╯" << endl;
        cout << "Tidak ada jadwal yang bisa dihapus" << endl;
        return;
    } else {
        Jadwal *temp = head;
        int no = 1;
        while (temp != nullptr) {
            cout << "│ " << setw(4) << left << no++
                 << " │ " << setw(12) << left << temp->kodePenerbangan
                 << " │ " << setw(17) << left << temp->tujuan
                 << " │ " << setw(18) << left << temp->status << " │" << endl;
            temp = temp->next;
        }
    }
    cout << "╰──────┴──────────────┴───────────────────┴────────────────────╯" << endl;
    
    Jadwal *hapus = head;
    head = head->next;
    cout << "Jadwal dengan kode " << hapus->kodePenerbangan << " dihapus." << endl;
    delete hapus;
}

void updateStatus() {
    cout << "╭──────────────────────────────────────────────────────────────╮" << endl;
    cout << "│                  UPDATE STATUS PENERBANGAN                   │" << endl;
    cout << "├──────┬──────────────┬───────────────────┬────────────────────┤" << endl;
    cout << "│ No   │ Kode         │ Tujuan            │ Status             │" << endl;
    cout << "├──────┼──────────────┼───────────────────┼────────────────────┤" << endl;
    if (isEmpty()) {
        cout << "│      │ --           │ Belum ada jadwal  │ --                 │" << endl;
        cout << "╰──────┴──────────────┴───────────────────┴────────────────────╯" << endl;
        cout << "Tidak ada jadwal" << endl;
        return;
    } else {
        Jadwal* temp = head;
        int no = 1;
        while (temp != nullptr) {
            cout << "│ " << setw(4) << left << no++
                 << " │ " << setw(12) << left << temp->kodePenerbangan
                 << " │ " << setw(17) << left << temp->tujuan
                 << " │ " << setw(18) << left << temp->status << " │" << endl;
            temp = temp->next;
        }
    }
    cout << "╰──────┴──────────────┴───────────────────┴────────────────────╯" << endl;
    
    string kode;
    cout << "Masukkan kode penerbangan: ";
    getline(cin, kode);
    Jadwal *current = head;
    while (current != nullptr && current->kodePenerbangan != kode) {
        current = current->next;
    }
    if (current == nullptr) {
        cout << "Kode penerbangan tidak ditemukan" << endl;
    } else {
        string statusBaru = pilihStatus();
        current->status = statusBaru;
        cout << "Status penerbangan " << kode << " berhasil diperbarui." << endl;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    int pilihan;
    do {
        clearScreen();
        cout << "╭──────────────────────────────────────────────────────────────╮" << endl;
        cout << "│                   FLIGHT SCHEDULE SYSTEM                     │" << endl;
        cout << "│              [ INAYAH RAMADHANI - 2409106068 ]               │" << endl;
        cout << "├──────────────────────────────────────────────────────────────┤" << endl;
        cout << "│ 1. Tambah Jadwal Penerbangan                                 │" << endl;
        cout << "│ 2. Sisipkan Jadwal Penerbangan                               │" << endl;
        cout << "│ 3. Hapus Jadwal Paling Awal                                  │" << endl;
        cout << "│ 4. Update Status Penerbangan                                 │" << endl;
        cout << "│ 5. Tampilkan Semua Jadwal                                    │" << endl;
        cout << "│ 0. Keluar                                                    │" << endl;
        cout << "╰──────────────────────────────────────────────────────────────╯" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1:
                clearScreen();
                tambahJadwal();
                break;
            case 2:
                clearScreen();
                sisipJadwal();
                break;
            case 3:
                clearScreen();
                hapusAwal();
                break;
            case 4:
                clearScreen();
                updateStatus();
                break;
            case 5:
                clearScreen();
                tampilkanJadwal();
                break;
            case 0:
                clearScreen();
                cout << "╭──────────────────────────────────────────────────────────────╮" << endl;
                cout << "│                        EXIT PROGRAM                          │" << endl;
                cout << "╰──────────────────────────────────────────────────────────────╯" << endl;
                return 0;
            default:
                cout << ">> Pilihan tidak valid <<" << endl;
        }
        cout << "Tekan ENTER untuk kembali ke menu...";
        cin.get();
    } while (pilihan != 0);
    return 0;

}
