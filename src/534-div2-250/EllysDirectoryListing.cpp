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

class EllysDirectoryListing {
public:
   vector <string> getFiles( vector <string> files ) {
	   bool swapped = false;
	   FOR(i,0,SZ(files)-2){
		   if(files[i]==".."||files[i]=="."){
			   string tmp = files[i];
			   if(swapped){
				   files[i] = files[SZ(files)-2];
				   files[SZ(files)-2] = tmp;
			   }
			   else{
				   files[i] = files[SZ(files)-1];
				   files[SZ(files)-1] = tmp;
				   swapped = true;
			   }
			   i--;
		   }
	   }
	   return files;
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
	template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) { 
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
			string files[]            = {"ContestApplet.jnlp", ".", "Image.jpg", "..", "Book.pdf", "Movie.avi"};
			string expected__[]       = {"ContestApplet.jnlp", "Movie.avi", "Image.jpg", "Book.pdf", "..", "." };

			clock_t start__           = clock();
			vector <string> received__ = EllysDirectoryListing().getFiles(vector <string>(files, files + (sizeof files / sizeof files[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string files[]            = {"Image.jpg", "..", "."};
			string expected__[]       = {"Image.jpg", "..", "." };

			clock_t start__           = clock();
			vector <string> received__ = EllysDirectoryListing().getFiles(vector <string>(files, files + (sizeof files / sizeof files[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string files[]            = {"..", ".", "Image.jpg"};
			string expected__[]       = {"Image.jpg", ".", ".." };

			clock_t start__           = clock();
			vector <string> received__ = EllysDirectoryListing().getFiles(vector <string>(files, files + (sizeof files / sizeof files[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string files[]            = {"No", "..", "Zaphod", ".", "Just", "very", "very...", "Improbable"};
			string expected__[]       = {"No", "Improbable", "Zaphod", "very...", "Just", "very", ".", ".." };

			clock_t start__           = clock();
			vector <string> received__ = EllysDirectoryListing().getFiles(vector <string>(files, files + (sizeof files / sizeof files[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string files[]            = {"www.topcoder.com", "Ever.tried", ".", "Ever.failed", "..", "No", "Matter.", "Try", "Again.", "Fail", "Again..", "Fail.Better"};
			string expected__[]       = {"www.topcoder.com", "Ever.tried", "Fail.Better", "Ever.failed", "Again..", "No", "Matter.", "Try", "Again.", "Fail", "..", "." };

			clock_t start__           = clock();
			vector <string> received__ = EllysDirectoryListing().getFiles(vector <string>(files, files + (sizeof files / sizeof files[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			string files[]            = {"This", ".", "is", "tricky", "test", ".."};
			string expected__[]       = {"This", "test", "is", "tricky", "..", "." };

			clock_t start__           = clock();
			vector <string> received__ = EllysDirectoryListing().getFiles(vector <string>(files, files + (sizeof files / sizeof files[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string files[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = EllysDirectoryListing().getFiles(vector <string>(files, files + (sizeof files / sizeof files[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string files[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = EllysDirectoryListing().getFiles(vector <string>(files, files + (sizeof files / sizeof files[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			string files[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = EllysDirectoryListing().getFiles(vector <string>(files, files + (sizeof files / sizeof files[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
