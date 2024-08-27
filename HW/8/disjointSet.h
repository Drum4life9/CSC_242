//
// Created by Brian Myers on 3/28/23.
//

#ifndef INC_8_DISJOINTSET_H
#define INC_8_DISJOINTSET_H

#include <vector>

//SET BY SIZE IMPLEMENTATION
class disjoint_set {

    disjoint_set(int num) : data(new int[num]), sz{num} {}
    disjoint_set(int num, int* d) : sz{num} {
        for (int i = 0; i < num; ++i) data[i] = d[i];
    }



    void unionSet(int n1, int n2) {
        if (n1 > sz || n2 > sz) return;
        //n1 tree smaller than n2
        if (data[n1] > data[n2]) {
            data[n2] += data[n1];
            data[n1] = n2;
        }
        else {
            data[n1] += data[n2];
            data[n2] = n1;
        }
    }

    //returns the set that it is a part of
    //also compresses path
    int find(int n) {
        if (n > sz || n < 0) return -1;
        int par = data[n];
        int fin;
        std::vector<int> visited;
        while (true) {
            if (data[par] == -1) {
                fin = par;
                break;
            }
            visited.push_back(par);
            par = data[par];

        }
        for (int i : visited)
            data[i] = fin;

        return fin;
    }

    int numSets() const {
        int count = 0;
        for (int i = 0; i < sz; ++i)
            if (data[i] < 0) ++count;
        return count;
    }
    int largestSet() const {
        int max = 0;
        for (int i = 0; i < sz; ++i)
            if (data[i] < max) max = data[i];
        return max * -1;
    }


private:
    int* data;
    int sz;
};

#endif //INC_8_DISJOINTSET_H
