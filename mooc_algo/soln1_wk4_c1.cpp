#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <cstdlib>
#include <algorithm>
using namespace std;

vector<vector<int> > raw_graph;
vector<vector<int> > rev_graph;
vector<bool> visited;
stack<int> finished;
vector<vector<int> > scc;

void DFSRev(int node)
{
    visited[node] = true;
    for (unsigned int i = 0; i < rev_graph[node].size(); i++)
    {
        int neighbor = rev_graph[node][i];
        if (!visited[neighbor])
        {
            DFSRev(neighbor);
        }
    }
    finished.push(node);
}

void DFSFwd(int node)
{
    scc[scc.size() - 1].push_back(node);
    visited[node] = true;
    for (unsigned int i = 0; i < raw_graph[node].size(); i++)
    {
        int neighbor = raw_graph[node][i];
        if (!visited[neighbor])
        {
            DFSFwd(neighbor);
        }
    }
}


int main()
{    
    ifstream input;
    input.open("SCC.txt");
    string line;

    int numNodes = 875714;

    raw_graph.resize(numNodes);
    rev_graph.resize(numNodes);
    visited.resize(numNodes);
    while (!input.eof())
    {
        int from;
        int to;
        input >> from >> to;
        raw_graph[from - 1].push_back(to - 1);
        rev_graph[to - 1].push_back(from - 1);
    }
    input.close(); 

    // Step 1: 1st pass DFS on the reverse graph
    for (int i = 0; i < numNodes; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < numNodes; i++)
    {
        if (!visited[i])
        {
            DFSRev(i);
        }
    }

    // Step 2: 2nd pass DFS on the normal graph in 1st pass finishing time order
    for (int i = 0; i < numNodes; i++)
    {
        visited[i] = false;
    }

    while (finished.size() > 0)
    {
        int candidate = finished.top();
        finished.pop();
        if (!visited[candidate])
        {
            scc.push_back(vector<int>());
            DFSFwd(candidate);
        }
    }

    for (unsigned int i = 0; i < scc.size(); i++)
    {
        cout << scc[i].size() << endl;
    }

    return 0;
}
