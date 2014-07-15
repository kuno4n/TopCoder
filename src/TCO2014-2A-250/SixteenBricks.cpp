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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 


int dp[1<<16];

int bitcnt(LL n)
{
    int c;
    for(c=0;n!=0;c++,n&=n-1) ;
    return c;
}

int add(int mask, int a, int h){
    int x = a/4;
    int y = a%4;
    int res = 1;
    if(x == 0 || !(mask & (1<<((x-1)*4+y)))) res += h;
    else res -= h;
    if(x == 3 || !(mask & (1<<((x+1)*4+y)))) res += h;
    else res -= h;
    if(y == 0 || !(mask & (1<<(x*4+(y-1))))) res += h;
    else res -= h;
    if(y == 3 || !(mask & (1<<(x*4+(y+1))))) res += h;
    else res -= h;
    return res;
}


class SixteenBricks {
	public:
	int maximumSurface(vector <int> h) {
		sort(ALL(h));
        reverse(ALL(h));
        MSET(dp, -1);
        dp[0] = 0;
        
        FOR(i, 1, (1<<16)){
            int tar = h[bitcnt(i)-1];
            REP(a, 16) if(i & (1<<a)) chmax(dp[i], dp[i-(1<<a)] + add(i, a, tar));
        }
        return dp[(1<<16)-1];
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
			int height[]              = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			int expected__            = 32;

			clock_t start__           = clock();
			int received__            = SixteenBricks().maximumSurface(vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int height[]              = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2};
			int expected__            = 64;

			clock_t start__           = clock();
			int received__            = SixteenBricks().maximumSurface(vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int height[]              = {77, 78, 58, 34, 30, 20, 8, 71, 37, 74, 21, 45, 39, 16, 4, 59} ;
			int expected__            = 1798;

			clock_t start__           = clock();
			int received__            = SixteenBricks().maximumSurface(vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int height[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SixteenBricks().maximumSurface(vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int height[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SixteenBricks().maximumSurface(vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int height[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SixteenBricks().maximumSurface(vector <int>(height, height + (sizeof height / sizeof height[0])));
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
// You have 16 bricks. Each brick has the shape of a rectangular box. You are given a vector <int> height. For each i, one of your bricks has dimensions 1 x 1 x height[i].

You also have an opaque table. You are going to place your 16 bricks onto the table in a specific way. You are not allowed to rotate the bricks while placing them: the dimension given in height must always be vertical. On the table, there is a 4 x 4 grid of squares. You have to place exactly one of your bricks onto each of the squares.

After you place all the bricks, we will look at the solid formed by them. We are interested in the visible surface area of the solid. Note that the bottom sides of your bricks are not a part of the visible surface, as they stand on the table. Also, adjacent bricks always touch each other and the parts where they touch are not visible.

Different arrangements of bricks may lead to different visible surfaces. Return the largest possible visible surface area.


DEFINITION
Class:SixteenBricks
Method:maximumSurface
Parameters:vector <int>
Returns:int
Method signature:int maximumSurface(vector <int> height)


CONSTRAINTS
-height will contain exactly 16 elements.
-Each element of height will be between 1 and 100, inclusive.


EXAMPLES

0)
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

Returns: 32

All your bricks look the same.
The only solid you can construct is a 1 x 4 x 4 box.
The bottom side of the box is not visible, the other five sides are.
The total visible surface area is 4*4 + 4*(1*4) = 32.

1)
{1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2}

Returns: 64

In order to maximize the visible surface area, you should produce a configuration in which no two bricks with height 2 share a common face.

2)
{77, 78, 58, 34, 30, 20, 8, 71, 37, 74, 21, 45, 39, 16, 4, 59}


Returns: 1798



*/

// END CUT HERE
