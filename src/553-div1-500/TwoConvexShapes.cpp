
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

int MOD = 1000000007;
vector <string> g;
int n, m;

void add(int &a, int b){
	a = ((LL)a + b) % MOD;
}
void sub(int &a, int b){
	a = ((LL)a - b + MOD) % MOD;
}

bool chk(int a, int b, char c1, char c2){
	bool ok = true;
	for(int i = 0; i < b; i++) ok &= (g[a][i] != c2);
	for(int i = b; i < m; i++) ok &= (g[a][i] != c1);
	return ok;
}

int inc(char c1, char c2){
	int  dp[55][55]; MSET(dp, 0);
	for(int i = 0; i <= m; i++) if(chk(0, i, c1, c2)) dp[0][i] = 1;
	
	for(int i = 1; i < n; i++) for(int j = 0; j <= m; j++){
		if(!chk(i, j, c1, c2)) continue;
		for(int k = 0; k <= j; k++) add(dp[i][j], dp[i-1][k]);
	}
	
	int res = 0;
	for(int j = 0; j <= m; j++) add(res, dp[n-1][j]);
	return res;
}

int dec(char c1, char c2){
	int  dp[55][55]; MSET(dp, 0);
	for(int i = 0; i <= m; i++) if(chk(0, i, c1, c2)) dp[0][i] = 1;
	
	for(int i = 1; i < n; i++) for(int j = 0; j <= m; j++){
		if(!chk(i, j, c1, c2)) continue;
		for(int k = j; k <= m; k++) add(dp[i][j], dp[i-1][k]);
	}
	
	int res = 0;
	for(int j = 0; j <= m; j++) add(res, dp[n-1][j]);
	return res;
}

