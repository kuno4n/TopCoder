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

class Pillars {
    
	public:
	double getExpectedLength(int w, int x, int y) {
        double l = 0;
        if(x>y) swap(x, y);
        l += w * x;
        
        FOR(i, 1, 100010){
            int tmpx = max(0, i<y-x ? x : y-i);
            int tmpy = max(0, x-i);
            l += sqrt(w*w + (LL)i*i) * (tmpx+tmpy);
        }
                
        return l/((double)x*y);
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
			int w                     = 1;
			int x                     = 1;
			int y                     = 1;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = Pillars().getExpectedLength(w, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int w                     = 1;
			int x                     = 5;
			int y                     = 1;
			double expected__         = 2.387132965131785;

			clock_t start__           = clock();
			double received__         = Pillars().getExpectedLength(w, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int w                     = 2;
			int x                     = 3;
			int y                     = 15;
			double expected__         = 6.737191281760445;

			clock_t start__           = clock();
			double received__         = Pillars().getExpectedLength(w, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int w                     = 10;
			int x                     = 15;
			int y                     = 23;
			double expected__         = 12.988608956320535;

			clock_t start__           = clock();
			double received__         = Pillars().getExpectedLength(w, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int w                     = ;
			int x                     = ;
			int y                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = Pillars().getExpectedLength(w, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int w                     = ;
			int x                     = ;
			int y                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = Pillars().getExpectedLength(w, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int w                     = ;
			int x                     = ;
			int y                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = Pillars().getExpectedLength(w, x, y);
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
// On a horizontal line, there are two vertical pillars.
The distance between their bottoms is w.
The height of the first pillar is an integer, chosen uniformly at random in the range 1 through x, inclusive.
The height of the second pillar is an integer, chosen uniformly at random in the range 1 through y, inclusive.
The tops of both pillars will be connected by a straight piece of rope.

You are given the ints w, x, and y.
Compute and return the expected length of the rope.

DEFINITION
Class:Pillars
Method:getExpectedLength
Parameters:int, int, int
Returns:double
Method signature:double getExpectedLength(int w, int x, int y)


NOTES
-Your return value must have a relative or an absolute error of less than 1e-9.
-In this task, the expected rope length can be computed as the average rope length over all possible cases.


CONSTRAINTS
-w will be between 1 and 1000, inclusive.
-x will be between 1 and 100,000, inclusive.
-y will be between 1 and 100,000, inclusive.


EXAMPLES

0)
1
1
1

Returns: 1.0

The rope always has a length of 1.

1)
1
5
1

Returns: 2.387132965131785

There are 5 possible (equiprobable) cases in which the length of the rope is 1, sqrt(2), sqrt(5), sqrt(10) and sqrt(17). The correct answer is the arithmetic average of these 5 numbers.

2)
2
3
15

Returns: 6.737191281760445



3)
10
15
23

Returns: 12.988608956320535



*/

// END CUT HERE
