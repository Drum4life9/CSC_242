//
// Created by yarnall on 3/28/23.
//

#ifndef CDS242_SP23_DISJSETS_DISJOINTSET_H
#define CDS242_SP23_DISJSETS_DISJOINTSET_H
#include <vector>

class DisjointSet {
public:
    /**
     * Initialize with size sz. Initially, all entries are in their own
     * components
     * @param sz
     */
    DisjointSet(int sz);

    /**
     * merge the components containing x and y
     * @param x
     * @param y
     */
    void join_components(int x, int y);

    /**
     * return true if x and y are in the same component
     * @param x
     * @param y
     * @return true if x and y are related
     */
    bool same_component(int x, int y);

    /**
     * return the size of the component containing x
     * @param x an element of the set
     * @return the size of the component containing x
     */
    int size_component(int x);

    /**
     *
     * @return the number of disjoint components in our set
     */
    int num_components();

    /**
     *
     * @return the size of the largest component
     */
    int largest_component_size() const;
private:

    /**
     *
     * @param x an element of our set
     * @return the "representative" of the component containing x.
     */
    int find(int x);

private:
    std::vector<int> data;
};


#endif //CDS242_SP23_DISJSETS_DISJOINTSET_H