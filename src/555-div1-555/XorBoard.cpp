
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


int MOD = 555555555;

void add(LL &a, LL b){
	a = (a + b) % MOD;
}
void mul(LL &a, LL b){
	a = (a * b) % MOD;
}

int C[3200][3200];

void makepas(){
    REP(i, 3200) REP(j, 3200) C[i][j] = 0;
    C[0][0] = 1;
    for(int i=1; i < 3200; i++){
        C[i][0] = 1;
        C[i][i] = 1;
        for(int j=1; j<i; j++){
            C[i][j] = ((LL)C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }
}



class XorBoard {
public:
   int count( int H, int W, int Rcount, int Ccount, int S ) {
	makepas();
	LL res = 0;
	for(int r = 0; r <= H; r++) for(int c = 0; c <= W; c++){
		if(r*W + c*H - r*c*2 != S) continue;
		if(r > Rcount || c > Ccount || ((Rcount-r)&1) || ((Ccount-c)&1)) continue;
		LL tmp = 1;
		int rr = (Rcount-r)/2, cc = (Ccount-c)/2;
		mul(tmp, C[H][r]);
		mul(tmp, C[rr+H-1][H-1]);
		mul(tmp, C[W][c]);
		mul(tmp, C[cc+W-1][W-1]);
		add(res, tmp);
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
			int H                     = 2;
			int W                     = 2;
			int Rcount                = 2;
			int Ccount                = 2;
			int S                     = 4;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = XorBoard().count(H, W, Rcount, Ccount, S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int H                     = 2;
			int W                     = 2;
			int Rcount                = 0;
			int Ccount                = 0;
			int S                     = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = XorBoard().count(H, W, Rcount, Ccount, S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int H                     = 10;
			int W                     = 20;
			int Rcount                = 50;
			int Ccount                = 40;
			int S                     = 200;
			int expected__            = 333759825;

			clock_t start__           = clock();
			int received__            = XorBoard().count(H, W, Rcount, Ccount, S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int H                     = 1200;
			int W                     = 1000;
			int Rcount                = 800;
			int Ccount                = 600;
			int S                     = 4000;
			int expected__            = 96859710;

			clock_t start__           = clock();
			int received__            = XorBoard().count(H, W, Rcount, Ccount, S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int H                     = 555;
			int W                     = 555;
			int Rcount                = 555;
			int Ccount                = 555;
			int S                     = 5550;
			int expected__            = 549361755;

			clock_t start__           = clock();
			int received__            = XorBoard().count(H, W, Rcount, Ccount, S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int H                     = ;
			int W                     = ;
			int Rcount                = ;
			int Ccount                = ;
			int S                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = XorBoard().count(H, W, Rcount, Ccount, S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int H                     = ;
			int W                     = ;
			int Rcount                = ;
			int Ccount                = ;
			int S                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = XorBoard().count(H, W, Rcount, Ccount, S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int H                     = ;
			int W                     = ;
			int Rcount                = ;
			int Ccount                = ;
			int S                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = XorBoard().count(H, W, Rcount, Ccount, S);
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
// Fox Jiro has a rectangular grid with H rows and W columns (i.e., the grid has H*W cells in total). Initially, each cell in the grid contained the character '0'.

A row flip is an operation in which Jiro picks a row of the grid, and in that row he changes all '0's to '1's and vice versa.
Similarly, a column flip is an operation in which Jiro does the same to a column of the grid.
Jiro took the grid that contained '0's everywhere.
He performed a row flip Rcount times, and then a column flip Ccount times.
(It is possible that Jiro flipped the same row or column multiple times.)
At the end, Jiro noticed that there are exactly S '1's in the grid.

You are given the ints H, W, Rcount, Ccount, and S.
We are interested in the number of different ways in which Jiro could have flipped the rows and columns of the grid.
Two ways of flipping are considered different if there is a row or a column that was flipped a different number of times.
(That is, the order in which the rows and columns are flipped does not matter.)
Return the number of different ways of flipping that match the given situation, modulo 555,555,555.


DEFINITION
Class:XorBoard
Method:count
Parameters:int, int, int, int, int
Returns:int
Method signature:int count(int H, int W, int Rcount, int Ccount, int S)


CONSTRAINTS
-H will be between 1 and 1,555, inclusive.
-W will be between 1 and 1,555, inclusive.
-Rcount will be between 0 and 1,555, inclusive.
-Ccount will be between 0 and 1,555, inclusive.
-S will be between 0 and H*W, inclusive.


EXAMPLES

0)
2
2
2
2
4

Returns: 4

In two of the four ways, Jiro flips each row once, and then the same column twice.
In the other two ways he first flips the same row twice, and then each column once.

1)
2
2
0
0
1

Returns: 0

Without any flips, all cells still contain '0's, so S=1 is impossible.

2)
10
20
50
40
200

Returns: 333759825

Rcount and Ccount may be greater than H and W.

3)
1200
1000
800
600
4000

Returns: 96859710



4)
555
555
555
555
5550

Returns: 549361755



*/

// END CUT HERE
