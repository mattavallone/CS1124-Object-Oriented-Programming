//Matthew Avallone

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	ifstream ifs("jabberwocky.txt");
	if (!ifs)
	{
		cerr << "Failed to open fileName\n";
		exit(1);
	}
	int lineCount = 0;
	string line = "";
	while (getline(ifs, line))
	{
		cout << line << endl;
		lineCount++;
	}

	cout << lineCount << endl;
	ifs.close();
	ifs.open("jabberwocky.txt");

	int wordCount = 0;
	string word = "";

	while (ifs >> word)
	{
		cout << word << endl;
		wordCount++;
	}
	cout << wordCount << endl;
}
