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

class BoardSplitting {
	public:
	int minimumCuts(int desiredLength, int desiredCount, int actualLength) {
		int nowlen = 0;
        int cut = 0;
        int made = 0;
        
        while(1){
            nowlen += actualLength;
            while(nowlen >= desiredLength){
                made++;
                nowlen -= desiredLength;
                if(nowlen != 0) cut++;
                if(made == desiredCount) goto LABEL;
            }
        }
    LABEL:
        return cut;
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
			int desiredLength         = 5;
			int desiredCount          = 4;
			int actualLength          = 4;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = BoardSplitting().minimumCuts(desiredLength, desiredCount, actualLength);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int desiredLength         = 6;
			int desiredCount          = 100;
			int actualLength          = 3;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = BoardSplitting().minimumCuts(desiredLength, desiredCount, actualLength);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int desiredLength         = 500;
			int desiredCount          = 5;
			int actualLength          = 1000;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = BoardSplitting().minimumCuts(desiredLength, desiredCount, actualLength);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int desiredLength         = 314;
			int desiredCount          = 159;
			int actualLength          = 26;
			int expected__            = 147;

			clock_t start__           = clock();
			int received__            = BoardSplitting().minimumCuts(desiredLength, desiredCount, actualLength);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int desiredLength         = ;
			int desiredCount          = ;
			int actualLength          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BoardSplitting().minimumCuts(desiredLength, desiredCount, actualLength);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int desiredLength         = ;
			int desiredCount          = ;
			int actualLength          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BoardSplitting().minimumCuts(desiredLength, desiredCount, actualLength);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int desiredLength         = ;
			int desiredCount          = ;
			int actualLength          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BoardSplitting().minimumCuts(desiredLength, desiredCount, actualLength);
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
// A construction company recently ordered some boards of length desiredLength from a lumber company.  By mistake, the lumber company instead delivered boards of length actualLength.  The construction company doesn't have time to reissue the order, so instead they will cut and glue together the boards they have in order to form boards of the proper length.

The construction company needs desiredCount boards of length desiredLength.  The have an effectively unlimited supply of boards of length actualLength.  The construction company wants to use as few boards as possible.  If there are multiple ways to use the same number of boards, they want to perform as few cuts as possible.  Return the number of cuts they will perform.

DEFINITION
Class:BoardSplitting
Method:minimumCuts
Parameters:int, int, int
Returns:int
Method signature:int minimumCuts(int desiredLength, int desiredCount, int actualLength)


NOTES
-A board is a one-dimensional piece of wood.  A single board of length L may be cut into two boards of length X and Y, provided X > 0, Y > 0, and X + Y = L.  Two boards of length X and Y may be glued together to form a board of length X + Y.


CONSTRAINTS
-desiredLength will be between 1 and 1000, inclusive.
-desiredCount will be between 1 and 1000, inclusive.
-actualLength will be between 1 and 1000, inclusive.


EXAMPLES

0)
5
4
4

Returns: 3

We need 4 boards of length 5 each. We have an unlimited supply of boards of length 4.  One solution is to cut one board into 4 pieces of length 1 each (using 3 cuts), then glue each piece to a board of length 4.

1)
6
100
3

Returns: 0

No cuts are necessary.

2)
500
5
1000

Returns: 3

We cut 3 boards in half.

3)
314
159
26

Returns: 147



*/

// END CUT HERE
