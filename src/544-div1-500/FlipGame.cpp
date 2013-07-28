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

class FlipGame {
	public:
	int minOperations(vector <string> board) {
        int h = SZ(board), w = SZ(board[0]);
        int b[h][w];
        REP(i, h) REP(j, w){
            if(board[i][j] == '0') b[i][j] = 0;
            else b[i][j] = 1;
        }
		int cnt = -1;
        int mx;
        do{
            mx = -1;
            cnt++;
            REP(i, h) for(int j = w-1; j >= 0; j--){
                if(b[i][j]) chmax(mx, j);
                if(j <= mx) b[i][j] = (b[i][j]+1) % 2;
            }
        }while(mx >= 0);
        return cnt;
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
			string board[]            = {"1000",
 "1110",
 "1111"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FlipGame().minOperations(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"1111",
 "1111",
 "1111"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FlipGame().minOperations(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"00",
 "00",
 "00"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FlipGame().minOperations(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"00000000",
 "00100000",
 "01000000",
 "00001000",
 "00000000"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = FlipGame().minOperations(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"000000000000001100000000000000",
 "000000000000011110000000000000",
 "000000000000111111000000000000",
 "000000000001111111100000000000",
 "000000000011111111110000000000",
 "000000000111111111111000000000",
 "000000001100111111001100000000",
 "000000011000011110000110000000",
 "000000111100111111001111000000",
 "000001111111111111111111100000",
 "000011111111111111111111110000",
 "000111111111000000111111111000",
 "001111111111100001111111111100",
 "011111111111110011111111111110",
 "111111111111111111111111111111"};
			int expected__            = 29;

			clock_t start__           = clock();
			int received__            = FlipGame().minOperations(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FlipGame().minOperations(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FlipGame().minOperations(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FlipGame().minOperations(vector <string>(board, board + (sizeof board / sizeof board[0])));
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
// Eel Takahashikun is playing a simple game on a rectangular board.


The rectangular board is divided into H x W unit squares. Each unit square contains a 0 or a 1. In each operation, Takahashikun chooses a shortest path along edges of unit squares from the upper-left corner to the lower-right corner, and flips the numbers in all unit squares that are below the chosen path (i.e., changes all 0s into 1s and vice versa).


For example, the following picture shows a valid operation. The squares below the chosen path are highlighted in green.





The operation in the following picture is invalid because the path is not shortest.





You are given the initial state of the board in vector <string> board. The j-th character of the i-th element is the number written in the unit square at row i, column j. Rows are numbered from top to bottom, and columns are numbered from left to right. Return the minimal number of iterations required to change all numbers to 0s.


DEFINITION
Class:FlipGame
Method:minOperations
Parameters:vector <string>
Returns:int
Method signature:int minOperations(vector <string> board)


NOTES
-It is always possible to change all numbers to 0s by a finite number of operations.


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain between 1 and 50 characters, inclusive.
-Each element of board will contain the same number of characters.
-Each character in board will be '0' or '1'.


EXAMPLES

0)
{"1000",
 "1110",
 "1111"}

Returns: 1

Takahashikun can flip all 1s in one operation.


1)
{"1111",
 "1111",
 "1111"}

Returns: 1



2)
{"00",
 "00",
 "00"}

Returns: 0



3)
{"00000000",
 "00100000",
 "01000000",
 "00001000",
 "00000000"}

Returns: 4



4)
{"000000000000001100000000000000",
 "000000000000011110000000000000",
 "000000000000111111000000000000",
 "000000000001111111100000000000",
 "000000000011111111110000000000",
 "000000000111111111111000000000",
 "000000001100111111001100000000",
 "000000011000011110000110000000",
 "000000111100111111001111000000",
 "000001111111111111111111100000",
 "000011111111111111111111110000",
 "000111111111000000111111111000",
 "001111111111100001111111111100",
 "011111111111110011111111111110",
 "111111111111111111111111111111"}

Returns: 29



*/

// END CUT HERE
