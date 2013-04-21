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

class SilverDistance {
	public:
	int minSteps(int sx, int sy, int gx, int gy) {
        int res = 3000000;
        REP(i, 2000001){
            int yy = sy + i;
            int dx = abs(gx - sx);
            int dy = abs(gy - yy);
            if((dy + dx) % 2 == 1)continue;
            res = min(res, i + max(dx, dy));
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
			int sx                    = 1;
			int sy                    = 0;
			int gx                    = 1;
			int gy                    = 9;
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = SilverDistance().minSteps(sx, sy, gx, gy);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int sx                    = 0;
			int sy                    = 0;
			int gx                    = -4;
			int gy                    = 3;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = SilverDistance().minSteps(sx, sy, gx, gy);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int sx                    = 0;
			int sy                    = 0;
			int gx                    = 5;
			int gy                    = 8;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = SilverDistance().minSteps(sx, sy, gx, gy);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int sx                    = -487617;
			int sy                    = 826524;
			int gx                    = 892309;
			int gy                    = -918045;
			int expected__            = 1744571;

			clock_t start__           = clock();
			int received__            = SilverDistance().minSteps(sx, sy, gx, gy);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int sx                    = -27857;
			int sy                    = 31475;
			int gx                    = -27857;
			int gy                    = 31475;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SilverDistance().minSteps(sx, sy, gx, gy);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int sx                    = ;
			int sy                    = ;
			int gx                    = ;
			int gy                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SilverDistance().minSteps(sx, sy, gx, gy);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int sx                    = ;
			int sy                    = ;
			int gx                    = ;
			int gy                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SilverDistance().minSteps(sx, sy, gx, gy);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int sx                    = ;
			int sy                    = ;
			int gx                    = ;
			int gy                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SilverDistance().minSteps(sx, sy, gx, gy);
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
// In Japanese Chess, there is a piece called Silver. A Silver piece located in cell (x,y) can move to any of the following cells in one step: (x-1,y+1), (x,y+1), (x+1,y+1), (x-1,y-1), (x+1,y-1). In other words, it can move one cell in any of the four diagonal directions, or it can move one cell vertically in the positive y direction.





Initially, there's a Silver piece in cell (sx,sy) of an infinitely large board. Return the minimal number of steps required to move to cell (gx,gy).

DEFINITION
Class:SilverDistance
Method:minSteps
Parameters:int, int, int, int
Returns:int
Method signature:int minSteps(int sx, int sy, int gx, int gy)


CONSTRAINTS
-sx, sy, gx and gy will each be between -1,000,000 and 1,000,000 inclusive.


EXAMPLES

0)
1
0
1
9

Returns: 9

Move up vertically in the positive y direction 9 times.

1)
0
0
-4
3

Returns: 5

Follow the path : (0,0) -> (-1,1) -> (-1,2) -> (-2,3) -> (-3,2) -> (-4,3)

2)
0
0
5
8

Returns: 8

Move up vertically in the postive y direction 3 times, then move diagonally up and to the right 5 times.

3)
-487617
826524
892309
-918045

Returns: 1744571



4)
-27857
31475
-27857
31475

Returns: 0

The Silver is already in the goal.

*/

// END CUT HERE
