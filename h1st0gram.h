#define BARSIZE 2 /* Required to be a multiple of 2 -- 1 block consists of '[' ']' */
#define MAXSIZE 6

int getData(int data[]);
int getMinData(int data[]);
int getMaxData(int data[]);
double getAveData(int data[]);

void fill_x_axis(int axis[], int n);
void fill_y_axis(int axis[], int n);

void fill_column(char table[][MAXSIZE*BARSIZE+1], int col, int height, int data[]);
void fill_table(char table[][MAXSIZE*BARSIZE+1], int col, int height, int data[]);

void print_x_axis(int axis[], int n);
void print_h1st0gram(int data[]);
