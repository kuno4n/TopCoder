#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset((x), (a), (int)sizeof(x))
#define VI vector < int >
#define LL long long 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FIT(it,v) for(typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define OUT(A) cout << #A << " = " << A << endl

class P8XMatrixTransformation {
	public:
	string solve(vector <string> o, vector <string> t) {
		int co=0;
        int to=0;
        REP(i,SZ(o)){
            REP(j,SZ(o[0])){
                if(o[i][j]=='1') co++;
            }
        }
        REP(i,SZ(t)){
            REP(j,SZ(t[0])){
                if(t[i][j]=='1') to++;
            }
        }
        return co == to ? "YES" : "NO";
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
			string original[]         = {"01"
,"11"};
			string target[]           = {"11"
,"10"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = P8XMatrixTransformation().solve(vector <string>(original, original + (sizeof original / sizeof original[0])), vector <string>(target, target + (sizeof target / sizeof target[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string original[]         = {"0111"
,"0011"};
			string target[]           = {"1011"
,"1100"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = P8XMatrixTransformation().solve(vector <string>(original, original + (sizeof original / sizeof original[0])), vector <string>(target, target + (sizeof target / sizeof target[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string original[]         = {"0"};
			string target[]           = {"1"};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = P8XMatrixTransformation().solve(vector <string>(original, original + (sizeof original / sizeof original[0])), vector <string>(target, target + (sizeof target / sizeof target[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string original[]         = {"1111"
,"1111"
,"0000"
,"0000"};
			string target[]           = {"1111"
,"1111"
,"0000"
,"0000"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = P8XMatrixTransformation().solve(vector <string>(original, original + (sizeof original / sizeof original[0])), vector <string>(target, target + (sizeof target / sizeof target[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string original[]         = {"0110"
,"1001"
,"0110"};
			string target[]           = {"1111"
,"0110"
,"0000"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = P8XMatrixTransformation().solve(vector <string>(original, original + (sizeof original / sizeof original[0])), vector <string>(target, target + (sizeof target / sizeof target[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string original[]         = {"0000"
,"1111"
,"0000"};
			string target[]           = {"1111"
,"0000"
,"1111"};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = P8XMatrixTransformation().solve(vector <string>(original, original + (sizeof original / sizeof original[0])), vector <string>(target, target + (sizeof target / sizeof target[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string original[]         = ;
			string target[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = P8XMatrixTransformation().solve(vector <string>(original, original + (sizeof original / sizeof original[0])), vector <string>(target, target + (sizeof target / sizeof target[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string original[]         = ;
			string target[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = P8XMatrixTransformation().solve(vector <string>(original, original + (sizeof original / sizeof original[0])), vector <string>(target, target + (sizeof target / sizeof target[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string original[]         = ;
			string target[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = P8XMatrixTransformation().solve(vector <string>(original, original + (sizeof original / sizeof original[0])), vector <string>(target, target + (sizeof target / sizeof target[0])));
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

You are given two vector <string>s original and target, which are two rectangular matrices with the same dimensions. Each character in the matrices will be either '0' or '1'. You want to transform original into target. You are only allowed to use one type of operations: Pick either a single row or a single column, and permute all its characters arbitrarily. You may use as many operations as you want to, one after another.

Is it possible to transform original into target by using the allowed operations only? Return "YES" if it's possible, "NO" otherwise (quotes for clarity).

DEFINITION
Class:P8XMatrixTransformation
Method:solve
Parameters:vector <string>, vector <string>
Returns:string
Method signature:string solve(vector <string> original, vector <string> target)


NOTES
-Permuting the characters means rearranging them into a new order.


CONSTRAINTS
-original will contain between 1 and 50 elements, inclusive.
-Each element of original will contain between 1 and 50 characters, inclusive.
-All the elements of original will contain the same number of characters.
-Each character in each element of original will be either '0' or '1'.
-target will contain exactly R elements, where R is the number of elements in original.
-Each element of target will contain exactly C characters, where C is the number of characters in original[0].
-Each character in each element of target will be either '0' or '1'.


EXAMPLES

0)
{"01"
,"11"}
{"11"
,"10"}

Returns: "YES"

For example, you can apply the following operations:

That is, you can first permute the first row and then the second column in the way shown above.

1)
{"0111"
,"0011"}
{"1011"
,"1100"}

Returns: "YES"



2)
{"0"}
{"1"}

Returns: "NO"



3)
{"1111"
,"1111"
,"0000"
,"0000"}
{"1111"
,"1111"
,"0000"
,"0000"}

Returns: "YES"



4)
{"0110"
,"1001"
,"0110"}
{"1111"
,"0110"
,"0000"}

Returns: "YES"



5)
{"0000"
,"1111"
,"0000"}
{"1111"
,"0000"
,"1111"}

Returns: "NO"



*/

// END CUT HERE
