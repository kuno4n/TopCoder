
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
#include <queue>

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
#define OUT(A) cout << #A << " = "<< A << endl


queue<int> que;
int N;
int memo[200010];


class BinaryFlips {
public:
   int minimalMoves( int A, int B, int K ) {
	   N = A+B;
	   if(A == 0) return 0;
	   if(N < K) return -1;
	   while(!que.empty()) que.pop();
	   REP(i, 100010) memo[i] = -1;

	   memo[A] = 0;
	   que.push(A);

	   while(!que.empty()){
		   int cnt0 = que.front();
		   int cnt1 = N-cnt0;
		   if(cnt0 == 0) return memo[0];
		   que.pop();

		   int minflip0 = max(0, K-cnt1);
		   int maxflip0 = min(K, cnt0);
		   for(int flip0 = minflip0; flip0<=maxflip0; flip0++){
			   int nextcnt0 = cnt0 - flip0 + (K-flip0);
			   if(memo[nextcnt0] >= 0) continue;
			   memo[nextcnt0] = memo[cnt0] +1;
			   que.push(nextcnt0);
		   }
	   }


	   return -1;
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
			int A                     = 3;
			int B                     = 0;
			int K                     = 3;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = BinaryFlips().minimalMoves(A, B, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A                     = 4;
			int B                     = 0;
			int K                     = 3;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = BinaryFlips().minimalMoves(A, B, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A                     = 4;
			int B                     = 1;
			int K                     = 3;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = BinaryFlips().minimalMoves(A, B, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A                     = 3;
			int B                     = 2;
			int K                     = 5;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = BinaryFlips().minimalMoves(A, B, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int A                     = 100000;
			int B                     = 100000;
			int K                     = 578;
			int expected__            = 174;

			clock_t start__           = clock();
			int received__            = BinaryFlips().minimalMoves(A, B, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int A                     = 0;
			int B                     = 0;
			int K                     = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = BinaryFlips().minimalMoves(A, B, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int A                     = 4;
			int B                     = 44;
			int K                     = 50;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = BinaryFlips().minimalMoves(A, B, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int A                     = ;
			int B                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BinaryFlips().minimalMoves(A, B, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int A                     = ;
			int B                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BinaryFlips().minimalMoves(A, B, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int A                     = ;
			int B                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BinaryFlips().minimalMoves(A, B, K);
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
// You are playing a game where you initially have A zeros and B ones.  Your goal is to end up with all ones.  In each move, you must choose exactly K of the numbers and flip their values (zeros change to ones, and vice-versa).  You can choose any K numbers each time, regardless of their current values or whether you have flipped them before.  Return the minimal number of moves required to win the game, or -1 if it is impossible.


DEFINITION
Class:BinaryFlips
Method:minimalMoves
Parameters:int, int, int
Returns:int
Method signature:int minimalMoves(int A, int B, int K)


CONSTRAINTS
-A will be between 0 and 100,000, inclusive.
-B will be between 0 and 100,000, inclusive.
-K will be between 1 and 100,000, inclusive.


EXAMPLES

0)
3
0
3

Returns: 1

You initially have 3 zeros and 0 ones, and you must flip 3 numbers in each move.  Your only possible move is to flip every number.  After the first move, you end up with all ones and win the game.


1)
4
0
3

Returns: 4

This is similar to the previous example, but this time, you have 4 zeros.  Here's one minimal sequence of moves that will lead to a win:

0. 0000 (the initial state)
1. 1110 (first three numbers flipped)
2. 1001 (last three numbers flipped)
3. 0100 (first, second and fourth numbers flipped)
4. 1111 (first, third and fourth numbers flipped)


2)
4
1
3

Returns: 2

3)
3
2
5

Returns: -1

4)
100000
100000
578

Returns: 174

5)
0
0
1

Returns: 0

6)
4
44
50

Returns: -1

*/

// END CUT HERE
