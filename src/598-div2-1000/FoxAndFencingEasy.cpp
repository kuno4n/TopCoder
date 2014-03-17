#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <fstream>
//#include "cout.h"

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
#define OUT(A) cout << #A << " = "<< (A) << endl
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

class FoxAndFencingEasy {
public:
   string WhoCanWin( int mov1, int mov2, int d ) {
       if(mov1 >= d) return "Ciel";
       if(mov1 < (mov2+1)/2) return "Liss";
       if(mov2 < (mov1+1)/2) return "Ciel";
       return "Draw";
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
			int mov1                  = 1;
			int mov2                  = 58;
			int d                     = 1;
			string expected__         = "Ciel";

			clock_t start__           = clock();
			string received__         = FoxAndFencingEasy().WhoCanWin(mov1, mov2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int mov1                  = 100;
			int mov2                  = 100;
			int d                     = 100000000;
			string expected__         = "Draw";

			clock_t start__           = clock();
			string received__         = FoxAndFencingEasy().WhoCanWin(mov1, mov2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int mov1                  = 100;
			int mov2                  = 150;
			int d                     = 100000000;
			string expected__         = "Draw";

			clock_t start__           = clock();
			string received__         = FoxAndFencingEasy().WhoCanWin(mov1, mov2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int mov1                  = 100;
			int mov2                  = 250;
			int d                     = 100000000;
			string expected__         = "Liss";

			clock_t start__           = clock();
			string received__         = FoxAndFencingEasy().WhoCanWin(mov1, mov2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int mov1                  = ;
			int mov2                  = ;
			int d                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndFencingEasy().WhoCanWin(mov1, mov2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int mov1                  = ;
			int mov2                  = ;
			int d                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndFencingEasy().WhoCanWin(mov1, mov2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int mov1                  = ;
			int mov2                  = ;
			int d                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndFencingEasy().WhoCanWin(mov1, mov2, d);
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
// Fox Ciel is playing a board game with her friend Squirrel Liss.
The game is played on an infinite strip of paper.
The strip of paper is divided into consecutive cells.
Each cell has an integer coordinate.
Formally, for each integer i, the left neighbor of cell i is cell (i-1) and the right neighbor of cell i is cell (i+1).



Each of the players has a single token called the fencer.
At the beginning of the game, Ciel's fencer is in cell 0 and Liss's fencer is in cell d.
Each of the fencers has a limit: its maximum move length.
For Ciel's fencer the maximum move length is mov1 and for Liss's fencer it is mov2.



The players take alternating turns.
Ciel goes first.
In each turn the current player moves her fencer.
The distance between the original cell and the destination cell must be at most equal to the fencer's maximum move length.
(It is also allowed to leave the fencer in the same cell.)
If the current player moves her fencer into the cell with the other fencer, the current player's fencer scores a hit and wins the game.



You are given the ints mov1, mov2, and d.
Return "Ciel" (quotes for clarity) if Fox Ciel has a winning strategy, "Liss" if Squirrel Liss has a winning strategy, and "Draw" otherwise.

DEFINITION
Class:FoxAndFencingEasy
Method:WhoCanWin
Parameters:int, int, int
Returns:string
Method signature:string WhoCanWin(int mov1, int mov2, int d)


CONSTRAINTS
-mov1 will be between 1 and 100,000,000, inclusive.
-mov2 will be between 1 and 100,000,000, inclusive.
-d will be between 1 and 100,000,000, inclusive.


EXAMPLES

0)
1
58
1

Returns: "Ciel"

Ciel can win in her first turn by moving her fencer one cell to the right.


1)
100
100
100000000

Returns: "Draw"

Liss can avoid getting hit forever by repeating Ciel's moves. For example, whenever Ciel moves her fencer 47 cells to the right, Liss also moves her fencer 47 cells to the right. Ciel has a similar strategy: in her first turn she can move her fencer arbitrarily and in each of the following turns she will repeat Liss's previous move. Therefore the game ends in a draw.

2)
100
150
100000000

Returns: "Draw"



3)
100
250
100000000

Returns: "Liss"



*/

// END CUT HERE
