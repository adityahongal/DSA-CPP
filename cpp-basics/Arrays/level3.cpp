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
// bool search2DArray(int a[][4],int rows,int cols,int target){
//     for( int i = 0; i < rows; i++){
//         for( int j = 0; j < cols; j++){
//             if(a[i][j] == target){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// void example2(){
//     int a[3][4] = { {10,20,30,40},
//                     {50,60,70,80},
//                     {90,100,150,200}};
//     int rows = 3;
//     int cols = 4;
//     int target = 400;
//     bool ans = search2DArray(a,rows,cols,target);
//     cout << "answer is: "<< ans << endl;
// }

// Creation on 2D array using vector
// void print2DVector(){
//     vector<vector<int> > arr(4,vector<int>(3,999));
//     int row = arr.size();
//     int col = arr[0].size();

//     for( int i=0; i<row; i++){
//         for( int j=0; j<col;j++){
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

void findMinimumIn2DArray(){
    int a[3][4] = {
      {10, 20, 30, 40},
      {50, 60, 7090, -2},
      {110, 2000, 30, 400909},
  };

  int min_number = INT_MAX;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      min_number = min(a[i][j],min_number);                           //Inbuilt function
    }
  }
  cout << "Minimum Number is " << min_number << endl;
}

void findMaximumIn2DArray() {
  int a[3][4] = {
      {10, 20, 30, 40},
      {50, 60, 7090, 80},
      {110, 2000, 30, 400909},
  };

  int max_number = INT_MIN;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
        max_number = max(a[i][j],max_number);                         //Inbuilt number
    }
  }
  cout << "Max Number is " << max_number << endl;
}

void printRowWiseSum(){
    int a[3][4] = {
      {10, 20, 30, 40},
      {50, 60, 70, 80},
      {110, 200, 300, 400},
  };

  for (int i = 0; i < 3; i++) {
    int rowSum = 0;                              //Start everytime with 0
    for (int j = 0; j < 4; j++) {
      rowSum += a[i][j];                         // rowSum = rowSum + a[i][j];
    }
    cout << "Sum of Row: " << i << " is: " << rowSum << endl;
  }
  cout << endl;
}

void printColWiseSum() {
  int a[3][4] = {
      {55, 20, 30, 40},
      {50, 60, 90, 80},
      {110, 23, 30, 99},
  };

  for (int j = 0; j < 4; j++) {
    int colSum = 0;
    for (int i = 0; i < 3; i++) {
      colSum += a[i][j];
    }
    cout << "Sum of Col: " << j << " is: " << colSum << endl;
  }
  cout << endl;
}

void diagonalSum() {
  int a[4][4] = {
      {10, 20, 30, 40},
      {50, 60, 7090, 80},
      {110, 2, 30, 9},
      {110, 2, 30, 2},
  };

  int diaSum = 0;
  for (int i = 0; i < 4; i++) {
    diaSum += a[i][i];
  }

  cout << "Diagonal Sum: " << diaSum << endl;
}

void transposeMatrix(){
    int b[3][3] = {{10, 20, 30,},
                    {11,12,13},
                    {31,32,33}};
    
    // int ans[100][100] = {0};

    // for(int i=0; i<3; i++){
    //     for(int j=0; j<3; j++){
    //         ans[i][j] = b[j][i];
    //     }
    // }

    // for(int i=0; i<3; i++){
    //     for(int j=0; j<3; j++){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // To transpose using same matrix - use swap function
    for(int i=0; i<3; i++){
        for(int j=i; j<3; j++){                  // j =i; cz we dont want to repeat the same ---> when i = 1, (0,1) = (1,0), This will repeat so we avoid
            swap(b[i][j],b[j][i]);
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){                           
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    // example1();
    // example2();
    // print2DVector();
    // findMinimumIn2DArray();
    // findMaximumIn2DArray();
    // printRowWiseSum();
    // printColWiseSum();
    // diagonalSum();
    transposeMatrix();
    return 0;
}