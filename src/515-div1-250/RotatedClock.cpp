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

string conv(int a){
    string res = "";
    res += '0' + (a/10);
    res += '0' + (a%10);
    return res;
}

class RotatedClock {
	public:
	string getEarliest(int hourHand, int minuteHand) {
        if(minuteHand%6) return "";
		REP(i, 12){
            int m = (i*5 + minuteHand/6) % 60;
            int h = (i + (hourHand)/30) % 12;
            if((hourHand % 30) * 2 == m) return conv(h) + ':' + conv(m);
        }
        
        return "";
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
			int hourHand              = 70;
			int minuteHand            = 300;
			string expected__         = "08:20";

			clock_t start__           = clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int hourHand              = 90;
			int minuteHand            = 120;
			string expected__         = "11:00";

			clock_t start__           = clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int hourHand              = 240;
			int minuteHand            = 36;
			string expected__         = "";

			clock_t start__           = clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int hourHand              = 19;
			int minuteHand            = 19;
			string expected__         = "";

			clock_t start__           = clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int hourHand              = 1;
			int minuteHand            = 12;
			string expected__         = "00:02";

			clock_t start__           = clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int hourHand              = ;
			int minuteHand            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int hourHand              = ;
			int minuteHand            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int hourHand              = ;
			int minuteHand            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
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
// Lecette has a clock with an hour hand and a minute hand. 
The hour hand makes a full rotation in 12 hours, and the minute hand makes a full rotation in one hour. 
Both hands move smoothly, at constant speeds. 
The clock has a scale marked in 30 degree increments, and both hands point to the same mark at 00:00. 

Lecette wants to know what time it is, but the clock is rotated, so she can't tell where the top of the clock is. 
She measured the angles of hands from a certain mark, clockwise: 
hourHand and minuteHand (both in degrees). 
Return the earliest possible time that is consistent with these measurements. 
Format the return value as a string of the form "HH:MM" (quotes for clarity). 
Lecette might have measured the angles incorrectly. 
If there is no corresponding time, return an empty string instead. 


DEFINITION
Class:RotatedClock
Method:getEarliest
Parameters:int, int
Returns:string
Method signature:string getEarliest(int hourHand, int minuteHand)


CONSTRAINTS
-hourHand and minuteHand will each be between 0 and 359, inclusive. 


EXAMPLES

0)
70
300

Returns: "08:20"

This is how the clock were positioned when Lecette made her measurements: 



In order to show a valid time, the clock needs to be turned upside down: 




1)
90
120

Returns: "11:00"

2)
240
36

Returns: ""

3)
19
19

Returns: ""

4)
1
12

Returns: "00:02"

The time when the coding phase started. 


*/

// END CUT HERE
