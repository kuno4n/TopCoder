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

vector<string> board;

bool okl[101][101][101];
bool okt[101][101][101];


class TheMatrix {
public:
    int MaxArea(vector<string> _board) {
        board = _board;
        int h = SZ(board);
        int w = SZ(board[0]);
        // MSET(okl, false);
        // MSET(okt, false);
        // int res = 1;
        // REP(i, h){
        //     REP(j, w){
        //         okl[i][j][0] = true;
        //         for(int k = 1; i+k < h; k++){
        //             okl[i][j][k] = okl[i][j][k-1] & (board[i+k][j]!=board[i+k-1][j]);
        //             if(okl[i][j][k]) chmax(res, k+1);
        //         }
        //         okt[i][j][0] = true;
        //         for(int k = 1; j+k < w; k++){
        //             okt[i][j][k] = okt[i][j][k-1] & (board[i][j+k]!=board[i][j+k-1]);
        //             if(okt[i][j][k]) chmax(res, k+1);
        //         }
        //     }
        // }
        // // OUT(okt[0][0][1]);
        // REP(i, h){
        //     REP(j, w){
        //         for(int k = 1; j+k < w; k++) if(okt[i][j][k]){
        //             for(int l = 1; i+l < h; l++){
        //                 if(!okt[i+l][j][k]) break;
        //                 if(!okl[i][j][l]) break;
        //                 chmax(res, (k+1)*(l+1));
        //             }
        //         }
        //     }
        // }

        // int res = 0;
        // REP(i, w){
        //     FOR(j, i, w){
        //         int cnt = 0;
        //         REP(k, h){
        //             bool ok = true;
        //             for(int l = i+1; l <= j; l++) ok &= (board[k][l] != board[k][l-1]);
        //             if(ok){
        //                 if(cnt > 0 && board[k][i] != board[k-1][i]) cnt++;
        //                 else cnt = 1;
        //             }
        //             else cnt = 0;
        //             chmax(res, cnt * (j-i+1)); 
        //         }
        //     }
        // }

        int left[101][101];
        REP(i, 101) REP(j, 101) left[i][j] = 1;
        REP(i, h) FOR(j, 1, w) if(board[i][j] != board[i][j-1]) left[i][j] = left[i][j-1]+1;
        int res = 0;
        REP(i, h) REP(j, w){
            chmax(res, left[i][j]);
            int mnw = left[i][j];
            for(int k = i-1; k >= 0; k--){
                if(board[k][j] == board[k+1][j]) break;
                chmin(mnw, left[k][j]);
                chmax(res, (i-k+1)*mnw);
            }
        }

        return res;
    }
};

// CUT begin
ifstream data("TheMatrix.sample");

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

bool do_test(vector<string> board, int __expected) {
    time_t startClock = clock();
    TheMatrix *instance = new TheMatrix();
    int __result = instance->MaxArea(board);
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
        vector<string> board;
        from_stream(board);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(board, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1421991869;
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
        cout << "TheMatrix (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
