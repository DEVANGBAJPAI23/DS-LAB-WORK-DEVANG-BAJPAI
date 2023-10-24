// insert at beginning
#include <iostream>
using namespace std;

int main() {
    int arr[100];
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

   
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int value;
    cout << "Enter the value to insert at the beginning: ";
    cin >> value;

    
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

   

    size++; 

    cout << "Updated Array after insertion at the beginning: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
// deletion at beginning
#include <iostream>
using namespace std;

int main() {
    int arr[100];
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

   
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

   
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--; 

    cout << "Updated Array after deletion at the beginning: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
