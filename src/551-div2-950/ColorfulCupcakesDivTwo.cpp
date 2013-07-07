
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

int cnt[3];
int n;
int MOD = 1000000007;

void add(int &a, int b){
	a = ((LL) a + b) % MOD;
}

int cur[55][55][55][3];
int nxt[55][55][55][3];

int cal(int start){
	MSET(cur, 0);
	if(start == 0) cur[1][0][0][0] = 1;
	if(start == 1) cur[0][1][0][1] = 1;
	if(start == 2) cur[0][0][1][2] = 1;
	
	for(int i = 1; i < n; i++){
		MSET(nxt, 0);
		REP(j, 52) REP(k, 52-j) REP(l, 52-j-k){
			if(j > 0){
				if(!(i == n-1 && start == 0)){
					add(nxt[j][k][l][0], cur[j-1][k][l][1]);
					add(nxt[j][k][l][0], cur[j-1][k][l][2]);
				}
			}
			if(k > 0){
				if(!(i == n-1 && start == 1)){
					add(nxt[j][k][l][1], cur[j][k-1][l][0]);
					add(nxt[j][k][l][1], cur[j][k-1][l][2]);
				}
			}
			if(l > 0){
				if(!(i == n-1 && start == 2)){
					add(nxt[j][k][l][2], cur[j][k][l-1][0]);
					add(nxt[j][k][l][2], cur[j][k][l-1][1]);
				}
			}
		}
		REP(j, 52) REP(k, 52) REP(l, 52) REP(m, 3) cur[j][k][l][m] = nxt[j][k][l][m];
	}
	int res = 0;
	REP(i, 3) add(res, cur[cnt[0]][cnt[1]][cnt[2]][i]);
	return res;
}

class ColorfulCupcakesDivTwo {
public:
   int countArrangements( string c ) {
	n = SZ(c);
	MSET(cnt, 0);
	REP(i, n) cnt[c[i]-'A']++;
	
	int res = 0;
	REP(i, 3) add(res, cal(i));
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
			string cupcakes           = "ABAB";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ColorfulCupcakesDivTwo().countArrangements(cupcakes);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string cupcakes           = "ABABA";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ColorfulCupcakesDivTwo().countArrangements(cupcakes);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string cupcakes           = "ABC";
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = ColorfulCupcakesDivTwo().countArrangements(cupcakes);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string cupcakes           = "ABABABABABABABABABABABABABABABABABABABABABABABABAB";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ColorfulCupcakesDivTwo().countArrangements(cupcakes);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string cupcakes           = "BCBABBACBABABCCCCCAABBAACBBBBCBCAAA";
			int expected__            = 741380640;

			clock_t start__           = clock();
			int received__            = ColorfulCupcakesDivTwo().countArrangements(cupcakes);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string cupcakes           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulCupcakesDivTwo().countArrangements(cupcakes);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string cupcakes           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulCupcakesDivTwo().countArrangements(cupcakes);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string cupcakes           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulCupcakesDivTwo().countArrangements(cupcakes);
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
// Beaver Bindu has N cupcakes.
Each cupcake has one of three possible colors.
In this problem we will represent the colors by uppercase letters 'A', 'B', and 'C'.
Two cupcakes of the same color are indistinguishable.
You are given a string cupcakes consisting of exactly N characters.
Each character in cupcakes gives the color of one of Bindu's cupcakes.


Bindu has N friends, sitting around a round table.
She wants to give each friend one of the cupcakes.
Moreover, she does not want to give cupcakes of the same color to any pair of friends who sit next to each other.


Let X be the number of ways in which she can hand out the cupcakes to her friends.
As X can be very large, compute and return the value (X modulo 1,000,000,007).

DEFINITION
Class:ColorfulCupcakesDivTwo
Method:countArrangements
Parameters:string
Returns:int
Method signature:int countArrangements(string cupcakes)


NOTES
-Formally, Bindu's friends can be labeled 0 through N-1 in such a way that friends i and (i+1 modulo N) are adjacent, for each i.


CONSTRAINTS
-cupcakes will contain between 3 and 50 characters, inclusive.
-Each character in cupcakes will be either 'A', 'B', or 'C'.


EXAMPLES

0)
"ABAB"

Returns: 2

The two valid ways of handing out the cupcakes are "ABAB" and "BABA".
(I.e., in the first way, friends 0 and 2 will receive cupcake of color A; and friends 1 and 3 will receive cupcake of color B.
The second way is exactly opposite.)


1)
"ABABA"

Returns: 0

Regardless of how she hands out the cupcakes, there will always be a pair of adjacent friends who both received a cupcake of color A.
Hence, there are no valid arrangements of cupcakes.


2)
"ABC"

Returns: 6

Each of the six permutations of "ABC" corresponds to a valid arrangement.

3)
"ABABABABABABABABABABABABABABABABABABABABABABABABAB"

Returns: 2



4)
"BCBABBACBABABCCCCCAABBAACBBBBCBCAAA"

Returns: 741380640

*/

// END CUT HERE
