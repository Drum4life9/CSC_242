#include <chrono>

using namespace std::chrono;

int main() {
    /* 2.5
     *
     * f(N) = N
     * g(N) = N^(3sin(N))
     *
     * Since sin is an oscillating function (between) -1 and 1, g(N)
     * will either be N^3 or N^-3. N^-3 < N < N^3 as N goes to infinity,
     * so neither statement will always be true
     */

    int n = 10000;

    //2.7
    auto start = high_resolution_clock::now();
    int sum = 0;
    for( int i = 0; i < n; ++i )
        ++sum;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    //a) O(N)
    //b) n = 100: 0
    //   n = 1000: 0
    //   n = 10000: 6
    //c) Very fast, seems about right. So quick it couldn't even time the first few


    start = high_resolution_clock::now();
    int sum2 = 0;
    for( int i = 0; i < n; ++i )
        for( int j = 0; j < n; ++j )
            ++sum2;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //a) O(N^2)
    //b) n = 100: 11
    //   n = 1000: 761
    //   n = 10000: 59755
    //c) Getting slower with every *10 seconds


    start = high_resolution_clock::now();
    int sum3 = 0;
    for( int i = 0; i < n; ++i )
        for( int j = 0; j < n * n; ++j )
            ++sum3;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //a) O(N^3)
    //b) n = 100: 821
    //   n = 1000: 606334
    //   n = 10000: wow this is taking forever im gonna stop it after more than 7 minutes
    //c) Yea this just took forever at 10000. Makes sense


    start = high_resolution_clock::now();
    int sum4 = 0;
    for( int i = 1; i < n; ++i )
        for( int j = 0; j < i; ++j )
            ++sum4;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //a) O(N!)
    //b) n = 100: 4
    //   n = 1000: 288
    //   n = 10000: 28990
    //c) Factorial? It increased in time but not as bad as some other algorithms


    start = high_resolution_clock::now();
    int sum5 = 0;

    for( int i = 0; i < n; ++i )
        for( int j = 0; j < i * i; ++j )
            for( int k = 0; k < j; ++k )
                ++sum5;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    //a) O(N^6) ?
    //b) n = 100: 601530
    //   n = 1000:  a whole lot
    //   n = 10000: not even gonna try
    //c) Nope. Too slow


    start = high_resolution_clock::now();
    int sum6 = 0;
    for(int i = 1; i < n; ++i )
        for(int j = 1; j < i * i; ++j )
            if( j % i == 0 )
                for( int k = 0; k < j; ++k )
                    ++sum6;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //a) O(N^5) ?? - no idea
    //b) n = 100: 7586
    //   n = 1000: 72941565
    //   n = 10000: nope
    //c) Increased a lot, but then I wasn't even going to try for the last one


}
