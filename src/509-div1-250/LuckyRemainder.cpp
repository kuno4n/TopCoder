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

class LuckyRemainder {
	public:
	int getLuckyRemainder(string X) {
        LL tmp = 0;
        REP(i, SZ(X)) tmp += X[i]-'0';
        REP(i, SZ(X)-1) tmp = (tmp<<1) %9;
        return tmp%9;
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
			string X                  = "123";
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string X                  = "24816";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string X                  = "8";
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string X                  = "11235813213455";
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string X                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string X                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string X                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
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
// Little Arthur loves numbers and 9 is his most favorite. When encountering a number, he always calculates its lucky remainder - the remainder after division by 9. 

This time Arthur is given a number X of length N which contains no zeros. He is asked to find the supersum of X: super(X).

super(X) is defined as follows. For a given non-full set S of digit positions in X we erase the digits in these positions to obtain a sub-number. For example, if X = 12345 and S = {2, 4} we erase 2nd and 4th digits and obtain a sub-number 135. Supersum of X is simply the sum of sub-numbers for all valid sets S.

For example, if X is 123, then super(X) = 123 + 12 + 13 + 23 + 1 + 2 + 3 = 177.

Calculating super(X) is very difficult for Arthur. However, before getting to work he is wondering if it is possible to quickly tell what the lucky reminder of the supersum of X is. You have to help him.

Given string X, which contains the decimal representation of the number X, return super(X)'s lucky remainder.

DEFINITION
Class:LuckyRemainder
Method:getLuckyRemainder
Parameters:string
Returns:int
Method signature:int getLuckyRemainder(string X)


CONSTRAINTS
-X will contain between 1 and 50 characters, inclusive.
-Each character of X will be one of the following: '1', '2', '3', '4', '5', '6', '7', '8', '9'.


EXAMPLES

0)
"123"

Returns: 6

Example?from?the?problem?statement.?super(123)?=?177,?which?gives?remainder?6?after?division?by?9.

1)
"24816"

Returns: 3

Supersum of 24816 is 43986.

2)
"8"

Returns: 8



3)
"11235813213455"

Returns: 7

Supersum is 43950094900477.

*/

// END CUT HERE
