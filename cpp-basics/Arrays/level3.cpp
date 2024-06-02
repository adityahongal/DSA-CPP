#include <climits>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void print2Darray(int arr[][2],int row,int col){        //In C++, when you pass a 2D array to a function, you need to specify the size of the second dimension explicitly
    //Row wise traversal
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void print2DArrayColWise(int arr[][4], int rows, int cols) {
  cout << "Printing Array" << endl;

  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      cout << arr[j][i] << " ";
    }
    cout << endl;
  }
}

void example1(){
    // Intializing 2D array
    // int arr[4][3];
    // int arr[3][2] = { 10,20,30,40};

    // cout << arr[2][1] << endl;

    int arr[3][2] = {
                    {10, 20},
                    {30, 40},
                    {50, 60}};

    int brr[][4] = {{10, 20, 30, 40}, {50, 60, 70, 80}};

    print2Darray( arr, 3, 2);
    print2DArrayColWise(brr, 2, 4);
}

int main() {

    example1();
    return 0;
}