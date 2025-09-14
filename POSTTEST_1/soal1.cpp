#include <iostream>
using namespace std;

void cetakArray(int *arr, int ukuran) {
    for (int i = 0; i < ukuran; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void balikArray(int *arr, int ukuran) {
    int *awal = arr;
    int *akhir = arr + ukuran - 1;
    
    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main() {
    int bilanganPrima[7] = {2, 3, 5, 7, 11, 13, 17};
    
    cout << "Array sebelum dibalik: ";
    cetakArray(bilanganPrima, 7);
    
    balikArray(bilanganPrima, 7);
    
    cout << "Array setelah dibalik: ";
    cetakArray(bilanganPrima, 7);
    
    return 0;
}