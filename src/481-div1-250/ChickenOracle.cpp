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

class ChickenOracle {
	public:
	string theTruth(int n, int eggCount, int lieCount, int liarCount) {
        bool e = false, c = false;
		REP(i, liarCount+1){
            if(i > lieCount || liarCount-i > n-lieCount) continue;
            if(n - lieCount - liarCount + i*2 == eggCount) e = true;
            if(lieCount + liarCount - i*2 == eggCount) c = true;
        }
        if(e && c) return "Ambiguous";
        if(e) return "The egg";
        if(c) return "The chicken";
        return "The oracle is a lie";
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int n                     = 10;
			int eggCount              = 10;
			int lieCount              = 0;
			int liarCount             = 0;
			string expected__         = "The egg";

			clock_t start__           = clock();
			string received__         = ChickenOracle().theTruth(n, eggCount, lieCount, liarCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 60;
			int eggCount              = 40;
			int lieCount              = 0;
			int liarCount             = 30;
			string expected__         = "The oracle is a lie";

			clock_t start__           = clock();
			string received__         = ChickenOracle().theTruth(n, eggCount, lieCount, liarCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 60;
			int eggCount              = 20;
			int lieCount              = 5;
			int liarCount             = 25;
			string expected__         = "The chicken";

			clock_t start__           = clock();
			string received__         = ChickenOracle().theTruth(n, eggCount, lieCount, liarCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 1000;
			int eggCount              = 500;
			int lieCount              = 250;
			int liarCount             = 250;
			string expected__         = "Ambiguous";

			clock_t start__           = clock();
			string received__         = ChickenOracle().theTruth(n, eggCount, lieCount, liarCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			int n                     = 330;
			int eggCount              = 310;
			int lieCount              = 70;
			int liarCount             = 300;
			string expected__         = "";

			clock_t start__           = clock();
			string received__         = ChickenOracle().theTruth(n, eggCount, lieCount, liarCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 5: {
			int n                     = ;
			int eggCount              = ;
			int lieCount              = ;
			int liarCount             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = ChickenOracle().theTruth(n, eggCount, lieCount, liarCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int eggCount              = ;
			int lieCount              = ;
			int liarCount             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = ChickenOracle().theTruth(n, eggCount, lieCount, liarCount);
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
// This time, instead of solving an easy problem with a known solution, you will be in charge in solving an old problem with a solution which was unknown to this date. The old question is whether the egg or the chicken came first. This question has been very difficult to answer over the ages, but a chance has finally come: It is said that a new oracle has appeared which knows everything.

You tried asking the question to the oracle, but the oracle refused to answer, arguing that it has already answered the question to n other people and is tired of answering that question. Not to give up, you decided to interview each of the n people. Of them, eggCount people told you that the answer was "The egg", while the remaining n-eggCount people claimed that the answer was "The chicken". Confused by the results, you asked the oracle a second time. The oracle still refused to answer the question, but instead explained the results: In order to hide the truth to those unworthy, the oracle has intentionally given the wrong answer to exactly lieCount people. On the other hand, also to avoid sharing the secret, exactly liarCount people (not necessarily those that were told the right answer by the oracle) have intentionally given you the opposite answer to the one given to them by the oracle.

You are still suspiscious that the explanation given by the oracle is another lie. Given ints n, eggCount, lieCount and liarCount, find out if scenarios exist such that "The egg"  or "The chicken" is the correct answer. If there exist scenarios such that either answer is correct, return "Ambiguous" (quotes for clarity). If only one answer has a possible scenario, return "The egg" or "The chicken" (quotes for clarity) depending on the answer. If neither of the answers has a possible scenario, return "The oracle is a lie".

 


DEFINITION
Class:ChickenOracle
Method:theTruth
Parameters:int, int, int, int
Returns:string
Method signature:string theTruth(int n, int eggCount, int lieCount, int liarCount)


CONSTRAINTS
-n will be between 1 and 1000000, inclusive.
-eggCount, lieCount and liarCount will each be between 0 and n, inclusive. 


EXAMPLES

0)
10
10
0
0

Returns: "The egg"

In this case, every person has answered correctly.

1)
60
40
0
30

Returns: "The oracle is a lie"

According to the oracle, it has told the correct answer to all 60 people and then 30 of them lied to you. However, it contradicts the fact that 40 people have told you one answer and 20 people have told another one.

2)
60
20
5
25

Returns: "The chicken"



3)
1000
500
250
250

Returns: "Ambiguous"



*/

// END CUT HERE
