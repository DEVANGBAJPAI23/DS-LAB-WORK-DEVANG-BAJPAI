#include <iostream>
using namespace std;
int findfloor(int arr[] , int n, int x){
    int s = 0;
    int e = n - 1;
    int ans = -1 ;
    while(s <= e){
        int mid = (s + e)/2;
        if (arr[mid] <= x) {
			ans = arr[mid];
			s = mid + 1;
		}
		else {
			e = mid - 1; 
		}
    }
    return ans;
}
int findceil(int arr[], int n, int x){
    int s = 0;
    int e = n - 1;
    int ans = -1 ;
    while(s <= e){
        int mid = (s + e)/2;
        if (arr[mid] >= x) {
			ans = arr[mid];
            e = mid - 1; 
			
		}
		else {
			s = mid + 1;
		}
    }
    return ans;
}
int peak(int arr[], int n){
    int s = 0;
    int e = n - 1;
    if(arr[s] < arr[e]){
        return arr[e];
    }
    while(s < e){
        int mid = (s + e)/2;
        if(arr[s] >= arr[mid]){
           
            e = mid;
        }
        else{
            s = mid ;
        }
    }
    return arr[s];
}
int minimum(int arr[], int n){
    int s = 0;
    int e = n - 1;
    if(arr[s] < arr[e]){
        return arr[s];
    }
    while(s < e){
        int mid = (s + e)/2;
        if(arr[0] <= arr[mid]){
           
            s = mid + 1;
        }
        else{
            e = mid;
        }
    }
    return arr[s];
}
int main(){
    int n;
    cout << "enter the no. of elements = ";
    cin >> n;
    int arr[50];
    for(int i=0;i<n;i++){
        cin >> arr[i] ;
    }
    int x;
    cout << "enter the element for floor and ceil = " << endl;
    cin >> x;
    int floor = findfloor(arr, n, x);
    cout << "the floor of sorted of rotated array is " << floor << endl;
    int ceil = findceil(arr, n, x);
    cout << "the ceiling of sorted of rotated array is "<< ceil <<endl;
    int maxi = peak(arr, n);
    cout << "the peak element of rotated array is " << maxi << endl;
    int min = minimum(arr,n);
    cout << "the minimum of rotated array is " << min << endl;
}
