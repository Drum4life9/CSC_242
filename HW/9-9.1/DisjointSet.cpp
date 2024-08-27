//
// Created by yarnall on 3/28/23.
//

#include "DisjointSet.h"

DisjointSet::DisjointSet(int sz)
        : data(sz, -1)
{}

void DisjointSet::join_components(int x, int y) {
    int r1 = find(x);
    int r2 = find(y);
    if (r1 == r2)
        return;
    if (data[r1] < data[r2]) {
        // component r1 is bigger
        data[r1] += data[r2];
        data[r2] = r1;
    }
    else {
        data[r2] += data[r1];
        data[r1] = r2;
    }
}

bool DisjointSet::same_component(int x, int y) {
    return find(x) == find(y);
}

int DisjointSet::size_component(int x) {
    int r = find(x);
    return -data[r];
}

int DisjointSet::num_components() {
    int num = 0;
    for (auto d: data) {
        if (d < 0)
            ++num;
    }
    return num;
}

int DisjointSet::largest_component_size() const {
    int largest = 0;
    for (auto d: data) {
        if (d < 0 && d < largest) {
            largest = d;
        }
    }
    return -largest;
}

int DisjointSet::find(int x) {
    if (data[x] < 0)
        return x;
    return data[x] = find(data[x]);
}