#include <iostream>
#include <vector>
#include "graf.h"
using namespace std;

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