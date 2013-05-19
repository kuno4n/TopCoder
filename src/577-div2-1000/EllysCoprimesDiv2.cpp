
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

long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a%b);
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


class EllysCoprimesDiv2 {
public:
   int getCount( vector <int> numbers ) {
	sort(ALL(numbers));
	int res = 0;
	REP(i, SZ(numbers)-1){
		int a = numbers[i], b = numbers[i+1];
		if(gcd(a,b) == 1) continue;
		bool can = false;
		for(int j = a+1; j < b; j++) if(gcd(a, j) == 1 && gcd(j, b) == 1){
			can = true;
			break;
		}
		if(can) res++;
		else res += 2;
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
			int numbers[]             = {2200, 42, 2184, 17};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = EllysCoprimesDiv2().getCount(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int numbers[]             = {13, 1, 6, 20, 33};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = EllysCoprimesDiv2().getCount(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int numbers[]             = {7, 42};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = EllysCoprimesDiv2().getCount(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int numbers[]             = {55780, 44918, 55653, 4762, 41536, 40083, 79260, 7374, 24124, 91858, 7856, 12999, 64025, 12706, 19770, 71495, 32817, 79309, 53779, 8421, 97984, 34586, 893, 64549, 77792, 12143, 52732, 94416, 54207, 51811, 80845, 67079, 14829, 25350, 22976, 23932, 62273, 58871, 82358, 13283, 33667, 64263, 1337, 42666};
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = EllysCoprimesDiv2().getCount(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int numbers[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysCoprimesDiv2().getCount(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int numbers[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysCoprimesDiv2().getCount(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int numbers[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysCoprimesDiv2().getCount(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
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
// Elly has a set of unique positive integers, given in the vector <int> numbers. She wants to add several (possibly none) new positive integers to this set, such that when the set is sorted no two consecutive numbers will share a positive divisor greater than 1. Return the smallest possible count of new numbers, with which she can achieve that.

DEFINITION
Class:EllysCoprimesDiv2
Method:getCount
Parameters:vector <int>
Returns:int
Method signature:int getCount(vector <int> numbers)


CONSTRAINTS
-numbers will contain between 1 and 50 elements, inclusive.
-Each element of numbers will be between 1 and 100,000, inclusive.
-All elements of numbers will be distinct.


EXAMPLES

0)
{2200, 42, 2184, 17}

Returns: 3

Here one possible set of additional numbers is {43, 2195, 2199}.
The sorted sequence is (17, 42, 43, 2184, 2195, 2199, 2200), and as you may see, no two consecutive numbers share a divisor greater than one.

1)
{13, 1, 6, 20, 33}

Returns: 0

For some sets, such as this one, no additional numbers are needed. When sorted, no pair of consecutive numbers shares a common divisor greater than 1.

2)
{7, 42}

Returns: 1

Note that prime numbers are not coprime with all other numbers.

3)
{55780, 44918, 55653, 4762, 41536, 40083, 79260, 7374, 24124, 91858, 7856,
 12999, 64025, 12706, 19770, 71495, 32817, 79309, 53779, 8421, 97984, 34586,
 893, 64549, 77792, 12143, 52732, 94416, 54207, 51811, 80845, 67079, 14829,
 25350, 22976, 23932, 62273, 58871, 82358, 13283, 33667, 64263, 1337, 42666}

Returns: 15

Large random set of numbers.

*/

// END CUT HERE
