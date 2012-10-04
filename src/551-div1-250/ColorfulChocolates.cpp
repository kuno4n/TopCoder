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

class ColorfulChocolates {
public:
   int maximumSpread( string C, int maxSwaps ) {
	   int res=0;
	   FOR(i,0,SZ(C)){
		   int R=0,L=0,cost=0;
		   char c=C[i];
		   FOR(j,1,SZ(C)){
			   if(i+j<SZ(C)){
				   if(C[i+j]==c){
					   int costtmp = cost+j-1-R;
					   if(costtmp>maxSwaps) ;
					   else {R++; cost=costtmp;}
				   }
			   }
			   if(i-j>=0){
				   if(C[i-j]==c){
					   int costtmp = cost+j-1-L;
					   if(costtmp>maxSwaps) ;
					   else {L++; cost=costtmp;}
				   }
			   }
		   }
		   res= max(res,R+L+1);
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
			string chocolates         = "ABCDCBC";
			int maxSwaps              = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string chocolates         = "ABCDCBC";
			int maxSwaps              = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string chocolates         = "ABBABABBA";
			int maxSwaps              = 3;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string chocolates         = "ABBABABBA";
			int maxSwaps              = 4;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string chocolates         = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO";
			int maxSwaps              = 77;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string chocolates         = ;
			int maxSwaps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string chocolates         = ;
			int maxSwaps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string chocolates         = ;
			int maxSwaps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
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
