
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

class PotatoGame {
	public:
	string theWinner(int n) {
		if(n%5 == 0 || n%5 == 2) return "Hanako";
        else return "Taro";
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
			string expected__         = "Taro";

			clock_t start__           = clock();
			string received__         = PotatoGame().theWinner(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 2;
			string expected__         = "Hanako";

			clock_t start__           = clock();
			string received__         = PotatoGame().theWinner(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 3;
			string expected__         = "Taro";

			clock_t start__           = clock();
			string received__         = PotatoGame().theWinner(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int n                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PotatoGame().theWinner(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int n                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PotatoGame().theWinner(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PotatoGame().theWinner(n);
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
// Taro and Hanako like potatoes very much. Today they decided to play Potato Game.


Initially there is a box containing n potatoes. Taro and Hanako alternate turns, and Taro goes first. In each turn, the player must eat some potatoes from the box. The number of eaten potatoes must be a power of four, i.e., 1, 4, 16, 64 and so on. The first player who cannot eat a valid number of potatoes loses. Return the name of the winner assuming that they both play optimally.


DEFINITION
Class:PotatoGame
Method:theWinner
Parameters:int
Returns:string
Method signature:string theWinner(int n)


CONSTRAINTS
-n will be between 1 and 1,000,000,000 (10^9), inclusive.


EXAMPLES

0)
1

Returns: "Taro"

Taro will win if he eats 1 potato in the first turn.

1)
2

Returns: "Hanako"

Taro must eat exactly 1 potato in the first turn. In the second turn, Hanako will eat 1 potato and she will win.

2)
3

Returns: "Taro"



*/

// END CUT HERE
