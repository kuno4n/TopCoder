
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
#include <numeric>
//#include "cout.h"

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl

int n;
int table1[55], table2[55][55]; 

class SurveillanceSystem {
public:
   string getContainerInfo( string containers, vector <int> reports, int L ) {
	MSET(table1, 0); MSET(table2, 0);
	n = SZ(containers);
	REP(i, n-L+1) for(int j = i; j < i+L; j++) if(containers[j] == 'X') table1[i]++;
	REP(i, L+1) REP(j, n-L+1) if(table1[j] == i) for(int k = j; k < j+L; k++) table2[i][k]++;
	
	bool can1[55], can2[55];
	REP(i, 55) can1[i] = can2[i] = false;
	
	REP(i, L+1){
		int reportcnt = count(ALL(reports), i);
		int intervalcnt = count(table1, table1+n-L+1, i);
		if(reportcnt == 0) continue;
		REP(j, n) if(table2[i][j] != 0) can1[j] = true;
		REP(j, n) if(table2[i][j] > intervalcnt - reportcnt) can2[j] = true;
	}
	string res = "";
	REP(i, n){
		if(can2[i]) res += '+';
		else if(can1[i]) res += '?';
		else res += '-';
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
			string containers         = "-X--XX";
			int reports[]             = {1, 2};
			int L                     = 3;
			string expected__         = "??++++";

			clock_t start__           = clock();
			string received__         = SurveillanceSystem().getContainerInfo(containers, vector <int>(reports, reports + (sizeof reports / sizeof reports[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string containers         = "-XXXXX-";
			int reports[]             = {2};
			int L                     = 3;
			string expected__         = "???-???";

			clock_t start__           = clock();
			string received__         = SurveillanceSystem().getContainerInfo(containers, vector <int>(reports, reports + (sizeof reports / sizeof reports[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string containers         = "------X-XX-";
			int reports[]             = {3, 0, 2, 0};
			int L                     = 5;
			string expected__         = "++++++++++?";

			clock_t start__           = clock();
			string received__         = SurveillanceSystem().getContainerInfo(containers, vector <int>(reports, reports + (sizeof reports / sizeof reports[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string containers         = "-XXXXX---X--";
			int reports[]             = {2, 1, 0, 1};
			int L                     = 3;
			string expected__         = "???-??++++??";

			clock_t start__           = clock();
			string received__         = SurveillanceSystem().getContainerInfo(containers, vector <int>(reports, reports + (sizeof reports / sizeof reports[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string containers         = "-XX--X-XX-X-X--X---XX-X---XXXX-----X";
			int reports[]             = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
			int L                     = 7;
			string expected__         = "???++++?++++++++++++++++++++??????--";

			clock_t start__           = clock();
			string received__         = SurveillanceSystem().getContainerInfo(containers, vector <int>(reports, reports + (sizeof reports / sizeof reports[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string containers         = ;
			int reports[]             = ;
			int L                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = SurveillanceSystem().getContainerInfo(containers, vector <int>(reports, reports + (sizeof reports / sizeof reports[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string containers         = ;
			int reports[]             = ;
			int L                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = SurveillanceSystem().getContainerInfo(containers, vector <int>(reports, reports + (sizeof reports / sizeof reports[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string containers         = ;
			int reports[]             = ;
			int L                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = SurveillanceSystem().getContainerInfo(containers, vector <int>(reports, reports + (sizeof reports / sizeof reports[0])), L);
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
// There is a long narrow storehouse.
The storehouse is divided into a sequence of N identical sectors, labeled 0 through N-1.
Each sector is large enough to contain a single container.
Currently, some sectors are empty and some sectors are filled by containers.
The storehouse also contains a surveillance system that is described below.

We are going to break into the storehouse.
As a part of preparation for the heist, we already found out some information about the warehouse.
In particular, we know exactly how the containers are currently placed in the warehouse.
You are given a string containers consisting of N characters.
For each i, character i of containers is 'X' if sector i contains a container, and it is '-' if sector i is empty.

We also discovered some information about the surveillance system.
The system consists of several hidden cameras.
You are given a int L with the following meaning:
Each of the cameras monitors exactly L consecutive sectors.
The segments of sectors monitored by different cameras might overlap, but no two cameras watch exactly the same segment.
(In other words, each sector may be monitored by multiple cameras, but each camera monitors a different set of consecutive sectors.)

Finally, we know something about what the cameras currently see.
You are given a vector <int> reports.
Each element of reports corresponds to one of the cameras (in no particular order).
More precisely, reports[i] is the number of containers stored in the sectors monitored by the corresponding camera.

It is guaranteed that all our information is correct and consistent.

Your task is to use the provided information to deduce which sectors are monitored by at least one surveillance camera.
Return a string containing N characters.
For each i, character i of the return value should be one of '+', '?', and '-'.
Character '+' represents that sector i is certainly monitored by at least one camera.
Character '-' represents that sector i is certainly not monitored by any of the cameras.
Character '?' represents the remaining case: given the information we have, it is possible that sector i is monitored, but it is also possible that it is not monitored.

DEFINITION
Class:SurveillanceSystem
Method:getContainerInfo
Parameters:string, vector <int>, int
Returns:string
Method signature:string getContainerInfo(string containers, vector <int> reports, int L)


CONSTRAINTS
-containers will contain N elements, where N is between 1 and 50, inclusive.
-Each character in containers will be either 'X' or '-'.
-L will be between 1 and N, inclusive.
-reports will contain between 1 and N-L+1 elements, inclusive.
-Each element of reports will be between 0 and L, inclusive.
-The given information will be consistent.


EXAMPLES

0)
"-X--XX"
{1, 2}
3

Returns: "??++++"

This storehouse has 6 sectors.
There are containers in sectors 1, 4, and 5.
There are two cameras: camera #0 monitors 1 container, and camera #1 monitors 2 containers.
Clearly, camera #1 must be watching sectors 3, 4, and 5.
Camera #0 may be watching sectors (0, 1, 2), (1, 2, 3), or (2, 3, 4).
Thus, camera #0 is surely monitoring sector 2.
Sectors 0 and 1 may or may not be monitored.

1)
"-XXXXX-"
{2}
3

Returns: "???-???"

The camera is monitoring either the leftmost or the rightmost segment, thus the middle sector is surely not under surveillance.

2)
"------X-XX-"
{3, 0, 2, 0}
5

Returns: "++++++++++?"

We can deduce that cameras #1 and #3 are watching segments (0, 1, 2, 3, 4) and (1, 2, 3, 4, 5). Camera #2 is monitoring the segment (4, 5, 6, 7, 8), since this is the only segment with two occupied sectors. Camera #0 is either watching (5, 6, 7, 8, 9) or (6, 7, 8, 9, 10), thus the rightmost sector might have slipped from the surveillance.

3)
"-XXXXX---X--"
{2, 1, 0, 1}
3

Returns: "???-??++++??"



4)
"-XX--X-XX-X-X--X---XX-X---XXXX-----X"
{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}
7

Returns: "???++++?++++++++++++++++++++??????--"



*/

// END CUT HERE
