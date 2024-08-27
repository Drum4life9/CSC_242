#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

string binRec(int i, string& bin) {
    //base case
    if (i == 0) return bin;

    if (i % 2 == 0) bin = "0" + bin;
    else if (i % 2 == 1) bin = "1" + bin;

    return binRec(i / 2, bin);

}

int fibb(int a, int b, int target, int times) {
    if (target == times) return b;
    else return fibb(b, b + a, target, times + 1);
}

int main() {

    //1.5
    string bin;
    bin = binRec(10, bin);
    cout << "The Binary representation of 10 is " << bin << endl;
    //----------------------------------------------------------------

    //1.11a
    vector<int> fibbs;
    int N;
    cout << "Enter an N: ";
    cin >> N;

    fibbs.push_back(0);

    for (int i = 1; i < N; i++) fibbs.push_back(fibb(0, 1, i, 1));

    int sum = accumulate(fibbs.begin() + 1, fibbs.end(), -1);

    //removes last two to sum up until N-2
    sum -= fibbs[fibbs.size() - 1];
    sum -= fibbs[fibbs.size() - 2];

    int RHandExpress = fibbs[N - 1] - 2;

    cout << "Does sum == Fn - 2?: " << (sum == RHandExpress) << endl;



    //2.2
    /*
     * a. True, the max time between T1 and T2 is O(f(N))
     * b. True, the min time between T1 and T2 is o(f(N))
     * c. False, since the rates are the same, the answer is just 1
     * d. I think it's true, but I've never seen O inside O notation. My reasoning tells me that
     *        it's true because the T1(N) is going to be less than or equal to the T2(N), so taking
     *        the T2(N) and the time for that to happen (inside the outer O) seems like it's equal to the
     *        T1(N).
     */
}
