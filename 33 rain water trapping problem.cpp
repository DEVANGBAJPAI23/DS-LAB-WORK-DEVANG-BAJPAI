#include <bits/stdc++.h> 
using namespace std; 


int maxWater(int arr[], int n) 
{ 
	
	int res = 0; 

	
	for (int i = 1; i < n - 1; i++) { 

		
		int left = arr[i]; 
		for (int j = 0; j < i; j++) 
			left = max(left, arr[j]); 

		
		int right = arr[i]; 
		for (int j = i + 1; j < n; j++) 
			right = max(right, arr[j]); 

		
		res = res + (min(left, right) - arr[i]); 
	} 

	return res; 
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
	cout<<"Maximum Water that can be formed is: ";
	cout << maxWater(arr, n); 

	return 0; 
}
