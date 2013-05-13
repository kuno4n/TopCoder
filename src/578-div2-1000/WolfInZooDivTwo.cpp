
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

LL MOD = 1000000007;

int not0[350];
bool canALL0[350][350];
LL dp[350][350];

class WolfInZooDivTwo {
public:
   int count( int N, vector <string> L, vector <string> R ) {
	REP(i, 350) not0[i] = 10000;
	REP(i, 350) REP(j, 350) canALL0[i][j] = true;
	string sl, sr;
	REP(i, SZ(L)) sl += L[i];
	REP(i, SZ(R)) sr += R[i];
	stringstream ssl; ssl << sl;
	stringstream ssr; ssr << sr;
	while(1){
		int l=-1, r=-1;
		ssl >> l; ssr >> r;
		if(l == -1) break;
		not0[l] = min(not0[l], r);
	}
	REP(i, N)
		if(not0[i] < N) 
			for(int left = i; left >= 0; left--) 
				for(int right = not0[i]; right < N; right++) 
					canALL0[left][right] = false;
	
	REP(i, 350) REP(j, 350) dp[i][j] = 0;
	REP(i, N) dp[i][i] = 1;
	
	for(int len = 1; len < N; len++){
		for(int left = 0; left < N; left++){
			int right = left + len;
			if(right >= N) continue;
			
			dp[left][right] = (dp[left+1][right] * 2) % MOD;
			if(canALL0[left+1][right]) dp[left][right] = (dp[left][right] + 1) % MOD;
			
			if(not0[left] < right && canALL0[left+1][not0[left]]){
				int left2 = not0[left] + 1;
				dp[left][right] = (dp[left][right] - dp[left2][right] + MOD) % MOD;
			}
		}
	}OUT(dp[1][9]);
	return dp[0][N-1];

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
			int N                     = 5;
			string L[]                = {"0 1"};
			string R[]                = {"2 4"};
			int expected__            = 27;

			clock_t start__           = clock();
			int received__            = WolfInZooDivTwo().count(N, vector <string>(L, L + (sizeof L / sizeof L[0])), vector <string>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 10;
			string L[]                = {"0 4 2 7"};
			string R[]                = {"3 9 5 9"};
			int expected__            = 798;

			clock_t start__           = clock();
			int received__            = WolfInZooDivTwo().count(N, vector <string>(L, L + (sizeof L / sizeof L[0])), vector <string>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 100;
			string L[]                = {"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"};
			string R[]                = {"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"};
			int expected__            = 250671525;

			clock_t start__           = clock();
			int received__            = WolfInZooDivTwo().count(N, vector <string>(L, L + (sizeof L / sizeof L[0])), vector <string>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 3;
			string L[]                = {"1"};
			string R[]                = {"2"};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = WolfInZooDivTwo().count(N, vector <string>(L, L + (sizeof L / sizeof L[0])), vector <string>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			int N                     = 3;
			string L[]                = "0 1";
			string R[]                = "1 1";
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = WolfInZooDivTwo().count(N, vector <string>(L, L + (sizeof L / sizeof L[0])), vector <string>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 5: {
			int N                     = ;
			string L[]                = ;
			string R[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WolfInZooDivTwo().count(N, vector <string>(L, L + (sizeof L / sizeof L[0])), vector <string>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			string L[]                = ;
			string R[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WolfInZooDivTwo().count(N, vector <string>(L, L + (sizeof L / sizeof L[0])), vector <string>(R, R + (sizeof R / sizeof R[0])));
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
// Mr. Pasuterukun is walking along a straight road.
He is cautious, because he has heard that there may be some wolves on the road.


The road consists of N sections.
The sections are numbered 0 through N-1, in order.
Each section of the road contains at most one wolf.


You have M additional pieces of information about the positions of the wolves.
Each piece of information is an interval of the road that contains at least one wolf.
More precisely, for each i between 0 and M-1, inclusive, you are given two integers left[i] and right[i] such that the sections with numbers in the range from left[i] to right[i], inclusive, contain at least one wolf in total.


You are given two vector <string>s L and R.
The concatenation of all elements of L will be a single space separated list containing the integers left[0] through left[M-1].
R contains all the integers right[i] in the same format.


Return the number of ways in which wolves can be distributed in the sections of the road, modulo 1,000,000,007.

DEFINITION
Class:WolfInZooDivTwo
Method:count
Parameters:int, vector <string>, vector <string>
Returns:int
Method signature:int count(int N, vector <string> L, vector <string> R)


CONSTRAINTS
-N will be between 1 and 300, inclusive.
-L and R will contain between 1 and 50 elements, inclusive.
-Each element of L and R will contain between 1 and 50 characters, inclusive.
-Each character in L and R will be a digit ('0'-'9') or a space (' ').
-M will be between 1 and 300, inclusive.
-The concatenation of all elements of L will be a single space separated list of M integers. The integers will be between 0 and N-1, inclusive, and they will be given without unnecessary leading zeroes.
-The concatenation of all elements of R will be a single space separated list of M integers. The integers will be between 0 and N-1, inclusive, and they will be given without unnecessary leading zeroes.
-For each i, the i-th integer in L will be smaller than or equal to the i-th integer in R.


EXAMPLES

0)
5
{"0 1"}
{"2 4"}

Returns: 27

There is at least one wolf on the sections 0 through 2, and at least one wolf on the sections 1 through 4.

1)
10
{"0 4 2 7"}
{"3 9 5 9"}

Returns: 798



2)
100
{"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"}
{"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"}

Returns: 250671525

You must first concatenate the elements of L and only then split it into integers. The same holds for R.

3)
3
{"1"}
{"2"}

Returns: 6

The following picture shows all possible patterns.




*/

// END CUT HERE
