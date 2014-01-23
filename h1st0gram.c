#include <stdio.h>
#include "h1st0gram.h"

void fill_x_axis(int axis[], int n)
{
    int i = 1;
    while (i <= n) {
        axis[i-1] = i++;
    }
}

void fill_y_axis(int axis[], int n)
{
    int i = 0;
    while (n >= 0) {
        axis[i++] = n--;
    }
}

void fill_column(char table[][X_SIZE*2+1], int col, int data[])
{
    int left = col*2;
    int right = col*2+1;
    int i = Y_SIZE;
    
    int cnt = data[col];
    
    while (i > 0) {
        if (cnt>=0) { /*If data is still necessary fill with [*/
            table[i][left] = '['; /*Fill left column*/
            table[i][right] = ']'; /*Fill right column*/
            cnt--;
        }
        else { /**/
            table[i][left] = ' ';
            table[i][right] = ' ';
        }
        i--;
    }
}

void fill_table(char table[][X_SIZE*2+1], int col, int data[])
{
    int i = 0;
    int row = 0;
    while (i < col) {
        fill_column(table, i, data);
        i++;
    }
    
    while (row < Y_SIZE) { /*Fill last column with \0's*/
        table[row][i*2] = '\0';
        row++;
    }
}

void print_h1s_singleLine(int y_axis[], char table[][X_SIZE*2+1])
{
    int line = 0;
    while (line < Y_SIZE) {
        printf("%2d │%s\n", y_axis[line], table[line]);
        line++;
    }
    printf(" %d └────────────────────\n", y_axis[line]);
}

void print_x_axis(int x_axis[], int n)
{
    int i = 0;
    printf("    ");
    while (i < n) {
        printf("%d ", x_axis[i]);
        i++;
    }
    printf("\n");
}

