
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include "cout.h"

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl

#define MOD 1000000009
#define INF (1<<30)-1

int _isPow2(long long l);
bool isPow2(long long l);
int _isPowN(long long l, int N);
bool isPowN(long long l, int N);

long long _2to10(string s);
string _10to2(long long l);
long long Nto10(int N, string s);
string _10toN(long long l, int N);

bool isPrime(long long l);
vector<int> divisor(long long l);
map<int, int> prime_factor(long long l);
int sieve(int n);

long long gcd(long long a, long long b);
long long lcm(long long a, long long b);
long long extgcd(long long a, long long b, long long& x, long long& y);

long long fact(int n);
long long nCr(long long n, long long r);
long long _nCr(long long n, long long r);

long long _Pow(long long x, long long y);
long long modPow(long long x, long long y);
long long modInverse(long long x);
long long modDivision(long long p, long long q);
long long modC(long long n, int k);


    

//--------------------------------
// lが2のべき乗であれば、その指数を返す。0乗もあり。
// そうでなければ、-1を返す。
int _isPow2(long long l){
    if (l <= 0) return -1;
    int p = 0;
    while (!(l&1)){
        l >>= 1;
        p++;
    }
    if (l == 1) return p;
    else return -1;
}

//--------------------------------
// 2のべき乗かどうかの高速判定。
// 0乗もtrue。
bool isPow2(long long l){
    if (l <= 0) return false;
    else if (l & (l-1)) return false;
    else return true;
}

//--------------------------------
// N：2以上の整数
// lがNのべき乗であれば、その指数を返す。0乗もあり。
// そうでなければ、-1を返す。
int _isPowN(long long l, int N){
    if (l <= 0) return -1;
    if (N <= 1) return -1;
    int p = 0;
    while (!(l%N)){
        l/=N;
        p++;
    }
    if (l == 1) return p;
    else return -1;
}

//--------------------------------
// 0乗でもtrueとしたい場合。
bool isPowN(long long l, int N){
    if (_isPowN(l, N) == -1) return false;
    else return true;
}

//--------------------------------
//2進数を10進数に。
// s：0と1からなる文字列
long long _2to10(string s){
    long long res = 0;
    REP (i, SZ(s)) {
        res <<= 1;
        if (s[i] == '1') res++;
    }
    return res;
}

//--------------------------------
//10進数を2進数に。
// l：0以上の整数
string _10to2(long long l){
    if (l == 0) return "0";
    string res = "";
    while(l != 1){
        if ( l & 1 ) res = '1' + res;
        else res = '0' + res;
        l >>= 1;
    }
    return '1' + res;
}

//--------------------------------
//N進数の文字列sをを10進数に。
// N：2～9の自然数
// s：0～N-1からなる文字列
long long Nto10(int N, string s){
    long long res = 0;
    REP (i, SZ(s)) {
        res *= N;
        res += s[i] - '0';
    }
    return res;
}

//--------------------------------
//10進数をN進数の文字列に。
// l：0以上の整数
string _10toN(long long l, int N){
    if (l == 0) return "0";
    string res = "";
    while(l != 0){
        stringstream ss;
        ss << l % N;
        string tmp;
        ss >> tmp;
        res = tmp + res;
        l /= N;
    }
    return res;
}

//--------------------------------
//素数判定。O(√l)
// l：0以上の整数
bool isPrime(long long l){
    if(l < 2) return false;
    for(long long i=2; i*i<=l; i++)
        if(l%i == 0 )
            return false;
    return true; 
}

//--------------------------------
//約数の列挙。O(√l)
// l：0以上の整数
vector<int> divisor(long long l){
    vector<int> res;
    for(long long i=1; i*i<=l; i++){
        if(l%i == 0){
            res.push_back(i);
            if(i != l/i) res.push_back(l/i);
        }
    }
    return res;
}

