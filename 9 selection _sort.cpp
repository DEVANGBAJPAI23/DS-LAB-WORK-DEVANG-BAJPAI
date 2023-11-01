# include <iostream>
using namespace std;
int main()

{
	int i, j, arr[50], n, minindex, temp;
	cout << "enter the length = ";
	cin >> n;
	cout << "enter the elements = ";
	for(i = 0; i < n; i++){
		cin >> arr[i];
	}
	int temp;
	for(i = 0; i < n; i++){
		minindex = i;
		for(j = i + 1; j < n; j++){
			if(arr[j] < arr[minindex]){
				minindex = j;
				
			}
		}
		temp = arr[minindex];
		arr[minindex] = arr[i];
		arr[i] = temp;
		
	}
	cout << "sorted list is = " ;
	for(j = 0; j < n; j++){
		cout << arr[i] << " ";
	}
	return 0;
	
}
