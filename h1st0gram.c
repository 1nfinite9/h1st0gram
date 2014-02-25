#include <stdio.h>
#include <stdlib.h>
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

void updateResult(RESULT *set, INT_NODE *n)
{
    while ( n!=NULL ) {
        if ( set->count!=0 ) {
            set->count++;
            set->sum += n->value;
            if (n->value < set->min) {
                set->min = n->value;
            }
            if (n->value > set->max) {
                set->max = n->value;
            }
            set->mean = (double)set->sum / set->count;
        }
        else {
            set->count++;
            set->sum = n->value;
            set->min = n->value;
            set->max = n->value;
            set->mean = n->value;
        }
        n = n->next;
    }
    printf("Results updated.\n");
}

void printResult(RESULT *set)
{
    printf("******************************\n");
    printf("* Data count      = %-8d *\n", set->count);
    printf("* Sum of all data = %-8d *\n", set->sum);
    printf("* Minimum data    = %-8d *\n", set->min);
    printf("* Maximum data    = %-8d *\n", set->max);
    printf("* Mean of data    = %-8.2g *\n", set->mean);
    // printf("* Median of data  = %-8.2f *\n", set->median);
    // printf("* Mode of data    = %-8.2f *\n", set->mode);
    printf("******************************\n");
}

int getRawData(INT_NODE *p)
{
    INT_NODE *ptop = p;
    INT_NODE *pnew;
    int input;
    int count;
    
    while ( scanf("%d", &input) != EOF ) {
        pnew = (INT_NODE*)malloc(sizeof(INT_NODE));
        
        pnew->value = input;
        pnew->next = ptop->next;
        ptop->next = pnew;
        count++;
    }
    
    return count;
}

void printRawData(INT_NODE *p)
{
    if ( p != NULL ) {
        printRawData(p->next);
        printf("[%p] %2d [%p]\n", p, p->value, p->next);
    }
}

void fill_x_axis(INT_NODE *p)
{
    RESULT result = { 0, 0, 0, 0, 0, 0, 0 };
    updateResult(&result, p);
    
    int x_axis_value[result.count];
    int x_axis_count[result.count];
    
    int i = 0;
    while ( i < result.count ) {
        x_axis_count[i] = 0;
        i++;
    }
    
    i = 0;
    while ( p != NULL ) {
        x_axis_value[i] = p->value;
        x_axis_count[i]++;
        p = p->next;
        i++;
    }
    
    i = 0;
    while ( i < result.count ) {
        printf("%d ", x_axis_value[i]);
        i++;
    }
    printf("\n");
    
    i = 0;
    while ( i < result.count ) {
        printf("%d ", x_axis_count[i]);
        i++;
    }
    printf("\n");
}

void fill_x_axis_v1(int axis[], int n)
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

void print_h1st0gram(INT_NODE *n)
{
    RESULT result = { 0, 0, 0, 0, 0, 0, 0 };
    updateResult(&result, n);
    
    HISTOGRAM h1st0gram = { 0, 0 };
    h1st0gram.height = (result.max+1)/2;
    
    int x_axis[MAXSIZE];
    int y_axis[h1st0gram.height]; /*Plus one row for printing last row with 0*/
    int line = 0;
    char table[h1st0gram.height][MAXSIZE*BARSIZE+1];
    
    fill_x_axis(n);
    // fill_table(table, MAXSIZE, height, data);
    // fill_x_axis(x_axis, MAXSIZE);
    // fill_y_axis(y_axis, max);

    // while (line < height) {
    //     printf("%2d │%s\n", y_axis[line], table[line]);
    //     line++;
    // }
    
    // print_x_axis(x_axis, MAXSIZE);
}

void print_h1st0gram_v1(int data[])
{
    int max = getMaxData(data);
    int height = (max+1)/2;
    int x_axis[MAXSIZE];
    int y_axis[height]; /*Plus one row for printing last row with 0*/
    int line = 0;
    char table[height][MAXSIZE*BARSIZE+1];
    
    fill_table(table, MAXSIZE, height, data);
    fill_x_axis_v1(x_axis, MAXSIZE);
    fill_y_axis(y_axis, max);

    while (line < height) {
        printf("%2d │%s\n", y_axis[line], table[line]);
        line++;
    }
    
    print_x_axis(x_axis, MAXSIZE);
}
