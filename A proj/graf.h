#ifndef GRAF_H
#define GRAF_H
#include<iostream>
#include <vector>
using namespace std;

struct Node {
    int id;
    bool valid;
    vector<pair<int, bool>> adjacents; 
};


class Graf{
    private:
        vector<Node> nodes;
        int nombrenodes;
    public:
        Graf(vector<Node> nodesEnt);
        Graf();
        void afegirNode(Node n);
        void eliminarNode(int id);
        int nNodes();
        vector<int> nodesadjacents(int nodeID);
        bool esValid(int n);
        int grauNode(int n);
};


#endif