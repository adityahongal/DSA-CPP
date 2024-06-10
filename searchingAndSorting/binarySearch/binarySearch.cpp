#include<iostream>
#include<vector>
using namespace std;

void basicBinarySearch(){
    int arr[] = {10,20,30,40,50,60,70,80,90,100};
    int size = 10;
    int start = 0;
    int end = size - 1;
    int mid = (start + end)/2;
    int target = 90;

    while( start <= end ){
        if( arr[mid] == target ){
            cout << "Element found at index " << mid << endl;
            return;
        }
        else if(target > arr[mid]){
            start = mid + 1;
            // check in right direction
        }
        else if( target < arr[mid] ){
            end = mid - 1;
            // check in left direction
        }
        // Update Mid
        mid = (start + end)/2;
    }
    cout << "Target not found" << endl;
}

int main(){

    basicBinarySearch();
    return 0;
}