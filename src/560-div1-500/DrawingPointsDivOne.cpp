
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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

bool first[310][310], pt[310][310];
int dp[310][310];

class DrawingPointsDivOne {
public:
   int maxSteps( vector <int> x, vector <int> y ) {
	MSET(first, false), MSET(pt, false), MSET(dp, 0);
	int mnx = *min_element(ALL(x)), mny = *min_element(ALL(y));
	REP(i, SZ(x)) first[x[i]-mnx][y[i]-mny] = true;
	memcpy(pt, first, sizeof(first));
	
	for(int turn = 1; turn <= 300; turn++){
		for(int i = 300; i >= 0; i--) for(int j = 300; j >= 0; j--)
			pt[i][j] |= (i&&pt[i-1][j]) || (j&&pt[i][j-1]) || (i&&j&&pt[i-1][j-1]);
		for(int i = 300; i >= 0; i--) for(int j = 300; j >= 0; j--) if(pt[i][j])
			dp[i][j] = min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1])) + 1;
		REP(i, 301) REP(j, 301)
			if(!first[i][j] && dp[i][j]-turn > 0) return turn-1;
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
			int x[]                   = {0, 3};
			int y[]                   = {0, 0};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = DrawingPointsDivOne().maxSteps(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {0,2};
			int y[]                   = {0,0};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DrawingPointsDivOne().maxSteps(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {-70};
			int y[]                   = {3};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = DrawingPointsDivOne().maxSteps(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {-41,-40,1,-11,-32,-7,24,-11,49,-15,-22,20,-8,54,54,69,16,-30,36,-6,-30,40,64,20,-66, -37,-33,-18,-35,36,9,61,-43,45,5,60,-8,-58,65,-66,41,12,34,-11,-57,-38,46,63,-55,3};
			int y[]                   = {5,-24,-2,-4,23,14,1,70,-26,45,15,48,32,-41,54,-47,-67,-46,-9,-53,54,28,-61,11,53,68, -33,62,37,-8,-17,-17,48,19,-49,56,-41,16,17,-50,28,59,10,50,23,-16,56,31,-70,-44};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = DrawingPointsDivOne().maxSteps(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DrawingPointsDivOne().maxSteps(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DrawingPointsDivOne().maxSteps(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DrawingPointsDivOne().maxSteps(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
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



You are given two vector <int>s x, y of some equal length n. They describe all of the points that were drawn by Wojtek in the last step of his play. More precisely, you may assume that there are real numbers (not necessarily integers) dy and dx such that the following holds:

For each i between 0 and n-1, there is a point at coordinates (dx+x[i], dy+y[i]).
There are no other points anywhere on the paper, only those that follow from the previous statement.




Return the maximum number of steps Wojtek could have made.
If there is no maximum (that is, if the number of steps can be arbitrarily large), return -1 instead.


DEFINITION
Class:DrawingPointsDivOne
Method:maxSteps
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int maxSteps(vector <int> x, vector <int> y)


NOTES
-Note that the points drawn by Wojtek in the last step of his play could have non-integer coordinates.
-The paper used by Wojtek could have been arbitrarily large. In other words, ignore the paper size, it does not limit the number of steps in any way.


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-x and y will contain the same number of elements.
-Each element of x will be between -70 and 70, inclusive.
-Each element of y will be between -70 and 70, inclusive.
-No two points described by x and y will be the same.


EXAMPLES

0)
{0, 3}
{0, 0}

Returns: 1

An example scenario:


Wojtek draws the initial points at locations (100, 100), (100, 101), (101, 100), (101, 101), (103, 100), (104, 100), (103, 101), (104, 101), (315, 714).
In the first and only step, Wojtek draws points at locations (100.5, 100.5) and (103.5, 100.5). These locations correspond to x and y in this test case.


1)
{0,2}
{0,0}

Returns: 0



2)
{-70}
{3}

Returns: -1



3)
{-41,-40,1,-11,-32,-7,24,-11,49,-15,-22,20,-8,54,54,69,16,-30,36,-6,-30,40,64,20,-66,
 -37,-33,-18,-35,36,9,61,-43,45,5,60,-8,-58,65,-66,41,12,34,-11,-57,-38,46,63,-55,3}
{5,-24,-2,-4,23,14,1,70,-26,45,15,48,32,-41,54,-47,-67,-46,-9,-53,54,28,-61,11,53,68,
 -33,62,37,-8,-17,-17,48,19,-49,56,-41,16,17,-50,28,59,10,50,23,-16,56,31,-70,-44}

Returns: 9



*/

// END CUT HERE
