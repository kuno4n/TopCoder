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

vector<int> sweets;
int n;
// VI memo[1<<10];


// int bitcnt(int bits){
//     bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
//     bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
//     bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
//     bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
//     return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
// }

// VI rec(int bit){
//     VI &res = memo[bit];
//     if(SZ(res)) return res;
//     res.push_back(0);res.push_back(0);
//     // if(bitcnt(bit) == n) return res;
//     int turn = bitcnt(bit) & 1;
//     int diff = -1000000;
//     REP(i, n) if(!(bit & (1<<i)) && sweets[i] != 0) {
//         VI tmp = rec(bit | (1<<i));
//         int mul = 1;
//         if(i > 0   && (bit & (1<<(i-1)))) mul *= 2;
//         if(i < n-1 && (bit & (1<<(i+1)))) mul *= 2;
//         tmp[turn] += sweets[i] * mul;
//         if(diff < tmp[turn]-tmp[!turn]){
//             res = tmp;
//             diff = tmp[turn]-tmp[!turn];
//         }
//     }
//     return res;
// }

int rec(int mask, int sum1, int sum2){
    bool end = true;
    int res = -1;
    REP(i, n) if(!(mask&(1<<i))) if(sweets[i] != 0){
        end = false;
        int mul = 1;
        if(i > 0   && (mask&(1<<(i-1)))) mul *= 2;
        if(i < n-1 && (mask&(1<<(i+1)))) mul *= 2;
        chmax(res, -rec(mask|(1<<i), sum2, sum1+sweets[i]*mul));
    }
    if(end){
        if(sum1 > sum2) return 1;
        if(sum1 < sum2) return -1;
        return 0;
    }
    return res;
}

class EllysCandyGame {
public:
    string getWinner(vector<int> _sweets) {
        sweets = _sweets;
        n = SZ(sweets);
        int res = rec(0, 0, 0);
        if(res == 1) return "Elly";
        if(res == -1) return "Kris";
        return "Draw";

        // REP(i, (1<<10)) memo[i].clear();
        // VI res = rec(0);

        // VI tmp;
        // tmp = memo[1];
        // OUT2(tmp[0], tmp[1]);
        // tmp = memo[2];
        // OUT2(tmp[0], tmp[1]);
        // tmp = memo[4];
        // OUT2(tmp[0], tmp[1]);
        // tmp = memo[8];
        // OUT2(tmp[0], tmp[1]);
        // tmp = memo[16];
        // OUT2(tmp[0], tmp[1]);

        // if(res[0] > res[1]) return "Elly";
        // if(res[0] < res[1]) return "Kris";
        // return "Draw";
    }
};

// CUT begin
ifstream data("EllysCandyGame.sample");

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

bool do_test(vector<int> sweets, string __expected) {
    time_t startClock = clock();
    EllysCandyGame *instance = new EllysCandyGame();
    string __result = instance->getWinner(sweets);
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
        vector<int> sweets;
        from_stream(sweets);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(sweets, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1421827197;
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
        cout << "EllysCandyGame (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
