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

VI erase_step(VI v, int step){
    VI res;
    REP(i, SZ(v)) if(i%step) res.push_back(v[i]);
    return res;
}

class LockersDivOne {
	public:
	int lastOpened(int N) {
		VI v;
        REP(i, N) v.push_back(i+1);
        for(int i=2; SZ(v) != 1; i++) v = erase_step(v, i);
        return v[0];
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
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
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
			int N                     = 9;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = LockersDivOne().lastOpened(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 42;
			int expected__            = 42;

			clock_t start__           = clock();
			int received__            = LockersDivOne().lastOpened(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 314;
			int expected__            = 282;

			clock_t start__           = clock();
			int received__            = LockersDivOne().lastOpened(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LockersDivOne().lastOpened(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LockersDivOne().lastOpened(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LockersDivOne().lastOpened(N);
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
// A hallway is filled with lockers numbered 1 through N, initially all closed.  Out of boredom, Dave and Earl decide to open all the lockers.  They make multiple passes through the hallway, each beginning at locker 1.  On the first pass, they open the first unopened locker, and every second unopened locker thereafter.  On the second pass, they open the first unopened locker, and every third unopened locker thereafter.  In general, on the nth pass, they open the first unopened locker, and every (n+1)th unopened locker thereafter.

For example, with 9 lockers, on the first pass they open 1, 3, 5, 7, and 9, leaving 2, 4, 6, and 8.  On the second pass they open 2 and 8, leaving 4 and 6.  On the third pass they open locker 4, and on the final pass locker 6.

You will be given N, the number of lockers.  Return the number of the locker opened last.

DEFINITION
Class:LockersDivOne
Method:lastOpened
Parameters:int
Returns:int
Method signature:int lastOpened(int N)


CONSTRAINTS
-N will be between 1 and 2000000, inclusive.


EXAMPLES

0)
9

Returns: 6

The example from the problem statement.

1)
42

Returns: 42



2)
314

Returns: 282



*/

// END CUT HERE
