/*
Matthew Avallone
hw01
Caesar's Cypher
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void fillVector(ifstream& file, vector<string>& lines);
char decryptChar(char c, int shift);
void decryptString(string& encryptedS, int shift);

int main()
{
	ifstream ifs("encrypted.txt");
	if (!ifs) {
		cerr << "Failed to open encrypted\n";
		exit(1);
	}

	int shift;
	ifs >> shift; //finds the number for the cypher shift
	vector<string> lines;
	fillVector(ifs, lines);

	for (size_t index = lines.size()-1; index > 0; index--) {
		decryptString(lines[index], shift);
		cout << lines[index] << endl;
	}
	decryptString(lines[0], shift);
	cout << lines[0] << endl; //when I included zero in for loop size_t when out of range
}

void fillVector(ifstream& file, vector<string>& lines) {
	string encryptedLine;
	getline(file, encryptedLine);
	while (getline(file, encryptedLine)) {
		lines.push_back(encryptedLine);
	}
	file.close();
}

char decryptChar(char oldChar, int shift) {
	if (oldChar < 97 || oldChar > 122) { //checks to see if character is actually a lower case letter
		return oldChar;
	}
	char decryptedChar = oldChar - shift;
	if (decryptedChar < 97) { //adjusts shifted letter if not in range of lower case letter
		int diff = 97 - decryptedChar;
		decryptedChar = 123 - diff;
	}
	return decryptedChar;
}

void decryptString(string& encryptedLine, int shift) {
	for (size_t index = 0; index < encryptedLine.size(); index++) {
		encryptedLine[index] = decryptChar(encryptedLine[index], shift);
	}
}
