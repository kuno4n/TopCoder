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

class Zoo {
	public:
	long long theCount(vector <int> answers) {
        int cnt[41] = {0};
        REP(i, SZ(answers)) cnt[answers[i]]++;
        if(cnt[0] == 0) return 0LL;
        REP(i, 41) if(cnt[i] > 2) return 0LL;
        REP(i, 40) if(cnt[i] < cnt[i+1]) return 0LL;
        
        LL res = 1LL;
        REP(i, 41) {
            if(cnt[i] == 2) res <<= 1;
            if(cnt[i] == 1){
                res <<= 1;
                return res;
            }
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int answers[]             = {0, 1, 2, 3, 4};
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int answers[]             = {5, 8};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int answers[]             = {0, 0, 0, 0, 0, 0};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int answers[]             = {1, 0, 2, 0, 1};
			long long expected__      = 8;

			clock_t start__           = clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int answers[]             = {1, 0, 1};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int answers[]             = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int answers[]             = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int answers[]             = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
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
// There are N animals numbered 0 to N-1 in a zoo. Each animal is a rabbit or a cat. Their heights are pairwise distinct.


Fox Jiro can't distinguish between rabbits and cats, so he asked the following question to each animal: "How many animals of the same kind as you are taller than you?" Each rabbit tells the number of rabbits taller than him, and each cat tells the number of cats taller than her. The differences of heights are slight, so Fox Jiro can't tell which animals are taller than other animals. However, each animal is able to determine which animals are taller that him and which ones are shorter.


The answer given by the i-th animal is answers[i]. Given these numbers, return the number of configurations resulting in exactly those numbers, assuming everyone tells the truth. Two configurations are different if there exists an i such that the i-th animal is a rabbit in one configuration and cat in the other configuration.


DEFINITION
Class:Zoo
Method:theCount
Parameters:vector <int>
Returns:long long
Method signature:long long theCount(vector <int> answers)


CONSTRAINTS
-answers will contain between 1 and 40 elements, inclusive.
-Each element of answers will be between 0 and 40, inclusive.


EXAMPLES

0)
{0, 1, 2, 3, 4}

Returns: 2

There are two possible configurations: all animals are rabbits or all animals are cats.

1)
{5, 8}

Returns: 0

There are only two animals. These animals are definitely lying.

2)
{0, 0, 0, 0, 0, 0}

Returns: 0



3)
{1, 0, 2, 0, 1}

Returns: 8



4)
{1, 0, 1}

Returns: 0



*/

// END CUT HERE
