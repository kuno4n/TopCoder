
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

class RedAndGreen {
public:
   int minPaints( string row ) {
	   int n = SZ(row);
	   int res = 50;
	   for(int i=0; i<=n; i++){
		   int tmp = 0;
		   REP(j, n){
			   if(j<i && row[j]=='G')  tmp++;
			   else if(j>=i && row[j]=='R') tmp++;
		   }
		   res = min(res, tmp);
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
			string row                = "RGRGR";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = RedAndGreen().minPaints(row);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string row                = "RRRGGGGG";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = RedAndGreen().minPaints(row);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string row                = "GGGGRRR";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = RedAndGreen().minPaints(row);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string row                = "RGRGRGRGRGRGRGRGR";
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = RedAndGreen().minPaints(row);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string row                = "RRRGGGRGGGRGGRRRGGRRRGR";
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = RedAndGreen().minPaints(row);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string row                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RedAndGreen().minPaints(row);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string row                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RedAndGreen().minPaints(row);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string row                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RedAndGreen().minPaints(row);
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
// 
You have several squares arranged in a single row. Each square is currently painted red or green. You can choose any of the squares and paint it over with either color. The goal is that, after painting, every red square is further to the left than any of the green squares. We want you to do it repainting the minimum possible number of squares.

Squares are numbered from left to right. You will be given the initial arrangement as a string row, such that character i is 'R' if square i is red or 'G' if square i is green. Return the minimum number of repaints needed to achieve the goal.


DEFINITION
Class:RedAndGreen
Method:minPaints
Parameters:string
Returns:int
Method signature:int minPaints(string row)


CONSTRAINTS
-row will contain between 1 and 50 characters, inclusive.
-Each character of row will be either 'R' or 'G'.


EXAMPLES

0)
"RGRGR"

Returns: 2

Paint the squares in the marked positions in the picture below with the opposite color. There are other ways with 2 total paints.

RGRGR
 |  |
RRRGG


1)
"RRRGGGGG"

Returns: 0

There is no need to paint anything.

2)
"GGGGRRR"

Returns: 3

Paint all the red squares green.

3)
"RGRGRGRGRGRGRGRGR"

Returns: 8



4)
"RRRGGGRGGGRGGRRRGGRRRGR"

Returns: 9



*/

// END CUT HERE
