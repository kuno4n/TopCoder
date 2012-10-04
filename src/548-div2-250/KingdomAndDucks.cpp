// Paste me into the FileEdit configuration dialog

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define SZ(x) ((int)x.size()) 
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define OUT(A) std::cout << #A << '='<<A << std::endl;

class KingdomAndDucks {
public:
   int minDucks( vector <int> d ) {
	   map <int, int> m;
	   int cnt=0;
	   FOR(i, 0, SZ(d)) {
		   m[d[i]]++;
		   cnt=max(cnt, m[d[i]]);
	   }
	   return cnt*SZ(m);

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
			int duckTypes[]           = {5, 8};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = KingdomAndDucks().minDucks(vector <int>(duckTypes, duckTypes + (sizeof duckTypes / sizeof duckTypes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int duckTypes[]           = {4, 7, 4, 7, 4};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = KingdomAndDucks().minDucks(vector <int>(duckTypes, duckTypes + (sizeof duckTypes / sizeof duckTypes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int duckTypes[]           = {17, 17, 19, 23, 23, 19, 19, 17, 17};
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = KingdomAndDucks().minDucks(vector <int>(duckTypes, duckTypes + (sizeof duckTypes / sizeof duckTypes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int duckTypes[]           = {50};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = KingdomAndDucks().minDucks(vector <int>(duckTypes, duckTypes + (sizeof duckTypes / sizeof duckTypes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int duckTypes[]           = {10, 10, 10, 10, 10};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = KingdomAndDucks().minDucks(vector <int>(duckTypes, duckTypes + (sizeof duckTypes / sizeof duckTypes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int duckTypes[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomAndDucks().minDucks(vector <int>(duckTypes, duckTypes + (sizeof duckTypes / sizeof duckTypes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int duckTypes[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomAndDucks().minDucks(vector <int>(duckTypes, duckTypes + (sizeof duckTypes / sizeof duckTypes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int duckTypes[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomAndDucks().minDucks(vector <int>(duckTypes, duckTypes + (sizeof duckTypes / sizeof duckTypes[0])));
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
