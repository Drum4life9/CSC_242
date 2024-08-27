#include <iostream>
#include <vector>
#include "Graph.h"
#include <random>
#include <chrono>

using namespace std;

Graph gen_graph(int n, int d, bool directed) {
    static random_device rd;
    static default_random_engine re(rd());
    uniform_int_distribution<int> dist(0, n-1);
    uniform_int_distribution<int> weight(1, 10);
    Graph ret(n, directed);

    for (int i=0; i<n*d; ++i) {
        auto u = dist(re);
        auto v = dist(re);
        auto w = weight(re);
        ret.add_edge(u, v, w);
    }

    return ret;
}

int main() {
    /*
    int n = 27000;

    for (int i = 10000; i < n; i*=1.1) {
        Graph g = gen_graph(i, 2, false);
        auto start = chrono::system_clock::now();
        g.DFSIter(0);
        auto end = chrono::system_clock::now();
        auto diff = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << i << " iter took " << diff << "ms and recur took ";
        start = chrono::system_clock::now();
        g.DFSRecur(0);
        end = chrono::system_clock::now();
        diff = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << diff << "ms." << endl;
    }

     */

    /*
     * for some reason, I'm assuming its space related, my code crashes at about 40,000 node graph
     * on the recursion. The first few cases show that recursion is certainly faster than the iteration
     * version. I don't know why I can't test more.
     */

    Graph g(12, false);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(1, 4);
    g.add_edge(2, 3);
    g.add_edge(2, 5);
    g.add_edge(4, 5);
    g.add_edge(4, 8);
    g.add_edge(4, 9);
    g.add_edge(5, 6);
    g.add_edge(8, 10);
    g.add_edge(9, 11);
    g.add_edge(10, 11);

    vector<int> ret = g.get_articulations();
    for (int i : ret)
        cout << i << " is an articulation point." << endl;

}