//--------------------------------
//素因数分解。O(√l)
// l：0以上の整数
map<int, int> prime_factor(long long l){
    map<int, int> res;
    for(long long i=2; i*i<=l; i++){
        while(l%i == 0){
            res[i]++;
            l /= i;
        }
    }
    if(l!=1) res[l] = 1;
    return res;
}

//--------------------------------
//エラストテネスの篩。だいたいO(n loglog n)
// n：0以上の整数
// n以下の素数の数を返す。
int sieve(int n){
    int p = 0;
    int prime[n]; // i番目の素数。必要なら外出し。
    bool is_prime[n+1]; // is_prime[i]がtrueならiは素数。必要なら外出し。
    for(int i=0; i<=n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<=n; i++){
        if(is_prime[i]){
            prime[p++] = i;
            for(int j=2*i; j<=n; j+=i) is_prime[j] = false;
        }
    }
    return p;
}

//--------------------------------
//最大公約数。
//a,bは1以上の整数。
long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

//--------------------------------
//最小公倍数。
//a,bは1以上の整数。
long long lcm(long long a, long long b){
    return a*b/gcd(a,b);
}

//--------------------------------
//拡張ユークリッドの互除法。
//ax+by=gcd(a,b) となる整数解(x, y)を求める。
//ついでにgcd(a,b)を返す。
long long extgcd(long long a, long long b, long long& x, long long& y){
    long long d = a;
    if(b != 0){
        d = extgcd(b, a%b, y, x);
        y -= (a/b)*x;
    } else{
        x = 1; y = 0;
    }
    return d;
}

//--------------------------------
//単純な順列。
long long fact(int n){
    long long res = 1;
    while(n!=1){
        res *= n;
        n--;
    }
    return res;
}

//--------------------------------
//単純な組み合わせ。
long long nCr(long long n, long long r)
{
    if(n==r) return 1;
    return (nCr(n-1,r)*n)/(n-r);
}

//--------------------------------
//パスカルの三角形使った組み合わせ。
//0Crは-100にしてるので注意。
//あと、n<rのときも-100。
//nC0は1。
long long _nCr(long long n, long long r)
{
    int maxn = 100;
    int c[maxn][maxn];
    REP(i, maxn) REP(j, maxn) c[i][j] = -100;
    for(int i=1; i<=n; i++){
        c[i][0] = 1;
        c[i][i] = 1;
        for(int j=1; j<i; j++){
            c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }
    return c[n][r];
    
}




//--------------------------------
//最小２乗法を用いたpow。
long long _Pow(long long x, long long y){
    long long r=1, a=x;
    while(y > 0){
        if((y&1) == 1) r = r*a;
        a = a*a;
        y /= 2;
    }
    return r;
}

//--------------------------------
//最小２乗法を用いたpow。MOD版。
long long modPow(long long x, long long y){
    long long r=1, a=x;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}

//--------------------------------
//ここからはMODが素数の場合のみ可

//--------------------------------
//MODでの逆元。
long long modInverse(long long x){
    return modPow(x, MOD-2);
}

//--------------------------------
//MODでの割り算。
long long modDivision(long long p, long long q){
    return (p*modInverse(q)) % MOD;
}

//--------------------------------
//MODでの組み合わせ。
long long modC(long long n, int k){
    if(k>n) return 0;
    long long p=1, q=1;
    for(int i=1; i<=k; i++){
        q = (q*i) % MOD;
        p = (p*(n-i+1))%MOD;
    }
    return modDivision(p, q);
}

//ここまではMODが素数の場合のみ可
//--------------------------------


//--------------------------------
//Union-Find木。

class Union_Find{
private:
	vector<int> par;  //親
	vector<int> rank; //木の深さ
public:
	// n要素で初期化（コンストラクタ）
	Union_Find(int n){
		par.clear();
		rank.clear();
		for(int i=0; i<n; i++){
			par.push_back(i);
			rank.push_back(0);
		}
	}
	// n要素で初期化
	void init(int n){
		par.clear();
		rank.clear();
		for(int i=0; i<n; i++){
			par.push_back(i);
			rank.push_back(0);
		}
	}
	//木の根を求める
	int find(int x){
		if(par[x] == x) return x;
		else return par[x] = find(par[x]);
	}
	//xとyの属する集合を結合
	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		if(rank[x] < rank[y]) par[x] = y;
		else{
			par[y] = x;
			if(rank[x] == rank[y]) rank[x]++;
		}
	}
	//xとyが同じ集合に属するか
	bool same(int x, int y){
		return find(x) == find(y);
	}
};



