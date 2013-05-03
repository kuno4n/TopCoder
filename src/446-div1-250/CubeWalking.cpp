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

string C[3] = {"GREEN", "BLUE", "RED"};

class CubeWalking {
	public:
	string finalPosition(string movement) {
        int col = 0,  dir = 0;
        REP(i, SZ(movement)){
            if(movement[i] == 'L') dir = (dir+3) % 4;
            else if(movement[i] == 'R') dir = (dir+1) % 4;
            else{
                if(col == 0){
                    col = 1;
                    dir = 0;
                }
                else if(col == 1){
                    if(dir == 0){
                        col = 1;
                        dir = 2;
                    }
                    else if(dir == 1){
                        col = 2;
                        dir = 1;
                    }
                    else if(dir == 2){
                        col = 0;
                        dir = 0;
                    }
                    else if(dir == 3){
                        col = 2;
                        dir = 0;
                    }
                }
                else if(col == 2){
                    if(dir == 0){
                        col = 2;
                        dir = 3;
                    }
                    else if(dir == 1){
                        col = 2;
                        dir = 2;
                    }
                    else if(dir == 2){
                        col = 1;
                        dir = 1;
                    }
                    else if(dir == 3){
                        col = 1;
                        dir = 3;
                    }
                    
                }
            }
        }
        return C[col];
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
			string movement           = "LLRR";
			string expected__         = "GREEN";

			clock_t start__           = clock();
			string received__         = CubeWalking().finalPosition(movement);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string movement           = "WWWWWWWWWWWW";
			string expected__         = "GREEN";

			clock_t start__           = clock();
			string received__         = CubeWalking().finalPosition(movement);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string movement           = "WLWRW";
			string expected__         = "RED";

			clock_t start__           = clock();
			string received__         = CubeWalking().finalPosition(movement);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string movement           = "WWLLWRWLWLLRWW";
			string expected__         = "BLUE";

			clock_t start__           = clock();
			string received__         = CubeWalking().finalPosition(movement);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string movement           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CubeWalking().finalPosition(movement);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string movement           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CubeWalking().finalPosition(movement);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string movement           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CubeWalking().finalPosition(movement);
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
Consider the 3x3x3 cube shown above.  There are nine squares on each of its six faces, and each face is colored using the following pattern:
	
		The four corner squares are red.
		The center square is green.
		The remaining four squares are blue.
	
There is a robot standing in the green square of the top face of the cube, facing one of the blue squares.  It receives a sequence of commands.  Each command is one of the following:
	
		'L': Stay in the current square and turn left 90 degrees.
		'R': Stay in the current square and turn right 90 degrees.
		'W': Walk forward in the current direction to the next square.
	
Note that the robot can cross an edge of the cube into another face.  When that happens, the cube will rotate automatically to keep the robot on the top face.
You are given a string movement containing the sequence of commands received by the robot.  The robot will execute all of the commands in order.  Return the color of the robot's final landing square - "RED", "GREEN" or "BLUE" (all quotes for clarity).

DEFINITION
Class:CubeWalking
Method:finalPosition
Parameters:string
Returns:string
Method signature:string finalPosition(string movement)


NOTES
-The answer does not depend on the initial direction of the robot.


CONSTRAINTS
-movement will contain between 1 and 50 characters, inclusive.
-Each character in movement will be 'L', 'R' or 'W'.


EXAMPLES

0)
"LLRR"

Returns: "GREEN"

In this example, the robot only turns left or right without ever moving to a different square.

1)
"WWWWWWWWWWWW"

Returns: "GREEN"

Walking 12 squares forward in the same direction will lead the robot back to its original position.

2)
"WLWRW"

Returns: "RED"



3)
"WWLLWRWLWLLRWW"

Returns: "BLUE"



*/

// END CUT HERE
