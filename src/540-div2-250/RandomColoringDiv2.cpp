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

class RandomColoringDiv2 {
public:
   int getCount( int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2 ) {

	   int res=0;
	   FOR(r,0,maxR){
		   FOR(g,0,maxG){
			   FOR(b,0,maxB){
				   if(
					   abs(r-startR)<=d2 &&
					   abs(g-startG)<=d2 &&
					   abs(b-startB)<=d2 &&
					   (
					   abs(r-startR)>=d1 ||
					   abs(g-startG)>=d1 ||
					   abs(b-startB)>=d1 


					   )
					 )
					 res++;
			   }
		   }
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
			int maxR                  = 5;
			int maxG                  = 1;
			int maxB                  = 1;
			int startR                = 2;
			int startG                = 0;
			int startB                = 0;
			int d1                    = 0;
			int d2                    = 1;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = RandomColoringDiv2().getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int maxR                  = 4;
			int maxG                  = 2;
			int maxB                  = 2;
			int startR                = 0;
			int startG                = 0;
			int startB                = 0;
			int d1                    = 3;
			int d2                    = 3;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = RandomColoringDiv2().getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int maxR                  = 4;
			int maxG                  = 2;
			int maxB                  = 2;
			int startR                = 0;
			int startG                = 0;
			int startB                = 0;
			int d1                    = 5;
			int d2                    = 5;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = RandomColoringDiv2().getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int maxR                  = 6;
			int maxG                  = 9;
			int maxB                  = 10;
			int startR                = 1;
			int startG                = 2;
			int startB                = 3;
			int d1                    = 0;
			int d2                    = 10;
			int expected__            = 540;

			clock_t start__           = clock();
			int received__            = RandomColoringDiv2().getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int maxR                  = 6;
			int maxG                  = 9;
			int maxB                  = 10;
			int startR                = 1;
			int startG                = 2;
			int startB                = 3;
			int d1                    = 4;
			int d2                    = 10;
			int expected__            = 330;

			clock_t start__           = clock();
			int received__            = RandomColoringDiv2().getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int maxR                  = 49;
			int maxG                  = 59;
			int maxB                  = 53;
			int startR                = 12;
			int startG                = 23;
			int startB                = 13;
			int d1                    = 11;
			int d2                    = 22;
			int expected__            = 47439;

			clock_t start__           = clock();
			int received__            = RandomColoringDiv2().getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int maxR                  = ;
			int maxG                  = ;
			int maxB                  = ;
			int startR                = ;
			int startG                = ;
			int startB                = ;
			int d1                    = ;
			int d2                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RandomColoringDiv2().getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int maxR                  = ;
			int maxG                  = ;
			int maxB                  = ;
			int startR                = ;
			int startG                = ;
			int startB                = ;
			int d1                    = ;
			int d2                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RandomColoringDiv2().getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int maxR                  = ;
			int maxG                  = ;
			int maxB                  = ;
			int startR                = ;
			int startG                = ;
			int startB                = ;
			int d1                    = ;
			int d2                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RandomColoringDiv2().getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2);
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
