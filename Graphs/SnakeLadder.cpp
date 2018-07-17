#include <iostream>
#include <list>
#include <map>
#include <queue>
#define INT_MAX 99999
using namespace std;

template <typename T>

class Graph{
    map<T , list<T> > adjList;
public:
    Graph(){

    }

    void addEdge(T u,T v,bool bidir = true){
        adjList[u].push_back(v);
        if(bidir)
            adjList[v].push_back(u);
    }

    void print(){
        for(auto i:adjList){
            cout<<i.first<<" -> ";
            for(T entry:i.second){
                cout<<entry<<",";
            }
            cout<<endl;
        }
    }

    int bfs(T src,T dest){
        queue<T> q;
        map<T,int> dist;
        map<T, T> parent;

        for(auto i:adjList)
            dist[i.first] = INT_MAX;

        q.push(src);
        dist[src] = 0;
        parent[src] = src;

        while(!q.empty()){
            T node = q.front();
            cout<<node<<" ";
            q.pop();

            for(int neighbour: adjList[node]){
                if(dist[neighbour] == INT_MAX){
                    q.push(neighbour);
                    dist[neighbour] = dist[node] + 1;
                    parent[neighbour] = node;
                }
            }
        }
        cout<<endl;
        T temp = dest;
        while(temp != src){
            cout<<temp<<"<--";
            temp = parent[temp];
        }
        cout<<src<<endl;

        return dist[dest];
    }
};
int main() {
    Graph<int> g;
    
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;

    //Lets fisrt construct the graph
    for(int u=0;u <= 36;u++){
        //At every node u can throw a dice
        for(int dice = 1;dice <=6 ;dice++){
            int v = u + dice + board[u+dice];
            g.addEdge(u,v,false);
        }
    }
    cout<<"The shortest path is "<<g.bfs(1,36)<<endl;

}

/*
The shortest path is 1 15 3 4 7 6 16 29 19 21 8 27 10 11 12 13 22 30 31 33 35 23 26 14 28 36 
36<--30<--29<--15<--1
4


Question
https://www.zenithsports.com.ng/shop/games/snake-ladder/
*/

