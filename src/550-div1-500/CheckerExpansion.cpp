
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

int calc(LL x, LL y, LL a){
	if(a == 1){
		if(x == 0 && y == 0) return 1;
		if(x == 2 && y == 0) return 2;
		if(x == 1 && y == 1) return 2;
		return 0;
	}
	if(y >= a){
		if(x < a || x >= a*3) return 0;
		return calc(x-a, y-a, a/2);
	}
	else{
		if(x < a*2) return calc(x, y, a/2);
		else return calc(x-a*2, y, a/2);
	}
}

class CheckerExpansion {
public:
   vector <string> resultAfter( long long t, long long x0, long long y0, int w, int h ) {
	int res[w][h]; MSET(res, -1);
	REP(dx, w) REP(dy, h){
		LL x = x0 + dx, y = y0 + dy;
		res[dx][dy] = (x+y > (t-1)*2 ? 0 : calc(x0+dx, y0+dy, (1LL<<55)));
	}
	vector<string> ans;
	REP(i, h){
		string s;
		REP(j, w){
			if(res[j][h-i-1] == 0) s.push_back('.');
			else if(res[j][h-i-1] == 1) s.push_back('A');
			else s.push_back('B');
		}
		ans.push_back(s);
	}
	return ans;
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) { 
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
			long long t               = 1;
			long long x0              = 0;
			long long y0              = 0;
			int w                     = 4;
			int h                     = 4;
			string expected__[]       = {"....", "....", "....", "A..." };

			clock_t start__           = clock();
			vector <string> received__ = CheckerExpansion().resultAfter(t, x0, y0, w, h);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			long long t               = 5;
			long long x0              = 4;
			long long y0              = 1;
			int w                     = 3;
			int h                     = 4;
			string expected__[]       = {"A..", "...", "B..", ".B." };

			clock_t start__           = clock();
			vector <string> received__ = CheckerExpansion().resultAfter(t, x0, y0, w, h);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			long long t               = 1024;
			long long x0              = 1525;
			long long y0              = 512;
			int w                     = 20;
			int h                     = 2;
			string expected__[]       = {"B...B...B...........", ".B.A.B.A.B.........." };

			clock_t start__           = clock();
			vector <string> received__ = CheckerExpansion().resultAfter(t, x0, y0, w, h);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			long long t               = 53;
			long long x0              = 85;
			long long y0              = 6;
			int w                     = 5;
			int h                     = 14;
			string expected__[]       = {".....", ".....", "B....", ".B.A.", ".....", ".....", ".....", ".....", ".....", ".....", "B....", ".B...", "..B..", ".A.B." };

			clock_t start__           = clock();
			vector <string> received__ = CheckerExpansion().resultAfter(t, x0, y0, w, h);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			long long t               = ;
			long long x0              = ;
			long long y0              = ;
			int w                     = ;
			int h                     = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = CheckerExpansion().resultAfter(t, x0, y0, w, h);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			long long t               = ;
			long long x0              = ;
			long long y0              = ;
			int w                     = ;
			int h                     = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = CheckerExpansion().resultAfter(t, x0, y0, w, h);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			long long t               = ;
			long long x0              = ;
			long long y0              = ;
			int w                     = ;
			int h                     = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = CheckerExpansion().resultAfter(t, x0, y0, w, h);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
// Alice and Bob are playing a game on an infinite grid. The grid is initially empty. Alice and Bob each have an infinite supply of checkers. Alice's checkers are red, Bob's are blue. In the first turn, Alice places one of her red checkers into the cell (0,0). The game continues by Bob and Alice taking alternate turns. In each turn, the current player places their checkers into some empty cells. The player must always add all the checkers that can be added in their turn by repeatedly applying the following rules:

If cell (x-1,y-1) contains a checker of the other player and cell (x-2,y) is empty, add your checker into the cell (x,y).
If cell (x-2,y) contains a checker of the other player and cell (x-1,y-1) is empty, add your checker into the cell (x,y).

Bob has asked you to simulate the game so that he can understand it better. You are given long longs
t, x0 and y0 and ints w and h. Return a vector <string> containing h elements of w characters each. The j-th character of the i-th element of your return value will represent the contents of cell at x=x0+j and y=y0+h-i-1 after t turns. The character representing a particular cell should be 'A' (quotes for clarity) if it contains one of Alice's checkers, 'B' if it contains one of Bob's checkers and '.' if it is empty. 

DEFINITION
Class:CheckerExpansion
Method:resultAfter
Parameters:long long, long long, long long, int, int
Returns:vector <string>
Method signature:vector <string> resultAfter(long long t, long long x0, long long y0, int w, int h)


CONSTRAINTS
-t will be between 1 and 1000000000000 (10^12), inclusive.
-x0 and y0 will each be between 0 and 1000000000000 (10^12), inclusive.
-w and h will each be between 1 and 50, inclusive. 


EXAMPLES

0)
1
0
0
4
4

Returns: {"....", "....", "....", "A..." }

This is the initial turn.

1)
5
4
1
3
4

Returns: {"A..", "...", "B..", ".B." }

The checker that appears at the top row of this rectangle was placed by Alice just at the fifth turn.

2)
1024
1525
512
20
2

Returns: {"B...B...B...........", ".B.A.B.A.B.........." }



3)
53
85
6
5
14

Returns: {".....", ".....", "B....", ".B.A.", ".....", ".....", ".....", ".....", ".....", ".....", "B....", ".B...", "..B..", ".A.B." }



*/

// END CUT HERE
