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
//#include "cout.h"

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

#define MOD 1000000009

map<int, int> prime_factor(long long l){
    map<int, int> res;
    for(LL i=2; i*i<=l; i++){
        while(l%i == 0){
            res[i]++;
            l /= i;
        }
    }
    if(l!=1) res[l] = 1;
    return res;
}

LL modPow(LL x, LL y){
    LL r=1, a=x;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}

LL modInverse(LL x){
    return modPow(x, MOD-2);
}

LL modDivision(LL p, LL q){
    return (p*modInverse(q)) % MOD;
}

LL modC(LL n, int k){
    if(k>n) return 0;
    LL p=1, q=1;
    for(int i=1; i<=k; i++){
        q = (q*i) % MOD;
        p = (p*(n-i+1))%MOD;
    }
    return modDivision(p, q);
}

class DivisibleSequence {
public:
	int count(int N, int H) {
		map<int, int> m = prime_factor(N);
        
        int res = 1;
        FIT(it, m) res = ((LL)res * modC((LL)H+(*it).second-1, (*it).second)) % MOD;
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
			int N                     = 5;
			int H                     = 3;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DivisibleSequence().count(N, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 6;
			int H                     = 3;
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = DivisibleSequence().count(N, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 10;
			int H                     = 2;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = DivisibleSequence().count(N, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 1;
			int H                     = 10000;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = DivisibleSequence().count(N, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 30;
			int H                     = 4;
			int expected__            = 64;

			clock_t start__           = clock();
			int received__            = DivisibleSequence().count(N, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 25883;
			int H                     = 100000;
			int expected__            = 991000009;

			clock_t start__           = clock();
			int received__            = DivisibleSequence().count(N, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int H                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DivisibleSequence().count(N, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int H                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DivisibleSequence().count(N, H);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int N                     = ;
			int H                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DivisibleSequence().count(N, H);
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
// A divisible sequence with starting value N and length H is a sequence of positive integers with the following properties:

The sequence has H elements, labeled A[0] through A[H-1].
A[0] equals N.
For each i between 0 and H-2, inclusive, A[i+1] divides A[i].


You are given the ints N and H.
Let C be the count of all divisible sequences with starting value N and length H.
Return the value (C modulo 1,000,000,009).


DEFINITION
Class:DivisibleSequence
Method:count
Parameters:int, int
Returns:int
Method signature:int count(int N, int H)


CONSTRAINTS
-N will be between 1 and 1,000,000,000, inclusive.
-H will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
5
3

Returns: 3

The three possible sequences are:
5, 5, 5
5, 5, 1
5, 1, 1


1)
6
3

Returns: 9

The nine possible sequences are:
6, 6, 6
6, 6, 3
6, 6, 2
6, 6, 1
6, 3, 3
6, 3, 1
6, 2, 2
6, 2, 1
6, 1, 1

2)
10
2

Returns: 4

A[1] can be equal to each of the divisors of the number 10. That is, A[1] can be 1, 2, 5, or 10.

3)
1
10000

Returns: 1

The only possible sequence consists of all ones.

4)
30
4

Returns: 64



5)
25883
100000

Returns: 991000009



*/

// END CUT HERE
