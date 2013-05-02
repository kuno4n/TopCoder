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

int dx[8] = {-2, -2, -1, -1, 1, 1, 2 ,2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1 ,1};
int acc[8][8];

class KnightsTour {
	public:
	int visitedPositions(vector <string> b) {
        
        int res = 1;
        int x=-1, y=-1;
        REP(i, 8) REP(j, 8) if(b[i][j] == 'K'){
            x = i;
            y = j;
            b[i][j] = '*';
        }
        
        while(1){
            REP(i, 8) REP(j, 8) acc[i][j] = 0;
            REP(i, 8) REP(j, 8) REP(k, 8){
                int ax = i + dx[k];
                int ay = j + dy[k];
                if(ax >= 0 && ax < 8 && ay >= 0 && ay < 8 && b[ax][ay] == '.') acc[i][j]++;
            }
            if(acc[x][y] == 0) break;
            res++;
            int nxt = 8;
            int tmp = 9;
            REP(i, 8){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || b[nx][ny] == '*') continue;
                if(tmp > acc[nx][ny]){
                    tmp = acc[nx][ny];
                    nxt = i;
                }
            }
            x = x + dx[nxt];
            y = y + dy[nxt];
            b[x][y] = '*';
            
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
			string board[]            = {"........"
,".*.*...."
,".*......"
,"..K...*."
,"*...*..."
,"...*...."
,"...*.*.."
,"........"};
			int expected__            = 39;

			clock_t start__           = clock();
			int received__            = KnightsTour().visitedPositions(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"K......."
,"........"
,"........"
,"........"
,"........"
,"........"
,"........"
,"........"};
			int expected__            = 64;

			clock_t start__           = clock();
			int received__            = KnightsTour().visitedPositions(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"********"
,"*******."
,"********"
,"**.***.*"
,"********"
,"***.*.**"
,"********"
,"****K***"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = KnightsTour().visitedPositions(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"*.*....*"
,".......*"
,"**...*.."
,"..***..."
,".**.*..."
,"..*.*..K"
,"..***.*."
,"**...*.."};
			int expected__            = 17;

			clock_t start__           = clock();
			int received__            = KnightsTour().visitedPositions(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"..*...*."
,"**.....*"
,"*..*...."
,"*..*...."
,".....*.."
,"....*..K"
,"**.*...*"
,"..**...."};
			int expected__            = 27;

			clock_t start__           = clock();
			int received__            = KnightsTour().visitedPositions(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KnightsTour().visitedPositions(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KnightsTour().visitedPositions(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KnightsTour().visitedPositions(vector <string>(board, board + (sizeof board / sizeof board[0])));
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
// Facebook engineers love playing chess. They also like to play other games on the chessboard. Today, they were wondering how many cells a knight would visit on the chessboard if it followed some predefined algorithm.

You are given a vector <string> board describing a standard 8x8 chessboard, where the c-th character of the r-th element corresponds to the cell in row r, column c.  Some cells are blocked and cannot be jumped into. These will be represented with a '*'. All other cells are marked with a '.', except for the starting position of the knight, which is marked with a 'K'.

A valid jump for a knight consists of shifting one square along one axis and two squares along the other axis.  A cell is "accessible" if it is not blocked and it has not been visited by the knight before.  The starting position of the knight is considered to be visited, and each time the knight jumps into a new cell, that cell becomes visited.  The accessibility number of a cell is the number of accessible cells that the knight can make a valid jump to from that cell.  Note that accessibility numbers of cells may change as the knight moves through the board and visits more cells.

The knight will use the following simple algorithm to traverse the board.  On each move, it will make a valid jump into the accessible cell with the lowest accessibility number.  In case of a tie, it will choose the one with the lowest row number, and if there is still a tie, it will choose the one among them with the lowest column number.  The knight will stop moving when it can no longer make a valid jump into an accessible cell.

Return the number of cells that the knight will visit (including the starting cell).

DEFINITION
Class:KnightsTour
Method:visitedPositions
Parameters:vector <string>
Returns:int
Method signature:int visitedPositions(vector <string> board)


CONSTRAINTS
-board will contain exactly 8 elements.
-Each element of board will contain exactly 8 characters '.', 'K' or '*'.
-Character 'K' will appear exactly once in board.


EXAMPLES

0)
{"........"
,".*.*...."
,".*......"
,"..K...*."
,"*...*..."
,"...*...."
,"...*.*.."
,"........"}

Returns: 39

From its starting cell K, the knight can jump to cells A, B and C, which have accessibility numbers of 3, 6 and 4, respectively (see first image below).  It will jump to cell A because it has the lowest accessibility number.

From cell A, it can then jump to cells D, E and F, which have accessibility numbers of 1, 5 and 4, respectively (see second image).  It will choose cell D.  It will continue in this fashion and visit a total of 39 cells.

??


1)
{"K......."
,"........"
,"........"
,"........"
,"........"
,"........"
,"........"
,"........"}

Returns: 64

If no cells are blocked, then the knight will end up visiting every cell by following the given algorithm.

2)
{"********"
,"*******."
,"********"
,"**.***.*"
,"********"
,"***.*.**"
,"********"
,"****K***"}

Returns: 3

From its starting cell K, the knight can jump to cells A and B, which have accessibility numbers of 1 (see the image). Both A and B have the same accessibility number and the same row number, so it will jump to A because it has the lowest column number. It will then jump to C and stop, visiting a total of 3 cells.

??


3)
{"*.*....*"
,".......*"
,"**...*.."
,"..***..."
,".**.*..."
,"..*.*..K"
,"..***.*."
,"**...*.."}

Returns: 17



4)
{"..*...*."
,"**.....*"
,"*..*...."
,"*..*...."
,".....*.."
,"....*..K"
,"**.*...*"
,"..**...."}

Returns: 27



*/

// END CUT HERE
