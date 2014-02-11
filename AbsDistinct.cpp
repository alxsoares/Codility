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
    int l = 0, r = n - 1, ret = 0;
    for (; l < r && A[l] < 0 && A[r] > 0; ) {
        int temp = A[l] + A[r];
        if (temp < 0) {
			ret++;
			for (int val = A[l]; A[l] == val; l++);
        } else if (temp > 0) {
			ret++;
			for (int val = A[r]; A[r] == val; r--);
        } else {
            ret++;
            for (int val = A[l]; A[l] == val; l++);
            for (int val = A[r]; A[r] == val; r--);
        }
    }
    for (; l <= r; ) {
        ret++;
        for (int val = A[l]; A[l] == val; l++);
    }
    return ret;
}

int main() {
	int myints[] = {-5, -3, -1, 0, 3, 6};
	vector<int> A(myints, myints + 6);
	cout << solution(A) << endl;
	return 0;
}

