#pragma once

class Triangular_iterator {
    public:
        Triangular_iterator(int index) : m_index(index - 1) {} 
        bool operator==(const Triangular_iterator&) const; 
        bool operator!=(const Triangular_iterator&) const; 
        int operator*() const; 
        Triangular_iterator& operator++(); // prefix version 
        Triangular_iterator operator++(int); // postfix version

    private:
        void check_integrity() const; 
        int m_index; // an index into s_elems of the Triangular class 
} ;