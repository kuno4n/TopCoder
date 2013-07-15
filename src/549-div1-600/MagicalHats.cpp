
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

const int MX = 1600000, INF = (1<<29);
int n, m;
int h, w, hx[13], hy[13], hat;
int pw[15];

int dp[MX];
bool valid[MX];


int bitcnt(LL n){
    int c;
    for(c=0;n!=0;c++,n&=n-1) ;
    return c;
}


int rec(int bit, int step){
	int &res = dp[bit];
	if(res >= 0) return res;
	if(!valid[bit]) return res = INF;
	
	int b[hat];
	REP(i, hat) b[i] = bit%3, bit /= 3;
	
	if(step == m){
		int cnt = 0;
		REP(i, hat) if(b[i] == 1) cnt++;
		return res = cnt;
	}
	
	REP(i, hat) if(b[i] == 0){
		int tmp = INF;
		for(int j = 1; j <= 2; j++){
			b[i] = j;
			int nbit = 0;
			REP(i, hat) nbit += b[i]*pw[i];
			chmin(tmp, rec(nbit, step+1));
		}
		b[i] = 0;
		chmax(res, tmp);
	}
	return res;
}

class MagicalHats {
public:
   int findMaximumReward( vector <string> board, vector <int> coins, int numGuesses ) {
	n = SZ(coins), m = numGuesses;
	h = SZ(board), w = SZ(board[0]);
	pw[0] = 1; 
	for(int i = 1; i <= 13; i++) pw[i] = pw[i-1] * 3;
	
	hat = 0;
	REP(i, h) REP(j, w) if(board[i][j] == 'H') hx[hat] = i, hy[hat++] = j;
	
	MSET(valid, false);
	REP(mask, (1<<hat)) if(bitcnt(mask) == n){
		int cnth[h], cntw[w];
		MSET(cnth, 0), MSET(cntw, 0);
		REP(i, hat) cnth[hx[i]]++, cntw[hy[i]]++;
		REP(i, hat) if(mask & (1<<i)) cnth[hx[i]]++, cntw[hy[i]]++;
		REP(i, hat) if(cnth[hx[i]] & 1 || cntw[hy[i]] & 1) goto FAIL;
		
		REP(mask2, (1<<hat)){
			int bit = 0;
			REP(i, hat) if(mask2 & (1<<i)){
				if(mask & (1<<i)) bit += pw[i];
				else  bit += pw[i]*2;
			}
			valid[bit] = true;
		}
		
		FAIL:;
	}
	
	MSET(dp, -1);
	int ans = rec(0, 0);
	if(ans == INF) return -1;
	
	sort(ALL(coins));
	int res = 0;
	REP(i, ans) res += coins[i];
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
			string board[]            = {"H"};
			int coins[]               = {1};
			int numGuesses            = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"HHH",
 "H.H",
 "HH."};
			int coins[]               = {9};
			int numGuesses            = 1;
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"HH",
 "HH"};
			int coins[]               = {1,2,3,4};
			int numGuesses            = 3;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"HHH",
 "HHH",
 "H.H"};
			int coins[]               = {13,13,13,13};
			int numGuesses            = 2;
			int expected__            = 13;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"HHH",
 "HHH",
 "H.H"};
			int coins[]               = {13,13,13,13};
			int numGuesses            = 3;
			int expected__            = 26;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string board[]            = {"H.H.",
 ".H.H",
 "H.H."};
			int coins[]               = {17};
			int numGuesses            = 6;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string board[]            = {"HHH",
 "H.H",
 "HHH",
 "H.H",
 "HHH"};
			int coins[]               = {33,337,1007,2403,5601,6003,9999};
			int numGuesses            = 5;
			int expected__            = 1377;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			string board[]            = {".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".....H.H.....",
 "......H......",
 ".....H.H.....",
 ".............",
 ".............",
 ".............",
 "............."};
			int coins[]               = {22};
			int numGuesses            = 3;
			int expected__            = 22;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			string board[]            = ;
			int coins[]               = ;
			int numGuesses            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string board[]            = ;
			int coins[]               = ;
			int numGuesses            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			string board[]            = ;
			int coins[]               = ;
			int numGuesses            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
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
// A magician has challenged you to a game of wits. First he shows you some coins. Different coins may have different values. Next he takes some hats and hides all the coins inside the hats, in such a way that no two coins are hidden in the same hat. Finally, he places each of the hats with their respective coin onto some cell of a checkerboard. Now he has given you some guesses. In each guess you may ask the magician to reveal the contents of one of the hats. 

