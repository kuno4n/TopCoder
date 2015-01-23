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

vector<string> m;
int n;

int sol(int mask){
    bool vis[n][n];
    MSET(vis, false);
    int res = 0;
    REP(i, n*4) if((1<<i)&mask){
        int pos = i%n;
        if(i/n == 0){
            REP(j, n){
                if(vis[j][pos]) return 0;
                vis[j][pos] = true;
                if(m[j][pos] == 'Y'){
                    res++;
                    break;
                }

            }
        }
        if(i/n == 1){
            for(int j = n-1; j >= 0; j--){
                if(vis[pos][j]) return 0;
                vis[pos][j] = true;
                if(m[pos][j] == 'Y'){
                    res++;
                    break;
                }

            }
        }
        if(i/n == 2){
            for(int j = n-1; j >= 0; j--){
                if(vis[j][pos]) return 0;
                vis[j][pos] = true;
                if(m[j][pos] == 'Y'){
                    res++;
                    break;
                }

            }
        }
        if(i/n == 3){
            REP(j, n){
                if(vis[pos][j]) return 0;
                vis[pos][j] = true;
                if(m[pos][j] == 'Y'){
                    res++;
                    break;
                }

            }
        }
    }
    return res;
}

class ElephantDrinkingEasy {
public:
    int maxElephants(vector<string> _map) {
        m = _map;
        n = SZ(m);
        int res = 0;
        REP(i, (1<<(n*4))) chmax(res, sol(i));
        return res;
    }
};

// CUT begin
ifstream data("ElephantDrinkingEasy.sample");

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

bool do_test(vector<string> map, int __expected) {
    time_t startClock = clock();
    ElephantDrinkingEasy *instance = new ElephantDrinkingEasy();
    int __result = instance->maxElephants(map);
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
        vector<string> map;
        from_stream(map);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(map, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1422000230;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "ElephantDrinkingEasy (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
