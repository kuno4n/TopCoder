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

class GraphWalkWithProbabilities {
    vector<string> graph;
    vector<int> winprob;
    vector<int> looseprob;
    int Start;

    double dp[55][3010];

public:
    double findprob(vector<string> _graph, vector<int> _winprob, vector<int> _looseprob, int _Start) {
        graph = _graph, winprob = _winprob, looseprob = _looseprob, Start = _Start;

        int n = SZ(graph);
        MSET(dp, 0);

        FOR(k, 1, 3010){
        	REP(i, n){
        		REP(j, n){
        			if(graph[i][j] == '0') continue;
        			double p = winprob[j] / 100.0 + (100 - winprob[j] - looseprob[j]) / 100.0 * dp[j][k-1];
        			chmax(dp[i][k], p);
        		}
        	}
        }

        return dp[Start][3000];

        // double d[n];
        // REP(i, n) d[i] = 0.0;
        // d[Start] = 1.0;

        // priority_queue<P, vector<P>, greater<P> > q;
        // q.push(P(1.0, Start));
        // while(SZ(q)){
        // 	P p = q.top(); q.pop();
        // 	int v = p.second;
        // 	if(d[v] > p.first) continue;
        // 	REP(i, n) if(graph[v][i] == '1'){
        // 		double pr = d[v] * (100 - looseprob[i]) / 100;
        // 		if(d[i] < pr){
        // 			d[i] = pr;
        // 			q.push(P(d[i], i));
        // 		}
        // 	}
        // }

        // double res = 0.0;
        // REP(i, n) REP(j, n) if(graph[i][j] == '1' && winprob[j] > 0) chmax(res, d[i] * winprob[j] / (winprob[j] + looseprob[j]));

        // return res;
    }
};

// CUT begin
ifstream data("GraphWalkWithProbabilities.sample");

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

bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }

bool do_test(vector<string> graph, vector<int> winprob, vector<int> looseprob, int Start, double __expected) {
    time_t startClock = clock();
    GraphWalkWithProbabilities *instance = new GraphWalkWithProbabilities();
    double __result = instance->findprob(graph, winprob, looseprob, Start);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
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
        vector<int> winprob;
        from_stream(winprob);
        vector<int> looseprob;
        from_stream(looseprob);
        int Start;
        from_stream(Start);
        next_line();
        double __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(graph, winprob, looseprob, Start, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1421291450;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 950 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "GraphWalkWithProbabilities (950 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
