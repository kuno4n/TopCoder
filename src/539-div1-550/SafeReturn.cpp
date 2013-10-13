
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
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



    const int MAX_V = 110;
    
    int V; // 左の頂点数。忘れずに設定すること。
    // ちなみに、Vは左右合わせた全部の頂点数でも問題ない。（左が終わった後に右からのをチェックしても、マッチ数は絶対増えない）
    
    
    VI G[MAX_V]; // ちゃんとGもケースごとに全部clear。
    int match[MAX_V];
    bool used[MAX_V];
    
    void add_edge(int u, int v){
        G[u].PB(v);
        G[v].PB(u);
    }
    
    bool dfs(int v){
        used[v] = true;
        REP(i, SZ(G[v])){
            int u = G[v][i], w = match[u];
            if(w < 0 || (!used[w] && dfs(w))){
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }
    
    int bipartite_matching(){
        int res = 0;
        MSET(match, -1);
        REP(v, V){
            if(match[v] < 0){
                MSET(used, 0);
                if(dfs(v)) res++;
            }
        }
        return res;
    }


const int INF = (1<<29);

class SafeReturn {
public:
   int minRisk( int N, vector <string> streets ) {
	V = N+1;
	int n = SZ(streets);
	
	int g[n][n];
	REP(i, n) REP(j, n) g[i][j] = INF;
	REP(i, n) g[i][i] = 0;
	REP(i, n) REP(j, n) if(streets[i][j] != '-') g[i][j] = streets[i][j] - '0';
	REP(k, n) REP(i, n) REP(j, n) chmin(g[i][j], g[i][k]+g[k][j]);
	
	REP(i, MAX_V) G[i].clear();
	REP(i, V) REP(j, V) if(i != j){
		if(g[0][i] + g[i][j] == g[0][j]) add_edge(0, i+V), add_edge(i, j+V);
	}
	
	return V - bipartite_matching();
	
	
   }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int N                     = 3;
			string streets[]          = {"-234",
 "2---",
 "3---",
 "4---"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = SafeReturn().minRisk(N, vector <string>(streets, streets + (sizeof streets / sizeof streets[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 2;
			string streets[]          = {"-12",
 "1-1",
 "21-"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = SafeReturn().minRisk(N, vector <string>(streets, streets + (sizeof streets / sizeof streets[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 3;
			string streets[]          = {"-----7",
 "--1---",
 "-1-5--",
 "--5-1-",
 "---1-3",
 "7---3-"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = SafeReturn().minRisk(N, vector <string>(streets, streets + (sizeof streets / sizeof streets[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 2;
			string streets[]          = {"-11",
 "1-1",
 "11-"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = SafeReturn().minRisk(N, vector <string>(streets, streets + (sizeof streets / sizeof streets[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			string streets[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SafeReturn().minRisk(N, vector <string>(streets, streets + (sizeof streets / sizeof streets[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			string streets[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SafeReturn().minRisk(N, vector <string>(streets, streets + (sizeof streets / sizeof streets[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			string streets[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SafeReturn().minRisk(N, vector <string>(streets, streets + (sizeof streets / sizeof streets[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}

/*
// PROBLEM STATEMENT
// You used to worry about your popularity with the troops, but not anymore. Your priority is their safety. You are the commander of N soldiers. Each soldier has an assignment to visit a different fort. They all leave fort 0 at the same time and travel through the streets of the city at the same time until each reaches his assigned destination. This is very risky and you would want each soldier to to reach his fort as soon as possible. It is also very dangerous to go alone, thus as a secondary objective, you must minimize the number of soldiers that are exposed to risk by going over at least one street alone.

There are T locations, where T >= N+1. The locations are numbered 0 to T-1. Location 0 is the fort where all soldiers start at time 0. For each i between 1 and N, inclusive, location i is the destination fort for one of the soldiers.
The remaining locations have no specific meaning. Some pairs of locations are connected by bidirectional streets. The streets are given as a vector <string> streets. If there is no street connecting locations i and j, streets[i][j] will be '-' (quotes for clarity). Otherwise, streets[i][j] will be a digit between '1' and '9', inclusive. The digit represents the number of minutes it takes any soldier to walk along the street in either direction.

All soldiers can move at the same time, and multiple soldiers can move along the same street. If a group of soldiers reaches a fort that is the destination for one of them, that soldier enters the fort in zero time and the remaining ones keep on walking to other locations.

A soldier is safe if at each moment of his walk through the city he is accompanied by at least one other soldier.
A soldier is endangered if he is not safe, i.e., if he walks alone for some time. Remember that the primary requirement is that each soldier must use one of the (possibly many) fastest paths to his destination fort. Given this requirement, you want to choose the paths in such a way that the number of soldiers in danger is minimized. Return the smallest possible number of endangered soldiers.

DEFINITION
Class:SafeReturn
Method:minRisk
Parameters:int, vector <string>
Returns:int
Method signature:int minRisk(int N, vector <string> streets)


CONSTRAINTS
-N will be between 1 and 49, inclusive.
-streets will contain T elements, where T is between N+1 and 50, inclusive.
-Each element of streets will contain T characters.
-Each character in each element of streets will either be '-', or one of '1'-'9'.
-For each i, streets[i][i] will be '-'.
-For each pair (i,j), streets[i][j] will be equal to streets[j][i].
-For each  1 <= i <= N, there will always be at least one way of reaching location i from location 0 by using one or more streets.


EXAMPLES

0)
3
{"-234",
 "2---",
 "3---",
 "4---"}

Returns: 3

There are 3 soldiers assigned to 3 forts and 3 direct connections going from the starting fort to each of them. It is not possible for a soldier to accompany any other without losing the opportunity to reach his own fort in the minimum time possible.

1)
2
{"-12",
 "1-1",
 "21-"}

Returns: 1

The minimum time after which soldier #1 can reach fort is 1 minute and the minimum time for soldier #2 is 2 minutes. It is possible for soldier #2 to first drop soldier #1 off in his assigned fort before reaching his own one and both soldiers still reach their assigned fort in the minimum time.


2)
3
{"-----7",
 "--1---",
 "-1-5--",
 "--5-1-",
 "---1-3",
 "7---3-"}

Returns: 1



3)
2
{"-11",
 "1-1",
 "11-"}

Returns: 2



*/

// END CUT HERE
