#include <stdio.h>
#include "h1st0gram.h"

#define TEST_MODE 1

int main() {
    
    #if TEST_MODE
    // Initialize test data
    int data[MAXSIZE] = { 1, 0, 3, 5, 10, 15, 9, 6, 0, 1 };
    
    #else
    // Receive input from user or open file
    int data[MAXSIZE];
    int cnt = get_data(data);
    printf("Inputted data count = %d\n", cnt);
    #endif
    
    // Handle data and processing
    int cnt = getMaxData(data);
    printf("Max data counted by maxData() = %d\n", cnt);
    
    // Output to screen
    print_h1st0gram(data);

    return 0;
}
