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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

const int INF = (1<<29);

class MergersDivTwo {
	public:
	double findMaximum(vector <int> r, int k) {
        int n = SZ(r);
        double dp[n]; REP(i, n) dp[i] = -INF;
        sort(ALL(r));
        dp[0] = r[0];
        REP(i, n-k+1) if(dp[i] != -INF) for(int j = i+k-1; j < n; j++){
            double tmp = dp[i];
            for(int k = i+1; k <= j; k++) tmp += r[k];
            tmp /= j-i+1;
            chmax(dp[j], tmp);
        }
        return dp[n-1];
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
			int revenues[]            = {5, -7, 3};
			int k                     = 2;
			double expected__         = 1.5;

			clock_t start__           = clock();
			double received__         = MergersDivTwo().findMaximum(vector <int>(revenues, revenues + (sizeof revenues / sizeof revenues[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int revenues[]            = {5, -7, 3};
			int k                     = 3;
			double expected__         = 0.3333333333333333;

			clock_t start__           = clock();
			double received__         = MergersDivTwo().findMaximum(vector <int>(revenues, revenues + (sizeof revenues / sizeof revenues[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int revenues[]            = {1, 2, 2, 3, -10, 7};
			int k                     = 3;
			double expected__         = 2.9166666666666665;

			clock_t start__           = clock();
			double received__         = MergersDivTwo().findMaximum(vector <int>(revenues, revenues + (sizeof revenues / sizeof revenues[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int revenues[]            = {-100, -100, -100, -100, -100, 100};
			int k                     = 4;
			double expected__         = -66.66666666666667;

			clock_t start__           = clock();
			double received__         = MergersDivTwo().findMaximum(vector <int>(revenues, revenues + (sizeof revenues / sizeof revenues[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int revenues[]            = {869, 857, -938, -290, 79, -901, 32, -907, 256, -167, 510, -965, -826, 808, 890, -233, -881, 255, -709, 506, 334, -184, 726, -406, 204, -912, 325, -445, 440, -368};
			int k                     = 7;
			double expected__         = 706.0369290573373;

			clock_t start__           = clock();
			double received__         = MergersDivTwo().findMaximum(vector <int>(revenues, revenues + (sizeof revenues / sizeof revenues[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int revenues[]            = ;
			int k                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MergersDivTwo().findMaximum(vector <int>(revenues, revenues + (sizeof revenues / sizeof revenues[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int revenues[]            = ;
			int k                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MergersDivTwo().findMaximum(vector <int>(revenues, revenues + (sizeof revenues / sizeof revenues[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int revenues[]            = ;
			int k                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MergersDivTwo().findMaximum(vector <int>(revenues, revenues + (sizeof revenues / sizeof revenues[0])), k);
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
// Warning: This problem statement contains superscripts and/or subscripts. It may not display properly outside of the applet.

The candy industry is going through a hard time in Byteland. Some of the biggest companies in the business have decided to perform a series of mergers so as to become one company in the end. Due to the depression, each merger should join at least k companies at once. Surprisingly, empirical studies conducted by the economists of Byteland have shown that the revenue of a company that is created by simultainously merging m (m >= k) companies with revenues equal to r0, r1, ..., rm - 1 is equal to the average of these revenues, that is (r0 + r1 + ... + rm - 1) / m.


You are given a vector <int> revenues. The revenue of the i-th of the companies that want to merge is equal to revenues[i]. Return the maximum possible revenue of the final company that can be created in any series of mergers that joins all the companies.

DEFINITION
Class:MergersDivTwo
Method:findMaximum
Parameters:vector <int>, int
Returns:double
Method signature:double findMaximum(vector <int> revenues, int k)


NOTES
-The returned value must have an absolute or relative error less than 10-9.
-Please note that the revenue of a company may be negative; this means that the company is actually losing money.
-It is always possible to merge all companies into a single one: for example, by merging all of them in a single step.


CONSTRAINTS
-revenues will contain between 2 and 50 elements, inclusive.
-Each element of revenues will be between -1,000 and 1,000, inclusive.
-k will be between 2 and the number of elements in revenues, inclusive.


EXAMPLES

0)
{5, -7, 3}
2

Returns: 1.5

The optimal way is to first merge companies 1 and 2, obtaining a company with total revenue -2, and then merge that company with company 0.

1)
{5, -7, 3}
3

Returns: 0.3333333333333333

The respective revenues are the same as in the previous example, but because k = 3, we have to merge all companies at once.

2)
{1, 2, 2, 3, -10, 7}
3

Returns: 2.9166666666666665

The solution is to first merge companies 0, 1, 2 and 4, and then merge the resulting company with companies 3 and 5.

3)
{-100, -100, -100, -100, -100, 100}
4

Returns: -66.66666666666667

Note that we can't merge less than six companies in the first step, because otherwise we would be left with only two or three companies and we would be unable to finish the merging process.

4)
{869, 857, -938, -290, 79, -901, 32, -907, 256, -167, 510, -965, -826, 808, 890,
 -233, -881, 255, -709, 506, 334, -184, 726, -406, 204, -912, 325, -445, 440, -368}
7

Returns: 706.0369290573373



*/

// END CUT HERE
