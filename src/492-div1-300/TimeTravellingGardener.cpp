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

#define EPS 1e-11

class TimeTravellingGardener {
	public:
	int determineUsage(vector <int> distance, vector <int> height) {
		int res = SZ(distance);
        int x[60] = {0};
        REP(i, SZ(distance)) x[i+1] = x[i] + distance[i];
        int y[60] = {0};
        REP(i, SZ(height)) y[i] = height[i];
        
        REP(i, SZ(height)){
            FOR(j, i+1, SZ(height)){
                double a = (y[j]-y[i])/(double)(x[j]-x[i]);
                int tmp = 0;
                REP(k, SZ(height)){
                    double yy = y[i] + a*(x[k]-x[i]);
                    if(yy > y[k]+EPS || yy < -EPS) tmp = 10000;
                    if(yy < y[k]-EPS) tmp++;
                }
                res = min(res, tmp);
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
			int distance[]            = {2,2};
			int height[]              = {1,3,10};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage(vector <int>(distance, distance + (sizeof distance / sizeof distance[0])), vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int distance[]            = {3,3};
			int height[]              = {3,1,3};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage(vector <int>(distance, distance + (sizeof distance / sizeof distance[0])), vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int distance[]            = {1,3};
			int height[]              = {4,4,4};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage(vector <int>(distance, distance + (sizeof distance / sizeof distance[0])), vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int distance[]            = {4,2};
			int height[]              = {9,8,5};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage(vector <int>(distance, distance + (sizeof distance / sizeof distance[0])), vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int distance[]            = {476,465,260,484};
			int height[]              = {39,13,8,72,80};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage(vector <int>(distance, distance + (sizeof distance / sizeof distance[0])), vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int distance[]            = {173,36,668,79,26,544};
			int height[]              = {488,743,203,446,444,91,453};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage(vector <int>(distance, distance + (sizeof distance / sizeof distance[0])), vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int distance[]            = {2,4,2,2,4,2,4,2,2,4};
			int height[]              = {2,2,10,10,10,16,16,22,22,28,28};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage(vector <int>(distance, distance + (sizeof distance / sizeof distance[0])), vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int distance[]            = ;
			int height[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage(vector <int>(distance, distance + (sizeof distance / sizeof distance[0])), vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int distance[]            = ;
			int height[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage(vector <int>(distance, distance + (sizeof distance / sizeof distance[0])), vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int distance[]            = ;
			int height[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TimeTravellingGardener().determineUsage(vector <int>(distance, distance + (sizeof distance / sizeof distance[0])), vector <int>(height, height + (sizeof height / sizeof height[0])));
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


There are N trees arranged in a straight horizontal line. They are numbered 0 through N-1 from left to right. The distance between tree i and tree (i+1) is distance[i], and the initial vertical height of tree i is height[i]. Each tree is assumed to be a perfect vertical segment.


Your goal is to make the topmost points of all the trees collinear. To do this, you can choose any number of trees and have them travel back to a time when they were shorter. You can decrease the height of each chosen tree to any non-negative value (not necessarily an integer). You will operate on each tree individually, so the trees do not all have to decrease in height by the same amount. The trees that you do not choose will all remain at their original heights.


Return the minimum number of trees you must send back in time to achieve this goal.

DEFINITION
Class:TimeTravellingGardener
Method:determineUsage
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int determineUsage(vector <int> distance, vector <int> height)


NOTES
-Two or more points are collinear if they lie on a single straight line.


CONSTRAINTS
-distance will contain between 1 and 49 elements, inclusive.
-Each element of distance will be between 1 and 1000, inclusive.
-The number of elements in height will be one plus the number of elements in distance.
-Each element of height will be between 1 and 1000, inclusive.


EXAMPLES

0)
{2,2}
{1,3,10}

Returns: 1



1)
{3,3}
{3,1,3}

Returns: 2



2)
{1,3}
{4,4,4}

Returns: 0



3)
{4,2}
{9,8,5}

Returns: 1



4)
{476,465,260,484}
{39,13,8,72,80}

Returns: 3



5)
{173,36,668,79,26,544}
{488,743,203,446,444,91,453}

Returns: 5

6)
{2,4,2,2,4,2,4,2,2,4}
{2,2,10,10,10,16,16,22,22,28,28}

Returns: 6



*/

// END CUT HERE
