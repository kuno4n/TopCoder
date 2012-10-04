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

class PikachuEasy {
	public:
	string check(string word) {
        while(1){
            if(word == "") return "YES";
            else if(word.substr(0, 2) == "pi") word = word.substr(2);
            else if(word.substr(0, 2) == "ka") word = word.substr(2);
            else if(word.substr(0, 3) == "chu") word = word.substr(3);
            else return "NO";
        }
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
			string word               = "pikapi";
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = PikachuEasy().check(word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string word               = "pipikachu";
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = PikachuEasy().check(word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string word               = "pikaqiu";
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = PikachuEasy().check(word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string word               = "topcoder";
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = PikachuEasy().check(word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string word               = "piika";
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = PikachuEasy().check(word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string word               = "chupikachupipichu";
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = PikachuEasy().check(word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string word               = "pikapipachu";
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = PikachuEasy().check(word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string word               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PikachuEasy().check(word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string word               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PikachuEasy().check(word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string word               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PikachuEasy().check(word);
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