After you make your guess, but before he reveals the contents of a hat, the magician may magically reshuffle all coins that are still hidden. That is, he can use a magic spell to redistribute the coins among all hats that still were not revealed, including the hat you just selected. After reshuffling, each hat must again contain at most one coin. 

After you make a guess and the magician reshuffles the hidden coins, the hat you selected is flipped upside down (and remains in this state until the end of the game). If it contained a coin, the coin remains in the hat, but it is now visible and the magician cannot move it in the future. If it did not contain a coin, the magician can't ever put a coin into this hat anymore. 

Furthermore, the magician has given you one more set of guarantees.
At any moment in the game, the following constraints will all be satisfied:

For each row, the number of hats in the row plus the number of coins in the row will be an even number.
For each column, the number of hats in the column plus the number of coins in the column will be an even number.


You are given a vector <string> board representing the checkerboard. The j-th character of the i-th element of board is 'H' when there is a hat at row i column j of the checkerboard and '.' otherwise. You are also given an vector <int> coins representing the different coins that are hidden under hats. You are also given an int numGuesses representing the number of guesses that you get.

At the end of the game you get to keep all the coins that were revealed while playing. Your goal is to maximize the total value of the coins you get. The magician's goal is to minimize the total value of the coins you get. If it is not possible to hide all the coins in coins under the hats on the given board while meeting all the constraints above, return -1. Otherwise, return the total value of coins you'll get, assuming both you and the magician play optimally.

DEFINITION
Class:MagicalHats
Method:findMaximumReward
Parameters:vector <string>, vector <int>, int
Returns:int
Method signature:int findMaximumReward(vector <string> board, vector <int> coins, int numGuesses)


CONSTRAINTS
-board will contain between 1 and 13 elements, inclusive.
-Each element of board will contain between 1 and 13 characters, inclusive.
-Each element of board will contain the same number of characters.
-Each character of each element of board will be either 'H' or '.'.
-board will contain at most 13 occurrences of the character 'H'.
-coins will contains between 1 and 13 elements, inclusive.
-Each element of coins will be between 1 and 10,000, inclusive.
-There will always be at least as many 'H' characters in board as elements in coins.
-numGuesses will be between 1 and the number of 'H' characters in board, inclusive.


EXAMPLES

0)
{"H"}
{1}
1

Returns: 1

One guess for one hat. The reward is just the contents of the hat.

1)
{"HHH",
 "H.H",
 "HH."}
{9}
1

Returns: 9

The only position the 9 coin can possibly be in is the top left corner.

2)
{"HH",
 "HH"}
{1,2,3,4}
3

Returns: 6

The magician manages to always give you the worst possible reward regardless of how you guess.

3)
{"HHH",
 "HHH",
 "H.H"}
{13,13,13,13}
2

Returns: 13



4)
{"HHH",
 "HHH",
 "H.H"}
{13,13,13,13}
3

Returns: 26



5)
{"H.H.",
 ".H.H",
 "H.H."}
{17}
6

Returns: -1



6)
{"HHH",
 "H.H",
 "HHH",
 "H.H",
 "HHH"}
{33,337,1007,2403,5601,6003,9999}
5

Returns: 1377



7)
{".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".....H.H.....",
 "......H......",
 ".....H.H.....",
 ".............",
 ".............",
 ".............",
 "............."}
{22}
3

Returns: 22



*/

// END CUT HERE
