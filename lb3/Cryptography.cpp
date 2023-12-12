#include "Cryptography.h"

int Cryptography::keycode(char s) {
	for (int i = 0; i < alphabet_lower.length(); i++) {
		if (s == alphabet_lower[i] || s == alphabet_upper[i]) return i;
	}
	return 0;
}

string Cryptography::Caesar_encrypt(string text) {
	int k;
	cout << "Введите сдвиг k = ";
	cin >> k;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] != ' ') {
			if (alphabet_lower.find(text[i]) != string::npos) {
				text[i] = alphabet_lower[(keycode(text[i]) + k) % alphabet_lower.length()];
			}
			else if (alphabet_upper.find(text[i]) != string::npos) {
				text[i] = alphabet_upper[(keycode(text[i]) + k) % alphabet_upper.length()];
			}
		}
	}
	cout << "Зашифрованный текст: " << text << endl;
	return text;
}

string Cryptography::Caesar_decrypt(string text) {
	int k;
	cout << "Введите сдвиг k = ";
	cin >> k;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] != ' ') {
			if (alphabet_lower.find(text[i]) != string::npos) {
				text[i] = alphabet_lower[(keycode(text[i]) + alphabet_lower.length() - k) % alphabet_lower.length()];
			}
			else if (alphabet_upper.find(text[i]) != string::npos) {
				text[i] = alphabet_upper[(keycode(text[i]) + alphabet_lower.length() - k) % alphabet_upper.length()];
			}
		}
	}
	cout << "Расшифрованный текст: " << text << endl;
	return text;
}

string Cryptography::Vigenere_encrypt(string text) {
	string key;
	cout << "Введите ключевое слово: ";
	cin >> key;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] != ' ') {
			if (alphabet_lower.find(text[i]) != string::npos) {
				text[i] = alphabet_lower[(keycode(text[i]) + keycode(key[i % key.length()])) % alphabet_lower.length()];
			}
			else if (alphabet_upper.find(text[i]) != string::npos) {
				text[i] = alphabet_upper[(keycode(text[i]) + keycode(key[i % key.length()])) % alphabet_upper.length()];
			}
		}
	}
	cout << "Зашифрованный текст: " << text << endl;
	return text;
}

string Cryptography::Vigenere_decrypt(string text) {
	string key;
	cout << "Введите ключевое слово: ";
	cin >> key;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] != ' ') {
			if (alphabet_lower.find(text[i]) != string::npos) {
				text[i] = alphabet_lower[(keycode(text[i]) + alphabet_lower.length() - keycode(key[i % key.length()])) % alphabet_lower.length()];
			}
			else if (alphabet_upper.find(text[i]) != string::npos) {
				text[i] = alphabet_upper[(keycode(text[i]) + alphabet_upper.length() - keycode(key[i % key.length()])) % alphabet_upper.length()];
			}
		}
	}
	cout << "Зашифрованный текст: " << text << endl;
	return text;
}