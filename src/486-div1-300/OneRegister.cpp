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

set <LL> seen;

class OneRegister {
	public:
	string getProgram(int s, int t) {
		seen.clear();
        queue<LL> Q;
        queue<string> QS;
        Q.push(s);
        QS.push("");
        seen.insert(s);
        while(SZ(Q)){
            LL k = Q.front();
            string l = QS.front();
            Q.pop();
            QS.pop();
            
            if(k == t) return l;
            
            LL mul = k*k;
            if(seen.find(mul) == seen.end() && (mul <= s || mul <= t)){
                seen.insert(mul);
                Q.push(mul);
                QS.push(l + '*');
            }
            
            LL plus = k+k;
            if(seen.find(plus) == seen.end() && (plus <= s || plus <= t)){
                seen.insert(plus);
                Q.push(plus);
                QS.push(l + '+');
            }
            
            LL div = 1;
            if(seen.find(div) == seen.end()){
                seen.insert(div);
                Q.push(div);
                QS.push(l + '/');
            }
            
        }
        return ":-(";
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
			int s                     = 7;
			int t                     = 392;
			string expected__         = "+*+";

			clock_t start__           = clock();
			string received__         = OneRegister().getProgram(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int s                     = 7;
			int t                     = 256;
			string expected__         = "/+***";

			clock_t start__           = clock();
			string received__         = OneRegister().getProgram(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int s                     = 4;
			int t                     = 256;
			string expected__         = "**";

			clock_t start__           = clock();
			string received__         = OneRegister().getProgram(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int s                     = 7;
			int t                     = 7;
			string expected__         = "";

			clock_t start__           = clock();
			string received__         = OneRegister().getProgram(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int s                     = 7;
			int t                     = 9;
			string expected__         = ":-(";

			clock_t start__           = clock();
			string received__         = OneRegister().getProgram(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int s                     = 10;
			int t                     = 1;
			string expected__         = "/";

			clock_t start__           = clock();
			string received__         = OneRegister().getProgram(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int s                     = ;
			int t                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = OneRegister().getProgram(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int s                     = ;
			int t                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = OneRegister().getProgram(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int s                     = ;
			int t                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = OneRegister().getProgram(s, t);
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
You've designed a computer and implemented all the common arithmetic operators: addition, subtraction, multiplication and integer division.  However, your budget was very limited, so you could only afford to place a single register in the computer.  The register can store any non-negative integer value.  Since there is only one register, there is no need to identify the store location or the operands of each operation or its result.  The programming language has four instructions: '+', '-', '*' and '/'.  Each instruction performs the corresponding operation using the value in the register as both its parameters.  It then stores the result in the same register, overwriting the previous content.

A program for your computer is a sequential list of zero or more instructions.  You want to show that, even with its limitations, your newly constructed computer is powerful.  You will be given two ints s and t.  Return the shortest program that finishes with a value of t in the register if it contained s before executing.  If there is more than one possible answer, return the one that comes earliest lexicographically.  If there is no program that can do the job, return ":-(" (quotes for clarity) instead.


DEFINITION
Class:OneRegister
Method:getProgram
Parameters:int, int
Returns:string
Method signature:string getProgram(int s, int t)


NOTES
-A string comes lexicographically earlier than another one of the same length if and only if it contains a symbol with a lower ASCII code in the first position at which they differ. The operators in ascending order of ASCII code are: '*', '+', '-' and '/'.
-If the division operation is used when the register contains a zero, the program will give an error and terminate with a zero value in the register.


CONSTRAINTS
-s and t will be between 1 and 1000000000 (10^9), inclusive.


EXAMPLES

0)
7
392

Returns: "+*+"

The program executes as follows:

 Reg | Ins | Res
-----+-----+-----
   7 |  +  |  14
  14 |  *  | 196
 196 |  +  | 392


1)
7
256

Returns: "/+***"



2)
4
256

Returns: "**"



3)
7
7

Returns: ""

A trivial program.

4)
7
9

Returns: ":-("

No solution.

5)
10
1

Returns: "/"



*/

// END CUT HERE
