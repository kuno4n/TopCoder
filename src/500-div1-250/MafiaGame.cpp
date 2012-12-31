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

class MafiaGame {
	public:
	double probabilityToLose(int N, vector <int> decisions) {
		int cnt[510] = {0};
        REP(i, SZ(decisions)) cnt[decisions[i]]++;
        int mx = 0;
        REP(i, 510) mx = max(mx, cnt[i]);
        if(mx == 1) return 0.0;
        int vulnerable=0, vote=0;
        REP(i, 510) if(cnt[i] == mx) vulnerable++;
        vote = N - vulnerable*mx;
        double res = 1.0/vulnerable;
        while(1){
            if(vulnerable == 1) return res;
            if(vulnerable == 0) return 0.0;
            vulnerable = vote%vulnerable;
            vote = N - vulnerable*mx;
        }
        return 0.0;
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int N                     = 3;
			int decisions[]           = {1, 1, 1};
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 5;
			int decisions[]           = {1, 2, 3};
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 20;
			int decisions[]           = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 18, 19, 0};
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 23;
			int decisions[]           = {17, 10, 3, 14, 22, 5, 11, 10, 22, 3, 14, 5, 11, 17};
			double expected__         = 0.14285714285714285;

			clock_t start__           = clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int decisions[]           = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			int decisions[]           = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int decisions[]           = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
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
// N friends (numbered from 0 to N-1) play a game called Mafia. The exact rules of the game are not important for this problem. What's important is that at some point in the game they will need to choose one player who will lose and leave the game.

It is known that some players have a definite opinion on who should lose. Their opinions are given in the vector <int> decisions, where each element corresponds to a single opinion and is the number of a player who should lose according to that opinion. All opinions in decisions belong to different players. If decisions contains less than N elements, then all other players do not have a definite opinion on who should lose.

In order to determine who will lose, one or more rounds of voting will be conducted. In each round, there's a set of players for whom the players are allowed to vote. The players in this set are called "vulnerable". It's impossible to vote for players not in this set. Before the first round of voting, all N players are included in this set.

All N players will vote in each round. The voting is held according to the following scheme:

First, each player who has a definite opinion on who should lose is allowed to vote if the player he thinks should lose is "vulnerable" in this round.  All of these players will vote according to their opinions.
Then all other players vote, in order. Each of them votes for the "vulnerable" player who currently has the smallest number of votes (only considering the votes in the current round). If there are several such players, he/she chooses one of them uniformly at random and votes for the chosen player.
Once all players have voted, if there is only one player who has the largest number of votes in the current round, this player loses and leaves the game. In this case there will be no more rounds of voting. Otherwise, the set of "vulnerable" players in the next round is set to all players who have the largest number of votes in the current round.

If it is possible that an infinite number of voting rounds will be held, then return 0. Otherwise, consider an array containing exactly N elements, where the i-th element (0-based) is equal to the probability that the i-th player will lose. Return the maximum value among all elements of this array.

DEFINITION
Class:MafiaGame
Method:probabilityToLose
Parameters:int, vector <int>
Returns:double
Method signature:double probabilityToLose(int N, vector <int> decisions)


NOTES
-The exact numbers of people to whom the opinions in decisions belong are not relevant in this problem.
-It is possible that a player will decide to vote against himself (see example 0). It is also possible that a player will have to vote against himself (if he is one of "vulnerable" players who have the smallest number of votes in the current round).
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-N will be between 2 and 500, inclusive.
-decisions will contain between 1 and min(N, 50) elements, inclusive.
-Each element of decisions will be between 0 and N-1, inclusive.


EXAMPLES

0)
3
{1, 1, 1}

Returns: 1.0

After the first voting round, there will be 3 votes against player 1 and no votes against other players. Therefore player 1 will lose with probability 1.0.

1)
5
{1, 2, 3}

Returns: 0.0

The first round will proceed as follows. The first three votes will be against players 1, 2 and 3. The next vote will be against player 0 with probability 50% (in this case the last vote will be against player 4) or against player 4 with probability 50% (in this case the last vote will be against player 0). In both cases, after the end of the round there will be 1 vote against each player, so the set of "vulnerable" players will remain unchanged.

Each next round will proceed according to the same scenario, so there will be infinitely many rounds.

2)
20
{1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 18, 19, 0}

Returns: 0.0

There can be different voting scenarios, but in each of them the number of "vulnerable" players after the first three rounds is 7, 6 and 2, respectively. Then, starting from the fourth round, there will be exactly 10 votes against each "vulnerable" player, so the set of "vulnerable" players will remain unchanged and there will be infinitely many rounds.

3)
23
{17, 10, 3, 14, 22, 5, 11, 10, 22, 3, 14, 5, 11, 17}

Returns: 0.14285714285714285

There can also be many different voting scenarios, but each of them consists of exactly 3 rounds. Each of players 3, 5, 10, 11, 14, 17, 22 can lose with the same probability of 1/7.

*/

// END CUT HERE
