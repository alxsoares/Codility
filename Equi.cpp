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

int solution(const vector<int> &A) {
    // write your code in C++98
    int n = A.size();
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += A[i];
    long long left = 0;
    for (int i = 0; i < n; i++) {
        if (left == sum - A[i] - left) {
            return i;
        }
        left += A[i];
    }
    return -1;
}

int main() {
}

