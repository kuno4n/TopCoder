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

class TheSimilarNumbers {
	public:
	int find(int lower, int upper) {
		int res = 0;
        for(LL i = lower; i <= upper; i = i*10+1) res++;
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
			int lower                 = 1;
			int upper                 = 10;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheSimilarNumbers().find(lower, upper);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int lower                 = 5;
			int upper                 = 511;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TheSimilarNumbers().find(lower, upper);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int lower                 = 5;
			int upper                 = 4747;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TheSimilarNumbers().find(lower, upper);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int lower                 = 1;
			int upper                 = 1000000;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = TheSimilarNumbers().find(lower, upper);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int lower                 = 10;
			int upper                 = 10110;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TheSimilarNumbers().find(lower, upper);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int lower                 = ;
			int upper                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheSimilarNumbers().find(lower, upper);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int lower                 = ;
			int upper                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheSimilarNumbers().find(lower, upper);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int lower                 = ;
			int upper                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheSimilarNumbers().find(lower, upper);
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
// Two positive integers A and B are called similar if A <= 10*B and B <= 10*A. For example, 1 and 10 are similar, but 1 and 11 are not.

You are given ints lower and upper. You must select as many integers as possible so that:

each selected integer is between lower and upper, inclusive;
no two selected integers are similar.

Return the maximum number of selected integers.

DEFINITION
Class:TheSimilarNumbers
Method:find
Parameters:int, int
Returns:int
Method signature:int find(int lower, int upper)


CONSTRAINTS
-upper will be between 1 and 1,000,000, inclusive.
-lower will be between 1 and upper, inclusive.


EXAMPLES

0)
1
10

Returns: 1

Any two integers between 1 and 10 are similar. Therefore you may select only 1 number.

1)
5
511

Returns: 3

You can select 51, 5, and 511.

2)
5
4747

Returns: 3



3)
1
1000000

Returns: 6



4)
10
10110

Returns: 3



*/

// END CUT HERE
