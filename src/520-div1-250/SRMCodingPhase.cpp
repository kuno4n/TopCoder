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

class SRMCodingPhase {
	public:
	int countScore(vector <int> points, vector <int> skills, int luck) {
		int res = 0;
        REP(t0, 100){
            REP(t1, 100){
                REP(t2, 100){
                    if(t0+t1+t2 > luck) break;
                    if(t0>=skills[0] || t1>=skills[1] || t2>=skills[2]) break;
                    int time[3] = {skills[0]-t0, skills[1]-t1, skills[2]-t2};
                    int pt[3] = {points[0]-2*time[0], points[1]-4*time[1], points[2]-8*time[2]};
                    REP(i, 1<<3){
                        int use = 0;
                        REP(j, 3) if(i&1<<j) use += time[j];
                        if(use > 75) continue;
                        int pt_tmp = 0;
                        REP(j, 3) if(i&1<<j) pt_tmp += pt[j];
                        res = max(res, pt_tmp);
                    }
                }
            }
        }
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
			int points[]              = {250, 500, 1000};
			int skills[]              = {10, 25, 40};
			int luck                  = 0;
			int expected__            = 1310;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int points[]              = {300, 600, 900};
			int skills[]              = {30, 65, 90};
			int luck                  = 25;
			int expected__            = 680;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int points[]              = {250, 550, 950};
			int skills[]              = {10, 25, 40};
			int luck                  = 75;
			int expected__            = 1736;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int points[]              = {256, 512, 1024};
			int skills[]              = {35, 30, 25};
			int luck                  = 0;
			int expected__            = 1216;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int points[]              = {300, 600, 1100};
			int skills[]              = {80, 90, 100};
			int luck                  = 4;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int points[]              = ;
			int skills[]              = ;
			int luck                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int points[]              = ;
			int skills[]              = ;
			int luck                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int points[]              = ;
			int skills[]              = ;
			int luck                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
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
// Mr. Dengklek introduced you to an online programming contest called SRM (Special Round Match)!

You are now in the coding phase of the contest. There are 3 problems in the contest. You have practiced a lot before in practice rooms, so you are sure that you can solve the first problem in skills[0] minutes, the second problem in skills[1] minutes and the third problem is skills[2] minutes.

You have exactly 75 minutes to solve the problems. Before submitting a solution to a problem, you must first open the problem. If you submit a solution to a problem t minutes after you open the problem, you will receive:

(points[0] - 2t) points for the first problem, or
(points[1] - 4t) points for the second problem, or
(points[2] - 8t) points for the third problem.


In your strategy, you only submit a solution to a problem after you solve the problem. If you don't submit a solution to a problem, you will receive zero points for the problem.

It is well-known that luck plays an important role in a contest. A fortune-teller told you that you have luck points of luck. You may use these points to decrease the amount of time you need to solve the problems, in minutes. Of course, you don't have to use all the points. Each point is worth one minute per problem. So, if you initially can solve a problem in t minutes, by using x points of luck (where x is a positive integer and 0 < x < t), you can solve the problem in (t - x) minutes (it is impossible to use t or more points of luck on the problem).

Arrange your strategy in this coding phase. Return the maximum total score you can achieve in this coding phase.

DEFINITION
Class:SRMCodingPhase
Method:countScore
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int countScore(vector <int> points, vector <int> skills, int luck)


CONSTRAINTS
-points will contain exactly 3 elements.
-points[0] will be between 250 and 300, inclusive.
-points[1] will be between 450 and 600, inclusive.
-points[2] will be between 900 and 1100, inclusive.
-skills will contain exactly 3 elements.
-Each element of skills will be between 1 and 100, inclusive.
-luck will be between 0 and 100, inclusive.


EXAMPLES

0)
{250, 500, 1000}
{10, 25, 40}
0

Returns: 1310

You don't have any luck points. However, you can solve all the problems in exactly 75 minutes.

1)
{300, 600, 900}
{30, 65, 90}
25

Returns: 680

Use 25 luck points on the 600-point problem, and then solve the 300- and 600-point problems.

2)
{250, 550, 950}
{10, 25, 40}
75

Returns: 1736

Using the large amount of luck points, solve each problem in only 1 minute.

3)
{256, 512, 1024}
{35, 30, 25}
0

Returns: 1216



4)
{300, 600, 1100}
{80, 90, 100}
4

Returns: 0



*/

// END CUT HERE
