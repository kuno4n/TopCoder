
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
#include <queue>
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
#define OUT(A) cout << #A << " = "<< A << endl

VI B;
int r, c, szr, szc;

class EllysFigurines {
public:
   int getMoves( vector <string> board, int R, int C ) {
	   r = R; c = C;
	   szr = SZ(board); szc = SZ(board[0]);
	   B.clear();
	   REP(i, szr){
		   int tmp = 0;
		   REP(j, szc) if(board[i][j] == 'X') tmp += (1<<j);
		   B.PB(tmp);
	   }

	   int res = 100;
	   REP(i, (1<<szr)){
		   int mask = i;
		   int cnt = 0;

		   REP(j, szr) if(i & (1<<j)){
			   cnt++;
			   REP(k, R) if(j + k < szr) mask |= (1<<(j+k));
		   }
		   int S = 0;
		   REP(j, szr) if(!(mask & (1<<j))) S |= B[j];

		   REP(j, szc) if(S & (1<<j)){
			   cnt++;
			   REP(k, C) if(j + k < szc) S &= (~(1<<(j + k)));
		   }
		   res = min(res, cnt);
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
			string board[]            = {".X.X.",
 "XX..X",
 ".XXX.",
 "...X.",
 ".X.XX"};
			int R                     = 1;
			int C                     = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {".X.X.",
 "XX..X",
 ".X.X.",
 "...X.",
 ".X.XX"};
			int R                     = 2;
			int C                     = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"XXXXXXX"};
			int R                     = 2;
			int C                     = 3;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"XXXXX",
 "X....",
 "XXX..",
 "X....",
 "XXXXX"};
			int R                     = 1;
			int C                     = 1;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"XXX..XXX..XXX.",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X...XXX..XXX.",
 "..............",
 "...XX...XXX...",
 "....X......X..",
 "....X....XXX..",
 "....X......X..",
 "...XXX..XXX..."};
			int R                     = 1;
			int C                     = 2;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int R                     = ;
			int C                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int R                     = ;
			int C                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int R                     = ;
			int C                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
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
// Elly has placed several (possibly none) figurines on a rectangular board with several rows and columns. Now Kristina wants to remove all figurines from the board. In a single move she selects either up to R consecutive rows, or up to C consecutive columns and removes all remaining figurines that are located there. The girl wonders what is the minimal number of moves in which she can clear the entire board.

The position of the figurines will be given to you in the vector <string> board. The j-th character of the i-th element of board will be '.' if the cell is empty, or 'X' if it contains a figurine. The maximal number of cleared rows in a single move will be given in the int R. The maximal number of cleared columns in a single move will be given in the int C. Return the minimal number of moves that is sufficient to clear the entire board.

DEFINITION
Class:EllysFigurines
Method:getMoves
Parameters:vector <string>, int, int
Returns:int
Method signature:int getMoves(vector <string> board, int R, int C)


NOTES
-In a single move the girl can only select a consecutive group of rows or columns to be cleared. In other words, in each move Kristina first decides whether she wants rows or columns, then she picks the index i of the first chosen row/column, then the number k of chosen rows/columns, and finally she removes all figurines from the rows/columns with indices i, i+1, i+2, ..., i+k-1.


CONSTRAINTS
-board will contain between 1 and 15 elements, inclusive.
-Each element of board will contain between 1 and 15 characters, inclusive.
-All elements of board will contain the same number of characters.
-Each character of board will be either '.' or 'X'.
-R will be between 1 and 15, inclusive.
-C will be between 1 and 15, inclusive.


EXAMPLES

0)
{".X.X.",
 "XX..X",
 ".XXX.",
 "...X.",
 ".X.XX"}
1
2

Returns: 3

In this case in a single move Elly can remove all figurines from a single row, all figurines from a single column or all figurines from two consecutive columns.
One way to achieve the optimal answer here would be to remove the figurines from the first and second column in the first move, then the ones from the fourth and fifth column in the second move, and finally the remaining ones on the third row in the third move.
Another solution would be to erase only columns, again using three moves.

1)
{".X.X.",
 "XX..X",
 ".X.X.",
 "...X.",
 ".X.XX"}
2
2

Returns: 2

Almost the same as the first example, but without the figurine in the middle and the number of maximal rows removed is increased by one.
This time, the only optimal solution is to clear the first two columns in one move and the last two in another move.

2)
{"XXXXXXX"}
2
3

Returns: 1

The maximal allowed number of cleared rows or columns might be greater than the corresponding dimension of the board. The optimal solution for this board is to clear the only row in one move.

3)
{"XXXXX",
 "X....",
 "XXX..",
 "X....",
 "XXXXX"}
1
1

Returns: 4

Here clearing rows 1, 3 and 5, together with column 1 yields the best result 4.

4)
{"XXX..XXX..XXX.",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X...XXX..XXX.",
 "..............",
 "...XX...XXX...",
 "....X......X..",
 "....X....XXX..",
 "....X......X..",
 "...XXX..XXX..."}
1
2

Returns: 7

Good luck in TCO 13!

*/

// END CUT HERE
