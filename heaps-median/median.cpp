#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> a, b;
    cout << setprecision(1) << fixed;
    double median;
    for(int i = 0; i < n; i++){
        double input;
        cin >> input;
        a.push_back(input);
        make_heap(a.begin(), a.end());
        while (b.size() < a.size()) {
            b.push_back(a.front());
            make_heap(b.begin(), b.end(), greater<int>());
            pop_heap(a.begin(), a.end());
            a.pop_back();
        }
        while (b.size() > a.size()) {
            a.push_back(b.front());
            make_heap(a.begin(), a.end());
            pop_heap(b.begin(), b.end());
            b.pop_back();
        }
        /* cout << "a: ";
        for (int n : a) {
            cout << n << " ";
        }
        cout << endl;
        cout << "b: ";
        for (int n : b) {
            cout << n << " ";
        }
        cout << endl; */
        if (b.size() > a.size()) {
            median = double(b.front());
        } else if (a.size() > b.size()) {
            median = double(a.front());
        } else {
            median = ((double)a.front() + (double)b.front()) /2;
        }
        cout << median << endl;
    }
    return 0;
}
