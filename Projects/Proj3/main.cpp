#include <iostream>
#include "GOB_Graph.h"

using namespace std;

int main() {
    GOB g("input.txt");
    vector<pair<string, double>> set = g.influencerRanking();

    int count = 0;
    for (auto s : set) {
        if (++count > 10) break;
        cout << "Influencer #" << count << " is: " << s.first << " with score: " << s.second << endl;
    }

    /*
     * Part 1:
     * I agree with Bubba's general statement. If Bubba is followed by many others, and the
     * followers reGoB Bubba's posts, then their followers will also see it. Bubba's connection
     * to his followers' followers is represented by an additive benefit from the shortest path
     * to new members of this chain. This will increase the overall size of R, which will
     * increase the influencer score.
     */
}
