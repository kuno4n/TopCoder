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

class FoxPlayingGame {
	public:
	double theMax(int nA, int nB, int paramA, int paramB) {
		double sum = paramA*nA/1000.0;
        double res = sum;
        REP(i, nB){
            sum *= (paramB/1000.0);
            res = max(res, sum);
        }
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
			int nA                    = 5;
			int nB                    = 4;
			int paramA                = 3000;
			int paramB                = 2000;
			double expected__         = 240.0;

			clock_t start__           = clock();
			double received__         = FoxPlayingGame().theMax(nA, nB, paramA, paramB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int nA                    = 3;
			int nB                    = 3;
			int paramA                = 2000;
			int paramB                = 100;
			double expected__         = 6.0;

			clock_t start__           = clock();
			double received__         = FoxPlayingGame().theMax(nA, nB, paramA, paramB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int nA                    = 4;
			int nB                    = 3;
			int paramA                = -2000;
			int paramB                = 2000;
			double expected__         = -8.0;

			clock_t start__           = clock();
			double received__         = FoxPlayingGame().theMax(nA, nB, paramA, paramB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int nA                    = 5;
			int nB                    = 5;
			int paramA                = 2000;
			int paramB                = -2000;
			double expected__         = 160.0;

			clock_t start__           = clock();
			double received__         = FoxPlayingGame().theMax(nA, nB, paramA, paramB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int nA                    = 50;
			int nB                    = 50;
			int paramA                = 10000;
			int paramB                = 2000;
			double expected__         = 5.62949953421312E17;

			clock_t start__           = clock();
			double received__         = FoxPlayingGame().theMax(nA, nB, paramA, paramB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int nA                    = 41;
			int nB                    = 34;
			int paramA                = 9876;
			int paramB                = -1234;
			double expected__         = 515323.9982341775;

			clock_t start__           = clock();
			double received__         = FoxPlayingGame().theMax(nA, nB, paramA, paramB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int nA                    = ;
			int nB                    = ;
			int paramA                = ;
			int paramB                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FoxPlayingGame().theMax(nA, nB, paramA, paramB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int nA                    = ;
			int nB                    = ;
			int paramA                = ;
			int paramB                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FoxPlayingGame().theMax(nA, nB, paramA, paramB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int nA                    = ;
			int nB                    = ;
			int paramA                = ;
			int paramB                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FoxPlayingGame().theMax(nA, nB, paramA, paramB);
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
// Fox Ciel was very bored, so she invented a single player game. The rules of the game are:

You start with 0 points.
You make exactly nA+nB moves.
You have two types of moves available. These are called move A and move B.
Exactly nA times you will make move A. Exactly nB times you will make move B. The moves can be in any order.
The moves affect your score in the following ways:

Each time you make move A, you add scoreA to your score.
Each time you make move B, you multiply your score by scoreB.


You are given int nA, int nB, int paramA and int paramB.  Calculate scoreA and scoreB as follows ("/" denotes exact division, without any rounding):
scoreA = paramA/1000.0
scoreB = paramB/1000.0
Return the maximum possible score after nA+nB moves.

DEFINITION
Class:FoxPlayingGame
Method:theMax
Parameters:int, int, int, int
Returns:double
Method signature:double theMax(int nA, int nB, int paramA, int paramB)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-nA will be between 0 and 50, inclusive.
-nB will be between 0 and 50, inclusive.
-paramA will be between -10000 and 10000, inclusive.
-paramB will be between -2000 and 2000, inclusive.


EXAMPLES

0)
5
4
3000
2000

Returns: 240.0

scoreA = 3000/1000 = 3
scoreB = 2000/1000 = 2
The optimal order of operations is:
(3 + 3 + 3 + 3 + 3) * 2 * 2 * 2 * 2 = 240

1)
3
3
2000
100

Returns: 6.0

scoreA = 2000/1000 = 2
scoreB = 100/1000 = 0.1
Multiplying the score by scoreB decreases its absolute value, so it's better to do all multiplications before additions. Thus, the optimal order of operations is:
0 * 0.1 * 0.1 * 0.1 + 2 + 2 + 2 = 6

2)
4
3
-2000
2000

Returns: -8.0

Multiplying the score by scoreB increases its absolute value, but given that scoreA is negative, the overall score will be negative as well, so it's better to do multiplications before additions again to keep the absolute value small.

3)
5
5
2000
-2000

Returns: 160.0

Multiplication increases the absolute value of the score, but if you do all 5 multiplications after additions, you'll end up with negative score. Thus, the optimal order of operations is:
(0 * (-2) + 2 + 2 + 2 + 2 + 2) * (-2) * (-2) * (-2) * (-2) = 160

4)
50
50
10000
2000

Returns: 5.62949953421312E17



5)
41
34
9876
-1234

Returns: 515323.9982341775



*/

// END CUT HERE
