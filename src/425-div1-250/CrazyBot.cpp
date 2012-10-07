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

int m;
double prob[4];
bool vis[40][40] = {false};
int vx[] = {1,-1,0,0};
int vy[] = {0,0,-1,1};

double dfs(int nown, int lx, int ly){
    if(vis[lx][ly]) return 0;
    if(nown == m) return 1;
    vis[lx][ly] = true;
    double res = 0;
    REP(i, 4) res += (prob[i] * dfs(nown+1, lx+vx[i], ly+vy[i]));
    vis[lx][ly] = false;
    return res;
}


class CrazyBot {
	public:
	double getProbability(int N, int east, int west, int south, int north) {
        m = N;
        prob[0] = (double)east/100;
        prob[1] = (double)west/100;
        prob[2] = (double)south/100;
        prob[3] = (double)north/100;
        return dfs(0, 15, 15);
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int n                     = 1;
			int east                  = 25;
			int west                  = 25;
			int south                 = 25;
			int north                 = 25;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = CrazyBot().getProbability(n, east, west, south, north);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 2;
			int east                  = 25;
			int west                  = 25;
			int south                 = 25;
			int north                 = 25;
			double expected__         = 0.75;

			clock_t start__           = clock();
			double received__         = CrazyBot().getProbability(n, east, west, south, north);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 7;
			int east                  = 50;
			int west                  = 0;
			int south                 = 0;
			int north                 = 50;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = CrazyBot().getProbability(n, east, west, south, north);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 14;
			int east                  = 50;
			int west                  = 50;
			int south                 = 0;
			int north                 = 0;
			double expected__         = 1.220703125E-4;

			clock_t start__           = clock();
			double received__         = CrazyBot().getProbability(n, east, west, south, north);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 14;
			int east                  = 25;
			int west                  = 25;
			int south                 = 25;
			int north                 = 25;
			double expected__         = 0.008845493197441101;

			clock_t start__           = clock();
			double received__         = CrazyBot().getProbability(n, east, west, south, north);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int n                     = ;
			int east                  = ;
			int west                  = ;
			int south                 = ;
			int north                 = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CrazyBot().getProbability(n, east, west, south, north);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int east                  = ;
			int west                  = ;
			int south                 = ;
			int north                 = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CrazyBot().getProbability(n, east, west, south, north);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int east                  = ;
			int west                  = ;
			int south                 = ;
			int north                 = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CrazyBot().getProbability(n, east, west, south, north);
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
// An out-of-control robot is placed on a plane, and it takes n random steps.  At each step, the robot chooses one of four directions randomly and moves one unit in that direction. The probabilities of the robot choosing north, south, east or west are north, south, east and west percent, respectively.

The robot's path is considered simple if it never visits the same point more than once.  (The robot's starting point is always the first visited point.)  Return a double containing the probability that the robot's path is simple.  For example, "EENE" and "ENW" are simple, but "ENWS" and "WWWWSNE" are not ('E', 'W', 'N' and 'S' represent east, west, north and south, respectively).

DEFINITION
Class:CrazyBot
Method:getProbability
Parameters:int, int, int, int, int
Returns:double
Method signature:double getProbability(int n, int east, int west, int south, int north)


NOTES
-Your return must have relative or absolute error less than 1E-9.


CONSTRAINTS
-n will be between 1 and 14, inclusive.
-east will be between 0 and 100, inclusive.
-west will be between 0 and 100, inclusive.
-south will be between 0 and 100, inclusive.
-north will be between 0 and 100, inclusive.
-The sum of east, west, south and north will be 100.


EXAMPLES

0)
1
25
25
25
25

Returns: 1.0

The robot only takes one step, so it never visits a point more than once.

1)
2
25
25
25
25

Returns: 0.75

The robot will visit its starting point twice only if the two moves are in opposite directions.

2)
7
50
0
0
50

Returns: 1.0

Here, the only possible directions are north and east, so the robot will never visit the same point twice.

3)
14
50
50
0
0

Returns: 1.220703125E-4

Here, the only possible directions are east and west. The only two available paths are "EEEEEEEEEEEEEE" and "WWWWWWWWWWWWWW". The probability is equal to 2 / (2^14).

4)
14
25
25
25
25

Returns: 0.008845493197441101

The probability is quite small for n=14.

*/

// END CUT HERE
