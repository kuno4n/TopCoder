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

int cnv(char c){
    if(c == 'O') return 0;
    if(c == 'X') return 1;
    return 2;
}

class CaptureFish {
	public:
	int getParity(string fish) {
		int res = 0;
        int n = SZ(fish);
        
        REP(i, n) for(int j = i+1; j <= n; j++){
            bool ok = true;
            int chk1[3], chk2[3]; MSET(chk1, 0), MSET(chk2, 0);
            for(int k = 0; k < i; k++) chk1[cnv(fish[k])]++;
            for(int k = i; k < j; k++) chk2[cnv(fish[k])]++;
            for(int k = j; k < n; k++) chk1[cnv(fish[k])]++;
            ok &= !(chk1[0] > 0 && chk1[1] > 0);
            ok &= !(chk2[0] > 0 && chk2[1] > 0);
            ok &= !(chk1[0] > 0 && chk2[0] > 0);
            ok &= !(chk1[1] > 0 && chk2[1] > 0);
            res ^= ok;
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
			string fish               = "OXOXO";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = CaptureFish().getParity(fish);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string fish               = "OO";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CaptureFish().getParity(fish);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string fish               = "**OX**";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = CaptureFish().getParity(fish);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string fish               = "O***O***O***O";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CaptureFish().getParity(fish);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string fish               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CaptureFish().getParity(fish);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string fish               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CaptureFish().getParity(fish);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string fish               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CaptureFish().getParity(fish);
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
// There are N fish and N+1 buoys in a small pond. Mr. Jeipouju wants to capture some of the fish.

In this problem, regard the pond as a 2-dimensional Cartesian plane (as seen from above). Each fish and each buoy is a point on the plane.
The buoys are lined up on x axis and numbered 0 to N from left to right.
There is exactly one fish between each two neighboring buoys.  The fish are numbered 0 to N-1 from left to right.
For the purpose of this problem we will assume that the fish are staying on their spots without any movement.
The exact coordinates of the fish and the buoys do not matter.  See the following image for clarity.



You are given a string fish with N characters. Each character of fish is either letter 'O' or 'X' or '*'. If fish[i] is 'O', it represents that he must capture fish i. If fish[i] is 'X', he must not capture fish i. If fish[i] is '*', he does not care whether he capture fish i or not.

To capture the fish, Mr. Jeipouju wants to set up a net in the pond so that the net will separate the caught fishes from the uncaught ones.
From above, the net must be a closed curve in our plane.
Furthermore, this closed curve must satisfy the following conditions:


  The net is not allowed to pass through any of the fish.
  The net is not allowed to touch or intersect itself.
  The net may only cross the x axis at points that contain the buoys. The net is not allowed to touch the x axis without crossing it.
  The net must cross the x axis at least twice.
  The fish Mr. Jeipouju wants to capture and the fish he wants not to capture must be separated by the net.
  That is, either all fish marked with 'X' are to be inside the net and all fish marked with 'O' outside, or vice versa. 
  The fish marked '*' may be anywhere, possibly some of them inside and some outside the net.


The following image shows some examples of valid and invalid net placements: 4 nets to the left are valid and 5 nets to the right are invalid.



A net can be encoded into a sequence using the following algorithm:

  Start anywhere on the net, but not on a buoy.
  Walk along the net until you reach your starting point again.
  During the walk, each time you encounter a buoy, write down its number and the halfplane in which you are moving away from the x axis. (The halfplane is "+" if after visiting the buoy your y coordinate is positive and "-" if it is negative.)

In this way you will obtain some sequence (buoy1,side1,...,buoyK,sideK).
Two nets are considered the same if they can be encoded to the same sequence.

Mr. Jeipouju wants to know whether the number of different nets is odd or even.
Your method must return the number of different nets, modulo 2.


DEFINITION
Class:CaptureFish
Method:getParity
Parameters:string
Returns:int
Method signature:int getParity(string fish)


CONSTRAINTS
-fish will contain between 1 and 50 characters, inclusive.
-Each character of fish will be either letter 'O' or 'X' or '*'.
-fish will contain at least one 'O' character.


EXAMPLES

0)
"OXOXO"

Returns: 0

In this case, there are 5 fish. There are 8 ways to separate them.



1)
"OO"

Returns: 1

There is only one valid net and it looks as follows:



Two things to notice:
First, the net does not have to pass through all the buoys.
Second, it is allowed to have no fish at all at either side of the net.

2)
"**OX**"

Returns: 0



3)
"O***O***O***O"

Returns: 1



*/

// END CUT HERE
