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
const int MAXN = 100000 + 5;
int ll[MAXN], rr[MAXN];
vector<int> solution(const vector<int> &A) {
    // write your code in C++98
    int n = A.size();
    vector<int> ret(n);
    for (int i = 0; i < n; i++) {
        ll[i] = i;
        while (ll[i] > 0 && A[ll[i] - 1] <= A[i]) {
            ll[i] = ll[ll[i] - 1];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        rr[i] = i;
        while (rr[i] < n - 1 && A[rr[i] + 1] <= A[i]) {
            rr[i] = rr[rr[i] + 1];
        }
    }
    for (int i = 0; i < n; i++) {
		if (ll[i] == 0 && rr[i] == n - 1) ret[i] = 0;
		else {
			if (ll[i] == 0) ret[i] = rr[i] + 1 - i;
			else if (rr[i] == n - 1) ret[i] = i + 1 - ll[i];
			else ret[i] = min(rr[i] + 1 - i, i + 1 - ll[i]);
		}
    }
    return ret;
}

int main() {
	int myint[] = {4, 3, 1, 4, -1, 2, 1, 5, 7};
	vector<int> A(myint, myint + 9);
	vector<int> ret = solution(A);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
	cout << endl;
	return 0;
}

