#include "Library.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Library::Library() { count = 0; }

void Library::addBook(std::string title, std::string author, std::string ISBN,
                      int copies) {
  if (copies <= 0) {
    throw logic_error("Shit can't be less than zero");
  }

  for (Book *book : books) {
    if (book->getISBN() == ISBN) {
      book->setTotalCopies(book->getTotalCopies() + copies);
      book->setAvailableCopies(book->getAvailableCopies() + copies);
      count += copies;
      return;
    }
  }

  Book *newBook = new Book(title, author, ISBN, copies);
  books.push_back(newBook);
  count += copies;
}

void ::Library::checkoutBook(string ISBN) {
  for (Book *book : books) {
    if (book->getISBN() == ISBN) {
      if (book->getAvailableCopies() > 0) {
        book->setAvailableCopies(book->getAvailableCopies() - 1);
        return;
      } else {
        throw logic_error("Shit doesn't exist for you to checkout");
      }
    }
  }
  throw logic_error("Shit don't exist");
}

// reutrn fuction

void ::Library::returnBook(string ISBN) {
  for (Book *book : books){
    if (book->getISBN() == ISBN) {
      if (book->getAvailableCopies() < book->getTotalCopies()) {
        book->setAvailableCopies(book->getAvailableCopies() + 1);
        return;
    } else {

      throw logic_error("everything has been returned ya cunt");
        }
    }
}


  throw logic_error("Shit doesn't exist");
}




void Library::print() {
  cout << "=========================" << endl;
  cout << "         Library         " << endl;
  cout << "=========================" << endl;

  for (unsigned int i = 0; i < books.size(); i++) {
    cout << "Title:  " << books[i]->getTitle() << endl;
    cout << "Author: " << books[i]->getAuthor() << endl;
    cout << "ISBN:   " << books[i]->getISBN() << endl;
    cout << "Copies: " << books[i]->getAvailableCopies() << "/"
         << books[i]->getTotalCopies() << endl;

    if (i < books.size() - 1) {
      cout << "-------------------------" << endl;
    }
  }

  cout << "=========================" << endl;
  cout << "Books: " << count << endl;
  cout << "=========================" << endl;
}
