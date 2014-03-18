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

map<LL, int> prime_factor(long long l){
    map<LL, int> res;
    for(long long i=2; i*i<=l; i++){
        while(l%i == 0){
            res[i]++;
            l /= i;
        }
    }
    if(l!=1) res[l] = 1;
    return res;
}

int cnt(LL n){
    int res = 0;
    LL tmp = 1;
    while(tmp*2 <= n){
        tmp *= 2;
        res++;
    }
    if(n - tmp > 0) res++;
    return res;
}

class BigFatInteger {
public:
   int minOperations( int A, int B ) {
       map<LL, int> m = prime_factor(A);
       int res = 0;
       for(auto it = m.begin(); it != m.end(); it++) chmax(res, cnt((*it).second * (LL)B));
       return res + SZ(m);
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
			int A                     = 6;
			int B                     = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A                     = 162;
			int B                     = 1;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A                     = 999983;
			int B                     = 9;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A                     = 360;
			int B                     = 8;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations(A, B);
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
// This problem statement contains superscipts that may not display properly outside the applet.

Lun the dog loves very large integers. Her favorite is AB (A to the power of B).


She has an integer variable X. Initially, the value of X is set to 1. She can perform the following two kinds of operations in any order, any number of times.

Operation 1: choose a prime number p, then multiply X by p.
Operation 2: choose a positive divisor d of the value of X at that point, then multiply X by d.



You are given two ints A and B. Return the minimum number of operations Lun needs to perform
in order to obtain X = AB from the initial state X = 1.

DEFINITION
Class:BigFatInteger
Method:minOperations
Parameters:int, int
Returns:int
Method signature:int minOperations(int A, int B)


CONSTRAINTS
-A will be between 2 and 1,000,000 (106), inclusive.
-B will be between 1 and 1,000,000 (106), inclusive.


EXAMPLES

0)
6
1

Returns: 2

Here, AB = 61 = 6. Here is one of the optimal sequences of operations:

Perform operation 1 by choosing p=2. X is now 1*2 = 2.
Perform operation 1 by choosing p=3. X is now 2*3 = 6.


1)
162
1

Returns: 4

One of the optimal sequences of operations:

Perform operation 1 by choosing p=3. X is now 1*3 = 3.
Perform operation 1 by choosing p=3. X is now 3*3 = 9.
Perform operation 2 by choosing d=9. X is now 9*9 = 81.
Perform operation 1 by choosing p=2. X is now 81*2 = 162.


2)
999983
9

Returns: 5

Here, A is prime. One of the optimal sequences of operations:

Perform operation 1 by choosing p=A. X is now A.
Perform operation 1 by choosing p=A. X is now A2.
Perform operation 1 by choosing p=A. X is now A3.
Perform operation 2 by choosing d=A3. X is now A6.
Perform operation 2 by choosing d=A3. X is now A9.


3)
360
8

Returns: 8



*/

// END CUT HERE
