#ifndef NATSLIBRARY_H
#define NATSLIBRARY_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::vector;


class Date{
    private:
        int day;
        int month;
        int year;

    public:
        Date(int day = 0, int month = 0, int year = 0){
            this->day = day;
            this->month = month;
            this->year = year;
        }

        void set_day(int new_day){
            this->day = new_day;
        }

        void set_month(int new_month){
            this->month = new_month;
        }

        void set_year(int new_year){
            this->year = new_year;
        }

        string as_string() const{
            string s = std::to_string(this->day) + "/" + std::to_string(this->month) + "/" + std::to_string(this->year);
            return s;
        }

};


class Identity{

    private:
        string name;
        string surname;
        Date* birthday;
    
    public:
        Identity(string name, string surname, Date* birthday){
            this->name = name;
            this->surname = surname;
            this->birthday = birthday;
        }

        string get_name() const{
            return this->name;
        }

        string get_surname() const{
            return this->surname;
        }

        Date* get_date() const{
            return this->birthday;
        }

        string as_string() const{
            string s = this->name + " " + this->surname + " ("  + this->birthday->as_string()  + ")";
            return s;

        }

};


class Author{

    private:
        Identity* author;
        string genere;

    public:
        Author(Identity* id, char g){
            this->author = id;
            this->genere = g;
        }

        string get_surname() const{
            return this->author->get_surname();
        }

        string as_string() const{
            string s = "Author: " + this->author->as_string() + " genre: " + genere;
            return s;
        }

        void set_genere(string new_g){
            this->genere = new_g;
        }
};

class Publisher{
    
    private:
        string name;
        Identity* founder;
    
    public:
        Publisher(string name, Identity* founder){
            this->name = name;
            this->founder = founder;
        }

        string get_name() const{
            return this->name;
        }

        string as_string() const{
            string s = "Publishing house: " + this->name + ", founded by: " + this->founder->as_string();
            return s;
        }
};

class Book{

    private:
        string title;
        int publication_year;
        Publisher* publisher;
        vector <Author> authors;
        int n_book;

    public:
        Book(string title, int pubblication_year, Publisher* publisher, vector<Author> authors){
            this->title = title;
            this->publication_year = publication_year;
            this->publisher = publisher;
            this->authors = authors;
            this->n_book = 1;
        }

        void add_author(Author& new_author){
            this->authors.push_back(new_author);
        }

        int get_n_book() const{
            return this->n_book;
        }

        void set_n_book(int new_n){
            this->n_book = new_n;
        }

        string as_string() const{
            string s = "Title: " + this->title + " published in " + std::to_string(this->publication_year);
            s += "\n" + this->authors[0].as_string();
            s += "\n" + this->publisher->as_string();
            return s;
        }

        int get_p_year() const{
            return this->publication_year;
        }

        string get_title() const{
            return this->title;
        }

        string get_authors() const{
            string s;
            for(Author all : authors){
                s += all.get_surname();
                s += ", ";
            }
            s.resize(s.size() - 2);
            return s;
        }
        


};


class Library{

    private:
        vector<Book> books;
        int library_size;

    public:

        Library(){
            this->books = vector<Book> ();
            this->library_size = 0;
        }
        
        void add_book(Book& book){

            for(Book all : books){
                if(all.as_string() == book.as_string()){
                    book.set_n_book(book.get_n_book() + 1);
                    return;
                }
            }

            if(library_size == 0){
                books.push_back(book);
            }else{
                int count = 0;
                for(Book all : books){
                    if(all.get_p_year() > book.get_p_year()){
                        count ++;
                    }else{
                        books.insert(books.begin() + count, book);
                    }
                }
            }
            
        }

        Book* get_book_title(string title){
            
        }

        
};

#endif //NATSLIBRARY_H