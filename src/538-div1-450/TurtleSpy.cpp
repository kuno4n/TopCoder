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
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }

const double PI = 3.1415926535897932384;

double cal(int a, int b, int deg){
    double d = PI * (deg/180.0);
    double x = a - b*cos(d);
    double y = b*sin(d);
    return sqrt(x*x + y*y);
}

class TurtleSpy {
	public:
	double maxDistance(vector <string> commands) {
		VI fo, ba, de;
        REP(i, SZ(commands)){
            stringstream ss;
            ss << commands[i];
            string s;
            int in;
            ss >> s >> in;
            if(s == "forward") fo.push_back(in);
            if(s == "backward") ba.push_back(in);
            if(s == "left") de.push_back(in);
            if(s == "right") de.push_back(-in);
        }
        
        bool memo[360]; MSET(memo, false);
        memo[0] = true;
        REP(i, SZ(de)){
            bool tmp[360];
            REP(j, 360) tmp[j] = memo[j];
            REP(j, 360) if(memo[j]) tmp[(j+de[i]+360)%360] = true;
            REP(j, 360) memo[j] |= tmp[j];
        }
        int deg = 0;
        REP(i, 360) if(memo[i] && abs(180-deg) > abs(180-i)) deg = i;
        int a = accumulate(ALL(fo), 0);
        int b = accumulate(ALL(ba), 0);
        return max(cal(a, b, deg), cal(b, a, deg));
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
			string commands[]         = {"forward 100", "backward 100", "left 90" };
			double expected__         = 141.4213562373095;

			clock_t start__           = clock();
			double received__         = TurtleSpy().maxDistance(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string commands[]         = {"left 45", "forward 100", "right 45", "forward 100"};
			double expected__         = 200.0;

			clock_t start__           = clock();
			double received__         = TurtleSpy().maxDistance(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string commands[]         = {"left 10", "forward 40",  "right 30", "left 10", "backward 4", "forward 4" };
			double expected__         = 40.58520737741619;

			clock_t start__           = clock();
			double received__         = TurtleSpy().maxDistance(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			string commands[]         = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TurtleSpy().maxDistance(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			string commands[]         = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TurtleSpy().maxDistance(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string commands[]         = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TurtleSpy().maxDistance(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
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
// The Very Heterogeneous State of Feudalia's army is designing a new spy robot. The robot is disguised as a turtle and takes four different commands:

"right X", where X is a integer between 1 and 359, inclusive. Will add X degrees to the turtle's direction angle. 
"left X", where X is a integer between 1 and 359, inclusive. Will subtract X degrees from the turtle's direction angle. 
"forward X", where X is a integer. Will move X units in the direction given by the turtle's direction angle.
"backward X", where X is a integer. Will move X units in the opposite direction of the turtle's direction angle (The angle minus 180 degrees).

The army created a program that made the robot infiltrate deeply into foreign land by making the robot terminate as far as possible from the original location. Unfortunately, Feudalia is world famous for the ineptitude of its public officials. The program got mixed up and there is no way to tell the original order of the commands. You are given a vector <string> commands. Each element of commands represents a command in the described format. Find the order for all of the commands in the input that will maximize the Euclidean distance between the point where the robot was started and the point it reached after all commands were executed. Return the maximum distance.



DEFINITION
Class:TurtleSpy
Method:maxDistance
Parameters:vector <string>
Returns:double
Method signature:double maxDistance(vector <string> commands)


NOTES
-The Euclidean distance between the points (x1,y1) and (x2,y2) is sqrt( (x2-x1)^2 + (y2-y1)^2 ).
-Your return value must be within 1e-9 relative or absolute error of the correct value


CONSTRAINTS
-commands will contain between 1 and 50 elements, inclusive.
-Each element of commands will be a string in the form "COMM X", where COMM is one of "left", "right", "forward" or "backward" (quotes for clarity) and X is a integer between 1 and 1000, inclusive.
-For each element of commands, if the command is "left" or "right" then X will not exceed 359.


EXAMPLES

0)
{"forward 100", "backward 100", "left 90" }

Returns: 141.4213562373095

That distance is possible if we make sure to run the "left 90" command inbetween the other two commands.

1)
{"left 45", "forward 100", "right 45", "forward 100"}

Returns: 200.0

We can, for example, run the commands in the following order:
 "forward 100", "left 45", "right 45" and "forward 100".



2)
{"left 10", "forward 40",  "right 30", "left 10", "backward 4", "forward 4" }

Returns: 40.58520737741619



*/

// END CUT HERE
