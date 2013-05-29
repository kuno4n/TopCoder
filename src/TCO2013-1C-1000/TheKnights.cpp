
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

double oneKnight(int n, int a, int b){
	const double dx[9] = {a, a, -a, -a, 0, b, b, -b, -b};
	const double dy[9] = {b, -b, b, -b, 0, a, -a, a, -a};
	
	double cnt = 0.0;
	for(int i = (a==b ? 4 : 8); i >= 0; i--){
		double minx = max(0.0, dx[i]);
		double maxx = min(n-1.0, n-1.0+dx[i]);
		double miny = max(0.0, dy[i]);
		double maxy = min(n-1.0, n-1.0+dy[i]);
		cnt += max(0.0, (maxx-minx+1.0)) * max(0.0, (maxy-miny+1.0));
	}
	return cnt / ((double)n*n);
}


double intersection(int n, int a, int b){
	const double dx[9] = {a, a, -a, -a, 0, b, b, -b, -b};
	const double dy[9] = {b, -b, b, -b, 0, a, -a, a, -a};
	
	double cnt = 0.0;
	for(int i = (a==b ? 4 : 8); i >= 0; i--){
		for(int j = (a==b ? 4 : 8); j >= 0; j--){
			if(i == j) continue;
			double minx_i = max(0.0, dx[i]);
			double maxx_i = min(n-1.0, n-1.0+dx[i]);
			double miny_i = max(0.0, dy[i]);
			double maxy_i = min(n-1.0, n-1.0+dy[i]);
			double minx_j = max(0.0, dx[j]);
			double maxx_j = min(n-1.0, n-1.0+dx[j]);
			double miny_j = max(0.0, dy[j]);
			double maxy_j = min(n-1.0, n-1.0+dy[j]);
			double minx = max(minx_i, minx_j);
			double maxx = min(maxx_i, maxx_j);
			double miny = max(miny_i, miny_j);
			double maxy = min(maxy_i, maxy_j);
			
			cnt += max(0.0, (maxx-minx+1.0)) * max(0.0, (maxy-miny+1.0));
			
		}
	}
	return cnt / ((double)n*n*((double)n*n-1));
}


class TheKnights {
public:
   double find( int n, int a, int b ) {
	return oneKnight(n, a, b)*2.0 - intersection(n, a, b);
//	return oneKnight(n, a, b);
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
			int n                     = 2;
			int a                     = 1;
			int b                     = 1;
			double expected__         = 3.3333333333333335;

			clock_t start__           = clock();
			double received__         = TheKnights().find(n, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 47;
			int a                     = 7;
			int b                     = 74;
			double expected__         = 2.0;

			clock_t start__           = clock();
			double received__         = TheKnights().find(n, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 3;
			int a                     = 2;
			int b                     = 1;
			double expected__         = 4.888888888888889;

			clock_t start__           = clock();
			double received__         = TheKnights().find(n, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 9999;
			int a                     = 999;
			int b                     = 99;
			double expected__         = 16.25885103191273;

			clock_t start__           = clock();
			double received__         = TheKnights().find(n, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 10;
			int a                     = 1;
			int b                     = 6;
			double expected__         = 7.636363636363637;

			clock_t start__           = clock();
			double received__         = TheKnights().find(n, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int n                     = ;
			int a                     = ;
			int b                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheKnights().find(n, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int a                     = ;
			int b                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheKnights().find(n, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int a                     = ;
			int b                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheKnights().find(n, a, b);
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
// John and Brus have two (a, b) chess knights.
When an (a, b) knight moves, it can move a squares horizontally and b squares vertically, or b squares horizontally and a squares vertically.


John and Brus place their knights on two different cells of an n by n chessboard.
The pair of cells is chosen uniformly at random.
A chessboard cell is attacked if it is either occupied by one of the knights, or if it can be reached by one of the knights in a single move.
Return the expected number of attacked cells.


DEFINITION
Class:TheKnights
Method:find
Parameters:int, int, int
Returns:double
Method signature:double find(int n, int a, int b)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.
-Informally, the expected number of attacked cells can be seen as the average number over very many rounds of the process. See http://en.wikipedia.org/wiki/Expected_value for a formal definition.


CONSTRAINTS
-n will be between 2 and 1,000,000,000, inclusive.
-a will be between 1 and 1,000,000,000, inclusive.
-b will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
2
1
1

Returns: 3.3333333333333335

If we fix one of the knights, there are three ways to place the other one.
In two of those three cases all 4 cells on the board will be attacked.
In the last case only the 2 cells occupied by the knights will be attacked.
Thus the expected value is 4*(2/3) + 2*(1/3) =  10/3.


1)
47
7
74

Returns: 2.0

For any placement of the knights only two cells will be attacked.

2)
3
2
1

Returns: 4.888888888888889



3)
9999
999
99

Returns: 16.25885103191273



4)
10
1
6

Returns: 7.636363636363637



*/

// END CUT HERE
