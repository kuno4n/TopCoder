
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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

#define MOD 1000000009
#define INF (1<<30)-1

int bitcnt(LL a);
long long str2int(string s);

string int2str(LL a);
string _int2str(LL a, int len);

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
long long modFact(int n);
long long nCr(long long n, long long r);
long long _nCr(long long n, long long r);

long long _Pow(long long x, long long y);
long long modPow(long long x, long long y);
long long modInverse(long long x);
long long modDivision(long long p, long long q);
long long modC(long long n, int k);


// vector <string> vs = {"34 22 1", "00, 54"} みたいに入っている数値を、
// int a[300] みたいな配列に入れて、要素数をnに入れる。
// parse(vs, a, n); みたいに呼ぶ
void parse(vector<string> &s, int *a, int &n){
	n = 0;
	string t;
	REP(i, SZ(s)) t += s[i];
	stringstream ss(t);
	while(ss >> a[n]) n++;
}

int bitcnt(LL n)
{
    int c;
    for(c=0;n!=0;c++,n&=n-1) ;
    return c;
}

int bitcnt2(int bits)
{
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}

//--------------------------------
// stringをintに変換。
LL str2int(string s){
    LL res = 0;
    REP(i, SZ(s)){
        res *= 10;
        res += s[i]-'0';
    }
    return res;
}

//--------------------------------
// intをstringに変換。
string int2str(LL a){
    stringstream ss;
    ss << a;
    string res;
    ss >> res;
    return res;
}

//--------------------------------
// intをstringに変換。
// 長さが足りない場合は0詰め。
string _int2str(int a, int len){
    stringstream ss;
    ss << a;
    string res;
    ss >> res;
    while(SZ(res) < len) res = "0"+res;
    return res;
}

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
// N：2～10の自然数
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
//エラストテネスの篩その２。
//primefactors[n] に、nの素因数の数を入れる。
//primefactors[12]=3。
//nが素数とは、primefactors[n] == 0 ということ。
namespace _sieve{
	const int MAX_N = 1000000;
	int primefactors[MAX_N+1];
	
	void make(){
		fill(primefactors, primefactors+MAX_N+1, 0); 
		primefactors[0] = primefactors[1] = 1; //0 and 1 are not primes
		for (int i=2; i<=MAX_N; i++)             //
		 if(primefactors[i] == 0)         //it is a prime number
		     for (int j=2*i; j<=MAX_N; j+=i )           // For each multiple of i
		         for (int x = j; x%i == 0 ;  x/=i ) // appropriately increase
		             primefactors[j]++;             // the number of prime factors.
	}
};

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

