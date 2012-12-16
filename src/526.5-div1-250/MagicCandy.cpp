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

class MagicCandy {
	public:
	int whichOne(int n) {
        LL set = 0;
		while((set+1)*(set+1)<n) set++;
        LL lo = set*set;
        LL hi = (set+1)*(set+1);
        if(n <= (lo+hi)/2) return lo+1;
        return (lo+hi)/2 + 1;
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
			int n                     = 5;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MagicCandy().whichOne(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 9;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = MagicCandy().whichOne(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 20;
			int expected__            = 17;

			clock_t start__           = clock();
			int received__            = MagicCandy().whichOne(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 5265;
			int expected__            = 5257;

			clock_t start__           = clock();
			int received__            = MagicCandy().whichOne(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 20111223;
			int expected__            = 20110741;

			clock_t start__           = clock();
			int received__            = MagicCandy().whichOne(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int n                     = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MagicCandy().whichOne(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicCandy().whichOne(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicCandy().whichOne(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicCandy().whichOne(n);
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
// Today is the Christmas Eve. People around the world celebrate this 
holiday. The following story takes place in the land of reindeer, where Santa Claus resides.



The reindeer love candies. They have n pieces of candy. The pieces of candy are numbered 1 through n. Dasher is one of the reindeer. He wants to eat one of the candies. To pick the one he will eat, Dasher uses the following method:

While there is more than one piece of candy:
Discard all candies that are numbered by perfect squares (i.e., candies 1, 4, 9, 16, 25, etc.).
Relabel the remaining k candies 1 through k, keeping the numbers in the same order.
Once only one piece of candy remains, Dasher will eat it.




You are given an int n. Your method must compute and return the number initially assigned to the piece of candy eaten by Dasher.

DEFINITION
Class:MagicCandy
Method:whichOne
Parameters:int
Returns:int
Method signature:int whichOne(int n)


NOTES
-It can be proved that Dasher's method will always lead to a situation in which only one piece of candy remains.


CONSTRAINTS
-n will be between 1 and 1,000,000,000 inclusive.


EXAMPLES

0)
5

Returns: 5

We start with 5 candies. Let's call them A, B, C, D, and E. Initially, they are numbered 1 through 5, in this order.

In the first round, we discard candies with numbers 1 (which is A) and 4 (which is D).
This leaves us with candies B, C, and E.
These candies now get new numbers: B becomes 1, C becomes 2, and E becomes 3.
In the second round, we discard candy number 1 (which is now B).
This leaves us with candies C and E.
Again, the candies now get new numbers: C becomes 1 and E becomes 2.
In the third round, we discard candy number 1 (which is now C).

The only remaining candy is E. Its number in the beginning was 5, therefore our method should return 5.

1)
9

Returns: 7

This time we start with 9 pieces of candy. If we label them A through I, the process will look as follows:

start: ABCDEFGHI
throw away candies 1, 4, 9 (A, D, I)
after the first round: BCEFGH
throw away candies 1, 4 (B, F)
after the second round: CEGH
throw away candies 1, 4 (C, H)
after the third round: EG
throw away candy 1 (E)
at the end: G


2)
20

Returns: 17



3)
5265

Returns: 5257



4)
20111223

Returns: 20110741



5)
1

Returns: 1



*/

// END CUT HERE
