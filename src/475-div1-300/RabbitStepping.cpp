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

class RabbitStepping {
	public:
	double getExpected(string field, int r) {
		int cnt = 0, sum = 0;
        
        int comb = (1<<r)-1;
        while(comb < 1<<SZ(field)){
            cnt++;
            int before = -1;
            int next = comb;
            for(int sz = SZ(field); sz>2; sz--){
                int init = next;
                VI vi(sz);
                REP(i, sz) vi[i] = 0;
                REP(i, sz){
                    if(!((1<<i) & init)) continue;
                    else if(i==0) vi[1]++;
                    else if(i==sz-1) vi[sz-2]++;
                    else if(i==sz-2) vi[sz-3]++;
                    else if(field[i] == 'W') vi[i-1]++;
                    else if(field[i] == 'B') vi[i+1]++;
                    else{
                        if(before == -1) vi[i-1]++;
                        else if(field[i+1]=='W' && (1<<(i+1) & before)) vi[i+1]++;
                        else vi[i-1]++;
                    }
                }
                next = 0;
                REP(i, sz) if(vi[i] == 1) next += (1<<i);
                before = init;
            }
            if(next == 1 || next == 2) sum += 1;
            else if(next == 3) sum += 2;
            
            int x = comb & -comb, y = comb + x;
            comb = ((comb & ~y) / x>>1) | y;
        }
        return (double)sum/cnt;
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
			string field              = "WRBRW";
			int r                     = 4;
			double expected__         = 0.8;

			clock_t start__           = clock();
			double received__         = RabbitStepping().getExpected(field, r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string field              = "WWB";
			int r                     = 2;
			double expected__         = 1.3333333333333333;

			clock_t start__           = clock();
			double received__         = RabbitStepping().getExpected(field, r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string field              = "WW";
			int r                     = 1;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = RabbitStepping().getExpected(field, r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string field              = "BBBBBBBBBB";
			int r                     = 4;
			double expected__         = 0.9523809523809523;

			clock_t start__           = clock();
			double received__         = RabbitStepping().getExpected(field, r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string field              = "RRBRRWRRBRRW";
			int r                     = 8;
			double expected__         = 0.9696969696969697;

			clock_t start__           = clock();
			double received__         = RabbitStepping().getExpected(field, r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string field              = ;
			int r                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = RabbitStepping().getExpected(field, r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string field              = ;
			int r                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = RabbitStepping().getExpected(field, r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string field              = ;
			int r                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = RabbitStepping().getExpected(field, r);
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
// Rabbits often feel lonely, so one group of rabbits decided to gather together and play a game. 

The game is played on a horizontal row of N cells (N >= 2), numbered 0 to N - 1 from left to right. 
Each cell is colored white, black or red. 
You are given a string field of length N, 
where the i-th character is the color of cell i ('W' for white, 'B' for black and 'R' for red). 

There are r rabbits playing the game. 
The rabbits choose their starting cells randomly such that no two rabbits are on the same cell. 
Each subset of r distinct cells has the same probability of being chosen as their starting cells. 
The size of the field is the number of cells it contains (which is initially N). 
The following is repeated while the size of the field is greater than 2: 


	Each rabbit steps onto a neighboring cell. 
	Since each cell potentially has up to two neighboring cells, 
	the following rules are used to determine which cell the rabbit will choose: 
	
		If a rabbit is on cell 0, she must step onto cell 1. 
		If a rabbit is on cell size - 1 or size - 2, she must step onto the left neighboring cell. 
		All other rabbits choose which neighboring cell to step onto according to the color of the cell they are currently on: 
		
			White: She must step onto the left neighboring cell. 
			Black: She must step onto the right neighboring cell. 
			Red: If this is her first move, she must step onto the left neighboring cell. 
			Otherwise, she must return to the cell she was on immediately before she was on the current cell. 
		
		
	
	
	After all rabbits finished their steps, for each cell that contains more than one rabbit, all rabbits on that cell will be removed from the field. 
	The rightmost cell will disappear (causing the size of the field to decrease by 1). 
	By the rules above, this cell will always be empty. 


When the game ends, 0, 1 or 2 rabbits will remain on the field. 
Return the expected number of rabbits left on the field when the game ends. 



DEFINITION
Class:RabbitStepping
Method:getExpected
Parameters:string, int
Returns:double
Method signature:double getExpected(string field, int r)


NOTES
-The returned value must have an absolute or relative error less than 1e-9. 


CONSTRAINTS
-field will contain between 2 and 17 characters, inclusive. 
-Each character in field will be either 'W', 'B', or 'R'. 
-r will be between 1 and N, inclusive, where N is the number of characters in field. 


EXAMPLES

0)
"WRBRW"
4

Returns: 0.8

The initial positions of the rabbits are cells 
{ 0, 1, 2, 3 }, { 0, 1, 2, 4 }, { 0, 1, 3, 4 }, { 0, 2, 3, 4 }, or { 1, 2, 3, 4 }. 
For example, if { 0, 1, 2, 4 } is chosen, 
they will step as follows and 2 rabbits will remain on the field: 




1)
"WWB"
2

Returns: 1.3333333333333333

2)
"WW"
1

Returns: 1.0

No moves will be performed, and one rabbit will remain alone on the field. 


3)
"BBBBBBBBBB"
4

Returns: 0.9523809523809523

4)
"RRBRRWRRBRRW"
8

Returns: 0.9696969696969697

*/

// END CUT HERE
