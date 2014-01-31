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



class PowerOfThree {
	public:
	string ableToGet(int _x, int _y) {
		LL x = _x, y = _y;
        
        while(1){
            x = abs(x);
            y = abs(y);
            if(x == 0 && y == 0) return "Possible";
            int xx = x % 3, yy = y % 3;
            if(xx != 0 && yy != 0) return "Impossible";
            if(xx == 0 && yy == 0) return "Impossible";
            if(xx == 1) x -= 1;
            if(yy == 1) y -= 1;
            if(xx == 2) x += 1;
            if(yy == 2) y += 1;
            x /= 3, y /= 3;
        }
    
    
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
			int x                     = 1;
			int y                     = 3;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x                     = 0;
			int y                     = 2;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x                     = 1;
			int y                     = 9;
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x                     = 3;
			int y                     = 0;
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x                     = 1;
			int y                     = 1;
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int x                     = -6890;
			int y                     = 18252;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int x                     = 1000000000;
			int y                     = -1000000000;
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			int x                     = 0;
			int y                     = 0;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			int x                     = ;
			int y                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int x                     = ;
			int y                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int x                     = ;
			int y                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
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
// Fox Ciel has a robot.
The robot is located on an infinite plane.
At the beginning, the robot starts at the coordinates (0, 0).
The robot can then make several steps.
The steps are numbered starting from 0.

In each step, Ciel must choose one of four directions for the robot: left (x coordinate decreases), right (x coordinate increases), up (y coordinate increases), or down (y coordinate decreases).
In step k, the robot will move 3^k units in the chosen direction.
It is not allowed to skip a step.

You are given ints x and y.
Return "Possible" (quotes for clarity) if it is possible that the robot reaches the point (x,y) after some (possibly zero) steps.
Otherwise, return "Impossible".

DEFINITION
Class:PowerOfThree
Method:ableToGet
Parameters:int, int
Returns:string
Method signature:string ableToGet(int x, int y)


CONSTRAINTS
-x will be between -1,000,000,000 and 1,000,000,000, inclusive.
-y will be between -1,000,000,000 and 1,000,000,000, inclusive.


EXAMPLES

0)
1
3

Returns: "Possible"

In step 0 Ciel will send the robot right to (1,0). In step 1 she will send it up to (1,3).

1)
0
2

Returns: "Possible"

The robot will move from (0,0) down to (0,-1) and then up to (0,2).

2)
1
9

Returns: "Impossible"

Note that it is not allowed to move the robot right in step 0, skip step 1, and then move the robot up in step 2.

3)
3
0

Returns: "Impossible"



4)
1
1

Returns: "Impossible"



5)
-6890
18252

Returns: "Possible"



6)
1000000000
-1000000000

Returns: "Impossible"



7)
0
0

Returns: "Possible"



*/

// END CUT HERE
