#include <climits>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void print2Darray(int arr[][2],int row,int col){        //In C++, when you pass a 2D array to a function, you need to specify the size of the second dimension explicitly
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    // Intializing 2D array
    // int arr[4][3];

    // int arr[3][2] = { {10, 20},
    //                   {30, 40},
    //                   {50, 60}
    //                   };
    
    // int arr[3][2] = { 10,20,30,40};

    // cout << arr[2][1] << endl;

    int arr[3][2] = {
                    {10, 20},
                    {30, 40},
                    {50, 60}};
    print2Darray( arr, 3, 2);

    return 0;
}