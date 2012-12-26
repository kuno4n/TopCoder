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

int conv(char c){
    if('0'<=c && c<='9') return c-'0';
    if('A'<=c && c<='Z') return c-'A'+10;
    if('a'<=c && c<='z') return c-'a'+36;
    return 0;
}

class MysteriousRestaurant {
	public:
	int maxDays(vector <string> prices, int budget) {
        
		REP(i, SZ(prices)){
            int mn = 0;
            REP(dish, min(7, i+1)){
                int dishmn = 100000000;
                REP(j, SZ(prices[0])){
                    int tmp = 0;
                    for(int k=dish; k<=i; k+=7){
                        tmp += conv(prices[k][j]);
                    }
                    dishmn = min(dishmn, tmp);
                }
                mn += dishmn;
            }
            if(mn > budget) return i;
        }
        return SZ(prices);
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
			string prices[]           = {"26", "14", "72", "39", "32", "85", "06"};
			int budget                = 13;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string prices[]           = {"26", "14", "72", "39", "32", "85", "06", "91"};
			int budget                = 20;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string prices[]           = {"SRM", "512"};
			int budget                = 4;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string prices[]           = {"Dear", "Code", "rsHa", "veFu", "nInT", "heCh", "alle", "ngeP", "hase", "andb", "ecar", "eful"};
			int budget                = 256;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string prices[]           = ;
			int budget                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string prices[]           = ;
			int budget                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string prices[]           = ;
			int budget                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
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
// A mysterious new restaurant is open in the city for only N days. Happy to hear that, Ash and Elsh would like to have lunch at the restaurant on as many days as possible.

The restaurant sells M types of dishes. Being a mysterious restaurant, it has mysterious rules for the customers:


They can only buy one single dish per day.
If they buy a dish of type j on the i-th day, then on the same day next week, i.e., on the (i+7)-th day, they can only buy a dish of type j.
If they don't buy any dishes on any day, then they can't buy any dishes again from the restaurant.


Mysteriously, the price of each type of dish varies every day. You are given a vector <string> prices consisting of N elements, each containing M characters. prices[i][j] represents the price of the j-th type of dish on the i-th day, encoded as follows:


'0' - '9': denotes the price of 0 - 9 dollars.
'A' - 'Z': denotes the price of 10 - 35 dollars.
'a' - 'z': denotes the price of 36 - 61 dollars.


Ash and Elsh have only budget dollars allocated for having lunch in the restaurant. Return the maximum number of days they could have lunch in the restaurant.

DEFINITION
Class:MysteriousRestaurant
Method:maxDays
Parameters:vector <string>, int
Returns:int
Method signature:int maxDays(vector <string> prices, int budget)


CONSTRAINTS
-prices will contain between 1 and 50 elements, inclusive.
-Each element of prices will contain the same number of characters, between 1 and 50 characters, inclusive.
-Each character in prices will be '0'-'9', 'a'-'z', or 'A'-'Z'.
-budget will be between 0 and 10,000, inclusive.


EXAMPLES

0)
{"26", "14", "72", "39", "32", "85", "06"}
13

Returns: 5

The restaurant is open for 7 days. They can have lunch for 5 days, each picking the cheaper dish from the two available types. The total prices would be 2+1+2+3+2 = 10.

1)
{"26", "14", "72", "39", "32", "85", "06", "91"}
20

Returns: 8

In this case, it is better to buy the second type of dish on the first and the eighth day, so they can have lunch for the entire 8 days.

2)
{"SRM", "512"}
4

Returns: 0

They don't have sufficient budget.

3)
{"Dear", "Code", "rsHa", "veFu", "nInT", "heCh", "alle", "ngeP", "hase", "andb", "ecar", "eful"}
256

Returns: 10



*/

// END CUT HERE