class TwoConvexShapes {
public:
   int countWays( vector <string> grid ) {
	g = grid;
	n = SZ(g), m = SZ(g[0]);
	int res = 0;
	
	add(res, inc('B', 'W'));
	add(res, inc('W', 'B'));
	bool B = true; REP(i, n) B &= chk(i, m, 'B', 'W'); if(B) sub(res, 1);
	bool W = true; REP(i, n) W &= chk(i, m, 'W', 'B'); if(W) sub(res, 1);
	
	add(res, dec('B', 'W'));
	add(res, dec('W', 'B'));
	B = true; REP(i, n) B &= chk(i, m, 'B', 'W'); if(B) sub(res, 1);
	W = true; REP(i, n) W &= chk(i, m, 'W', 'B'); if(W) sub(res, 1);
	
	B = true; REP(i, n) B &= chk(i, m, 'B', 'W'); if(B) sub(res, 1);
	W = true; REP(i, n) W &= chk(i, m, 'W', 'B'); if(W) sub(res, 1);
	
	bool dup;
	for(int i = 1; i < n; i++){
		dup = true;
		for(int j = 0; j < i; j++) dup &= chk(j, m, 'B', 'W');
		for(int j = i; j < n; j++) dup &= chk(j, m, 'W', 'B');
		if(dup) sub(res, 1);
		
		dup = true;
		for(int j = 0; j < i; j++) dup &= chk(j, m, 'W', 'B');
		for(int j = i; j < n; j++) dup &= chk(j, m, 'B', 'W');
		if(dup) sub(res, 1);
	}
	
	for(int i = 1; i < m; i++){
		dup = true;
		REP(j, n) dup &= chk(j, i, 'B', 'W');
		if(dup) sub(res, 1);
		
		dup = true;
		REP(j, n) dup &= chk(j, i, 'W', 'B');
		if(dup) sub(res, 1);
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
			string grid[]             = {"??",
 "??"};
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = TwoConvexShapes().countWays(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string grid[]             = {"B?",
 "??"};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = TwoConvexShapes().countWays(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string grid[]             = {"WWB",
 "WWW",
 "WWW",
 "WWW"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TwoConvexShapes().countWays(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string grid[]             = {"BBBBBB",
 "WWBBBB",
 "WBBBBB"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TwoConvexShapes().countWays(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string grid[]             = {"?BB?",
 "BBBB",
 "?BB?"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = TwoConvexShapes().countWays(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string grid[]             = {"?WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "B?WWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BB?WWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBB?WWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBB?WWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBB?WWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBB?WWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBB?WWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBB?WWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBB?WWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBB?WWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBB?WWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBB?WWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBB?WWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBB?WWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBB?WWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBB?WWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBB?WWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBB?WWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBB?WWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBB?WWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBB?WWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBB?WWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBB?WWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBB?WWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBB?WWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBB?WWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBB?WWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBB?WW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBBB?W"};
			int expected__            = 73741817;

			clock_t start__           = clock();
			int received__            = TwoConvexShapes().countWays(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TwoConvexShapes().countWays(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TwoConvexShapes().countWays(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TwoConvexShapes().countWays(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
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
// A platypus has been given the mission to paint the cells on a grid either black or white according to the following two conditions:

For each color, all cells of that color must be connected.
Formally, a pair of cells of color X is connected if there is a path of adjacent cells of color X between them.
(Two cells are adjacent if they share a common edge.)
We require that for each color, each pair of cells of that color must be connected.
All the cells of each color must form a convex shape. 
A group of cells of a given color is convex if in each row and each column the cells of that color form a connected segment (possibly taking the whole row or column).
In other words, whenever two cells of the same color share the same row or the same column, all cells between them must also have that particular color.

The platypus is also allowed to paint the grid completely white or black.

The platypus may have already painted some of the cells. The current state of the grid is given as a vector <string> grid. The i-th character of the j-th element of grid that represents the cell at row j, column i is 'W' if it has been painted white, 'B' if it has been painted black, and '?' if it does not have a color yet. Let X be the number of different ways how to color the rest of the grid according to the above conditions. Return the value X modulo 1000000007 (10^9 + 7). Two ways to color a grid are different if the color of at least one cell differs.



DEFINITION
Class:TwoConvexShapes
Method:countWays
Parameters:vector <string>
Returns:int
Method signature:int countWays(vector <string> grid)


CONSTRAINTS
-grid will contain between 1 and 50 elements, inclusive.
-Element 0 of grid will contain between 1 and 50 characters, inclusive.
-The remaining elements of grid will contain the same number of characters as element 0.
-Each character in each element of grid will be one of 'B', 'W', and '?' (quotes for clarity).


EXAMPLES

0)
{"??",
 "??"}

Returns: 14

Of all the 16 different ways to color the grid, only the following 2 are not valid.

BW WB
WB BW

This is because cells of the same color are not connected.

1)
{"B?",
 "??"}

Returns: 7

The following seven ways to color the grid are correct:

BB BW BB BW BB BB BW
BB BW WW WW WB BW BB


2)
{"WWB",
 "WWW",
 "WWW",
 "WWW"}

Returns: 1

All colors have already been picked. The only possible coloring is already valid.

3)
{"BBBBBB",
 "WWBBBB",
 "WBBBBB"}

Returns: 0

This coloring of the grid is not valid, the black cells do not form a convex shape.

4)
{"?BB?",
 "BBBB",
 "?BB?"}

Returns: 5



5)
{"?WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "B?WWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BB?WWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBB?WWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBB?WWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBB?WWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBB?WWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBB?WWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBB?WWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBB?WWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBB?WWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBB?WWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBB?WWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBB?WWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBB?WWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBB?WWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBB?WWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBB?WWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBB?WWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBB?WWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBB?WWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBB?WWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBB?WWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBB?WWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBB?WWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBB?WWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBB?WWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBB?WWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBB?WW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBBB?W"}

Returns: 73741817

Each of the 2^30 ways to color the remaining cells in the grid is valid.

*/

// END CUT HERE
