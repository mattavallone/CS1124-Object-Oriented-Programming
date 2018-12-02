//Matthew Avallone
#include <iostream>
#include<string>
using namespace std;

void foo(int n) { //tests being able to follow call stack
	if (n > 3) {
		cout << n;
		foo(n / 2);
		cout << n;
		foo(n / 4);
		cout << n;
	}
	cout << n;
}

bool isPalidrome(string s) { //checks if word is a palidrome
	if (s.length() == 1) return true;
	if (s.substr(0, 1) == s.substr(s.length() - 1, 1)) {
		isPalidrome(s.substr(1, s.length() - 1));
	}
	else
		return false;
	return true;
}

void printCstring(char arr[], int size) { //prints cstring forwards
	if (size == 0) return;
	printCstring(arr, size - 1);
	cout << arr[size - 1];
}

int fact(int n) { //finds n factorial
	if (n == 0) return 1;
	return n * fact(n - 1);
}

int power(int x, int n) {
	if (n == 0) return 1;
	return x*power(x, n - 1);
}

int fib(int n) {
	if (n < 2) return n;
	return fib(n - 1) + fib(n - 2);
}

void towers(int n, char source, char target, char spare) {
	if (n == 0) return;
	towers(n-1, source, spare, target);
	cout << "Move " << n << " from " << source << " to " << spare << endl;
	towers(n-1, spare, target, source);
}

int countTowers(int n, char source, char target, char spare) {
	if (n == 0) return 0;
	return 2 * countTowers(n - 1, source, spare, target) + 1;
}

/*
int main() {
	//foo(4);
	//cout << endl;
	//cout << boolalpha << isPalidrome("rats live on no evil star");
	//const int size = 5;
	//char a[size] = { 'a', 'b', 'c', 'd', 'e' };
	//printCstring(a, size);
	//cout << fact(5);
	//cout << power(2, 5);
	//cout << fib(21);
	//cout << countTowers(8, 'a', 'b', 'c');
}
*/