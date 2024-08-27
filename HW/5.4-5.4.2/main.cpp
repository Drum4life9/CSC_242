#include <iostream>
#include "QuadraticProbing.h"
using namespace std;

// Simple main
int main( )
{
    //pt 1:
    /*
     * Given input {4371, 1323, 6173, 4199, 4344, 9679, 1989} and a hash function
        h(x) = x (mod () 10), show the resulting

        b)

        0) 9679
        1) 4371
        2) 1989
        3) 1323
        4) 6173
        5) 4344
        6)
        7)
        8)
        9) 4199

        c)

        0) 9679
        1) 4371
        2)
        3) 1323
        4) 6173
        5) 4344
        6)
        7)
        8) 1989
        9) 4199
     */

    //Pt. 2:
    //line 57 tells us that once we hit size/2, we need to rehash. To change the load factor, we need to divide the
    //constant that we divide by, for example, a load factor of 1 means we divide by 1, a load factor of 2 means
    //divide by .5, and so on.

    HashTable<int> h1;
    HashTable<int> h2;

    const int NUMS = 4000;
    const int GAP  =   37;
    int i;

    cout << "Checking... (no more output means success)" << endl;

    for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
        h1.insert( i );

    h2 = h1;

    for( i = 1; i < NUMS; i += 2 )
        h2.remove( i );

    for( i = 2; i < NUMS; i += 2 )
        if( !h2.contains( i ) )
            cout << "Contains fails " << i << endl;

    for( i = 1; i < NUMS; i += 2 )
    {
        if( h2.contains( i ) )
            cout << "OOPS!!! " <<  i << endl;
    }

    return 0;
}
