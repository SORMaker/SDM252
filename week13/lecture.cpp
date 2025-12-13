#include "lecture.h"
#include <iostream>


void lecture_21(){
    // static
    // A static variable can only be seen at the identical .cpp file, which means its scope is 
    // limited to the .cpp file where it is decleared.
    static int s_variable = 10;
    std::cout << s_variable << std::endl;
}

struct Entity{
    int x;
    int y;

    // static method can not access the non-static variable.
    // Because static method doesn't have the 'this' pointer.
    // 'this' pointer can help us distinguish different instances.
    // static void Print(){
    //     std::cout << x << " , " << y << std::endl;
    // }
    void Print(){
        std::cout << x << " , " << y << std::endl;
    }
};

void lecture_22(){
    // static in class and struct

    // Suppose we have a static variable 'x' in a class or a struct, then we create some different
    // instances, their static variable 'x' point to the same memory, they are same. 
    Entity e;
    e.x = 2; // when x is a static variable in class Entity, then e.x is equivalent to Entity::x.
    e.y = 3;
    Entity e1;
    e1.x = 5;
    e1.y = 10;

    // Entity::Print();
    e.Print();
    e1.Print();

}

/*
1. Global Configuration (Config Manager)
Scenario: Your program reads settings (like screen resolution or volume) from a file.
Why Singleton: It creates a single source of truth. If you have multiple managers, 
different parts of the program might read different or outdated settings, 
causing data inconsistency.

2. Logging System (Logger)
Scenario: Writing system logs to a single file (e.g., log.txt).
Why Singleton: It prevents resource contention. If multiple objects try to write to 
the file at the same time, the text will get mixed up or the file will be locked/corrupted.

3. Hardware Interface (Device Control)
Scenario: Controlling a specific physical device, like a robotic arm.
Why Singleton: It ensures safety. You cannot have two controllers sending 
conflicting commands (e.g., "move left" vs. "move right") to the same port.
The Singleton acts as the only "remote control" to prevent physical damage.
*/

class Singleton{
private:
    static Singleton* s_instance;
public:
    static Singleton& Get() {return *s_instance; }

    void Hello() {}
};

// Below is a more concise way to express the singleton.
/*
class Singleton{
public:
    static Singleton& Get() {
        static Singleton instance;
        return instance; 
    }

    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;

    void Hello() {}
}; 
*/

Singleton* Singleton::s_instance = nullptr;

void function(){
    static int i = 0;
    i++;
    std::cout << i << std::endl;
}

void lecture_23(){

    function();
    function();
    function();
    function();
    function();

    Singleton::Get().Hello();

}

// void print_position(const Position& p);

class Position{
public:
    int x, y;

    Position(int x, int y){
        // In this function, 'this' actually is Position *this 
        this->x = x;
        this->y = y;

        // print_position(*this);
    }

    int GetX() const{
        // In a const function, 'this' is const Position *this 
        
        return x;
    }

};

// void print_position(const Position& p){
//     // do some print.
// }

void lecture_42(){
    // this pointer


}

void lecture_main(){

    lecture_21();
    lecture_22();
    lecture_23();

}
