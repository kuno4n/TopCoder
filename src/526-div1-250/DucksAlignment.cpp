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

class DucksAlignment {
	public:
	int minimumTime(vector <string> grid) {
		VI col, row;
        col.clear();
        row.clear();
        int res = 100000;
        
        REP(i, SZ(grid)){
            REP(j, SZ(grid[0])){
                if(grid[i][j]=='o'){
                    col.push_back(j);
                    row.push_back(i);
                }
            }
        }
        sort(ALL(col));
        sort(ALL(row));
        
        REP(i, SZ(grid[0])){
            int tmp_col = 0;
            REP(j, SZ(col)) tmp_col += abs(col[j]-i);
            int tmp_row = 100000;
            REP(j, SZ(row)){
                int tmp = 0;
                REP(k, SZ(row)){
                    tmp += abs(row[j]-row[k]) - abs(j-k);
                }
                tmp_row = min(tmp_row, tmp);
            }
            
            res = min(res, tmp_col + tmp_row);
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
			string grid[]             = {".o",
 "o."};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = DucksAlignment().minimumTime(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string grid[]             = {".o...",
 "..o..",
 "....o"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DucksAlignment().minimumTime(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string grid[]             = {"o..........",
 "..o........",
 ".......o...",
 "...........",
 "...........",
 "...........",
 "........o..",
 "..........."};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = DucksAlignment().minimumTime(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string grid[]             = {".........",
 "....o....",
 "........."};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DucksAlignment().minimumTime(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string grid[]             = {"...o..........................",
 "............................o.",
 ".o............................",
 "............o.................",
 ".................o............",
 "......................o.......",
 "......o.......................",
 "....o.........................",
 "...............o..............",
 ".......................o......",
 "...........................o..",
 ".......o......................"};
			int expected__            = 99;

			clock_t start__           = clock();
			int received__            = DucksAlignment().minimumTime(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DucksAlignment().minimumTime(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DucksAlignment().minimumTime(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DucksAlignment().minimumTime(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
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
// Mr. Dengklek has a rectangular farm conveniently divided into a grid of unit squares. At this moment, each unit square contains at most one duck. Moreover, each row and column of the farm also contains at most one duck. You are given a vector <string> grid. The j-th character of the i-th element of grid will be 'o' if there is exactly one duck in square (i, j), i.e., row i column j, or '.' if there is no duck in that square. 

Today, Mr. Dengklek wants to align the ducks so that the ducks form a contiguous line. More precisely, assume that there are N ducks on the farm. After the alignment, the ducks must either occupy N contiguous squares in some row or N contiguous squares in some column. To accomplish that, he will move the ducks one at a time. To move a duck in square (a, b) to another empty square (c, d), he needs |a-c| + |b-d| seconds, where |x| denotes the absolute value of x. Mr. Dengklek can always move any duck to any empty square he desires - the other ducks are not obstacles.

Return the minimum time in seconds Mr. Dengklek needs to align the ducks. Note that restrictions imposed on the initial placement of ducks guarantee that a proper alignment is always possible.

DEFINITION
Class:DucksAlignment
Method:minimumTime
Parameters:vector <string>
Returns:int
Method signature:int minimumTime(vector <string> grid)


CONSTRAINTS
-grid will contain between 1 and 50 elements, inclusive.
-Each element of grid will contain between 1 and 50 characters, inclusive.
-All elements of grid will contain the same number of characters.
-Each character of grid will be either 'o' or '.'.
-Each row in grid will contain at most one character 'o'.
-Each column in grid will contain at most one character 'o'.
-grid will contain at least one character 'o'.


EXAMPLES

0)
{".o",
 "o."}

Returns: 1

Move either duck to an adjacent empty square.

1)
{".o...",
 "..o..",
 "....o"}

Returns: 3

One of the solutions is: move the the duck in the first row one square to the right, and then move the duck in the last row two squares to the left.

2)
{"o..........",
 "..o........",
 ".......o...",
 "...........",
 "...........",
 "...........",
 "........o..",
 "..........."}

Returns: 16

Align all ducks in the second row.

3)
{".........",
 "....o....",
 "........."}

Returns: 0



4)
{"...o..........................",
 "............................o.",
 ".o............................",
 "............o.................",
 ".................o............",
 "......................o.......",
 "......o.......................",
 "....o.........................",
 "...............o..............",
 ".......................o......",
 "...........................o..",
 ".......o......................"}

Returns: 99



*/

// END CUT HERE
