#include <climits>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// void print2DArray(int drr[][4],int row,int col){        //In C++, when you pass a 2D array to a function, you need to specify the size of the second dimension explicitly
//     //Row wise traversal
//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
//             cout << drr[i][j] << " ";
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

// void print2DArrayDiagonalwise(int crr[][4], int rows, int cols) {
//   cout << "Printing Array" << endl;

//   // Method 1
// //   for(int i=0; i < rows; i++) {
// //     for(int j=0; j<cols;j++){
// //         if(i==j){
// //             cout << crr[i][j] << " ";
// //         }
// //     }
// //     cout << endl;
// //   }

//   // Method 2
//   for(int i=0; i < rows; i++) {
//     cout << crr[i][i] << " ";
//   }
// }

// void example1(){
//     // Intializing 2D array
//     // int arr[4][3];
//     // int arr[3][2] = { 10,20,30,40};

//     // cout << arr[2][1] << endl;

//     int arr[3][2] = {
//                     {10, 20},
//                     {30, 40},
//                     {50, 60}};

//     int brr[][4] = {{10, 20, 30, 40}, {50, 60, 70, 80}, {500, 600, 700, 800}};

//     // Printing diagonal 
//     // Can be done only in square matrix format
//     int crr[4][4] = {{10, 20, 30, 40}, {50, 60, 70, 80}, {500, 600, 700, 800}, {699,799,899,999}};

//     // Taking input for 2D array - row wise
//     int drr[3][4];

//     int rows = 3;
//     int cols = 4;
//     cout << "Enter elements for array input" << endl;
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             cout << "Enter Element for row: " << i << " and col: " << j << endl;
//             cin >> drr[i][j];
//         }
//      }

//     print2DArray(drr, 3, 4);

//     // print2DArray( arr, 3, 2);
//     // print2DArrayColWise(brr, 3, 4);
//     // print2DArrayDiagonalwise(crr, 4, 4);

// }

// Searching in 2D array using Linear search algorithm
bool search2DArray(int a[][4],int rows,int cols,int target){
    for( int i = 0; i < rows; i++){
        for( int j = 0; j < cols; j++){
            if(a[i][j] == target){
                return true;
            }
        }
    }
    return false;
}

void example2(){
    int a[3][4] = { {10,20,30,40},
                    {50,60,70,80},
                    {90,100,150,200}};
    int rows = 3;
    int cols = 4;
    int target = 400;
    bool ans = search2DArray(a,rows,cols,target);
    cout << "answer is: "<< ans << endl;
}

int main() {

    // example1();
    example2();
    return 0;
}