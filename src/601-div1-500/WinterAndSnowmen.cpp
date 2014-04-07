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
const int msk = (1<<11);
void add(int &a , int b){
    a = ((LL)a + b) % MOD;
}

int dp[2010][msk][2][2];

class WinterAndSnowmen {
public:
   int getNumber( int N, int M ) {
       int res = 0;
       REP(d, 11){
           MSET(dp, 0);
           dp[0][0][0][0] = 1;
           FOR(i, 1, max(N, M)+1) REP(j, (1<<(11-d))) REP(k, 2) REP(l, 2){
               add(dp[i][j][k][l], dp[i-1][j][k][l]);
               int nmsk = j ^ (i>>d);
               if(i <= N) add(dp[i][nmsk][k^((i>>d)&1)][l], dp[i-1][j][k][l]);
               if(i <= M) add(dp[i][nmsk][k][l^((i>>d)&1)], dp[i-1][j][k][l]);
           }
           add(res, dp[max(N, M)][0][0][1]);
           add(res, dp[max(N, M)][1][0][1]);
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
			int N                     = 2;
			int M                     = 2;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = WinterAndSnowmen().getNumber(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 1;
			int M                     = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = WinterAndSnowmen().getNumber(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 3;
			int M                     = 5;
			int expected__            = 74;

			clock_t start__           = clock();
			int received__            = WinterAndSnowmen().getNumber(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 7;
			int M                     = 4;
			int expected__            = 216;

			clock_t start__           = clock();
			int received__            = WinterAndSnowmen().getNumber(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 47;
			int M                     = 74;
			int expected__            = 962557390;

			clock_t start__           = clock();
			int received__            = WinterAndSnowmen().getNumber(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int N                     = 1899;
			int M                     = 1999;
			int expected__            = 564171057;

			clock_t start__           = clock();
			int received__            = WinterAndSnowmen().getNumber(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int N                     = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WinterAndSnowmen().getNumber(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WinterAndSnowmen().getNumber(N, M);
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
It's winter time!
Time for snowmen to play some games.




Two snowmen are playing a game.
In this game, the first snowman must choose a subset of the set {1, 2, ..., N}, and the second one must choose a subset of the set {1, 2, ..., M}.
The following two conditions must be fulfilled:


The two sets have an empty intersection.


The XOR of all elements in the first set is less than the XOR of all elements in the second set.






You are given two ints N and M.
Let X be the total number of different ways to choose the pair of sets.
Return the value (X modulo 1,000,000,007).


DEFINITION
Class:WinterAndSnowmen
Method:getNumber
Parameters:int, int
Returns:int
Method signature:int getNumber(int N, int M)


NOTES
-XOR (exclusive or) is a binary operation, performed on two numbers in binary notation. First, the shorter number is prepended with leading zeroes until both numbers have the same number of digits (in binary). Then, the result is calculated as follows: for each bit where the numbers differ the result has 1 in its binary representation. It has 0 in all other positions.
-For example 42 XOR 7 is performed as follows. First, the numbers are converted to binary: 42 is 101010 and 7 is 111. Then the shorter number is prepended with leading zeros until both numbers have the same number of digits. This means 7 becomes 000111. Then 101010 XOR 000111 = 101101 (the result has ones only in the positions where the two numbers differ). Then the result can be converted back to decimal notation. In this case 101101 = 45, so 42 XOR 7 = 45.
-The XOR of an empty set is 0.


CONSTRAINTS
-N will be between 1 and 2000, inclusive.
-M will be between 1 and 2000, inclusive.


EXAMPLES

0)
2
2

Returns: 4

The following 4 pairs of subsets are possible in this case:


{} and {1}


{} and {2}


{} and {1, 2}


{1} and {2}



1)
1
1

Returns: 1

The only pair possible in this case is {} and {1}.

2)
3
5

Returns: 74



3)
7
4

Returns: 216



4)
47
74

Returns: 962557390



*/

// END CUT HERE
