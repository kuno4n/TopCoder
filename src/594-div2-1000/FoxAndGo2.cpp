
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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector <string> b;
int n;

vector < vector <PII > > w;
vector < vector <PII > > bb[200];
bool deleted[200];


bool used[20][20];
vector < PII > dfs(int x, int y, vector<string> &vs){
	used[x][y] = true;
	vector < PII > res;
	res.push_back(make_pair(x, y));
	REP(i, 4){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || nx >= n || ny < 0 || ny >= n || vs[nx][ny] != 'o' || used[nx][ny]) continue;
		vector< PII > tmp = dfs(nx, ny, vs);
		REP(j, SZ(tmp)) res.push_back(tmp[j]);
	}
	return res;
} 

bool isD(vector < PII > vp){
	bool res = true;
	vector <string> bb = b;
	REP(i, SZ(vp)){
		int x = vp[i].first;
		int y = vp[i].second;
		bb[x][y] = 'o';
	}
	REP(i, SZ(vp)){
		int x = vp[i].first;
		int y = vp[i].second;
		REP(j, 4){
			int nx = x + dx[j];
			int ny = y + dy[j];
			if(nx < 0 || nx >= n || ny < 0 || ny >= n || bb[nx][ny] == 'o') continue;
			res = false;
		}
	}
	
	return res;
}

bool candel(int a){
	int cnt = 0;
	REP(i, SZ(bb[a])) cnt += isD(bb[a][i]);
	return cnt <= 1;
}


