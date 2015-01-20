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

vector<int> A;
vector<int> B;
string haveFox;

VI g[52];
int cnt[52];
int memo[52][52];

int makeTree(int v, int p){
	cnt[v] = haveFox[v] == 'Y';
	REP(i, SZ(g[v])) if(g[v][i] != p) cnt[v] += makeTree(g[v][i], v);
	return cnt[v];
}

int rec(int v, int p, int num){
	int &res = memo[v][num];
	if(res >= 0) return res;

	if(num == 0){
		res = 0;
		REP(i, SZ(g[v])) if(g[v][i] != p) res += rec(g[v][i], v, 0);
		res += cnt[v];
		return res;
	}
	int dp[52][52];
	REP(i, 52) REP(j, 52) dp[i][j] = (1<<29);
	dp[0][0] = 0;
	int pos = 0;
	REP(i, SZ(g[v])) if(g[v][i] != p){
		REP(j, 52) if(dp[pos][j] < (1<<29)) {
			REP(k, 52) if(j+k < 51){
				chmin(dp[pos+1][j+k], dp[pos][j] + rec(g[v][i], v, k));
			}
		}
		pos++;
	}
	return res = dp[pos][num-1] + abs(cnt[v] - num);
}

class FoxConnection {
public:
    int minimalDistance(vector<int> _A, vector<int> _B, string _haveFox) {
        A = _A, B = _B, haveFox = _haveFox;

        REP(i, 52) g[i].clear();
        REP(i, SZ(A)){
        	g[A[i]-1].push_back(B[i]-1);
        	g[B[i]-1].push_back(A[i]-1);
        }
        int res = (1<<29);
        REP(i, SZ(A)+1){
        	MSET(cnt, 0);
        	makeTree(i, -1);
        	MSET(memo, -1);
        	chmin(res, rec(i, -1, cnt[i]));
        }
        return res;
    }
};

// CUT begin
ifstream data("FoxConnection.sample");

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

bool do_test(vector<int> A, vector<int> B, string haveFox, int __expected) {
    time_t startClock = clock();
    FoxConnection *instance = new FoxConnection();
    int __result = instance->minimalDistance(A, B, haveFox);
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
        vector<int> A;
        from_stream(A);
        vector<int> B;
        from_stream(B);
        string haveFox;
        from_stream(haveFox);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(A, B, haveFox, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1421715687;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 550 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "FoxConnection (550 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
