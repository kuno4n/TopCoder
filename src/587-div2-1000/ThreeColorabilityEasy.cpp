
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

int cal1(int a, int b){
	set<int> s;
	s.insert(a);
	s.insert(b);
	for(int i = 1; i <= 3; i++) if(s.count(i) == 0) return i;
	return -1;
}

int cal2(int a, int b, int c){
	set<int> s;
	s.insert(a);
	s.insert(b);
	s.insert(c);
	for(int i = 1; i <= 3; i++) if(s.count(i) == 0) return i;
	return -1;
}

class ThreeColorabilityEasy {
public:
   string isColorable( vector <string> cells ) {
	int h = SZ(cells), w = SZ(cells[0]);
	int dp[55][55];MSET(dp, 0);
	
	dp[0][0] = 1, dp[0][1] = 2;
	if(cells[0][0] == 'Z') dp[1][0] = 3, dp[1][1] = 1;
	else dp[1][0] = 2, dp[1][1] = 3;
	for(int i = 1; i < w; i++){
		if(cells[0][i] == 'Z') dp[0][i+1] = cal1(dp[0][i], dp[1][i]), dp[1][i+1] = dp[0][i];
		else dp[0][i+1] = dp[1][i], dp[1][i+1] = cal1(dp[0][i], dp[1][i]);
	}
	
	for(int i = 1; i < h; i++){
		if(cells[i][0] == 'Z') dp[i+1][0] = cal1(dp[i][0], dp[i][1]), dp[i+1][1] = dp[i][0];
		else dp[i+1][0] = dp[i][1], dp[i+1][1] = cal1(dp[i][0], dp[i][1]);
		if(w > 1 && dp[i+1][1] == dp[i][2] && cells[i][1] == 'Z') return "No";
		for(int j = 1; j < w; j++){
			if(cells[i][j] == 'Z') dp[i+1][j+1] = cal1(dp[i][j+1], dp[i+1][j]);
			else dp[i+1][j+1] = cal2(dp[i][j], dp[i+1][j], dp[i][j+1]);
			if(dp[i+1][j+1] == -1) return "No";
		}
	}
	
	return "Yes";
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string cells[]            = {"Z"};
			string expected__         = "Yes";

			clock_t start__           = clock();
			string received__         = ThreeColorabilityEasy().isColorable(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string cells[]            = {"NZ"
,"NZ"};
			string expected__         = "Yes";

			clock_t start__           = clock();
			string received__         = ThreeColorabilityEasy().isColorable(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string cells[]            = {"ZZZ"
,"ZNZ"};
			string expected__         = "No";

			clock_t start__           = clock();
			string received__         = ThreeColorabilityEasy().isColorable(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string cells[]            = {"NZNZNNN"
,"NNZNNNZ"
,"NNNNZZZ"
,"ZZZNZZN"
,"ZZNZNNN"
,"NZZZZNN"
,"ZZZNZNN"};
			string expected__         = "No";

			clock_t start__           = clock();
			string received__         = ThreeColorabilityEasy().isColorable(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string cells[]            = {"ZZZZ"
,"ZZZZ"
,"ZZZZ"};
			string expected__         = "Yes";

			clock_t start__           = clock();
			string received__         = ThreeColorabilityEasy().isColorable(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string cells[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = ThreeColorabilityEasy().isColorable(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string cells[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = ThreeColorabilityEasy().isColorable(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string cells[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = ThreeColorabilityEasy().isColorable(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
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
There is a H times W rectangle divided into unit cells.
The rows of cells are numbered 0 to H-1 from top to bottom, and the columns are numbered 0 to W-1 from left to right.
The corners of cells are called lattice points.
By definition, there are (H+1)*(W+1) lattice points in our rectangle.


Each of the four edges of each cell is painted white.
Additionally, in each cell exactly one of the two diagonals is painted white.
Two lattice points are called adjacent if they are connected by a white line segment.
(In other words, consecutive corners of a cell are always adjacent, opposite corners of a cell are adjacent if and only if they are connected by a painted diagonal, and no other pairs of lattice points are adjacent.)


We now want to color each of the lattice points using one of three available colors: red, green, or blue.
There is only one constraint: adjacent lattice points are not allowed to share the same color.


You are given a vector <string> cells with H elements, each consisting of W characters.
If cells[i][j] is 'N', there is a diagonal line from the top left to the bottom right corner in the cell in row i, column j.
If cells[i][j] is 'Z', there is a diagonal line from the top right to the bottom left corner in the cell in row i, column j.


If there is at least one valid way to color all lattice points, return "Yes" (quotes for clarity).
Otherwise, return "No".



DEFINITION
Class:ThreeColorabilityEasy
Method:isColorable
Parameters:vector <string>
Returns:string
Method signature:string isColorable(vector <string> cells)


CONSTRAINTS
-cells will contain between 1 and 50 elements, inclusive.
-Each element of cells will contain between 1 and 50 characters, inclusive.
-All elements of cells will contain the same number of characters.
-Each character of cells will be either 'N' or 'Z'.


EXAMPLES

0)
{"Z"}

Returns: "Yes"

One of the possible colorings is as follows.




1)
{"NZ"
,"NZ"}

Returns: "Yes"





2)
{"ZZZ"
,"ZNZ"}

Returns: "No"



3)
{"NZNZNNN"
,"NNZNNNZ"
,"NNNNZZZ"
,"ZZZNZZN"
,"ZZNZNNN"
,"NZZZZNN"
,"ZZZNZNN"}

Returns: "No"



4)
{"ZZZZ"
,"ZZZZ"
,"ZZZZ"}

Returns: "Yes"



*/

// END CUT HERE
