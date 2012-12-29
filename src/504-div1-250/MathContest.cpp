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

class MathContest {
	public:
	int countBlack(string ballSequence, int repetitions) {
		int res = 0;
        string s = "";
        REP(i, repetitions) s += ballSequence;
        int top = 0, bot = SZ(s)-1;
        bool rev = false, change = false;
        while(top <= bot){
            if(rev){
                if(change){
                    if(s[bot]=='B'){
                        rev = !rev;
                    }
                    else{
                        change = !change;
                        res++;
                    }
                }
                else{
                    if(s[bot]=='B'){
                        change = !change;
                        res++;
                    }
                    else{
                        rev = !rev;
                    }                    
                }
                bot--;
            }
            else{
                if(change){
                    if(s[top]=='B'){
                        rev = !rev;
                    }
                    else{
                        change = !change;
                        res++;
                    }
                }
                else{
                    if(s[top]=='B'){
                        change = !change;
                        res++;
                    }
                    else{
                        rev = !rev;
                    }
                }
                top++;
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
			string ballSequence       = "BBWWB";
			int repetitions           = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MathContest().countBlack(ballSequence, repetitions);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string ballSequence       = "BBB";
			int repetitions           = 10;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MathContest().countBlack(ballSequence, repetitions);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string ballSequence       = "BW";
			int repetitions           = 10;
			int expected__            = 20;

			clock_t start__           = clock();
			int received__            = MathContest().countBlack(ballSequence, repetitions);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string ballSequence       = "WWWWWWWBWWWWWWWWWWWWWW";
			int repetitions           = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MathContest().countBlack(ballSequence, repetitions);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string ballSequence       = ;
			int repetitions           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MathContest().countBlack(ballSequence, repetitions);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string ballSequence       = ;
			int repetitions           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MathContest().countBlack(ballSequence, repetitions);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string ballSequence       = ;
			int repetitions           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MathContest().countBlack(ballSequence, repetitions);
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
// The most famous math contest is going to start soon. As usual in math contests, there is going to be a problem that involves an abstract machine of sorts and predicting how will it process a sequence of colored balls. This time, the machine will use the balls as a special language that works as follows: The process begins when the machine is given a stack of balls that are colored either white or black. The next steps are as follows:
Take the top ball out of the stack, show it to the audience and discard it.
If the taken ball was white, the contents of the stack will be dumped into a new stack and the new stack will be used in the next step. In other words, the order of the balls in the stack will be reversed.
If the taken ball was black, the balls inside the stack will get their colors inverted. Every originally-white ball will turn black and every originally-black ball will turn white.
The process is repeated until there are no balls left in the stack.

You have been hired to make a program to grade the answers to this contest question. Given the contents of the stack, return the number of black balls that will be shown to the audience. Due to limitations in the input size, the contents of the stack are given by string ballSequence, and int repetitions. To form the sequence of balls, repeat ballSequence repetitions times. The final sequence will contain 'B' and 'W' characters denoting a black or a white ball respectively from the top of the stack to the bottom.

DEFINITION
Class:MathContest
Method:countBlack
Parameters:string, int
Returns:int
Method signature:int countBlack(string ballSequence, int repetitions)


CONSTRAINTS
-ballSequence will contain between 1 and 50 characters, inclusive.
-Each character in ballSequence will be 'B' or 'W'.
-repetitions will be between 1 and 3500, inclusive.
-The total number of balls after generating the sequence will be between 1 and 100000, inclusive.


EXAMPLES

0)
"BBWWB"
1

Returns: 2

The starting contents of the stack from top to bottom are: BBWWB. The process can be simulated as follows:

(Stack contents: BBWWB). Take a black ball, change the contents from BWWB to WBBW.
(Stack contents: WBBW). Take a white ball, change the contents from BBW to WBB.
(Stack contents: WBB). Take a white ball, change the contents from BB to BB.
(Stack contents: BB). Take a black ball, change the contents from B to W.
(Stack contents: W). Take a white ball.



1)
"BBB"
10

Returns: 1

There are initially 30 black balls in the stack. After the first one is processed, all the remaining balls become white. A white ball cannot change the color of the remaining balls.

2)
"BW"
10

Returns: 20

A series of alternating black and white balls which begins with a black ball. Initially, a black ball inverts the colors of the remaining balls, making them a new alternation of black and white balls that begins with a black ball. The process will repeat for each ball and each ball will be black when picked.

3)
"WWWWWWWBWWWWWWWWWWWWWW"
1

Returns: 2

Eventually, the black ball will be reached after reversing the order 14 times. It will turn all of the remaining balls black. But the next black ball that is processed will turn all the remaining balls white once again.


*/

// END CUT HERE
