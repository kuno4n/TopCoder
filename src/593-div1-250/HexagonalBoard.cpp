
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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 


int dx[6] = {-1, -1, 0, 1, 1, 0};
int dy[6] = {0, 1, 1, 0, -1, -1};
int col[55][55];
int res;
int n;
vector <string> b;

void dfs(int x, int y, int c){
	chmax(res, c+1);
	col[x][y] = c;
	
	REP(k, 6){
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if(b[nx][ny] == 'X'){
			if(col[nx][ny] < 0) dfs(nx, ny, c^1);
			else if(col[nx][ny] == c) res = 3;
		}
	}
}

class HexagonalBoard {
public:
   int minColors( vector <string> board ) {
	b = board;
	n = SZ(board);
	MSET(col, -1);
	res = 0;
	REP(i, n) REP(j, n) if(board[i][j] == 'X' && col[i][j] < 0) dfs(i, j, 0);
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
			string board[]            = {"---",
 "---",
 "---"}
 ;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = HexagonalBoard().minColors(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"-X--",
 "---X",
 "----",
 "-X--"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = HexagonalBoard().minColors(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"XXXX",
 "---X",
 "---X",
 "---X"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = HexagonalBoard().minColors(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"XX-XX--"
,"-XX-XXX"
,"X-XX--X"
,"X--X-X-"
,"XX-X-XX"
,"-X-XX-X"
,"-XX-XX-"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = HexagonalBoard().minColors(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HexagonalBoard().minColors(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HexagonalBoard().minColors(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HexagonalBoard().minColors(vector <string>(board, board + (sizeof board / sizeof board[0])));
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
// The pony Applejack has an N by N hexagonal board. The following picture shows the hexagonal board when N = 1, 2, 3, and 4.





She wants to color some cells of the board. You are given a vector <string> board. If the j-th character of the i-th element of board is 'X', she wants to color the cell (i, j). If she colors two cells that share an edge, she must use different colors for those cells. Return the minimal number of colors she needs.

DEFINITION
Class:HexagonalBoard
Method:minColors
Parameters:vector <string>
Returns:int
Method signature:int minColors(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain exactly N characters, where N is the number of elements in board.
-Each character in board will be either 'X' or '-'.


EXAMPLES

0)
{"---",
 "---",
 "---"}
 

Returns: 0

She won't color any cells, so she won't need any colors.

1)
{"-X--",
 "---X",
 "----",
 "-X--"}

Returns: 1

She can color all cells with the same color.

2)
{"XXXX",
 "---X",
 "---X",
 "---X"}

Returns: 2

For example, she can color cells in the following way:

Color cells (0, 0), (0, 2), (1, 3), and (3, 3) red.
Color cells (0, 1), (0, 3), and (2, 3) blue.



3)
{"XX-XX--"
,"-XX-XXX"
,"X-XX--X"
,"X--X-X-"
,"XX-X-XX"
,"-X-XX-X"
,"-XX-XX-"}

Returns: 3



*/

// END CUT HERE
