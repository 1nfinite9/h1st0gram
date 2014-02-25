#include <stdio.h>
#include "h1st0gram.h"

#define TEST_MODE 1

int main(int argc, char **argv) {
    
    // #if TEST_MODE
    // // Initialize test data
    // int data[MAXSIZE] = { 2, 20, 37, 22, 6, 3 };
    
    // #else
    // // Receive input from user or open file
    // int data[MAXSIZE];
    // int cnt = getData(data);
    // printf("Inputted data count = %d\n", cnt);
    // #endif
    
    // Handle data and processing
    RESULT set = { 0, 0, 0, 0, 0, 0, 0 }; /*Initialize results to zero*/
    INT_NODE top;
    top.next = NULL;
    
    printf("Address of top      = [%p]\n", &top);
    printf("Address of top.next = [%p]\n", top.next);
    getRawData(&top);
    updateResult(&set, top.next);
    
    printRawData(top.next);
    
    printResult(&set);
    
    // updateResult(&set, top.next);
    // printResult(&set);
    
    // updateResult(&set, top.next);
    // printResult(&set);
    
    // Output to screen
    print_h1st0gram(top.next);

    return 0;
}
