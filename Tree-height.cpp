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

struct tree {
	int x;
	tree *l, *r;
};
// you can also use includes, for example:
// #include <algorithm>
int dfs(tree *T) {
    if (T == NULL) return 0;
    return max(dfs(T->l), dfs(T->r)) + 1;
}
int solution(tree * T) {
    // write your code in C++98
    return dfs(T) - 1;
}

int main() {
	return 0;
}

