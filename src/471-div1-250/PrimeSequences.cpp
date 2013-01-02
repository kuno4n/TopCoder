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

#define INF 12000000
int is_prime[INF];

class PrimeSequences {
	public:
	int getLargestGenerator(int N, int D) {
		REP(i, INF) is_prime[i] = 1;
        is_prime[0] = is_prime[1] = 0;
        for(int i=2; i<=N; i++){
            if(is_prime[i]){
                for(int j=2*i; j<=N; j+=i) is_prime[j] = 0;
            }
        }
        for(int i=N; i>=2; i--){
            if(!is_prime[i]) continue;
            int cnt = 0;
            for(int j=i; is_prime[j]; j/=2) cnt++;
            if(cnt >= D) return i;
        }
        return -1;
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
			int N                     = 10;
			int D                     = 2;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = PrimeSequences().getLargestGenerator(N, D);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 42;
			int D                     = 3;
			int expected__            = 23;

			clock_t start__           = clock();
			int received__            = PrimeSequences().getLargestGenerator(N, D);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 666;
			int D                     = 7;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = PrimeSequences().getLargestGenerator(N, D);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 1337;
			int D                     = 5;
			int expected__            = 47;

			clock_t start__           = clock();
			int received__            = PrimeSequences().getLargestGenerator(N, D);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 100000;
			int D                     = 5;
			int expected__            = 2879;

			clock_t start__           = clock();
			int received__            = PrimeSequences().getLargestGenerator(N, D);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 40000;
			int D                     = 1;
			int expected__            = 39989;

			clock_t start__           = clock();
			int received__            = PrimeSequences().getLargestGenerator(N, D);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int D                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PrimeSequences().getLargestGenerator(N, D);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int D                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PrimeSequences().getLargestGenerator(N, D);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int N                     = ;
			int D                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PrimeSequences().getLargestGenerator(N, D);
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
// Elly loves "div 2" problems! By this she means problems in which she has to divide by two.
She observes an interesting property of some prime numbers: after division by two (all divisions in this problem are rounded down, i.e., integer divisions) the new number is also prime. An example of such a prime number is 7, which after division becomes 3, which is also prime. Some numbers generate even longer sequences: {47, 23, 11, 5, 2} contains 5 consecutive prime numbers, for example.

The length of the sequence generated by a natural number K is defined as the number of times K can be divided by two before obtaining a number which is not prime. For example, the number 479 has length of only 2, because after two divisions the resulting number 119 is not prime (even though subsequent divisions produce the prime numbers 59, 29, 7 and 3).

Given ints N and D, Elleonora wants to find a positive integer X less than or equal to N such that the length of the sequence generated by X is at least D. If more than one such number exists, she wants the largest one. If no such number exists, return -1 instead.

DEFINITION
Class:PrimeSequences
Method:getLargestGenerator
Parameters:int, int
Returns:int
Method signature:int getLargestGenerator(int N, int D)


NOTES
-A prime number is a natural number greater than one with exactly two distinct natural divisors: 1 and itself.


CONSTRAINTS
-N will be between 2 and 10,000,000, inclusive.
-D will be between 1 and 10, inclusive.


EXAMPLES

0)
10
2

Returns: 7

Here the optimal sequence is {7, 3}. Another sequence {5, 2} with the same length exists too, but the first one begins with a larger number.


1)
42
3

Returns: 23

The optimal sequence is {23, 11, 5, 2}, which has length 4.

2)
666
7

Returns: -1

Six hundred and sixty six is, apparently, not large enough to contain a sequence of length 7.

3)
1337
5

Returns: 47

4)
100000
5

Returns: 2879

There are not many sequences of length five or more.

5)
40000
1

Returns: 39989

39989 is the largest prime number less than or equal to 40000.

*/

// END CUT HERE
