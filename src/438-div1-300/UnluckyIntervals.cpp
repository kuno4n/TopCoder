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

LL calc(int a, int b, int m){
    LL res = 0LL;
    res += (LL)(b-m)*(m-a-1);
    res += (LL)(b-m-1);
    return res;
}

class UnluckyIntervals {
	public:
	vector <int> getLuckiest(vector <int> l, int n) {
        l.push_back(0);
		sort(ALL(l));
        vector < pair< LL, int > > v;
        
        FOR(i, 1, SZ(l)) v.push_back(make_pair(0LL, l[i]));
        
        FOR(i, 1, SZ(l)){
            FOR(j, 1, 100){
                if(l[i-1]+j > l[i]-j) break;
                v.push_back(make_pair(calc(l[i-1], l[i], l[i-1]+j), l[i-1]+j));
                if(l[i-1]+j != l[i]-j) v.push_back(make_pair(calc(l[i-1], l[i], l[i]-j), l[i]-j));
            }
        }
        
        FOR(i, 1, 100) v.push_back(make_pair((1LL<<50), l[SZ(l)-1]+i));
        
        sort(ALL(v));
        VI res;
        REP(i, n) res.push_back(v[i].second);
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
			int luckySet[]            = {3};
			int n                     = 6;
			int expected__[]          = {3, 1, 2, 4, 5, 6 };

			clock_t start__           = clock();
			vector <int> received__   = UnluckyIntervals().getLuckiest(vector <int>(luckySet, luckySet + (sizeof luckySet / sizeof luckySet[0])), n);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int luckySet[]            = {5, 11, 18};
			int n                     = 9;
			int expected__[]          = {5, 11, 18, 1, 4, 6, 10, 2, 3 };

			clock_t start__           = clock();
			vector <int> received__   = UnluckyIntervals().getLuckiest(vector <int>(luckySet, luckySet + (sizeof luckySet / sizeof luckySet[0])), n);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int luckySet[]            = {7, 13, 18};
			int n                     = 9;
			int expected__[]          = {7, 13, 18, 14, 17, 8, 12, 1, 6 };

			clock_t start__           = clock();
			vector <int> received__   = UnluckyIntervals().getLuckiest(vector <int>(luckySet, luckySet + (sizeof luckySet / sizeof luckySet[0])), n);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int luckySet[]            = {1000, 1004, 4000, 4003, 5000};
			int n                     = 19;
			int expected__[]          = {1000, 1004, 4000, 4003, 5000, 4001, 4002, 1001, 1003, 1002, 4004, 4999, 1, 999, 4005, 4998, 2, 998, 4006 };

			clock_t start__           = clock();
			vector <int> received__   = UnluckyIntervals().getLuckiest(vector <int>(luckySet, luckySet + (sizeof luckySet / sizeof luckySet[0])), n);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int luckySet[]            = {1000000000};
			int n                     = 8;
			int expected__[]          = {1000000000, 1, 999999999, 2, 999999998, 3, 999999997, 4 };

			clock_t start__           = clock();
			vector <int> received__   = UnluckyIntervals().getLuckiest(vector <int>(luckySet, luckySet + (sizeof luckySet / sizeof luckySet[0])), n);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int luckySet[]            = ;
			int n                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = UnluckyIntervals().getLuckiest(vector <int>(luckySet, luckySet + (sizeof luckySet / sizeof luckySet[0])), n);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int luckySet[]            = ;
			int n                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = UnluckyIntervals().getLuckiest(vector <int>(luckySet, luckySet + (sizeof luckySet / sizeof luckySet[0])), n);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int luckySet[]            = ;
			int n                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = UnluckyIntervals().getLuckiest(vector <int>(luckySet, luckySet + (sizeof luckySet / sizeof luckySet[0])), n);
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
// You are given a set of integers called luckySet.  An interval [A,B], where B is greater than A, and A and B are positive integers, is considered unlucky if none of the integers between A and B, inclusive, belongs to luckySet.

An integer x is considered to be luckier than another integer y if the number of unlucky intervals that contain x is smaller than the number of unlucky intervals that contain y.  In case both x and y belong to an equal number of unlucky intervals, or both belong to an infinite number of unlucky intervals, the smallest of them is considered to be luckier than the other.

Given a vector <int> luckySet, return the top n luckiest positive integers sorted in descending order by luckiness (in other words, each element of the vector <int> must be luckier than the next element).

DEFINITION
Class:UnluckyIntervals
Method:getLuckiest
Parameters:vector <int>, int
Returns:vector <int>
Method signature:vector <int> getLuckiest(vector <int> luckySet, int n)


CONSTRAINTS
-luckySet will contain between 1 and 50 elements, inclusive.
-Each element of luckySet will be between 1 and 1000000000, inclusive.
-Each element of luckySet will be distinct.
-n will be between 1 and 100, inclusive.


EXAMPLES

0)
{3}
6

Returns: {3, 1, 2, 4, 5, 6 }

0 unlucky intervals contain 3.
1 unlucky interval contains 1: [1,2].
1 unlucky interval contains 2: [1, 2].
Since 1 and 2 are inside an equal number of intervals, 1 is considered luckier because it is less than 2.
For every number greater than 3, there is an infinite number of unlucky intervals that contain it. However, 4 and 5 are considered to be the luckiest among them, as they are smallest.

1)
{5, 11, 18}
9

Returns: {5, 11, 18, 1, 4, 6, 10, 2, 3 }

3 unlucky intervals: [1,2], [1,3] and [1,4] include 1. 
3 unlucky intervals: [1,4], [2,4] and [3,4] include 4. 
4 unlucky intervals: [6,7], [6,8], [6,9] and [6,10] include 6. 
4 unlucky intervals: [6,10], [7,10], [8,10] and [9,10] include 10. 
5 unlucky intervals: [1,2], [1,3], [1,4], [2,3] and [2,4] include 2. 
5 unlucky intervals: [1,3], [1,4], [2,3], [2,4] and [3,4] include 3. 



2)
{7, 13, 18}
9

Returns: {7, 13, 18, 14, 17, 8, 12, 1, 6 }



3)
{1000, 1004, 4000, 4003, 5000}
19

Returns: {1000, 1004, 4000, 4003, 5000, 4001, 4002, 1001, 1003, 1002, 4004, 4999, 1, 999, 4005, 4998, 2, 998, 4006 }



4)
{1000000000}
8

Returns: {1000000000, 1, 999999999, 2, 999999998, 3, 999999997, 4 }



*/

// END CUT HERE
