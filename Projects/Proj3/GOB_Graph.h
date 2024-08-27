//
// Created by dasd on 4/22/2023.
//

#include <vector>
#include <string>
#include <map>
#include <unordered_map>

#ifndef PROJ3_GOB_GRAPH_H
#define PROJ3_GOB_GRAPH_H

class GOB {
public:
    explicit GOB(std::string fName);
    std::vector<std::pair<std::string, double>> influencerRanking() const;

private:
    struct edge {
        int src;
        int dest;

        edge(int s, int d) : src(s), dest(d) {};
    };
    struct vertex {
        int idx;
        std::vector<edge> edges;

        explicit vertex(int idxx = -1) : idx(idxx) {};
    };




private:
    void add_edge(int src, int dest);
    std::vector<int> shortest_path(int v) const;
    double get_score(int v) const;
    bool is_edge(int src, int dest) const;

private:
    std::vector<vertex> graph;
    std::unordered_map<std::string, int> map;
};

#endif //PROJ3_GOB_GRAPH_H
