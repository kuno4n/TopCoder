#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <fstream>
//#include "cout.h"

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



    const int MAX_N = 1000;
	int par[MAX_N];  //親
	int _rank[MAX_N]; //木の深さ
    
	// n要素で初期化
	void init(int n){
        REP(i, n){
			par[i] = i;
            _rank[i] = 0;
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
		if(_rank[x] < _rank[y]) par[x] = y;
		else{
			par[y] = x;
			if(_rank[x] == _rank[y]) _rank[x]++;
		}
	}
	//xとyが同じ集合に属するか
	bool same(int x, int y){
		return find(x) == find(y);
	}



vector<string> graph;

class BigO {
public:
    int minK(vector<string> _graph) {
        graph = _graph;
        int n = SZ(graph);
        bool g[n][n]; MSET(g, false);
        REP(i, n) REP(j, n) if(graph[i][j] == 'Y') g[i][j] = true;
        REP(k, n) REP(i, n) REP(j, n) g[i][j] |= g[i][k] && g[k][j];
        init(n);
        int loopCnt[n]; MSET(loopCnt, 0);
        REP(i, n){
        	REP(j, n) if(graph[i][j] == 'Y' && g[j][i]) unite(i, j), loopCnt[i]++;
        	if(loopCnt[i] > 1) return -1;
        }
        int g2[n][n]; MSET(g2, -1);
        REP(i, n) REP(j, n) if(loopCnt[i] > 0 && loopCnt[j] > 0 && find(i) == i && find(j) == j && !same(i, j) && g[i][j]) g2[i][j] = 1;
        REP(k, n) REP(i, n) REP(j, n) if(g2[i][k] > 0 && g2[k][j] > 0) chmax(g2[i][j], g2[i][k] + g2[k][j]);
        int res = 0;
        REP(i, n) REP(j, n) chmax(res, g2[i][j]);
        return res;
    }
};

// CUT begin
ifstream data("BigO.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<string> graph, int __expected) {
    time_t startClock = clock();
    BigO *instance = new BigO();
    int __result = instance->minK(graph);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<string> graph;
        from_stream(graph);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(graph, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1421915321;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "BigO (600 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
