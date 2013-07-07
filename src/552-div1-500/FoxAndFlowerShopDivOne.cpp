
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

int P[32][32][32][32];
int L[32][32][32][32];
int INF = (1<<29);

int cal(vector<string> f, int md){
	MSET(P, 0); MSET(L, 0);
	int h = SZ(f), w = SZ(f[0]);
	REP(x1, h)
		REP(y1, w)
			for(int x2 = x1+1; x2 <= h; x2++)
				for(int y2 = y1+1; y2 <= w; y2++){
					P[x1][y1][x2][y2] = P[x1][y1][x2-1][y2] + P[x1][y1][x2][y2-1] - P[x1][y1][x2-1][y2-1] + (f[x2-1][y2-1] == 'P');
					L[x1][y1][x2][y2] = L[x1][y1][x2-1][y2] + L[x1][y1][x2][y2-1] - L[x1][y1][x2-1][y2-1] + (f[x2-1][y2-1] == 'L');
	}
	
	int res = -1;
	
	for(int r = 1; r <= h-1; r++){
		int up[2000], lo[2000];
		REP(i, 2000) up[i] = -INF, lo[i] = -INF;
		
		REP(x1, r)
			REP(y1, w)
				for(int x2 = x1+1; x2 <= r; x2++)
					for(int y2 = y1+1; y2 <= w; y2++){
						int diff = P[x1][y1][x2][y2] - L[x1][y1][x2][y2];
						chmax(up[diff+1000], P[x1][y1][x2][y2] + L[x1][y1][x2][y2]);
		}
		for(int x1 = r; x1 < h; x1++)
			REP(y1, w)
				for(int x2 = x1+1; x2 <= h; x2++)
					for(int y2 = y1+1; y2 <= w; y2++){
						int diff = P[x1][y1][x2][y2] - L[x1][y1][x2][y2];
						chmax(lo[diff+1000], P[x1][y1][x2][y2] + L[x1][y1][x2][y2]);
		}
		
		REP(i, 2000) REP(j, 2000) if(abs(i+j-2000) <= md) chmax(res, up[i]+lo[j]);
	}
	return res;
}


