
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
#include <queue>

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
#define OUT(A) cout << #A << " = "<< A << endl

vector <string> g;
int u, h, w;

bool can(int sz, int x, int y){
	for(int xx = x, yy = y+sz-1; xx < x+sz; xx++, yy--){
		if(g[xx][yy] != '/') return false;
	}
	int use = 0;
	for(int xx = x, yy = y+sz-2; xx < x+sz-1; xx++, yy--){
		for(int yyy = yy; yyy >= y; yyy--){
			if(g[xx][yyy] == '.') return false;
			if(g[xx][yyy] == '/') use++;
		}
	}
	if(use > u) return false;
	if(x > 0){
		for(int yy = y; yy < y+sz; yy++){
			if(g[x-1][yy] == '#') return false;
		}
	}
	if(y > 0){
		for(int xx = x; xx < x+sz; xx++){
			if(g[xx][y-1] == '#') return false;
		}
	}
	return true;
}

class UnfoldingTriangles {
public:
   int solve( vector <string> grid, int unfoldLimit ) {
	   g = grid;
	   u = unfoldLimit;
	   h = SZ(grid); w = SZ(grid[0]);
	   REP(i, h) REP(j, w){
		   g[i][j] = grid[h-i-1][w-j-1];
	   }

	   int res = -1;
	   for(int sz = 1; sz <= min(h, w); sz++){
		   for(int x = 0; x+sz-1 < h; x++){
			   for(int y = 0; y+sz-1 < w; y++){
				   if(can(sz, x, y)) res = max(res, sz*(sz+1)/2);
			   }
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
			string grid[]             = {".../",
 "../#",
 "./#/",
 "/#//"};
			int unfoldLimit           = 4;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = UnfoldingTriangles().solve(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), unfoldLimit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string grid[]             = {".../",
 "../#",
 "./#/",
 "/#//"};
			int unfoldLimit           = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = UnfoldingTriangles().solve(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), unfoldLimit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string grid[]             = {"////",
 "////",
 "////",
 "////"};
			int unfoldLimit           = 5;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = UnfoldingTriangles().solve(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), unfoldLimit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string grid[]             = {".....#...",
 "....###.."};
			int unfoldLimit           = 10;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = UnfoldingTriangles().solve(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), unfoldLimit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string grid[]             = {"#//#",
 "#//#",
 "####",
 "///#"};
			int unfoldLimit           = 4;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = UnfoldingTriangles().solve(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), unfoldLimit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string grid[]             = {".../.../",
 "../#..//",
 "./.#.///",
 "/###...."};
			int unfoldLimit           = 3;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = UnfoldingTriangles().solve(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), unfoldLimit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string grid[]             = ;
			int unfoldLimit           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UnfoldingTriangles().solve(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), unfoldLimit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string grid[]             = ;
			int unfoldLimit           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UnfoldingTriangles().solve(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), unfoldLimit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string grid[]             = ;
			int unfoldLimit           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UnfoldingTriangles().solve(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), unfoldLimit);
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
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.


You are given a white rectangular grid made up of square cells.  Some cells contain black squares, and some contain black squares that have been folded in half to form right triangles, such that one of their sides matches the grid line to the right of the cell and another side of the triangle matches the grid line to the bottom of the cell.  At most unfoldLimit of these triangles can be unfolded to become black squares. However, black squares cannot be folded to become triangles.

We are interested in forming the largest possible proper black triangle in the grid using the aforementioned operations.  A black triangle is considered proper within a grid configuration if no other black shape shares a line segment with it.  However, black shapes may still share one or more points with the triangle. The size of a triangle is defined as the number of grid cells that are currently occupied by the triangle.

The grid will be given as a vector <string>, where the j-th character of the i-th element represents the cell at row i, column j.  '.' represents an empty cell, '#' represents a cell containing a black square, and '/' represents a cell containing a black triangle.  Return the largest possible size for a proper triangle that can be formed in the given grid by unfolding at most unfoldLimit triangles. In case it is not possible to form a proper black triangle in the grid, return -1.

For example, consider the following input grid:





If unfoldLimit is greater than or equal to 3, the largest possible proper triangle size is 10:
   



If unfoldLimit is 2, the largest possible proper triangle size is 3:
   
Larger black triangles are possible, but they would not be proper triangles.

DEFINITION
Class:UnfoldingTriangles
Method:solve
Parameters:vector <string>, int
Returns:int
Method signature:int solve(vector <string> grid, int unfoldLimit)


CONSTRAINTS
-grid will contain between 1 and 50 elements, inclusive.
-Each element of grid will contain between 1 and 50 characters, inclusive.
-Each element of grid will contain the same number of characters.
-Each character in grid will be '.', '#' or '/'.
-unfoldLimit will be between 1 and 2500, inclusive.


EXAMPLES

0)
{".../",
 "../#",
 "./#/",
 "/#//"}
4

Returns: 10



1)
{".../",
 "../#",
 "./#/",
 "/#//"}
2

Returns: 3

Examples 1 and 0 were explained in the problem statement.

2)
{"////",
 "////",
 "////",
 "////"}
5

Returns: 6



3)
{".....#...",
 "....###.."}
10

Returns: -1



4)
{"#//#",
 "#//#",
 "####",
 "///#"}
4

Returns: 1



5)
{".../.../",
 "../#..//",
 "./.#.///",
 "/###...."}
3

Returns: 6



*/

// END CUT HERE
