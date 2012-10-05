
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

class PointErasingTwo {
public:
   int getMaximum( vector <int> y ) {
	   int res = 0;
	   REP(i,SZ(y)){
		   REP(j,SZ(y)){
			   int tmp = 0;
			   for(int k=i+1; k<j; k++){
				   if(min(y[i],y[j]) < y[k] && y[k] < max(y[i], y[j])) tmp++;
			   }
			   res = max(res, tmp);
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
			int y[]                   = { 1, 2, 1, 1, 0, 4, 3 };
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = PointErasingTwo().getMaximum(vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int y[]                   = { 0, 1 };
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PointErasingTwo().getMaximum(vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int y[]                   = { 0, 1, 2, 3, 4 };
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = PointErasingTwo().getMaximum(vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int y[]                   = { 10, 19, 10, 19 };
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PointErasingTwo().getMaximum(vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int y[]                   = { 0, 23, 49, 50, 32, 0, 18, 50, 0, 28, 50, 27, 49, 0 };
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = PointErasingTwo().getMaximum(vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PointErasingTwo().getMaximum(vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PointErasingTwo().getMaximum(vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PointErasingTwo().getMaximum(vector <int>(y, y + (sizeof y / sizeof y[0])));
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
// You are given a vector <int> y of length N. 
The values in y describe N points in the plane: 
for each x = 0, 1, ..., N - 1 there is a point at coordinates (x, y[x]). 

Krolik is going to perform the following operation: 

	Choose two of the given points, say A and B, with different y-coordinates. 
	Consider the rectangle with sides parallel to coordinate axes and points A and B in two opposite corners. 
	Erase all points strictly inside the rectangle. 

Return the maximum possible number of points Krolik can erase by a single operation. 


DEFINITION
Class:PointErasingTwo
Method:getMaximum
Parameters:vector <int>
Returns:int
Method signature:int getMaximum(vector <int> y)


NOTES
-A point is strictly inside a rectangle if it is inside the rectangle and does not lie on the border of the rectangle. 


CONSTRAINTS
-y will contain between 2 and 50 elements, inclusive. 
-Each element of y will be between 0 and 50, inclusive. 
-y will contain at least 2 distinct elements. 


EXAMPLES

0)
{ 1, 2, 1, 1, 0, 4, 3 }

Returns: 2

If Krolik chooses A = (1, 2) and B = (4, 0), Krolik can erase two points: (2, 1) and (3, 1).




1)
{ 0, 1 }

Returns: 0

2)
{ 0, 1, 2, 3, 4 }

Returns: 3

3)
{ 10, 19, 10, 19 }

Returns: 0



4)
{ 0, 23, 49, 50, 32, 0, 18, 50, 0, 28, 50, 27, 49, 0 }

Returns: 5

*/

// END CUT HERE
