#include <stdio.h>
#include "h1st0gram.h"

#define TEST_MODE 1

int main(int argc, char **argv) {
    
    #if TEST_MODE
    // Initialize test data
    int data[MAXSIZE] = { 2, 20, 37, 22, 6, 3 };
    
    #else
    // Receive input from user or open file
    int data[MAXSIZE];
    int cnt = getData(data);
    printf("Inputted data count = %d\n", cnt);
    #endif
    
    // Handle data and processing
    
    
    // Output to screen
    print_h1st0gram(data);

    return 0;
}
