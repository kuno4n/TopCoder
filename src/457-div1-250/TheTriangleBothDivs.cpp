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

class TheTriangleBothDivs {
	public:
	string fix(string time) {
		string hh = time.substr(0,2);
        string mm = time.substr(3,2);
        char a = time[9];
        char d = time[10];
        
        int resh = 23;
        REP(h1, 3){
            if(hh[0] != '?' && hh[0]-'0' != h1) continue;
            REP(h2, 10){
                if(hh[1] != '?' && hh[1]-'0' != h2) continue;
                if(h1*10 + h2 > 23) continue;
                REP(diff, 10){
                    int h = h1*10 + h2;
                    if(d != '?' && d-'0' != diff) continue;
                    if(a == '-' && diff == 0) continue;
                    if(a == '+') h = (h-diff+24)%24;
                    else if(a == '-') h = (h+diff)%24;
                    else h = min( (h-diff+24)%24, (h+diff)%24);
                    resh = min(resh, h);
                }
            }
        }
        
        if(mm[0] == '?') mm[0] = '0';
        if(mm[1] == '?') mm[1] = '0';
        
        string res = "     ";
        res[0] = (resh/10)+'0';
        res[1] = (resh%10)+'0';
        res[2] = ':';
        res[3] = mm[0];
        res[4] = mm[1];
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
			string time               = "17:45 GMT-4";
			string expected__         = "21:45";

			clock_t start__           = clock();
			string received__         = TheTriangleBothDivs().fix(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string time               = "16:?? GMT??";
			string expected__         = "00:00";

			clock_t start__           = clock();
			string received__         = TheTriangleBothDivs().fix(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string time               = "?1:34 GMT-9";
			string expected__         = "06:34";

			clock_t start__           = clock();
			string received__         = TheTriangleBothDivs().fix(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string time               = "??:?? GMT??";
			string expected__         = "00:00";

			clock_t start__           = clock();
			string received__         = TheTriangleBothDivs().fix(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			string time               = "1?:45 GMT+?";
			string expected__         = "01:45";

			clock_t start__           = clock();
			string received__         = TheTriangleBothDivs().fix(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 5: {
			string time               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheTriangleBothDivs().fix(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string time               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheTriangleBothDivs().fix(time);
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
// John and Brus have always been confused by time zones.  Their recent promotions to Concorde pilot and copilot do not help.  Having to constantly fly through the Bermuda Triangle does not help either.  They have therefore purchased a special digital clock that displays the current time in one of 19 time zones, from GMT-9 to GMT+9.  The clock displays time in the format "HH:mm GMTof" (quotes for clarity), where HH is the hour of the day (between 00 and 23, inclusive), mm is the number of minutes since the start of the hour (between 00 and 59, inclusive), and of is the offset from "Greenwich Mean Time" (time zone GMT+0) to the current time zone.  If the offset is +4, for example, it means the displayed time is 4 hours ahead of the time in GMT+0, and if the offset is -4, it means the time is 4 hours behind the time in GMT+0.  GMT+0 will always be displayed with an offset of +0, so the clock will never display it as GMT-0.

In the middle of a flight, John wanted to know what time it was, so he asked Brus to check the clock.  To Brus' surprise, the Bermuda Triangle had caused the clock to malfunction, and some of the characters on the display were unrecognizable.  You are given the clock's display as a string time, where '?' characters represent the unrecognizable characters.  Assuming that all the recognizable characters are accurate, determine what time it is in time zone GMT+0.  Return this time formatted as "HH:mm" (quotes for clarity).  If there are multiple possible answers, return the one that comes earliest lexicographically.  The constraints ensure that at least one result is always possible.

DEFINITION
Class:TheTriangleBothDivs
Method:fix
Parameters:string
Returns:string
Method signature:string fix(string time)


NOTES
-string s1 comes before string s2 lexicographically if s1 has a lexicographically smaller character at the first index where they differ.


CONSTRAINTS
-time will contain exactly 11 characters.
-time will be formatted "xx:xx GMTsx" (quotes for clarity).
-Each x in time will be a digit ('0'-'9') or '?'.
-The s in time will be '-','+' or '?'.
-time will represent a valid clock display (as described in the statement) where zero or more of the digits or the '-' or '+' sign have been replaced by '?' characters.


EXAMPLES

0)
"17:45 GMT-4"

Returns: "21:45"



1)
"16:?? GMT??"

Returns: "00:00"

There are many possible times the clock could be displaying, for example: "16:00 GMT+8", "16:35 GMT-9", etc.
It is possible to choose "00" minutes and the GMT-8 time zone to yield time "00:00" which is the lexicographically first result.

2)
"?1:34 GMT-9"

Returns: "06:34"



3)
"??:?? GMT??"

Returns: "00:00"



*/

// END CUT HERE
