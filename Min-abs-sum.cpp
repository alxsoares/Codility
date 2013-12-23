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
#include <cstring>
const int BASE = 100;
const int MAX = BASE << 1;
const int MAXN = MAX + 5;
int dp[2][MAXN];
int solution(const vector<int> &A) {
    // write your code in C++98
    int n = A.size();
    memset(dp, 0, sizeof(dp));
    int cur = 0, nxt = 1;
    dp[cur][BASE] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= MAX; j++)
            dp[nxt][j] = 0;
        for (int j = 0; j <= MAX; j++) {
            if (dp[cur][j] == 0) continue;
            int newj = j - A[i];
            if (newj >= 0 && newj <= MAX) {
				dp[nxt][newj] = 1;
			}
            newj = j + A[i];
            if (newj >= 0 && newj <= MAX) {
				dp[nxt][newj] = 1;
			}
        }
        swap(cur, nxt);
    }
    for (int i = 0; i <= BASE; i++) {
        if (dp[cur][BASE - i] || dp[cur][BASE + i]) return i;
    }
    return -1;
}

int main() {
	int n;
	cin >> n;
	vector<int> A;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		A.PB(x);
	}
	cout << solution(A) << endl;
	return 0;
}

