//
// Created by dasd on 4/22/2023.
//

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <queue>
#include <unordered_map>

#include "GOB_Graph.h"

using namespace std;

bool GOB::is_edge(int src, int dest) const {
    for (const auto& e: graph[src].edges)
        if (e.dest == dest)
            return true;
    return false;
}

//source is the followee, dest is the follower
void GOB::add_edge(int src, int dest)
{
    if (src == dest || is_edge(src, dest)) return;
    graph[src].edges.emplace_back(src, dest);
}

vector<int> GOB::shortest_path(int v) const {
    std::vector<int> ret(graph.size(), -1);
    queue<int> q;

    ret[v] = 0;

    q.push(v);

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        for (const auto &e: graph[i].edges) {
            if (ret[e.dest] == -1) {
                ret[e.dest] = ret[i] + 1;
                q.push(e.dest);
            }
        }
    }
    return ret;
}

GOB::GOB(string fname) {
    //sets up file input
    string l = "../" + fname;
    ifstream in{l};
    string line;
    int num;
    in >> num;
    getline(in, line);

    vector<vertex> g;
    g.resize(num);
    for (int i = 0; i < num; ++i)
        g[i].idx = i;


    graph = g;

    while (getline(in, line)) {
        int colon = line.find(':');
        string follower = line.substr(0, colon);
        try {
            line = line.substr(colon + 2);
        } catch (std::out_of_range) {
            continue;
        }
        vector<string> followees;
        int space = 0;
        while (line.size() > 0 && space != -1) {
            space = line.find(' ');
            followees.push_back(line.substr(0, space));
            line = line.substr(space + 1);
        }
        if (map.find(follower) == map.end())
            map[follower] = map.size();
        for (string s : followees) {
            if (map.find(s) == map.end())
                map[s] = map.size();
            add_edge(map[s], map[follower]);
        }
    }
}

vector<pair<string, double>> GOB::influencerRanking() const {
    vector<pair<string, double>> ret(graph.size(), make_pair("", 0));
    for (vertex v : graph) {
        ret[v.idx].first = "";
        ret[v.idx].second = get_score(v.idx);
    }

    for (auto entry : map)
        ret[entry.second].first = entry.first;


    std::sort(ret.begin(), ret.end(), [](pair<string, double> p1, pair<string, double> p2){return p1.second > p2.second;});
    return ret;

    /*
     * This section discusses the time complexity for influencerRanking().
     *
     * For each vertex in the graph (aka |V|), I need to get their score. To get their score,
     * I determine the shortest path using BFS to every other vertex it is connected to. This takes
     * O(|E|+|V|), as our graph essentially holds adjacency lists. Each vertex holds a list of edges
     * connecting to another vertex. Another O(|V|) scan is done, along with several O(1) steps inside.
     * All together, getting an individual influencer score is O(|E|+|V|). This is done for every vertex
     * in the graph, meaning we do (|E|+|V|) work for |V| vertices. After this, I need to do another |V|
     * scan through the map in order to associate the string of the user with their respective score.
     * I then sort the return vector using std::sort, which is O(NlogN), or O(|V|log|V|). This is less
     * than |V^2| from calculating the total score for every person, so this can be omitted from the final
     * O(). The final time complexity is O(|E|*|V|+|V^2|) when we distribute e + v work among v vertices.
     *                                   ^^^^^^^^^^^^^^^^
     */
}

double GOB::get_score(int v) const {
    vector<int> allVerts = shortest_path(v);
    int reachable = 0;
    double avg = 0.0;
    for (int i : allVerts) {
        if (i != -1) {
            avg += i;
            ++reachable;
        }
    }
    avg /= reachable;
    return ((reachable - 1) * 1.0 / (graph.size() - 1)) / avg;
}