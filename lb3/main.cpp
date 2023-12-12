#include <iostream>
#include <string>
#include "Cryptography.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	int crypto_algorithm = 0;
	cout << "������" << endl;
	cout << "1 - ���������� ������" << endl;
	cout << "2 - ���������� ��������" << endl;
	cout << "3 - ������������ ������" << endl;
	cout << "4 - ������������ ��������" << endl;
	cout << "5 - ����� ���������" << endl;
	string text;
	Cryptography crypt;
	while (crypto_algorithm != 5) {
		cout << "�������� ����� = ";
		cin >> crypto_algorithm;
		if (!cin) {
			cout << "Error";
			return 0;
		}
		if (crypto_algorithm == 5) cout << "����� ���������" << endl;
		else if (crypto_algorithm > 4 || crypto_algorithm < 1) cout << "������ �� ����������" << endl;
		else {
			cout << "������� �����" << endl;
			cin.ignore();
			getline(cin, text);
			if (crypto_algorithm == 1) {
				text = crypt.Caesar_encrypt(text);
			}
			else if (crypto_algorithm == 2) {
				text = crypt.Vigenere_encrypt(text);
			}
			else if (crypto_algorithm == 3) {
				text = crypt.Caesar_decrypt(text);
			}
			else if (crypto_algorithm == 4) {
				text = crypt.Vigenere_decrypt(text);
			}
		}
	}
	system("pause");
	return 0;
}