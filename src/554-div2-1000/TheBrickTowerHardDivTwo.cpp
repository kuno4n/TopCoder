
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

LL MOD = 1234567891LL;

LL dp[50][1<<8][8];

void add(LL &a, LL b){
	a = (a+b) % MOD;
}

class TheBrickTowerHardDivTwo {
public:
   int find( int C, int K, int H ) {
	MSET(dp, 0);
	
	REP(a, C) REP(b, C) REP(c, C) REP(d, C){
		int k = (a==b) + (a==c) + (b==d) + (c==d);
		if(k <= K) dp[1][a|(b<<2)|(c<<4)|(d<<6)][k] = 1;
	}
	for(int h = 2; h <= H; h++) REP(a, C) REP(b, C) REP(c, C) REP(d, C) for(int k = 0 ; k <= K; k++){
		REP(aa, C) REP(bb, C) REP(cc, C) REP(dd, C){
			int kk = k + (aa==bb) + (aa==cc) + (bb==dd) + (cc==dd) + (a==aa) + (b==bb) + (c==cc) + (d==dd);
			if(kk <= K) add(dp[h][aa|(bb<<2)|(cc<<4)|(dd<<6)][kk], dp[h-1][a|(b<<2)|(c<<4)|(d<<6)][k]);
		}
	}
	
	LL res = 0;
	for(int i = 1; i <= H; i++) for(int j = 0; j < (1<<8); j++) for(int k = 0; k <= K; k++)
		add(res, dp[i][j][k]);
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
			int C                     = 2;
			int K                     = 0;
			int H                     = 2;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TheBrickTowerHardDivTwo().find(C, K, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int C                     = 1;
			int K                     = 7;
			int H                     = 19;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheBrickTowerHardDivTwo().find(C, K, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int C                     = 2;
			int K                     = 3;
			int H                     = 1;
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = TheBrickTowerHardDivTwo().find(C, K, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int C                     = 4;
			int K                     = 7;
			int H                     = 47;
			int expected__            = 1008981254;

			clock_t start__           = clock();
			int received__            = TheBrickTowerHardDivTwo().find(C, K, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int C                     = ;
			int K                     = ;
			int H                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheBrickTowerHardDivTwo().find(C, K, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int C                     = ;
			int K                     = ;
			int H                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheBrickTowerHardDivTwo().find(C, K, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int C                     = ;
			int K                     = ;
			int H                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheBrickTowerHardDivTwo().find(C, K, H);
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
John and Brus are building towers using toy bricks.
They have an unlimited supply of bricks of C different colors.
Each brick is a 1x1x1 cube.
A tower of height X is a 2x2xX rectangular prism, built using 4X bricks.



John and Brus want their towers to look nice.
A tower is nice if it has the following two properties:

There are at most K pairs of neighboring bricks with the same color. (Two bricks are neighboring if they share a common side.)
The height of the tower is between 1 and H, inclusive.




You are given the ints C, K, and H.
Return the number of nice towers, modulo 1,234,567,891.



DEFINITION
Class:TheBrickTowerHardDivTwo
Method:find
Parameters:int, int, int
Returns:int
Method signature:int find(int C, int K, int H)


CONSTRAINTS
-C will be between 1 and 4, inclusive.
-K will be between 0 and 7, inclusive.
-H will be between 1 and 47, inclusive.


EXAMPLES

0)
2
0
2

Returns: 4

No two neighboring bricks may share the same color.
As we only have two colors, the entire tower must be colored like a chessboard.
There are two such towers of height 1, and two of height 2.


1)
1
7
19

Returns: 1

Only one tower of height 1 is acceptable here.


2)
2
3
1

Returns: 14

There are 16 possible towers of height 1.
If all bricks share the same color, the tower is not nice.
There are two such towers.
Each of the remaining 14 towers is nice.


3)
4
7
47

Returns: 1008981254

*/

// END CUT HERE
