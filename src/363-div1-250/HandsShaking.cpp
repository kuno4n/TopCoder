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

LL memo[55];

LL rec(int num){
    if(memo[num] >= 0) return memo[num];
    LL res = 0;
    for(int i=1; i<num; i+=2){
        LL tmp1 = rec(i-1);
        memo[i-1] = tmp1;
        LL tmp2 = rec(num-i-1);
        memo[num-i-1] = tmp2;
        res += (tmp1*tmp2>0 ? tmp1*tmp2 : tmp1+tmp2);
    }
    return res;
}


class HandsShaking {
	public:
	long long countPerfect(int n) {
        MSET(memo, -1);
		memo[0] = 0;
		memo[2] = 1;
        return rec(n);
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
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
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = HandsShaking().countPerfect(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 4;
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = HandsShaking().countPerfect(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 8;
			long long expected__      = 14;

			clock_t start__           = clock();
			long long received__      = HandsShaking().countPerfect(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int n                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = HandsShaking().countPerfect(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int n                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = HandsShaking().countPerfect(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = HandsShaking().countPerfect(n);
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
// Consider a meeting of n businessmen sitting around a circular table. To start the meeting, they must shake hands. Each businessman shakes the hand of exactly one other businessman. All handshakes happen simultaneously. We say that the shake is perfect if no arms cross each other. Given an int n, return the number of perfect shakes that exist for n businessmen. See examples for further clarification.

DEFINITION
Class:HandsShaking
Method:countPerfect
Parameters:int
Returns:long long
Method signature:long long countPerfect(int n)


NOTES
-Businessmen are distinguishable. Rotating a perfect shake can yield a different perfect shake (see example 1).


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-n will be even.


EXAMPLES

0)
2

Returns: 1

Two businessmen have only one possibility - just to shake each other's hand.

1)
4

Returns: 2

Two out of three possible shakes are perfect.
? ? 

2)
8

Returns: 14



*/

// END CUT HERE
