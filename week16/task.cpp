#include "task.h"
#include <algorithm>
#include <string>

void print(const LibMat& mat){
    std::cout << "in global print() : about to print mat.print()\n";

    mat.print();
}

void task_main(){

    // First Test
    {
        std::cout << "Creating a LibMat object to print()\n";
        LibMat libmat;
        print(libmat);
    }

    std::cout << "|----------------------------------------------------|\n";

    // Second Test
    {
        std::cout << "Creating a Book object to print()\n";
        Book book("The Castle", "Franz Kafka");
        print(book);
    }

    std::cout << "|----------------------------------------------------|\n";

    // Third Test
    {
        std::cout << "Creating an AudioBook object to print()\n";
        AudioBook audiobook("Man without Qualities", "Robert Musil", "Kenneth Meyer");
        print(audiobook);
    }

    std::cout << "|----------------------------------------------------|\n";
    
    {
        AudioBook audiobook("Mason and Dixon", "Thomas Pynchon", "Edwin Leonard");
        std::cout << "The title is: " << audiobook.title() << '\n'
                  << "The author is: " << audiobook.author() << '\n'
                  << "The narrator is:" << audiobook.narrator() << '\n';
    }
}