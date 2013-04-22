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

#define MOD 1000000009

string s;
int n, absorb[310][310];
LL dp[3][310][310];

class TheExperiment {
	public:
	int countPlacements(vector <string> intensity, int M, int L, int A, int B) {
		s = "";
        REP(i, SZ(intensity)) s += intensity[i];
        n = SZ(s);
        
        REP(i, n) absorb[i][0] = 0;
        REP(i, n) for(int j = 1; j <= L; j++){
            if(i + j > n) continue;
            absorb[i][j] = absorb[i][j-1] + (s[i + j - 1] - '0');
        }
        
        REP(i, 3) REP(j, 310) REP(k, 310) dp[i][j][k] = 0;
        for(int i = 0; i <= n; i++) dp[1][0][i] = 1;
        
        for(int i = 1; i <= M; i++){
            for(int j = 1; j <= n; j++){
                
                // k == 0
                dp[1][i][j] += dp[1][i][j-1];
                dp[1][i][j] += dp[2][i][j-1];
                
                // k < L
                for(int k = 1; k < L; k++){
                    if(j < k) continue;
                    if(absorb[j-k][k] < A || absorb[j-k][k] > B) continue;
                    dp[0][i][j] += dp[0][i-1][j-k];
                    dp[0][i][j] += dp[1][i-1][j-k];
                    dp[2][i][j] += dp[2][i-1][j-k];
                }
                
                // k == L
                if(j >= L && absorb[j-L][L] >= A && absorb[j-L][L] <= B){
                    dp[2][i][j] += dp[0][i-1][j-L];
                    dp[2][i][j] += dp[1][i-1][j-L];
                    dp[2][i][j] += dp[2][i-1]
                    [j-L];
                }
                
                
                REP(k, 3) dp[k][i][j] %= MOD;
            }
        }
        
        LL res = 0;
        for(int j = 1; j <= n; j++) res = (res + dp[2][M][j]) % MOD;
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
			string intensity[]        = {"341156"};
			int M                     = 3;
			int L                     = 3;
			int A                     = 6;
			int B                     = 10;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheExperiment().countPlacements(vector <string>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), M, L, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string intensity[]        = {"999112999"};
			int M                     = 2;
			int L                     = 4;
			int A                     = 21;
			int B                     = 30;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheExperiment().countPlacements(vector <string>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), M, L, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string intensity[]        = {"111"};
			int M                     = 2;
			int L                     = 2;
			int A                     = 2;
			int B                     = 3;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheExperiment().countPlacements(vector <string>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), M, L, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string intensity[]        = {"59059", "110", "1132230231"};
			int M                     = 1;
			int L                     = 5;
			int A                     = 10;
			int B                     = 20;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = TheExperiment().countPlacements(vector <string>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), M, L, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string intensity[]        = {"111111111111111111111111", "111111111111111111111111111", "11111111111111111111111"};
			int M                     = 12;
			int L                     = 8;
			int A                     = 4;
			int B                     = 2700;
			int expected__            = 418629948;

			clock_t start__           = clock();
			int received__            = TheExperiment().countPlacements(vector <string>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), M, L, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string intensity[]        = ;
			int M                     = ;
			int L                     = ;
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheExperiment().countPlacements(vector <string>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), M, L, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string intensity[]        = ;
			int M                     = ;
			int L                     = ;
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheExperiment().countPlacements(vector <string>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), M, L, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string intensity[]        = ;
			int M                     = ;
			int L                     = ;
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheExperiment().countPlacements(vector <string>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), M, L, A, B);
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
// Manao is conducting an experiment to measure the humidity level of some spongy material. The experiment is conducted in a closed room which is observed from a side, so we will consider it in two dimensions.

The room is N centimeters wide. There are N drop counters built in the ceiling of the room. Drop counter 0 is attached 0.5 centimeters from the left end of the room, and each next one is attached 1 centimeter to the right of the previous one. You are given a vector <string> intensity filled with digits. Concatenate its elements to obtain one string S of length N. The i-th (0-based index) drop counter drips exactly S[i] drops per minute, where S[i] is the digit at the i-th position in S.

Manao is going to place M sponges in the room. All sponges are exactly L centimeters long and their thickness is negligible.
Each sponge must be placed horizontally, it must be entirely within the room, and the distance between the left wall of the room and the sponge must be an integer.
In other words, the coordinate of its left end must be an integer between 0 and N-L, inclusive.
Different sponges must be attached at different heights.
Each sponge will totally absorb every drop that drips at it.
For example, in the following picture, the sponges (from top to bottom) absorb 12, 5, and 3 drops per minute.



The experiment requires the sponges to be attached in such a way that each of them absorbs between A and B drops per minute, inclusive.
Manao is interested in the number of ways in which this can be done.
Two ways P and Q of attaching the sponges are the same if and only if for each sponge S1 in P there exists a sponge S2 in Q such that S1 and S2 lie directly beneath the same sets of drop counters.
A sponge X lies directly beneath a drop counter Y if there is no other sponge between them.
That is, if there is some water dripping from the drop counter Y, it all lands on the sponge X.
Note that according to these definitions the sponges are indistinguishable.

You are given the vector <string> intensity and the ints M, L, A, and B.
Count the number of different ways to attach the sponges and return that count modulo 1,000,000,009.

DEFINITION
Class:TheExperiment
Method:countPlacements
Parameters:vector <string>, int, int, int, int
Returns:int
Method signature:int countPlacements(vector <string> intensity, int M, int L, int A, int B)


CONSTRAINTS
-intensity will contain between 1 and 6 elements, inclusive.
-Each element of intensity will be between 1 and 50 characters long, inclusive.
-Each element of intensity will consist of digits ('0'-'9') only.
-M will be between 1 and 300, inclusive.
-L will be between 1 and N, inclusive, where N is the total number of characters in intensity.
-A will be between 1 and 2700, inclusive.
-B will be between A and 2700, inclusive.


EXAMPLES

0)
{"341156"}
3
3
6
10

Returns: 2

Manao needs to place three sponges of length 3 in such a way that they absorb between 6 and 10 drops per minute. The valid ways to attach the sponges are the following:


In the first way, the sponges receive 8, 6 and 6 drops, from highest to lowest. In the second way, they absorb 7, 7 and 6. Note that Manao could interchange the heights of the lower two sponges in the second picture, but this would result in the same way.

1)
{"999112999"}
2
4
21
30

Returns: 2

One of the platforms should have its left end exactly at the left wall. The other's left end can be either 4 or 5 centimeters away from the left wall.

2)
{"111"}
2
2
2
3

Returns: 0

One of the platforms will never receive enough drops.

3)
{"59059", "110", "1132230231"}
1
5
10
20

Returns: 6



4)
{"111111111111111111111111", "111111111111111111111111111", "11111111111111111111111"}
12
8
4
2700

Returns: 418629948



*/

// END CUT HERE
