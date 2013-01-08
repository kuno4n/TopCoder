
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
#include <queue>

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
#define OUT(A) cout << #A << " = "<< A << endl

class BouncingBalls {
public:
   double expectedBounces( vector <int> x, int T ) {
	   int n= SZ(x);
	   int cnt = 0;
	   REP(mask, (1<<n)){
			   vector<int> xx;
		   REP(i, n){
			   if(mask & (1<<i)){
				   xx.PB(x[i]+T);
			   }
			   else {
				   xx.PB(x[i]-T);
			   }
		   }
		   REP(i, n){
			   FOR(j, i+1, n){
				   if(x[i]>x[j] && xx[i]<=xx[j]) cnt++;
				   else if(x[i]<x[j] && xx[i]>=xx[j]) cnt++;
			   }
		   }
	   }
	   return (double)cnt/(1<<n);
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
			int x[]                   = {5, 8};
			int T                     = 2;
			double expected__         = 0.25;

			clock_t start__           = clock();
			double received__         = BouncingBalls().expectedBounces(vector <int>(x, x + (sizeof x / sizeof x[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {5, 8};
			int T                     = 1;
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = BouncingBalls().expectedBounces(vector <int>(x, x + (sizeof x / sizeof x[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {91, 857, 692, 54, 8679, 83, 792, 86, 9537, 913, 64, 592};
			int T                     = 458;
			double expected__         = 11.5;

			clock_t start__           = clock();
			double received__         = BouncingBalls().expectedBounces(vector <int>(x, x + (sizeof x / sizeof x[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {75432};
			int T                     = 386;
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = BouncingBalls().expectedBounces(vector <int>(x, x + (sizeof x / sizeof x[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
			int T                     = 3;
			double expected__         = 12.75;

			clock_t start__           = clock();
			double received__         = BouncingBalls().expectedBounces(vector <int>(x, x + (sizeof x / sizeof x[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int x[]                   = ;
			int T                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = BouncingBalls().expectedBounces(vector <int>(x, x + (sizeof x / sizeof x[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int x[]                   = ;
			int T                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = BouncingBalls().expectedBounces(vector <int>(x, x + (sizeof x / sizeof x[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int x[]                   = ;
			int T                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = BouncingBalls().expectedBounces(vector <int>(x, x + (sizeof x / sizeof x[0])), T);
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
// John is playing with balls. All of the balls are identical in weight and considered to have a zero radius. All balls are located on the same straight line and can move only along this line. If a ball rolling to the right and a ball rolling to the left at the same speed collide, they do not change speed, but they change direction.


You are given vector <int> x. x[i] is the initial position of the i-th ball. John decides the direction for each ball (right or left) with equal probability. At time 0, he rolls the balls in the chosen directions simultaneously at a speed of one unit per second. Return the expected number of bounces between all balls during T seconds (including those collisions that happen exactly at T seconds).

DEFINITION
Class:BouncingBalls
Method:expectedBounces
Parameters:vector <int>, int
Returns:double
Method signature:double expectedBounces(vector <int> x, int T)


NOTES
-There is no friction. Each ball continues rolling at the same speed forever.
-Your return value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-x will contain between 1 and 12 elements, inclusive.
-Each element of x will be between 0 and 100,000,000, inclusive.
-All elements of x will be distinct.
-T will be between 1 and 100,000,000, inclusive.


EXAMPLES

0)
{5, 8}
2

Returns: 0.25

If he rolls the left ball to the right and right ball to the left, they collide at time 1.5. Otherwise, they don't collide.

1)
{5, 8}
1

Returns: 0.0

x is the same as in example 0, but T is too small.

2)
{91, 857, 692, 54, 8679, 83, 792, 86, 9537, 913, 64, 592}
458

Returns: 11.5



3)
{75432}
386

Returns: 0.0



4)
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
3

Returns: 12.75



*/

// END CUT HERE
