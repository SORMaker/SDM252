#include "lecture.h"
#include <iostream>
#include <string>

struct Vector2{
    float x,y;

    Vector2(float x, float y)
    : x(x), y(y){}

    Vector2 Add(const Vector2& other) const{
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator+(const Vector2& other) const{
        return Add(other);
    }

    Vector2 Multiply(const Vector2& other) const{
        return Vector2(x * other.x, y * other.y);
    }

    Vector2 operator*(const Vector2& other) const{
        return Multiply(other);
    }

    bool operator==(const Vector2& other) const{
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2& other) const{
        return !(*this == other);
    }
};

std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
    stream << other.x << ", " << other.y;
    return stream;
}

void lecture_41(){
    // overload is very useful and important.
    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.5f, 1.5f);
    Vector2 result = position + speed * powerup;

    std::cout << result << std::endl;
}

class myString
{
private:
    char* m_buffer;
    unsigned int m_size;
public:
    myString(const char* string);
    myString(const myString& other);
    ~myString();
    friend std::ostream& operator<<(std::ostream& stream, const myString& string);
    char& operator[](unsigned int index);
};

myString::myString(const char* string)
{
    m_size = strlen(string);
    m_buffer = new char[m_size + 1];
    memcpy(m_buffer, string, m_size);
    m_buffer[m_size] = 0;
}

// If we set myString::myString(const myString& other) = delete;, which means we banned the deep copy.
myString::myString(const myString& other){
    
    // memcpy(this, &other, sizeof(myString));
    std::cout << "Copy Happend!" << std::endl;
    m_buffer = new char[m_size + 1];
    m_size = other.m_size;
    memcpy(m_buffer, other.m_buffer, m_size + 1);
}

myString::~myString()
{
    delete[] m_buffer;
}

char& myString::operator[](unsigned int index){
    return m_buffer[index];
}

std::ostream& operator<<(std::ostream& stream, const myString& string){
    stream << string.m_buffer;
    return stream;
}

void print_string(const myString& str){
    // If you implement a copy construction function, please make sure to use a const reference.
    // ALWAYS use const reference!
    std::cout << str << std::endl;
}

void lecture_45(){

    myString str1 = "abcdefg";
    myString str2 = str1;
    str2[2] = 'o';
    print_string(str1);
    print_string(str2);

    return;
}

void lecture_main(){

    lecture_41();
    lecture_45();

}
