#include <iostream>
#include <vector>
#include "graf.h"
#include <queue>
using namespace std;

queue<int> difusioIC(Graf G, double p, queue<int> &Activats){
    queue<int> ActTot = Activats;
    while(Activats.size() > 0){
        int node = Activats.front();
        Activats.pop();
        if(G.esValid(node)){
            vector<int> adj = G.nodesadjacents(node);
            for(int i = 0; i < adj.size(); ++i){
                if((double)rand()/ (double)RAND_MAX < p){
                    Activats.push(adj[i]);
                    ActTot.push(adj[i]);
                }
            }
        }
    }
    return ActTot;
}

int main(){
    Graf G;
    Node N;
    N.id = 4;
    N.adjacents.push_back(make_pair(0, true));
    N.valid = true;
    G.afegirNode(N);
    cout << "TEST: NOMBRENODES " << G.nNodes() << endl;
    vector<int> test_adj = G.nodesadjacents(4);
    for(int i = 0; i < test_adj.size(); i++){
        cout << test_adj[i] << " ";
    }
    cout << endl;
    G.eliminarNode(0);
    cout << "TEST: NOMBRENODES2 " << G.nNodes() << endl;
    test_adj = G.nodesadjacents(4);
    for(int i = 0; i < test_adj.size(); i++){
        cout << test_adj[i] << " ";
    }
    cout << endl;
}