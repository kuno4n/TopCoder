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
//#include "cout.h"

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

int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};

//double cals(LL x1, LL y1, LL x2, LL y2){
//    LL a = x1*x1 + y1*y1;
//    LL b = x2*x2 + y2*y2;
//    LL c = (x1*x2 + y1*y2) * (x1*x2 + y1*y2);
//    return sqrt(a*b-c)/2;
//}

set <LL> s;
vector < pair < LL, LL > > AA;
vector < pair < LL, LL > > BB;

class MaxTriangle {
	public:
	double calculateArea(int A, int B) {
        s.clear();
        AA.clear();
        BB.clear();
        for(LL i = 0; i * i < 2000000000LL; i++) s.insert(i*i);
        FIT(it, s){
            LL c = (*it);
            if(s.count(A-c)) AA.push_back(make_pair((LL)(sqrt(c)), (LL)(sqrt(A-c))));
            if(s.count(B-c)) BB.push_back(make_pair((LL)(sqrt(c)), (LL)(sqrt(B-c))));
        }
        if(SZ(AA)==0  || SZ(BB) == 0) return -1;
        double res = 0.0;
        REP(i, SZ(AA)){
            REP(j, SZ(BB)){
                    REP(jj, 4){
                        LL x1 = AA[i].first;
                        LL y1 = AA[i].second;
                        LL x2 = BB[j].first * dx[jj];
                        LL y2 = BB[j].second * dy[jj];
                        res = max(res, abs((double)x1*y2 - x2*y1)/2);
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
			int A                     = 1;
			int B                     = 1;
			double expected__         = 0.5;

			clock_t start__           = clock();
			double received__         = MaxTriangle().calculateArea(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A                     = 3;
			int B                     = 7;
			double expected__         = -1.0;

			clock_t start__           = clock();
			double received__         = MaxTriangle().calculateArea(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A                     = 41;
			int B                     = 85;
			double expected__         = 29.5;

			clock_t start__           = clock();
			double received__         = MaxTriangle().calculateArea(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 3: {
			int A                     = 2000000000;
			int B                     = 1;
			double expected__         = 22240.0;

			clock_t start__           = clock();
			double received__         = MaxTriangle().calculateArea(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 4: {
			int A                     = 1;
			int B                     = 2000000000;
			double expected__         = 22240.0;

			clock_t start__           = clock();
			double received__         = MaxTriangle().calculateArea(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 5: {
			int A                     = 925;
			int B                     = 725;
			double expected__         = 408.5;

			clock_t start__           = clock();
			double received__         = MaxTriangle().calculateArea(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
      }
            case 6: {
                int A                     = 725;
                int B                     = 925;
                double expected__         = 408.5;
                
                clock_t start__           = clock();
                double received__         = MaxTriangle().calculateArea(A, B);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
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
// A triangle with positive area has been positioned on the plane in such a way that all of its vertices are located at integer coordinates. The lengths of two sides of this triangle are equal to sqrt(A) and sqrt(B), where sqrt(X) denotes the square root of X. Return the maximum area this triangle can have. If there is no such triangle, return -1 instead.

DEFINITION
Class:MaxTriangle
Method:calculateArea
Parameters:int, int
Returns:double
Method signature:double calculateArea(int A, int B)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-A and B will each be between 1 and 2000000000, inclusive.


EXAMPLES

0)
1
1

Returns: 0.5

1)
3
7

Returns: -1.0

2)
41
85

Returns: 29.5

One possible triangle has vertices at (-1, 1), (6, -5) and (10, 0).

*/

// END CUT HERE
