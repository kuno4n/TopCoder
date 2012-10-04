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

class ANDEquation {
public:
   int restoreY( vector <int> A ) {


	   FOR(i,0,SZ(A)){
	   int a = -1;
		   FOR(j,0,SZ(A)){
			   if(j!=i) a&=A[j];
		   }
		   if(a==A[i]) return a;
	   }
	   return -1;

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
			int A[]                   = {1, 3, 5} ;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ANDEquation().restoreY(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A[]                   = {31, 7} ;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ANDEquation().restoreY(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A[]                   = {31, 7, 7} ;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = ANDEquation().restoreY(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A[]                   = {1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0, 0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,1};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ANDEquation().restoreY(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int A[]                   = {191411,256951,191411,191411,191411,256951,195507,191411,192435,191411, 191411,195511,191419,191411,256947,191415,191475,195579,191415,191411, 191483,191411,191419,191475,256947,191411,191411,191411,191419,256947, 191411,191411,191411};
			int expected__            = 191411;

			clock_t start__           = clock();
			int received__            = ANDEquation().restoreY(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int A[]                   = {1362,1066,1659,2010,1912,1720,1851,1593,1799,1805,1139,1493,1141,1163,1211};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ANDEquation().restoreY(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int A[]                   = {2, 3, 7, 19};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ANDEquation().restoreY(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int A[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ANDEquation().restoreY(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int A[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ANDEquation().restoreY(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int A[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ANDEquation().restoreY(vector <int>(A, A + (sizeof A / sizeof A[0])));
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
