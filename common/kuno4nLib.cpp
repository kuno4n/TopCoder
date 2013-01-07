
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
long long c(int n, int k);

long long _Pow(long long x, long long y);
long long modPow(long long x, long long y);
long long modInverse(long long x);
long long modDivision(long long p, long long q);
long long modC(long long n, int k);

//class Union_Find{
//private:
//	vector <int> par;
//	vector <int> rank;
//public:
//	Union_Find(int n);
//	void init(int n);
//	int find(int x);
//	void unite(int x, int y);
//	bool same(int x, int y);
//};
    

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
long long c(int n, int k){
    if(k == 0 || n==k) return 1;
    return fact(n)/fact(n-k)/fact(k);
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
