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




class LotteryCheating {
	public:
	int minimalChange(string ID) {
        int res = 0;
        REP(i, SZ(ID)) if(ID[i]!='0') res++;
        
        for(LL i=1; i*i<10000000000LL; i++){
            int diff = 0;
            LL tmp = i*i;
            for(int j = SZ(ID)-1; j>=0; j--){
                if(ID[j]-'0' != tmp%10) diff++;
                tmp /= 10;
            }
            if(tmp) continue;
            res = min(res, diff);
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
			string ID                 = "1";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = LotteryCheating().minimalChange(ID);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string ID                 = "1234";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = LotteryCheating().minimalChange(ID);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string ID                 = "9000000000";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = LotteryCheating().minimalChange(ID);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string ID                 = "4294967296";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = LotteryCheating().minimalChange(ID);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string ID                 = "7654321";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = LotteryCheating().minimalChange(ID);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string ID                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LotteryCheating().minimalChange(ID);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string ID                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LotteryCheating().minimalChange(ID);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string ID                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LotteryCheating().minimalChange(ID);
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
// Bob likes to play the lottery, but it's so hard to win without cheating.  Each lottery ticket has an identifier which contains exactly n decimal digits.  If an identifier contains only '0's, it is considered a winning ticket.  Otherwise, the identifier is interpreted as a positive integer X written in decimal notation (possibly with leading zeros).  If X has an odd number of positive integer divisors, it is a winning ticket, otherwise, it is not.  A positive integer is a divisor of X if it divides X evenly.


Unfortunately, Bob only has enough money to buy one ticket, and he cannot see the identifier before buying a ticket.  Therefore, he decides to cheat by buying a ticket and modifying its identifier to make it a winning ticket.  In a single change operation, he can choose one digit, erase it, and print some other digit in the same position.  No other types of modifications are allowed.  He can perform any number of these change operations, but he wants to perform as few as possible to minimize the risk of getting caught.


You are given a string ID, the initial identifier on Bob's ticket.  Return the minimal number of change operations necessary to transform the identifier into a winning one.  If the initial identifier is already a winner, return 0.

DEFINITION
Class:LotteryCheating
Method:minimalChange
Parameters:string
Returns:int
Method signature:int minimalChange(string ID)


CONSTRAINTS
-ID will contain between 1 and 10 characters, inclusive.
-Each character in ID will be between '0' and '9', inclusive.


EXAMPLES

0)
"1"

Returns: 0

1 is the only divisor of this identifier.  Since there are an odd number of divisors, it is already a winning ticket, and no changes are necessary.

1)
"1234"

Returns: 2

One possible solution is to transform "1234" into "1024". As 1024 is 2^10, it has 11 divisors: 2^0, 2^1, ..., 2^10.

2)
"9000000000"

Returns: 1

Bob can change the '9' into a '0'. The resulting identifier "0000000000" contains only '0's, so it is a winning ticket.

3)
"4294967296"

Returns: 0

The initial identifier represents the integer 2^32, so it has 33 divisors.

4)
"7654321"

Returns: 3



*/

// END CUT HERE
