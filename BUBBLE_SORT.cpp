#include <iostream>
using namespace std;
int main()

{
	int i, j, k, temp = 0, n, arr[50];
	cout << "enter the no. of elements = ";
	cin >> n;
	cout << "enter the elements = ";
	
	for(k = 0; k < n; k++ ){
		cin >> arr[i];
	}
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n-1; j++){
			if( arr[j] > arr[j +1] ){
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				
			}
		}
	}
	cout << "sorted list is as follows = " << endl;
	for(i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}
