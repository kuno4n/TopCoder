#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset((x), (a), (int)sizeof(x))
#define VI vector < int >
#define LL long long 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FIT(it,v) for(typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define OUT(A) cout << #A << " = " << A << endl

class GogoXBallsAndBinsEasy {
	public:
	int solve(vector <int> T) {
		int res = 0;
        VI _T = T;
        while(next_permutation(T.begin(), T.end())){
            int tmp = 0;
            REP(i, SZ(T)) tmp += abs(T[i] - _T[i]);
            res = max(res, tmp);
        }
        return res/2;
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
			int T[]                   = {0, 2, 5};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = GogoXBallsAndBinsEasy().solve(vector <int>(T, T + (sizeof T / sizeof T[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int T[]                   = {5, 6, 7, 8};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = GogoXBallsAndBinsEasy().solve(vector <int>(T, T + (sizeof T / sizeof T[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int T[]                   = {0, 1, 2, 10};
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = GogoXBallsAndBinsEasy().solve(vector <int>(T, T + (sizeof T / sizeof T[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int T[]                   = {1, 2, 3, 4, 5, 6, 7, 8};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = GogoXBallsAndBinsEasy().solve(vector <int>(T, T + (sizeof T / sizeof T[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int T[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GogoXBallsAndBinsEasy().solve(vector <int>(T, T + (sizeof T / sizeof T[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int T[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GogoXBallsAndBinsEasy().solve(vector <int>(T, T + (sizeof T / sizeof T[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int T[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GogoXBallsAndBinsEasy().solve(vector <int>(T, T + (sizeof T / sizeof T[0])));
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
// Like all other software engineers, Gogo likes to play with bins and balls. He has N bins, numbered 0 through N-1. Yesterday, Gogo distributed all his balls into the bins, placing S[0] balls into bin 0, S[1] balls into bin 1, and so on. No two bins contained the same number of balls. It is possible that one of the bins contained zero balls.

This morning, Gogo attended a lecture about sorting. After he got home, he decided to rearrange the balls in his bins into sorted order. More precisely, he wanted to reach a state with T[0] balls in bin 0, T[1] balls in bin 1, and so on, such that the following two conditions are met:

 T is a permutation of S 
 T is sorted in ascending order 

For example, suppose that S = {2, 5, 0}, i.e., there are 2 balls in bin 0, 5 balls in bin 1, and 0 balls in bin 2. Gogo would rearrange the balls to obtain T = {0, 2, 5}.

When rearranging the balls, Gogo always moves them one ball at a time. In other words, in each move Gogo takes a single ball from one bin and places it into another bin. Gogo is very smart, so he always uses the smallest possible number of moves.

For example, when rearranging S = {2, 5, 0} to T = {0, 2, 5}, Gogo will make exactly 5 moves. One way of changing S to T in 5 moves: first Gogo will move 3 balls from bin 1 to bin 2, and then he will move 2 balls from bin 0 to bin 2.

You just came to visit Gogo. You see that he already rearranged the balls. You are given a vector <int> T containing the current number of balls in each of the bins.

You do not know the original state S. The number of balls Gogo moved depends on S. For example, we already know that for S = {2, 5, 0} Gogo would move 5 balls. If he had S = {0, 5, 2} instead, he would also produce T = {0, 2, 5}, but this time he would only need 3 moves.

Your method must find and return the maximum number of moves Gogo could have performed. In other words, among all sequences S that produce the given sequence T, find one that requires the most moves, and return that number of moves.

DEFINITION
Class:GogoXBallsAndBinsEasy
Method:solve
Parameters:vector <int>
Returns:int
Method signature:int solve(vector <int> T)


CONSTRAINTS
-T will contain between 2 and 10 elements, inclusive.
-Each element of T will be between 0 and 10, inclusive.
-T will be given in a strictly ascending manner. Note that this implies that all the elements of T will be distinct.


EXAMPLES

0)
{0, 2, 5}

Returns: 5

This is the example from the problem statement. No sequence is worse than S = {2, 5, 0}. There are two other sequences S such that Gogo will make exactly 5 moves when producing T = {0, 2, 5}, namely {5, 0, 2} and {5, 2, 0}.

1)
{5, 6, 7, 8}

Returns: 4



2)
{0, 1, 2, 10}

Returns: 11



3)
{1, 2, 3, 4, 5, 6, 7, 8}

Returns: 16



*/

// END CUT HERE
