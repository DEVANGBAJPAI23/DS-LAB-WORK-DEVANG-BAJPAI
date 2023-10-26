#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {

    int start = 0;
    int end = size-1;

    int mid = start + (end-start)/2;

    while(start <= end) {

        if(arr[mid] == key) {
            return mid;
        }

        
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{ 
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
    
    return -1;
}


int main() { 

   int n;
   cout << "enter the no. of elements ";
    cin >> n;
   int arr[50];
   cout << "enter the elements ";
   for(int i = 0; i < n; i++){
    cin >> arr[i];
   }
   int x;
   cout << "enter the element to be search ";
   cin >> x;
    int ans = binarySearch(arr, n, x);
    cout << "index of x is " << ans ;
    return 0;
}
