#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterToRight(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> s;
    
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[i] > arr[s.top()]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    
    return result;
}

vector<int> nextGreaterToLeft(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> s;
    
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[i] > arr[s.top()]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    
    return result;
}

vector<int> nearestSmallerToLeft(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> s;
    
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = arr[s.top()];
        }
        s.push(i);
    }
    
    return result;
}

vector<int> nextSmallerToRight(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> s;
    
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = arr[s.top()];
        }
        s.push(i);
    }
    
    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    
    vector<int> ngr = nextGreaterToRight(arr);
    vector<int> ngl = nextGreaterToLeft(arr);
    vector<int> nsl = nearestSmallerToLeft(arr);
    vector<int> nsr = nextSmallerToRight(arr);
    
    // Printing the results
    for (int i = 0; i < arr.size(); ++i) {
        cout << "Element " << arr[i] << ": NGR=" << ngr[i] << ", NGL=" << ngl[i] << ", NSL=" << nsl[i] << ", NSR=" << nsr[i] << endl;
    }
    
    return 0;
}
