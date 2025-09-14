#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    float ipk;
};

int main() {
    Mahasiswa mahasiswa[4];
    
    for (int i = 0; i < 4; i++) {
        cout << "Mahasiswa ke-" << (i + 1) << ":" << endl;
        cout << "Nama: ";
        cin >> mahasiswa[i].nama;
        cout << "NIM: ";
        cin >> mahasiswa[i].nim;
        cout << "IPK: ";
        cin >> mahasiswa[i].ipk;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (mahasiswa[j].ipk > mahasiswa[j + 1].ipk) {
                Mahasiswa temp = mahasiswa[j];
                mahasiswa[j] = mahasiswa[j + 1];
                mahasiswa[j + 1] = temp;
            }
        }
    }

    cout << "\nSetelah diurutkan:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << ". Nama: " << mahasiswa[i].nama << endl;
        cout << "   NIM: " << mahasiswa[i].nim << endl;
        cout << "   IPK: " << mahasiswa[i].ipk << endl;
    }
    
    return 0;
}