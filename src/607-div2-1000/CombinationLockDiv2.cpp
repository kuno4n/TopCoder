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
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }


const int INF = (1<<29);
int dp[55][450][2];


class CombinationLockDiv2 {
	public:
	int minimumMoves(string S, string T) {
		int n = SZ(S);
        int dif[n];
        REP(i, n) dif[i] = (T[i]-'0'+10 - (S[i]-'0')) % 10;
        
        REP(i, n) REP(j, 450) REP(k, 2) dp[i][j][k] = INF;
        REP(j, 450){
            if(j % 10 == dif[0]) dp[0][j][0] = j;
            if((1000-j) % 10 == dif[0]) dp[0][j][1] = j;
        }
        for(int i = 1; i < n; i++){
            REP(j, 450) REP(k, 450){
                if(k % 10 == dif[i]){
                    chmin(dp[i][k][0], dp[i-1][j][1] + k);
                    if(j > k) chmin(dp[i][k][0], dp[i-1][j][0]);
                    else chmin(dp[i][k][0], dp[i-1][j][0] + (k-j));
                }
                if((1000-k) % 10 == dif[i]){
                    chmin(dp[i][k][1], dp[i-1][j][0] + k);
                    if(j > k) chmin(dp[i][k][1], dp[i-1][j][1]);
                    else chmin(dp[i][k][1], dp[i-1][j][1] + (k-j));
                }
            }
        }
        int res = INF;
        REP(j, 450) REP(k, 2) chmin(res, dp[n-1][j][k]);
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
			string S                  = "123";
			string T                  = "112";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "1";
			string T                  = "7";
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "607";
			string T                  = "607";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "1234";
			string T                  = "4567";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "020";
			string T                  = "909";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string S                  = "4423232218340";
			string T                  = "6290421476245";
			int expected__            = 18;

			clock_t start__           = clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string S                  = ;
			string T                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string S                  = ;
			string T                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string S                  = ;
			string T                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
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
// Andrew has a combination lock.
The lock consists of multiple dials that are placed next to each other.
Each dial contains the digits 0 through 9, in order.
At any moment, exactly one of the digits on each dial is visible.
The string formed by the currently visible digits is called the current combination.

The visible digit on a dial can be changed by rotating the dial up or down.
Rotating the dial up changes 0 to 1, 1 to 2, and so on.
Note that the digits on a dial wrap around: if we rotate up a dial that shows a 9, it will show a 0 again.
Naturally, rotating the dial down changes the digit in the other direction.

We are able to rotate multiple dials at the same time, as long as they are next to each other.
More precisely, in a single turn we can take an arbitrarily long segment of consecutive dials, and rotate all of them one step in the same direction (i.e., either all of them up, or all of them down).

For example, suppose that the current combination is "123".
In one step, we can change it to many different combinations, including "012" (all three dials down), "234" (all three dials up), "133" (middle dial up), and "013" (first two dials down).
Note that we cannot change "123" to "224" in a single step.

You are given two strings: S and T.
S is the current combination, T is the secret combination that unlocks the lock.
That is, to open the lock we need to change S into T by rotating some of the dials.
Return the smallest number of steps needed.

DEFINITION
Class:CombinationLockDiv2
Method:minimumMoves
Parameters:string, string
Returns:int
Method signature:int minimumMoves(string S, string T)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-S will contain the same number of characters as T.
-Each character in S and T will be a digit ('0'-'9').


EXAMPLES

0)
"123"
"112"

Returns: 1

Rotate the last two dials down.

1)
"1"
"7"

Returns: 4

Rotate the dial down 4 times: from 1 to 0, from 0 to 9, from 9 to 8, and from 8 to 7.

2)
"607"
"607"

Returns: 0



3)
"1234"
"4567"

Returns: 3



4)
"020"
"909"

Returns: 2



5)
"4423232218340"
"6290421476245"

Returns: 18



*/

// END CUT HERE
