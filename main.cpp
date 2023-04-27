#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;
class Library;
class BOOK{ 
        string name;
        int id;
        int numberOfBook;
    public:
        BOOK():name(""), id(0), numberOfBook(0){};
        BOOK(string name, int id, int numberOfBook){
            this->name = name;
            this->id = id;
            this->numberOfBook = numberOfBook;
        }
        BOOK(const BOOK &b){
            name = b.name;
            id = b.id;
            numberOfBook = b.numberOfBook;
        }
        ~BOOK(){}

        friend Library;
};

class Library{
    public:
    vector<BOOK> book;
    public:
        void addBook(string name, int id, int numberOfBook);
        void deleteBook(int _id);
        void showBook();

};
void Library::addBook(string name, int id, int numberOfBook){
    bool index = false;
    for(int i = 0; i < this->book.size(); i++){
        if(this->book[i].id == id){
            index = true;
            break;
        }
    }
    if(index == false){
        BOOK new_Book;
        new_Book.name = name;
        new_Book.id = id;
        new_Book.numberOfBook = numberOfBook;
        this->book.push_back(new_Book);
    }else{
        cout << "This ID already exists. Don't ADD..." << endl;

    }
    
}
void Library::deleteBook(int _id){
    int index = -1;
    for(int i = 0; i < this->book.size(); i++){
        if(this->book[i].id == _id){
            index = i;
            this->book.erase(this->book.begin() + index);
            break;
        }
    }
    if(index == -1){
        cout << "Not Found..." << endl;
    }
}
void Library::showBook(){
    cout << "ID" << '\t' << "Name" << "\t\t" << "NumberOfBook" << endl;
    cout << "**" << '\t' << "****" << "\t\t" << "************" << endl;
    for(int i = 0; i < this->book.size(); i++){
        cout << this->book[i].id << '\t' << this->book[i].name << "\t\t"  << this->book[i].numberOfBook << endl;
    }
}
void menu(){
    cout << "****LIBRARY MANEGEMENT SYSTEM****" << endl;
    cout << "*********************************" << endl;
    cout << "[1] ADD BOOK" << endl;
    cout << "[2] DELETE BOOK" << endl;
    cout << "[3] SHOW BOOK" << endl;
    cout << "[4] QUIT" << endl;
}
int main(){
    Library lib;
    lib.addBook("Math", 1, 5);
    lib.addBook("Physics", 2, 2);
    lib.addBook("Econemic", 3, 8);

    int start = 1;
    int chose = 0;
    string clear;
    while(start != 0){
        menu();
        cout << "ENTER CHOSE: ";
        cin >> chose;
        string _name;
        int _id;
        int _numberOfBook;
        switch(chose){
        case 1:
            cout << "Book Name: ";
            cin.ignore();
            getline(cin, _name);
            cout << "ID: ";
            cin >> _id;
            cout << "Number Of Book: ";
            cin >> _numberOfBook;
            lib.addBook(_name, _id, _numberOfBook);

            break;
        case 2:
            cout << "Enter ID, You Want To Delete: ";
            cin >> _id;
            lib.deleteBook(_id);
            break;
        case 3:
            lib.showBook();
            break;
        case 4:
            start = 0;
            cout << "QUIT PROGRAM." << endl;
            break;
        default:
            break;
        }
        if(getch()){
            system("cls");
        }
        
    }



    return 0;
}