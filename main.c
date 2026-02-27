#include <unistd.h>

int main(int args, char* argv[]) {
    int n = 1024;
    char input[1024];
    size_t result;
    for(;;){
        write(1, "mysh> ", 6);    
        result = read(0, input, n);
        if(result == 0){
            return 0;
        }else {
            write(1, input, result);
        }
    }    
}