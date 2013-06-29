
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

int MOD = 555555555;
int dp[600][600][2];

void add(int &a, int b){
	a = (a+b) % MOD;
}

class MuddyRoad2 {
public:
   int theCount( int n, int m ) {
	MSET(dp, 0); dp[0][0][0] = 1;
	
	// m+1個の箱にn-m個のボールを入れると考える（0個の箱があってもOK）
	// 最終的に、3の倍数個のボールがどれかの箱に入っているような場合の数を求める
	for(int i = 1; i <= m+1; i++) for(int j = 0; j <= n-m; j++){
		// i番の箱までに合計j個入れる場合を考える
		
		for(int k = 0; k <= n-m; k++){
			// i番の箱にはk個入れる
			
			if(j - k < 0) continue;
			if((i == 1 || i == m+1) && k == 0) continue; // 1個目とm+1個目の箱には1個以上ボールを入れないといけない
			add(dp[i][j][1], dp[i-1][j-k][1]);
			if(k%3 == 0) add(dp[i][j][1], dp[i-1][j-k][0]);
			else add(dp[i][j][0], dp[i-1][j-k][0]);
		}
	}
	return dp[m+1][n-m][1];
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
			int muddyCount            = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MuddyRoad2().theCount(N, muddyCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 5;
			int muddyCount            = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MuddyRoad2().theCount(N, muddyCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 10;
			int muddyCount            = 4;
			int expected__            = 65;

			clock_t start__           = clock();
			int received__            = MuddyRoad2().theCount(N, muddyCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 314;
			int muddyCount            = 78;
			int expected__            = 498142902;

			clock_t start__           = clock();
			int received__            = MuddyRoad2().theCount(N, muddyCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 555;
			int muddyCount            = 222;
			int expected__            = 541606281;

			clock_t start__           = clock();
			int received__            = MuddyRoad2().theCount(N, muddyCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int muddyCount            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MuddyRoad2().theCount(N, muddyCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int muddyCount            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MuddyRoad2().theCount(N, muddyCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int muddyCount            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MuddyRoad2().theCount(N, muddyCount);
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
// Fox Ciel is going to walk along an unpaved road to her friend's house.
For our purposes, the road can be considered a one-dimensional polyline consisting of N segments.
The segments are numbered 0 through N-1 along the road.
At the beginning, Ciel stands on the segment number 0.
Her friend's house is on the segment number N-1.

Unfortunately, yesterday it rained, so some segments of the road are now muddy.
Ciel has new shoes, so she must only use the other, dry segments.
She knows that segments 0 and N-1 are dry.
The friend just called her and gave her two additional pieces of information:

Out of the remaining N-2 segments, exactly muddyCount are muddy.
There is an even number of ways how Ciel can get to the friend's house without stepping into the mud, while making steps of length at most 2.


We will now explain the second information in more detail.
When Ciel walks along the road, each of her steps has either length 1 or 2.
A step of length 1 takes her from segment i to segment i+1.
A step of length 2 takes her from segment i to segment i+2, skipping the (possibly, but not necessarily muddy) segment i+1.

Fox Ciel would like to use the information she has to determine how the road looks like.
Of course, there may be multiple configurations that match the information.
It is also possible that her friend was mistaken and there is no sequence of dry and muddy segments that matches what she told Ciel.

You are given the ints N and muddyCount.
Count all the ways the road can look like, and return that count modulo 555,555,555.

DEFINITION
Class:MuddyRoad2
Method:theCount
Parameters:int, int
Returns:int
Method signature:int theCount(int N, int muddyCount)


NOTES
-Zero (0) is also an even number. Hence, if Ciel cannot reach her friend's house without stepping into the mud, there is an even number of ways to reach the house.
-Two configurations of the road are different if some road segment is dry in one of them and muddy in the other.


CONSTRAINTS
-N will be between 2 and 555, inclusive.
-muddyCount will be between 0 and N-2, inclusive.


EXAMPLES

0)
5
1

Returns: 2

There are two possible configurations of the road: 
.#...
and
...#. (where '#' denotes a muddy segment and '.' a dry one).

1)
5
2

Returns: 2

Possible configurations:
.##..
and
..##.
Note that in these configurations, there are no ways to go from part 0 to part 4 without stepping onto any muddy parts. You have to count this kind of configurations too, since 0 is an even number.

2)
10
4

Returns: 65



3)
314
78

Returns: 498142902



4)
555
222

Returns: 541606281



*/

// END CUT HERE
