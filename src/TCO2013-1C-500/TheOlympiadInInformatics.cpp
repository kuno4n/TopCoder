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

VI s;
int K;

bool can(LL a){
//    if(a == 0) return true;
    int tmp = 0;
    REP(i, SZ(s)) tmp += s[i]/(a+1);
    if(tmp > K) return false;
    else return true;
}

class TheOlympiadInInformatics {
	public:
	int find(vector <int> sums, int k) {
		s = sums;
        K = k;
        
        LL hi = (1LL<<60)-1;
        LL lo = -1;
        LL mid;
        while(hi - lo > 1){
            mid = (hi+lo) / 2;
            if(can(mid)) hi = mid;
            else lo = mid;
        }
        return hi;
        
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
			int sums[]                = {4, 7, 0, 5};
			int k                     = 0;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int sums[]                = {4, 7};
			int k                     = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int sums[]                = {999999999};
			int k                     = 1000000000;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int sums[]                = {95, 23, 87, 23, 82, 78, 59, 44, 12};
			int k                     = 70;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
          int sums[]                = {1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000};
			int k                     = 1000000000;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 5: {
			int sums[]                = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int sums[]                = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
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
// John takes part in a regional olympiad in informatics together with other participants.
At the contest each participant gains some nonnegative integer score.
Each participant (except for John) is assigned to one of the N contest rooms (numbered from 0 to N-1) and John is the only contestant in the room number N.
John has no idea how many participants are in the other rooms.
For each of the other rooms he only knows the sum of scores of all participants in it.


You are given a vector <int> sums containing N elements and an int k.
The i-th element of sums is the sum of participants' scores in the i-th contest room.
Return the minimal score John has to gain to be sure that there are at most k participants with strictly higher scores.


DEFINITION
Class:TheOlympiadInInformatics
Method:find
Parameters:vector <int>, int
Returns:int
Method signature:int find(vector <int> sums, int k)


CONSTRAINTS
-sums will contain between 1 and 47 elements, inclusive.
-Each element of sums will be between 0 and 1,000,000,000, inclusive.
-k will be between 0 and 1,000,000,000, inclusive.


EXAMPLES

0)
{4, 7, 0, 5}
0

Returns: 7

John has to gain at least 7 points, because there might be a competitor with 7 points in room number 1 (0-based index).

1)
{4, 7}
2

Returns: 3

It is possible that there are three contestants who scored more than 2 points: there can be one in room 0 and two more in room 1.
There can only be at most two contestants who scored more than 3 points: there can be at most one such contestant in each of the two rooms.
(Note that the score of each contestant has to be an integer.)
Therefore, John has to score at least 3 points.


2)
{999999999}
1000000000

Returns: 0

Here it is enough to gain 0 points.

3)
{95, 23, 87, 23, 82, 78, 59, 44, 12}
70

Returns: 6



*/

// END CUT HERE
