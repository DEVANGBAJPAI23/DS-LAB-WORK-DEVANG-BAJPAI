#include <iostream>
using namespace std;

void towerofhanoi(int n, char from_rod, char auxi_rod, char to_rod){
    if(n == 0){
        return ;
    }
    towerofhanoi(n - 1, from_rod, to_rod, auxi_rod);
    cout << "Move disk "<< n <<" from rod "<<from_rod<<" to rod "<<to_rod<< endl;
    towerofhanoi(n - 1, auxi_rod, from_rod, to_rod);
}

int main(){
    int n;
    cout << "enter the no. of disc"<< endl;
    cin >> n;
    towerofhanoi(n , 'A', 'B', 'C');
    return 0;
}
