
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


const int MOD = 1000000007;
int dp[52][52];
int h;
VI b, p;

void mul(LL &aa, LL bb){
	aa = (aa * bb) % MOD;
}

void add(LL &aa, LL bb){
	aa = (aa + bb) % MOD;
}

int rec(int num, int before){
	if(dp[num][before] != -1) return dp[num][before];
	if(SZ(b) == num) return dp[num][before] = 1;
	
	LL res = 0;
	if(b[num] == 0){
		for(int i = p[num]; i > before; i--) add(res, rec(num+1, i));
	}
	else{
		for(int i = max(p[num], before+1); i <= h; i++) add(res, rec(num+1, i));
	}
	return dp[num][before] = res;
}


class FoxAndShogi {
public:
   int differentOutcomes( vector <string> board ) {
	h = SZ(board);
	
	LL res = 1;
	REP(i, SZ(board[0])){
		b.clear(); p.clear();
		MSET(dp, -1);
		REP(j, h){
			if(board[j][i] == 'U') b.PB(0), p.PB(j+1);
			if(board[j][i] == 'D') b.PB(1), p.PB(j+1);
		}
		mul(res, rec(0, 0));
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
			string board[]            = {".D.",
 "...",
 "..."}
 ;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = FoxAndShogi().differentOutcomes(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {".D.",
 "...",
 ".U."}
 ;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = FoxAndShogi().differentOutcomes(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"DDDDD",
 ".....",
 ".....",
 ".....",
 "....."}
;
			int expected__            = 3125;

			clock_t start__           = clock();
			int received__            = FoxAndShogi().differentOutcomes(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"DDDDD",
 "U....",
 ".U...",
 "..U..",
 "...U."}
;
			int expected__            = 900;

			clock_t start__           = clock();
			int received__            = FoxAndShogi().differentOutcomes(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"....D..",
 "U....D.",
 "D.D.U.D",
 "U.U...D",
 "....U..",
 "D.U...D",
 "U.U...."}
;
			int expected__            = 2268;

			clock_t start__           = clock();
			int received__            = FoxAndShogi().differentOutcomes(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string board[]            = {"DDDDDDDDDD",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 ".........."}
;
			int expected__            = 999999937;

			clock_t start__           = clock();
			int received__            = FoxAndShogi().differentOutcomes(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string board[]            = {"..",
 ".."};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FoxAndShogi().differentOutcomes(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndShogi().differentOutcomes(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndShogi().differentOutcomes(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndShogi().differentOutcomes(vector <string>(board, board + (sizeof board / sizeof board[0])));
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
// Fox Ciel is going to play Shogi with her friend Jiro.
Before they start, Jiro showed her a puzzle with some pawns on the board.


You are given a vector <string> board that describes Jiro's board.
Character j of element i of board represents the cell (i,j) of the board:
'U' is a cell with a pawn that may move upwards, 'D' a cell with a pawn that may move downwards, and '.' is an empty cell.


Jiro showed Ciel this board and gave her the following question:
You are allowed to make as many valid moves as you wish, including zero.
In each move you may either take a 'U' pawn and move it one cell upwards, or take a 'D' pawn and move it one cell downwards.
Of course, both types of moves are only valid if the destination cell is currently empty.
Pawns are not allowed to move out of bounds.
How many different configurations can you create?


Return the number of different configurations that are reachable from the one described by board, modulo 1,000,000,007.

DEFINITION
Class:FoxAndShogi
Method:differentOutcomes
Parameters:vector <string>
Returns:int
Method signature:int differentOutcomes(vector <string> board)


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-board will contain exactly n elements.
-Each element in board will contain exactly n characters.
-Each character in board will be one of 'U', 'D' or '.'.


EXAMPLES

0)
{".D.",
 "...",
 "..."}
 

Returns: 3

Ciel can move the pawn 0, 1, or 2 steps downwards.

1)
{".D.",
 "...",
 ".U."}
 

Returns: 3

There are three different outcomes: Either we do not move any of the pawns, or we move the top one downwards, or the bottom one upwards.

2)
{"DDDDD",
 ".....",
 ".....",
 ".....",
 "....."}


Returns: 3125

The answer is 5^5. Note that we are only counting each configuration once, even if there are multiple ways of reaching it.

3)
{"DDDDD",
 "U....",
 ".U...",
 "..U..",
 "...U."}


Returns: 900



4)
{"....D..",
 "U....D.",
 "D.D.U.D",
 "U.U...D",
 "....U..",
 "D.U...D",
 "U.U...."}


Returns: 2268



5)
{"DDDDDDDDDD",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 ".........."}


Returns: 999999937

The answer is 10^10 mod 1,000,000,007.


6)
{"..",
 ".."}

Returns: 1



*/

// END CUT HERE
