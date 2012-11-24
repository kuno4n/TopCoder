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

class ElectionFraudDiv1 {
    VI p;
    int N;
    
    int calper(int num, int all){
        return (int)round(((double)num/all)*100);
    }
    
    int calmin(int all, int per){
        for(int tmp=0; ; tmp++){
            if(calper(tmp, all) > per) break;
            if(calper(tmp, all) == per) return tmp;
        }
        return -1;
    }
    
    int calmax(int all, int per){
        for(int tmp=all; ; tmp--){
            if(calper(tmp, all) < per) break;
            if(calper(tmp, all) == per) return tmp;
        }
        return -1;
    }
    
    bool OK(int a){
        int summn=0;
        int summx=0;
        REP(i, N){
            int mn = calmin(a, p[i]);
            int mx = calmax(a, p[i]);
            if(mn == -1 || mx == -1) return false;
            summn += mn;
            summx += mx;
        }
        if(summn > a || summx < a) return false;
        return true;
    }
    
	public:
	int MinimumVoters(vector <int> percentages) {
        p = percentages;
//        int sum = 0;
//        int num0 = 0;
//        int num100 = 0;
        
        N = SZ(percentages);
//        REP(i, N) {
//            sum += percentages[i];
//            if(percentages[i] == 0) num0++;
//            if(percentages[i] == 100) num100++;
//        }
//        if(sum+0.5*N <= 100 || sum-0.5*(N-num0) > 100) return -1;
        
        int res = 1;
        for(;res < 1000;res++) if(OK(res)) break;
        return res == 1000 ? -1 : res;
        
        
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
			int percentages[]         = {33, 33, 33};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int percentages[]         = {29, 29, 43};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int percentages[]         = {12, 12, 12, 12, 12, 12, 12, 12};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int percentages[]         = {13, 13, 13, 13, 13, 13, 13, 13};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int percentages[]         = {0, 1, 100};
			int expected__            = 200;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int percentages[]         = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4};
			int expected__            = 97;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

//      case 6: {
//          int percentages[]         = {0,0,0,99};
//			int expected__            = -1;
//
//			clock_t start__           = clock();
//			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
//			return verify_case(casenum__, expected__, received__, clock()-start__);
//		}
/*      case 7: {
			int percentages[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int percentages[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
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
// In a normal election, one expects the percentages received by each of the candidates to sum to exactly 100 percent.  There are two ways this might not be the case: if the election is fraudulent, or if the reported percentages are rounded.
For example, in an election with 3 voters and 3 candidates, if each voter chooses a different candidate the final percentages would be reported as 33, 33, 33, which only sum to 99.  Conversely, in an election with 7 voters and 3 candidates, if the candidates receive 2, 2, and 3 votes, respectively, the final percentages would be reported as 29, 29, and 43, which sum to 101.
The ministry of voting wants you to help them determine if an election was run fairly or not.  You'll be given a vector <int> percentages, giving the percentage of the vote that went to each candidate, rounded to the nearest whole number (in the case a number lies halfway between 2 consecutive integers, it will be rounded up).  If the election could be legitimate, return the minimum number of voters that could have participated in this election.  If the election is definitely fraudulent, return -1.

DEFINITION
Class:ElectionFraudDiv1
Method:MinimumVoters
Parameters:vector <int>
Returns:int
Method signature:int MinimumVoters(vector <int> percentages)


NOTES
-You may assume that whenever the election may be legitimate, the smallest possible number of voters will fit into a int.


CONSTRAINTS
-percentages will contain between 1 and 50 elements, inclusive.
-Each element of percentages will be between 0 and 100, inclusive.


EXAMPLES

0)
{33, 33, 33}

Returns: 3

The first example from the problem statement.

1)
{29, 29, 43}

Returns: 7

The second example from the problem statement.

2)
{12, 12, 12, 12, 12, 12, 12, 12}

Returns: -1

These results are impossible.

3)
{13, 13, 13, 13, 13, 13, 13, 13}

Returns: 8



4)
{0, 1, 100}

Returns: 200

The only possibility is that the candidates received 0, 1, and 199 votes, respectively.

5)
{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4}

Returns: 97



*/

// END CUT HERE
