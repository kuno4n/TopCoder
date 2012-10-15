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

class CirclesCountry {
	public:
	int leastBorders(vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2) {
		int N = SZ(X);
        int res = 0;
        REP(i, N){
            int c1 = 0;
            int c2 = 0;
            if((X[i]-x1)*(X[i]-x1) + (Y[i]-y1)*(Y[i]-y1) < R[i]*R[i]) c1++;
            if((X[i]-x2)*(X[i]-x2) + (Y[i]-y2)*(Y[i]-y2) < R[i]*R[i]) c2++;
            if(c1!=c2) res++;
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
			int X[]                   = {0};
			int Y[]                   = {0};
			int R[]                   = {2};
			int x1                    = -5;
			int y1                    = 1;
			int x2                    = 5;
			int y2                    = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = CirclesCountry().leastBorders(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int X[]                   = {0,-6,6};
			int Y[]                   = {0,1,2};
			int R[]                   = {2,2,2};
			int x1                    = -5;
			int y1                    = 1;
			int x2                    = 5;
			int y2                    = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = CirclesCountry().leastBorders(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int X[]                   = {1,-3,2,5,-4,12,12};
			int Y[]                   = {1,-1,2,5,5,1,1};
			int R[]                   = {8,1,2,1,1,1,2};
			int x1                    = -5;
			int y1                    = 1;
			int x2                    = 12;
			int y2                    = 1;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = CirclesCountry().leastBorders(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int X[]                   = {-3,2,2,0,-4,12,12,12};
			int Y[]                   = {-1,2,3,1,5,1,1,1};
			int R[]                   = {1,3,1,7,1,1,2,3};
			int x1                    = 2;
			int y1                    = 3;
			int x2                    = 13;
			int y2                    = 2;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = CirclesCountry().leastBorders(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int X[]                   = {-107,-38,140,148,-198,172,-179,148,176,153,-56,-187};
			int Y[]                   = {175,-115,23,-2,-49,-151,-52,42,0,68,109,-174};
			int R[]                   = {135,42,70,39,89,39,43,150,10,120,16,8};
			int x1                    = 102;
			int y1                    = 16;
			int x2                    = 19;
			int y2                    = -108;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = CirclesCountry().leastBorders(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int X[]                   = ;
			int Y[]                   = ;
			int R[]                   = ;
			int x1                    = ;
			int y1                    = ;
			int x2                    = ;
			int y2                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CirclesCountry().leastBorders(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int X[]                   = ;
			int Y[]                   = ;
			int R[]                   = ;
			int x1                    = ;
			int y1                    = ;
			int x2                    = ;
			int y2                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CirclesCountry().leastBorders(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int X[]                   = ;
			int Y[]                   = ;
			int R[]                   = ;
			int x1                    = ;
			int y1                    = ;
			int x2                    = ;
			int y2                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CirclesCountry().leastBorders(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), x1, y1, x2, y2);
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
// Circles Country is a country that contains several circular-shaped districts.  Some districts may be situated inside other districts, but their borders do not intersect or touch.  Qatam is a resident of Circles Country.  When he travels between two locations, he always tries to cross the fewest number of district borders as possible because crossing borders is usually a laborious task.

Imagine Circles Country as an infinite plane.  You are given vector <int>s X, Y and R, where (X[i], Y[i]) are the coordinates of the i-th district's center and R[i] is its radius.  Qatam is currently at point (x1,y1) and he needs to get to point (x2,y2).  Neither of these points lies on a district border.  Return the minimal number of district borders he must cross to get to his destination.


DEFINITION
Class:CirclesCountry
Method:leastBorders
Parameters:vector <int>, vector <int>, vector <int>, int, int, int, int
Returns:int
Method signature:int leastBorders(vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2)


CONSTRAINTS
-X will contain between 1 and 50 elements, inclusive.
-X, Y and R will each contain the same number of elements.
-Each element of X and Y will be between -1000 and 1000, inclusive.
-Each element of R will be between 1 and 1000, inclusive.
-x1, y1, x2 and y2 will be between -1000 and 1000, inclusive.
-No two circumferences will have common points.
-The points (x1,y1) and (x2,y2) will not lie on any of the circumferences.


EXAMPLES

0)
{0}
{0}
{2}
-5
1
5
1

Returns: 0



1)
{0,-6,6}
{0,1,2}
{2,2,2}
-5
1
5
1

Returns: 2



2)
{1,-3,2,5,-4,12,12}
{1,-1,2,5,5,1,1}
{8,1,2,1,1,1,2}
-5
1
12
1

Returns: 3



3)
{-3,2,2,0,-4,12,12,12}
{-1,2,3,1,5,1,1,1}
{1,3,1,7,1,1,2,3}
2
3
13
2

Returns: 5



4)
{-107,-38,140,148,-198,172,-179,148,176,153,-56,-187}
{175,-115,23,-2,-49,-151,-52,42,0,68,109,-174}
{135,42,70,39,89,39,43,150,10,120,16,8}
102
16
19
-108

Returns: 3

*/

// END CUT HERE
