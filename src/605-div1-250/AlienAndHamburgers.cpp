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

vector<int> type;
vector<int> taste;

class AlienAndHamburgers {
public:
    int getNumber(vector<int> _type, vector<int> _taste) {
        type = _type, taste = _taste;

        int res = 0;
        set<int> s;
        vector<pair<int, int> > vp;
        REP(i, SZ(type)) vp.push_back(make_pair(taste[i], type[i]));
        sort(ALL(vp));
        reverse(ALL(vp));
        int sum = 0;
        REP(i, SZ(vp)){
            if(vp[i].first < 0 && s.find(vp[i].second) != s.end()) continue;
            sum += vp[i].first;
            s.insert(vp[i].second);
            chmax(res, SZ(s)*sum);
        }
        return res;
        // VI a[110];
        // REP(i, SZ(type)) a[type[i]].push_back(taste[i]);
        // REP(i, 110){
        //     sort(ALL(a[i]));
        //     reverse(ALL(a[i]));
        // }
        // int res = 0;
        // int ty = 0;
        // int ta = 0;
        // REP(i, 110) if(SZ(a[i]) && a[i][0] >= 0){
        //     ty++;
        //     REP(j, SZ(a[i])) if(a[i][j] >= 0) ta += a[i][j];
        // }
        // chmax(res, ty*ta);

        // VI b;
        // REP(i, 110) if(SZ(a[i]) && a[i][0] < 0){
        //         b.push_back(a[i][0]);
        // }
        // sort(ALL(b));
        // reverse(ALL(b));
        // REP(i, SZ(b)){
        //     ty++;
        //     ta += b[i];
        //     chmax(res, ty*ta);
        // }

        // return res;
    }
};

// CUT begin
ifstream data("AlienAndHamburgers.sample");

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

bool do_test(vector<int> type, vector<int> taste, int __expected) {
    time_t startClock = clock();
    AlienAndHamburgers *instance = new AlienAndHamburgers();
    int __result = instance->getNumber(type, taste);
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
        vector<int> type;
        from_stream(type);
        vector<int> taste;
        from_stream(taste);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(type, taste, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1421807922;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "AlienAndHamburgers (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
