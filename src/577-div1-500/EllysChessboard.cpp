
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

bool b[15][15];
int dp[15][15][15][15];

int mx(int a, int b, int c){
	return max(a, max(b, c));
}

int calc(int x1, int y1, int x2, int y2){
	//printf("%d %d %d %d\n", x1, y1, x2, y2);
	if(dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];
	if(x2 < 0 || y2 < 0) return 0;
	if(x1 > x2 || y1 > y2) return dp[x1][y1][x2][y2] = 0;

	int res = (1<<30);
	int tmp;

	tmp = calc(x1+1, y1, x2, y2);
	for(int i = y1; i <= y2; i++) if(b[x1][i]) tmp += mx(i-y1, y2-i, x2-x1);
	res = min(res, tmp);

	tmp = calc(x1, y1+1, x2, y2);
	for(int i = x1; i <= x2; i++) if(b[i][y1]) tmp += mx(i-x1, x2-i, y2-y1);
	res = min(res, tmp);

	tmp = calc(x1, y1, x2-1, y2);
	for(int i = y1; i <= y2; i++) if(b[x2][i]) tmp += mx(i-y1, y2-i, x2-x1);
	res = min(res, tmp);

	tmp = calc(x1, y1, x2, y2-1);
	for(int i = x1; i <= x2; i++) if(b[i][y2]) tmp += mx(i-x1, x2-i, y2-y1);
	res = min(res, tmp);

	return dp[x1][y1][x2][y2] = res;
}

class EllysChessboard {
public:
   int minCost( vector <string> board ) {
	   REP(i, 15) REP(j, 15) b[i][j] = false;
	   REP(i, SZ(board)) REP(j, SZ(board[0])) if(board[i][j] == '#') b[i+j][i-j+7] = true;
	   REP(i, 15) REP(j, 15) REP(k, 15) REP(l, 15) dp[i][j][k][l] = -1;
	   return calc(0, 0, 14, 14);
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
			string board[]            = {"........",
 "........",
 "...#....",
 ".#......",
 ".......#",
 "........",
 "........",
 "........"};
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = EllysChessboard().minCost(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = EllysChessboard().minCost(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {".#......",
 "........",
 "..#..#.#",
 "...#..#.",
 "........",
 "...#...#",
 "...#...#",
 "........"};
			int expected__            = 58;

			clock_t start__           = clock();
			int received__            = EllysChessboard().minCost(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"##..####",
 "#####..#",
 "..#.#...",
 "#..##.##",
 ".#.###.#",
 "####.###",
 "#.#...#.",
 "##....#."};
			int expected__            = 275;

			clock_t start__           = clock();
			int received__            = EllysChessboard().minCost(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"########",
 "########",
 "########",
 "########",
 "########",
 "########",
 "########",
 "########"};
			int expected__            = 476;

			clock_t start__           = clock();
			int received__            = EllysChessboard().minCost(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysChessboard().minCost(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysChessboard().minCost(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysChessboard().minCost(vector <string>(board, board + (sizeof board / sizeof board[0])));
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
// Elly has a standard chessboard, divided into 8 by 8 unit square cells.
She wants to place pebbles onto some of the cells.
You are given a vector <string> board.
The j-th character of the i-th element of board is '#' if she wants to put a pebble onto the cell (i, j), and it is '.' otherwise.

Initially the chessboard doesn't contain any pebbles.
Elly places the pebbles one by one.
The cost of adding a pebble is defined as follows.
If this is the first pebble to be placed (i.e., the board is empty), it can be placed for free.
Otherwise, the cost is the Manhattan distance (see Notes for the definition) to the most distant pebble that has already been placed on the board.

Return the minimal total cost of placing a pebble onto each chosen cell.

DEFINITION
Class:EllysChessboard
Method:minCost
Parameters:vector <string>
Returns:int
Method signature:int minCost(vector <string> board)


NOTES
-The Manhattan distance between the cell (x1, y1) and the cell (x2, y2) is defined as |x1-x2| + |y1-y2|, where || denotes absolute value.


CONSTRAINTS
-board will contain exactly 8 elements.
-Each element of board will contain exactly 8 characters.
-Each character in board will be either '#' or '.'.


EXAMPLES

0)
{"........",
 "........",
 "...#....",
 ".#......",
 ".......#",
 "........",
 "........",
 "........"}

Returns: 10

Elly wants to put pebbles on three cells: (2, 3), (3, 1), and (4, 7). One of the optimal ways to do this is as follows:

First, put a pebble to (2, 3). It costs nothing.
Next, put a pebble to (3, 1). It costs |2-3| + |3-1| = 3.
Next, put a pebble to (4, 7). The Manhattan distance between (4, 7) and (2, 3) is 6, and the Manhattan distance between (4, 7) and (3, 1) is 7, so the cost is max(6, 7) = 7.

The total cost is 0 + 3 + 7 = 10.

1)
{"........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........"}

Returns: 0



2)
{".#......",
 "........",
 "..#..#.#",
 "...#..#.",
 "........",
 "...#...#",
 "...#...#",
 "........"}

Returns: 58



3)
{"##..####",
 "#####..#",
 "..#.#...",
 "#..##.##",
 ".#.###.#",
 "####.###",
 "#.#...#.",
 "##....#."}

Returns: 275



4)
{"########",
 "########",
 "########",
 "########",
 "########",
 "########",
 "########",
 "########"}

Returns: 476



*/

// END CUT HERE
