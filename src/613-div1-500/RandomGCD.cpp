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
int p[100010];

long long modPow(long long x, long long y){
    long long r=1, a=x%MOD;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}

void add(LL &a, LL b){
    a = (a + b)% MOD;
}
void sub(LL &a, LL b){
    a = (a - b + MOD) % MOD;
}

int cal(int hi, int lo, int d, int N){
    LL k = (hi/d - (lo+d-1)/d) + 1;
    return (modPow(k, N) - k + MOD) % MOD;
}

class RandomGCD {
public:
   int countTuples( int N, int K, int low, int high ) {
       int lo = (low+K-1)/K;
       int hi = high/K;
       if(hi < lo) return 0;
       
       MSET(p, 0);
       for(int i = 2; i < 100010; i++){
           int l = i;
           for(int j = 2; j*j <= l; j++){
               int cnt = 0;
               while(l % j == 0){
                   if(cnt > 0){
                       p[i] = 0;
                       goto fail;
                   }
                   cnt++;
                   p[i]++;
                   l /= j;
               }
           }
           if(l != 1) p[i]++;
       fail:;
       }
       
       LL res = cal(hi, lo, 1, N);
       for(int i = 2; i <= hi - lo; i++){
           if(p[i] == 0) continue;
           if(p[i]&1) sub(res, cal(hi, lo, i, N));
           else add(res, cal(hi, lo, i, N));
       }
       if(lo == 1) res++;
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
			int K                     = 2;
			int low                   = 2;
			int high                  = 4;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = RandomGCD().countTuples(N, K, low, high);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 2;
			int K                     = 100;
			int low                   = 2;
			int high                  = 4;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = RandomGCD().countTuples(N, K, low, high);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 1;
			int K                     = 5;
			int low                   = 5;
			int high                  = 5;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = RandomGCD().countTuples(N, K, low, high);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 73824;
			int K                     = 17347;
			int low                   = 9293482;
			int high                  = 9313482;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = RandomGCD().countTuples(N, K, low, high);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 222;
			int K                     = 222;
			int low                   = 222;
			int high                  = 22222;
			int expected__            = 339886855;

			clock_t start__           = clock();
			int received__            = RandomGCD().countTuples(N, K, low, high);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int K                     = ;
			int low                   = ;
			int high                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RandomGCD().countTuples(N, K, low, high);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int K                     = ;
			int low                   = ;
			int high                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RandomGCD().countTuples(N, K, low, high);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int K                     = ;
			int low                   = ;
			int high                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RandomGCD().countTuples(N, K, low, high);
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
// Consider the integers between low and high, inclusive.
We are going to select a sequence of N integers from this range.
The sequence is allowed to contain repeated elements, hence there are (high-low+1)^N possible sequences (where '^' denotes exponentiation).

Out of those sequences, we are only interested in the ones that have one additional property:
the greatest common divisor (GCD) of their elements must be exactly K.

You are given the ints N, K, low, and high.
Let X be the number of N-tuples described above.
Because X can be very large, compute and return the value (X modulo 1,000,000,007).

DEFINITION
Class:RandomGCD
Method:countTuples
Parameters:int, int, int, int
Returns:int
Method signature:int countTuples(int N, int K, int low, int high)


NOTES
-The greatest common divisor of a sequence is the largest positive integer that divides each element of the sequence.


CONSTRAINTS
-N, K and low will each be between 1 and 1,000,000,000, inclusive.
-high will be between low and 1,000,000,000, inclusive.
-The difference high - low will be less than or equal to 100,000.


EXAMPLES

0)
2
2
2
4

Returns: 3

There are 9 possible sequences: {(2, 2), (2, 3), (2, 4), (3, 2), (3, 3), (3, 4), (4, 2), (4, 3), (4, 4)}.
Out of these, 3 of them have the requested gcd of 2: {(2, 2), (2, 4), (4, 2)}.
Hence, the answer is 3.

1)
2
100
2
4

Returns: 0

Sometimes no combinations yield the requested GCD.

2)
1
5
5
5

Returns: 1

Sometimes you select only one number.

3)
73824
17347
9293482
9313482

Returns: 0



4)
222
222
222
22222

Returns: 339886855



*/

// END CUT HERE
