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

class WorkingRabbits {
public:
   double getEfficiency( vector <string> p ) {
	   int  P=0, Q=0;
	   FOR(i,0,SZ(p)){
		   FOR(j,i+1,SZ(p[0])){
			   P+=p[i][j]-'0';
			   Q++;
		   }
	   }
	   return (double)P/(double)Q;
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			string profit[]           = { "071", 
  "702", 
  "120" }
;
			double expected__         = 3.3333333333333335;

			clock_t start__           = clock();
			double received__         = WorkingRabbits().getEfficiency(vector <string>(profit, profit + (sizeof profit / sizeof profit[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string profit[]           = { "00", 
  "00" }
;
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = WorkingRabbits().getEfficiency(vector <string>(profit, profit + (sizeof profit / sizeof profit[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string profit[]           = { "0999", 
  "9099", 
  "9909", 
  "9990" }
;
			double expected__         = 9.0;

			clock_t start__           = clock();
			double received__         = WorkingRabbits().getEfficiency(vector <string>(profit, profit + (sizeof profit / sizeof profit[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string profit[]           = { "013040", 
  "100010", 
  "300060", 
  "000008", 
  "416000", 
  "000800" }
;
			double expected__         = 1.5333333333333334;

			clock_t start__           = clock();
			double received__         = WorkingRabbits().getEfficiency(vector <string>(profit, profit + (sizeof profit / sizeof profit[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string profit[]           = { "06390061", 
  "60960062", 
  "39090270", 
  "96900262", 
  "00000212", 
  "00222026", 
  "66761201", 
  "12022610" }
;
			double expected__         = 3.2142857142857144;

			clock_t start__           = clock();
			double received__         = WorkingRabbits().getEfficiency(vector <string>(profit, profit + (sizeof profit / sizeof profit[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string profit[]           = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = WorkingRabbits().getEfficiency(vector <string>(profit, profit + (sizeof profit / sizeof profit[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string profit[]           = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = WorkingRabbits().getEfficiency(vector <string>(profit, profit + (sizeof profit / sizeof profit[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string profit[]           = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = WorkingRabbits().getEfficiency(vector <string>(profit, profit + (sizeof profit / sizeof profit[0])));
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
