//organizing words from a file to see number of occurences
//file not included
//9/16/15

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void displayWords(const vector<Word>& words);

struct Word {
	string token;
	vector<int> positions;
};

size_t isTokenInCollection(const string& token, const vector<Word>& words) {
	for (size_t index = 0; index < words.size(); index++) {
		if (token == words[index].token) {
			return index;
		}
	}
	return words.size(); //allows us to return a size_t value that is impossible to be a position
}

int main() {
	ifstream jabberwocky("jabberwocky");
	if (!jabberwocky) {
		cerr << "Could not open jabberwocky\n";
	}

	vector<Word> words;
	string token;
	int position = 0;
	while (jabberwocky >> token) {
		size_t foundIndex = isTokenInCollection(token, words);
		if (foundIndex != words.size()) {
			words[foundIndex].positions.push_back(position); //adds position to Word object
		}
		else {
			Word wordToAdd;
			wordToAdd.token = token;
			wordToAdd.positions.push_back(position); //creates another Word and its position
			words.push_back(wordToAdd);
		}
		++position;
	}
	jabberwocky.close();

	void displayWords(const vector<Word>& words) {
		for (const Word& word : words) {
			cout << word.token << ": ";
			for (int i : word.positions) {
				cout << i << endl;
			}
		}
	}
}