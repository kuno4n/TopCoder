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


double pow(double x){
    return x * x;
}

double dist(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1-x2) + pow(y1-y2));
}


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


vector<int> x;
vector<int> y;
int n;

double g[22][22];
double g2[22][22];


pair<double, vector<pair<int, int> > > cal(double b){
    vector<tuple<double, int, int> >t;
    REP(i, n) REP(j, n) if(i != j) t.push_back(make_tuple(pow(b-g[i][j]), i, j));
    sort(ALL(t));
    init(n);
    double res1 = 0.0;
    vector<pair<int, int> > res2;
    REP(i, SZ(t)){
        int a = get<1>(t[i]);
        int b = get<2>(t[i]);
        if(!same(a, b)){
            res1 += get<0>(t[i]);
            res2.push_back(make_pair(a, b));
            unite(a, b);
        }
    }
    return make_pair(res1, res2);
}

class Egalitarianism2 {
public:
    double minStdev(vector<int> _x, vector<int> _y) {
        x = _x, y = _y;
        n = SZ(x);
        REP(i, n) REP(j, n) {
            if(i == j) g[i][j] = -1;
            else g[i][j] = dist(x[i], y[i], x[j], y[j]);
        }
        double tmp = 1e30;
        vector<pair<int, int> > v;
        REP(i, n) FOR(j, i+1, n) REP(k, n) FOR(l, k+1, n){
            double b = (g[i][j] + g[k][l]) / 2 + 1e-9;
            pair<double, vector<pair<int, int> > > p = cal(b);
            if(tmp > p.first){
                tmp = p.first;
                v = p.second;
            }
        }
        double s = 0.0;
        REP(i, SZ(v)) s += g[v[i].first][v[i].second];
        double b = s/(n-1);
        double res = 0.0;
        REP(i, SZ(v)) res += pow(b - g[v[i].first][v[i].second]);
        return sqrt(res/(n-1));
    }
};

// CUT begin
ifstream data("Egalitarianism2.sample");

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

bool do_test(vector<int> x, vector<int> y, double __expected) {
    time_t startClock = clock();
    Egalitarianism2 *instance = new Egalitarianism2();
    double __result = instance->minStdev(x, y);
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
        vector<int> x;
        from_stream(x);
        vector<int> y;
        from_stream(y);
        next_line();
        double __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(x, y, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1422004676;
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
        cout << "Egalitarianism2 (550 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
