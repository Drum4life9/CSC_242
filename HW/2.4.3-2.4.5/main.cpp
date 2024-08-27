#include <vector>

using namespace std;

//2.15, simple existence algorithm
bool doesIExist(const vector<int>& v, int i) {
    return v[0] < i < v[v.size() - 1];
    //determines only if it exists, as it would be greater than v[0]
    //and less than v[v.size() - 1]. Running time = Omega(1), only one line to run.
}



int main() {
    /* 2.11
     * a) 2.5ms
     * b) 3.495 ms?
     * c) 12.5 ms
     * d) 62.5 ms
     *
     *
     *
     * 2.12
     * a) 200,000 (2000x)
     * b) 34,266 (342.657x)
     * c) 4,472 (44.721x)
     * d) 1,260 (12.599x)
     */
}
