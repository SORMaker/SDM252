#include <iostream>
#include <vector>
#include <limits>
using namespace::std;

void print_seq(vector<int> seq, string seq_name){
    cout << "The first " << seq.size()
         << " elements of the " << seq_name << " Series: \n\t";

    for(auto& element : seq){
        cout << element << ' ';
    }

    cout << '\n';

}

vector<int> gen_fibonacci_seq(int seq_size){
    vector<int> fibonacci_seq(seq_size);
    fibonacci_seq[0] = 0;
    fibonacci_seq[1] = 1;
    for(int i = 2; i < seq_size; i++){
        fibonacci_seq[i] = fibonacci_seq[i-1] + fibonacci_seq[i-2];
    }
    return fibonacci_seq;
}

vector<int> gen_lucas_seq(int seq_size){
    vector<int> lucas_seq(seq_size);
    lucas_seq[0] = 2;
    lucas_seq[1] = 1;
    for(int i = 2; i < seq_size; i++){
        lucas_seq[i] = lucas_seq[i-1] + lucas_seq[i-2];
    }
    return lucas_seq;
}

vector<int> gen_pell_seq(int seq_size){
    vector<int> pell_seq(seq_size);
    pell_seq[0] = 0;
    pell_seq[1] = 1;
    for(int i = 2; i < seq_size; i++){
        pell_seq[i] = 2 * pell_seq[i-1] + pell_seq[i-2];
    }
    return pell_seq;
}

vector<int> gen_triangular_seq(int seq_size){
    vector<int> triangular_seq(seq_size);
    triangular_seq[0] = 1;
    for(int i = 1; i < seq_size; i++){
        triangular_seq[i] = triangular_seq[i-1] + (i + 1);
    }

    return triangular_seq;
}

vector<int> gen_square_seq(int seq_size){
    vector<int> square_seq(seq_size);
    square_seq[0] = 1;
    for(int i = 1; i < seq_size; i++){
        square_seq[i] = (i + 1) * (i + 1);
    }

    return square_seq;
}

vector<int> gen_pentagonal_seq(int seq_size){
    vector<int> pentagonal_seq(seq_size);
    pentagonal_seq[0] = 1;
    for(int i = 1; i < seq_size; i++){
        pentagonal_seq[i] = pentagonal_seq[i-1] + (3 * (i + 1) - 2);
    }

    return pentagonal_seq;
}

void print_all(int seq_size){
    vector<int> fibonacci_seq = gen_fibonacci_seq(seq_size);
    vector<int> lucas_seq = gen_lucas_seq(seq_size);
    vector<int> pell_seq = gen_pell_seq(seq_size);
    vector<int> triangular_seq = gen_triangular_seq(seq_size);
    vector<int> square_seq = gen_square_seq(seq_size);
    vector<int> pentagonal_seq = gen_pentagonal_seq(seq_size);

    print_seq(fibonacci_seq, "Fibonacci");
    print_seq(lucas_seq, "Lucas");
    print_seq(pell_seq, "Pell");
    print_seq(triangular_seq, "Triangular");
    print_seq(square_seq, "Square");
    print_seq(pentagonal_seq, "Pentagonal");
}

void guess_seq_game(int seq_size){
    int elem_vals[] = {
        1,2,3, 3,4,7, 2,5,12, 
        3,6,10, 4,9,16, 5,12,22, 1,2
    };

    vector<int> elem_seq(elem_vals, elem_vals + seq_size);

    int cur_tuple = 0;
    int num_tries = 0;
    int num_right = 0;
    
    while(cur_tuple + 2 < seq_size){
        num_tries = 0;
        while(num_tries < 3){
            cout << "The first two elements of the sequence are: "
            << elem_seq[cur_tuple] << ", "
            << elem_seq[cur_tuple + 1]
            << "\nWhat is the next element? ";

            int user_guess = -1;
            while(!(cin >> user_guess)){
                cin.clear();
                
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Come on,please input a number : ";
            }
            num_tries++;

            if(user_guess == elem_seq[cur_tuple + 2]){
                cout << "Yes! You got it!\n";
                num_right++;
                break;
            }
            if(num_tries == 3){
                cout << "You have tried 3 times.\n";
                cout << "Let's try another sequence!\n";
                break;
            }

            cout << "Incorrect. Do you want to try again? (Y/N) ";
            char try_again = ' ';
            do{ 
                cin >> try_again;

                if(try_again != 'Y' && try_again != 'y'
                && try_again != 'N' && try_again != 'n'){
                    cout << "Come on,please input Y or N : ";
                }
            }while(try_again != 'Y' && try_again != 'y'
                   && try_again != 'N' && try_again != 'n');

            if(try_again == 'N' || try_again == 'n'){
                break;
            }
        }

        if(num_right == 6){
            cout << "Ohhhh! You have already guessed all sequences!\n";
            cout << "Goodbye!\n";
            break;
        }

        char try_another = ' ';
        cout << "Do you want to try another sequence? (Y/N) ";            
        do{
            cin >> try_another;

            if(try_another != 'Y' && try_another != 'y'
            && try_another != 'N' && try_another != 'n'){
                cout << "Come on,please input Y or N : ";
            }
        }while(try_another != 'Y' && try_another != 'y'
               && try_another != 'N' && try_another != 'n');

        if(try_another == 'N' || try_another == 'n'){
            cout << "Goodbye!\n";
            break;
        }
        else if(try_another == 'Y' || try_another == 'y'){
            cur_tuple += 3;
        }
    }
}

int main(){

    // const int seq_size = 18;

    // print_all(seq_size);

    // guess_seq_game(seq_size);

    char* buffer = new char[8];
    memset(buffer, 1, 8);

    char** ptr = &buffer;

    delete[] buffer;
    return 0;
}