#include <stdio.h>
#include "h1st0gram.h"

int getData(int data[])
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

int getMinData(int data[])
{
    int min = data[0];
    int i = 1;
    while (i < MAXSIZE) {
        if (min > data[i]) {
            min = data[i];
        }
        i++;
    }
    return min;
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

double getAveData(int data[])
{
    int i, sum = 0;
    for (i = 0; i < MAXSIZE; i++) {
        sum += data[i];
    }
    
    return (double)sum / MAXSIZE;
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
    if (n % 2 != 0) /*Round-up axis value if maximum is odd number*/
        n++;
    
    while (n >= 0) {
        axis[i++] = n;
        n -= 2;
    }
}

void fill_column(char table[][MAXSIZE*BARSIZE+1], int col, int height, int data[])
{
    int left = col*BARSIZE;
    int right = col*BARSIZE+(BARSIZE-1);
    
    int cnt = (data[col]+1)/2; /*cnt is for looping through the value of each column*/
    
    while (height >= 0) {
        if (cnt>=0) { /*If data is still necessary fill two columns with []*/
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

void fill_table(char table[][MAXSIZE*BARSIZE+1], int col, int height, int data[])
{
    int i = 0;
    int row = 0;
    while (i < col) {
        fill_column(table, i, height, data);
        i++;
    }
    
    while (row < height) { /*Fill last column with \0's*/
        table[row][i*BARSIZE] = '\0';
        row++;
    }
}

void print_x_axis(int x_axis[], int n)
{
    int i = 0; /* Set i for first line */
    
    printf(" 0 └"); /* Print first line of X-Axis */
    while (i < MAXSIZE*BARSIZE) {
        printf("─");
        i++;
    }
    printf("\n");
    
    i = 0; /* Reset i for second line */
    printf("    "); /* Print second line with digits */
    while (i < n) {
        printf("%d ", x_axis[i]);
        i++;
    }
    printf("\n");
}

void print_h1st0gram(int data[])
{
    int max = getMaxData(data);
    int height = (max+1)/2;
    int x_axis[MAXSIZE];
    int y_axis[height]; /*Plus one row for printing last row with 0*/
    int line = 0;
    char table[height][MAXSIZE*BARSIZE+1];
    
    fill_table(table, MAXSIZE, height, data);
    fill_x_axis(x_axis, MAXSIZE);
    fill_y_axis(y_axis, max);

    while (line < height) {
        printf("%2d │%s\n", y_axis[line], table[line]);
        line++;
    }
    
    print_x_axis(x_axis, MAXSIZE);
}
