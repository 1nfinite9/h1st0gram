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

int getMaxData(int data[])
{
    int max = data[0];
    int i = 1;
    while (i < MAXSIZE) {
        if (max < data[i]) {
            max = data[i];
        }
        i++;
    }
    return max;
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

void fill_column(char table[][MAXSIZE*2+1], int col, int height, int data[])
{
    int left = col*2;
    int right = col*2+1;

    int cnt = data[col]; /*cnt is for looping through the value of each column*/
    
    while (height >= 0) {
        if (cnt>=0) { /*If data is still necessary fill with [*/
            table[height][left] = '['; /*Fill left column*/
            table[height][right] = ']'; /*Fill right column*/
            cnt--;
        }
        else { /**/
            table[height][left] = ' ';
            table[height][right] = ' ';
        }
        height--; /*Go up one row*/
    }
}

void fill_table(char table[][MAXSIZE*2+1], int col, int height, int data[])
{
    int i = 0;
    int row = 0;
    while (i < col) {
        fill_column(table, i, height, data);
        i++;
    }
    
    while (row < height) { /*Fill last column with \0's*/
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
    int height = getMaxData(data);
    int x_axis[MAXSIZE];
    int y_axis[height+1]; /*Plus one row for printing last row with 0*/
    int line = 0;
    char table[height][MAXSIZE*2+1];
    
    fill_table(table, MAXSIZE, height, data);
    fill_x_axis(x_axis, MAXSIZE);
    fill_y_axis(y_axis, height);

    while (line < height) {
        printf("%2d │%s\n", y_axis[line], table[line]);
        line++;
    }
    printf(" %d └────────────────────\n", y_axis[line]);
    print_x_axis(x_axis, MAXSIZE);
}
