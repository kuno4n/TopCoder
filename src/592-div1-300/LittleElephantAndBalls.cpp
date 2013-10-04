
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
#include <numeric>
//#include "cout.h"

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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

class LittleElephantAndBalls {
public:
   int getNumber( string S ) {
	string RGB = "RGB";
	int cnt[3]; MSET(cnt, 0);
	int res = 0;
	REP(i, SZ(S)){
		int a; REP(j, 3) if(RGB[j] == S[i]) a = j;
		REP(j, 3) res += min(2, cnt[j]);
		cnt[a]++;
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
			string S                  = "RGB";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = LittleElephantAndBalls().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "RGGRBBB";
			int expected__            = 21;

			clock_t start__           = clock();
			int received__            = LittleElephantAndBalls().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "RRRGBRR";
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = LittleElephantAndBalls().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "RRRR";
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = LittleElephantAndBalls().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "GGRRRGR";
			int expected__            = 18;

			clock_t start__           = clock();
			int received__            = LittleElephantAndBalls().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string S                  = "G";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = LittleElephantAndBalls().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LittleElephantAndBalls().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LittleElephantAndBalls().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LittleElephantAndBalls().getNumber(S);
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
Little Elephant from the Zoo of Lviv likes balls.
He has some balls that he wants to arrange into a row on the table.
Each of those balls has one of three possible colors: red, green, or blue.




You are given a string S.
This string represents all of the balls Little Elephant has, in the order in which he will be placing them onto the table.
Red, green, and blue balls are represented by the characters 'R', 'G', and 'B', respectively.
Each time Little Elephant places a new ball onto the table, he may add it anywhere into the row of already placed balls.




Additionally, each time Little Elephant adds a ball to the table, he scores some points (possibly zero).
The number of points is calculated as follows:

If this is the first ball being placed on the table, there are 0 points for it.
If he adds the current ball to one of the ends of the row, the number of points scored is equal to the number of different colors of the balls on the table, excluding the current ball.
If he adds the current ball between two other balls, the number of points scored is equal to the number of different colors of the balls before the current ball, plus the number of different colors of the balls after the current ball.





For example, suppose that the balls currently on the table form the row "GBBG". 
Little Elephant now wants to add a new red ball ('R').
One of the options is to add it to the beginning.
This scores 2 points and produces the row "RGBBG".
Another option is to add it between "GBB" and "G".
There are 2 distinct colors in "GBB" and 1 in "G", so this move is worth 2+1 = 3 points.
This move produces the row "GBBRG".




Return the maximum total number of points that Little Elephant can earn for placing the balls onto the table.


DEFINITION
Class:LittleElephantAndBalls
Method:getNumber
Parameters:string
Returns:int
Method signature:int getNumber(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-S will consist only of characters 'R', 'G' and 'B'.


EXAMPLES

0)
"RGB"

Returns: 3

Any strategy is optimal here. Each strategy scores 0+1+2 = 3 points.

1)
"RGGRBBB"

Returns: 21



2)
"RRRGBRR"

Returns: 16



3)
"RRRR"

Returns: 5



4)
"GGRRRGR"

Returns: 18



5)
"G"

Returns: 0



*/

// END CUT HERE
