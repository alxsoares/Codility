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
int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++98
    int n = A.size(), m = B.size();
    for (int i = 1; i < n; i++)
        A[i] = min(A[i], A[i - 1]);
    int i = 0, j = n - 1;
    for (; i < m && j >= 0; ) {
        while (j >= 0 && A[j] < B[i]) {
            j--;
        }
        if (j >= 0) {
            j--;
            i++;
        }
    }
    return i;
}

int main(int argc, char const *argv[])
{
	return 0;
}