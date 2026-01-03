#pragma once

#include <iostream>
#include <string>

class LibMat
{
public:
    LibMat() {std::cout << "LibMat::LibMat() default constructor!\n";};
    virtual ~LibMat() {std::cout << "LibMat::~LibMat() destructor!\n";};
    virtual void print() const {std::cout << "LibMat::print() -- I am a LibMat object!\n";};
};

class Book : public LibMat
{
protected:
    std::string m_title;
    std::string m_author;
public:
    Book(const std::string& title, const std::string& author)
        : m_title(title), m_author(author) {
            std::cout << "Book::Book(" << m_title << ", " << m_author << ") constructor!\n";
        }
    virtual ~Book() {std::cout << "Book::~Book() destructor!\n";}
    const std::string& title() const {return m_title ;}
    const std::string& author() const { return m_author; }
    virtual void print() const override {
        std::cout << "Book::print() -- I am a Book object\n"
                  << "My title is: " << m_title << "\n"
                  << "My author is: " << m_author << std::endl;
    }
};

class AudioBook : public Book{

protected:
    std::string m_narrator;

public:
    AudioBook(const std::string& title, const std::string& author, const std::string& narrator)
        : Book(title, author), m_narrator(narrator){
        std::cout << "AudioBook::AudioBook(" << m_title << ", " << m_author << ", "
                  << m_narrator << ", " << ") constructor!\n";
    }

    virtual ~AudioBook(){ std::cout << "AudioBook::~AudioBook() destructor!\n"; }
    const std::string& narrator() const { return m_narrator; }
    virtual void print() const override{
        std::cout << "AudioBook::print() -- I am an AudioBook object!\n"
                  << "My title is: " << m_title << '\n'
                  << "My author is: " << m_author << '\n'
                  << "My narrator is: " << m_narrator << std::endl;
    }

};

void task_main();
