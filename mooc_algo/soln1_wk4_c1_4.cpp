# include <iostream>
# include <fstream>
# include <map>
# include <vector>
# include <string>
# include <stack>
# include <set>

using namespace std;

struct adjacency {
    int name;
    bool visited;
    vector<int> list;
};

typedef int option;

/* function prototype */
void store_file(map<int, adjacency>&, map<int, adjacency>&, string);
void print_adjacency_list(map<int, adjacency>&);
void dfs_loop(map<int, adjacency>&, map<int, adjacency>&, option);
void dfs(map<int, adjacency>&, map<int, adjacency>&, adjacency&, option, int&);
void print_stack();
void print_set();

stack<adjacency> stack_list;
multiset<int> size_set;

int main(int argc, char** argv) {

    map<int, adjacency> adjacency_list;
    map<int, adjacency> reverse_list;

    store_file(adjacency_list, reverse_list, "SCC.txt");
//    cout << "adjacency_list: " << endl;
//    print_adjacency_list(adjacency_list);
//    cout << "reverse_list: " << endl;
//    print_adjacency_list(reverse_list);

    dfs_loop(adjacency_list, reverse_list, 1);
    dfs_loop(adjacency_list, reverse_list, 2);

//    print_stack();
    print_set();

    return 0;
}

/* store the txt file into adjacency list */
void store_file(map<int, adjacency>& adjacency_list, map<int, adjacency>& reverse_list, string filename) {
    ifstream infile;
    infile.open(filename, ios::in);
    int tmp1, tmp2;
    map<int, adjacency>::iterator it;
    while (infile >> tmp1 >> tmp2) {
        /* tmp1->tmp2 */
        if (adjacency_list.find(tmp1) == adjacency_list.end()) {
            vector<int> tmp_vec(1, tmp2);
            adjacency adj_tmp;
            adj_tmp.visited = false;
            adj_tmp.name = tmp1;
            adj_tmp.list = tmp_vec;
            adjacency_list.insert(pair<int, adjacency>(tmp1, adj_tmp));
        }
        else {
            adjacency_list[tmp1].list.push_back(tmp2);
        }
        if (adjacency_list.find(tmp2) == adjacency_list.end()) {
            vector<int> tmp_vec(0);
            adjacency adj_tmp;
            adj_tmp.visited = false;
            adj_tmp.name = tmp2;
            adj_tmp.list = tmp_vec;
            adjacency_list.insert(pair<int, adjacency>(tmp2, adj_tmp));
        }
        if (reverse_list.find(tmp2) == reverse_list.end()) {
            vector<int> tmp_vec(1, tmp1);
            adjacency adj_tmp;
            adj_tmp.visited = false;
            adj_tmp.name = tmp2;
            adj_tmp.list = tmp_vec;
            reverse_list.insert(pair<int, adjacency>(tmp2, adj_tmp));
        }
        else {
            reverse_list[tmp2].list.push_back(tmp1);
        }
        if (reverse_list.find(tmp1) == reverse_list.end()) {
            vector<int> tmp_vec(0);
            adjacency adj_tmp;
            adj_tmp.visited = false;
            adj_tmp.name = tmp1;
            adj_tmp.list = tmp_vec;
            reverse_list.insert(pair<int, adjacency>(tmp1, adj_tmp));
        }
    }
    infile.close();
}

/* print the adjacency list */
void print_adjacency_list(map<int, adjacency>& adjacency_list) {
    for (map<int, adjacency>::iterator it = adjacency_list.begin(); it != adjacency_list.end(); ++it) {
        cout << it->first << ": ";
        for (int i = 0; i < it->second.list.size(); ++i) {
            cout << it->second.list[i] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void dfs_loop(map<int, adjacency>& adjacency_list, map<int, adjacency>& reverse_list, option op) {
    if (op == 1) {
        for (map<int, adjacency>::reverse_iterator rit = reverse_list.rbegin(); rit != reverse_list.rend(); ++rit) {
            if (rit->second.visited == false) {
                int sz = 0;
                dfs(adjacency_list ,reverse_list, rit->second, op, sz);
            }
        }
    }
    else if (op == 2) {
        while (!stack_list.empty()) {
            if (adjacency_list[stack_list.top().name].visited == false) {
                int sz = 1;
                dfs(adjacency_list, reverse_list, stack_list.top(), op, sz);
                size_set.insert(sz);
            }
            stack_list.pop();
        }
    }
}

void dfs(map<int, adjacency>& adjacency_list, map<int, adjacency>& reverse_list, adjacency& node, option op, int& sz) {
    node.visited = true;
    if (op == 1) {
        for (int i = 0; i < node.list.size(); ++i) {
            if (reverse_list[node.list[i]].visited == false)
                dfs(adjacency_list, reverse_list, reverse_list[node.list[i]], op, sz);
        }
        stack_list.push(adjacency_list[node.name]);
    }
    else if (op == 2) {
        adjacency_list[node.name].visited = true;
        for (int i = 0; i < node.list.size(); ++i) {
            if (adjacency_list[node.list[i]].visited == false) {
                ++sz;
                dfs(adjacency_list, reverse_list, adjacency_list[node.list[i]], op, sz);
            }
        }
    }
}

/* print the stack */
void print_stack() {
    while (!stack_list.empty()) {
        cout << " " << stack_list.top().name;
        stack_list.pop();
    }
    cout << endl;
}

/* print top 5 set */
void print_set() {
    cout << "top size: " << endl;
    int i = 0;
    for (auto rit = size_set.crbegin(); rit != size_set.crend(); ++rit) {
        ++i;
        cout << *rit << endl;
        if (i == 5)
            break;
    }
    while (i < 5) {
        cout << 0 << endl;
        ++i;
    }
}
