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

class YetAnotherIncredibleMachine {
	public:
	int countWays(vector <int> platformMount, vector <int> platformLength, vector <int> balls) {
		LL res = 1LL;
        int n = SZ(platformLength);
        
        REP(i, n){
            LL cnt = 0;
            REP(move, platformLength[i]+1){
                cnt++;
                REP(j, SZ(balls)){
                    if(platformMount[i]-move <= balls[j] && balls[j] <= platformMount[i]+platformLength[i]-move){
                        cnt--;
                        break;
                    }
                }
            }
            res *= cnt;
            res %= 1000000009;
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
			int platformMount[]       = {7};
			int platformLength[]      = {10};
			int balls[]               = {3,4};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int platformMount[]       = {1,4};
			int platformLength[]      = {3,3};
			int balls[]               = {2,7};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int platformMount[]       = {4,4,4};
			int platformLength[]      = {10,9,8};
			int balls[]               = {1,100};
			int expected__            = 27;

			clock_t start__           = clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int platformMount[]       = {0};
			int platformLength[]      = {1};
			int balls[]               = {0};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int platformMount[]       = {100, -4215, 251};
			int platformLength[]      = {400, 10000, 2121};
			int balls[]               = {5000, 2270, 8512, 6122};
			int expected__            = 250379170;

			clock_t start__           = clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int platformMount[]       = ;
			int platformLength[]      = ;
			int balls[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int platformMount[]       = ;
			int platformLength[]      = ;
			int balls[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int platformMount[]       = ;
			int platformLength[]      = ;
			int balls[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
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
// You may remember an old computer game called "The Incredible Machine". It was a game where you could simulate simple processes like balls falling, lasers shooting, or cats pursuing mice.
Manao is faced with the following problem in this game.

The game is 2-dimensional. To make solving the problem easier, Manao introduced the cartesian coordinates on the screen. The OX axis goes from left to right and coincides with the ground. The OY axis goes from bottom to top.

There are N horizontal platforms mounted at different heights. The length of the i-th platform is platformLength[i] and it is mounted at point (platformMount[i], i + 1). Each platform can be moved horizontally in such a way that it does not disconnect from its mount, i.e., the mount resides between its ends or on one of them. In other words, the leftmost possible position of the i-th platform is when its left end is at (platformMount[i] - platformLength[i], i + 1) and the rightmost position is when its right end is at (platformMount[i] + platformLength[i], i + 1). The platforms may only be moved by integer distances, so both left and right ends of a platform are always located at points with integer coordinates.

Several balls will simultaneously fall downwards to the ground from a height that is above all platforms. All balls will fall vertically and the i-th of them will fall at X-coordinate balls[i]. The balls are very small and can be considered as points. Manao should set the platforms' placement in such a way that no ball falls on a platform. Falling on an end of a platform counts as falling on a platform. Manao is not allowed to move the platforms once the balls start falling.

Count the number of ways to place the platforms so that all of the balls miss them. Return this number modulo 1,000,000,009. Two placements are different if there's a platform that has different positions in these placements.

DEFINITION
Class:YetAnotherIncredibleMachine
Method:countWays
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int countWays(vector <int> platformMount, vector <int> platformLength, vector <int> balls)


CONSTRAINTS
-platformMount will contain between 1 and 50 elements, inclusive.
-Each element of platformMount will be between -10000 and 10000, inclusive.
-platformLength will contain the same number of elements as platformMount.
-Each element of platformLength will be between 1 and 10000, inclusive.
-balls will contain between 1 and 50 elements, inclusive.
-Each element of balls will be between -10000 and 10000, inclusive.
-All elements of balls will be distinct.


EXAMPLES

0)
{7}
{10}
{3,4}

Returns: 3

A platform of length 10 is mounted at point (7, 1). Two balls will fall at coordinates 3 and 4. There are three placements of the platform which let the ball miss it: setting the platform's left end at X-coordinate 5, 6 and 7.

1)
{1,4}
{3,3}
{2,7}

Returns: 1

The only placement which ensures that balls land aside the platforms is when platform 0's right end is at point (1, 1) and platform 1's left end is at (3, 2).

2)
{4,4,4}
{10,9,8}
{1,100}

Returns: 27

There are 3 possible placements for each of the platforms.

3)
{0}
{1}
{0}

Returns: 0

There is no way to move the platform away from the ball's trajectory.

4)
{100, -4215, 251}
{400, 10000, 2121}
{5000, 2270, 8512, 6122}

Returns: 250379170



*/

// END CUT HERE
