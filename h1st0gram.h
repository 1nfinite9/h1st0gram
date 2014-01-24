#define MAXSIZE 10

int get_data(int data[]);
int getMaxData(int data[]);

void fill_x_axis(int axis[], int n);
void fill_y_axis(int axis[], int n);

void fill_column(char table[][MAXSIZE*2+1], int col, int height, int data[]);
void fill_table(char table[][MAXSIZE*2+1], int col, int height, int data[]);

void print_x_axis(int axis[], int n);
void print_h1st0gram(int data[]);
