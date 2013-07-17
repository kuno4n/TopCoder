
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


int prime[30];

void sieve(){
    int p = 0;
    bool is_prime[90];
    for(int i=0; i<90; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<90; i++){
        if(is_prime[i]){
            prime[p++] = i;
            for(int j=2*i; j<90; j+=i) is_prime[j] = false;
        }
    }
}

int p_table[55];
int dp[1<<20];

class RelativelyPrimeSubset {
public:
   int findSize( vector <int> S ) {
	int n = SZ(S);
	
	sieve();
	MSET(p_table, 0);
	REP(i, n) for(int j = 0; prime[j] < 50; j++) if(S[i]%prime[j] == 0) p_table[i] |= (1<<j);
	
	MSET(dp, -1); dp[0] = 0;
	REP(i, n) REP(j, (1<<20)) if(dp[0] >= 0 && !(p_table[i] & j)) chmax(dp[j|p_table[i]], dp[j]+1);
	int res = -1;
	REP(j, (1<<20)) chmax(res, dp[j]);
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
			int S[]                   = {2,3,7,11,4};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = RelativelyPrimeSubset().findSize(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int S[]                   = {4,8,12,16};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = RelativelyPrimeSubset().findSize(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int S[]                   = {100,17,81,82};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = RelativelyPrimeSubset().findSize(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int S[]                   = {2,3,4,5,6};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = RelativelyPrimeSubset().findSize(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			int S[]                   = {2,6,9};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = RelativelyPrimeSubset().findSize(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 5: {
			int S[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RelativelyPrimeSubset().findSize(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int S[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RelativelyPrimeSubset().findSize(vector <int>(S, S + (sizeof S / sizeof S[0])));
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
// You are given a vector <int> S containing a set of pairwise distinct positive integers.

Return the size of the largest subset T of S such that any two numbers from T are relatively prime.

DEFINITION
Class:RelativelyPrimeSubset
Method:findSize
Parameters:vector <int>
Returns:int
Method signature:int findSize(vector <int> S)


NOTES
-Two integers A and B are relatively prime if and only if their greatest common divisor equals to 1.


CONSTRAINTS
-S will contain between 1 and 50 elements, inclusive.
-Each element of S will be between 1 and 100, inclusive.
-All elements in S will be distinct.


EXAMPLES

0)
{2,3,7,11,4}

Returns: 4

One such subset T is {2,3,7,11}, another is {3,4,7,11}.

1)
{4,8,12,16}

Returns: 1



2)
{100,17,81,82}

Returns: 3



3)
{2,3,4,5,6}

Returns: 3



*/

// END CUT HERE
