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

#define INF ((LL)1<<63)-1

class TheCoffeeTimeDivOne {
	public:
	long long find(int n, vector <int> t) {
        LL res = 0;
        sort(ALL(t));
        res += 4*SZ(t) + 47 + t[SZ(t)-1]*2;
        
        LL back = INF;
        REP(i, 7){
            LL tmp = 0;
            REP(j, SZ(t)-1){
                if(j%7 == i) tmp += t[j]*2+47;
            }
            back = min(back, tmp);
        }
        res += back;
        if(n == SZ(t)) return res;
        
        LL last = n;
        sort(ALL(t), greater<int>());
        for(int i=0; i<SZ(t); i++, last--) if(t[i] != last) break;
        sort(ALL(t));
        res += 4*(n-SZ(t)) + 47 + last*2;
        
        back = INF;
        int sz = SZ(t);
        REP(i, 7){
            LL tmp = 0;
//            int ptr = 0, cnt = 0;
//            FOR(j, 1, n){
//                if(ptr<sz && j==t[ptr]){
//                    ptr++;
//                    continue;
//                }
//                if(cnt%7 == i && j!=last) tmp += j*2+47;
//                cnt++;
//            }
            int ptr = 0;
            for(int j=i+1; j<last; j+=7){
                while(ptr<sz && t[ptr]<=j){
                    ptr++;
                    j++;
                }
                if(j>=last) break;
                tmp += j*2 + 47;
            }
            back = min(back, tmp);
        }
        res += back;
        
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
			int n                     = 2;
			int tea[]                 = {1};
			long long expected__      = 108;

			clock_t start__           = clock();
			long long received__      = TheCoffeeTimeDivOne().find(n, vector <int>(tea, tea + (sizeof tea / sizeof tea[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 2;
			int tea[]                 = {2, 1};
			long long expected__      = 59;

			clock_t start__           = clock();
			long long received__      = TheCoffeeTimeDivOne().find(n, vector <int>(tea, tea + (sizeof tea / sizeof tea[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 15;
			int tea[]                 = {1, 2, 3, 4, 5, 6, 7};
			long long expected__      = 261;

			clock_t start__           = clock();
			long long received__      = TheCoffeeTimeDivOne().find(n, vector <int>(tea, tea + (sizeof tea / sizeof tea[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 47;
			int tea[]                 = {1, 10, 6, 2, 4};
			long long expected__      = 891;

			clock_t start__           = clock();
			long long received__      = TheCoffeeTimeDivOne().find(n, vector <int>(tea, tea + (sizeof tea / sizeof tea[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			int tea[]                 = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheCoffeeTimeDivOne().find(n, vector <int>(tea, tea + (sizeof tea / sizeof tea[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			int tea[]                 = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheCoffeeTimeDivOne().find(n, vector <int>(tea, tea + (sizeof tea / sizeof tea[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int tea[]                 = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheCoffeeTimeDivOne().find(n, vector <int>(tea, tea + (sizeof tea / sizeof tea[0])));
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
// John and Brus are flying on an airplane and now it's coffee time.

There are n seats in the plane numbered from 1 to n, one seat in each row. All seats are occupied, thus there are n passengers overall (including John and Brus). A stewardess will serve a cup of coffee or tea to each passenger. She needs to serve tea to all passengers whose seat numbers are listed in vector <int> tea, and she needs to serve coffee to all other passengers.

A coffee and tea machine is located just before the first seat of the plane. The stewardess has a flask that can contain enough coffee or tea to serve at most 7 passengers. Initially, the stewardess is located near the coffee and tea machine and the flask is empty.

The stewardess can perform the following kinds of actions:

Move from the coffee and tea machine to seat 1 or move from seat 1 to the coffee and tea machine. Each of these two actions takes 1 second.
Move from seat i, i > 1, to seat i-1. It takes 1 second.
Move from seat i, i < n, to seat i+1. It takes 1 second.
If she is near seat i, the passenger at this seat has not yet been served and the current type of drink in the flask is the same as the drink this passenger wants, she can serve this passenger with a cup of drink he/she wants. It takes 4 seconds.
If she is near the coffee and tea machine and the flask is empty, she can fill the flask with either tea or coffee (but not both simultaneously). It takes 47 seconds. Note that she can fill the flask partially (to serve less than 7 passengers), but it still takes 47 seconds.


Given int n and vector <int> tea, return the minimal time needed for the stewardess to serve all passengers with proper drinks and return to the coffee and tea machine.

DEFINITION
Class:TheCoffeeTimeDivOne
Method:find
Parameters:int, vector <int>
Returns:long long
Method signature:long long find(int n, vector <int> tea)


CONSTRAINTS
-n will be between 2 and 44,777,777, inclusive.
-tea will contain between 1 and 47 elements, inclusive.
-Each element of tea will be between 1 and n, inclusive.
-All elements of tea will be distinct.


EXAMPLES

0)
2
{1}

Returns: 108

The stewardess will serve coffee in 47+2+4+2=55 seconds and tea in 47+1+4+1=53 seconds.

1)
2
{2, 1}

Returns: 59

Here she only needs to serve tea.

2)
15
{1, 2, 3, 4, 5, 6, 7}

Returns: 261

The stewardess will fill the flask three times overall: once with tea and two times with coffee.

3)
47
{1, 10, 6, 2, 4}

Returns: 891

*/

// END CUT HERE
