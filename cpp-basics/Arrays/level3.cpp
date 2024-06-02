#include <climits>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// void print2Darray(int arr[][2],int row,int col){        //In C++, when you pass a 2D array to a function, you need to specify the size of the second dimension explicitly
//     //Row wise traversal
//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// void print2DArrayColWise(int brr[][4], int rows, int cols) {
//   cout << "Printing Array" << endl;

//   for (int j = 0; j < cols; j++) {                                  // Interchange Loops of i to Loops of j
//     for (int i = 0; i < rows; i++) {
//       cout << brr[i][j] << " ";
//     }
//     cout << endl;
//   }
// }

void print2DArrayDiagonalwise(int crr[][4], int rows, int cols) {
  cout << "Printing Array" << endl;

  // Method 1
  for(int i=0; i < rows; i++) {
    for(int j=0; j<cols;j++){
        if(i==j){
            cout << crr[i][j] << " ";
        }
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

    int brr[][4] = {{10, 20, 30, 40}, {50, 60, 70, 80}, {500, 600, 700, 800}};

    // Printing diagonal 
    // Can be done only in square matrix format
    int crr[4][4] = {{10, 20, 30, 40}, {50, 60, 70, 80}, {500, 600, 700, 800}, {699,799,899,999}};

    // print2Darray( arr, 3, 2);
    // print2DArrayColWise(brr, 3, 4);
    print2DArrayDiagonalwise(crr, 4, 4);

}

int main() {

    example1();
    return 0;
}