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

vector<string> P;
vector<string> Q;

int dp[2][25100][2];
const int INF = (1<<29);

class CombinationLockDiv1 {
public:
    int minimumMoves(vector<string> _P, vector<string> _Q) {
        P = _P, Q = _Q;
        string s, t;
        REP(i, SZ(P)) s += P[i];
        REP(i, SZ(Q)) t += Q[i];
        int n = SZ(s);
        int diff[2510][2];
        REP(i, n) diff[i][0] = ((s[i]-'0') - (t[i]-'0') + 10) % 10;
        REP(i, n) diff[i][1] = (10-diff[i][0]) % 10;
        REP(i, 2) REP(j, 25100) REP(k, 2) dp[i][j][k] = INF;
        REP(j, 25100) if(j%10 == diff[0][0]) dp[0][j][0] = j;
        REP(j, 25100) if(j%10 == diff[0][1]) dp[0][j][1] = j;
        REP(i, n-1){
            int ni = i+1;
            REP(j, 25100){
                REP(k, 2){
                    dp[ni&1][j][k] = INF;
                }
            }
            REP(j, 25000){
                REP(k, 2){
                    int cur = dp[i&1][j][k];
                    if(cur == INF) continue;
                    chmin(dp[ni&1][diff[i+1][0]][0], cur + diff[i+1][0]);
                    chmin(dp[ni&1][diff[i+1][1]][1], cur + diff[i+1][1]);
                    int now = j%10;
                    int nxt = diff[i+1][k];
                    if(now >= nxt){
                        chmin(dp[ni&1][j-now+nxt][k],    cur);
                        chmin(dp[ni&1][j-now+nxt+10][k], cur+(10-now)+nxt);
                    }
                    else if(now < nxt){
                        chmin(dp[ni&1][j-now+nxt][k], cur+(nxt-now));
                        if(j >= 10) chmin(dp[ni&1][j-now-10+nxt][k], cur);
                    }
                }
            }
        }
        int res = INF;
        REP(j, 25000) REP(k, 2) chmin(res ,dp[(n-1)&1][j][k]);
        return res;
    }
};

// const int INF = (1<<29);
// int dp[55][450][2];


// class CombinationLockDiv2 {
//     public:
//     int minimumMoves(string S, string T) {
//         int n = SZ(S);
//         int dif[n];
//         REP(i, n) dif[i] = (T[i]-'0'+10 - (S[i]-'0')) % 10;
        
//         REP(i, n) REP(j, 450) REP(k, 2) dp[i][j][k] = INF;
//         REP(j, 450){
//             if(j % 10 == dif[0]) dp[0][j][0] = j;
//             if((1000-j) % 10 == dif[0]) dp[0][j][1] = j;
//         }
//         for(int i = 1; i < n; i++){
//             REP(j, 450) REP(k, 450){
//                 if(k % 10 == dif[i]){
//                     chmin(dp[i][k][0], dp[i-1][j][1] + k);
//                     if(j > k) chmin(dp[i][k][0], dp[i-1][j][0]);
//                     else chmin(dp[i][k][0], dp[i-1][j][0] + (k-j));
//                 }
//                 if((1000-k) % 10 == dif[i]){
//                     chmin(dp[i][k][1], dp[i-1][j][0] + k);
//                     if(j > k) chmin(dp[i][k][1], dp[i-1][j][1]);
//                     else chmin(dp[i][k][1], dp[i-1][j][1] + (k-j));
//                 }
//             }
//         }
//         int res = INF;
//         REP(j, 450) REP(k, 2) chmin(res, dp[n-1][j][k]);
//         return res;
//     }
// };

// CUT begin
ifstream data("CombinationLockDiv1.sample");

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

bool do_test(vector<string> P, vector<string> Q, int __expected) {
    time_t startClock = clock();
    CombinationLockDiv1 *instance = new CombinationLockDiv1();
    int __result = instance->minimumMoves(P, Q);
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
        vector<string> P;
        from_stream(P);
        vector<string> Q;
        from_stream(Q);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(P, Q, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1421899522;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 475 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "CombinationLockDiv1 (475 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
