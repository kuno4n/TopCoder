#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset((x), (a), (int)sizeof(x))
#define VI vector < int >
#define LL long long 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FIT(it,v) for(typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define OUT(A) cout << #A << " = " << A << endl

class MagicStonesStore {
	public:
	string ableToDivide(int n) {
		if(n>1) return "YES";
        else return "NO";
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int n                     = 1;
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = MagicStonesStore().ableToDivide(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 2;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = MagicStonesStore().ableToDivide(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 3;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = MagicStonesStore().ableToDivide(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 5;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = MagicStonesStore().ableToDivide(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = MagicStonesStore().ableToDivide(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = MagicStonesStore().ableToDivide(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = MagicStonesStore().ableToDivide(n);
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



The currency in the land of reindeer are magic stones. Santa's reindeer have 2n magic stones (i.e., an even number of them). They want to divide the stones into two piggy banks. Santa's reindeer are very fond of primes, therefore they want each piggy bank to contain a prime number of magic stones.



You are given an int n. If it is possible to divide 2n magic stones into two piggy banks, each containing a prime number of stones, return "YES", otherwise return "NO" (quotes for clarity).

DEFINITION
Class:MagicStonesStore
Method:ableToDivide
Parameters:int
Returns:string
Method signature:string ableToDivide(int n)


NOTES
-A positive integer is prime if and only if it has exactly two positive integer divisors. The first few prime numbers are 2, 3, 5, 7, 11, ...
-The number zero is not a prime number, hence you are not allowed to leave any piggy bank empty.


CONSTRAINTS
-n will be between 1 and 1,000, inclusive.


EXAMPLES

0)
1

Returns: "NO"

As n=1, we are dividing 2 magic stones into two piggy banks. In this case is impossible to have a prime number of stones in each piggy bank.

1)
2

Returns: "YES"

The only valid way of dividing the stones in this case is to put 2 magic stones into each of the piggy banks.

2)
3

Returns: "YES"

Now the only way is to put 3 magic stones into each of the piggy banks.

3)
5

Returns: "YES"

For 2n=10 stones we have two valid ways of dividing them: either as 5 + 5 or as 7 + 3.

*/

// END CUT HERE
