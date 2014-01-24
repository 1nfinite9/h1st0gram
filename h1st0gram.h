#define MAXSIZE 10
#define Y_SIZE 20

int get_data(int data[]);

void fill_x_axis(int axis[], int n);
void fill_y_axis(int axis[], int n);

void fill_column(char table[][MAXSIZE*2+1], int col, int data[]);
void fill_table(char table[][MAXSIZE*2+1], int col, int data[]);

void print_x_axis(int axis[], int n);
void print_h1st0gram(int data[]);
