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

class FoxAndIntegers {
public:
   vector <int> get( int AminusB, int BminusC, int AplusB, int BplusC ) {
	   VI res;

	   if((AminusB+AplusB)%2!=0) return res;
	   if((BminusC+BplusC)%2!=0) return res;

	   if((AplusB-AminusB) != (BminusC+BplusC)) return res;

	   res.PB((AminusB+AplusB)/2);
	   res.PB((AplusB-AminusB)/2);
	   res.PB((BplusC-BminusC)/2);

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
			int AminusB               = 1;
			int BminusC               = -2;
			int AplusB                = 3;
			int BplusC                = 4;
			int expected__[]          = {2, 1, 3 };

			clock_t start__           = clock();
			vector <int> received__   = FoxAndIntegers().get(AminusB, BminusC, AplusB, BplusC);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int AminusB               = 0;
			int BminusC               = 0;
			int AplusB                = 5;
			int BplusC                = 5;
			int expected__[]          = { };

			clock_t start__           = clock();
			vector <int> received__   = FoxAndIntegers().get(AminusB, BminusC, AplusB, BplusC);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int AminusB               = 10;
			int BminusC               = -23;
			int AplusB                = -10;
			int BplusC                = 3;
			int expected__[]          = {0, -10, 13 };

			clock_t start__           = clock();
			vector <int> received__   = FoxAndIntegers().get(AminusB, BminusC, AplusB, BplusC);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int AminusB               = -27;
			int BminusC               = 14;
			int AplusB                = 13;
			int BplusC                = 22;
			int expected__[]          = { };

			clock_t start__           = clock();
			vector <int> received__   = FoxAndIntegers().get(AminusB, BminusC, AplusB, BplusC);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int AminusB               = 30;
			int BminusC               = 30;
			int AplusB                = 30;
			int BplusC                = -30;
			int expected__[]          = {30, 0, -30 };

			clock_t start__           = clock();
			vector <int> received__   = FoxAndIntegers().get(AminusB, BminusC, AplusB, BplusC);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int AminusB               = ;
			int BminusC               = ;
			int AplusB                = ;
			int BplusC                = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = FoxAndIntegers().get(AminusB, BminusC, AplusB, BplusC);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int AminusB               = ;
			int BminusC               = ;
			int AplusB                = ;
			int BplusC                = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = FoxAndIntegers().get(AminusB, BminusC, AplusB, BplusC);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int AminusB               = ;
			int BminusC               = ;
			int AplusB                = ;
			int BplusC                = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = FoxAndIntegers().get(AminusB, BminusC, AplusB, BplusC);
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
// END CUT HERE
