#include "lecture.h"
#include <iostream>
#include <string>

namespace LECTURE27 {

    class Entity
    {
    private:
        /* data */
    public:
        float X, Y;
        void Move(float xa, float ya){
            X += xa;
            Y += ya;
        }
    };

    class Player : public Entity
    {
    public:
        const char* Name;

        void print_name(){
            std::cout << Name << std::endl;
        }
    };

    void main(){

        Player p1;
        p1.print_name();
        p1.Move(5, 5);
        p1.X;

        std::cout << sizeof(Entity) << std::endl;
        std::cout << sizeof(Player) << std::endl;
    
    }
}

namespace LECTURE28{

    class Entity{
    public:
        virtual std::string name(){
            return "Entity";
        }

    };

    class Player : public Entity{
    private: 
        std::string m_name;

    public:
        Player(const std::string& name)
            : m_name(name) {}

        std::string name() override {
            return m_name;
        }

    };

    void print_name(Entity* e){
        std::cout << e->name() << std::endl;
    }

    void main(){
        Entity* e = new Entity;
        print_name(e);
        std::cout << e->name() << std::endl;

        Player* p = new Player("abc");
        print_name(p);
        std::cout << p->name() << std::endl;

        Entity* entity = p;
        std::cout << entity->name() << std::endl;

    }

}

namespace LECTURE29{

    class Printable{
        public:
            virtual std::string class_name() = 0;
    };

    class Entity : public Printable{
    public:
        // virtual std::string name() = 0;
        virtual std::string name() {return "Entity"; }
        std::string class_name() override {return "Entity"; }
    };

    class Player : public Entity{
    private: 
        std::string m_name;

    public:
        Player(const std::string& name)
            : m_name(name) {}

        std::string name() override {
            return m_name;
        }
        std::string class_name() override {return "Player"; }
    
    };

    void print_name(Entity* e){
        std::cout << e->name() << std::endl;
    }

    void m_print(Printable* p){
        std::cout << p->class_name() << std::endl;
    }

    void main(){
        Entity* e = new Entity;
        print_name(e);
        std::cout << e->name() << std::endl;

        Player* p = new Player("abc");
        print_name(p);
        std::cout << p->name() << std::endl;

        Entity* entity = p;
        std::cout << entity->name() << std::endl;

        m_print(e);
        m_print(p);
    }

}

namespace LECTURE68{

    class Base{
        public:
            Base() {std::cout << "Base Constructor \n";}
            virtual ~Base() {std::cout << "Base Destructor \n";}
    };

    class Derived : public Base{
        public:
            Derived() {m_Array = new int[5]; std::cout << "Derived Constructor \n";}
            ~Derived() {delete[] m_Array; std::cout << "Derived Destructor \n";}
        private:
            int* m_Array;
    };
    void main(){
        Base* base = new Base();
        delete base;
        std::cout << "----------------\n";
        Derived* derived = new Derived();
        delete derived;
        std::cout << "----------------\n";
        Base* poly = new Derived();
        delete poly;
    }
}

void lecture_main(){

    LECTURE27::main();
    LECTURE28::main();
    LECTURE29::main();
    LECTURE68::main();

}