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

int dp[52][52][52][52];
bool con[2][52][52][52];

int H, W;

class DonutsOnTheGridEasy {
	public:
	int calc(vector <string> grid) {
        H = SZ(grid);
        W = SZ(grid[0]);
		MSET(dp, 0);
        REP(i, 2) REP(j, 52) REP(k, 52) REP(l, 52) con[i][j][k][l] = false;
        
        REP(x, H) REP(y, W){
            REP(i, H-x){
                if(grid[x+i][y] == '.') break;
                con[0][x][y][i] = true;
            }
            REP(i, W-y){
                if(grid[x][y+i] == '.') break;
                con[1][x][y][i] = true;
            }
        }
        
        for(int h = 3; h <= H; h++) for(int w = 3; w <= W; w++){
            REP(x, H-h+1) REP(y, W-w+1){
                if(con[0][x][y][h-1] && con[0][x][y+w-1][h-1] && con[1][x][y][w-1] && con[1][x+h-1][y][w-1])
                    dp[x][y][h][w] = dp[x+1][y+1][h-2][w-2] + 1;
                else{
                    dp[x][y][h][w] = max(dp[x][y][h][w], dp[x][y][h-1][w]);
                    dp[x][y][h][w] = max(dp[x][y][h][w], dp[x][y][h][w-1]);
                    dp[x][y][h][w] = max(dp[x][y][h][w], dp[x+1][y][h-1][w]);
                    dp[x][y][h][w] = max(dp[x][y][h][w], dp[x][y+1][h][w-1]);
                }
            }
        }
        
        return dp[0][0][H][W];
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
			string grid[]             = {"0000000"
,"0.....0"
,"0.00000"
,"0.0..00"
,"0.00000"
,"0.....0"
,"0000000"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = DonutsOnTheGridEasy().calc(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string grid[]             = {"000"
,"0.0"
,"000"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = DonutsOnTheGridEasy().calc(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string grid[]             = {"..."
,"..."
,"..."};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DonutsOnTheGridEasy().calc(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string grid[]             = {"00.000"
,"00.000"
,"0.00.0"
,"000.00"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DonutsOnTheGridEasy().calc(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string grid[]             = {"0000000....",
 "0000000....",
 "0000000.000",
 "0000000.0.0",
 "0000000.000",
 "0000000....",
 "0000000...."};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DonutsOnTheGridEasy().calc(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DonutsOnTheGridEasy().calc(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DonutsOnTheGridEasy().calc(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DonutsOnTheGridEasy().calc(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
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
// Petya likes donuts. He tries to find them everywhere. For example if he is given a grid where each cell contains a '0' (zero) or '.' he will construct donuts from the cells.
To make the donuts:

Petya first selects a rectangle of cells of width, w, and height, h, where both are at least 3.
Then he removes a rectangular hole of width w-2 and height h-2 centered in the larger rectangle.
For the remaining cells (a closed rectangular ring) to be a valid donut, all of the cells must contain '0' (because donuts are shaped like zeros). Cells in the hole can contain anything since they are not part of the donut.

An example of large donut containing a smaller donut.

..........
.00000000.
.0......0.
.0.0000.0.
.0.0..0.0.
.0.0..0.0.
.0.0000.0.
.0......0.
.00000000.
..........

Donuts may contain other donuts and donuts may touch, but the cells of one donut may not overlap the cells of another. Petra is most interested in donuts that contain other donuts. He first places one valid donut on the grid (if possible). He then places a valid donut in the hole of the first donut (if possible). He continues to place a donut into the hole of the most recently placed donut until this is no longer possible.

Your task is to find the maximum number of donuts that Petya can place on the grid as described such that each donut (except for the first) is contained within the previous donut. You are given grid, a String[], containing only '0' and '.' characters. The j-th character of the i-th element is the value at cell (i, j).


DEFINITION
Class:DonutsOnTheGridEasy
Method:calc
Parameters:vector <string>
Returns:int
Method signature:int calc(vector <string> grid)


CONSTRAINTS
-grid will have between 1 and 50 elements, inclusive.
-Each element of grid will have between 1 and 50 characters, inclusive.
-All elements of grid will have the same length.
-Each character of grid will be either '0' (zero) or '.'.


EXAMPLES

0)
{"0000000"
,"0.....0"
,"0.00000"
,"0.0..00"
,"0.00000"
,"0.....0"
,"0000000"}

Returns: 2



1)
{"000"
,"0.0"
,"000"}

Returns: 1



2)
{"..."
,"..."
,"..."}

Returns: 0



3)
{"00.000"
,"00.000"
,"0.00.0"
,"000.00"}

Returns: 0



4)
{"0000000....",
 "0000000....",
 "0000000.000",
 "0000000.0.0",
 "0000000.000",
 "0000000....",
 "0000000...."}

Returns: 3



*/

// END CUT HERE
