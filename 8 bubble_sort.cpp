#include <iostream>
using namespace std;
void bubble_sort(int arr[], int n){
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n - i - 1; j++){
			if( arr[j] > arr[j + 1] ){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				
			}
		}
	}
}
int main()

{
	int n, arr[50];
	cout << "enter the no. of elements = ";
	cin >> n;
	cout << "enter the elements = ";
	
	for(int k = 0; k < n; k++ ){
		cin >> arr[k];
	}
	
	bubble_sort(arr, n);
	cout << "sorted list is as follows = " << endl;
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}

	
