#include <stdio.h>
#include "h1st0gram.h"

int main() {
    
    // Initialize test data
    int data[10] = { 1, 0, 3, 5, 10, 15, 9, 6, 0, 1 };
    int *pData = data;
    int y_axis[Y_SIZE+1];
    int x_axis[X_SIZE];
    char table[Y_SIZE][X_SIZE*2+1] = {{' '}};
    
    // Receive input from user or open file
    fill_y_axis(y_axis, Y_SIZE);
    fill_x_axis(x_axis, X_SIZE);
    
    fill_table(table, X_SIZE, data);
    
    // Handle data and processing
    
    // Output to screen
    print_h1s_singleLine(y_axis, table);
    print_x_axis(x_axis, X_SIZE);
    
    return 0;
}
