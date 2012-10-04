// Paste me into the FileEdit configuration dialog

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
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define OUT(A) std::cout << #A << '='<<A << std::endl;

class ElectionFraudDiv2 {
public:
   string IsFraudulent( vector <int> p ) {

	   double mn=0.0,mx=0.0;
	   FOR(i,0,SZ(p)){
		   if(p[i]!=0) mn += (double)p[i]-0.5;
		   if(p[i]!=100) mx += (double)p[i]+0.5;
		   else mx += (double)p[i];
	   }
	   if(mx == 100 && SZ(p) ==1) return "NO";
	   if(mn>100 || mx<=100) return "YES";
	   else return "NO";

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
			int percentages[]         = {100};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = ElectionFraudDiv2().IsFraudulent(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int percentages[]         = {34, 34, 34};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = ElectionFraudDiv2().IsFraudulent(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int percentages[]         = {12, 12, 12, 12, 12, 12, 12, 12};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = ElectionFraudDiv2().IsFraudulent(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int percentages[]         = {13, 13, 13, 13, 13, 13, 13, 13};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = ElectionFraudDiv2().IsFraudulent(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int percentages[]         = {0, 1, 100};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = ElectionFraudDiv2().IsFraudulent(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int percentages[]         = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = ElectionFraudDiv2().IsFraudulent(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int percentages[]         = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = ElectionFraudDiv2().IsFraudulent(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int percentages[]         = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = ElectionFraudDiv2().IsFraudulent(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int percentages[]         = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = ElectionFraudDiv2().IsFraudulent(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
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
// END CUT HERE
