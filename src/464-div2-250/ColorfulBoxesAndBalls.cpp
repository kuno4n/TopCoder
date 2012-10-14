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

class ColorfulBoxesAndBalls {
	public:
	int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors) {
		int a = min(numRed, numBlue);
        return max(numRed*onlyRed + numBlue*onlyBlue,
                   a *
                   bothColors *
                   2 +
                   (numRed+numBlue-a*2)*(numRed<numBlue ? onlyBlue : onlyRed));
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
			int numRed                = 2;
			int numBlue               = 3;
			int onlyRed               = 100;
			int onlyBlue              = 400;
			int bothColors            = 200;
			int expected__            = 1400;

			clock_t start__           = clock();
			int received__            = ColorfulBoxesAndBalls().getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int numRed                = 2;
			int numBlue               = 3;
			int onlyRed               = 100;
			int onlyBlue              = 400;
			int bothColors            = 300;
			int expected__            = 1600;

			clock_t start__           = clock();
			int received__            = ColorfulBoxesAndBalls().getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int numRed                = 5;
			int numBlue               = 5;
			int onlyRed               = 464;
			int onlyBlue              = 464;
			int bothColors            = 464;
			int expected__            = 4640;

			clock_t start__           = clock();
			int received__            = ColorfulBoxesAndBalls().getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int numRed                = 1;
			int numBlue               = 4;
			int onlyRed               = 20;
			int onlyBlue              = -30;
			int bothColors            = -10;
			int expected__            = -100;

			clock_t start__           = clock();
			int received__            = ColorfulBoxesAndBalls().getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int numRed                = 9;
			int numBlue               = 1;
			int onlyRed               = -1;
			int onlyBlue              = -10;
			int bothColors            = 4;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ColorfulBoxesAndBalls().getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int numRed                = ;
			int numBlue               = ;
			int onlyRed               = ;
			int onlyBlue              = ;
			int bothColors            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulBoxesAndBalls().getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int numRed                = ;
			int numBlue               = ;
			int onlyRed               = ;
			int onlyBlue              = ;
			int bothColors            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulBoxesAndBalls().getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int numRed                = ;
			int numBlue               = ;
			int onlyRed               = ;
			int onlyBlue              = ;
			int bothColors            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulBoxesAndBalls().getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors);
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
// You are playing a game where you have numRed red boxes, numBlue blue boxes, 
numRed red balls, and numBlue blue balls. 
You must place a single ball into each box. 
Each box is then scored as follows: 

	If the box is red and it contains a red ball, you get onlyRed points. 
	If the box is blue and it contains a blue ball, you get onlyBlue points. 
	In all other cases, you get bothColors points. 

Your total score is the sum of the scores of all the boxes. 
Return the maximum possible total score you can get. 


DEFINITION
Class:ColorfulBoxesAndBalls
Method:getMaximum
Parameters:int, int, int, int, int
Returns:int
Method signature:int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors)


CONSTRAINTS
-numRed and numBlue will each be between 1 and 100, inclusive. 
-onlyRed, onlyBlue, and bothColors will each be between -1000 and 1000, inclusive. 


EXAMPLES

0)
2
3
100
400
200

Returns: 1400


In this example, you should put two red balls into red boxes, and three blue balls into blue boxes. 
Then you can get 100 * 2 + 400 * 3 = 1400 points in total. 


1)
2
3
100
400
300

Returns: 1600


bothColors is a larger value here than it was in the previous example. 
You should put two blue balls into red boxes, and two red balls and one blue ball into blue boxes. 
Then you can get 300 * 4 + 400 * 1 = 1600 points. 


2)
5
5
464
464
464

Returns: 4640

No matter how you place the balls, your score will always be the same. 


3)
1
4
20
-30
-10

Returns: -100

The maximum total score may be less than zero. 


4)
9
1
-1
-10
4

Returns: 0



*/

// END CUT HERE
