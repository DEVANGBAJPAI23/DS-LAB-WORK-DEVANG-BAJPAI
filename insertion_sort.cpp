#include<iostream>
using namespace std;

void insertSort(int a[],int key,int n){
   for(int i=0;i<n;i++){
       int temp=a[i];
       int j;
       for(j=i-1;j>=0;j--){
           if(temp<a[j]){
            a[j+1]=a[j];
           }
           else break;
       }
       a[j+1]=temp;
    }
    return;
}
int main()
{
    int key , n;
    int a[1000];
   	cout << "enter the no of data"<< endl;
   	cin >> n;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d", &a[i]);
    }
	cout << "sorted array = ";
    insertSort(a,key,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}

