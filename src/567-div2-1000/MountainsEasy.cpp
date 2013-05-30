
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

int h, w;
int MOD = 1000000009;


    const int MAX_N = 100;
    LL nCr[MAX_N+1][MAX_N+1];
    
    void makepas(){
        REP(i, MAX_N+1) REP(j, MAX_N+1) nCr[i][j] = -1;
        for(int i=1; i<=MAX_N; i++){
            nCr[i][0] = 1;
            nCr[i][i] = 1;
            for(int j=1; j<i; j++){
                nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % MOD;
            }
        }
    }


long long modPow(long long x, long long y){
    long long r=1, a=x%MOD;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}

vector <string> p;

void erase(int y, int x){
	if(p[y][x] == '.') return;
	if(p[y][x] == 'X') p[y][x] = '.';
	if(y == h-1) return;
	if(x > 0) erase(y+1, x-1);
	if(x < w-1) erase(y+1, x+1);
	erase(y+1, x);
	return;
}

class MountainsEasy {
public:
   int countPlacements( vector <string> picture, int N ) {
	h = SZ(picture), w = SZ(picture[0]); p = picture;
	int peak = 0;
	int Xcnt = 0;
	REP(i, h) REP(j, w) if(p[i][j] == 'X') Xcnt++;
	REP(i, h) REP(j, w) if(p[i][j] == 'X'){
		peak++;
		erase(i, j);
	}
	LL res = 0;
	makepas();
	for(int i = 0; i <= peak; i++) res = (res + nCr[peak][i]*modPow(Xcnt-i, N)*(i&1 ? -1 : 1) + MOD) % MOD;
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
			string picture[]          = {"X.",
 "XX"};
			int N                     = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])), N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string picture[]          = {"X.",
 "XX"};
			int N                     = 2;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])), N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string picture[]          = {"X.X",
 "XXX"};
			int N                     = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])), N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string picture[]          = {"X.X",
 "XXX"};
			int N                     = 3;
			int expected__            = 24;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])), N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string picture[]          = {"......",
 "X..X..",
 "XXXXXX",
 "XXXXXX"};
			int N                     = 3;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])), N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string picture[]          = {"......",
 "X..X..",
 "XXXXXX",
 "XXXXXX"};
			int N                     = 4;
			int expected__            = 300;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])), N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string picture[]          = {"....X...X..",
 "...XXX.XXX.",
 "XXXXXXXXXXX"};
			int N                     = 10;
			int expected__            = 764632413;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])), N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string picture[]          = ;
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])), N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string picture[]          = ;
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])), N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string picture[]          = ;
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])), N);
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
// Manao is developing a simple 2-D computer game. The screen of the game is H pixels high and W pixels wide (1 <= H, W <= 50).

Manao is currently working on the background which should be filled with several mountains. The contents of the screen are stored in an array of characters pix where pix[x, y] gives the contents of the pixel at column x, row y. Both indices are 0-based. Columns are numbered left to right and rows are numbered bottom to top. Character 'X' denotes a part of a mountain and character '.' means that this pixel is not covered by any mountains.

Manao wants to draw N mountains in order to achieve the necessary background. The i-th (0-based index) mountain is described by its peak position (X[i], Y[i]), 0 <= X[i] < W, 0 <= Y[i] < H. In order to draw the mountains, the following pseudocode is used:

Fill all elements of pix with '.' characters.
For 0 <= i < N:
??For 0 <= x < W:
????For 0 <= y <= Y[i] - |x - X[i]|:
??????pix[x, y] := 'X'

For example, consider three mountains with peaks at (1, 1), (2, 2) and (4, 1). Once these mountains are drawn on a screen with H = 3, W = 6, the resulting picture will look as follows:

..X...
.XXXX.
XXXXXX


You are given a vector <string> picture describing the background which Manao wants to obtain. It contains H elements and each element contains W characters. The required value of pix[x, y] is given by x-th character of picture[H-y-1]. In other words, elements of picture list the rows of the screen from top to bottom.

You are also given an int N. Count the number of sequences S of exactly N mountains such that when you draw all mountains from S on the screen as described above, the result will match the given picture. Return this number modulo 1,000,000,009.

Note that the order of mountains in a sequence is important. Sequences containing the same mountains, but in a different order, are distinct. It is guaranteed that there exists at least one way to obtain the given picture by drawing exactly N mountains.

DEFINITION
Class:MountainsEasy
Method:countPlacements
Parameters:vector <string>, int
Returns:int
Method signature:int countPlacements(vector <string> picture, int N)


CONSTRAINTS
-picture will contain between 1 and 50 elements, inclusive.
-Each element of picture will be between 1 and 50 characters long, inclusive.
-All elements of picture will be of the same length.
-Each element of picture will consist of 'X' and '.' characters only.
-N will be between 1 and 50, inclusive.
-picture can be obtained by drawing exactly N mountains according to the rules given in the problem statement.


EXAMPLES

0)
{"X.",
 "XX"}
1

Returns: 1

This is a mountain (0, 1).

1)
{"X.",
 "XX"}
2

Returns: 5

Here one of the mountains is completely covered by the other. The five possible sequences are: 

(0, 1), (0, 1)
(0, 1), (0, 0)
(0, 1), (1, 0)
(0, 0), (0, 1)
(1, 0), (0, 1)


2)
{"X.X",
 "XXX"}
2

Returns: 2

The two possible sequences are:

(0, 1), (2, 1) 
(2, 1), (0, 1) 



3)
{"X.X",
 "XXX"}
3

Returns: 24



4)
{"......",
 "X..X..",
 "XXXXXX",
 "XXXXXX"}
3

Returns: 6

There are three mountains (0, 2), (3, 2), (5, 1) placed in any order.

5)
{"......",
 "X..X..",
 "XXXXXX",
 "XXXXXX"}
4

Returns: 300



6)
{"....X...X..",
 "...XXX.XXX.",
 "XXXXXXXXXXX"}
10

Returns: 764632413



*/

// END CUT HERE
