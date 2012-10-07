#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
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
#define FIT(it,v) for(typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define OUT(A) cout << #A << " = " << A << endl

class Cryptography {
	public:
	long long encrypt(vector <int> numbers) {
		LL res = 0;
        REP(i, SZ(numbers)){
            VI tmp = numbers;
            tmp[i]++;
            LL x = 1;
            REP(j, SZ(tmp)) x *= tmp[j];
            res = max( res, x);
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
			int numbers[]             = {1,2,3};
			long long expected__      = 12;

			clock_t start__           = clock();
			long long received__      = Cryptography().encrypt(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int numbers[]             = {1,3,2,1,1,3};
			long long expected__      = 36;

			clock_t start__           = clock();
			long long received__      = Cryptography().encrypt(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int numbers[]             = {1000,999,998,997,996,995};
			long long expected__      = 986074810223904000LL;

			clock_t start__           = clock();
			long long received__      = Cryptography().encrypt(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int numbers[]             = {1,1,1,1};
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = Cryptography().encrypt(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int numbers[]             = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Cryptography().encrypt(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int numbers[]             = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Cryptography().encrypt(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int numbers[]             = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Cryptography().encrypt(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
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
// TopCoder Security Agency (TSA, established today) has just invented a new encryption system! This encryption system takes as its input a list of numbers to encrypt.


You work at TSA and your task is to implement a very important part of the encryption process. You are allowed to pick one number in the input list and increment its value by 1. This should be done in such way that the product of all numbers in the list after this change becomes as large as possible.


Given the list of numbers as vector <int> numbers, return the maximum product you can obtain. It is guaranteed that the return value will not exceed 2^62.


DEFINITION
Class:Cryptography
Method:encrypt
Parameters:vector <int>
Returns:long long
Method signature:long long encrypt(vector <int> numbers)


CONSTRAINTS
-numbers will contain between 2 and 50 elements, inclusive.
-Each element of numbers will be between 1 and 1000, inclusive.
-The return value will not exceed 2^62.


EXAMPLES

0)
{1,2,3}

Returns: 12

If we increment the first number, we get 2*2*3 = 12. If we increment the second, we get 1*3*3 = 9. If we increment the third, we get 1*2*4 = 8. Hence, the correct return value is 12.

1)
{1,3,2,1,1,3}

Returns: 36

The elements of numbers are not necessarily unique.

2)
{1000,999,998,997,996,995}

Returns: 986074810223904000

The answer may be very big, but will not exceed 2^62.

3)
{1,1,1,1}

Returns: 2



*/

// END CUT HERE