//--------------------------------
//行列の累乗。

namespace _mat{
    
    typedef vector < VI > mat;
    
    mat mul(mat &A, mat &B){
        mat C(SZ(A), VI(SZ(B[0])));
        REP(i, SZ(A)){
            REP(k, SZ(B)){
                REP(j, SZ(B[0])){
                    C[i][j] = (C[i][j] + A[i][k]*B[k][j]); // MODある場合はここで
                }
            }
        }
        return C;
    }
    
    mat pow(mat A, LL n){
        mat B(SZ(A), VI(SZ(A)));
        REP(i, SZ(A)) B[i][i] = 1;
        while(n > 0){
            if(n&1) B = mul(B, A);
            A = mul(A, A);
            n >>= 1;
        }
        return B;
    }
}


//--------------------------------
//セグメント木。RMQ。

namespace seg_tree{
    int tab[200040];
    
    // 区間 [a, b) 内の最小値。　呼び出すときは get(a, b, 0, 0, n);
    int get(int a, int b, int node, int left, int right){
        if(right <= a || b <= left) return INF;
        if(a <= left && right <= b) return tab[node];
        int m = (left + right) / 2;
        int la = get(a, b, node*2+1, left, m);
        int ra = get(a, b, node*2+2, m, right);
        return min(la, ra);
    }
    
    // a番目の値をxに変える。　呼び出すときは update(a, x, 0, 0, n);
    void update(int a, int x, int node, int left, int right){
        if(a < left || right <= a) return;
        if(left+1 == right) {
            tab[node] = min(x, tab[node]);
            return;
        }
        int m = (left+right)/2;
        update(a, x, node*2+1, left, m);
        update(a, x, node*2+2, m, right);
        tab[node] = min(tab[node*2+1], tab[node*2+2]);
    }
}

//--------------------------------
//BIT。
//[1,n]なので注意。[0,n-1]ではない。

namespace BIT{
    const int MAX_N = 100;
    int bit[MAX_N], n;
    
    int sum(int i){
        int s = 0;
        while(i>0){
            s+=bit[i];
            i -= i & -i;
        }
        return s;
    }
    
    void add(int i, int x){
        while(i <= n){
            bit[i] += x;
            i += i & -i;
        }
    }
    
}

//--------------------------------
//隣接行列グラフから木を作成
//ノード数N
//根が0なら、makeTree(0, -1)で作成出来る。

namespace MakeTree{
	const int N = 100;
	bool G[N][N];
	int tree[N][N];
	int childcnt[N];
    
	void makeTree(int node, int parent){
		REP(i, N) if(G[node][i] && i != parent){
			tree[node][childcnt[node]++] = i;
			makeTree(i, node);
		}
		return;
	}
    
}




//--------------------------------
//ワーシャル-フロイド法による全点対最短路検出。
//O(|V|^3)。

//同時に、経路復元も出来るようにしている。
//また、負閉路検出もしている。

namespace Warshall_Floyd{
    const int MAX_V = 100;
    int V;
    
    // G[i][j]は、最終的に「iからjの最短路長」が入る。
    // 負閉路が存在する場合は、G[i][i] < 0 となるiが最終的に発生する。
    // 初期値として、G[i][i]は0、路がある場合はその路長、路が無い場合はINFを入れておく。
    int G[MAX_V][MAX_V];
    
    // prev[i][j]は、最終的に「iからjの最短路におけるjの直前のノード」が入る。
    // 初期値として、全てのi, jに対してprev[i][j] = i としてしまってOK
    int prev[MAX_V][MAX_V];
    
