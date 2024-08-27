#include <iostream>
#include <vector>

using namespace std;

struct node {

    node(vector<int>& list, vector<int>& pDays, int v, short d, short pDa, short lPos, node* l, node* r, short numLefts) :
            val{v}, index{lPos}, left{l}, right{r}, lefts{numLefts}, pDay{pDa}, day{d}, lst{list}, pDays{pDays} {}

    int val;
    short index;
    short lefts, pDay, day;
    node* left;
    node* right;
    vector<int>& lst, pDays;
};

int find_min(node* n) {
    if (!n)
        return 1024;
    if (n->pDay >= n->pDays.size())
    {
        int temp = n->lefts;
        delete n;
        return temp;
    }
    else if (n->day == n->pDays[n->pDay]) { //If n->pday > n->pdays size, it will throw an out of bound error
        if (n->val != 0) {
            delete n;
            return 1024;
        }
        ++(n->pDay);
    }
    if (n->index >= n->lst.size())
    {
        int temp = n->lefts;
        delete n;
        return temp;
    }

    int val1 = n->val + n->lst[n->index] - n->lst[n->index + 1];
    int val2 = n->val + n->lst[n->index];

    n->left = new node(n->lst, n->pDays, (val1 < 0 ? 0 : val1), n->day + 1, n->pDay, n->index + 2, nullptr, nullptr, n->lefts + 1);
    n->right = new node(n->lst, n->pDays, (val2), n->day + 1, n->pDay, n->index + 2, nullptr, nullptr, n->lefts);

    cout << n->day << endl;
    return min(find_min(n->left), find_min(n->right));
}

int stuff() {

    int days, pDays;
    cin >> days >> pDays;
    vector<int> list, pList;
    for (int i = 0; i < days * 2; i++)
    {
        int val;
        cin >> val;
        list.push_back(val);
    }
    for (int i = 0; i < pDays; i++)
    {
        int val;
        cin >> val;
        pList.push_back(val);
    }

    vector<int>& inp = list;
    vector<int>& inp2 = pList;



    node day0{inp, inp2, 0, 0, 0, 0, nullptr, nullptr, 0};

    int ans = find_min(&day0);

    cout << (ans < 1024 ? ans : -1);



}