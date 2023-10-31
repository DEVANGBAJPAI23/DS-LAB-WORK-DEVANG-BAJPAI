#include <iostream>
#include <list>
#include<unordered_map>
using namespace std;


class graph{
    public:
        unordered_map<int , list<int>> adj;

        void addedge( int u, int v, bool direction){
            adj[u].push_back(v);
            if(!direction){
                adj[v].push_back(u);
            }  //undirected edge so add the other way around as well.
        }

        void print(){
            for(auto i : adj){
                cout << i.first << "-> ";
                for(auto j : i.second){
                    cout << j << ", ";
                }
                cout << endl;
            }
        }
};

int main(){
    int n;
    cout << "enter the no of  nodes ";
    cin >> n;

    int m ;
    cout<<"Enter no of edges ";
    cin>>m;
    graph g;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g.addedge(u, v, 1);
    }
    g.print();
}
