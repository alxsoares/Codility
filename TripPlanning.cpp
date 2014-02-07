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
#include <climits>
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

#define maxn 90010
#define th(x) this->x = x
int rmq[2*maxn];
struct ST {
	int mm[2*maxn];
	int best[20][2*maxn];
	void init(int n) {
		int i,j,a,b;
		mm[0]=-1;
		for(i=1; i<=n; i++) {
			mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
			best[0][i]=i;
		}
		for(i=1; i<=mm[n]; i++) {
			for(j=1; j<=n+1-(1<<i); j++) {
				a=best[i-1][j];
				b=best[i-1][j+(1<<(i-1))];
				best[i][j]=rmq[a] < rmq[b]?a:b;
			}
		}
	}
	int query(int a, int b) {
		if(a > b)	swap(a, b);
		int t;
		t=mm[b-a+1];
		a=best[t][a];
		b=best[t][b-(1<<t)+1];
		return rmq[a] < rmq[b] ? a : b;
	}
};
//下面是LCA2RMQ开始
struct Nod {
	int b, nxt;
	void init(int b, int nxt) {
		th(b);	th(nxt);
	}
};
/**
	lca转化为rmq问题
	注意: 
		1.maxn为最大节点数, ST的数组和F、buf要设置为2*maxn!!!!!
		2.ST类为1开始，此类依然为0开始!
		3.F是欧拉序列,rmq是深度序列,P某点在欧拉序列中第一次出现的位置
*/
struct LCA2RMQ {
	int n;							//节点个数
	Nod buf[2*maxn];	int len;	int E[maxn];	//Tree	资源
	int V[2*maxn], route[maxn];				//路径的权，根到某点的路径和
	char vis[maxn];						//0没有访问，1正在访问
	
	ST st;							//Spare-Table...
	int F[2*maxn], P[maxn], cnt;	//介绍如上,cnt为计数器,lev为dfs时层数(减少递归栈大小)
	
	void init(int n) {
		th(n);
		len = 0;
		memset(E, 255, sizeof(E));
	}
	void addEdge(int a, int b, int v) {
		buf[len].init(b, E[a]);		V[len] = v;		E[a] = len ++;
		buf[len].init(a, E[b]);		V[len] = v;		E[b] = len ++;
	}
	int query(int a, int b) {				//传入两个节点，返回他们lca节点编号
		return F[st.query(P[a], P[b])];
	}
	//1.【递归版】
	void dfs(int a, int lev) {
		vis[a] = 1;
		
		++ cnt;
		F[cnt] = a;
		rmq[cnt] = lev;
		P[a] = cnt;
		for(int i = E[a]; i != -1; i = buf[i].nxt) {
			if(vis[buf[i].b])	continue;
			route[buf[i].b] = route[a] + V[i];
			dfs(buf[i].b, lev+1);
			++ cnt;
			F[cnt] = a;
			rmq[cnt] = lev;
		}
	}
	void solve(int root) {
		memset(vis, 0, sizeof(vis));
		route[root] = cnt = 0;
		dfs(root, 0);
		st.init(2*n-1);
	}
	
} lca;

// you can also use includes, for example:
// #include <algorithm>
vector<int> solution(int K, vector<int> &T) {
    // write your code in C++98
    int n = T.size();
	lca.init(n);
	vector<vector<int> > adj(n);
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        if (i == T[i]) continue;
		lca.addEdge(i, T[i], 1);
        deg[i]++; deg[T[i]]++;
    }
	lca.solve(K);
	vector<int> dep(n);
	set<int> st;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1 && i != K) {
			dep[i] = lca.route[i];
			st.insert(i);
			//cout << i << " " << lca.route[i] << endl;
        }
    }
	vector<int> ans;
	ans.push_back(K);
	set<int>::iterator it;
	vector<int> rmv(n);
	while (st.size() > 0) {
		int idx = n, mx = -1;
		for (it = st.begin(); it != st.end(); it++) {
			if (dep[*it] > mx || (dep[*it] == mx && *it < idx)) {
				mx = dep[*it];
				idx = *it;
			}
		}
		ans.push_back(idx);
		//update
		st.erase(idx);
		for (it = st.begin(); it != st.end(); it++) {
			//cout << *it << " " << dep[*it] << endl;
			int j = *it;
			int anc = lca.query(idx, j);
			if (lca.route[anc] > rmv[j]) {
				rmv[j] = lca.route[anc];
			}
			dep[*it] = lca.route[j] - rmv[j];
		}
	}
    return ans;
}

int main() {
	int ints[] = {1, 2, 3, 3, 2, 1, 4};
	vector<int> T(ints, ints + 7);
	vector<int> ans;
	ans = solution(2, T);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}