    // 負閉路が存在した後に処理をするための、ループ検出フラグ
    bool used[MAX_V];
    
    void warshall_floyd(){
        REP(k, V) REP(i, V) REP(j, V){
            if(G[i][j] > G[i][k] + G[k][j]){
                G[i][j] = G[i][k] + G[k][j];
                prev[i][j] = prev[k][j];
                if(i==j && G[i][i] < 0){
                    // 負閉路が存在したときの処理。
                    // 一つでも発生したらここで処理しておしまいにしている。
                    // 最後までwarshall_floydやってその後で負閉路検出してもいい。
                    fill(used, used+V, false);
                    for(int v = i; !used[v]; v = prev[i][v]){
                        used[v] = true;
                        // 負閉路に対する何か処理
                    }
                    // 負閉路に対する何か処理
                    return;
                }
            }
        }
        return;
    }
}




//--------------------------------
//二部グラフの最大マッチング。

// Vは、二部グラフの左の頂点数。
// 「ここからまだフロー流せるか？」を左の頂点全てに対して行う。
// ちなみに、Vは左右合わせた全部の頂点数でも問題ない。（左が終わった後に右からのをチェックしても、マッチ数は絶対増えない）

namespace _bipartite_matching{
    const int MAX_V = 110;
    
    int V;
    VI G[MAX_V];
    int match[MAX_V];
    bool used[MAX_V];
    
    void add_edge(int u, int v){
        G[u].PB(v);
        G[v].PB(u);
    }
    
