#include <iostream>
#include <string>

using namespace std;

class Cryptography {
	string alphabet_lower = "abcdefghijklmnopqrstuvwxyz";
	string alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:

	int keycode(char s);
	string Caesar_encrypt(string text);
	string Caesar_decrypt(string text);
	string Vigenere_encrypt(string text);
	string Vigenere_decrypt(string text);
};