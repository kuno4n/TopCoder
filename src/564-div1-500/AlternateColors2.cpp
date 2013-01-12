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

LL dp[100010][8][3];

class AlternateColors2 {
	public:
	long long countWays(int n, int k) {
        MSET(dp, 0);
        int color[3];
        for(int i=n; i>=0; i--){
            FOR(mask, 1, 8){
                int t = 0;
                REP(j, 3) if(mask&(1<<j)) color[t++] = j;
                REP(p, t){
                    if(i==n) dp[i][mask][p] = 1;
                    else{
                        if(k-1!=i || color[p]==0) dp[i][mask][p] += dp[i+1][mask][(p+1)%t];                        
                        if(t>1) dp[i][mask][p] += dp[i][mask - (1<<color[p])][p==t-1 ? 0 : p];
                    }
                }
            }
        }
        return dp[0][7][0];
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
			int n                     = 1;
			int k                     = 1;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 3;
			int k                     = 3;
			long long expected__      = 3;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 6;
			int k                     = 4;
			long long expected__      = 9;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 6;
			int k                     = 1;
			long long expected__      = 21;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 1000;
			int k                     = 2;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int n                     = 100000;
			int k                     = 100000;
			long long expected__      = 1666700000;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int n                     = ;
			int k                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int k                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int n                     = ;
			int k                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
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
// Bob is playing with his ball destroyer robot. Initially, Bob had r red balls, g green balls and b blue balls. The robot repeated the following 3-step program until there were no balls left:

If there is at least one red ball available, destroy one red ball.
If there is at least one green ball available, destroy one green ball.
If there is at least one blue ball available, destroy one blue ball.

Bob forgot how many balls of each color he initially had. He only remembers that there were n balls in total and that the k-th (1-based index) ball that was destroyed was red. Return the total number of different initial settings that match that description. Formally, return the number of different tuples (r, g, b) such that r + g + b = n and the k-th ball that was destroyed was red.

DEFINITION
Class:AlternateColors2
Method:countWays
Parameters:int, int
Returns:long long
Method signature:long long countWays(int n, int k)


NOTES
-It follows from the constraints that the return value will always fit into a long long.


CONSTRAINTS
-n will be between 1 and 100000, inclusive.
-k will be between 1 and n, inclusive.


EXAMPLES

0)
1
1

Returns: 1

There was only one ball. This ball was necessarily the first ball destroyed. Therefore, it had to be red.

1)
3
3

Returns: 3

There are three cases in which the third ball to be destroyed is red:
r = 3, b = 0, g = 0.
r = 2, b = 1, g = 0.
r = 2, b = 0, g = 1.

2)
6
4

Returns: 9



3)
6
1

Returns: 21



4)
1000
2

Returns: 1

In order for the second destroyed ball to be red, there would have to be zero balls of the other colors.

5)
100000
100000

Returns: 1666700000



*/

// END CUT HERE
