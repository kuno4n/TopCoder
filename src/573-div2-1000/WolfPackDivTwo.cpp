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

#define MOD 1000000007


const int MAX_N = 60;
LL nCr[MAX_N+1][MAX_N+1];

void makepas(){
    REP(i, MAX_N+1) REP(j, MAX_N+1) nCr[i][j] = 1;
    for(int i=1; i<=MAX_N; i++){
        nCr[i][0] = 1;
        nCr[i][i] = 1;
        for(int j=1; j<i; j++){
            nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % MOD;
        }
    }
}


int n, m;
VI x, y;

LL cnt2(int sx, int sy, int gx, int gy){
    int dx = abs(sx - gx);
    int dy = abs(sy - gy);
    int dd = dx + dy;
    if(dd > m || ((m-dd) & 1)) return 0;
    LL res = 0;
    int rem = (m - dd) / 2;
    REP(i, rem+1) {
        LL tmp = 1;
        int x1 = dx+i, x2 = i;
        int y1 = dy+(rem-i);
        tmp = (tmp * nCr[m][x1]) % MOD;
        tmp = (tmp * nCr[m-x1][x2]) % MOD;
        tmp = (tmp * nCr[m-x1-x2][y1]) % MOD;
        res = (res + tmp) % MOD;
    }
    return res;
}

LL cnt(int gx, int gy){
    LL res = 1LL;
    REP(i, n) res = (res * cnt2(x[i], y[i], gx, gy)) % MOD;
    return res;
}

class WolfPackDivTwo {
	public:
	int calc(vector <int> X, vector <int> Y, int M) {
		x = X;
        y = Y;
        m = M;
        n = SZ(x);
        REP(i, n) x[i] += 50;
        REP(i, n) y[i] += 50;
        LL res = 0;
        makepas();
        REP(i, 151) REP(j, 151) res = (res + cnt(i, j)) % MOD;
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
			int x[]                   = {3,5};
			int y[]                   = {0,0};
			int m                     = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = WolfPackDivTwo().calc(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {0,1};
			int y[]                   = {0,0};
			int m                     = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = WolfPackDivTwo().calc(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {0,2,4};
			int y[]                   = {0,0,0};
			int m                     = 2;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = WolfPackDivTwo().calc(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {7,8};
			int y[]                   = {8,7};
			int m                     = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = WolfPackDivTwo().calc(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,8,8,8,8,8,8,8,8,8,8} ;
			int y[]                   = {0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18} ;
			int m                     = 12;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = WolfPackDivTwo().calc(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int x[]                   = {0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,8,8,8,8,8,8,8,8,8,8} ;
			int y[]                   = {0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18} ;
			int m                     = 31;
			int expected__            = 573748580;

			clock_t start__           = clock();
			int received__            = WolfPackDivTwo().calc(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			int m                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WolfPackDivTwo().calc(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			int m                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WolfPackDivTwo().calc(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int x[]                   = ;
			int y[]                   = ;
			int m                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WolfPackDivTwo().calc(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), m);
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
// Wolf Sothe is a member of the wolf pack called Grid Walkers.
The N wolves in the pack are numbered 0 through N-1.
(Wolf Sothe is the wolf number 0, but this does not matter.)


At any moment, each wolf is located at some grid point in the plane.
Multiple wolves may share the same grid point.
For each i, the wolf number i is initially located at (x[i],y[i]).
Then there are exactly m rounds in which the wolves move.
In each round, each wolf must move from its current grid point to one of the four adjacent grid points.
More precisely, the wolf located at (i,j) has to move to (i+1,j), (i-1,j), (i,j+1), or (i,j-1).


The wolves have a goal: all of them have to be located at the same grid point after the m-th round.
The grid point at which they all meet is not given - they can choose any grid point.


You are given the vector <int>s x and y, and the int m.
Count and return the number of ways in which the wolves can reach their goal, modulo 1,000,000,007.
Two ways of reaching the goal are different if in some round the same wolf moves in a different direction.
(Equivalently, two ways of reaching the goal are different if there is some number of rounds x and a wolf y such that the grid point of the wolf y after x rounds of the first way differs from the grid point of the wolf y after x rounds of the second way.)

DEFINITION
Class:WolfPackDivTwo
Method:calc
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int calc(vector <int> x, vector <int> y, int m)


CONSTRAINTS
-x will contain between 2 and 50 elements, inclusive.
-y will contain the same number of elements as x.
-m will be between 1 and 50, inclusive.
-Each element of x and y will be between 0 and 50, inclusive.
-The points (x[i],y[i]) will be pairwise distinct.


EXAMPLES

0)
{3,5}
{0,0}
1

Returns: 1

There are two wolves: one at (3,0) and the other at (5,0).
There will be 1 round of movement.
Thus, the meeting point has to be (4,0), wolf 0 has to move by (+1,0) and wolf 1 by (-1,0).
This is the only way of reaching the goal.

1)
{0,1}
{0,0}
1

Returns: 0

In this case the two wolves cannot be at the same grid point at the end. Note that they both have to move.

2)
{0,2,4}
{0,0,0}
2

Returns: 4

In this case, the meeting point has to be (2,0).
Wolf 0 has to go (0,0) -> (1,0) -> (2,0).
Wolf 2 has to go (4,0) -> (3,0) -> (2,0).
Wolf 1 has 4 possible ways of reaching the meeting point: in the first step he can choose any direction, and in the second step he will then choose the opposite direction.

3)
{7,8}
{8,7}
1

Returns: 2

This time there are two possible meeting points. For each of them there is a unique way in which the wolves can reach it.

4)
{0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,8,8,8,8,8,8,8,8,8,8}

{0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18}

12

Returns: 0



5)
{0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,8,8,8,8,8,8,8,8,8,8}

{0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18}

31

Returns: 573748580



*/

// END CUT HERE
