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
#define OUT(A) cout << #A << " = " << (A) << endl

class BinaryCards {
	public:
	long long largestNumber(long long A, long long B) {
		LL res = 0;
        int diff = -1;
        REP(i, 64) if((A>>i&1) != (B>>i&1)) diff = i;
        for(int i=0; i<=diff; i++) res += ((LL)1<<i);
        FOR(i, diff+1, 64) if((B>>i)&1) res += ((LL)1<<i);
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
			long long A               = 6;
			long long B               = 6;
			long long expected__      = 6;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long A               = 6;
			long long B               = 7;
			long long expected__      = 7;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long A               = 6;
			long long B               = 8;
			long long expected__      = 15;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long A               = 1;
			long long B               = 11;
			long long expected__      = 15;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long A               = 35;
			long long B               = 38;
			long long expected__      = 39;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			long long A               = 1125899906842630LL;
			long long B               = 1125899906842632LL;
			long long expected__      = 1125899906842639LL;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			long long A               = ;
			long long B               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long A               = ;
			long long B               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			long long A               = ;
			long long B               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber(A, B);
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
// Karel is a robot. He has a set of 64 cards: for each x between 0 and 63, he has a card that is blank on one side and has 2^x dots on the other side.

Karel's cards are placed on a table. At any moment, the cards show some integer between 0 and (2^64)-1, inclusive. To read the number, you just count all the dots you see.

Karel is using the cards to count from A to B. That is, he is flipping some of the cards in such a way that the numbers A, A+1, ..., B appear in this order.

Of course, Karel is using the shortest possible sequence of flips. Additionally, he always flips the cards one at a time. Sometimes, changing the number from some Z to Z+1 requires Karel to flip more than one card. In that case, he flips the necessary cards ordered by the number of dots they have, starting with the one with the most dots.

For example, if A=6 and B=8, the following will happen:


In the beginning, the card with 4 dots and the card with 2 dots are showing the dots, all other cards are blank side up. This shows the number 6.
Karel flips the card with 1 dot. Now the number 7 is shown.
Karel flips the card with 8 dots.
Karel flips the card with 4 dots.
Karel flips the card with 2 dots.
Karel flips the card with 1 dot. Now the number 8 is shown and Karel is done.



Given are long longs A and B. Your method must return the largest number that will be shown at any moment during Karel's counting.


DEFINITION
Class:BinaryCards
Method:largestNumber
Parameters:long long, long long
Returns:long long
Method signature:long long largestNumber(long long A, long long B)


CONSTRAINTS
-A will be between 1 and 10^18, inclusive.
-B will be between A and 10^18, inclusive.


EXAMPLES

0)
6
6

Returns: 6



1)
6
7

Returns: 7



2)
6
8

Returns: 15

This is the example from the problem statement. When flipping cards to create the number 8 from the number 7, Karel starts by flipping the card with 8 dots. At this moment, the number shown on the cards is 15.

3)
1
11

Returns: 15



4)
35
38

Returns: 39



5)
1125899906842630
1125899906842632

Returns: 1125899906842639



*/

// END CUT HERE