long long modFact(int n){
    long long res = 1;
    while(n!=1){
        res = (res*n) % MOD;
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
//0Cr、n<rのとき、0としている。（0Crは1としておくと組み合わせのとき楽かも）
//（少なくとも0C0は1？）
//nC0は1。
namespace pas {
    const int MAX_N = 1000;
    LL nCr[MAX_N+1][MAX_N+1];
    
    void makepas(){
        REP(i, MAX_N+1) REP(j, MAX_N+1) nCr[i][j] = 0;
        for(int i=1; i<=MAX_N; i++){
            nCr[i][0] = 1;
            nCr[i][i] = 1;
            for(int j=1; j<i; j++){
                nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % MOD;
            }
        }
    }
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
    long long r=1, a=x%MOD;
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
    return (p*modInverse(q)) % MOD; //((p%MOD)*modInverse(q)) % MOD の方が安全？
}

//--------------------------------
//MODでの組み合わせ。
long long modC(long long n, int k){
    if(k > n) return 0;
//    if(k == 0 || n == 0) return 1; // 問題に応じて設定
    long long p=1, q=1;
    for(int i=1; i<=k; i++){
        q = (q*i) % MOD;
        p = (p*((n-i+1+MOD)%MOD))%MOD;
    }
    return modDivision(p, q);
}

//ここまではMODが素数の場合のみ可
//--------------------------------


//--------------------------------
//Union-Find木。

namespace Union_Find{
    const int MAX_N = 1000;
	int par[MAX_N];  //親
	int rank[MAX_N]; //木の深さ
    
	// n要素で初期化
	void init(int n){
        REP(i, n){
			par[i] = i;
            rank[i] = 0;
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
                    C[i][j] = (C[i][j] + A[i][k]*B[k][j]); // MODある場合はここで。A[i][k]とかも先にMODしておく。かけ算でオーバーフローしちゃうから。
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
//単純なダイクストラ。
//O(|V|^2)。
//残っている頂点のうち最短の頂点から「配る」のイメージ。

//同時に、経路復元も出来るようにしている。

namespace dijkstra{
    
	//const int INF = (1<<29);

	const int MAX_V = 100;
	int cost[MAX_V][MAX_V]; // cost[u][v] は辺 e = (u, v) のコストが最初に入っている。存在しない場合はINF。
	int d[MAX_V]; // d[v]は最終的に「スタートの頂点sから頂点vの最短距離」が入る。
	bool used[MAX_V];
	int V; // Vに値を入れることも忘れずに！

    int prev[MAX_V]; // 頂点sからvへの最短路で、vの直前のノードがprev[v]となる


	void dijk(int s){
		fill(used, used+V, false);
		fill(d, d+V, INF);
        fill(prev, prev+V, -1);
		d[s] = 0;
		while(1){
			int v = -1;
			REP(i, V) if(!used[i] && (v == -1 || d[i] < d[v])) v = i;
			if(v == -1) break;
			used[v] = true;
			REP(i, V) if(d[i] > d[v] + cost[v][i]){
                d[i] = d[v] + cost[v][i];
                prev[i] = v;
            }
		}
	}
    
    // 頂点sから頂点tへの最短路
    VI get_path(int t){
        VI path;
        for(; t != -1; t = prev[t]) path.push_back(t);
        reverse(ALL(path));
        return path;
    }
}



//--------------------------------
//ワーシャル-フロイド法による全点対最短路検出。
//O(|V|^3)。

//同時に、経路復元も出来るようにしている。
//また、負閉路検出もしている。

//REP(k, V) が最初なので注意

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

namespace _bipartite_matching{
    const int MAX_V = 110;
    
    int V; // 左の頂点数。忘れずに設定すること。
    // ちなみに、Vは左右合わせた全部の頂点数でも問題ない。（左が終わった後に右からのをチェックしても、マッチ数は絶対増えない）
    
    
    VI G[MAX_V]; // ちゃんとGもケースごとに全部clear。
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
//強連結成分分解。

namespace strongly_connected_component{
    const int MAX_V = 100;
    
    int V;
    VI G[MAX_V];
    VI rG[MAX_V];
    VI vs;
    bool used[MAX_V];
    int cmp[MAX_V];
    
    void add_edge(int from, int to){
        G[from].push_back(to);
        rG[to].push_back(from);
    }
    
    void dfs(int v){
        used[v] = true;
        REP(i, SZ(G[v])) if(!used[G[v][i]]) dfs(G[v][i]);
        vs.push_back(v);
    }
    
    void rdfs(int v, int k){
        used[v] = true;
        cmp[v] = k;
        REP(i, SZ(rG[v])) if(!used[rG[v][i]]) rdfs(rG[v][i], k);
    }
    
    // 強連結成分の数をついでに返す。
	// 強連結成分の１番末尾の番号（cmp[]に入ってる）は、k-1なので注意。
    int scc(){
        MSET(used, false);
        vs.clear();
        int k = 0;
        REP(v, V) if(!used[v]) dfs(v);
        MSET(used, false);
        for(int i = SZ(vs) - 1; i >= 0; i--)
            if(!used[vs[i]]) rdfs(vs[i], k++);
        return k;
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
	
	// CCW : ConterClockWise
	// 3頂点を回った時、反時計回りなら正
	// 一直線上の場合、0になる。
	double ccw(P p1, P p2, P p3){
		return (p2-p1).det(p3-p1);
	}
	
	// 三角形の面積。反時計回りなら正
	double triangleArea(P p1, P p2, P p3){
		return ((p2-p1).det(p3-p1))/2;
	}
    
}


//--------------------------------
//二次元ベクトル系ライブラリ。
//整数のみで処理する場合。

namespace vec2{
    
    struct P{
        LL x, y;
        P() {}
        P(LL x, LL y) : x(x), y(y){
        }
        P operator + (P p){
            return P(x+p.x, y+p.y);
        }
        P operator - (P p){
            return P(x-p.x, y-p.y);
        }
        P operator * (LL d){
            return P(x*d, y*d);
        }
        LL dot(P p){ // 内積
            return x*p.x + y*p.y;
        }
        LL det(P p){ // 外積
            return x*p.y - y*p.x;
        }
    };
    
    
    //線分p1-p2と線分p3-p4が交差していたら、trueを返す。
    //線分が重なっている場合はfalseを返す。
    //端点で交わっている場合もfalseを返す。
    bool intersect(P p1, P p2, P p3, P p4){
        LL t1 = (p1.x - p2.x) * (p3.y - p1.y) + (p1.y - p2.y) * (p1.x - p3.x);
        LL t2 = (p1.x - p2.x) * (p4.y - p1.y) + (p1.y - p2.y) * (p1.x - p4.x);
        LL t3 = (p3.x - p4.x) * (p1.y - p3.y) + (p3.y - p4.y) * (p3.x - p1.x);
        LL t4 = (p3.x - p4.x) * (p2.y - p3.y) + (p3.y - p4.y) * (p3.x - p2.x);
    //t1*t2やt3*t4は結構大きくなるので（座標の4乗くらい）、やばかったらdoubleを使うこと。
        if(t1*t2 < 0 && t3*t4 < 0) return true;
        return false;
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
	LL dist(P p, P q){
		return (p - q).dot(p - q);
	}
	
	// CCW : ConterClockWise
	// 3頂点を回った時、反時計回りなら正
	// 一直線上の場合、0になる。
	LL ccw(P p1, P p2, P p3){
		return (p2-p1).det(p3-p1);
	}
	
	// 三角形の面積。反時計回りなら正
	double triangleArea(P p1, P p2, P p3){
		return ((p2-p1).det(p3-p1))/2.0;
	}
    
}


//--------------------------------
// 連立方程式。O(n);

namespace gauss_jordan{
    const double EPS = 1e-8;
    typedef vector<double> vec;
    typedef vector<vec> mat;
    
    // Ax = b を解く　Aは正方行列
    // 解が無いか、一意でない場合は長さ０の配列を返す
    vec gauss_jordan(const mat& A, const vec& b){
        int n = SZ(A);
        mat B(n, vec(n + 1));
        REP(i, n) REP(j, n) B[i][j] = A[i][j];
        REP(i, n) B[i][n] = b[i];
        
        REP(i, n){
            int pivot = i;
            FOR(j, i, n) if(abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
            swap(B[i], B[pivot]);
            if(abs(B[i][i]) < EPS) return vec();
            for(int j = i + 1; j <= n; j++) B[i][j] /= B[i][i];
            REP(j, n) if(i != j) for(int k = i + 1; k <= n; k++) B[j][k] -= B[j][i] * B[i][k];
        }
        vec x(n);
        REP(i, n) x[i] = B[i][n];
        return x;
    }
}




//--------------------------------
// 数え上げ問題
// n個のボールを、m個の箱に入れる

// ①nが区別できるか ②mが区別できるか ③分割の方法
// で 2*2*3 = 12 通り

namespace count{
    const int MAX_N = 100, MAX_M = 100;
    LL dp[MAX_N][MAX_M];
    LL C[MAX_N+1][MAX_M+1];
    
    void makepas(){
		REP(i, MAX_N+1) REP(j, MAX_N+1) C[i][j] = 0;
		C[0][0] = 1;
        for(int i=1; i<=MAX_N; i++){
            C[i][0] = 1;
            C[i][i] = 1;
            for(int j=1; j<i; j++){
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
            }
        }
	}    
    
    void add(LL &a, LL b){
		a = (a + b) % MOD;
	}
    
    void sub(LL &a, LL b){
		a = (a - b + MOD) % MOD;
	}
    
    void mul(LL &a, LL b){
		a = (a * b) % MOD;
	}
    
    
    // 1-1-1
    // n: 区別できる
    // m: 区別できる
    // ちょうどm個への分割（最低一個は入れる）
    
    // S(n, m) = S(n-1, m)*m + S(n-1, m-1)*m
    
    int count_1_1_1(int n, int m){
		
//		cout << endl;
//		OUT2(n, m);
		
		//包除原理
		LL res = 0;
		makepas();
		for(int i = 1; i <= m; i++){
			LL tmp = (C[m][i] * modPow(i, n)) % MOD;
			if((m-i)&1) sub(res, tmp);
			else add(res, tmp);
		}
//		OUT(res);
		
		//dp
		MSET(dp, 0); dp[0][0] = 1;
		for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
			LL tmp = 0;
			add(tmp, (dp[i-1][j] * j)  % MOD);   // i-1個のボールがj個の箱に入っている状態で、i個目のボールを入れる場合
			add(tmp, (dp[i-1][j-1] * j)  % MOD); // i-1個のボールがj-1個の箱に入っている状態で、i個目のボールは新しい箱に入れる場合
			add(dp[i][j], tmp);
		}
//		OUT(dp[n][m]);
		
		return res;
	}
    
    
    // 1-1-2
    // n: 区別できる
    // m: 区別できる
    // m個以下への分割
    int count_1_1_2(int n, int m){
		cout << endl;
		OUT2(n, m);
		
		int res = modPow(m, n);
		OUT(res);
		return res;
	}
    
    
    // 1-1-3
    // n: 区別できる
    // m: 区別できる
    // 箱には高々1個しか入らない（n > m のとき 0）
    int count_1_1_3(int n, int m){
		cout << endl;
		OUT2(n, m);
		
		// mPn を返せば良い
		LL res;
		if(n > m) res = 0;
		else{
			res = 1;
			while(n--) mul(res, m--);
		}
		
		OUT(res);
		return res;
	}
    
    
    // 1-2-1
    // n: 区別できる
    // m: 区別できない
    // ちょうどm個への分割（最低一個は入れる）
    
    // 第二種スターリング数と呼ばれる
    // S(n, m) = S(n-1, m)*m + S(n-1, m-1)
    
    int count_1_2_1(int n, int m){
//		cout << endl;
//		OUT2(n, m);
		
		// 1-1-1をm!で割る。
		// MODが素数の時のみ可。
		LL res = modDivision(count_1_1_1(n, m), modFact(m));
//		OUT(res);
		
		
		//dpでやる場合
		MSET(dp, 0); dp[0][0] = 1;
		for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
			LL tmp = 0;
			add(tmp, (dp[i-1][j] * j)  % MOD);   // i-1個のボールがj個の箱に入っている状態で、i個目のボールを入れる場合。この場合はj通り区別できる。
			add(tmp, dp[i-1][j-1]); // i-1個のボールがj-1個の箱に入っている状態で、i個目のボールは新しい箱に入れる場合。この場合は区別できない。
			add(dp[i][j], tmp);
		}
//		OUT(dp[n][m]);
		
		return res;
	}
    
    
    
    // 1-2-2
    // n: 区別できる
    // m: 区別できない
    // m個以下への分割
    
    // n = m のとき、ベル数と呼ばれる。
    // ベル数は「n個の区別できるものを、空でないいくつかのまとまりに分ける場合の数」
    
    int count_1_2_2(int n, int m){
		cout << endl;
		OUT2(n, m);
		
		LL res = 0;
		
		// 1-2-1を全部足し合わせる。
		// 例えば、n=10, m=7だったら、「箱が1個」「箱が2個」・・・「箱が7個」を足し合わせる。
		for(int i = 1; i <= m; i++) add(res, count_1_2_1(n, i)); 
		OUT(res);
		
		
		// dpでやる場合
		// 1-2-1のdpを前もってやっとく。
		// そして例えば、1-2-2のdp[10][7]を計算するときは、1-2-2のdp[10][6]（この中に、箱１個使う～箱６個使う、が全て含まれている）と、
		// 1-2-1のdp[10][7]（箱７個使う）を足せば良い。
		// もちろん、答えが欲しいだけなら、1-2-1のdp[10][1]～dp[10][7]を足せば良い。
		
		LL dp1[MAX_N][MAX_M];
		MSET(dp1, 0); dp1[0][0] = 1;
		for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
			LL tmp = 0;
			add(tmp, (dp1[i-1][j] * j)  % MOD);
			add(tmp, dp1[i-1][j-1]);
			add(dp1[i][j], tmp);
		}
		
		LL dp2[MAX_N][MAX_M];
		MSET(dp2, 0);
		for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
			add(dp2[i][j], dp2[i][j-1]);
			add(dp2[i][j], dp1[i][j]);
		}
		OUT(dp2[n][m]);
		
		
		return res;
	}
	
	
	
	// 1-2-2に付随して、ベル数。
    // ベル数は「n個の区別できるものを、空でないいくつかのまとまりに分ける場合の数」
    // B(n+1) = Σ(C[n][k]*B(k))
    
    // 上記の式の考え方。例えばB(9)を計算するときは、
    // 「1～8番のボールのうち、9番と一緒にしないボールをk個選ぶ。このk個のバラけ方はB(k)」
    // であり、kを0～8ととして足せば良い。
    
    int bell(int n){
		cout << endl;
		OUT(n);
		
		makepas();
		
		LL dp[MAX_N];
		MSET(dp, 0); dp[0] = 1;
		for(int i = 1; i <= n; i++) for(int j = 0; j <= i-1; j++) add(dp[i], (C[i-1][j]*dp[j])%MOD);
		
		LL res = dp[n];
		OUT(res);
		return res;
	}
    
    
    
    // 1-2-3
    // n: 区別できる
    // m: 区別できない
    // 箱には高々1個しか入らない（n > m のとき 0）
    int count_1_2_3(int n, int m){
		cout << endl;
		OUT2(n, m);
		
		LL res;
		if(n > m) res = 0;
		else res = 1;
		
		OUT(res);
		return res;
	}
    
    
    // 2-1-1
    // n: 区別できない
    // m: 区別できる
    // ちょうどm個への分割（最低一個は入れる）
    int count_2_1_1(int n, int m){
		cout << endl;
		OUT2(n, m);
		
		// n個並べたボールの合間にm-1個の仕切りを入れる。
		// C[n-1][m-1]
		
		LL res;
		
		if(n == 0 || m == 0) res = 0;
		else{
			makepas();
			res = C[n-1][m-1];
		}
		
		// 包除原理でもいい。
		
		OUT(res);
		return res;
	}
    
    
    // 2-1-2
    // n: 区別できない
    // m: 区別できる
    // m個以下への分割
    int count_2_1_2(int n, int m){
		cout << endl;
		OUT2(n, m);
		
		LL res;
		
		// 重複組合せ。nHm。
		if(n == 0 || m == 0) res = 0;
		else{
			makepas();
			res = C[n+m-1][m-1]; // 3H5 だったら、8個のボールを5個の箱に、必ず一つ入れると考える
		}
		
		// ちなみにdpでやると
		MSET(dp, 0); dp[0][0] = 1;
		for(int i = 0; i <= n; i++) for(int j = 1; j <= m; j++){
			for(int k = 0; k <= i; k++) add(dp[i][j], dp[i-k][j-1]); // j番目の箱にはk個入れる。合計i個になるように。
		}
		
		OUT(res);
		OUT(dp[n][m]);
		return res;
	}
    
    
    // 2-1-3
    // n: 区別できない
    // m: 区別できる
    // 箱には高々1個しか入らない（n > m のとき 0）
    int count_2_1_3(int n, int m){
		cout << endl;
		OUT2(n, m);
		
		makepas();
		LL res = C[m][n];
		
		
		OUT(res);
		return res;
	}
    
    
    // 2-2-1
    // n: 区別できない
    // m: 区別できない
    // ちょうどm個への分割（最低一個は入れる）
    int count_2_2_1(int n, int m){
		cout << endl;
		OUT2(n, m);
		
		MSET(dp, 0); dp[0][0] = 1;
		for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
			add(dp[i][j], dp[i-1][j-1]); // ボール1個の箱が少なくとも1つある場合。1個箱に入れて、残りi-1個をj-1個の箱に分ける。
			if(i >= j) add(dp[i][j], dp[i-j][j]); // ボール1個の箱が無い場合。まず1個づつ、j個の箱に入れてしまう。残りi-j個をj個の箱に分ける。 
		}
		
		LL res = dp[n][m];
		OUT(res);
		return res;
	}
    
    
    // 2-2-2
    // n: 区別できない
    // m: 区別できない
    // m個以下への分割
    int count_2_2_2(int n, int m){
		cout << endl;
		OUT2(n, m);
		
		// 2-2-1を計算して、1～mのsumをとっても良い。
		MSET(dp, 0); dp[0][0] = 1;
		for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
			add(dp[i][j], dp[i-1][j-1]); 
			if(i >= j) add(dp[i][j], dp[i-j][j]); 
		}
		
		LL res = 0;
		for(int i = 1; i <= m; i++) add(res, dp[n][i]);
		OUT(res);
		
		// もしくは、
		MSET(dp, 0); dp[0][0] = 1;
		for(int i = 0; i <= n; i++) for(int j = 1; j <= m; j++){
			add(dp[i][j], dp[i][j-1]); // j-1個以下の箱に入れる場合
			if(i >= j) add(dp[i][j], dp[i-j][j]); // 必ずj個使う場合（最初に一個づつ入れてしまう））
		}
		OUT(dp[n][m]);
		
		return res;
	}
    
    
    // 2-2-3
    // n: 区別できない
    // m: 区別できない
    // 箱には高々1個しか入らない（n > m のとき 0）
    int count_2_2_3(int n, int m){
		cout << endl;
		OUT2(n, m);
		
		LL res;
		if(n > m) res = 0;
		else res = 1;
		
		OUT(res);
		return res;
	}
	
	
	// カタラン数 C(n)
	// ・n対のpush・popの正しい並べ方
	// ・n対の括弧の正しい並べ方
	// ・n*nの格子で(1, 1)から(n, n)に対角線より反対に行かないような行き方
	// ・n+1チームのトーナメント
	// ・n+1項目の足し算の括弧の付け方 1+((2+3)+4) とか
	// ・1～2nの数字を2×nの枠に、上から下、左から右に大きくなるような並べ方
	// ・n+2角形の三角形への分け方
	// ・2n人が輪になって手を交差しないような手のつなぎ方
	// 　　・・・など
	int catalan(int n){
		OUT(n);
		
		makepas();
		int res = C[2*n][n] - C[2*n][n-1];
		// C[2*n][n] / (n+1) ともかける
		res = (res + MOD) % MOD;
		
		
		// トーナメント戦で、iチームのトーナメント戦は、
		// jチームのトーナメントの優勝者 対 i-jチームのトーナメントの優勝者
		// と考えると
		LL dp[100];  MSET(dp, 0);
		dp[1] = 1;
		for(int i = 2; i <= n+1; i++){
			for(int j = 1; j < i; j++) add(dp[i], (dp[j]*dp[i-j]) % MOD);
		}
		OUT(dp[n+1]);
		
		OUT(res);
		return res;
	}
	
	
	
	// おまけ
	// 1～nのボールを、1～nの箱に、番号が異なるように入れる入れ方
	int diffcnt(int n){
		OUT(n);
		
		// 包除原理でもできるはず
		
		LL dp[100];  MSET(dp, 0);
		dp[1] = 0; dp[2] = 1;
		for(int i = 3; i <= n; i++) dp[i] = ((i-1) * ((dp[i-2] + dp[i-1]) % MOD)) % MOD;
		// まず、i番のボールを1～i-1のどれかの箱に入れる（これでi-1通り）（k番の箱に入れたとする）
		// dp[i-2] は、k番のボールをi番の箱に入れた時。
		// dp[i-1] は、k番のボールをi番の箱に入れない時。このとき、1～i-1番のボール全て、入れられない箱が1個あるわけだから、結局dp[i-1]となる。
		
		LL res = dp[n];
		OUT(res);
		return res;
	}
	
	
}



//--------------------------------
//有名問題集。

namespace prob{
    
    // 最大部分列和 (Maximum Segment Sum : MSS)
    // {3,-4,2,3,-1,2}であれば6が解
    // O(n)
    // 下記のO(n)解法はそんなに直感的ではない
    int MSS(vector<int> a){
        int mss, s;
        mss = s = 0;
        REP(i, SZ(a)){
            s += a[i];
            chmax(s, 0); // 0を下回ったらリセット
            chmax(mss, s);
        }
        return mss;
    }
    
    // 最長増加部分列 (Longest Increasing Subsequence : LIS)
    // {40,10,20,50,30,35} であれば{10,20,30,35}が解
    // O(nlogn)
    vector<int> LIS(vector<int> a){
        int dp[100]; REP(i, 100) dp[i] = INF;
        REP(i, SZ(a)) *lower_bound(dp, dp+100, a[i]) = a[i]; //「a[i]を最後尾とするような最長増加部分列の長さ」をk+1としたとき、dp[k]を（a[i]のほうが小さければ）更新していく。
        vector<int> res;
        REP(i, lower_bound(dp, dp+100, INF)-dp) res.push_back(dp[i]);
        return res;
    }
    
    // 最長共通部分列 (Longest Common Subsequence : LCS)
    // 例えば"abcfbc" と "abfcab" であれば "abfc" や "abcb" の長さが解
    // O(n*m)
    int LCS(string s1, string s2){
		int dp[100][100]; MSET(dp, 0);
		for(int i = 1; i <= SZ(s1); i++) for(int j = 1; j <= SZ(s2); j++){
			if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1; // 最後の一文字が一緒であれば、両方一文字前までの値+1
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);// 最後の一文字が異なっていれば、片方一文字前までの値の大きい方
		}
		int res = dp[SZ(s1)][SZ(s2)];
		return res;
	}
	
	// 編集距離 (レーベンシュタイン距離, Levenshtein Distance) 
	// 削除と挿入でコスト１
	// 例えば"darling" と"airline"であれば
	// darling → arling → airling → airlin → airline の4手が解
	// O(n*m)
	// LCSと考え方は似ている
	 int LD(string s1, string s2){
		int dp[100][100]; MSET(dp, 0);
		for(int i = 1; i <= SZ(s1); i++) dp[i][0] = i;
		for(int j = 1; j <= SZ(s2); j++) dp[0][j] = j;
		for(int i = 1; i <= SZ(s1); i++) for(int j = 1; j <= SZ(s2); j++){
			if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]; // 最後の一文字が一緒であれば、両方一文字前のコストと同じ
			else dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1); // 最後の一文字が異なっていれば、片方一文字前の状態に一文字挿入
		}
		int res = dp[SZ(s1)][SZ(s2)];
		
		// 更新でもコスト１とする場合
		// darling → arling → airling → airline の3手が解
		MSET(dp, 0);
		for(int i = 1; i <= SZ(s1); i++) dp[i][0] = i;
		for(int j = 1; j <= SZ(s2); j++) dp[0][j] = j;
		for(int i = 1; i <= SZ(s1); i++) for(int j = 1; j <= SZ(s2); j++){
			if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]; 
			else dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+1); 
		}
		OUT(dp[SZ(s1)][SZ(s2)]);
		
		return res;
		
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
				VI d(c,&c[4]); //こんな初期化も出来る
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
                //OUT(_nCr(0,1));
                //OUT(_nCr(1,1));
                //OUT(_nCr(1,0));
                //OUT(_nCr(10,0));
                //OUT(_nCr(10,1));
                //OUT(_nCr(10,3));
                //OUT(_nCr(10,10));
                //OUT(_nCr(10,11));
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
//            case 30 : {// Union_Find
//                Union_Find uf(6);
//				uf.unite(0,1);
//				uf.unite(0,3);
//				uf.unite(2,4);
//				uf.unite(4,5);
//				OUT(1);
//				OUT(uf.same(0,3));
//				OUT(uf.same(2,5));
//				OUT(uf.same(0,5));
//				uf.unite(4,100);
//				OUT(uf.same(0,100));
//				OUT(uf.same(4,100));
//				OUT(uf.same(4,120));
//				OUT(uf.find(1111));
//				//OUT(uf.same(-5,120));
//                return 1;
//            }
                
            case 40 : {
                _bipartite_matching::V = 4;
                return 1;
            }
            case 50 : {
//                count::count_1_2_2(1,1);
//                count::count_1_2_2(1,2);
//                count::count_1_2_2(1,3);
//                count::count_1_2_2(1,4);
//                count::count_1_2_2(1,5);
//                count::count_1_2_2(2,1);
//                count::count_1_2_2(2,2);
//                count::count_1_2_2(2,3);
//                count::count_1_2_2(2,4);
//                count::count_1_2_2(2,5);
//                count::count_1_2_2(3,1);
//                count::count_1_2_2(3,2);
//                count::count_1_2_2(3,3);
//                count::count_1_2_2(3,4);
//                count::count_1_2_2(3,5);
//                count::count_1_2_2(4,1);
//                count::count_1_2_2(4,2);
//                count::count_1_2_2(4,3);
//                count::count_1_2_2(4,4);
//                count::count_1_2_2(4,5);
//                count::count_1_2_2(5,1);
//                count::count_1_2_2(5,2);
//                count::count_1_2_2(5,3);
//                count::count_1_2_2(5,4);
//                count::count_1_2_2(5,5);
//                count::count_1_2_2(99,60);

                count::diffcnt(2);
                count::diffcnt(3);
                count::diffcnt(4);
                
                return 1;
            }
            case 60 : {
                int a[5] = {3,-1,4,-2,-1};
                VI b(a, &a[5]);
                OUT(prob::MSS(b));
                int c[6] = {40,10,20,50,30,35};
                VI d(c, &c[6]);
                OUT(prob::LIS(d));
                OUT(prob::LCS("abcfbc","abfcab"));
                OUT(prob::LD("abc","ab"));
                OUT(prob::LD("darling","airline"));
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
