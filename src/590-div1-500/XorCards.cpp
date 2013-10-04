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
#define VL vector < long long >
#define LL long long 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = " << A << endl
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

const int bits = 60;
typedef vector < VI > mat;

int _rank(mat &A, VI &B){
    int n = SZ(A[0]);
    int m = bits;
    bool used[m]; MSET(used, false);
    int r = 0;
    REP(j, n){
        int i = 0;
        while(i < m && (used[i] || !A[i][j])) i++;
        if(i == m) continue;
        used[i] = true;
        r++;
        REP(k, m) if(k != i && A[k][j]){
            REP(l, n) A[k][l] ^= A[i][l];
            B[k] ^= B[i];
        }
    }
    REP(i, m) if(!used[i] && B[i]) return -1;
    return r;
}

LL cnt(VL &a, LL b){
    int n = SZ(a);
    mat A(bits, VI(n));
    VI B(bits);
    REP(i, bits){
        REP(j, n) A[i][j] = ((a[j]>>i) & 1);
        B[i] = ((b>>i) & 1);
    }
    int r = _rank(A, B);
//    if(r != -1) {OUT(a);OUT(b);OUT(r);}
    return (r == -1 ? 0 : (1LL << (n-r)));
}


class XorCards {
	public:
	long long numberOfWays(vector<long long> number, long long limit) {
		LL res = 0;
        int n = SZ(number);
        REP(i, bits){
            if((1LL<<i) & limit){
                VL a;
                REP(j, n) a.push_back(number[j]>>i);
                res += cnt(a, (limit>>i)-1);
            }
        }
        res += cnt(number, limit);
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
			long long number[]        = {1, 2};
			long long limit           = 2;
			long long expected__      = 3;

			clock_t start__           = clock();
			long long received__      = XorCards().numberOfWays(vector<long long>(number, number + (sizeof number / sizeof number[0])), limit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long number[]        = {5, 5};
			long long limit           = 3;
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = XorCards().numberOfWays(vector<long long>(number, number + (sizeof number / sizeof number[0])), limit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long number[]        = {1, 2, 3, 4, 5, 6, 7};
			long long limit           = 5;
			long long expected__      = 96;

			clock_t start__           = clock();
			long long received__      = XorCards().numberOfWays(vector<long long>(number, number + (sizeof number / sizeof number[0])), limit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long number[]        = {123, 456, 789, 147, 258, 369, 159, 357};
			long long limit           = 500;
			long long expected__      = 125;

			clock_t start__           = clock();
			long long received__      = XorCards().numberOfWays(vector<long long>(number, number + (sizeof number / sizeof number[0])), limit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long number[]        = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			long long limit           = 1000000000000000LL;
			long long expected__      = 4294967296LL;

			clock_t start__           = clock();
			long long received__      = XorCards().numberOfWays(vector<long long>(number, number + (sizeof number / sizeof number[0])), limit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			long long number[]        = {1000000000000000LL, 999999999999999LL};
			long long limit           = 65535;
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = XorCards().numberOfWays(vector<long long>(number, number + (sizeof number / sizeof number[0])), limit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			long long number[]        = ;
			long long limit           = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = XorCards().numberOfWays(vector<long long>(number, number + (sizeof number / sizeof number[0])), limit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long number[]        = ;
			long long limit           = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = XorCards().numberOfWays(vector<long long>(number, number + (sizeof number / sizeof number[0])), limit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			long long number[]        = ;
			long long limit           = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = XorCards().numberOfWays(vector<long long>(number, number + (sizeof number / sizeof number[0])), limit);
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
// You have a set of cards.
There is one non-negative integer on each card.
Different cards may contain the same integer.
For each i, the number written on the i-th card (0-based index) is number[i].
Your friend wants to select a subset of those cards such that the bitwise xor of the selected cards is less than or equal to limit.



You are given the vector<long long> number and the long long limit.
Count the number of ways in which your friend can select the subset of cards.
Two subsets count as different if they differ as sets of cards (even if the corresponding sets of numbers are the same, see Example 4).

DEFINITION
Class:XorCards
Method:numberOfWays
Parameters:vector<long long>, long long
Returns:long long
Method signature:long long numberOfWays(vector<long long> number, long long limit)


NOTES
-XOR (exclusive or) is a binary operation, performed on two numbers in binary notation. First, the shorter number is prepended with leading zeroes until both numbers have the same number of digits (in binary). Then, the result is calculated as follows: for each bit where the numbers differ the result has 1 in its binary representation. It has 0 in all other positions.
-For example 42 XOR 7 is performed as follows. First, the numbers are converted to binary: 42 is 101010 and 7 is 111. Then the shorter number is prepended with leading zeros until both numbers have the same number of digits. This means 7 becomes 000111. Then 101010 XOR 000111 = 101101 (the result has ones only in the positions where the two numbers differ). Then the result can be converted back to decimal notation. In this case 101101 = 45, so 42 XOR 7 = 45.
-If your friend decides to select zero cards, the bitwise xor of numbers on selected cards is zero.
-If your friend decides to select a single card, the bitwise xor of numbers on selected cards is the number on the selected card.


CONSTRAINTS
-number will contain between 1 and 50 elements, inclusive.
-Each element in number will be between 0 and 1,000,000,000,000,000 (10^15), inclusive.
-limit will be between 0 and 1,000,000,000,000,000 (10^15), inclusive.


EXAMPLES

0)
{1,2}
2

Returns: 3

This set of cards has four possible subsets.
Here they are, along with the corresponding bitwise xors:
{} => 0, {1} => 1, {2} => 2, and {1,2} => 3.
Note that limit=2.
Out of these four subsets, for the first three the bitwise xor of selected numbers is at most equal to limit.

1)
{5,5}
3

Returns: 2

The two good subsets are {} and {5,5}.

2)
{1,2,3,4,5,6,7}
5

Returns: 96



3)
{123, 456, 789, 147, 258, 369, 159, 357}
500

Returns: 125



4)
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
1000000000000000

Returns: 4294967296



5)
{1000000000000000, 999999999999999}
65535

Returns: 2



*/

// END CUT HERE
