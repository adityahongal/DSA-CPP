#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// Check if array is sorted or not using recursion
bool checkSorted(int arr[], int size, int index){
    // Base case: if index reaches the end of array, return true
    if(index == size - 1)
        return true;
    
    bool currAns = false;
    bool recursionKaAns = false;
    //1 case solve
    if(arr[index+1] > arr[index]) 
    {
        currAns = true;
    }
    //Recursive call
    recursionKaAns = checkSorted(arr,size,index+1);

    return (currAns && recursionKaAns);                  // checks and return true if both cases are true

}

int main(){

    int arr[] = {10,20,30,40,50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index = 0;
    bool ans = checkSorted(arr,size, index);
    cout << "Array is sorted or not: " << ans << endl;


    return 0;
}