class FoxAndGo2 {
public:
   int maxKill( vector <string> board ) {
	b = board; n = SZ(b);
	MSET(used, false);
	w.clear();
	REP(i, n) REP(j, n) if(b[i][j] == 'o' && !used[i][j]) w.push_back(dfs(i, j, b));
	
	REP(i, 200) bb[i].clear();
	REP(i, SZ(w)){
		string tmp(n, '.');
		vector <string> vs(n, tmp);
		REP(j, SZ(w[i])){
			int x = w[i][j].first, y = w[i][j].second;
			REP(k, 4){
				int nx = x + dx[k];
				int ny = y + dy[k];
				if(nx < 0 || nx >= n || ny < 0 || ny >= n || b[nx][ny] == 'o') continue;
				vs[nx][ny] = 'o';
			}
		}
		MSET(used, false);
		REP(ii, n) REP(jj, n) if(vs[ii][jj] == 'o' && !used[ii][jj]) bb[i].push_back(dfs(ii, jj, vs));
	}
	
	
	MSET(deleted, false);
	int res = 0;
	REP(_, 200) REP(i, SZ(w)) if(!deleted[i] && candel(i)){
		deleted[i] = true;
		res += SZ(w[i]);
		REP(j, SZ(w[i])){
			int x = w[i][j].first, y = w[i][j].second;
			b[x][y] = '.';
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
			string board[]            = {"...",
 ".o.",
 "..."};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FoxAndGo2().maxKill(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"o.",
 "oo"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = FoxAndGo2().maxKill(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {".o.o.",
 "o.o.o",
 ".o.o.",
 "o.o.o",
 ".o.o."};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FoxAndGo2().maxKill(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {".o.o.",
 "o.o.o",
 ".o.o.",
 "o.o.o",
 "....."};
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = FoxAndGo2().maxKill(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {".o.o.o.o.o.",
 "o.ooo.ooo.o",
 ".o.......o.",
 "oo.......oo",
 ".o...o...o.",
 "o...o.o...o",
 ".o...o...o.",
 "oo.......oo",
 ".o.......o.",
 "o.ooo.ooo.o",
 ".o.o.o.o.o."};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = FoxAndGo2().maxKill(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string board[]            = {"...ooo.....",
 "...o.o.....",
 ".ooo.ooo...",
 ".o.....o...",
 ".ooo.ooo...",
 "...o.o.....",
 "...ooo.....",
 "....o......",
 "....o...ooo",
 "....ooooo.o",
 "........ooo"}
;
			int expected__            = 38;

			clock_t start__           = clock();
			int received__            = FoxAndGo2().maxKill(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string board[]            = {"ooooooooooo",
 "o.........o",
 "o...ooo...o",
 "o...o.o...o",
 "o...ooo...o",
 "o....o....o",
 "o....oooooo",
 "o..........",
 "o.......ooo",
 "o.......o.o",
 "ooooooooooo"}
;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FoxAndGo2().maxKill(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			string board[]            = {"oo.o.ooo.o..o..",
 "...ooo.o..oo.oo",
 "o..o.o.ooo.o..o",
 "oo.......oo.ooo",
 "..oo.o.o.o.ooo.",
 "..oo..oo..o.ooo",
 "oo.o.oo..o.oooo",
 ".oo.o..ooo.o.oo",
 "o..o.o.o.o.oo..",
 ".oo.oo...o....o",
 "o.o.oo....oo..o",
 ".o.o..o.oo..ooo",
 "o.o.o..o..o....",
 "ooo.oooooooo..o",
 "o..oo.o..o.ooo."}
;
			int expected__            = 60;

			clock_t start__           = clock();
			int received__            = FoxAndGo2().maxKill(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 8: {
			string board[]            = {"oo.",
 "oo.",
 ".o."};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FoxAndGo2().maxKill(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 9: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndGo2().maxKill(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndGo2().maxKill(vector <string>(board, board + (sizeof board / sizeof board[0])));
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
// Fox Ciel is teaching her friend Jiro to play Go.
Ciel has just placed some white tokens onto a board.
She now wants Jiro to find the best possible sequence of moves.
(This is defined more precisely below.)


You are given a vector <string> board.
Character j of element i of board represents the cell (i,j) of the board:
'o' is a cell with a white token and '.' is an empty cell.
At least one cell on the board will be empty. Note that there are currently no black tokens on the board.


Each Jiro's move consists of adding a single black token to the board.
The token must be placed onto an empty cell.
Once Jiro places the token, some white tokens will be removed from the board according to the rules described in the next paragraphs.


The tokens on the board can be divided into connected components using the following rules:
If two tokens of the same color lie in cells that share an edge, they belong to the same component.
Being in the same component is transitive: if X lies in the same component as Y and Y lies in the same component as Z, then X lies in the same component as Z.


Note that each component of tokens is either completely white or completely black. Each component of tokens is processed separately.
For each component we check whether it is adjacent to an empty cell.
(That is, whether there are two cells that share an edge such that one of them is empty and the other contains a token from the component we are processing.)
If there is such an empty cell, the component is safe and its tokens remain on the board.
If there is no such empty cell, the component is killed and all its tokens are removed from the board.
There are also the following additional rules:

All white components must be processed before black ones (in any order).
If at least one white token was removed, then black components must not be processed at all.
Otherwise, all black components must be processed (in any order).
If at least one black token was removed, this is called a "suicide move". Such moves are invalid and Jiro is not allowed to make them.



Jiro's score is the total number of white tokens removed from the board after each of his moves is evaluated.
Return the maximal score he can get for the given board.


DEFINITION
Class:FoxAndGo2
Method:maxKill
Parameters:vector <string>
Returns:int
Method signature:int maxKill(vector <string> board)


CONSTRAINTS
-n will be between 2 and 19, inclusive.
-board will contain exactly n elements.
-Each element in board will contain exactly n characters.
-Each character in board will be 'o' or '.'.
-There will be at least 1 '.' in board.


EXAMPLES

0)
{"...",
 ".o.",
 "..."}

Returns: 1


.A.
BoC
.D.

Jiro can put black pieces at A,B,C,D (in any order).


1)
{"o.",
 "oo"}

Returns: 3

Jiro needs to place the black token into the empty cell. After that, the white component becomes unsafe and will be killed. The black component won't be processed, so the black token will remain on board.

2)
{".o.o.",
 "o.o.o",
 ".o.o.",
 "o.o.o",
 ".o.o."}

Returns: 0

Regardless of which empty cell he chooses, he will never kill any white component with this single black token.
On the other hand, his black token would always be killed.
Therefore, Jiro has no valid move on this board.

3)
{".o.o.",
 "o.o.o",
 ".o.o.",
 "o.o.o",
 "....."}

Returns: 10



4)
{".o.o.o.o.o.",
 "o.ooo.ooo.o",
 ".o.......o.",
 "oo.......oo",
 ".o...o...o.",
 "o...o.o...o",
 ".o...o...o.",
 "oo.......oo",
 ".o.......o.",
 "o.ooo.ooo.o",
 ".o.o.o.o.o."}

Returns: 4



5)
{"...ooo.....",
 "...o.o.....",
 ".ooo.ooo...",
 ".o.....o...",
 ".ooo.ooo...",
 "...o.o.....",
 "...ooo.....",
 "....o......",
 "....o...ooo",
 "....ooooo.o",
 "........ooo"}


Returns: 38



6)
{"ooooooooooo",
 "o.........o",
 "o...ooo...o",
 "o...o.o...o",
 "o...ooo...o",
 "o....o....o",
 "o....oooooo",
 "o..........",
 "o.......ooo",
 "o.......o.o",
 "ooooooooooo"}


Returns: 0

Sometimes, making no moves at all is an optimal strategy.


7)
{"oo.o.ooo.o..o..",
 "...ooo.o..oo.oo",
 "o..o.o.ooo.o..o",
 "oo.......oo.ooo",
 "..oo.o.o.o.ooo.",
 "..oo..oo..o.ooo",
 "oo.o.oo..o.oooo",
 ".oo.o..ooo.o.oo",
 "o..o.o.o.o.oo..",
 ".oo.oo...o....o",
 "o.o.oo....oo..o",
 ".o.o..o.oo..ooo",
 "o.o.o..o..o....",
 "ooo.oooooooo..o",
 "o..oo.o..o.ooo."}


Returns: 60



*/

// END CUT HERE
