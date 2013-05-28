
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
#define PII pair < LL, LL >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl

#define MOD 1000000009
//LL tab[1010][110];

LL C[2010][110];
   
void makepas(){
    REP(i, 2010) REP(j, 110) C[i][j] = -1;
    C[0][0] = 1;
    for(int i=1; i<2000; i++){
        C[i][0] = 1;
        for(int j=1; j<min(i, 100); j++){
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
		}
        if(i <= 100) C[i][i] = 1;
    }
}

map<int, int> prime_factor(long long l){
    map<int, int> res;
    for(long long i=2; i*i<=l; i++){
        while(l%i == 0){
            res[i]++;
            l /= i;
        }
    }
    if(l!=1) res[l] = 1;
    return res;
}

LL primeAppear(int N, int K, int p){
	LL res = 0;
	for(int c = 1; p*c <= N; c++){
		map<int, int> m = prime_factor(p*c);
		res += C[N+K-1-p*c][K-1] * m[p];
		res %= MOD;
	}
	return res;
}


class MegaFactorialDiv2 {
public:
   int countDivisors( int N, int K ) {
	makepas();
	bool used[N+1]; REP(i, N+1) used[i] = false;
	LL res = 1;
	for(int i = 2; i <= N; i++) if(!used[i]){
		res = (res * (primeAppear(N, K, i) + 1)) % MOD;
		for(int j = i; j <= N; j += i) used[j] = true;
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
			int N                     = 3;
			int K                     = 1;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = MegaFactorialDiv2().countDivisors(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 3;
			int K                     = 2;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = MegaFactorialDiv2().countDivisors(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 4;
			int K                     = 2;
			int expected__            = 18;

			clock_t start__           = clock();
			int received__            = MegaFactorialDiv2().countDivisors(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 6;
			int K                     = 3;
			int expected__            = 1392;

			clock_t start__           = clock();
			int received__            = MegaFactorialDiv2().countDivisors(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 100;
			int K                     = 2;
			int expected__            = 321266186;

			clock_t start__           = clock();
			int received__            = MegaFactorialDiv2().countDivisors(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int N                     = 77;
			int K                     = 11;
			int expected__            = 61095262;

			clock_t start__           = clock();
			int received__            = MegaFactorialDiv2().countDivisors(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MegaFactorialDiv2().countDivisors(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MegaFactorialDiv2().countDivisors(N, K);
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
// The factorial of the k-th order of a number n is denoted n!k and defined by the following recurrences:
1) n!k = n!(k-1) * (n-1)!k for n > 0 and k > 0
2) n!k = 1 for n = 0
3) n!k = n for k = 0

For example, 7!1 = 7! (the traditional factorial), and 5!3 = 5!2 * 4!3 = (5!1 * 4!2) * 4!3.

You are given ints N and K. Compute the number of distinct divisors of the number N!K. Return the computed number modulo 1,000,000,009.


DEFINITION
Class:MegaFactorialDiv2
Method:countDivisors
Parameters:LL, LL
Returns:int
Method signature:int countDivisors(int N, int K)


CONSTRAINTS
-N will be between 1 and 1000, inclusive.
-K will be between 1 and 100, inclusive.


EXAMPLES

0)
3
1

Returns: 4

3!1 = 3! = 6. The divisors of 6 are 1, 2, 3 and 6.

1)
3
2

Returns: 6

3!2 = 3!1 * 2!2 = 3! * 2!1 * 1!2 = 3! * 2! * 1!1 * 0!2 = 3! * 2! * 1! * 1 = 12. The divisors of 12 are 1, 2, 3, 4, 6 and 12.

2)
4
2

Returns: 18

4!2 is equal to 288.

3)
6
3

Returns: 1392



4)
100
2

Returns: 321266186



*/

// END CUT HERE
