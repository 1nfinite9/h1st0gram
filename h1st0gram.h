#define X_SIZE 10
#define Y_SIZE 20

void fill_x_axis(int axis[], int n);
void fill_y_axis(int axis[], int n);

void fill_column(char table[][X_SIZE*2+1], int col, int data[]);
void fill_table(char table[][X_SIZE*2+1], int col, int data[]);

void print_x_axis(int axis[], int n);
void print_h1s_singleLine(int y_axis[], char table[][X_SIZE*2+1]);