
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
#include <numeric>
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
#define MAX(a, b) if(a<(b)) a=(b)

int crt[1<<9], nxt[1<<9];
int h, w;

class TheTilesDivTwo {
public:
   int find( vector <string> board ) {
	int h = SZ(board), w = SZ(board[0]);
	REP(i, (1<<(h*2+1))) crt[i] = 0;
	
	REP(j, w) REP(i, h){
		REP(k, (1<<(h*2+1))) nxt[k] = 0;
		REP(k, (1<<(h*2+1))) {
			//nashi
			MAX(nxt[k>>1], crt[k]);
			if((i+j)&1 || board[i][j] == 'X') continue;
			
			// o
			// oo
			if(i>0 && j<w-1 && board[i-1][j] != 'X' && board[i][j+1] != 'X' && !(k&(1<<(h-1))) && !(k&(1<<(h*2))))
				MAX( nxt[ (k>>1) | (1<<(h-1)) | (1<<(h-2)) | (1<<(h*2-1)) ], crt[k]+1);
			
			// oo
			// o
			if(i<h-1 && j<w-1 && board[i+1][j] != 'X' && board[i][j+1] != 'X' && !(k&(1<<(h+1))) && !(k&(1<<(h*2))))
				MAX( nxt[ (k>>1) | (1<<(h-1)) | (1<<h) | (1<<(h*2-1)) ], crt[k]+1);
			
			// oo
			//  o
			if(i<h-1 && j>0 && board[i+1][j] != 'X' && board[i][j-1] != 'X' && !(k&(1<<(h+1))) && !(k&1))
				MAX( nxt[ (k>>1) | (1<<(h-1)) | (1<<h) ], crt[k]+1);
			
			//  o
			// oo
			if(i>0 && j>0 && board[i-1][j] != 'X' && board[i][j-1] != 'X' && !(k&(1<<(h-1))) && !(k&1))
				MAX( nxt[ (k>>1) | (1<<(h-1)) | (1<<(h-2)) ], crt[k]+1);
		}
		REP(i, (1<<(h*2+1))) crt[i] = nxt[i];
	}
	
	int res = 0;
	REP(i, (1<<(h*2+1))) MAX(res, crt[i]);
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
			string board[]            = {"X.X",
 "...",
 "X.X"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheTilesDivTwo().find(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"...",
 "...",
 "..."};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheTilesDivTwo().find(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"......X.X.XXX.X.XX."};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheTilesDivTwo().find(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"X.....XXX.XX..XXXXXXXXX...X.XX.XX....X",
 ".XXXX..X..XXXXXXXX....XX.X.X.X.....XXX",
 "....XX....X.XX..X.X...XX.X..XXXXXXX..X",
 "XX.XXXXX.X.X..X..XX.XXX..XX...XXX.X..."};
			int expected__            = 13;

			clock_t start__           = clock();
			int received__            = TheTilesDivTwo().find(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheTilesDivTwo().find(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheTilesDivTwo().find(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheTilesDivTwo().find(vector <string>(board, board + (sizeof board / sizeof board[0])));
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
// John and Brus have a rectangular chessboard with black and white tiles.
Rows and columns of the chessboard are numbered starting from 0.
The cell at row i, column j is black if i+j is even and it is white if i+j is odd.


Some of the cells of the chessboard are occupied by chess pieces.
You are given a vector <string> board.
For each i and j, the j-th character of the i-th element (0-based indices) of board is 'X' if the cell in row i, column j of the chessboard contains a chess piece.
Otherwise, the j-th character of the i-th element of board is '.'.


John and Brus also have an infinite supply of L-shaped tiles.
Each tile consists of three squares which are of the same size as the cells of the chessboard.
I.e., each tile looks as follows:

OO
O


John and Brus want to place some of the tiles onto their chessboard, according to the following rules:

Each tile may be rotated by any multiple of 90 degrees.
Each tile must cover exactly three cells of the chessboard.
Tiles are not allowed to overlap.
Tiles are not allowed to cover the cells that are already occupied by the chess pieces.
The corner cell of each tile must cover a black cell of the chessboard.



Return the maximum number of tiles John and Brus can place on the board according to the above rules.


DEFINITION
Class:TheTilesDivTwo
Method:find
Parameters:vector <string>
Returns:int
Method signature:int find(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 4 elements, inclusive.
-Each element of board will contain between 1 and 47 characters, inclusive.
-All elements of board will contain the same number of characters.
-Each element of board will consist of only characters 'X' and '.'.


EXAMPLES

0)
{"X.X",
 "...",
 "X.X"}

Returns: 1

Since only one black cell is available, just one tile can be placed on the board.

1)
{"...",
 "...",
 "..."}

Returns: 2



2)
{"......X.X.XXX.X.XX."}

Returns: 0



3)
{"X.....XXX.XX..XXXXXXXXX...X.XX.XX....X",
 ".XXXX..X..XXXXXXXX....XX.X.X.X.....XXX",
 "....XX....X.XX..X.X...XX.X..XXXXXXX..X",
 "XX.XXXXX.X.X..X..XX.XXX..XX...XXX.X..."}

Returns: 13



*/

// END CUT HERE
