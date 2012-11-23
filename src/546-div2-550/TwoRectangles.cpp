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

class TwoRectangles {    
    int check(int x){
        if(x>0) return 2; //seg
        if(x==0) return 1; //point
        return 0; //none
    }
    
    
    
	public:
	string describeIntersection(vector <int> A, vector <int> B) {
		int res = 0;
        int x = check(min(A[2], B[2]) - max(A[0], B[0]));
        int y = check(min(A[3], B[3]) - max(A[1], B[1]));
        
        if(x==2 && y==2) return "rectangle";
        if(x==0 || y==0) return "none";
        if(x==1 && y==1) return "point";
        return "segment";
        
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
			int A[]                   = {0,0,3,2};
			int B[]                   = {1,1,5,3};
			string expected__         = "rectangle";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A[]                   = {0,0,5,3};
			int B[]                   = {1,2,2,3};
			string expected__         = "rectangle";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A[]                   = {1,1,6,2};
			int B[]                   = {3,2,5,4};
			string expected__         = "segment";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A[]                   = {0,1,2,3};
			int B[]                   = {2,0,5,2};
			string expected__         = "segment";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int A[]                   = {0,0,1,1};
			int B[]                   = {1,1,5,2};
			string expected__         = "point";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int A[]                   = {1,1,2,2};
			int B[]                   = {3,1,4,2};
			string expected__         = "none";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int A[]                   = ;
			int B[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int A[]                   = ;
			int B[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int A[]                   = ;
			int B[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
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
You are given two rectangles in the plane.
The sides of each rectangle are parallel to the coordinate axes.
Each rectangle is given by the coordinates of its lower left corner and its upper right corner.
You are given two vector <int>s: A and B.
A describes the first rectangle: its lower left corner has coordinates (A[0],A[1]) and its upper right corner has coordinates (A[2],A[3]).
B describes the second rectangle in the same way.


Your task is to determine how their intersection looks like.
There are four options:


If the rectangles have a non-zero area in common, return "rectangle".
Otherwise, if they have a common line segment with non-zero length, return "segment".
Otherwise, if they have a point in common, return "point".
Otherwise, return "none" (in all four cases, the quotes are just for clarity).


DEFINITION
Class:TwoRectangles
Method:describeIntersection
Parameters:vector <int>, vector <int>
Returns:string
Method signature:string describeIntersection(vector <int> A, vector <int> B)


NOTES
-The Constraints guarantee that both rectangles lie in the first quadrant of the coordinate plane, and each rectangle has a positive area.


CONSTRAINTS
-A will contain exactly 4 elements.
-The elements of A will satisfy 0 <= A[0] < A[2] <= 1000 and 0 <= A[1] < A[3] <= 1000.
-B will contain exactly 4 elements.
-The elements of B will satisfy 0 <= B[0] < B[2] <= 1000 and 0 <= B[1] < B[3] <= 1000.


EXAMPLES

0)
{0,0,3,2}
{1,1,5,3}

Returns: "rectangle"

These two rectangles overlap partially:




1)
{0,0,5,3}
{1,2,2,3}

Returns: "rectangle"

The second rectangle is completely inside the first one.




2)
{1,1,6,2}
{3,2,5,4}

Returns: "segment"

The second rectangle sits on top of the first one.




3)
{0,1,2,3}
{2,0,5,2}

Returns: "segment"



4)
{0,0,1,1}
{1,1,5,2}

Returns: "point"



5)
{1,1,2,2}
{3,1,4,2}

Returns: "none"



*/

// END CUT HERE
