//
// Created by Brian Myers on 3/10/23.
//
#include <vector>

#ifndef INC_6_1_6_3_BINARYHEAP_H
#define INC_6_1_6_3_BINARYHEAP_H

template <typename Comparable>
class BinaryHeap
{
public:
    explicit BinaryHeap( int capacity = 100 );
    explicit BinaryHeap( const std::vector<Comparable> & items );

    bool isEmpty( ) const;
    const Comparable & findMin( ) const;

    void insert( const Comparable & x );
    void insert( Comparable && x );
    void deleteMin( );
    void deleteMin( Comparable & minItem );
    void makeEmpty( );

private:
    int currentSize; // Number of elements in heap
    std::vector<Comparable> array; // The heap array

    void buildHeap( );
    void percolateDown( int hole );
    void percolateUp( int hole );
};

template<typename Comparable>
void BinaryHeap<Comparable>::percolateUp(int hole) {
    //for insertion. Insert the element, move up the list if needed to.
    //hole is the element we are working with.
    //if root, we are done
    if (hole == 1) return;

    //get value for hole and it's parent
    Comparable v, p;
    v = array[hole];
    p = array[hole/2];

    //if value is less than parent, swap. If not, heap property is completed, break;
    if (v < p) {
        Comparable tmp = array[hole];
        array[hole] = std::move(array[hole/2]);
        array[hole/2] == std::move(tmp);
    }
    else return;

    //recurse moving up to parent (integer division, so it floors hole/2)
    percolateUp(hole / 2);

}

template<typename Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole) {
    //for deletion. Delete root, move hole downwards until you can fill in the element in the last spot
    //hole is elem we are working with
    //if hole * 2 is greater than currentSize, we have no children, so we are a leaf. Place element here.
    if (hole * 2 > currentSize) {
        array[hole] = std::move(array[currentSize]);
        return;
    }

    Comparable* val = &(array[currentSize]);
    const Comparable* lef = &(array[hole * 2]);


    //no right child
    if (hole * 2 + 1 > currentSize) {
        if (*val < *lef) {
            array[hole] = std::move(*val);
            return;
        }
    }

    const Comparable* rig = array[hole * 2 + 1];

    //two children, if smaller than both, move into hole
    if (*val < *rig && *val < *lef) {
        array[hole] = std::move(*val);
        return;
    }
    //else, find smaller, move up, and repeat
    if (*rig < *lef)
    {
        array[hole] = std::move(*rig);
        percolateDown(hole * 2);
    }
    else
    {
        array[hole] = std::move(*lef);
        percolateDown(hole * 2 + 1);
    }

}

#endif //INC_6_1_6_3_BINARYHEAP_H
