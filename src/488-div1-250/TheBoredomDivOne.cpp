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

#define EPS 1e-9

class TheBoredomDivOne {
	public:
	double find(int n, int m) {
		double now[100] = {0.0}, next[100] = {0.0};
        next[n] = 1.0;
        int cnt = 0;
        double res_now = 0.0, res_next = 0.0;
        
        while(res_next == 0.0 || res_next-res_now > EPS ||  (res_next-res_now)/res_next > EPS){
            cnt++;
            REP(i, 100){
                now[i] = next[i];
                if(i>=n+m) now[i] = 0.0;
                next[i] = 0.0;
            }
            res_now = res_next;
            
            REP(i, 100) {
                if(i+2 <= n+m)
                    next[i+2] += now[i] * ((n+m-i)*(n+m-i-1)) / ((n+m)*(n+m-1));
                if(i+1 <= n+m && i>=1)
                    next[i+1] += now[i] * ((n+m-i)*i*2) / ((n+m)*(n+m-1));
                if(i <= n+m && i>=2)
                    next[i] += now[i] * (i*(i-1)) / ((n+m)*(n+m-1));
            }
            res_next += next[n+m] * cnt;
        }
        
        return res_next;
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
			int m                     = 1;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = TheBoredomDivOne().find(n, m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 2;
			int m                     = 1;
			double expected__         = 1.5;

			clock_t start__           = clock();
			double received__         = TheBoredomDivOne().find(n, m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 1;
			int m                     = 2;
			double expected__         = 2.0;

			clock_t start__           = clock();
			double received__         = TheBoredomDivOne().find(n, m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 4;
			int m                     = 7;
			double expected__         = 13.831068977298521;

			clock_t start__           = clock();
			double received__         = TheBoredomDivOne().find(n, m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			int m                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheBoredomDivOne().find(n, m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			int m                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheBoredomDivOne().find(n, m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int m                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheBoredomDivOne().find(n, m);
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
// John and Brus are bored.
They have n+m common friends.
n of them are bored and m are not.
Every hour John and Brus randomly choose two different friends A and B. If there are several possible pairs (A, B), each one has the same probability of being chosen.
After that, John has a talk with friend A and Brus has a talk with friend B. For each of two chosen friends, if the friend is not
bored, he becomes bored after the talk.

You have to find the expected time for all the friends to become bored.


DEFINITION
Class:TheBoredomDivOne
Method:find
Parameters:int, int
Returns:double
Method signature:double find(int n, int m)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-n will be between 1 and 47, inclusive.
-m will be between 1 and 47, inclusive.


EXAMPLES

0)
1
1

Returns: 1.0

There are two friends overall. Since John and Brus always choose different friends for a talk, both friends will be bored after one hour.

1)
2
1

Returns: 1.5

Here John and Brus can choose two friends that are already bored, so the expectation is more than 1 hour.

2)
1
2

Returns: 2.0



3)
4
7

Returns: 13.831068977298521

*/

// END CUT HERE
