#include "iostream"
#include "conio.h"

#define max 10
using namespace std;

struct queue {
	int data[max];
	int head;
	int tail;
	int key[max];
}bayu;

void Create() {
	bayu.head = bayu.tail = -1;
}

bool isEmpty() {
	if (bayu.tail == -1) {
		return true;
	}
	else { return false; }
}

bool isFull() {
	if (bayu.tail == 10) {
		return true;
	}
	else { return false; }
}

int insertItem() {
	int x, y;
	cout << "masukan key: ";
	cin >> x;
	cout << "masukan data: ";
	cin >> y;
	if (isEmpty() == true) {
		bayu.head = 0;
		bayu.tail = 0;
		bayu.data[bayu.tail] = y;
		bayu.key[bayu.tail] = x;
	}
	else {
		if (isFull() == true) {
			cout << "antrian sudah penuh";
		}
		else {
			bayu.tail++;
			bayu.data[bayu.tail] = y;
			bayu.key[bayu.tail] = x;
			//sorting data berdasarkan key
			int temp;
			int temp1;
			for (int i = 0; i < bayu.tail; i++) {
				for (int j = i + 1; j <= bayu.tail; j++) {
					if (bayu.key[i] < bayu.key[j]) {
						temp = bayu.key[i];
						temp1 = bayu.data[i];
						bayu.key[i] = bayu.key[j];
						bayu.data[i] = bayu.data[j];
						bayu.key[j] = temp;
						bayu.data[j] = temp1;
					}
				}
			}
		}
	}
	cout << "key dan data telah dimasukkan";
	for (int i = 0; i <= bayu.tail; i++) {
		return bayu.data[i];
		return bayu.key[i];

	}return bayu.tail;
}
int removeMin() {
	int temp;
	int temp1;

	int l = 0;
	int h = 1;
	if (bayu.tail == -1) {
		cout << "data sudah kosong" << endl;
	}
	else if (bayu.tail != -1) {
		do {
			bayu.key[l] = bayu.key[h];
			bayu.data[l] = bayu.data[h];
			l++;
			h++;
		} while (l <= bayu.tail);
		bayu.tail--;
		cout << "data head sudah keluar" << endl;
	}
	for (int i = 0; i <= bayu.tail; i++) {
		return bayu.data[i];
		return bayu.key[i];

	}return bayu.tail;
}

void clear() {
	bayu.tail = -1;
	cout << "antrian telah dihapus" << endl;
}

void cetak() {
	if (isEmpty() == true) {
		cout << "antrian kosong" << endl;
	}
	else {

		cout << "key" << "   data" << endl;
		for (int a = 0; a <= bayu.tail; a++) {
			cout << "[" << bayu.key[a] << "]   [" << bayu.data[a] << "]" << endl;
		}
	}

}

void size() {
	int panjang;
	if (isEmpty() == true) {
		cout << "antrian kosong" << endl;
	}
	else {
		panjang = bayu.tail;
		cout << "panjang antrian adalah: " <<++panjang  << endl;
		panjang = 0;
	}

}
void getMinKey() {
	cout << "key terkecil adalah: " << bayu.key[bayu.tail];
}
void getMinValue() {
	int temp1;
	for (int i = 0; i <= bayu.tail; i++) {
		for (int j = i + 1; j <= bayu.tail; j++) {
			if (bayu.data[i] > bayu.data[j]) {
				temp1 = bayu.data[i];
				bayu.data[i] = bayu.data[j];
				bayu.data[j] = temp1;
			}
		}
	}
	cout << "data terkecil adalah " << bayu.data[0];
}
int main() {
	Create();

	int pilih;

	do {
		cout << "program priority queue" << endl;
		cout << "1. insert item" << endl;
		cout << "2. remove item" << endl;
		cout << "3. clear item" << endl;
		cout << "4. size item" << endl;
		cout << "5. cetak item" << endl;
		cout << "6. cek key terkecil" << endl;
		cout << "7. cek data terkecil" << endl;
		cout << "8. exit" << endl;
		cout << "pilih nomor: ";
		cin >> pilih;
		switch (pilih) {
		case 1:
			insertItem();
			_getch();
			break;
		case 2:
			removeMin();
			_getch();
			break;
		case 3:
			clear();
			_getch();
			break;
		case 4:
			size();

			_getch();
			break;
		case 5:
			cetak();
			_getch();
			break;
		case 6:
			getMinKey();
			_getch();
			break;
		case 7:
			getMinValue();
			_getch();
			break;
		case 8:
			cout << "terimakasih, silahkan keluar" << endl;
			_getch();
			break;

		default:
			cout << "pilihan tidak tersedia, silahkan pilih nomor yang tersedia";
			_getch();
		}
		system("cls");
	} while (pilih != 9);

	_getch();
	return 0;
}
//08-05-2021 16.57 selesai