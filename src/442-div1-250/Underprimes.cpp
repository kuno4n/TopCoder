
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
#include <queue>

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
#define OUT(A) cout << #A << " = "<< A << endl

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

bool isPrime(long long l){
    if(l < 2) return false;
    for(long long i=2; i*i<=l; i++)
        if(l%i == 0 )
            return false;
    return true; 
}

class Underprimes {
public:
   int howMany( int A, int B ) {
	   int res = 0;
	   for(int i = A; i <= B; i++){
		   map<int, int> m = prime_factor(i);
		   int cnt = 0;
		   FIT(it, m) cnt += (*it).second;
		   if(isPrime(cnt)) res++;
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
			int A                     = 2;
			int B                     = 10;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Underprimes().howMany(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A                     = 100;
			int B                     = 105;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Underprimes().howMany(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A                     = 17;
			int B                     = 17;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = Underprimes().howMany(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A                     = 123;
			int B                     = 456;
			int expected__            = 217;

			clock_t start__           = clock();
			int received__            = Underprimes().howMany(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Underprimes().howMany(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Underprimes().howMany(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Underprimes().howMany(A, B);
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
// The prime factorization of a number X is the list of prime numbers that multiply together to form X.  For example, the prime factorization of 12 is 2 * 2 * 3.  Note that 1 is not a prime number.
An underprime is a number whose prime factorization contains a prime number of elements.  For example, 12 is an underprime because its prime factorization contains 3 elements, and 3 is a prime number.  Given ints A and B, return the number of underprimes between A and B, inclusive.

DEFINITION
Class:Underprimes
Method:howMany
Parameters:int, int
Returns:int
Method signature:int howMany(int A, int B)


NOTES
-A positive integer number is called prime if it has exactly two divisors - 1 and itself. For example, 2, 3, 5 and 7 are prime numbers, and 4, 6, 8 and 9 are not prime. By convention, 1 is not considered to be a prime number.
-All prime factorizations of the same integer always contain the same prime numbers and can only differ by the order of primes within them.


CONSTRAINTS
-A will be between 2 and 100000, inclusive.
-B will be between A and 100000, inclusive.


EXAMPLES

0)
2
10

Returns: 5

The underprimes in this interval are: 4, 6, 8, 9, 10.

1)
100
105

Returns: 2

The underprimes in this interval are 102 = 2 * 3 * 17 and 105 = 3 * 5 * 7.

2)
17
17

Returns: 0

17 is a prime number, so its prime factorization contains one element. 1 is not a prime, so 17 is not an underprime.

3)
123
456

Returns: 217



*/

// END CUT HERE
