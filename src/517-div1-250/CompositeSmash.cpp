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

class CompositeSmash {
	public:
	string thePossible(int N, int target) {
		if(N == target) return "Yes";
        int n = N;
        set <int> s; s.clear();
        for(int i=2; i<=N;) {
            if(!(N%i)) {
                s.insert(i);
                N /= i;
                continue;
            }
            i++;
        }
        if(SZ(s) != 1) return (s.find(target) == s.end()) ? "No" : "Yes";
        int k = *(s.begin());
        if(n >= k*k) s.insert(k*k);
        return (s.find(target) == s.end()) ? "No" : "Yes";
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int N                     = 517;
			int target                = 47;
			string expected__         = "Yes";

			clock_t start__           = clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 8;
			int target                = 4;
			string expected__         = "Yes";

			clock_t start__           = clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 12;
			int target                = 6;
			string expected__         = "No";

			clock_t start__           = clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 5;
			int target                = 8;
			string expected__         = "No";

			clock_t start__           = clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 100000;
			int target                = 100000;
			string expected__         = "Yes";

			clock_t start__           = clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 5858;
			int target                = 2;
			string expected__         = "Yes";

			clock_t start__           = clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int N                     = 81461;
			int target                = 2809;
			string expected__         = "No";

			clock_t start__           = clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			int N                     = 65536;
			int target                = 256;
			string expected__         = "No";

			clock_t start__           = clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			int N                     = ;
			int target                = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int N                     = ;
			int target                = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int N                     = ;
			int target                = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CompositeSmash().thePossible(N, target);
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
// Toastwoman wants to be a magical girl. As training, she wants to make a ball that contains an integer target.


Initially she has a ball that contains an integer N. She can smash a ball that contains a composite number (see notes for definition) and break it into two balls. Each new ball will also contain an integer. If she smashes a ball that contains a composite number x and it breaks into two balls that contain y and z, it satisfies y &ge 2, z &ge 2 and yz = x. For example, if she smashes a ball that contains 12, it breaks into 2 and 6 or 3 and 4. Toastwoman can control the ball she smashes, but she can't control the numbers in the two new balls when there are multiple pairs of (y, z) that satisfy the above conditions. She can apply the described ball smash operation arbitrary number of times, but she can't smash a ball that contains a non-composite number.


If she can always make a ball that contains target, return "Yes" (quotes for clarity). Otherwise, return "No" (quotes for clarity).


DEFINITION
Class:CompositeSmash
Method:thePossible
Parameters:int, int
Returns:string
Method signature:string thePossible(int N, int target)


NOTES
-A positive integer x is called a composite number if it has at least one divisor other than 1 and x. For example, 4 and 6 are composite numbers, while 1 and 5 are not composite numbers.


CONSTRAINTS
-N will be between 2 and 100,000, inclusive.
-target will be between 2 and 100,000, inclusive.


EXAMPLES

0)
517
47

Returns: "Yes"

If?she?smashes?517,?it?breaks?into?11?and?47.

1)
8
4

Returns: "Yes"

If?she?smashes?8,?it?breaks?into?2?and?4.

2)
12
6

Returns: "No"

If?she?smashes?12?and?it?breaks?into?3?and?4,?she?can't?make?6.

3)
5
8

Returns: "No"



4)
100000
100000

Returns: "Yes"

She already has target.

5)
5858
2

Returns: "Yes"



6)
81461
2809

Returns: "No"



7)
65536
256

Returns: "No"

*/

// END CUT HERE
