
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

#define MOD 1000000007

LL mem[1300][52][52];
LL N, M;

LL rec(int modSum, int K, int x){
	if(mem[modSum][K][x] >= 0) return mem[modSum][K][x];
	if(modSum > N) return mem[modSum][K][x] = 0;
	LL res = 0;
	if(x == M){
		if((N-modSum)%M != 0 || K == 0) return mem[modSum][K][x] = 0;
		res = 1;
		LL R = (N-modSum) / M;
		REP(i, K-1) res = (res * ((R+K-1-i+MOD)%MOD)) % MOD;
		res = (res * K)  % MOD;
	}
	else{
		res += rec(modSum+x, K+1, x+1);
		res += rec(modSum, K, x+1);
		res %= MOD;
	}
	return mem[modSum][K][x] = res;
}

class DistinctRemainders {
public:
   int howMany( long long N_, int M_ ) {
	N = N_; M = M_;
	REP(i, 1300) REP(j, 52) REP(k, 52) mem[i][j][k] = -1;
	return rec(0, 0, 0);

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
			long long N               = 3;
			int M                     = 2;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = DistinctRemainders().howMany(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long N               = 3;
			int M                     = 3;
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = DistinctRemainders().howMany(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long N               = 58;
			int M                     = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = DistinctRemainders().howMany(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long N               = 572;
			int M                     = 7;
			int expected__            = 922572833;

			clock_t start__           = clock();
			int received__            = DistinctRemainders().howMany(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long N               = 1000000000000000000LL;
			int M                     = 20;
			int expected__            = 240297629;

			clock_t start__           = clock();
			int received__            = DistinctRemainders().howMany(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			long long N               = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DistinctRemainders().howMany(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long N               = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DistinctRemainders().howMany(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long N               = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DistinctRemainders().howMany(N, M);
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
// You are interested in a sequence of integers S = (S[1], S[2], ..., S[K]) with the following properties:


K >= 1.
For all i, S[i] is a non-negative integer.
S[1] + S[2] + ... + S[K] = N.
S[1] mod M, S[2] mod M, ..., S[K] mod M are all different.


You are given a long long N and an int M. Return the number of different valid sequences S, modulo 1,000,000,007. Two sequences S1 and S2 are considered different if they either have different number of elements, or if there is an index i such that S1[i] is different from S2[i].

DEFINITION
Class:DistinctRemainders
Method:howMany
Parameters:long long, int
Returns:int
Method signature:int howMany(long long N, int M)


CONSTRAINTS
-N will be between 1 and 10^18, inclusive.
-M will be between 1 and 50, inclusive.


EXAMPLES

0)
3
2

Returns: 5

The 5 sequences are:

(3)
(0, 3)
(1, 2)
(2, 1)
(3, 0)


1)
3
3

Returns: 9

The 9 sequences are:

(3)
(1, 2)
(2, 1)
(0, 1, 2)
(0, 2, 1)
(1, 0, 2)
(1, 2, 0)
(2, 0, 1)
(2, 1, 0)


2)
58
1

Returns: 1

The only sequence is (58).

3)
572
7

Returns: 922572833



4)
1000000000000000000
20

Returns: 240297629

Watch out for overflows.

*/

// END CUT HERE
