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
#include <stdlib.h>
#include <numeric>
//#include "cout.h"

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

LL MOD = 1000000007LL;
LL dp[350][350];

class WolfInZooDivOne {
	public:
	int count(int N, vector <string> L, vector <string> R) {
        string sl, sr;
        REP(i, SZ(L)) sl += L[i];
        REP(i, SZ(R)) sr += R[i];
        stringstream ssl; ssl << sl;
        stringstream ssr; ssr << sr;
        VI ll;
        VI rr;
        while(1){
            int l=-1, r=-1;
            ssl >> l; ssr >> r;
            if(l == -1) break;
            ll.push_back(l);
            rr.push_back(r);
        }
        
        int two[350];
        REP(i, 350) two[i] = -1;
        REP(i, SZ(ll)){
            if(rr[i] - ll[i] <= 1) continue;
            bool OK = true;
            REP(j, SZ(ll)){
                if(i == j) continue;
                if( (ll[i] >= ll[j] && rr[i] < rr[j]) || (ll[i] > ll[j] && rr[i] <= rr[j]) ) OK = false;
            }
            if(OK) two[ll[i]] = rr[i];
        }
        
        REP(i, 350) REP(j, 350) dp[i][j] = 1;
        
        for(int i = 1; i < N-1; i++){
            
            int left1 = i;
            for(int ii = i; ii >=0; ii--) if(two[ii] >= i) left1 = ii;
			
			LL sum1 = left1;
			for(int a = 0; a <= left1-2; a++) for(int b = a+1; b <= left1-1; b++)
				sum1 = (sum1 + dp[a][b]) % MOD;
			
			LL sum2 = 0;
			int ptr = left1;
			for(int j = i+1; j < N; j++){
				int left2 = i;
				for(int ii = i; ii >= 0; ii--) if(two[ii] >= j) left2 = ii;
				if(left2 > ptr){
					sum2 = (sum2 + left2-ptr) % MOD;
					for(int a = 0; a <= left1-1; a++) for(int b = ptr; b <= left2-1; b++)
						sum2 = (sum2 + dp[a][b]) % MOD;
					ptr = left2;
				}
				dp[i][j] = (dp[i][j] + sum1 + sum2) % MOD;
			}
			
        }
        
//        for(int i = 0; i < N-1; i++) for(int j = i+1; j < N; j++){
//			OUT(i);
//			OUT(j);
//			OUT(dp[i][j]);
//		}
        LL res = N + 1;
        REP(i, N-1) for(int j = i+1; j < N; j++) res = (res + dp[i][j]) % MOD;
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
			int N                     = 5;
			string L[]                = {"0"};
			string R[]                = {"4"};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = WolfInZooDivOne().count(N, vector <string>(L, L + (sizeof L / sizeof L[0])), vector <string>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 5;
			string L[]                = {"0 1"};
			string R[]                = {"2 4"};
			int expected__            = 21;

			clock_t start__           = clock();
			int received__            = WolfInZooDivOne().count(N, vector <string>(L, L + (sizeof L / sizeof L[0])), vector <string>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 10;
			string L[]                = {"0 4 2 7"};
			string R[]                = {"3 9 5 9"};
			int expected__            = 225;

			clock_t start__           = clock();
			int received__            = WolfInZooDivOne().count(N, vector <string>(L, L + (sizeof L / sizeof L[0])), vector <string>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 100;
			string L[]                = {"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"};
			string R[]                = {"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"};
			int expected__            = 6419882;

			clock_t start__           = clock();
			int received__            = WolfInZooDivOne().count(N, vector <string>(L, L + (sizeof L / sizeof L[0])), vector <string>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			int N                     = 6;
			string L[]                = {"0 2 2 2 2 2"};
			string R[]                = {"4 3 3 5 5 4"};
			int expected__            = 29;

			clock_t start__           = clock();
			int received__            = WolfInZooDivOne().count(N, vector <string>(L, L + (sizeof L / sizeof L[0])), vector <string>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 5: {
			int N                     = ;
			string L[]                = ;
			string R[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WolfInZooDivOne().count(N, vector <string>(L, L + (sizeof L / sizeof L[0])), vector <string>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			string L[]                = ;
			string R[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WolfInZooDivOne().count(N, vector <string>(L, L + (sizeof L / sizeof L[0])), vector <string>(R, R + (sizeof R / sizeof R[0])));
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
// Farmer Bessie and Cow John are walking along a straight road.
They are cautious, because they have heard that there may be some wolves on the road.


The road consists of N sections.
The sections are numbered 0 through N-1, in order.
Each section of the road contains at most one wolf.


You have M additional pieces of information about the positions of the wolves.
Each piece of information is an interval of the road that contains at most two wolves.
More precisely, for each i between 0 and M-1, inclusive, you are given two integers left[i] and right[i] such that the sections with numbers in the range from left[i] to right[i], inclusive, contain at most two wolves in total.


You are given two vector <string>s L and R.
The concatenation of all elements of L will be a single space separated list containing the integers left[0] through left[M-1].
R contains all the integers right[i] in the same format.


Return the number of ways in which wolves can be distributed in the sections of the road, modulo 1,000,000,007. 

DEFINITION
Class:WolfInZooDivOne
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
{"0"}
{"4"}

Returns: 16

There are at most two wolves in the segments 0 through 4, i.e., in the entire road.
The following picture shows all possible ways how the wolves can be distributed.
Note that there can also be only one wolf, or no wolves at all.




1)
5
{"0 1"}
{"2 4"}

Returns: 21



2)
10
{"0 4 2 7"}
{"3 9 5 9"}

Returns: 225



3)
100
{"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"}
{"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"}

Returns: 6419882

You must first concatenate the elements of L and only then split it into integers. The same holds for R.

*/

// END CUT HERE
