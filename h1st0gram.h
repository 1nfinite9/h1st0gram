#define BARSIZE 2 /* Required to be a multiple of 2 -- 1 block consists of '[' ']' */
#define MAXSIZE 6

typedef struct result {
    int count;
    int sum;
    int min;
    int max;
    double mean;
    double median;
    double mode;
} RESULT;

typedef struct h1st0gram {
    int height;
    int width;
} HISTOGRAM;

typedef struct node {
    int value;
    struct node *next;
} INT_NODE;

int getData(int data[]);
int getMinData(int data[]);
int getMaxData(int data[]);
double getAveData(int data[]);

void updateResult(RESULT *set, INT_NODE *n);
void printResult(RESULT *set);

int getRawData(INT_NODE *p);
void printRawData(INT_NODE *p);

void fill_x_axis(INT_NODE *p);
void fill_x_axis_v1(int axis[], int n);
void fill_y_axis(int axis[], int n);

void fill_column(char table[][MAXSIZE*BARSIZE+1], int col, int height, int data[]);
void fill_table(char table[][MAXSIZE*BARSIZE+1], int col, int height, int data[]);

void print_x_axis(int axis[], int n);
void print_h1st0gram(INT_NODE *n);
void print_h1st0gram_v1(int data[]);
