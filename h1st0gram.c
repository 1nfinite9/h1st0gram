#include <stdio.h>
#include "h1st0gram.h"

// void print_h1s(int *pDim)
// {
//     int tmpData[Y_SIZE][X_SIZE];

//     char row[30][10];
    
//     printf("%d\n", max);
    
    
// }

void print_h1s_singleLine()
{
    int line = 0;
    int y_num[Y_SIZE] = {15, 0, 0, 0, 0, 7, 0, 0, 0, 0};
    char singleLine[Y_SIZE][X_SIZE+1] = {
        {' ',' ',' ',' ',' ','O',' ',' ',' ',' ','\0'},
        {' ',' ',' ',' ',' ','O',' ',' ',' ',' ','\0'},
        {' ',' ',' ',' ',' ','O',' ',' ',' ',' ','\0'},
        {' ',' ',' ',' ','O','O',' ',' ',' ',' ','\0'},
        {' ',' ',' ',' ','O','O','O',' ',' ',' ','\0'},
        {' ',' ',' ',' ','O','O','O',' ',' ',' ','\0'},
        {' ',' ',' ',' ','O','O','O','O',' ',' ','\0'},
        {' ',' ',' ','O','O','O','O','O',' ',' ','\0'},
        {' ',' ','O','O','O','O','O','O',' ',' ','\0'},
        {'O',' ','O','O','O','O','O','O',' ','O','\0'},
    };
    while (line < Y_SIZE) {
        printf("%2d |%s\n", y_num[line], singleLine[line]);
        line++;
    }
    printf("    ----------\n");
}

// int maxDim(int *pDim)
// {
//     int i = 0;
//     int max = pDim[i];
    
//     while (i < SIZE - 1) {
//         if (max < pDim[i+1]) {
//             max = pDim[i+1];
//         }
//         i++;
//     }
    
//     return max;
// }

// int maxDim_1(int *pDim)
// {
//     int max = *pDim;
//     int i = 0;
    
//     while (i < 9) {
//         if (max < *(pDim+1)) {
//             max = *(pDim+1);
//         }
//         pDim++;
//         i++;
//     }
    
//     return max;
// }

