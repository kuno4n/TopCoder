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

LL sal[50];
int N;
vector <string> r;

LL cal(int emp){
    if(sal[emp] > 0) return sal[emp];
    
    LL tmp = 0;
    REP(i, N){
        if(r[emp][i] == 'Y') tmp += cal(i);
    }
    LL res = (tmp == 0 ? 1 : tmp);
    sal[emp] = res;
    return res;
}

class CorporationSalary {
	public:
	long long totalSalary(vector <string> relations) {
		N = SZ(relations);
        r = relations;
        MSET(sal, -1);
        
        LL res = 0;
        
        REP(i, N){
            res += cal(i);
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
			string relations[]        = {"N"};
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = CorporationSalary().totalSalary(vector <string>(relations, relations + (sizeof relations / sizeof relations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string relations[]        = {"NNYN",
 "NNYN",
 "NNNN",
 "NYYN"};
			long long expected__      = 5;

			clock_t start__           = clock();
			long long received__      = CorporationSalary().totalSalary(vector <string>(relations, relations + (sizeof relations / sizeof relations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string relations[]        = {"NNNNNN",
 "YNYNNY",
 "YNNNNY",
 "NNNNNN",
 "YNYNNN",
 "YNNYNN"};
			long long expected__      = 17;

			clock_t start__           = clock();
			long long received__      = CorporationSalary().totalSalary(vector <string>(relations, relations + (sizeof relations / sizeof relations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string relations[]        = {"NYNNYN",
 "NNNNNN",
 "NNNNNN",
 "NNYNNN",
 "NNNNNN",
 "NNNYYN"};
			long long expected__      = 8;

			clock_t start__           = clock();
			long long received__      = CorporationSalary().totalSalary(vector <string>(relations, relations + (sizeof relations / sizeof relations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string relations[]        = {"NNNN",
 "NNNN",
 "NNNN",
 "NNNN"};
			long long expected__      = 4;

			clock_t start__           = clock();
			long long received__      = CorporationSalary().totalSalary(vector <string>(relations, relations + (sizeof relations / sizeof relations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string relations[]        = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = CorporationSalary().totalSalary(vector <string>(relations, relations + (sizeof relations / sizeof relations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string relations[]        = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = CorporationSalary().totalSalary(vector <string>(relations, relations + (sizeof relations / sizeof relations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string relations[]        = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = CorporationSalary().totalSalary(vector <string>(relations, relations + (sizeof relations / sizeof relations[0])));
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
// You are working in the HR department of a huge corporation. Each employee may have several direct managers and/or several direct subordinates. Of course, his subordinates may also have their own subordinates, and his direct managers may have their own managers. We say employee X is a boss of employee Y if there exists a sequence of employees A, B, ..., D, such that X is the manager of A, A is the manager of B, and so on, and D is the manager of Y (of course, if X is a direct manager of employee Y, X will be a boss of employee Y). If A is a boss of B, then B can not be a boss of A. According to the new company policy, the salary of an employee with no subordinates is 1. If an employee has any subordinates, then his salary is equal to the sum of the salaries of his direct subordinates.

You will be given a vector <string> relations, where the j-th character of the i-th element is 'Y' if employee i is a direct manager of employee j, and 'N' otherwise. Return the sum of the salaries of all the employees.

DEFINITION
Class:CorporationSalary
Method:totalSalary
Parameters:vector <string>
Returns:long long
Method signature:long long totalSalary(vector <string> relations)


CONSTRAINTS
-relations will contain between 1 and 50 elements, inclusive. 
-Each element of relations will contain the same number of characters, which is equal to number of elements in relations.
-Each element of relations will contain only 'Y' or 'N'.
-Character i of element i of relations will be 'N' for each i. 
-If A is a boss of B, then B will not be a boss of A.


EXAMPLES

0)
{"N"}

Returns: 1

Here we've got only one employee so the answer is 1.

1)
{"NNYN",
 "NNYN",
 "NNNN",
 "NYYN"}

Returns: 5

There are 4 employees here. 0, 1 and 3 are managers of 2, and also 3 is a manager of 1. So:
salary(2) = 1 
salary(0) = salary(2) = 1
salary(1) = salary(2) = 1 
salary(3) = salary(2) + salary(1) = 2

2)
{"NNNNNN",
 "YNYNNY",
 "YNNNNY",
 "NNNNNN",
 "YNYNNN",
 "YNNYNN"}

Returns: 17



3)
{"NYNNYN",
 "NNNNNN",
 "NNNNNN",
 "NNYNNN",
 "NNNNNN",
 "NNNYYN"}

Returns: 8



4)
{"NNNN",
 "NNNN",
 "NNNN",
 "NNNN"}

Returns: 4



*/

// END CUT HERE
