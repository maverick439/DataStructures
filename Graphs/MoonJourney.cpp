//Hackerrank Jouney to Moon problem

#include <iostream>
#include <list>
#include <map>
#include <vector>
using namespace std;
vector<int> v;
template <typename T>
class Graph {
    map <T,list<T>>l;
public: 
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void dfs_helper(T src, map<T,bool>&visited){
        visited[src] = true;
        v.push_back(src);
        //cout<<src<<" ";
        for (T nbr : l[src]){
            if (!visited[nbr]){
                dfs_helper(nbr,visited);
            }
        }
    }
    void dfs(){
        map<T,bool> visited;
        //Mark all nodes as unvisited in the start
        for(auto p:l){
            T node = p.first;
            visited[node] = false; 
        }
        //To check the disconnected components
        int count = 0;
        for (auto p:l){
            T node = p.first;

            if (!visited[node]){
                //cout<<"Component"<<count<<"<--";
                dfs_helper(node,visited);
                count++;
                v.push_back(-1);
                //cout<<endl;
            }
        }
        
    }
};

int fact(int n) { 
    int res = 1; 
    for (int i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 

int main() {
    int n; int p;
    int x,y;
    Graph <int>g;
    cin>>n>>p;
    for (int i=0;i<p;i++){
        cin>>x>>y;
        g.addEdge(x,y);
    }
    g.dfs();
    int disconnected = 0;
    int ans = fact(n) / (fact(n-2) * fact(2));
    for (int i=0;i<v.size();i++){
        if(v[i] == -1){
            ans = ans - fact(disconnected) / (fact(disconnected-2) * fact(2));
            disconnected = 0;
        }
        else{
            disconnected++;
        }
    }
    cout<<ans;
}
//TLE STILL EXISTING FOR SUBMISSION
