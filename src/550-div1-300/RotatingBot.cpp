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

class RotatingBot {
public:
   int minArea( vector <int> moves ) {

	   bool used[200][200];
	   int x = 100, y = 100;
	   MSET(used,false);
	   used[x][y] = true;

	   int minx=x, maxx=x, miny=y, maxy=y;
	   int d=0;
	   int dx[4] = {1,0,-1,0};
	   int dy[4] = {0,1,0,-1};

	   FOR(i,0,SZ(moves)){
		   FOR(j,0,moves[i]){
			   x += dx[d];
			   y += dy[d];
			   if( used[x][y] ) return -1;
			   used[x][y] = true;

			   minx = min(x, minx);
			   maxx = max(x, maxx);
			   miny = min(y, miny);
			   maxy = max(y, maxy);
		   }
		   if(i!=SZ(moves)-1){
			   if(!used[x+dx[d]][y+dy[d]]){
				   if(d==0){
					   if(x!=maxx) return -1;
				   }
				   if(d==1){
					   if(y!=maxy) return -1;
				   }
				   if(d==2){
					   if(x!=minx) return -1;
				   }
				   if(d==3){
					   if(y!=miny) return -1;
				   }
			   }
		   }
		   d = (d+1)%4;
	   }

	   if(SZ(moves)>=5 ){
		   if(moves[4]>moves[2])return -1;
	   }

	   return (maxx-minx+1)*(maxy-miny+1);

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
			int moves[]               = {15};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int moves[]               = {3,10};
			int expected__            = 44;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int moves[]               = {1,1,1,1};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int moves[]               = {9,5,11,10,11,4,10};
			int expected__            = 132;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int moves[]               = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15};
			int expected__            = 420;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int moves[]               = {8,6,6,1};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int moves[]               = {8,6,6};
			int expected__            = 63;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			int moves[]               = {5,4,5,3,3};
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			int moves[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int moves[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int moves[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
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
