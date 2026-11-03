/* Library Book Index Management using a Simple Index File */
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
// om kutwal SY-12 Roll No. 70

// Record stored in the data file
struct Book {
    int id;
    char title[50];
    char author[50];
};

// Entry stored in the index file
struct Index {
    int id;
    long pos;   // byte position of the record in the data file
};

vector<Index> indexTable;

// Load index file into memory
void loadIndex() {
    ifstream fin("books.idx", ios::binary);
    Index temp;
    while (fin.read((char*)&temp, sizeof(Index))) {
        indexTable.push_back(temp);
    }
    fin.close();
}

// Save index (kept sorted by id) to the index file
void saveIndex() {
    ofstream fout("books.idx", ios::binary | ios::trunc);
    for (size_t i = 0; i < indexTable.size(); i++) {
        fout.write((char*)&indexTable[i], sizeof(Index));
    }
    fout.close();
}

// Binary search in the index table, returns position or -1
int searchIndex(int id) {
    int low = 0, high = (int)indexTable.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (indexTable[mid].id == id)
            return mid;
        else if (indexTable[mid].id < id)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Read one record from the data file using its position
bool readBook(long pos, Book &b) {
    ifstream fin("books.dat", ios::binary);
    if (!fin) return false;
    fin.seekg(pos, ios::beg);
    fin.read((char*)&b, sizeof(Book));
    fin.close();
    return true;
}

void printBook(const Book &b) {
    cout << "Book ID : " << b.id << "\n";
    cout << "Title   : " << b.title << "\n";
    cout << "Author  : " << b.author << "\n";
}

// Add a new book: append to data file and insert entry in sorted index
void addBook() {
    Book b;
    memset(&b, 0, sizeof(Book));

    cout << "Enter Book ID: ";
    cin >> b.id;
    if (searchIndex(b.id) != -1) {
        cout << "Book ID already exists. Duplicate not allowed.\n";
        return;
    }
    cin.ignore();
    cout << "Enter Title: ";
    cin.getline(b.title, 50);
    cout << "Enter Author: ";
    cin.getline(b.author, 50);

    // Records are fixed size and appended in order,
    // so the new record starts after all existing ones
    long pos = (long)indexTable.size() * sizeof(Book);

    ofstream fout("books.dat", ios::binary | ios::app);
    fout.write((char*)&b, sizeof(Book));
    fout.close();

    // Insert the index entry at its sorted position
    Index entry;
    entry.id = b.id;
    entry.pos = pos;

    size_t i = 0;
    while (i < indexTable.size() && indexTable[i].id < entry.id)
        i++;
    indexTable.insert(indexTable.begin() + i, entry);

    saveIndex();
    cout << "Book added and index updated.\n";
}

// Search a book using the index file
void searchBook() {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;

    int idx = searchIndex(id);
    if (idx == -1) {
        cout << "Book not found.\n";
        return;
    }
    Book b;
    if (readBook(indexTable[idx].pos, b)) {
        cout << "\nBook found (record position: " << indexTable[idx].pos << " bytes)\n";
        printBook(b);
    }
}

// Display the index table
void displayIndex() {
    if (indexTable.empty()) {
        cout << "Index is empty.\n";
        return;
    }
    cout << "\nIndex File Contents:\n";
    cout << "Book ID\tPosition\n";
    for (size_t i = 0; i < indexTable.size(); i++) {
        cout << indexTable[i].id << "\t" << indexTable[i].pos << "\n";
    }
}

// Display all books in sorted order of Book ID (via index)
void displayAll() {
    if (indexTable.empty()) {
        cout << "No books available.\n";
        return;
    }
    cout << "\nAll Books (sorted by Book ID):\n";
    for (size_t i = 0; i < indexTable.size(); i++) {
        Book b;
        if (readBook(indexTable[i].pos, b)) {
            printBook(b);
            cout << "-------------------------\n";
        }
    }
}

int main() {
    loadIndex();
    int choice;

    do {
        cout << "\nom kutwal sy-12 roll no.70";
        cout << "\n===== Library Book Index Management =====\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book by ID (using Index)\n";
        cout << "3. Display Index File\n";
        cout << "4. Display All Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: displayIndex(); break;
            case 4: displayAll(); break;
            case 5: cout << "Program Terminated.\n"; break;
            default: cout << "Invalid Choice!\n";
        }
    } while (choice != 5);

    return 0;
}