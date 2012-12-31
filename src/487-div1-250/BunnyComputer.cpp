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

class BunnyComputer {
    int sub(VI vi){
        int sum = accumulate(ALL(vi), 0);
        if(SZ(vi)%2 == 0) return sum;
        int mn = 10000000;
        for(int i=0; i<SZ(vi); i+=2) mn = min(mn, vi[i]);
        return sum - mn;
    }
    
	public:
	int getMaximum(vector <int> preference, int k) {
        int sum = 0;
		for(int i=0; i<=k && i+k+1<SZ(preference); i++){
            VI tmp;
            for(int j=i; j<SZ(preference); j+=(k+1)) tmp.push_back(preference[j]);
            sum += sub(tmp);
        }
        return sum;
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
			int preference[]          = { 3, 1, 4, 1, 5, 9, 2, 6 };
			int k                     = 2;
			int expected__            = 28;

			clock_t start__           = clock();
			int received__            = BunnyComputer().getMaximum(vector <int>(preference, preference + (sizeof preference / sizeof preference[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int preference[]          = { 3, 1, 4, 1, 5, 9, 2, 6 };
			int k                     = 1;
			int expected__            = 31;

			clock_t start__           = clock();
			int received__            = BunnyComputer().getMaximum(vector <int>(preference, preference + (sizeof preference / sizeof preference[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int preference[]          = { 1, 2, 3, 4, 5, 6 };
			int k                     = 3;
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = BunnyComputer().getMaximum(vector <int>(preference, preference + (sizeof preference / sizeof preference[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int preference[]          = { 487, 2010 };
			int k                     = 2;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = BunnyComputer().getMaximum(vector <int>(preference, preference + (sizeof preference / sizeof preference[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int preference[]          = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BunnyComputer().getMaximum(vector <int>(preference, preference + (sizeof preference / sizeof preference[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int preference[]          = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BunnyComputer().getMaximum(vector <int>(preference, preference + (sizeof preference / sizeof preference[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int preference[]          = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BunnyComputer().getMaximum(vector <int>(preference, preference + (sizeof preference / sizeof preference[0])), k);
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
// Bunnies like programming and they often practice for contests. 


There is a special computer named B-Computer, which all bunnies are eager to use. 
All bunnies want to solve a difficult problem using B-Computer. 
Because they type very fast, each of them wants to solve the problem according to the following process 
that consists of 3 stages (no delay is allowed between subsequent stages): 

	Use B-Computer for exactly one time unit. 
	Think and calculate on paper for exactly k time units, not using B-Computer. 
	Use B-Computer for exactly one time unit again to complete. 

B-Computer cannot be used by more than one bunny at the same time, 
but when a bunny is thinking and calculating on paper, another bunny may use B-Computer. 


A day is divided into a number of equal time units, 
and each time unit has an associated positive integer value called preference. 
You are given a vector <int> preference, which contains the preference values for a day. 
The number of elements in preference is the number of time units in the day, 
and the i-th element of preference is the preference of the i-th time unit. 


Bunnies want to design a B-Computer schedule for a single day 
so that the sum of preferences of time units in which one of them uses B-Computer is maximized. 
The schedule must be such that each bunny uses B-computer exactly as described above 
and both time units at which the same bunny uses B-computer are in the same day. 
Return the maximum possible sum of preferences. 
You can assume that there are infinitely many bunnies. 


DEFINITION
Class:BunnyComputer
Method:getMaximum
Parameters:vector <int>, int
Returns:int
Method signature:int getMaximum(vector <int> preference, int k)


CONSTRAINTS
-preference will contain between 1 and 50 elements, inclusive. 
-Each element of preference will be between 1 and 1,000,000, inclusive. 
-k will be between 1 and 50, inclusive. 


EXAMPLES

0)
{ 3, 1, 4, 1, 5, 9, 2, 6 }
2

Returns: 28

The sum is maximized when three bunnies use B-Computer as follows: 

	One bunny uses B-Computer during the 1-st time unit and again during the 4-th time unit. 
	One bunny uses B-Computer during the 3-rd time unit and again during the 6-th time unit. 
	One bunny uses B-Computer during the 5-th time unit and again during the 8-th time unit. 




1)
{ 3, 1, 4, 1, 5, 9, 2, 6 }
1

Returns: 31

2)
{ 1, 2, 3, 4, 5, 6 }
3

Returns: 14

3)
{ 487, 2010 }
2

Returns: 0

No bunnies can use B-Computer. 


*/

// END CUT HERE
