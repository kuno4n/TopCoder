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

class SlimeXSlimesCity {
	public:
	int merge(vector <int> population) {
		int res = 0;
        REP(i, SZ(population)){
            VI p = population;
            LL tmp = p[i];
            p[i] = 0;
            sort(ALL(p));
            bool ok = true;
            REP(j, SZ(p)){
                OUT(tmp);
                if(tmp < p[j]){
                    ok = false;
                    break;
                }
                tmp += p[j];
            }
            if(ok) res++;
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
			int population[]          = {2, 3, 4};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = SlimeXSlimesCity().merge(vector <int>(population, population + (sizeof population / sizeof population[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int population[]          = {1, 2, 3};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = SlimeXSlimesCity().merge(vector <int>(population, population + (sizeof population / sizeof population[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int population[]          = {8,2,3,8};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = SlimeXSlimesCity().merge(vector <int>(population, population + (sizeof population / sizeof population[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int population[]          = {1000000000, 999999999, 999999998, 999999997};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = SlimeXSlimesCity().merge(vector <int>(population, population + (sizeof population / sizeof population[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int population[]          = {1,1,1};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = SlimeXSlimesCity().merge(vector <int>(population, population + (sizeof population / sizeof population[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int population[]          = {1, 2, 4, 6, 14, 16, 20};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = SlimeXSlimesCity().merge(vector <int>(population, population + (sizeof population / sizeof population[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int population[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SlimeXSlimesCity().merge(vector <int>(population, population + (sizeof population / sizeof population[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int population[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SlimeXSlimesCity().merge(vector <int>(population, population + (sizeof population / sizeof population[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int population[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SlimeXSlimesCity().merge(vector <int>(population, population + (sizeof population / sizeof population[0])));
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
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.


You are playing a game titled Slimes City. You are managing several towns in this game.


You have N towns in a region. For simplicity, they are named 0 through N-1. The population of town i is population[i].


You are going to merge these towns to form one big city. The procedure is as follows. While the number of towns is more than one, pick two different towns, i and j. Delete these two towns and form a new one, with a population equal to the sum of the populations of towns i and j. The name of the newly formed town will be i if i had a larger population than j, or j if j had a larger population than i. If both of the original towns had the same population, either name can be chosen.


When this process ends, one town remains. That town's name becomes the city's name. Return the number of different possible names for the resulting city.

DEFINITION
Class:SlimeXSlimesCity
Method:merge
Parameters:vector <int>
Returns:int
Method signature:int merge(vector <int> population)


CONSTRAINTS
-population will contain between 2 and 50 elements, inclusive.
-Each element of population will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{2, 3, 4}

Returns: 2



If towns 0 and 1 are merged first, the city's name will be 1. Otherwise the city's name will be 2. It is illustrated by the following image that shows the only three possible ways to merge the cities.




1)
{1, 2, 3}

Returns: 2



If town 2 is merged first (with town 0 or 1), the city's name will be 2. Otherwise, if towns 0 and 1 are merged first (to form a new town named 1, with a population of 3) and then the resulting town is merged with town 2, the city can be named either 1 or 2.  It's not possible for the city to be named 0.



2)
{8,2,3,8}

Returns: 2

There may be multiple towns with the same population.

3)
{1000000000, 999999999, 999999998, 999999997}

Returns: 3



4)
{1,1,1}

Returns: 3



5)
{1, 2, 4, 6, 14, 16, 20}

Returns: 3



*/

// END CUT HERE
