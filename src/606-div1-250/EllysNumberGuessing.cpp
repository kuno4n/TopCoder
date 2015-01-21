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

vector<int> guesses;
vector<int> answers;

// vector<LL> intersection(vector<LL> a, vector<LL> b){
//     vector<LL> res;
//     REP(i, SZ(a)) REP(j, SZ(b)) if(a[i] == b[j]) res.push_back(a[i]);
//     return res;
// }

// bool valid(LL a){
//     return a >= 1 && a <= 1000000000;
// }

class EllysNumberGuessing {
public:
    int getNumber(vector<int> _guesses, vector<int> _answers) {
        guesses = _guesses, answers = _answers;

        int h = guesses[0] + answers[0];
        int l = guesses[0] - answers[0];
        if(h > 1000000000) h = -1;
        if(l < 1) l = -1;
        for(int i = 1; i < SZ(guesses); i++){
            int a = guesses[i] + answers[i];
            int b = guesses[i] - answers[i];
            if(h != a && h != b) h = -1;
            if(l != a && l != b) l = -1;
        }
        if(h == -1 && l == -1) return -2;
        if(h == -1 && l != -1) return l;
        if(h != -1 && l == -1) return h;
        return -1;


        // int n = SZ(guesses);
        // vector<LL> cand;
        // LL a = guesses[0] + answers[0];
        // LL b = guesses[0] - answers[0];
        // if(valid(a)) cand.push_back(a);
        // if(valid(b)) cand.push_back(b);
        // for(int i = 1; i < SZ(guesses); i++){
        //     vector<LL> _cand;
        //     a = guesses[i] + answers[i];
        //     b = guesses[i] - answers[i];
        //    if(valid(a)) _cand.push_back(a);
        //    if(valid(b)) _cand.push_back(b);
        //    cand = intersection(cand, _cand);
        // }
        // if(SZ(cand) == 0) return -2;
        // if(SZ(cand) == 2) return -1;
        // return cand[0];

        // LL res = -1;
        // vector<LL> cand;
        // REP(i, n){
        //     sort(ALL(cand));
        //     vector<LL> a;
        //     LL a1 = guesses[i] + answers[i];
        //     LL a2 = guesses[i] - answers[i];
        //     if(a1 >= 1 && a1 <= 1000000000) a.push_back(a1);
        //     if(a2 >= 1 && a2 <= 1000000000) a.push_back(a2);
        //     if(SZ(a) == 0) return -2;
        //     sort(ALL(a));
        //     if(res == -1){
        //         if(SZ(cand) == 0){
        //             cand = a;
        //         }
        //         if(SZ(cand) == 1){
        //             if(SZ(a) == 1){
        //                 if(cand[0] != a[0]) return -2;
        //                 else res = cand[0];
        //             }
        //             if(SZ(a) == 2){
        //                 if(cand[0] == a[0]){
        //                     res = cand[0];
        //                 }
        //                 else if(cand[0] == a[1]){
        //                     res = cand[0];
        //                 }
        //                 else{
        //                     return -2;
        //                 }
        //             }
        //         }
        //         if(SZ(cand) == 2){
        //             if(SZ(a) == 1){
        //                 if(cand[0] == a[0]) res = cand[0];
        //                 else if(cand[1] == a[0]) res = cand[1];
        //                 else return -2;
        //             }
        //             if(SZ(a) == 2){
        //                 if(cand[0] == a[0] && cand[1] == a[1]) continue;
        //                 if(cand[0] == a[0] || cand[0] == a[1]) res = cand[0];
        //                 else if(cand[1] == a[0] || cand[1] == a[1]) res = cand[1];
        //                 else return -2;
        //             }
        //         }
        //     }
        //     else{
        //         if(SZ(a) == 1){
        //             if(a[0] != res) return -2;
        //         }
        //         if(SZ(a) == 2){
        //             if(a[0] != res && a[1] != res) return -2;
        //         }
        //     }
        // }
        // if(res == -1 && SZ(cand) == 0) return -1;
        // if(res == -1 && SZ(cand) == 1) return cand[0];
        // if(res == -1 && SZ(cand) == 2) return -1;
        // return res;
    }
};

// CUT begin
ifstream data("EllysNumberGuessing.sample");

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

bool do_test(vector<int> guesses, vector<int> answers, int __expected) {
    time_t startClock = clock();
    EllysNumberGuessing *instance = new EllysNumberGuessing();
    int __result = instance->getNumber(guesses, answers);
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
        vector<int> guesses;
        from_stream(guesses);
        vector<int> answers;
        from_stream(answers);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(guesses, answers, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1421833939;
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
        cout << "EllysNumberGuessing (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
