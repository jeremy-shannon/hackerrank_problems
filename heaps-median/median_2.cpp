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
    double median = 0;
    for(int i = 0; i < n; i++){
        double input;
        cin >> input;
        if (i == 0) {
            median = input;
            cout << median << endl;
            continue;
        }
        if (i%2 == 1) {
            if (input < median) {
                a.push_back(input);
                make_heap(a.begin(), a.end());
                b.push_back(median);
                make_heap(b.begin(), b.end(), greater<int>());
                median = ((double)a.front() + median) /2;
            } else {
                a.push_back(median);
                make_heap(a.begin(), a.end());
                b.push_back(input);
                make_heap(b.begin(), b.end(), greater<int>());
                median = ((double)b.front() + median) /2;
            }
        } else {
            if (input < median) {
                a.push_back(input);
                make_heap(a.begin(), a.end());
                median = a.front();
                pop_heap(a.begin(), a.end());
                a.pop_back();
            } else {
                b.push_back(input);
                make_heap(b.begin(), b.end(), greater<int>());
                median = b.front();
                pop_heap(b.begin(), b.end());
                b.pop_back();
            }
        }
            
        
        /*    
        cout << "a: ";
        for (int n : a) {
            cout << n << " ";
        }
        cout << endl;
        cout << "b: ";
        for (int n : b) {
            cout << n << " ";
        }
        cout << endl; 
        */
        
        cout << median << endl;
    }
    return 0;
}
