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
#define MSET(x,a) memset((x), (a), (int)sizeof(x))
#define VI vector < int >
#define LL long long 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = " << A << endl

int mx[16] = {-1, 0, 1, 1, 1, 0,-1,-1, -1, 1, 2, 2, 1,-1,-2,-2};
int my[16] = {-1,-1,-1, 0, 1, 1, 1, 0, -2,-2,-1, 1, 2, 2, 1,-1};

class ChessMetric {
	public:
	long long howMany(int size, vector <int> start, vector <int> end, int numMoves) {
		LL now[110][110];
        LL next[110][110];
        REP(i, 110){
            REP(j, 110){
                now[i][j] = 0;
                next[i][j] = 0;
            }
        }
        now[start[0]][start[1]] = 1;
        
        REP(n, numMoves){
            MSET(next, 0);
            REP(i, size){
                REP(j, size){
                    if(now[i][j] == 0) continue;
                    REP(k, 16) {
                        int ly = i+my[k];
                        int lx = j+mx[k];
                        if(ly<0 || size<=ly || lx<0 || size<=lx) continue;
                        next[ly][lx] += now[i][j];
                    }
                }
            }
            REP(i, size){
                REP(j, size){
                    now[i][j] = next[i][j];
                }
            }
        }
        
        return now[end[0]][end[1]];
        
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int size                  = 3;
			int start[]               = {0,0};
			int end[]                 = {1,0};
			int numMoves              = 1;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = ChessMetric().howMany(size, vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(end, end + (sizeof end / sizeof end[0])), numMoves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int size                  = 3;
			int start[]               = {0,0};
			int end[]                 = {1,2};
			int numMoves              = 1;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = ChessMetric().howMany(size, vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(end, end + (sizeof end / sizeof end[0])), numMoves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int size                  = 3;
			int start[]               = {0,0};
			int end[]                 = {2,2};
			int numMoves              = 1;
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = ChessMetric().howMany(size, vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(end, end + (sizeof end / sizeof end[0])), numMoves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int size                  = 3;
			int start[]               = {0,0};
			int end[]                 = {0,0};
			int numMoves              = 2;
			long long expected__      = 5;

			clock_t start__           = clock();
			long long received__      = ChessMetric().howMany(size, vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(end, end + (sizeof end / sizeof end[0])), numMoves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int size                  = 100;
			int start[]               = {0,0};
			int end[]                 = {0,99};
			int numMoves              = 50;
			long long expected__      = 243097320072600LL;

			clock_t start__           = clock();
			long long received__      = ChessMetric().howMany(size, vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(end, end + (sizeof end / sizeof end[0])), numMoves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int size                  = ;
			int start[]               = ;
			int end[]                 = ;
			int numMoves              = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = ChessMetric().howMany(size, vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(end, end + (sizeof end / sizeof end[0])), numMoves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int size                  = ;
			int start[]               = ;
			int end[]                 = ;
			int numMoves              = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = ChessMetric().howMany(size, vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(end, end + (sizeof end / sizeof end[0])), numMoves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int size                  = ;
			int start[]               = ;
			int end[]                 = ;
			int numMoves              = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = ChessMetric().howMany(size, vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(end, end + (sizeof end / sizeof end[0])), numMoves);
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
// Suppose you had an n by n chess board and a super piece called a kingknight.  Using only one move the kingknight denoted 'K' below can reach any of the spaces denoted 'X' or 'L' below:
   .......
   ..L.L..
   .LXXXL.
   ..XKX..
   .LXXXL.
   ..L.L..
   .......

In other words, the kingknight can move either one space in any direction (vertical, horizontal or diagonally) or can make an 'L' shaped move.  An 'L' shaped move involves moving 2 spaces horizontally then 1 space vertically or 2 spaces vertically then 1 space horizontally.  In the drawing above, the 'L' shaped moves are marked with 'L's whereas the one space moves are marked with 'X's.  In addition, a kingknight may never jump off the board.

Given the size of the board, the start position of the kingknight and the end position of the kingknight, your method will return how many possible ways there are of getting from start to end in exactly numMoves moves.  start and finish are vector <int>s each containing 2 elements.  The first element will be the (0-based) row position and the second will be the (0-based) column position.  Rows and columns will increment down and to the right respectively.  The board itself will have rows and columns ranging from 0 to size-1 inclusive.  

Note, two ways of getting from start to end are distinct if their respective move sequences differ in any way.  In addition, you are allowed to use spaces on the board (including start and finish) repeatedly during a particular path from start to finish.  We will ensure that the total number of paths is less than or equal to 2^63-1 (the upper bound for a long long).

DEFINITION
Class:ChessMetric
Method:howMany
Parameters:int, vector <int>, vector <int>, int
Returns:long long
Method signature:long long howMany(int size, vector <int> start, vector <int> end, int numMoves)


NOTES
-For C++ users: long long is a 64 bit datatype and is specific to the GCC compiler.


CONSTRAINTS
-size will be between 3 and 100 inclusive
-start will contain exactly 2 elements
-finish will contain exactly 2 elements
-Each element of start and finish will be between 1 and size-1 inclusive
-numMoves will be between 1 and 50 inclusive
-The total number of paths will be at most 2^63-1.


EXAMPLES

0)
3
{0,0}
{1,0}
1

Returns: 1

Only 1 way to get to an adjacent square in 1 move

1)
3
{0,0}
{1,2}
1

Returns: 1

A single L-shaped move is the only way

2)
3
{0,0}
{2,2}
1

Returns: 0

Too far for a single move

3)
3
{0,0}
{0,0}
2

Returns: 5

Must count all the ways of leaving and then returning to the corner

4)
100
{0,0}
{0,99}
50

Returns: 243097320072600

*/

// END CUT HERE
