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

class Badgers {
	public:
	int feedMost(vector <int> hunger, vector <int> greed, int totalFood) {
        FOR(i, 1, SZ(hunger)+1){
            vector<int> table;
            REP(j, SZ(hunger)) table.push_back(hunger[j] + greed[j]*(i-1));
            sort(ALL(table));
            int tmp = 0;
            REP(j, i) tmp += table[j];
            if(tmp > totalFood) return i-1;
        }
        return SZ(hunger);
		
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
			int hunger[]              = {1,2,3};
			int greed[]               = {2,2,1};
			int totalFood             = 7;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Badgers().feedMost(vector <int>(hunger, hunger + (sizeof hunger / sizeof hunger[0])), vector <int>(greed, greed + (sizeof greed / sizeof greed[0])), totalFood);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int hunger[]              = {5,2,1,5};
			int greed[]               = {0,2,4,1};
			int totalFood             = 19;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = Badgers().feedMost(vector <int>(hunger, hunger + (sizeof hunger / sizeof hunger[0])), vector <int>(greed, greed + (sizeof greed / sizeof greed[0])), totalFood);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int hunger[]              = {1,1,1,1,1};
			int greed[]               = {1000,1000,1000,1000,1000};
			int totalFood             = 10;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Badgers().feedMost(vector <int>(hunger, hunger + (sizeof hunger / sizeof hunger[0])), vector <int>(greed, greed + (sizeof greed / sizeof greed[0])), totalFood);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int hunger[]              = {1,2,3,4,5,6,7,8,9,10};
			int greed[]               = {10,9,8,7,6,5,4,3,2,1};
			int totalFood             = 100;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Badgers().feedMost(vector <int>(hunger, hunger + (sizeof hunger / sizeof hunger[0])), vector <int>(greed, greed + (sizeof greed / sizeof greed[0])), totalFood);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int hunger[]              = ;
			int greed[]               = ;
			int totalFood             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Badgers().feedMost(vector <int>(hunger, hunger + (sizeof hunger / sizeof hunger[0])), vector <int>(greed, greed + (sizeof greed / sizeof greed[0])), totalFood);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int hunger[]              = ;
			int greed[]               = ;
			int totalFood             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Badgers().feedMost(vector <int>(hunger, hunger + (sizeof hunger / sizeof hunger[0])), vector <int>(greed, greed + (sizeof greed / sizeof greed[0])), totalFood);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int hunger[]              = ;
			int greed[]               = ;
			int totalFood             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Badgers().feedMost(vector <int>(hunger, hunger + (sizeof hunger / sizeof hunger[0])), vector <int>(greed, greed + (sizeof greed / sizeof greed[0])), totalFood);
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
// Badgers are lovely furry animals, and Manao has just decided to start keeping a few. The pet shop has offered him N badgers, and they are all so cute that Manao wants to take as many as he can feed. Normally, a badger needs some amount of food per day to be satisfied. However, if he sees other badgers eating, his greed awakens and he wants to eat more. A badger will want a fixed additional amount of food for each co-eater.

You're given vector <int>s hunger and greed, both containing N elements. The i-th element of hunger is the number of units of food that the i-th badger needs per day if he's alone. The i-th element of greed is the amount of additional units of food the i-th badger will need for each co-eater. Return the maximum number of badgers Manao can take while keeping them all satisfied if he can supply no more than totalFood units of food per day.


DEFINITION
Class:Badgers
Method:feedMost
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int feedMost(vector <int> hunger, vector <int> greed, int totalFood)


CONSTRAINTS
-hunger will contain between 1 and 50 elements, inclusive.
-greed will contain the same number of elements as hunger.
-Each element of hunger will be between 1 and 1000, inclusive.
-Each element of greed will be between 0 and 1000, inclusive.
-totalFood will be between 1 and 1000000, inclusive.


EXAMPLES

0)
{1,2,3}
{2,2,1}
7

Returns: 2

Manao can take badger 0 and one of the other two badgers.


1)
{5,2,1,5}
{0,2,4,1}
19

Returns: 3

Badger 2 is too greedy, but the rest can be fed together and will only need (5 + 2 * 0) + (2 + 2 * 2) + (5 + 2 * 1) = 18 units of food.


2)
{1,1,1,1,1}
{1000,1000,1000,1000,1000}
10

Returns: 1

They are too greedy to eat together.


3)
{1,2,3,4,5,6,7,8,9,10}
{10,9,8,7,6,5,4,3,2,1}
100

Returns: 5

*/

// END CUT HERE
