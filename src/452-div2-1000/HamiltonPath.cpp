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

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset((x), (a), (int)sizeof(x))
#define VI vector < int >
#define LL long long 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = " << A << endl

int mod = 1000000007;
bool checked[60];
int N;

class HamiltonPath {
	public:
    vector <string> roads;
    
	int countPaths(vector <string> roads) {
        this->roads = roads;
		N = SZ(roads);
        REP(i, N) checked[i] = false;
        REP(i, N){
            int Ycnt = 0;
            REP(j, N) if(roads[i][j] == 'Y') Ycnt++;
            if(Ycnt >= 3) return 0;
        }
        
        int multi = 0;
        int single = 0;
        REP(i, N){
            if(checked[i]) continue;
            int Ycnt = 0;
            int next = -1;
            REP(j, N) if(roads[i][j] == 'Y') {Ycnt++; next = j;}
            if(Ycnt > 1) continue;
            if(Ycnt == 0) {
                single++;
                checked[i] = true;
                continue;
            }
            
            //Ycnt==1. start.
            multi++;
            dfs(i);
        }
        
        REP(i, N) if(!checked[i]) return 0;
        
        LL res = multi + single;
        for(int i = res-1; i>0; i--) res = (res*i) % mod;
        REP(i, multi) res = (res*2) % mod;
        
        return (int)res;
	}
    
    void dfs(int i){
        checked[i] = true;
        REP(j, N) if(roads[i][j]=='Y' && !checked[j]) dfs(j);
        return;
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
			string roads[]            = {"NYN",
 "YNN",
 "NNN"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = HamiltonPath().countPaths(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string roads[]            = {"NYYY",
 "YNNN",
 "YNNN",
 "YNNN"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = HamiltonPath().countPaths(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string roads[]            = {"NYY",
 "YNY",
 "YYN"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = HamiltonPath().countPaths(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string roads[]            = {"NNNNNY",
 "NNNNYN",
 "NNNNYN",
 "NNNNNN",
 "NYYNNN",
 "YNNNNN"};
			int expected__            = 24;

			clock_t start__           = clock();
			int received__            = HamiltonPath().countPaths(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string roads[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HamiltonPath().countPaths(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string roads[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HamiltonPath().countPaths(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string roads[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HamiltonPath().countPaths(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
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
// There are N cities in a country, numbered 0 to N-1. Each pair of cities is connected by a bidirectional road.

John plans to travel through the country using the following rules:

He must start in one city and end in another city after travelling exactly N-1 roads.
He must visit each city exactly once.
You are given a vector <string> roads. If the j-th character of the i-th element of roads is 'Y', he must travel the road that connects city i and city j.

For example, if there are three cities, and he wants to travel the road between city 0 and city 1, there are 4 possible paths: 0->1->2, 1->0->2, 2->0->1, 2->1->0. Paths 0->2->1 and 1->2->0 are not allowed because they do not allow him to travel the road between city 0 and city 1.

Return the number of paths he can choose, modulo 1,000,000,007.

DEFINITION
Class:HamiltonPath
Method:countPaths
Parameters:vector <string>
Returns:int
Method signature:int countPaths(vector <string> roads)


CONSTRAINTS
-roads will contain between 2 and 50 elements, inclusive.
-Each element of roads will contain n characters, where n is the number of elements in roads.
-Each character in roads will be 'Y' or 'N'.
-The i-th character in the i-th element of roads will be 'N'.
-The j-th character in the i-th element of roads and the i-th character in the j-th element of roads will be equal.


EXAMPLES

0)
{"NYN",
 "YNN",
 "NNN"}

Returns: 4

The example from the problem statement.

1)
{"NYYY",
 "YNNN",
 "YNNN",
 "YNNN"}

Returns: 0

It's impossible to travel all these roads while obeying the other rules.

2)
{"NYY",
 "YNY",
 "YYN"}

Returns: 0

This is also impossible.

3)
{"NNNNNY",
 "NNNNYN",
 "NNNNYN",
 "NNNNNN",
 "NYYNNN",
 "YNNNNN"}

Returns: 24



*/

// END CUT HERE
