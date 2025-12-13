#include <iostream>
#include <vector>
#include <string>

#include "lecture.h"
#include "task.h"


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