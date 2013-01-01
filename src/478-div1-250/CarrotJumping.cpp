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

#define MOD 1000000007

class CarrotJumping {
	public:
	int theJump(int init) {
		LL now = (((LL)init<<2) + 3)%MOD;
        int cnt = 2;
        while(now != 0 && cnt < 400000){
            cnt++;
            now = ((now<<1) + 1)%MOD;
        }
        if(cnt > 300000) return -1;
        int res = 0;
        if(cnt%3 == 0) res = cnt/3;
        else if(cnt%3 == 1) res = 2 + (cnt-2)/3;
        else res = 1 + (cnt-1)/3 ;
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
			int init                  = 125000000;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CarrotJumping().theJump(init);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int init                  = 281250001;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = CarrotJumping().theJump(init);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int init                  = 18426114;
			int expected__            = 58;

			clock_t start__           = clock();
			int received__            = CarrotJumping().theJump(init);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int init                  = 4530664;
			int expected__            = 478;

			clock_t start__           = clock();
			int received__            = CarrotJumping().theJump(init);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int init                  = 705616876;
			int expected__            = 100000;

			clock_t start__           = clock();
			int received__            = CarrotJumping().theJump(init);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int init                  = 852808441;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = CarrotJumping().theJump(init);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int init                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CarrotJumping().theJump(init);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int init                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CarrotJumping().theJump(init);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int init                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CarrotJumping().theJump(init);
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
// Rabbits often feel hungry, so when they go out to eat carrots, they jump as quickly as possible.


Initially, rabbit Hanako stands at position init. From position x, she can jump to either position 4*x+3 or 8*x+7 in a single jump. She can jump at most 100,000 times because she gets tired by jumping.


Carrots are planted at position x if and only if x is divisible by 1,000,000,007 (i.e. carrots are planted at position 0, position 1,000,000,007, position 2,000,000,014, and so on). Return the minimal number of jumps required to reach a carrot. If it's impossible to reach a carrot using at most 100,000 jumps, return -1.



DEFINITION
Class:CarrotJumping
Method:theJump
Parameters:int
Returns:int
Method signature:int theJump(int init)


CONSTRAINTS
-init will be between 1 and 1,000,000,006, inclusive.


EXAMPLES

0)
125000000

Returns: 1

She can jump from 125000000 to 1000000007.

1)
281250001

Returns: 2

281250001 -> 1125000007 -> 9000000063

2)
18426114

Returns: 58



3)
4530664

Returns: 478



4)
705616876

Returns: 100000

5)
852808441

Returns: -1

She can't reach any carrot by making at most 100,000 jumps.

*/

// END CUT HERE
