#include <iostream>
#include <vector>
#include "graf.h"
using namespace std;

vector<Node> nodes;
 int nombrenodes;
//Constructora amb paràmetre.
Graf::Graf(vector<Node> nodesEnt){
    nodes = nodesEnt;
    nombrenodes = nodesEnt.size();
}
//Constructora buida (per introduir el graf, no permetrem graf buit)
Graf::Graf(){
    int n;
    cout << "Introdueix el nº de vèrtexs del graf:" << endl;
    cin >> n;
    vector<Node> nodesEntrada(n);
    for (int i = 0; i < n; ++i){
        cout << "Quantes arestes té el node " << i << "?" << endl;
        int m;
        cin >> m;
        Node N;
        N.id = i;
        N.valid = true;
        if (m > 0) cout << "Amb quins nodes és adjacent el node " << i << "?" << endl;
        vector<pair<int, bool>> adj(m);
        for (int j = 0; j < m; ++j){
            cout << j+1 << "/" << m << ": ";
            pair<int, bool> introduir;
            int a;
            cin >> a;
            introduir.first = a;
            introduir.second = true;
            adj[j] = introduir;
        }
        N.adjacents = adj;
        nodesEntrada[i] = N;
    }
    nodes = nodesEntrada;
    nombrenodes = nodesEntrada.size();
}

void Graf::afegirNode(Node n){
    nodes.push_back(n);
    for(int i = 0; i < n.adjacents.size(); ++i){
        if (n.adjacents[i].second){
            nodes[n.adjacents[i].first].adjacents.push_back(make_pair(n.id, true));
        }
    }
    nombrenodes++;
}

void Graf::eliminarNode(int id){
    nodes[id].valid = false;
    for(int i = 0; i < nodes[id].adjacents.size(); ++i){
        nodes[id].adjacents[i].second = false;
        //False totes les arestes que tinguin al node ID. Primer busquem dintre del node al que és adj.
        int nodeadj = nodes[id].adjacents[i].first;
        for(int j = 0; j < nodes[nodeadj].adjacents.size(); ++j){
            if( nodes[nodeadj].adjacents[j].first == id)  nodes[nodeadj].adjacents[j].second = false;
        } 
    }
    nombrenodes--;
}

//Consultores
int Graf::nNodes(){
    return nombrenodes;
}

vector<int> Graf::nodesadjacents(int nodeID){
    vector<int> ret;
    if (nodeID > nodes.size()) return ret;
    vector<pair<int, bool>> n = nodes[nodeID].adjacents;
    for (int i = 0; i < n.size(); ++i){
        if(n[i].second) ret.push_back(n[i].first);
    }
    return ret;
}

bool Graf::esValid(int n){
    return nodes[n].valid;
}
