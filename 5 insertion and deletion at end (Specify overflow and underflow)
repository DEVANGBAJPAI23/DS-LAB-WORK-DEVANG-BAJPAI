//insertion at the end
#include <iostream>
using namespace std;

int main() {
    int arr[100];
    int size;
    cout << "Enter the size of the array (maximum 100): ";
    cin >> size;

    if (size >= 100) {
        cout << "Overflow: The array is already full." << endl;
        return 1;
    }

    
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int value;
    cout << "Enter the value to insert at the end: ";
    cin >> value;

   
    arr[size] = value;

    size++; 

    cout << "Updated Array after insertion at the end: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
// deletion at the end
#include <iostream>
using namespace std;

int main() {
    int arr[100];
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size == 0) {
        cout << "Underflow: The array is already empty." << endl;
        return 1;
    }

   
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

   
    size--; 
    cout << "Updated Array after deletion at the end: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
