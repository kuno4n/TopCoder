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
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
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


long long _Pow(long long x, long long y){
    long long r=1, a=x;
    while(y > 0){
        if((y&1) == 1) r = r*a;
        a = a*a;
        y /= 2;
    }
    return r;
}

class Inequalities {
	public:
	int maximumSubset(vector <string> inequalities) {
		int res = 0;
        int n= SZ(inequalities);
        for(int i = -1; i <= 2001; i++){
            int cnt = 0;
            REP(j, n){
                string s[3];
                stringstream ss(inequalities[j]);
                string elem;
                int a = 0;
                while(ss >> elem) {
                    s[a] = elem;
                    a++;
                }
                int tar = 0;
                for(int k = SZ(s[2])-1; k>=0; k--){
                    tar += (s[2][k] - '0') * _Pow(10, SZ(s[2])-k-1);
                }
                tar *= 2;
                
                if(s[1] == "<") if(i < tar) cnt++;
                if(s[1] == "<=") if(i <= tar) cnt++;
                if(s[1] == "=") if(i == tar) cnt++;
                if(s[1] == ">=") if(i >= tar) cnt++;
                if(s[1] == ">") if(i > tar) cnt++;
                
            }
            
            
            res = max(res, cnt);
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
			string inequalities[]     = {"X <= 12","X = 13","X > 9","X < 10","X >= 14"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string inequalities[]     = {"X < 0","X <= 0"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string inequalities[]     = {"X = 1","X = 2","X = 3","X > 0"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string inequalities[]     = {"X <= 521","X >= 521","X = 521","X > 902","X > 12","X <= 1000"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string inequalities[]     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string inequalities[]     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string inequalities[]     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
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
// You're given a set of inequalities. Each of the inequalities refers to the variable X. Determine the maximum subset of the given set which has a solution.

To make your task easier, the inequalities in the given set are always reduced to one of the following five forms:

	X < C
	X <= C
	X = C
	X > C
	X >= C

Here, C indicates some non-negative integer constant.

The inequalities are given in the vector <string> inequalities, where each element is a single inequality formatted as shown above. Return the maximal number of inequalities of the set which can be satisfied simultaneously.

DEFINITION
Class:Inequalities
Method:maximumSubset
Parameters:vector <string>
Returns:int
Method signature:int maximumSubset(vector <string> inequalities)


NOTES
-Note that X doesn't have to be an integer or positive number.


CONSTRAINTS
-inequalities will contain between 1 and 50 elements, inclusive.
-Each element of inequalities will be formatted "X <E> <C>", where 'X' is uppercase, <E> is one of "<", "<=", "=", ">=" or ">", and <C> is an integer between 0 and 1000, inclusive, with no extra leading zeroes (all quotes for clarity).
-No two elements of inequalities will be equal.


EXAMPLES

0)
{"X <= 12","X = 13","X > 9","X < 10","X >= 14"}

Returns: 3

Any value between 9 and 10 will satisfy the first, third and fourth inequalities.

1)
{"X < 0","X <= 0"}

Returns: 2

The solution to the whole set is any negative number.

2)
{"X = 1","X = 2","X = 3","X > 0"}

Returns: 2

Obviously, you can choose no more than one equality in addition to the fourth inequality.

3)
{"X <= 521","X >= 521","X = 521","X > 902","X > 12","X <= 1000"}

Returns: 5

The best choice is number 521.

*/

// END CUT HERE
