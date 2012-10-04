#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset((x), (a), (int)sizeof(x))
#define VI vector < int >
#define LL long long 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FIT(it,v) for(typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define OUT(A) cout << #A << " = " << A << endl

class PairingPawns {
	public:
	int savedPawnCount(vector <int> start) {
		for(int i = SZ(start)-1; i>0; i--) start[i-1] += start[i]/2;
        return start[0];
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
			int start[]               = {0,2};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PairingPawns().savedPawnCount(vector <int>(start, start + (sizeof start / sizeof start[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int start[]               = {10,3};
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = PairingPawns().savedPawnCount(vector <int>(start, start + (sizeof start / sizeof start[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int start[]               = {0,0,0,8};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PairingPawns().savedPawnCount(vector <int>(start, start + (sizeof start / sizeof start[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int start[]               = {0,1,1,2};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PairingPawns().savedPawnCount(vector <int>(start, start + (sizeof start / sizeof start[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int start[]               = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,123456};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PairingPawns().savedPawnCount(vector <int>(start, start + (sizeof start / sizeof start[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int start[]               = {1000,2000,3000,4000,5000,6000,7000,8000};
			int expected__            = 3921;

			clock_t start__           = clock();
			int received__            = PairingPawns().savedPawnCount(vector <int>(start, start + (sizeof start / sizeof start[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int start[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PairingPawns().savedPawnCount(vector <int>(start, start + (sizeof start / sizeof start[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int start[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PairingPawns().savedPawnCount(vector <int>(start, start + (sizeof start / sizeof start[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int start[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PairingPawns().savedPawnCount(vector <int>(start, start + (sizeof start / sizeof start[0])));
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
"Pairing pawns" is a game played on a strip of paper, divided into N cells. The cells are labeled 0 through N-1. Each cell may contain an arbitrary number of pawns.


You are given a vector <int> start with N elements. For each i, element i of start is the initial number of pawns on cell i.


The goal of the game is to bring as many pawns as possible to cell 0.


The only valid move looks as follows:


Find a pair of pawns that share the same cell X (other than cell 0).
Remove the pair of pawns from cell X.
Add a single new pawn into the cell X-1.


You may make as many moves as you wish, in any order.


Return the maximum number of pawns that can be in cell 0 at the end of the game.


DEFINITION
Class:PairingPawns
Method:savedPawnCount
Parameters:vector <int>
Returns:int
Method signature:int savedPawnCount(vector <int> start)


NOTES
-You may assume that the answer will always fit into an int.
-Note that you are only given the vector <int> start. The number of cells N can be determined as the length of start.


CONSTRAINTS
-start will contain between 1 and 20 elements, inclusive.
-Each element of start will be between 0 and 1,000,000, inclusive.


EXAMPLES

0)
{0,2}

Returns: 1

There are two pawns on cell 1. You can remove them both and place a pawn onto cell 0.

1)
{10,3}

Returns: 11

There are 10 pawns already on cell 0. You can add another one by removing two pawns from cell 1. Note that at the end of the game cell 1 will still contain one pawn that cannot be used anymore.

2)
{0,0,0,8}

Returns: 1

After 7 moves you can get a single pawn to cell 0. The rest of the board will be empty.

3)
{0,1,1,2}

Returns: 1

Again, a single pawn can reach the leftmost cell.

4)
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,123456}

Returns: 0

That's a lot of pawns! But they are too far away. In this case it is impossible for a pawn to reach cell 0.

5)
{1000,2000,3000,4000,5000,6000,7000,8000}

Returns: 3921



*/

// END CUT HERE
