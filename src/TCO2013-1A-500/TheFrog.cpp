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
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
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

#define EPS 1e-11

int d, n;
VI l, r;

bool C(double x){
    REP(i, n){
        int cnt = (int)(l[i]/(x-EPS)) + 1;
        if(x * cnt < r[i] - EPS) return false;
    }
    return true;
}

class TheFrog {
	public:
	double getMinimum(int D, vector <int> L, vector <int> R) {
        sort(ALL(L)); sort(ALL(R));
		d = D; l = L; r = R;
        n = SZ(L);
        double res = 40000.0;
        REP(i, n){
            for(int j = R[i]; j >= 1; j--){
                double tmp = (double)R[i] / j;
                if(tmp > res) break;
                if(C(tmp)){
                    res = min(res, tmp);
                    break;
                }
            }
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
			int D                     = 16;
			int L[]                   = {2};
			int R[]                   = {7};
			double expected__         = 7.0;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int D                     = 25;
			int L[]                   = {11, 3};
			int R[]                   = {21, 7};
			double expected__         = 10.5;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int D                     = 100;
			int L[]                   = {0};
			int R[]                   = {100};
			double expected__         = 100.0;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int D                     = 100;
			int L[]                   = {0, 50};
			int R[]                   = {50, 100};
			double expected__         = 50.0;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int D                     = 30000;
			int L[]                   = {17, 25281, 5775, 2825, 14040};
			int R[]                   = {55, 26000, 5791, 3150, 14092};
			double expected__         = 787.8787878787879;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
            case 5: {
                int D                     = 50;
                int L[]                   = {0, 11,21,31,41};
                int R[]                   = {10, 20,30,41,50};
                double expected__         = 10.25;
                
                clock_t start__           = clock();
                double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 6: {
                int D                     = 50;
                int L[]                   = {0, 11,21,31,40};
                int R[]                   = {10, 20,30,40,50};
                double expected__         = 10.0;
                
                clock_t start__           = clock();
                double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 7: {
                int D                     = 50;
                int L[]                   = {0, 11,21,31,42};
                int R[]                   = {10, 20,30,41,50};
                double expected__         = 10.25;
                
                clock_t start__           = clock();
                double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }

		// custom cases

/*      case 5: {
			int D                     = ;
			int L[]                   = ;
			int R[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int D                     = ;
			int L[]                   = ;
			int R[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int D                     = ;
			int L[]                   = ;
			int R[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
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
// Frog Jim is fond of jumping.
Moreover, all his jumps have the same length X.
Currently, he is standing at the point 0 on the real axis.
He needs to jump along the axis until he gets to point D or beyond it.

There are several pits between points 0 and D. 
For each valid i, there is a pit strictly between L[i] and R[i].
This means that Jim cannot step onto any point that is strictly between points L[i] and R[i].
(He is allowed to step onto the points L[i] and R[i]: as all pits are disjoint, the endpoints of each pit are always safe.)

Find the minimum length of jump X such that if Jim performs only jumps of length X, he can avoid every pit and get to point D or any point beyond it. Note that this length can be non-integer.

DEFINITION
Class:TheFrog
Method:getMinimum
Parameters:int, vector <int>, vector <int>
Returns:double
Method signature:double getMinimum(int D, vector <int> L, vector <int> R)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-D will be between 1 and 30,000, inclusive.
-L will contain between 1 and 50 elements, inclusive.
-Each element of L will be between 0 and D-1, inclusive.
-R will contain the same number of elements as L.
-The i-th element of R will be between L[i]+1 and D, inclusive.
-The intervals given by (L[i], R[i]) will not intersect.


EXAMPLES

0)
16
{2}
{7}

Returns: 7.0

Moving by jumps of length 7, Jim goes from point 0 to point 7, then to point 14 and then to point 21, which is beyond 16. If Jim chose a shorter jump, he would end up in the pit.

1)
25
{11, 3}
{21, 7}

Returns: 10.5

There are two pits. One of them is between points 11 and 21 and the other between points 3 and 7. By fixing jump length at 10.5, Jim successfully avoids them.

2)
100
{0}
{100}

Returns: 100.0

Jim has no other choice but to jump right to point 100.

3)
100
{0, 50}
{50, 100}

Returns: 50.0

In this case, point 50 is a suitable place to land, so Jim can choose X = 50.

4)
30000
{17, 25281, 5775, 2825, 14040}
{55, 26000, 5791, 3150, 14092}

Returns: 787.8787878787879



*/

// END CUT HERE
