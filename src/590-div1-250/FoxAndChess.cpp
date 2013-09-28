
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

class FoxAndChess {
public:
   string ableToMove( string begin, string target ) {
	vector < PII > a, b;
	int n = SZ(begin);
	REP(i, n) if(begin[i] != '.'){
		PII pii = make_pair(i, (begin[i] == 'L' ? 0 : 1));
		a.PB(pii);
	}
	REP(i, n) if(target[i] != '.'){
		PII pii = make_pair(i, (target[i] == 'L' ? 0 : 1));
		b.PB(pii);
	}
	if(SZ(a) != SZ(b)) return "Impossible";
	REP(i, SZ(a)) if(a[i].second != b[i].second) return "Impossible";
	REP(i, SZ(a)){
		if(a[i].second == 0 && a[i].first < b[i].first)  return "Impossible";
		if(a[i].second == 1 && a[i].first > b[i].first)  return "Impossible";
	}
	
	return "Possible";
	
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
			string begin              = "R...";
			string target             = "..R.";
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = FoxAndChess().ableToMove(begin, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string begin              = "..R.";
			string target             = "R...";
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = FoxAndChess().ableToMove(begin, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string begin              = ".L.R.R.";
			string target             = "L...R.R";
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = FoxAndChess().ableToMove(begin, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string begin              = ".L.R.";
			string target             = ".R.L.";
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = FoxAndChess().ableToMove(begin, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string begin              = "LRLLRLRLLRLLRLRLRL";
			string target             = "LRLLRLRLLRLLRLRLRL";
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = FoxAndChess().ableToMove(begin, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string begin              = "L";
			string target             = ".";
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = FoxAndChess().ableToMove(begin, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string begin              = ;
			string target             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndChess().ableToMove(begin, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string begin              = ;
			string target             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndChess().ableToMove(begin, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string begin              = ;
			string target             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndChess().ableToMove(begin, target);
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
// Fox Ciel is playing a game with some chess pawns and a strip of paper.
The strip of paper is divided into a row of cells.
Each cell can contain at most one pawn.
The white pawns will be denoted 'R', because they are only allowed to move to the right.
The black pawns will be denoted 'L', because they are only allowed to move to the left.


You are given a string begin that describes the current state of the strip: 'R' and 'L' are cells with corresponding pawns, and '.' are empty cells.


You are now allowed to make some moves (as many as you wish, possibly zero).
In each move you may either take a 'R' pawn and move it one cell to the right, or take a 'L' pawn and move it one cell to the left.
Of course, both types of moves are only valid if the destination cell is currently empty.
Pawns are not allowed to move out of bounds.


You are also given a string target that represents the desired state of the strip.
If it is possible to reach target from begin by making some valid moves, return "Possible" (quotes for clarity), otherwise return "Impossible".

DEFINITION
Class:FoxAndChess
Method:ableToMove
Parameters:string, string
Returns:string
Method signature:string ableToMove(string begin, string target)


CONSTRAINTS
-begin will contain between 1 and 50 elements, inclusive.
-begin and target will contain the same number of elements.
-Each character in begin and target will be one of '.', 'L' and 'R'.


EXAMPLES

0)
"R..."
"..R."

Returns: "Possible"

You have to move the only pawn to the right twice.

1)
"..R."
"R..."

Returns: "Impossible"

Here target cannot be reached because the only pawn is only allowed to move to the right.

2)
".L.R.R."
"L...R.R"

Returns: "Possible"



3)
".L.R."
".R.L."

Returns: "Impossible"



4)
"LRLLRLRLLRLLRLRLRL"
"LRLLRLRLLRLLRLRLRL"

Returns: "Possible"



5)
"L"
"."

Returns: "Impossible"



*/

// END CUT HERE
