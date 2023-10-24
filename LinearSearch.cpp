#include <iosream>
using namspace std;

int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
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
    int ans = linearsearch(arr, n, x);
    cout << "index of x is " << ans ;
    return 0;
}
