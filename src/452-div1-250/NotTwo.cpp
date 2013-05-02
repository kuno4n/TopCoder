
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

class NotTwo {
public:
   int maxStones( int width, int height ) {
	   int res = 0;
	   REP(i, width){
			REP(j, height){
				if(((i%4 == 0 || i%4 == 1) && (j%4 == 0 || j%4 == 1)) ||
					((i%4 == 2 || i%4 == 3) && (j%4 == 2 || j%4 == 3)))
					res++;
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
			int width                 = 3;
			int height                = 2;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = NotTwo().maxStones(width, height);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int width                 = 3;
			int height                = 3;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = NotTwo().maxStones(width, height);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int width                 = 8;
			int height                = 5;
			int expected__            = 20;

			clock_t start__           = clock();
			int received__            = NotTwo().maxStones(width, height);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int width                 = ;
			int height                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NotTwo().maxStones(width, height);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int width                 = ;
			int height                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NotTwo().maxStones(width, height);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int width                 = ;
			int height                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NotTwo().maxStones(width, height);
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
// Bob has a width x height rectangular board divided into 1 x 1 cells. Rows of the board are numbered 0 to height-1 and columns are numbered 0 to width-1.


Each cell can contain at most one stone, and the Euclidean distance between each pair of stones must not equal 2. The Euclidean distance between cell in row x1, column y1 and cell in row x2, column y2 is defined as the square root from (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2).


Return the maximal number of stones he can place on the board.


DEFINITION
Class:NotTwo
Method:maxStones
Parameters:int, int
Returns:int
Method signature:int maxStones(int width, int height)


CONSTRAINTS
-width will be between 1 and 1000, inclusive.
-height will be between 1 and 1000, inclusive.


EXAMPLES

0)
3
2

Returns: 4

He can place four stones on the board. Here is one possible arrangement:
- * *
* * -


1)
3
3

Returns: 5

* - -
* * -
- * *


2)
8
5

Returns: 20



*/

// END CUT HERE
