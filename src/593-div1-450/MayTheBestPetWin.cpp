
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


class MayTheBestPetWin {
public:
   int calc( vector <int> A, vector <int> B ) {
	VI cur(1000010, 0);
	cur[0] = 1;
	VI nxt = cur;
	int n = SZ(A);
	REP(i, n){
		REP(j, 1000010) if(cur[j]) nxt[j] = true, nxt[j+A[i]+B[i]] = true;
//		swap(cur, nxt);
		cur = nxt;
	}
	int res = (1<<29);
	int SA = accumulate(ALL(A), 0), SB = accumulate(ALL(B), 0);
	REP(i, 1000010) if(cur[i]) chmin(res, max(i-SA, -(i-SB)));
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
			int A[]                   = {3,4,4,7};
			int B[]                   = {3,4,4,7};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MayTheBestPetWin().calc(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A[]                   = {1,3,5,4,5};
			int B[]                   = {2,5,6,8,7};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MayTheBestPetWin().calc(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A[]                   = {2907,949,1674,6092,8608,5186,2630,970,1050,2415,1923,2697,5571,6941,8065,4710,716,756,5185,1341,993,5092,248,1895,4223,1783,3844,3531,2431,1755,2837,4015};
			int B[]                   = {7296,6954,4407,9724,8645,8065,9323,8433,1352,9618,6487,7309,9297,8999,9960,5653,4721,7623,6017,7320,3513,6642,6359,3145,7233,5077,6457,3605,2911,4679,5381,6574};
			int expected__            = 52873;

			clock_t start__           = clock();
			int received__            = MayTheBestPetWin().calc(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MayTheBestPetWin().calc(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MayTheBestPetWin().calc(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MayTheBestPetWin().calc(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
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
// The pony Rainbow Dash wants to choose her pet.
There are N animals who want to be her pet.
Rainbow Dash numbered them 0 through N-1.

To help her make the decision, Rainbow Dash decided to organize a relay race for the animals.
The race track is already known, and for each animal we know how fast it is.
More precisely, you are given vector <int>s A and B with the following meaning:
For each i, the animal number i will take between A[i] and B[i] seconds (inclusive) to complete the track.

For the race the animals will be divided into two competing teams.
This is a relay race, so the team members of each team will all run the same track, one after another --
when the first team member finishes, the second one may start, and so on.
Thus the total time in which a team completes the race is the sum of the times of all team members.
Note that we can use the estimates given by A and B to estimate the total time for any team of animals.

Given two teams S and T, the value maxdiff(S,T) is defined as the largest possible difference in seconds
between the time in which team S finishes the course and the time in which team T finishes the course.

Rainbow Dash now needs to assign each of the animals to one of the two competing teams.
She wants to see a close competition, so she wants the teams to finish as close to each other as possible.
Formally, she wants to divide all animals into teams S and T in a way that minimizes maxdiff(S,T).
Return the smallest possible value of maxdiff(S,T).

DEFINITION
Class:MayTheBestPetWin
Method:calc
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int calc(vector <int> A, vector <int> B)


NOTES
-The teams are not required to contain the same number of animals.


CONSTRAINTS
-A will contain between 2 and 50 elements, inclusive.
-A and B will contain the same number of elements.
-Each element of A will be between 1 and 10,000, inclusive.
-Each element of B will be between 1 and 10,000, inclusive.
-For each i, B[i] will be greater than or equal to A[i].


EXAMPLES

0)
{3,4,4,7}
{3,4,4,7}

Returns: 2

In this test case we know the exact time in which each of the animals completes the track.
An optimal solution is to choose teams S={0,3} and T={1,2}.
Then team S will certainly complete the track in 3+7 = 10 seconds, and team T in 4+4 = 8 seconds.
Thus, maxdiff(S,T)=2.

1)
{1,3,5,4,5}
{2,5,6,8,7}

Returns: 5

Here one of the optimal solutions is S={2,3} and T={0,1,4}.
For these two teams we have maxdiff(S,T)=5.
For example, it is possible that S will complete the track in 6+8 = 14 seconds, and T will complete it in 1+3+5 = 9 seconds.
It is also possible that S will complete the track up to 5 seconds before T does.

2)
{2907,949,1674,6092,8608,5186,2630,970,1050,2415,1923,2697,5571,6941,8065,4710,716,756,5185,1341,993,5092,248,1895,4223,1783,3844,3531,2431,1755,2837,4015}
{7296,6954,4407,9724,8645,8065,9323,8433,1352,9618,6487,7309,9297,8999,9960,5653,4721,7623,6017,7320,3513,6642,6359,3145,7233,5077,6457,3605,2911,4679,5381,6574}

Returns: 52873



*/

// END CUT HERE
