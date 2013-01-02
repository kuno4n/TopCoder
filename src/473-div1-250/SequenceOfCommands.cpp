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

class SequenceOfCommands {
	public:
	string whatHappens(vector <string> commands) {
		int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        
        int lot = 0;
        int pos[2] = {0};
        
        REP(i, 10){
            REP(j, SZ(commands)){
                REP(k, SZ(commands[j])){
                    if(commands[j][k] == 'S'){
                        pos[0] += dx[lot];
                        pos[1] += dy[lot];
                    }
                    else if(commands[j][k] == 'L') lot = (lot+1)%4;
                    else lot = (lot+3)%4;
                }
            }
            
            if(lot == 0 && pos[0] == 0 && pos[1] == 0) return "bounded";
        }
        return "unbounded";
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
			string commands[]         = {"L"};
			string expected__         = "bounded";

			clock_t start__           = clock();
			string received__         = SequenceOfCommands().whatHappens(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string commands[]         = {"SRSL"};
			string expected__         = "unbounded";

			clock_t start__           = clock();
			string received__         = SequenceOfCommands().whatHappens(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string commands[]         = {"SSSS","R"};
			string expected__         = "bounded";

			clock_t start__           = clock();
			string received__         = SequenceOfCommands().whatHappens(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string commands[]         = {"SRSL","LLSSSSSSL","SSSSSS","L"};
			string expected__         = "unbounded";

			clock_t start__           = clock();
			string received__         = SequenceOfCommands().whatHappens(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string commands[]         = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = SequenceOfCommands().whatHappens(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string commands[]         = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = SequenceOfCommands().whatHappens(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string commands[]         = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = SequenceOfCommands().whatHappens(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
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
// 
You are standing on some arbitrary point in the infinite plane.


You are given a vector <string> commands that contains the commands you have to execute.
Each character of each element of commands is one command.
The commands must be executed in the given order: first you execute all commands in the first element of commands one by one, 
then those in the second element, etc.


There are only three types of commands: 'S' means "step forward", 'L' means "turn 90 degrees to the left", and 'R' means "turn 90 degrees to the right". All your steps have the same length.


You will be executing the commands forever: after you execute the last character of the last element of commands, you will always start from the beginning again.


We say that your path is bounded if there is some positive real number R such that while executing the infinite sequence of steps you will never leave the circle with radius R steps and center at your starting location.


Given the vector <string> commands, your method should determine whether your path will be bounded or not. Return the string "bounded" (quotes for clarity) if the path is bounded and "unbounded" if it is not.


DEFINITION
Class:SequenceOfCommands
Method:whatHappens
Parameters:vector <string>
Returns:string
Method signature:string whatHappens(vector <string> commands)


CONSTRAINTS
-commands will contain between 1 and 50 elements, inclusive.
-Each element in commands will contain between 1 and 50 characters, inclusive.
-Each character in each element of commands will be one of 'S', 'L', and 'R'.


EXAMPLES

0)
{"L"}

Returns: "bounded"

You are standing on the same spot forever, and in each step you take a turn 90 degrees to the left. This path is clearly bounded.

1)
{"SRSL"}

Returns: "unbounded"


Imagine that you start executing the commands facing to the north. While following this sequence you will repeatedly execute the following steps: make a step to the north, rotate right, make a step to the east, and rotate left (to face north again).


Given enough time, this path will take you arbitrarily far away from the spot where you started, hence it is unbounded.


2)
{"SSSS","R"}

Returns: "bounded"

While executing this sequence of commands, you will be walking along the boundary of a small square.

3)
{"SRSL","LLSSSSSSL","SSSSSS","L"}

Returns: "unbounded"



*/

// END CUT HERE
