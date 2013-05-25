
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

class MarblePositioning {
public:
   double totalWidth( vector <int> radius ) {
	double res = 100000000000.0;
	sort(ALL(radius));
	do{
		double tab[8];
		tab[0] = 0.0;
		for(int i = 1; i < SZ(radius); i++){
			double tmp = 0.0;
			REP(j, i){
				double r1 = (double)radius[j];
				double r2 = (double)radius[i];
//				if(r1 < r2) swap(r1, r2);
				double tmp2 = sqrt((r1+r2)*(r1+r2) - (r1-r2)*(r1-r2));
				tmp = max(tmp, tab[j]+tmp2);
			}
			tab[i] = tmp;
		}
		res = min(res, tab[SZ(radius)-1]);
	}while(next_permutation(ALL(radius)));
	
	return res;

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
			int radius[]              = {1, 2};
			double expected__         = 2.8284271247461903;

			clock_t start__           = clock();
			double received__         = MarblePositioning().totalWidth(vector <int>(radius, radius + (sizeof radius / sizeof radius[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int radius[]              = {7,7,7};
			double expected__         = 28.0;

			clock_t start__           = clock();
			double received__         = MarblePositioning().totalWidth(vector <int>(radius, radius + (sizeof radius / sizeof radius[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int radius[]              = {10, 20, 30};
			double expected__         = 62.92528739883945;

			clock_t start__           = clock();
			double received__         = MarblePositioning().totalWidth(vector <int>(radius, radius + (sizeof radius / sizeof radius[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int radius[]              = {100, 100,11,11,25};
			double expected__         = 200.0;

			clock_t start__           = clock();
			double received__         = MarblePositioning().totalWidth(vector <int>(radius, radius + (sizeof radius / sizeof radius[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int radius[]              = {1,999950884,1};
			double expected__         = 63246.0;

			clock_t start__           = clock();
			double received__         = MarblePositioning().totalWidth(vector <int>(radius, radius + (sizeof radius / sizeof radius[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int radius[]              = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MarblePositioning().totalWidth(vector <int>(radius, radius + (sizeof radius / sizeof radius[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int radius[]              = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MarblePositioning().totalWidth(vector <int>(radius, radius + (sizeof radius / sizeof radius[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int radius[]              = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MarblePositioning().totalWidth(vector <int>(radius, radius + (sizeof radius / sizeof radius[0])));
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
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.


Everybody loves geometry, so here is a geometry problem.
You have a few marbles of possibly different sizes.
You are given a vector <int> radius that describes the marbles: each element of radius is the radius of one of your marbles.

You want to place all marbles onto a straight line that is drawn on the table.
Clearly, this makes the problem two-dimensional: we can just view the marbles as circles that will all be touching the line from above.
Of course, the marbles cannot overlap, so in our problem no two circles are allowed to overlap.
Note that you may place the marbles onto the line in any order, you do not have to preserve the order in which they are given in radius.

Additionally, you want to pack the bottoms of the marbles as close together as possible.
More precisely:
For each marble consider the point where it touches the line.
Compute and return the smallest possible distance between the farthest two of those points.
(That is, if you imagine the line as going from the left to the right, your task is to minimize the distance between the leftmost and the rightmost of the points where the circles touch the line.)

DEFINITION
Class:MarblePositioning
Method:totalWidth
Parameters:vector <int>
Returns:double
Method signature:double totalWidth(vector <int> radius)


NOTES
-The returned values must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-radius will contain between 2 and 8 elements, inclusive.
-Each element of radius will be between 1 and 1000000000 (10^9), inclusive.


EXAMPLES

0)
{1, 2}

Returns: 2.8284271247461903

One of the best ways to place the marbles is the following one:




1)
{7,7,7}

Returns: 28.0



2)
{10, 20, 30}

Returns: 62.92528739883945





3)
{100, 100,11,11,25}

Returns: 200.0



4)
{1,999950884,1}

Returns: 63246.0



*/

// END CUT HERE
