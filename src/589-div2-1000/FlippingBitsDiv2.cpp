
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


const int INF = (1<<29);

int zeros[2][2510][2];
int dp[2][2510][2];
int M;

int rec(int lr, int len, int xr){
	if(dp[lr][len][xr] >= 0) return dp[lr][len][xr];
	if(len == 0) return dp[lr][len][xr] = 0;
	
	int res = zeros[lr][len][xr];
	for(int i = M; i <= len - M; i += M){
		chmin(res, rec(lr, i, (xr^1)) + zeros[lr][len][xr] - zeros[lr][i][xr] + 1);
	}
	return dp[lr][len][xr] = res;
}

class FlippingBitsDiv2 {
public:
   int getmin( vector <string> s, int _M ) {
	string S = "";
	REP(i, SZ(s)) S += s[i];
	M = _M;
	MSET(zeros, 0); MSET(dp, -1);
	REP(i, SZ(S)){
		zeros[0][i+1][0] = (S[i] == '0') + (i == 0 ? 0 : zeros[0][i][0]);
		zeros[0][i+1][1] = i+1 - zeros[0][i+1][0];
	}
	REP(i, SZ(S)){
		zeros[1][i+1][0] = (S[SZ(S)-1-i] == '0') + (i == 0 ? 0 : zeros[1][i][0]);
		zeros[1][i+1][1] = i+1 - zeros[1][i+1][0];
	}
	
	int res = INF;
	for(int i = 0; i <= SZ(S); i += M){
		chmin(res, rec(0, i, 0) + rec(1, SZ(S)-i, 0));
		chmin(res, rec(0, i, 1) + rec(1, SZ(S)-i, 0) + 1);
		chmin(res, rec(0, i, 0) + rec(1, SZ(S)-i, 1) + 1);
		chmin(res, rec(0, i, 1) + rec(1, SZ(S)-i, 1) + 2);
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
			string S[]                = {"00111000"};
			int M                     = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = FlippingBitsDiv2().getmin(vector <string>(S, S + (sizeof S / sizeof S[0])), M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S[]                = {"00111000"};
			int M                     = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = FlippingBitsDiv2().getmin(vector <string>(S, S + (sizeof S / sizeof S[0])), M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S[]                = {"111111"};
			int M                     = 3;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FlippingBitsDiv2().getmin(vector <string>(S, S + (sizeof S / sizeof S[0])), M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S[]                = {"00100"};
			int M                     = 5;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = FlippingBitsDiv2().getmin(vector <string>(S, S + (sizeof S / sizeof S[0])), M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S[]                = {"00010","11010110","1010111","110001010","0110001100"
,"000110110","011010101","00","111","100"}
;
			int M                     = 13;
			int expected__            = 31;

			clock_t start__           = clock();
			int received__            = FlippingBitsDiv2().getmin(vector <string>(S, S + (sizeof S / sizeof S[0])), M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string S[]                = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FlippingBitsDiv2().getmin(vector <string>(S, S + (sizeof S / sizeof S[0])), M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string S[]                = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FlippingBitsDiv2().getmin(vector <string>(S, S + (sizeof S / sizeof S[0])), M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string S[]                = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FlippingBitsDiv2().getmin(vector <string>(S, S + (sizeof S / sizeof S[0])), M);
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
// Goose Tattarrattat has a sequence B of bits.
Tattarrattat also has a favorite positive integer M.
M divides the number of bits in B.

Tattarrattat wants to have a sequence in which all the bits are 1s.
She will produce such a sequence in a sequence of steps.
In each step she can do one of the following three types of changes to the sequence:


Flip any bit (from 1 to 0 or from 0 to 1).
Flip the first k*M bits, for any positive integer k.
Flip the last k*M bits, for any positive integer k.


For example, suppose that B="110100001001" and M=4.
There are 17 different sequences Tattarrattat can produce from this B in a single step.
Among those sequences are "100100001001" (flipped the second bit), "001011111001" (flipped the first 2*M bits), and "110100000110" (flipped the last M bits).

You are given a vector <string> S and the int M.
Concatenate all elements of S to obtain one long string.
This string will represent the sequence B: each of its characters will be either '0' or '1'.
Return the minimal number of steps required to obtain a sequence that consists of 1s only.

DEFINITION
Class:FlippingBitsDiv2
Method:getmin
Parameters:vector <string>, int
Returns:int
Method signature:int getmin(vector <string> S, int M)


CONSTRAINTS
-S will contain between 1 and 50 elements, inclusive.
-Each element of S will contain between 1 and 50 characters, inclusive.
-Each character in each element of S will be '0' or '1'.
-M will be between 1 and 2500.
-M will be a divisor of N, where N is the number of characters in S.


EXAMPLES

0)
{"00111000"}
1

Returns: 2

There are several optimal solutions.
For example, she can flip the first 5*1 bits (obtaining "11000000") and then the last 6*1 bits (obtaining "11111111").
Another solution: she can flip the first 2*1 bits (obtaining "11111000") and then the last 3*1 bits (obtaining "11111111").

1)
{"00111000"}
2

Returns: 3



2)
{"111111"}
3

Returns: 0

This sequence already consists of 1s only, so no steps are necessary.

3)
{"00100"}
5

Returns: 2



4)
{"00010","11010110","1010111","110001010","0110001100"
,"000110110","011010101","00","111","100"}

13

Returns: 31

Don't forget to concatenate the elements of S.

*/

// END CUT HERE
