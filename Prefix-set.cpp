#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

// you can also use includes, for example:
// #include <algorithm>
int solution(const vector<int> &A) {
    // write your code in C++98
    int n = A.size();
    vector<bool> exist(n, false);
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (!exist[A[i]]) {
            ret = i;
            exist[A[i]] = true;
        }
    }
    return ret;
}

int main() {
}

