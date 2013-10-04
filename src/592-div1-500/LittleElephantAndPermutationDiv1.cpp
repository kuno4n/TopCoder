
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

const int MOD = 1000000007;
void add(LL &A, LL B){
	A = (A + B) % MOD;
}


LL prv[52][2510], nxt[52][2510];

class LittleElephantAndPermutationDiv1 {
public:
   int getNumber( int N, int K ) {
	
	MSET(prv, 0); 
	prv[0][0] = 1;
	for(int i = N; i >= 1; i--){
		MSET(nxt, 0);
		REP(k, 2505){
			int x = N - i;
			for(int x2 = max(0, x*2-N); x2 <= x; x2++){
				int x1 = x - x2;
				int x0 = N - x2 - x1*2;
				if(x0 >= 2)
					add(nxt[x2][k+i*2],  prv[x2][k] * x0 * (x0-1));
				if(x0 >= 1)
					add(nxt[x2+1][k+i],  prv[x2][k] * x0);
				if(x1 >= 1)
					add(nxt[x2+2][k],    prv[x2][k] * x1 * x1);
				if(x0 >= 1 && x1 >= 1)
					add(nxt[x2+1][k+i],  prv[x2][k] * x0 * x1 * 2);
			}
		}
		REP(j, 52) REP(k, 2510) prv[j][k] = nxt[j][k];
	}
	LL res = 0;
	for(int i = K; i < 2510; i++) add(res, prv[N][i]);
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
			int N                     = 1;
			int K                     = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = LittleElephantAndPermutationDiv1().getNumber(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 2;
			int K                     = 1;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = LittleElephantAndPermutationDiv1().getNumber(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 3;
			int K                     = 8;
			int expected__            = 18;

			clock_t start__           = clock();
			int received__            = LittleElephantAndPermutationDiv1().getNumber(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 10;
			int K                     = 74;
			int expected__            = 484682624;

			clock_t start__           = clock();
			int received__            = LittleElephantAndPermutationDiv1().getNumber(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 50;
			int K                     = 1000;
			int expected__            = 539792695;

			clock_t start__           = clock();
			int received__            = LittleElephantAndPermutationDiv1().getNumber(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LittleElephantAndPermutationDiv1().getNumber(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LittleElephantAndPermutationDiv1().getNumber(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LittleElephantAndPermutationDiv1().getNumber(N, K);
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
This problem statement contains superscripts and/or subscripts. These may not display properly outside the applet.




Little Elephant from the Zoo of Lviv likes permutations.
A permutation of size N is a sequence (a1, ..., aN) that contains each of the numbers from 1 to N exactly once.
For example, (3,1,4,5,2) is a permutation of size 5.




Given two permutations A = (a1, ..., aN) and B = (b1, ..., bN), the value magic(A,B) is defined as follows:
magic(A,B) = max(a1,b1) + max(a2,b2) + ... + max(aN,bN).




You are given the int N.
You are also given another int K.
Let X be the number of pairs (A,B) such that both A and B are permutations of size N, and magic(A,B) is greater than or equal to K.
(Note that A and B are not required to be distinct.) Return the value (X modulo 1,000,000,007).


DEFINITION
Class:LittleElephantAndPermutationDiv1
Method:getNumber
Parameters:int, int
Returns:int
Method signature:int getNumber(int N, int K)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-K will be between 1 and 2500, inclusive.


EXAMPLES

0)
1
1

Returns: 1

For N=1 the only pair of permutations is ( (1), (1) ).
The magic of this pair of permutations is 1, so we count it.

1)
2
1

Returns: 4

Now there are four possible pairs of permutations. They are shown below, along with their magic value.

magic( (1,2), (1,2) ) = 1+2 = 3
magic( (1,2), (2,1) ) = 2+2 = 4
magic( (2,1), (1,2) ) = 2+2 = 4
magic( (2,1), (2,1) ) = 2+1 = 3

In all four cases the magic value is greater than or equal to K.

2)
3
8

Returns: 18



3)
10
74

Returns: 484682624



4)
50
1000

Returns: 539792695



*/

// END CUT HERE
