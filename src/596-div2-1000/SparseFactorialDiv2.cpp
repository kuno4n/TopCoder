
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


LL imos[1000];
bool ok[1000];
LL p;


LL cnt(LL from, LL to){
	if(from > to) return 0;
	LL f = from % p;
	LL t = to % p;
	if(f <= t){
		return imos[t] - (f > 0 ? imos[f-1] : 0);
	}
	else{
		return imos[t] - imos[f-1] + imos[p-1];
	}
}


LL cal(LL n){
	MSET(imos, 0);
	MSET(ok, false);
	
	LL res = 0;
	
	for(LL i = 0; i*i < n; i++){
		if(!ok[(i*i) % p]){
			ok[(i*i) % p] = true;
			for(LL j = (i*i) % p; j < p; j++) imos[j]++;
		}
		LL kuri = (min((i+1)*(i+1), n) - i*i)/p;
		res += imos[p-1] * kuri;
		res += cnt(i*i + kuri*p + 1, min(n, (i+1)*(i+1)));
	}
	return res;
}


class SparseFactorialDiv2 {
public:
   long long getCount( long long lo, long long hi, long long divisor ) {
	p = divisor;
	return cal(hi) - cal(lo-1);
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			long long lo              = 4;
			long long hi              = 8;
			long long divisor         = 3;
			long long expected__      = 3;

			clock_t start__           = clock();
			long long received__      = SparseFactorialDiv2().getCount(lo, hi, divisor);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long lo              = 9;
			long long hi              = 11;
			long long divisor         = 7;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = SparseFactorialDiv2().getCount(lo, hi, divisor);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long lo              = 1;
			long long hi              = 1000000000000LL;
			long long divisor         = 2;
			long long expected__      = 999999999999LL;

			clock_t start__           = clock();
			long long received__      = SparseFactorialDiv2().getCount(lo, hi, divisor);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long lo              = 16;
			long long hi              = 26;
			long long divisor         = 11;
			long long expected__      = 4;

			clock_t start__           = clock();
			long long received__      = SparseFactorialDiv2().getCount(lo, hi, divisor);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long lo              = 10000;
			long long hi              = 20000;
			long long divisor         = 997;
			long long expected__      = 1211;

			clock_t start__           = clock();
			long long received__      = SparseFactorialDiv2().getCount(lo, hi, divisor);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			long long lo              = 123456789;
			long long hi              = 987654321;
			long long divisor         = 71;
			long long expected__      = 438184668;

			clock_t start__           = clock();
			long long received__      = SparseFactorialDiv2().getCount(lo, hi, divisor);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			long long lo              = ;
			long long hi              = ;
			long long divisor         = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = SparseFactorialDiv2().getCount(lo, hi, divisor);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long lo              = ;
			long long hi              = ;
			long long divisor         = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = SparseFactorialDiv2().getCount(lo, hi, divisor);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			long long lo              = ;
			long long hi              = ;
			long long divisor         = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = SparseFactorialDiv2().getCount(lo, hi, divisor);
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
// For an integer n, let F(n) = (n - 0^2) * (n - 1^2) * (n - 2^2) * (n - 3^2) * ... * (n - k^2), where k is the largest integer such that n - k^2 > 0.
You are given three long longs lo, hi and divisor.
It is guaranteed that divisor will be a prime number.
Compute and return the number of integers n between lo and hi, inclusive, such that F(n) is divisible by divisor.

DEFINITION
Class:SparseFactorialDiv2
Method:getCount
Parameters:long long, long long, long long
Returns:long long
Method signature:long long getCount(long long lo, long long hi, long long divisor)


CONSTRAINTS
-lo will be between 1 and 1,000,000,000,000, inclusive.
-hi will be between lo and 1,000,000,000,000, inclusive.
-divisor will be between 2 and 997, inclusive.
-divisor will be a prime number.


EXAMPLES

0)
4
8
3

Returns: 3

The value of F(n) for each n = 4, 5, ..., 8 is as follows. 

F(4) = 4*3   = 12
F(5) = 5*4*1 = 20
F(6) = 6*5*2 = 60
F(7) = 7*6*3 = 126
F(8) = 8*7*4 = 224

Thus, F(4), F(6), F(7) are divisible by 3 but F(5) and F(8) are not.

1)
9
11
7

Returns: 1


F(9)  = 9*8*5     = 360
F(10) = 10*9*6*1  = 540
F(11) = 11*10*7*2 = 1540

Only F(11) is divisible by 7.

2)
1
1000000000000
2

Returns: 999999999999

Watch out for the overflow. 

3)
16
26
11

Returns: 4



4)
10000
20000
997

Returns: 1211



5)
123456789
987654321
71

Returns: 438184668



*/

// END CUT HERE
