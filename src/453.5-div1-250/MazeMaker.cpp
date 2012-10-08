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
#define MP make_pair


int ref = 1000;

class MazeMaker {
	public:
	int longestPath(vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol) {
        
        int width = SZ(maze[0]);
        int height = SZ(maze);
        int m = SZ(moveRow);
        int board[100][100];
//        REP(i, 100) REP(j, 100) board[i][j] = -1;
        MSET(board, -1);
        
        queue<int> qx;
        queue<int> qy;
        qx.push(startCol);
        qy.push(startRow);
        board[startRow][startCol] = 0;
        
        while(!qx.empty()){
            int x = qx.front();
            int y = qy.front();
            qx.pop();
            qy.pop();
            
            REP(i, m){
                int dx = moveCol[i];
                int dy = moveRow[i];
                
                if(x+dx >= 0 && x+dx < width && y+dy >= 0 && y+dy < height &&
                   board[y+dy][x+dx] == -1 && maze[y+dy][x+dx] == '.'){
                    qx.push(x+dx);
                    qy.push(y+dy);
                    board[y+dy][x+dx] = board[y][x] + 1;
                }
            }
        }
        
        int res = -1;
        REP(goalx, width){
            REP(goaly, height){
                if(board[goaly][goalx] == -1 && maze[goaly][goalx] == '.') return -1;
                res = max(res, board[goaly][goalx]);
            }
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
			string maze[]             = {"...",
 "...",
 "..."};
			int startRow              = 0;
			int startCol              = 1;
			int moveRow[]             = {1,0,-1,0};
			int moveCol[]             = {0,1,0,-1};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string maze[]             = {"...",
 "...",
 "..."};
			int startRow              = 0;
			int startCol              = 1;
			int moveRow[]             = {1, 0, -1, 0, 1, 1, -1, -1};
			int moveCol[]             = {0, 1, 0, -1, 1, -1, 1, -1};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string maze[]             = {"X.X",
 "...",
 "XXX",
 "X.X"};
			int startRow              = 0;
			int startCol              = 1;
			int moveRow[]             = {1, 0, -1, 0};
			int moveCol[]             = {0, 1, 0, -1};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string maze[]             = {".......",
 "X.X.X..",
 "XXX...X",
 "....X..",
 "X....X.",
 "......."};
			int startRow              = 5;
			int startCol              = 0;
			int moveRow[]             = {1, 0, -1, 0,-2, 1};
			int moveCol[]             = {0, -1, 0, 1, 3, 0};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string maze[]             = {"......."};
			int startRow              = 0;
			int startCol              = 0;
			int moveRow[]             = {1, 0, 1, 0, 1, 0};
			int moveCol[]             = {0, 1, 0, 1, 0, 1};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string maze[]             = {"..X.X.X.X.X.X."};
			int startRow              = 0;
			int startCol              = 0;
			int moveRow[]             = {2,0,-2,0};
			int moveCol[]             = {0,2,0,-2};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string maze[]             = ;
			int startRow              = ;
			int startCol              = ;
			int moveRow[]             = ;
			int moveCol[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string maze[]             = ;
			int startRow              = ;
			int startCol              = ;
			int moveRow[]             = ;
			int moveCol[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string maze[]             = ;
			int startRow              = ;
			int startCol              = ;
			int moveRow[]             = ;
			int moveCol[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MazeMaker().longestPath(vector <string>(maze, maze + (sizeof maze / sizeof maze[0])), startRow, startCol, vector <int>(moveRow, moveRow + (sizeof moveRow / sizeof moveRow[0])), vector <int>(moveCol, moveCol + (sizeof moveCol / sizeof moveCol[0])));
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
Mike Mazemeister has recently built a large maze in his backyard.  The j-th character of the i-th element of maze is 'X' if the square is an impassable bush; otherwise, it is a '.'.  Mike wants his friend, Jumping Jim, to solve the maze.  Jim will start in row startRow in column startCol.

Unlike typical maze solvers, Jim has the ability to jump through the maze, rather than simply walking.  Jim's possible moves are described in moveRow and moveCol.  The i-th element corresponds to a move Jim can make in which his current row is changed by moveRow[i], and his current column is changed by moveCol[i].  For example, if moveRow = {1, 0, -1} and moveCol = {3, -2, 5}, Jim's legal moves are (1,3), (0, -2), and (-1, 5).  However, Jim cannot move outside the boundary of the maze, and he cannot land on an impassable bush.

Mike wants to make the maze impossible for Jim to exit, and can place the exit in any cell containing a '.' in the maze.  If this turns out to be impossible, then Mike wants to make Jim's trip take as long as possible.  Jim is smart, and he will always exit the maze in the minimum number of jumps that he can.  Return the maximum number of jumps that Jim will make to exit the maze; if it is impossible for him to exit the maze, return -1 instead.


DEFINITION
Class:MazeMaker
Method:longestPath
Parameters:vector <string>, int, int, vector <int>, vector <int>
Returns:int
Method signature:int longestPath(vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol)


CONSTRAINTS
-maze will contain between 1 and 50 elements, inclusive.
-Each element of maze will contain between 1 and 50 characters, inclusive.
-Each element of maze will contain the same number of characters.
-Each character of maze will be either 'X' or '.'.
-maze will contain at least 2 '.' characters.
-startRow will be between 0 and N-1, inclusive, where N is the number of elements in maze.
-startCol will be between 0 and M-1, inclusive, where M is the number of characters in each element of maze.
-maze[startRow][startCol] will be '.'.
-moveRow will contain between 1 and 50 elements, inclusive.
-moveCol will contain the same number of elements as moveRow.
-Each element of moveRow and moveCol will be between -50 and 50, inclusive.


EXAMPLES

0)
{"...",
 "...",
 "..."}
0
1
{1,0,-1,0}
{0,1,0,-1}

Returns: 3

Here Jim can move up, down, left and right.  Mike will set the exit in one of the bottom corners, which take Jim 3 steps to reach.

1)
{"...",
 "...",
 "..."}
0
1
{1, 0, -1, 0, 1, 1, -1, -1}
{0, 1, 0, -1, 1, -1, 1, -1}

Returns: 2

This is the same problem, but now Jim can move diagonally.  With this, he can reach any section in at most two steps.

2)
{"X.X",
 "...",
 "XXX",
 "X.X"}
0
1
{1, 0, -1, 0}
{0, 1, 0, -1}

Returns: -1

Here Mike can place the exit in the empty section of the bottom row; Jim can never reach it.

3)
{".......",
 "X.X.X..",
 "XXX...X",
 "....X..",
 "X....X.",
 "......."}
5
0
{1, 0, -1, 0,-2, 1}
{0, -1, 0, 1, 3, 0}

Returns: 7



4)
{"......."}
0
0
{1, 0, 1, 0, 1, 0}
{0, 1, 0, 1, 0, 1}

Returns: 6



5)
{"..X.X.X.X.X.X."}
0
0
{2,0,-2,0}
{0,2,0,-2}

Returns: -1

Since Jim can only jump (and can't move to the side), Mike can place the exit anywhere except the start to prevent Jim from winning.

*/

// END CUT HERE
