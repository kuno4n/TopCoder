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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

class BinPacking {
	public:
	int minBins(vector <int> item) {
		sort(ALL(item));
        int n = SZ(item);
        int res = (1<<29);
        
        int cnt100 = 0;
        REP(i, n) if(item[i] == 100) cnt100++;
        
        for(int i = 0; i <= cnt100; i+=3){
            int tmp = i/3;
            int ptr1 = i/3 * 3;
            int ptr2 = n-1;
            while(ptr1 < ptr2){
                if(item[ptr1] + item[ptr2] <= 300) tmp++, ptr1++, ptr2--;
                else tmp++, ptr2--;
            }
            if(ptr1 == ptr2) tmp++;
            
            chmin(res, tmp);
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
			int item[]                = {150, 150, 150, 150, 150};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = BinPacking().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int item[]                = {130, 140, 150, 160};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = BinPacking().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int item[]                = {100, 100, 100, 100, 100, 100, 100, 100, 100};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = BinPacking().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int item[]                = {100, 200, 100, 100, 100, 100, 200, 100, 200};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = BinPacking().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int item[]                = {157, 142, 167, 133, 135, 157, 143, 160, 141, 123, 162, 159, 165, 137, 138, 152};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = BinPacking().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int item[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BinPacking().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int item[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BinPacking().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int item[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BinPacking().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
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
// Fox Ciel has some items. The weight of the i-th (0-based) item is item[i]. She wants to put all items into bins.


The capacity of each bin is 300. She can put an arbitrary number of items into a single bin, but the total weight of items in a bin must be less than or equal to 300.


You are given the vector <int> item. It is known that the weight of each item is between 100 and 300, inclusive. Return the minimal number of bins required to store all items.


DEFINITION
Class:BinPacking
Method:minBins
Parameters:vector <int>
Returns:int
Method signature:int minBins(vector <int> item)


CONSTRAINTS
-item will contain between 1 and 50 elements, inclusive.
-Each element of item will be between 100 and 300, inclusive.


EXAMPLES

0)
{150, 150, 150, 150, 150}

Returns: 3

You have five items and each bin can hold at most two of them. You need at least three bins.

1)
{130, 140, 150, 160}

Returns: 2

For example, you can distribute the items in the following way:

Bin 1: 130, 150
Bin 2: 140, 160



2)
{100, 100, 100, 100, 100, 100, 100, 100, 100}

Returns: 3



3)
{100, 200, 100, 100, 100, 100, 200, 100, 200}

Returns: 4



4)
{157, 142, 167, 133, 135, 157, 143, 160, 141, 123, 162, 159, 165, 137, 138, 152}

Returns: 8



*/

// END CUT HERE