    bool dfs(int v){
        used[v] = true;
        REP(i, SZ(G[v])){
            int u = G[v][i], w = match[u];
            if(w < 0 || (!used[w] && dfs(w))){
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }
    
    int bipartite_matching(){
        int res = 0;
        MSET(match, -1);
        REP(v, V){
            if(match[v] < 0){
                MSET(used, 0);
                if(dfs(v)) res++;
            }
        }
        return res;
    }
}




//--------------------------------
//最大流。
//Ford-Fulkerson法
//O(F|E|)

namespace Ford_Fulkerson{
    
    const int MAX_V = 110;
    
    struct edge {int to, cap, rev;};
    vector <edge> G[MAX_V];
    bool used[MAX_V];
    
    void add_edge(int from, int to, int cap){
        G[from].push_back((edge){to, cap, G[to].size()});
        G[to].push_back((edge){from, 0, G[from].size()-1});
    }

    int dfs(int v, int t, int f){
        if (v == t) return f;
        used[v] = true;
        for(int i = 0; i < SZ(G[v]); i++){
            edge &e = G[v][i];
            if(!used[e.to] && e.cap > 0){
                int d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    
    int max_flow(int s, int t){
        int flow = 0;
        while(1){
            memset(used, 0, sizeof(used));
            int f = dfs(s, t, INF);
            if(f == 0) return flow;
            flow += f;
        }
    }
    
    
}


//--------------------------------
//最大流。
//Dinic法
//O(|E||V|^2)

namespace Dinic{
    
    const int MAX_V = 10000;
    
    struct edge {int to, cap, rev;};
    vector <edge> G[MAX_V];
    int level[MAX_V];
    int iter[MAX_V];
    
    void add_edge(int from, int to, int cap){
        G[from].push_back((edge){to, cap, G[to].size()});
        G[to].push_back((edge){from, 0, G[from].size()-1});
    }
    
    void bfs(int s){
        MSET(level, -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while(SZ(que)){
            int v = que.front(); que.pop();
            REP(i, SZ(G[v])){
                edge &e = G[v][i];
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    
    int dfs(int v, int t, int f){
        if (v == t) return f;
        for(int &i = iter[v]; i < SZ(G[v]); i++){
            edge &e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]){
                int d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    
    int max_flow(int s, int t){
        int flow = 0;
        while(1){
            bfs(s);
            if(level[t] < 0) return flow;
            memset(iter, 0, sizeof(iter));
            int f;
            while((f = dfs(s, t, INF)) > 0) flow += f;
        }
    }
}


//--------------------------------
//最小費用流。
//O(F|V|^2) または O(F|E|log|V})

namespace mincost{
    typedef pair<int, int> P;
    struct edge {int to, cap, cost, rev;};
    const int MAX_V = 1000;

    int V; // Vは別途忘れずに設定すること。「最後のノード番号＋１」であることに注意。sinkと同じ数ではない。sink+1。
    vector <edge> G[MAX_V]; // 使い回す場合は、Gも忘れず初期化すること
    int h[MAX_V];
    int dist[MAX_V];
    int prevv[MAX_V], preve[MAX_V];
    
    void add_edge(int from, int to, int cap, int cost){
        G[from].push_back((edge){to, cap, cost, G[to].size()});
        G[to].push_back((edge){from, 0, -cost, G[from].size()-1});
    }
    
    int min_cost_flow(int s, int t, int f){
        int res = 0;
        fill(h, h+V, 0);
        while(f > 0){
            priority_queue<P, vector<P>, greater<P> > que;
            fill(dist, dist+V, INF);
            dist[s] = 0;
            que.push(P(0, s));
            while(SZ(que)){
                P p = que.top(); que.pop();
                int v = p.second;
                if(dist[v] < p.first) continue;
                REP(i, SZ(G[v])){
                    edge &e = G[v][i];
                    if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        que.push(P(dist[e.to], e.to));
                    }
                }
            }
            if(dist[t] == INF) return -1;
            REP(v, V) h[v] += dist[v];
            int d = f;
            for(int v = t; v != s; v = prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);
            f -= d;
            res += d*h[t];
            for(int v = t; v != s; v = prevv[v]){
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }
}



//--------------------------------
//二次元ベクトル系ライブラリ。

namespace vec{
    double EPS = 1e-10;
    
    double add(double a, double b){
        if(abs(a+b) < EPS * (abs(a) + abs(b))) return 0;
        return a + b;
    }
    
    struct P{
        double x, y;
        P() {}
        P(double x, double y) : x(x), y(y){
        }
        P operator + (P p){
            return P(add(x, p.x), add(y, p.y));
        }
        P operator - (P p){
            return P(add(x, -p.x), add(y, -p.y));
        }
        P operator * (double d){
            return P(x*d, y*d);
        }
        double dot(P p){ // 内積
            return add(x*p.x, y*p.y);
        }
        double det(P p){ // 外積
            return add(x*p.y, -y*p.x);
        }
    };
    
    //線分p1-p2上に点qがあるか？
    bool on_seg(P p1, P p2, P q){
        return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
    }
    
    //直線p1-p2と直線q1-q2の交点
    //(q2-q1).det(p2-p1) == 0 のときは、２直線は平行。
    P intersection(P p1, P p2, P q1, P q2){
        return p1 + (p2-p1) * ((q2-q1).det(q1-p1) / (q2-q1).det(p2-p1));
    }

	//辞書順で比較
	bool cmp_x(const P& p, const P& q){
		if(p.x != q.x) return p.x < q.x;
		return p.y < q.y;
	}
    
	//凸包を求める。
	//nは要素数。
	//psはpの配列で渡すこと。
	vector<P> convex_hull(P* ps, int n){
		sort(ps, ps+n, cmp_x);
		int k = 0;
		vector<P> qs(n*2);
		REP(i, n){
			while(k>1 && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
			qs[k++] = ps[i];
		}
		for(int i=n-2, t=k; i>=0; i--){
			while(k>t && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
			qs[k++] = ps[i];
		}
		qs.resize(k-1);
		return qs;
	}

	// 距離の二乗
	double dist(P p, P q){
		return (p - q).dot(p - q);
	}
    
}




namespace unittest {
	int  run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Ilong longegal input! Test case " << casenum << " does not exist." << endl;
			}
            cout << endl;
			return;
		}
        
		int total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) break;
            cout << endl;
			++total;
		}
        
		if (total == 0) {
			cerr << "No test cases run." << endl;
		}
	}
    
	int run_test_case(int casenum__) {
		switch (casenum__) {
            case 0 : {
                OUT(_isPow2(16));
                OUT(_isPow2(1024));
                OUT(_isPow2(1));
                OUT(_isPow2(0));
                OUT(_isPow2(5));
                OUT(_isPow2(1023));
                OUT(_isPow2(-1));
                return 1;
            }
            case 1 : {
                OUT(isPow2(8192));
                OUT(isPow2(1));
                OUT(isPow2(0));
                OUT(isPow2(-1));
                OUT(isPow2(245436432));
                OUT(isPow2(_2to10("1000")));
                OUT(isPow2(_2to10("1111")));
                return 1;
            }
            case 2 : {
                OUT(_isPowN(625,5));
                OUT(_isPowN(624,5));
                OUT(_isPowN(5,5));
                OUT(_isPowN(2,5));
                OUT(_isPowN(1,5));
                OUT(_isPowN(0,5));
                OUT(_isPowN(-1,5));
                OUT(_isPowN(1024,1));
                return 1;
            }
            case 3 : {
                OUT(isPowN(144,12));
                OUT(isPowN(3000,5));
                OUT(isPowN(300,1));
                OUT(isPowN(1,234523));
                return 1;
            }
            case 4 : {
                OUT(_2to10("101"));
                OUT(_2to10("0"));
                OUT(_2to10("1"));
                OUT(_2to10("0001"));
                OUT(_2to10("1111"));
                OUT(_2to10("1000000"));
                OUT(isPowN(_2to10("10000"), 2));
                OUT(_2to10("1bcd"));
                return 1;
            }
            case 5 : {
                OUT(_10to2(5));
                OUT(_10to2(0));
                OUT(_10to2(16));
                OUT(_10to2(24));
                OUT(_10to2(255));
                //OUT(_10to2(-1));
                return 1;
            }
            case 6 : {
                OUT(Nto10(2,"101"));
                OUT(Nto10(2,"1000"));
                OUT(Nto10(3,"2012"));
                OUT(Nto10(8,"2705"));
                OUT(Nto10(9,"0010"));
                return 1;
            }
            case 7 : {
                OUT(_10toN(59, 3));
                OUT(_10toN(1477, 8));
                OUT(_10toN(0, 8));
                OUT(_10toN(1, 8));
                return 1;
            }
            case 8 : {// string
                string s("abcdefg");
                OUT(s.find("c"));
                OUT(s.find("def"));
                int a = s.find("df");
                OUT(a);
                //if (s.find("ag") == -1) OUT("1");

				string ss("ababacccddaa");
				set<char> sc(ALL(ss)); // イテレータで初期生成できる
				OUT(SZ(sc));
                return 1;
            }
            case 9 : {// vector
                VI a;
                a.PB(4);
                a.PB(-100);
                a.PB(200);
                a.PB(50);
                FIT(it, a) OUT(*it);
                cout << endl;
                sort(ALL(a));
                FIT(it, a) OUT(*it);
                cout << endl;
                sort(ALL(a), greater<int>());
                FIT(it, a) OUT(*it);
                cout << endl;
                //int tmp = find(ALL(a), 50);

				VI b(5); // 最初に要素数決定　いきなりb[3]とかできる
                VI b_(10, 23); // 最初に要素数と中身も決める　int b_[10] = {23} とほぼ同様（int配列はスタック領域、VIはヒープ領域）
				OUT(b[2]);
				OUT(b[4]);
				OUT(b[5]);
				OUT(b[6]);
				
                cout << endl;
				int c[4] = {4,2,10,5};
				VI d(c,&c[3]); //こんな初期化も出来る
				d.insert(d.begin(), 6); //先頭にinsert
                FIT(it, d) OUT(*it);
                
                
                VI e;
                e.PB(4);
                e.PB(-100);
                e.PB(200);
                VI f = e;
                f[1] = -105;
                OUT(e[1]);
                OUT(f[1]);
                
                
                return 1;
            }
            case 10 : {// pair, stack
                stack< int > st;
                st.push(1);
                OUT(st.top());
                pair<int, int> pii;
                pii = pair<int, int>(2,3);
                OUT(pii.second);
                pair<int, string> pis;
                pis = make_pair(4, "ad");
                OUT(pis.second);
                
                stack<pair<int, int> > st2;
                st2.push(pair<int, int>(5,6));
                st2.push(make_pair(7,8));
                OUT(st2.top().second);
                OUT(st2.empty());
                st2.pop();
                st2.pop();
                OUT(st2.empty());
                return 1;
            }
            case 11 : {//isPrime
                OUT(isPrime(0));
                OUT(isPrime(1));
                OUT(isPrime(2));
                OUT(isPrime(3));
                OUT(isPrime(4));
                OUT(isPrime(5));
                OUT(isPrime(16));
                OUT(isPrime(107));
                return 1;
            }
            case 12 : {//divisor
                OUT(divisor(48));
                OUT(divisor(1));
                return 1;
            }
            case 13 : {//prime_factor
                OUT(prime_factor(48));
                OUT(prime_factor(17));
                OUT(prime_factor(2));
                OUT(prime_factor(1));
                return 1;
            }
            case 14 : {//sieve
                OUT(sieve(200000));
                OUT(sieve(2));
                OUT(sieve(1));
                return 1;
            }
            case 15 : {//extgcd
                long long x, y;
                OUT(extgcd(4,11,x,y));
                OUT(x);
                OUT(y);
                OUT(extgcd(15,24,x,y));
                OUT(x);
                OUT(y);
                return 1;
            }
            case 16 : {//_Pow
                OUT(_Pow(2,10));
                return 1;
            }
            case 17 : {//nCr
//                OUT(nCr(0,1));
                OUT(nCr(1,1));
                OUT(nCr(1,0));
                OUT(nCr(10,0));
                OUT(nCr(10,1));
                OUT(nCr(10,3));
                OUT(nCr(10,10));
//                OUT(nCr(10,11));
                OUT(_nCr(0,1));
                OUT(_nCr(1,1));
                OUT(_nCr(1,0));
                OUT(_nCr(10,0));
                OUT(_nCr(10,1));
                OUT(_nCr(10,3));
                OUT(_nCr(10,10));
                OUT(_nCr(10,11));
                return 1;
            }
            case 20 : {// gcd, lcm
                OUT(gcd(16,12));
                OUT(gcd(12,16));
//                OUT(gcd(0,300));
//                OUT(gcd(300,0));
                OUT(gcd(1,300));
                OUT(gcd(300,1));
                OUT(gcd(4329214,12350103));
                OUT(gcd(32501239500,234253512300));
                
                OUT(lcm(16,12));
                OUT(lcm(3,5));
                OUT(lcm(1,150));
                OUT(lcm(1024,3000));
                return 1;
            }
            case 30 : {// Union_Find
                Union_Find uf(6);
				uf.unite(0,1);
				uf.unite(0,3);
				uf.unite(2,4);
				uf.unite(4,5);
				OUT(1);
				OUT(uf.same(0,3));
				OUT(uf.same(2,5));
				OUT(uf.same(0,5));
				uf.unite(4,100);
				OUT(uf.same(0,100));
				OUT(uf.same(4,100));
				OUT(uf.same(4,120));
				OUT(uf.find(1111));
				//OUT(uf.same(-5,120));
                return 1;
            }
                
            case 40 : {
                _bipartite_matching::V = 4;
                return 1;
            }
            case 999 : {
                return 1;
            }
            default : return -1;
		}
	}
}


int main(int argc, char *argv[]) {
    cout << endl;
	if (argc == 1) {
		unittest::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			unittest::run_test(atoi(argv[i]));
	}
}
