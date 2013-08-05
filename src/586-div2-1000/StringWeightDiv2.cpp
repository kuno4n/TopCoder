
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


const int MOD = 1000000009;

    LL C[1050][1050];
    
    void makepas(){
		MSET(C, 0);
		C[0][0] = C[1][0] = C[1][1] = 1;
        for(int i=2; i<1050; i++){
            C[i][0] = 1;
            C[i][i] = 1;
            for(int j=1; j<i; j++){
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
            }
        }
    }

void mul(LL &a, LL b){
	a = (a * b) % MOD;
}

class StringWeightDiv2 {
public:
   int countMinimums( int L ) {
	LL res = 1;
	REP(i, 26){
		mul(res, 26-i);
		if(i+1 == L) return res;
	}
	
	makepas();
	mul(res, C[L-26 + 26 - 1][26 - 1]);
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
			int L                     = 1;
			int expected__            = 26;

			clock_t start__           = clock();
			int received__            = StringWeightDiv2().countMinimums(L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int L                     = 2;
			int expected__            = 650;

			clock_t start__           = clock();
			int received__            = StringWeightDiv2().countMinimums(L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int L                     = 50;
			int expected__            = 488801539;

			clock_t start__           = clock();
			int received__            = StringWeightDiv2().countMinimums(L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int L                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = StringWeightDiv2().countMinimums(L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int L                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = StringWeightDiv2().countMinimums(L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int L                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = StringWeightDiv2().countMinimums(L);
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
// In this problem, all strings consist of uppercase English letters only.
That is, there are 26 distinct letters.

The weight of a string S can be computed as follows: 
for each letter that occurs at least once in S, its leftmost and rightmost occurrences L and R are found and the weight is increased by R-L.

For example, if S="ABCACAZ", the weight of S is (5-0) + (1-1) + (4-2) + (6-6) = 7.
(The leftmost occurrence of 'A' is at the index L=0, the rightmost one is at R=5, so 'A' contributes 5-0 = 5 to the weight of S. The only 'B' contributes 0, the pair of 'C's adds 2, and the only 'Z' adds 0.)

You are given a int L.
Consider all strings of length L.
Compute the weight of each of these strings.
The strings with the minimum weight among all of them are called light.
Your task is to count the number of light strings of length L.
Since this count may be very large, return it modulo 1,000,000,009.

DEFINITION
Class:StringWeightDiv2
Method:countMinimums
Parameters:int
Returns:int
Method signature:int countMinimums(int L)


CONSTRAINTS
-L will be between 1 and 1000, inclusive.


EXAMPLES

0)
1

Returns: 26

Any string of length 1 has weight equal to 0.

1)
2

Returns: 650

We can divide strings of length 2 into two classes: the strings with distinct first and second letter, and the strings with two equal letters. The strings composed of two equal letters have weight 1. All the other strings have weight 0. Thus, the number of strings of minimum weight is 26*26-26=650.

2)
50

Returns: 488801539



*/

// END CUT HERE
