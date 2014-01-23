#include <stdio.h>
#include "h1st0gram.h"

int get_data(int data[])
{
    int i = 0;
    int cnt = 0;
    
    printf("Enter your data: ");
    while ((i < MAXSIZE) && (scanf("%d", &data[i]))!=EOF) {
        i++;
        cnt++;
        if (i < MAXSIZE) /*Stop printing if datacount already at 10*/
            printf("Enter your data: ");
    }
    
    if (i != MAXSIZE) { /*Refill data with zeroes if not full*/
        while (i < MAXSIZE) {
            data[i] = 0;
            i++;
        }
        printf("\n"); /*Add extra if data not full*/
    }
    return cnt;
}

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

void fill_column(char table[][MAXSIZE*2+1], int col, int data[])
{
    int left = col*2;
    int right = col*2+1;
    int i = Y_SIZE;
    
    int cnt = data[col]; /*cnt is for looping through the value of each column*/
    
    while (i >= 0) {
        if (cnt>=0) { /*If data is still necessary fill with [*/
            table[i][left] = '['; /*Fill left column*/
            table[i][right] = ']'; /*Fill right column*/
            cnt--;
        }
        else { /**/
            table[i][left] = ' ';
            table[i][right] = ' ';
        }
        i--; /*Go up one row*/
    }
}

void fill_table(char table[][MAXSIZE*2+1], int col, int data[])
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

void print_h1st0gram(int data[])
{
    int x_axis[MAXSIZE];
    int y_axis[Y_SIZE+1];
    int line = 0;
    char table[Y_SIZE][MAXSIZE*2+1] = {{' '}};
    
    fill_table(table, MAXSIZE, data);
    fill_x_axis(x_axis, MAXSIZE);
    fill_y_axis(y_axis, Y_SIZE);

    while (line < Y_SIZE) {
        printf("%2d │%s\n", y_axis[line], table[line]);
        line++;
    }
    printf(" %d └────────────────────\n", y_axis[line]);
    print_x_axis(x_axis, MAXSIZE);
}
