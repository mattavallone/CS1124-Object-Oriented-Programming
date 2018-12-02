//Matthew Avallone
//CS1124
//Section C
//10/16/15

#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
public:
	PrintedMaterial(unsigned numPages) : numOfPages(numPages) {}

	virtual void displayNumPages() const = 0;

protected:
private:
	int numOfPages;
};

void PrintedMaterial::displayNumPages() const {
	cout << numOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
	Magazine(unsigned numPages) : PrintedMaterial(numPages) {}

	void displayNumPages() const {
		cout << "Magazine Length: ";
		PrintedMaterial::displayNumPages();
	}
protected:
private:
};

class Book : public PrintedMaterial {
public:
	Book(unsigned numPages) : PrintedMaterial(numPages) {}
	void displayNumPages() const {
		cout << "Book Length: ";
		PrintedMaterial::displayNumPages();
	}
	
protected:
private:
};

class TextBook : public Book {
public:
	TextBook(unsigned numPages, unsigned numOfIndexPages) : Book(numPages), numOfIndexPages(numOfIndexPages) {}

	void displayNumPages() const {
		cout << "Textbook Pages: ";
		PrintedMaterial::displayNumPages();
		cout << "Textbook Index pages: ";
		cout << numOfIndexPages << endl;
	}
protected:
private:
	unsigned numOfIndexPages;
};

class Novel : public Book {
public:
	Novel(unsigned numPages) : Book(numPages) {}

	void displayNumPages() const {
		cout << "Novel Length: ";
		PrintedMaterial::displayNumPages();
	}
protected:
private:
};

void printPrintedMaterial(PrintedMaterial& pm) {
	pm.displayNumPages();
}


int main()
{
	TextBook t(1738, 713);
	t.displayNumPages();
	Novel n(679);
	n.displayNumPages();
	Magazine m(78);
	m.displayNumPages();

	vector<PrintedMaterial*> printedMaterials;
	printedMaterials.push_back(&t);
	printedMaterials.push_back(&n);
	printedMaterials.push_back(&m);

	for (PrintedMaterial* pm : printedMaterials) {
		pm->displayNumPages();
	}
}
