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

class ToastXToast {
	public:
	int bake(vector <int> undertoasted, vector <int> overtoasted) {
		sort(ALL(undertoasted));
        sort(ALL(overtoasted));
        if(overtoasted[0] < undertoasted[0]) return -1;
        if(overtoasted[SZ(overtoasted)-1] < undertoasted[SZ(undertoasted)-1]) return -1;
        if(undertoasted[SZ(undertoasted)-1] < overtoasted[0]) return 1;
        return 2;
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
			int undertoasted[]        = {2,4};
			int overtoasted[]         = {5,6,3};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int undertoasted[]        = {5};
			int overtoasted[]         = {4};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int undertoasted[]        = {1,2,3};
			int overtoasted[]         = {5,6,7};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int undertoasted[]        = {1,3,5};
			int overtoasted[]         = {2,4,6};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int undertoasted[]        = ;
			int overtoasted[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int undertoasted[]        = ;
			int overtoasted[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int undertoasted[]        = ;
			int overtoasted[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
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


Toastman is going to create several eye-popping slices of toast out of several types of bread. 



Each type of bread has a positive number X (not necessarily integer) such that if a slice of bread of that type is toasted for less than X minutes, it becomes under toasted and if it is toasted for more than X minutes, it becomes over toasted. A slice of bread that is toasted for exactly X minutes becomes an eye-popping slice of toast.  



Note that the number X for different types of bread may be different, but such numbers will be the same for every slice of bread of a particular bread type. 


Toastman has toasted several slices of bread with the hope of creating an eye-popping slice of toast from several types of bread. Unfortunately he didn't know the exact value of X for any type of bread so all the slices of bread that he toasted became either under toasted or over toasted. You are given vector <int>s undertoasted and overtoasted denoting the slices of toast that were under toasted and over toasted, respectively. Each element will be an integer denoting the number of minutes that the corresponding slice of bread was toasted. 


Toastman does not have a very good memory (his brain is made out of bread!). Although he forgot which type of bread was used for each slice of toast, he thinks that the following condition was satisfied:

Each type of bread was used for at least one under toasted slice of toast and at least one over toasted slice of toast.

Return the minumum number of types of bread that could statisfy this condition. If the condition can not be satisified return -1.

DEFINITION
Class:ToastXToast
Method:bake
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int bake(vector <int> undertoasted, vector <int> overtoasted)


NOTES
-Assume that for any positive number X, there exists a bread type that needs to be toasted for exactly X minutes in order to become an eye-popping toast.


CONSTRAINTS
-undertoasted will contain between 1 and 50 elements, inclusive.
-Each element of undertoasted will be between 1 and 1,000,000, inclusive.
-All the elements of undertoasted will be distinct.
-overtoasted will contain between 1 and 50 elements, inclusive.
-Each element of overtoasted will be between 1 and 1,000,000, inclusive.
-All the elements of overtoasted will be distinct.
-overtoasted and undertoasted will not have an element in common.


EXAMPLES

0)
{2,4}
{5,6,3}

Returns: 2

Two types of bread is sufficient as illustrated below.


1)
{5}
{4}

Returns: -1



2)
{1,2,3}
{5,6,7}

Returns: 1



3)
{1,3,5}
{2,4,6}

Returns: 2



*/

// END CUT HERE
