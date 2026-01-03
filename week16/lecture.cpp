#include "lecture.h"
#include <iostream>
#include <string>
#include <cstddef>
#include <vector>

namespace LECTURE40 {
    class Entity
    {
    private:
        std::string m_name;
        int m_age;
    public:
        Entity(const std::string &name)
            : m_name(name), m_age(-1) {}

       explicit Entity(int age)
            : m_name("Unknown"), m_age(age) {}
    };

    void PrintEntity(const Entity& entity){

    }

    int main(){

        //Entity a("XZY");
        Entity a = std::string("XZY");

        // Entity b(22);
        // After add explicit
        Entity b = Entity(22);

        // PrintEntity(22);
        PrintEntity(Entity(22));

        return 0;
    }

}

namespace LECTUER43 {

    class Entity
    {
    public:
        Entity(){
            std::cout << "Created Entity!" << std::endl;
        }
        ~Entity(){
            std::cout << "Destoryed Entity!" << std::endl;
        }
    };

    int* create_array(){
        int array[50];
        return array;
    }

    class ScopedPtr
    {
    private:
        Entity* m_ptr;
    public:
        ScopedPtr(Entity* ptr)
            : m_ptr(ptr) { 

            }
        ~ScopedPtr(){
            delete m_ptr;
        }
    };

    

    int main(){

        {
            ScopedPtr e = new Entity();
        }

        int* a = create_array();

        return 0;
    }
}

namespace LECTURE46 {

    class Entity{
        public:
            int x;
        public:
            void Print() const {std::cout << "Hello!" << std::endl;}
    };

    class ScopedPtr
    {
        private:
            Entity* m_obj;
        public:
            ScopedPtr(Entity* entity)
                : m_obj(entity) {

                }
            ~ScopedPtr(){
                delete m_obj;
            }

            Entity* get_object() {return m_obj;}
            Entity* operator->() {
                return m_obj;
            }
            const Entity* operator->() const {
                return m_obj;
            }
    };

    struct Vector3{
        float x,y,z;
    };

    int main(){

        int offset = offsetof(Vector3, y);
        std::cout << offset << std::endl;


        const ScopedPtr entity = new Entity();
        entity->Print();
        return 0;
    }
}

namespace LECTURE47 {

    struct Vertex{
        float x,y,z;
    };

    std::ostream& operator<<(std::ostream& stream, const Vertex& vertex){
        stream << vertex.x << "," << vertex.y << "," << vertex.z;
        return stream;
    }

    int main(){
        // Vertex* vertices = new Vertex[5];
        std::vector<Vertex> vertices;
        vertices.push_back({1,2,3});
        vertices.push_back({4,5,6});

        for (int i = 0; i < vertices.size(); i++){
            std::cout << vertices[i] << std::endl;
        }

        // This is actually copy vertices, if you don't want to copy vertices, you should use
        // &, and better add the const.
        for(Vertex v : vertices){
            std::cout << v << std::endl;
        }

        vertices.erase(vertices.begin() + 1);

        for(const Vertex& v : vertices){
            std::cout << v << std::endl;
        }

        vertices.clear();

        return 0;
    }
}

void lecture_main(){

    LECTURE40::main();
    LECTUER43::main();
    LECTURE46::main();
    LECTURE47::main();
}