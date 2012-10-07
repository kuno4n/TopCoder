#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
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
#define FIT(it,v) for(typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define OUT(A) cout << #A << " = " << A << endl

class KiwiJuiceEasy {
	public:
	vector <int> thePouring(vector <int> capacities, vector <int> bottles, vector <int> fromId, vector <int> toId) {
		
        int N = SZ(fromId);
        REP(i, N){
            int f = fromId[i];
            int t = toId[i];
            int sum = bottles[f] + bottles[t];
            bottles[t] = min(capacities[t], sum);
            bottles[f] = sum - bottles[t];
        }
        return bottles;
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			int capacities[]          = {20, 20};
			int bottles[]             = {5, 8};
			int fromId[]              = {0};
			int toId[]                = {1};
			int expected__[]          = {0, 13 };

			clock_t start__           = clock();
			vector <int> received__   = KiwiJuiceEasy().thePouring(vector <int>(capacities, capacities + (sizeof capacities / sizeof capacities[0])), vector <int>(bottles, bottles + (sizeof bottles / sizeof bottles[0])), vector <int>(fromId, fromId + (sizeof fromId / sizeof fromId[0])), vector <int>(toId, toId + (sizeof toId / sizeof toId[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int capacities[]          = {10, 10};
			int bottles[]             = {5, 8};
			int fromId[]              = {0};
			int toId[]                = {1};
			int expected__[]          = {3, 10 };

			clock_t start__           = clock();
			vector <int> received__   = KiwiJuiceEasy().thePouring(vector <int>(capacities, capacities + (sizeof capacities / sizeof capacities[0])), vector <int>(bottles, bottles + (sizeof bottles / sizeof bottles[0])), vector <int>(fromId, fromId + (sizeof fromId / sizeof fromId[0])), vector <int>(toId, toId + (sizeof toId / sizeof toId[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int capacities[]          = {30, 20, 10};
			int bottles[]             = {10, 5, 5};
			int fromId[]              = {0, 1, 2};
			int toId[]                = {1, 2, 0};
			int expected__[]          = {10, 10, 0 };

			clock_t start__           = clock();
			vector <int> received__   = KiwiJuiceEasy().thePouring(vector <int>(capacities, capacities + (sizeof capacities / sizeof capacities[0])), vector <int>(bottles, bottles + (sizeof bottles / sizeof bottles[0])), vector <int>(fromId, fromId + (sizeof fromId / sizeof fromId[0])), vector <int>(toId, toId + (sizeof toId / sizeof toId[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int capacities[]          = {14, 35, 86, 58, 25, 62};
			int bottles[]             = {6, 34, 27, 38, 9, 60};
			int fromId[]              = {1, 2, 4, 5, 3, 3, 1, 0};
			int toId[]                = {0, 1, 2, 4, 2, 5, 3, 1};
			int expected__[]          = {0, 14, 65, 35, 25, 35 };

			clock_t start__           = clock();
			vector <int> received__   = KiwiJuiceEasy().thePouring(vector <int>(capacities, capacities + (sizeof capacities / sizeof capacities[0])), vector <int>(bottles, bottles + (sizeof bottles / sizeof bottles[0])), vector <int>(fromId, fromId + (sizeof fromId / sizeof fromId[0])), vector <int>(toId, toId + (sizeof toId / sizeof toId[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int capacities[]          = {700000, 800000, 900000, 1000000};
			int bottles[]             = {478478, 478478, 478478, 478478};
			int fromId[]              = {2, 3, 2, 0, 1};
			int toId[]                = {0, 1, 1, 3, 2};
			int expected__[]          = {0, 156956, 900000, 856956 };

			clock_t start__           = clock();
			vector <int> received__   = KiwiJuiceEasy().thePouring(vector <int>(capacities, capacities + (sizeof capacities / sizeof capacities[0])), vector <int>(bottles, bottles + (sizeof bottles / sizeof bottles[0])), vector <int>(fromId, fromId + (sizeof fromId / sizeof fromId[0])), vector <int>(toId, toId + (sizeof toId / sizeof toId[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int capacities[]          = ;
			int bottles[]             = ;
			int fromId[]              = ;
			int toId[]                = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = KiwiJuiceEasy().thePouring(vector <int>(capacities, capacities + (sizeof capacities / sizeof capacities[0])), vector <int>(bottles, bottles + (sizeof bottles / sizeof bottles[0])), vector <int>(fromId, fromId + (sizeof fromId / sizeof fromId[0])), vector <int>(toId, toId + (sizeof toId / sizeof toId[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int capacities[]          = ;
			int bottles[]             = ;
			int fromId[]              = ;
			int toId[]                = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = KiwiJuiceEasy().thePouring(vector <int>(capacities, capacities + (sizeof capacities / sizeof capacities[0])), vector <int>(bottles, bottles + (sizeof bottles / sizeof bottles[0])), vector <int>(fromId, fromId + (sizeof fromId / sizeof fromId[0])), vector <int>(toId, toId + (sizeof toId / sizeof toId[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int capacities[]          = ;
			int bottles[]             = ;
			int fromId[]              = ;
			int toId[]                = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = KiwiJuiceEasy().thePouring(vector <int>(capacities, capacities + (sizeof capacities / sizeof capacities[0])), vector <int>(bottles, bottles + (sizeof bottles / sizeof bottles[0])), vector <int>(fromId, fromId + (sizeof fromId / sizeof fromId[0])), vector <int>(toId, toId + (sizeof toId / sizeof toId[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
// Taro has prepared delicious kiwi fruit juice. He poured it into N bottles numbered from 0 to N-1. The capacity of the i-th bottle is capacities[i] liters, and he poured bottles[i] liters of kiwi juice into this bottle.


Now he wants to redistribute juice in the bottles. In order to do this, he will perform M operations numbered from 0 to M-1 in the order in which he will perform them. For the i-th operation, he will pour kiwi juice from bottle fromId[i] to bottle toId[i]. He will stop pouring when bottle fromId[i] becomes empty or bottle toId[i] becomes full, whichever happens earlier.


Return an vector <int> that contains exactly N elements and whose i-th element is the amount of kiwi juice in the i-th bottle after all pouring operations are finished.



DEFINITION
Class:KiwiJuiceEasy
Method:thePouring
Parameters:vector <int>, vector <int>, vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> thePouring(vector <int> capacities, vector <int> bottles, vector <int> fromId, vector <int> toId)


CONSTRAINTS
-capacities will contain between 2 and 50 elements, inclusive.
-Each element of capacities will be between 1 and 1,000,000, inclusive.
-capacities and bottles will contain the same number of elements.
-For each i, bottles[i] will be between 0 and capacities[i], inclusive.
-fromId will contain between 1 and 50 elements, inclusive.
-fromId and toId will contain the same number of elements.
-Each element of fromId and toId will be between 0 and N-1, inclusive, where N is the number of elements in capacities.
-For each i, fromId[i] and toId[i] will be distinct.


EXAMPLES

0)
{20, 20}
{5, 8}
{0}
{1}

Returns: {0, 13 }

He pours kiwi juice from bottle 0 to bottle 1. After pouring, bottle 0 will become empty and bottle 1 will contain 13 liters of kiwi juice.

1)
{10, 10}
{5, 8}
{0}
{1}

Returns: {3, 10 }

He will stop pouring when bottle 1 becomes full.

2)
{30, 20, 10}
{10, 5, 5}
{0, 1, 2}
{1, 2, 0}

Returns: {10, 10, 0 }



3)
{14, 35, 86, 58, 25, 62}
{6, 34, 27, 38, 9, 60}
{1, 2, 4, 5, 3, 3, 1, 0}
{0, 1, 2, 4, 2, 5, 3, 1}

Returns: {0, 14, 65, 35, 25, 35 }



4)
{700000, 800000, 900000, 1000000}
{478478, 478478, 478478, 478478}
{2, 3, 2, 0, 1}
{0, 1, 1, 3, 2}

Returns: {0, 156956, 900000, 856956 }



*/

// END CUT HERE