class FoxAndFlowerShopDivOne {
public:
   int theMaxFlowers( vector <string> f1, int md ) {
		int h = SZ(f1), w = SZ(f1[0]);
		vector <string> f2;
		REP(i, w){
			string s(h, ' ');
			REP(j, h) s[j] = f1[j][i];
			f2.push_back(s);
		}
		
		return max(cal(f1, md), cal(f2, md));
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
			string flowers[]          = {"LLL",
 "PPP",
 "LLL"};
			int maxDiff               = 1;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = FoxAndFlowerShopDivOne().theMaxFlowers(vector <string>(flowers, flowers + (sizeof flowers / sizeof flowers[0])), maxDiff);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string flowers[]          = {"LLL",
 "PPP",
 "LLL"};
			int maxDiff               = 0;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = FoxAndFlowerShopDivOne().theMaxFlowers(vector <string>(flowers, flowers + (sizeof flowers / sizeof flowers[0])), maxDiff);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string flowers[]          = {"...",
 "...",
 "..."};
			int maxDiff               = 3;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FoxAndFlowerShopDivOne().theMaxFlowers(vector <string>(flowers, flowers + (sizeof flowers / sizeof flowers[0])), maxDiff);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string flowers[]          = {"LLPL.LPP",
 "PLPPPPLL",
 "L.P.PLLL",
 "LPL.PP.L",
 ".LLL.P.L",
 "PPLP..PL"};
			int maxDiff               = 2;
			int expected__            = 38;

			clock_t start__           = clock();
			int received__            = FoxAndFlowerShopDivOne().theMaxFlowers(vector <string>(flowers, flowers + (sizeof flowers / sizeof flowers[0])), maxDiff);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string flowers[]          = {"LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL"};
			int maxDiff               = 0;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = FoxAndFlowerShopDivOne().theMaxFlowers(vector <string>(flowers, flowers + (sizeof flowers / sizeof flowers[0])), maxDiff);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string flowers[]          = {"LLLP..LLP.PLL.LL..LP",
 "L.PL.L.LLLL.LPLLPLP.",
 "PLL.LL.LLL..PL...L..",
 ".LPPP.PPPLLLLPLP..PP",
 "LP.P.PPL.L...P.L.LLL",
 "L..LPLPP.PP...PPPL..",
 "PP.PLLL.LL...LP..LP.",
 "PL...P.PPPL..PLP.L..",
 "P.PPPLPLP.LL.L.LLLPL",
 "PLLPLLP.LLL.P..P.LPL",
 "..LLLPLPPPLP.P.LP.LL",
 "..LP..L..LLPPP.LL.LP",
 "LPLL.PLLPPLP...LL..P",
 "LL.....PLL.PLL.P....",
 "LLL...LPPPPL.PL...PP",
 ".PLPLLLLP.LPP...L...",
 "LL...L.LL.LLLPLPPPP.",
 "PLPLLLL..LP.LLPLLLL.",
 "PP.PLL..L..LLLPPL..P",
 ".LLPL.P.PP.P.L.PLPLL"};
			int maxDiff               = 9;
			int expected__            = 208;

			clock_t start__           = clock();
			int received__            = FoxAndFlowerShopDivOne().theMaxFlowers(vector <string>(flowers, flowers + (sizeof flowers / sizeof flowers[0])), maxDiff);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string flowers[]          = ;
			int maxDiff               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndFlowerShopDivOne().theMaxFlowers(vector <string>(flowers, flowers + (sizeof flowers / sizeof flowers[0])), maxDiff);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string flowers[]          = ;
			int maxDiff               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndFlowerShopDivOne().theMaxFlowers(vector <string>(flowers, flowers + (sizeof flowers / sizeof flowers[0])), maxDiff);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string flowers[]          = ;
			int maxDiff               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndFlowerShopDivOne().theMaxFlowers(vector <string>(flowers, flowers + (sizeof flowers / sizeof flowers[0])), maxDiff);
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
// Fox Jiro came to a flower shop to buy flowers.
The flowers in the shop are arranged in some cells of a rectangular grid.
The layout of the grid is given as a vector <string> flowers.
There are two types of flowers in the shop: lilies and petunias.
If the j-th cell of the i-th row of the grid contains a flower, then the j-th character of the i-th element of flowers will be 'L' if it is a lily, and 'P' if it is a petunia.
(All indices in the previous sentence are 0-based.)
If the particular cell is empty, the corresponding character will be '.' (a period).

In order to buy flowers, Jiro has to draw two disjoint rectangles on this grid and buy all the flowers which lie inside the rectangles.
Of course, the sides of the rectangles must be on cell boundaries.
(Therefore, the sides of the rectangles will necessarily be parallel to the coordinate axes.)
The rectangles are allowed to touch, but they may not intersect.
In other words, the rectangles may share a common boundary, but no cell may belong to both rectangles.
Each of the two rectangles must contain at least one cell.

Jiro wants to buy approximately the same number of lilies and petunias.
More precisely, the positive difference between the number of lilies and petunias must be at most maxDiff, inclusive.
Given that constraint, Jiro wants to buy as many flowers as possible.

You are given the vector <string> flowers and the int maxDiff.
Return the maximum possible number of flowers Jiro can buy in this situation.
If there is no valid way to buy flowers, return -1 instead.

DEFINITION
Class:FoxAndFlowerShopDivOne
Method:theMaxFlowers
Parameters:vector <string>, int
Returns:int
Method signature:int theMaxFlowers(vector <string> flowers, int maxDiff)


CONSTRAINTS
-flowers will contain between 2 and 30 elements, inclusive.
-Each element of flowers will contain the same number of characters.
-Each element of flowers will contain between 1 and 30 characters, inclusive.
-Each character in flowers will be either 'L', 'P', or '.'.
-maxDiff will be between 0 and 900, inclusive.


EXAMPLES

0)
{"LLL",
 "PPP",
 "LLL"}
1

Returns: 7

Jiro cannot buy all the flowers, because the difference between the number of lilies and the number of petunias would be too large.
The best he can do is to buy 7 flowers: 4 lilies and 3 petunias.
One way of doing so is to draw two rectangles: (0,0)-(1,2) and (2,0)-(2,0).
Note that (r1,c1)-(r2,c2) denotes a rectangle with cell (r1,c1) in the top left corner and cell (r2,c2) in the bottom right corner.
(All indices are 0-based.)

1)
{"LLL",
 "PPP",
 "LLL"}
0

Returns: 6

This time Jiro is required to buy the same number of lilies and petunias.
Therefore the best he can do is to buy three of each kind.

2)
{"...",
 "...",
 "..."}
3

Returns: 0

There are no flowers.

3)
{"LLPL.LPP",
 "PLPPPPLL",
 "L.P.PLLL",
 "LPL.PP.L",
 ".LLL.P.L",
 "PPLP..PL"}
2

Returns: 38



4)
{"LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL"}
0

Returns: -1

Here it is impossible to draw the two rectangles. Regardless of how Jiro draws them, he will surely buy more lilies than petunias, and that is not allowed.

5)
{"LLLP..LLP.PLL.LL..LP",
 "L.PL.L.LLLL.LPLLPLP.",
 "PLL.LL.LLL..PL...L..",
 ".LPPP.PPPLLLLPLP..PP",
 "LP.P.PPL.L...P.L.LLL",
 "L..LPLPP.PP...PPPL..",
 "PP.PLLL.LL...LP..LP.",
 "PL...P.PPPL..PLP.L..",
 "P.PPPLPLP.LL.L.LLLPL",
 "PLLPLLP.LLL.P..P.LPL",
 "..LLLPLPPPLP.P.LP.LL",
 "..LP..L..LLPPP.LL.LP",
 "LPLL.PLLPPLP...LL..P",
 "LL.....PLL.PLL.P....",
 "LLL...LPPPPL.PL...PP",
 ".PLPLLLLP.LPP...L...",
 "LL...L.LL.LLLPLPPPP.",
 "PLPLLLL..LP.LLPLLLL.",
 "PP.PLL..L..LLLPPL..P",
 ".LLPL.P.PP.P.L.PLPLL"}
9

Returns: 208



*/

// END CUT HERE
