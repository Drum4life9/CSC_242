#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <vector>
#include <tuple>

class graph_exception: public std::exception {};

class Graph {
private:
    struct edge {
        int src;
        int dest;
        double w;

        edge(int s, int d, double w);
    };
    struct vertex {
        int idx;
        std::vector<edge> edges;

        explicit vertex(int idx = -1);
    };

public:
    explicit Graph(int sz, bool is_directed = true);

    void add_edge(int src, int dest, double weight = 1.0);

    [[nodiscard]] bool is_edge(int src, int dest) const;

    [[nodiscard]] std::vector<int> out_degree() const;
    [[nodiscard]] std::vector<int> in_degree() const;

    [[nodiscard]] std::tuple<std::vector<int>, bool> top_sort() const;

    [[nodiscard]] std::vector<std::pair<int, int>> shortest_path(int v) const;

    void print_rep() const;

    [[nodiscard]] std::vector<std::pair<double, int>> dijkstra(int v) const;

    [[nodiscard]] Graph kruskal() const;

    std::vector<bool> DFSIter(int v) const;

    std::vector<bool> DFSRecur(int v) const;

    std::vector<int> get_articulations() const;

private:
    void dfs(int v, std::vector<bool>& lis) const;
    void assignNum(int v, int& count, std::vector<int>& lis, std::vector<bool>& vis, std::vector<int>& par) const;
    void assignLow(int v, std::vector<int>& num, std::vector<int>& par, std::vector<int>& low, std::vector<int>& ret) const;

private:
    std::vector<vertex> graph;
    bool directed;
};

#endif //GRAPHS_GRAPH_H