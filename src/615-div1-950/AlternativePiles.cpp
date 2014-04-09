#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <fstream>
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

const int MOD = 1000000007;
void add(LL &a, LL b){
    a = (a + b) % MOD;
}
LL dp[5010][55][55];

class AlternativePiles {
public:
   int count( string C, int M ) {
       MSET(dp, 0);
       dp[0][0][0] = 1;
       REP(i, SZ(C)) REP(j, M+1) REP(k, M){
           switch(C[i]){
                   case 'B':
                     add(dp[i+1][j][k], dp[i][j][k]);
                     break;
                   case 'R':
                     if(j < M) add(dp[i+1][j+1][k], dp[i][j][k]);
                     break;
                   case 'G':
                     if(j > 0) add(dp[i+1][j-1][(k+1)%M], dp[i][j][k]);
                     break;
                   default:
                     add(dp[i+1][j][k], dp[i][j][k]);
                     if(j < M) add(dp[i+1][j+1][k], dp[i][j][k]);
                     if(j > 0) add(dp[i+1][j-1][(k+1)%M], dp[i][j][k]);
                     break;
           }
       }
       return dp[SZ(C)][0][0];
       
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
			string C                  = "WRGWWRGW";
			int M                     = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = AlternativePiles().count(C, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string C                  = "RRGG";
			int M                     = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = AlternativePiles().count(C, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string C                  = "BBBB";
			int M                     = 5;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = AlternativePiles().count(C, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string C                  = "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW";
			int M                     = 50;
			int expected__            = 265470435;

			clock_t start__           = clock();
			int received__            = AlternativePiles().count(C, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string C                  = "WRWRGWWGWWWRWBWRWGWWRWBWWRGWBWGRGWWGWGRWGRWBRWBW";
			int M                     = 7;
			int expected__            = 7400348;

			clock_t start__           = clock();
			int received__            = AlternativePiles().count(C, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string C                  = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AlternativePiles().count(C, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string C                  = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AlternativePiles().count(C, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string C                  = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AlternativePiles().count(C, M);
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
// Slow loris Guts is playing with N cards, numbered 0 through N-1. Each card has one of four colors: red, green, blue, or white. You are given the card colors as the string C. For each i, character i of C is one of 'R' (red), 'G' (green), 'B' (blue), and 'W' (white).

You are also given an int M.

Guts wants to color each white card red, green, or blue in such a way that the number of cards not colored blue is exactly 2*D*M for some non-negative integer D. Additionally, there must be exactly M sequences of integers S_0 through S_{M-1} with the following properties:


For each i, the sequence S_i contains exactly 2*D integers, each of them between 0 and N-1, inclusive.
For each i, the sequence S_i is strictly increasing. That is, S_i[0] < S_i[1] < ... < S_i[2*D-1].
For each i and each even j, the card S_i[j] is red.
For each i and each odd j, the card S_i[j] is green.
No two sequences share a common element. Hence, for each index x of a non-blue card there is precisely one pair (i,j) such that S_i[j]=x.

Return the number of valid ways to color all white cards, modulo 1,000,000,007.

DEFINITION
Class:AlternativePiles
Method:count
Parameters:string, int
Returns:int
Method signature:int count(string C, int M)


CONSTRAINTS
-C will contain between 1 and 5,000 characters, inclusive.
-Each character of C will be 'R', 'G', 'B' or 'W'.
-M will be between 1 and 50, inclusive.


EXAMPLES

0)
"WRGWWRGW"
2

Returns: 3

There are three valid colorings: "RRGRGRGG", "RRGGRRGG", and "BRGBBRGB".

For "RRGRGRGG", we have D=2 and one possibility is to select S_0 = {0,2,3,7} and S_1 = {1,4,5,6}.

For "BRGBBRGB", we have D=1 and to show that this is a valid coloring we let S_0 = {5,6} and S_1 = {1,2}.

1)
"RRGG"
1

Returns: 0

There is no valid way.

2)
"BBBB"
5

Returns: 1

Note that D can be zero. Also, note that even though there are no white cards in this test case, there is a valid way to color all white cards: we do nothing and keep the colors we currently have.

3)
"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
50

Returns: 265470435

Do not forget to calculate the answer modulo 10^9 + 7.

4)
"WRWRGWWGWWWRWBWRWGWWRWBWWRGWBWGRGWWGWGRWGRWBRWBW"
7

Returns: 7400348



*/

// END CUT HERE
