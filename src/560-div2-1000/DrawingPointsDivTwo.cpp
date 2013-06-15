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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

class DrawingPointsDivTwo {
	public:
	int maxSteps(vector <string> points) {
		int h = SZ(points), w = SZ(points[0]), H = h+21, W = w+21;
        bool t[H][W]; MSET(t, false);
        REP(i, h) REP(j, w) if(points[i][j] == '*') t[i][j] = true;
        for(int k = 1; k <= 21; k++){
            for(int i = H-1; i >= 0; i--) for(int j = W-1; j >= 0; j--){
                if(i > 0) t[i][j] |= t[i-1][j];
                if(j > 0) t[i][j] |= t[i][j-1];
                if(i > 0 && j > 0) t[i][j] |= t[i-1][j-1];
            }
            for(int i = H-1-k; i >= 0; i--) for(int j = W-1-k; j >= 0; j--){
                bool check = true;
                REP(ii, k+1) REP(jj, k+1) if(!t[i+ii][j+jj]) check = false;
                if(check && (i >= h || j >= w || points[i][j] != '*')) return k-1;
            }
        }
        
        return -1;
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
			string points[]           = {"*..*"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = DrawingPointsDivTwo().maxSteps(vector <string>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string points[]           = {"...",".*."};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = DrawingPointsDivTwo().maxSteps(vector <string>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string points[]           = {"*.*"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DrawingPointsDivTwo().maxSteps(vector <string>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string points[]           = {"..*.",
 "*...",
 "...*"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = DrawingPointsDivTwo().maxSteps(vector <string>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string points[]           = {"....................",
 "..........*.........",
 "....................",
 ".........*..........",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 ".*..................",
 "....................",
 "*.............**....",
 "....................",
 "....................",
 "................*...",
 "....................",
 "...................."};
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = DrawingPointsDivTwo().maxSteps(vector <string>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string points[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DrawingPointsDivTwo().maxSteps(vector <string>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string points[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DrawingPointsDivTwo().maxSteps(vector <string>(points, points + (sizeof points / sizeof points[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string points[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DrawingPointsDivTwo().maxSteps(vector <string>(points, points + (sizeof points / sizeof points[0])));
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
// This problem statement contains images. It may not display properly outside the applet.



Once upon a time, Little Wojtek had drawn a number of points with integer coordinates onto a sheet of paper.
Then he made zero or more steps.
Each step looked as follows:
Let's call all the points on Wojtek's paper old points.
For every four old points that formed the vertices of a 1x1 square, Wojtek would draw a point in the middle of that square.
Once he had drawn all such new points, he took an eraser and erased all the old points.



An example is shown in the picture below.
On the left is Wojtek's original paper.
In the middle is the same paper with the new points filled in.
(For clarity, the old points are black and the new ones are red.)
On the right is the paper after the old points were erased.



?
?




He has been playing for a while when he was called downstairs to dinner.
He looked at the paper with a surprised face and wondered how many steps he had made.



You are given a vector <string> points, describing a rectangular area of Wojtek's paper.
This area contains all of the points that were drawn by Wojtek at the end of his play.
More precisely, you may assume that there are real numbers (not necessarily integers) dy and dx such that the following holds:



If points[i][j] = '*', then there is a point at coordinates (dx+j,dy+i).
There are no other points anywhere on the paper, only those that follow from the previous statement.



Return the maximum number of steps Wojtek could have made.
If there is no maximum (that is, if the number of steps can be arbitrarily large), return -1 instead.


DEFINITION
Class:DrawingPointsDivTwo
Method:maxSteps
Parameters:vector <string>
Returns:int
Method signature:int maxSteps(vector <string> points)


NOTES
-Note that the points drawn by Wojtek in the last step of his play could have non-integer coordinates.
-The paper used by Wojtek could have been arbitrarily large. In other words, ignore the paper size, it does not limit the number of steps in any way.


CONSTRAINTS
-points will contain between 1 and 20 elements, inclusive.
-points[0] will contain between 1 and 20 characters, inclusive.
-All elements of points will contain the same number of characters.
-Each character of each element of points will be either '*' (an asterisk) or '.' (a period).
-points will contain at least one '*' character.


EXAMPLES

0)
{"*..*"}

Returns: 1

An example scenario:


Wojtek draws the initial points at locations (100, 100), (100, 101), (101, 100), (101, 101), (103, 100), (104, 100), (103, 101), (104, 101), (315, 714).
In the first and only step, Wojtek draws points at locations (100.5, 100.5) and (103.5, 100.5). These locations correspond to points in this test case.


1)
{"...",".*."}

Returns: -1



2)
{"*.*"}

Returns: 0



3)
{"..*.",
 "*...",
 "...*"}

Returns: 1



4)
{"....................",
 "..........*.........",
 "....................",
 ".........*..........",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 ".*..................",
 "....................",
 "*.............**....",
 "....................",
 "....................",
 "................*...",
 "....................",
 "...................."}

Returns: 11



*/

// END CUT HERE
