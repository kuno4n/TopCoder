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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

class SplitStoneGame {
	public:
	string winOrLose(vector <int> number) {
		int n = SZ(number);
        bool ng = true;
        REP(i, n) ng &= number[i] == 1;
        if(ng) return "LOSE";
        if(n == 1) return "LOSE";
        if(n&1) return "WIN";
        return "LOSE";
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
			int number[]              = {1, 1, 1};
			string expected__         = "LOSE";

			clock_t start__           = clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int number[]              = {2, 2};
			string expected__         = "LOSE";

			clock_t start__           = clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int number[]              = {1, 1, 2};
			string expected__         = "WIN";

			clock_t start__           = clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int number[]              = {1, 2, 3, 4, 3, 2, 2, 4, 3, 1, 4, 4, 1, 2, 4, 4, 1, 4, 3, 1, 4, 2, 1};
			string expected__         = "WIN";

			clock_t start__           = clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int number[]              = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 1, 9, 1, 3, 1, 1, 1, 1, 1};
			string expected__         = "LOSE";

			clock_t start__           = clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int number[]              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int number[]              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int number[]              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
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
Shiny likes to play games.
Her favorite games are games with pebbles (small stones).
Today, she is playing such a game with her friend Lucy.

Initially, there are N piles of stones.
You are given a vector <int> number with N elements.
Each element of number is the number of stones in one of the piles.

The players take alternating turns.
Shiny plays first.
In each turn, the current player must:

Choose a pile X that has at least two stones.
Split the chosen pile X into two non-empty parts A and B. (The parts can have arbitrary sizes, as long as both are non-empty.)
Choose two piles Y and Z. (Y and Z must be different non-empty piles other than X.)
Add all stones from A to the pile X, and all stones from B to the pile Y.


For example, if the current piles are {1, 2, 50}, the current player could:

Choose the pile with 50 stones as X.
Split it into two parts with 25 stones each.
Choose the other two piles (the ones with 1 and 2 stones) to be Y and Z.
Add all stones from A to the pile X, and all stones from B to the pile Y. At the end of the turn, there are two piles of stones: one with 26 and one with 27 stones.


The player who cannot make a valid move loses the game.
Assume that both players play the game optimally.
Return the string "WIN" (quotes for clarity) if Shiny wins the game, and "LOSE" if she does not.


DEFINITION
Class:SplitStoneGame
Method:winOrLose
Parameters:vector <int>
Returns:string
Method signature:string winOrLose(vector <int> number)


CONSTRAINTS
-number will contain between 1 and 50 elements, inclusive.
-Each element of number will be between 1 and 50, inclusive.


EXAMPLES

0)
{1, 1, 1}

Returns: "LOSE"

Shiny can't choose a pile X that has at least two stones, so she loses.

1)
{2, 2}

Returns: "LOSE"

After Shiny chooses one of the piles as X and splits it into two piles with one stone each, she is
unable to choose Y and Z, because there is only one pile left to choose from at the moment. Thus,
she cannot make a valid move and therefore she loses the game.

2)
{1, 1, 2}

Returns: "WIN"

Shiny can choose the last pile as X, split it into 1+1 stone, and add those stones to the other two
piles. This is a valid move that produces two piles with two stones each, and it is now Lucy's turn. 
As we saw in Example 1, Lucy now has no valid move left, thus she loses the game and Shiny is the
winner.

3)
{1, 2, 3, 4, 3, 2, 2, 4, 3, 1, 4, 4, 1, 2, 4, 4, 1, 4, 3, 1, 4, 2, 1}

Returns: "WIN"



4)
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 1, 9, 1, 3, 1, 1, 1, 1, 1}

Returns: "LOSE"



*/

// END CUT HERE
