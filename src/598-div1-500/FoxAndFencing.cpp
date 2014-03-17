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

class FoxAndFencing {
public:
   string WhoCanWin( int mov1, int mov2, int rng1, int rng2, int d ) {
       if(mov1 + rng1 >= d) return "Ciel";
       if(mov1 + d <= mov2 + rng2) return "Liss";
       if(mov1 > mov2 && mov1+rng1 > mov2*2+rng2) return "Ciel";
       if(mov2 > mov1 && mov2+rng2 > mov1*2+rng1) return "Liss";
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
			int rng1                  = 1;
			int rng2                  = 58;
			int d                     = 2;
			string expected__         = "Ciel";

			clock_t start__           = clock();
			string received__         = FoxAndFencing().WhoCanWin(mov1, mov2, rng1, rng2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int mov1                  = 2;
			int mov2                  = 1;
			int rng1                  = 1;
			int rng2                  = 100;
			int d                     = 50;
			string expected__         = "Liss";

			clock_t start__           = clock();
			string received__         = FoxAndFencing().WhoCanWin(mov1, mov2, rng1, rng2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int mov1                  = 2;
			int mov2                  = 1;
			int rng1                  = 1;
			int rng2                  = 100;
			int d                     = 150;
			string expected__         = "Draw";

			clock_t start__           = clock();
			string received__         = FoxAndFencing().WhoCanWin(mov1, mov2, rng1, rng2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int mov1                  = 100;
			int mov2                  = 100;
			int rng1                  = 100;
			int rng2                  = 100;
			int d                     = 100000000;
			string expected__         = "Draw";

			clock_t start__           = clock();
			string received__         = FoxAndFencing().WhoCanWin(mov1, mov2, rng1, rng2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int mov1                  = 100;
			int mov2                  = 1;
			int rng1                  = 100;
			int rng2                  = 1;
			int d                     = 100000000;
			string expected__         = "Ciel";

			clock_t start__           = clock();
			string received__         = FoxAndFencing().WhoCanWin(mov1, mov2, rng1, rng2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int mov1                  = 100;
			int mov2                  = 1;
			int rng1                  = 100;
			int rng2                  = 250;
			int d                     = 100000000;
			string expected__         = "Draw";

			clock_t start__           = clock();
			string received__         = FoxAndFencing().WhoCanWin(mov1, mov2, rng1, rng2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int mov1                  = 100;
			int mov2                  = 1;
			int rng1                  = 100;
			int rng2                  = 150;
			int d                     = 100000000;
			string expected__         = "Ciel";

			clock_t start__           = clock();
			string received__         = FoxAndFencing().WhoCanWin(mov1, mov2, rng1, rng2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			int mov1                  = 100;
			int mov2                  = 50;
			int rng1                  = 100;
			int rng2                  = 1;
			int d                     = 100000000;
			string expected__         = "Ciel";

			clock_t start__           = clock();
			string received__         = FoxAndFencing().WhoCanWin(mov1, mov2, rng1, rng2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 8: {
			int mov1                  = 100;
			int mov2                  = 150;
			int rng1                  = 100;
			int rng2                  = 1;
			int d                     = 100000000;
			string expected__         = "Draw";

			clock_t start__           = clock();
			string received__         = FoxAndFencing().WhoCanWin(mov1, mov2, rng1, rng2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 9: {
			int mov1                  = ;
			int mov2                  = ;
			int rng1                  = ;
			int rng2                  = ;
			int d                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndFencing().WhoCanWin(mov1, mov2, rng1, rng2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int mov1                  = ;
			int mov2                  = ;
			int rng1                  = ;
			int rng2                  = ;
			int d                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndFencing().WhoCanWin(mov1, mov2, rng1, rng2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 11: {
			int mov1                  = ;
			int mov2                  = ;
			int rng1                  = ;
			int rng2                  = ;
			int d                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndFencing().WhoCanWin(mov1, mov2, rng1, rng2, d);
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
Each of the fencers has two limits: its maximum move length and its hitting range.
For Ciel's fencer the maximum move length is mov1 and the hitting range is rng1.
Similarly, for Liss's fencer we have the parameters mov2 and rng2.
Note that the parameters of Liss's fencer may differ from the ones of Ciel's fencer.



The players take alternating turns.
Ciel goes first.
In each turn the current player starts by moving her fencer.
The distance between the original cell and the destination cell must be at most equal to the fencer's maximum move length.
(It is also allowed to leave the fencer in the same cell.)
Then, the current player checks whether the other fencer lies within the hitting range - that is, whether the current distance between the fencers is at most equal to the current fencer's hitting range.
If that is the case, the game ends and the current player wins.



You are given the ints mov1, mov2, rng1, rng2, and d.
Return "Ciel" (quotes for clarity) if Fox Ciel has a winning strategy, "Liss" if Squirrel Liss has a winning strategy, and "Draw" otherwise.

DEFINITION
Class:FoxAndFencing
Method:WhoCanWin
Parameters:int, int, int, int, int
Returns:string
Method signature:string WhoCanWin(int mov1, int mov2, int rng1, int rng2, int d)


CONSTRAINTS
-mov1 will be between 1 and 100,000,000, inclusive.
-mov2 will be between 1 and 100,000,000, inclusive.
-rng1 will be between 1 and 100,000,000, inclusive.
-rng2 will be between 1 and 100,000,000, inclusive.
-d will be between 1 and 100,000,000, inclusive.


EXAMPLES

0)
1
58
1
58
2

Returns: "Ciel"

The attributes of Ciel's fencer are much smaller than the attributes of Liss's fencer.
Luckily for Ciel, she can win the game in her first turn:
she should move her fencer to cell 1 and from there she can hit the other fencer.

1)
2
1
1
100
50

Returns: "Liss"

Ciel cannot score a hit in the first turn.
After Ciel's turn, her fencer will be on one of the cells {-2,-1,0,1,2}.
Regardless of its precise location, Liss can always move her fencer one cell to the left and then hit Ciel.

2)
2
1
1
100
150

Returns: "Draw"

Clearly, Ciel has no chance of winning this game.
However, this time the initial distance d is big enough for Ciel to escape.

3)
100
100
100
100
100000000

Returns: "Draw"



4)
100
1
100
1
100000000

Returns: "Ciel"



5)
100
1
100
250
100000000

Returns: "Draw"



6)
100
1
100
150
100000000

Returns: "Ciel"



7)
100
50
100
1
100000000

Returns: "Ciel"



8)
100
150
100
1
100000000

Returns: "Draw"



*/

// END CUT HERE
