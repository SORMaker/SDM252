#include <iostream>
#include <string>

class Entity_34{
    private:
        // int* m_x, m_y; In this situation, m_y is int type, not a pointer.
        int* m_x, *m_y; // Now, m_y is a pointer.
        mutable int var;
    public:
        // This method can only read the parameters in the calss.
        const int* const get_x() const{
            // m_x = 2; occurs an ERROR.
            
            // mutable allow us to mutate itself in a constant function; this is totally different from rust.
            var = 10;
            
            return m_x;

        }

        const int* const get_x() {
            
            return m_x;
        }

        void set_x(int x){
            *m_x = x;
        }
};

void print_entity(const Entity_34& e){
    // If the get_x() function didn't have the const keyword, then we would have an error here.
    // The reason is that we make e a const reference which means we do not want to modify e and its parameters.
    // But if we did not use the const keyword to constrain the Entity's method, the method may modify
    // the parameters unconsciously.
    // This defeats the purpose of using const. 
    // So that's why we often have two methods which have the same name, and one have const, the other do not have const.
    std::cout << e.get_x() << std::endl;
    
}

void lecture_34(){
    const int MAX_AGE = 90;

    const int* a = new int;
    // int const* a = new int;
    // *a = 2;
    a = (int*)&MAX_AGE;

    int* const b = new int;
    *b = 2;
    // b = (int*)&MAX_AGE;

    const int* const c = new int;

    std::cout << *a << std::endl;
    std::cout << *b << std::endl;  
    std::cout << *c << std::endl; 

    return;
}

class Entity_35
{
private:
    std::string m_name;
    mutable int m_debugcount = 0;
public:
    const std::string& get_name() const{
        m_debugcount++;
        return m_name;
    }

    Entity_35();
    ~Entity_35();
};

Entity_35::Entity_35()
{
}

Entity_35::~Entity_35()
{
}


void lecture_35(){
    // This lecture is about mutable.
    const Entity_35 e;
    e.get_name();

    int x = 8;
    auto f = [=]() mutable {
        x++;
        std::cout << x << std::endl;
    };

    f();

    std::cout << x << std::endl;

    return;
}

class Example
{
public:
    Example(){
        std::cout << "Create Example! " << std::endl;
    }

    Example(int x){
        std::cout << "Create Example with " << x << "!" << std::endl;
    }
};

class Entity_36
{
private:
    std::string m_name;
    int m_score;
    Example m_example;
public:
    const std::string& get_name() const{
        return m_name;
    }


    // If you use this initial method, you would find that example are created twice.
    // This results in wasted performance.
    // Entity_36()
    // {
    //     m_name = "Unknown";
    //     m_score = 10;
    //     m_example = Example(8);
    // }

    // On the other hand, if you choose member initialization lists, you would be surprised to find
    // that the example are created once!
    // So you shuold be using member initialization lists everywhere.
    Entity_36()
        :  m_name("Unknown"), m_score(0), m_example(8)
    {}

    Entity_36(const std::string& name)
        : m_name(name)
    {
    }
    
};


void lecture_36(){

    Entity_36 e0;
    // std::cout << e0.get_name() << std::endl;

    // Entity_36 e1("XIE");
    // std::cout << e1.get_name() << std::endl;


    return;
}


void lecture_main(){
    lecture_34();
    lecture_35();
    lecture_36();

    return;
}

class Triangular{
private:
    int m_length;
    int m_beg_pos;
    int m_next;
public:
    Triangular(int length = 1, int beg_pos = 1);
    Triangular(const Triangular& rhs);
    void print_init_status();
};

Triangular::Triangular(int length, int beg_pos)
    : m_length(length > 0 ? length : 1), m_beg_pos(beg_pos > 0 ? beg_pos : 1), m_next(m_beg_pos - 1)
{}

Triangular::Triangular(const Triangular& rhs)
    :   m_length(rhs.m_length), m_beg_pos(rhs.m_beg_pos), m_next(rhs.m_beg_pos - 1)
{}

void Triangular::print_init_status()
{
    std::cout << m_length << " , " << m_beg_pos << " , " << m_next << std::endl;
}

void task_main(){
 
    Triangular tri1;
    tri1.print_init_status();
    Triangular tri2(12);
    tri2.print_init_status();
    Triangular tri3(8, 3);
    tri3.print_init_status();
    Triangular tri4(tri3);
    tri4.print_init_status();

    return;
}

int main(int argc, char *argv[]){

    std::cout << argc << "," << argv[argc - 1] << std::endl;

    if (argc != 2)
    {
        std::cout << "Parameter Number Error" << std::endl;
        return 1;
    }

    std::string param = argv[1];

    if (param == "lmain")
    {
        lecture_main();
    }
    else if (param == "tmain")
    {
        task_main();
    }
    else
    {
        std::cout << "Parameter Name Error" << std::endl;
    }

    return 0;
}