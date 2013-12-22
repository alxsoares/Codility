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
int C[MAXN], N;
void add(int x, int num) {
	for (int i = x; i <= N; i += (i & (-i)))
		C[i] += num;
}
int sum(int x) {
	if (x <= 0) return 0;
	int ret = 0;
	for (int i = x; i > 0; i -= (i & (-i)))
		ret += C[i];
	return ret;
}
int solution(const vector<int> &A) {
    // write your code in C++98
    int n = A.size();
    vector<int> num = A;
    vector<int> as(n);
    sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
    N = n;
    for (int i = 0; i < n; i++) {
    	as[i] = lower_bound(num.begin(), num.end(), A[i]) - num.begin() + 1;
    }

    memset(C, 0, sizeof(C));
    LL inversion = 0;
    for (int i = n - 1; i >= 0; i--) {
    	inversion += sum(as[i] - 1);
    	add(as[i], 1);
    }
    return inversion > 1000000000 ? -1 : inversion;
}

int main() {
	int myint[] = {-1, 6, 3, 4, 7, 4};
	vector<int> A(myint, myint + 6);
	cout << solution(A) << endl;
	return 0;
}
