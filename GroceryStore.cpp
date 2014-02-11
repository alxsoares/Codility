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

const int maxn = 100 + 5;
vector<pair<int, int> > adj[maxn];
int dis[maxn];
int n;
void addEdge(int a, int b, int c) {
//	cout << a << " " << b << " " << c << endl;
    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
}
void dijkstra(int st) {
    for (int i = 1; i < n; i++)
        dis[i] = -1;
    dis[0] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first, w = adj[u][i].second;
            if (dis[v] == -1 || dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pq.push(make_pair(-dis[v], v));
            }
        }
    }
}
int solution(const vector<int> &A, const vector<int> &B, const vector<int> &C, const vector<int> &D) {
    // write your code in C++98
    n = D.size();
    for (int i = 0; i < A.size(); i++) {
        addEdge(A[i], B[i], C[i]);
    }
    dijkstra(0);
    int ret = -1;
    for (int i = 0; i < n; i++) {
    	if (dis[i] == -1) continue;
        if (dis[i] <= D[i]) {
            if (ret == -1 || dis[i] < ret)
            	ret = dis[i];
        }
    }
    return ret;
}

int main() {
	vector<int> A, B, C, D;
	int m, n;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		A.PB(a); B.PB(b); C.PB(c);
	}
	for (int i = 0; i < n; i++) {
		int d;
		scanf("%d", &d);
		D.PB(d);
	}
	cout << solution(A, B, C, D) << endl;
	return 0;
}