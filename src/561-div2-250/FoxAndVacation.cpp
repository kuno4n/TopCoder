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

class FoxAndVacation {
	public:
	int maxCities(int total, vector <int> d) {
        int res = 0;
		sort(ALL(d));
        REP(i, SZ(d)) {
            if(d[i] > total) break;
            total -= d[i];
            res++;
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
			int total                 = 5;
			int d[]                   = {2,2,2};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = FoxAndVacation().maxCities(total, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int total                 = 5;
			int d[]                   = {5,6,1};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FoxAndVacation().maxCities(total, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int total                 = 5;
			int d[]                   = {6,6,6};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FoxAndVacation().maxCities(total, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int total                 = 6;
			int d[]                   = {1,1,1,1,1};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = FoxAndVacation().maxCities(total, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int total                 = 10;
			int d[]                   = {7,1,5,6,1,3,4};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = FoxAndVacation().maxCities(total, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int total                 = 50;
			int d[]                   = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = FoxAndVacation().maxCities(total, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int total                 = 21;
			int d[]                   = {14,2,16,9,9,5,5,23,25,20,8,25,6,12,3,2,4,5,10,14,19,12,25,15,14};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = FoxAndVacation().maxCities(total, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int total                 = ;
			int d[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndVacation().maxCities(total, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int total                 = ;
			int d[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndVacation().maxCities(total, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int total                 = ;
			int d[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndVacation().maxCities(total, vector <int>(d, d + (sizeof d / sizeof d[0])));
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
// Fox Ciel is planning to visit the Tourist Kingdom for total days.
This kingdom is full of lovely cities.
During her stay Ciel would like to visit as many different cities as possible.
She cannot visit more than one city on the same day.



Additionally, different cities may require her to stay for a different number of days.
For each i, city i only counts as visited if Ciel spends at least d[i] days in the city.



You are given the int total and the vector <int> d.
Return the maximal number of cities she can visit during her vacation.

DEFINITION
Class:FoxAndVacation
Method:maxCities
Parameters:int, vector <int>
Returns:int
Method signature:int maxCities(int total, vector <int> d)


NOTES
-When solving the task, ignore travel times. (Fox Ciel always travels at night, and she can travel between any two cities very quickly.)


CONSTRAINTS
-total will be between 1 and 50, inclusive.
-d will contain between 1 and 50 elements, inclusive.
-Each element of d will be between 1 and 50, inclusive.


EXAMPLES

0)
5
{2,2,2}

Returns: 2

Fox Ciel's vacation lasts for 5 days. She needs at least 2 days to visit each of the cities, so she can visit at most 2 of them.

1)
5
{5,6,1}

Returns: 1

She can only visit one city: either city 0, or city 2.

2)
5
{6,6,6}

Returns: 0

This time the poor Fox Ciel cannot visit any city during her summer vacation.

3)
6
{1,1,1,1,1}

Returns: 5

In this test case Ciel can visit all five cities.
Note that at the end of her trip each city either does count as visited, or it does not -- there is no way to "visit" the same city twice.

4)
10
{7,1,5,6,1,3,4}

Returns: 4



5)
50
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}

Returns: 9



6)
21
{14,2,16,9,9,5,5,23,25,20,8,25,6,12,3,2,4,5,10,14,19,12,25,15,14}

Returns: 6



*/

// END CUT HERE
