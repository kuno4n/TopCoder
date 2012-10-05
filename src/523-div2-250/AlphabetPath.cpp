
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
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
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< A << endl

class AlphabetPath {
public:
   string doesItExist( vector <string> l ) {
	   int dx=0;
	   int dy=0;
	   int mx = SZ(l[0]);
	   int my = SZ(l);

	   REP(i, my) l[i] = "." + l[i] + ".";
	   mx = mx + 2;

	   string tmp = l[0];
	   REP(i, mx) tmp[i] = '.';
	   l.PB(tmp);
	   l.insert(l.begin(), tmp);
	   my = my + 2;


	   REP(i, my){
		   REP(j, mx){
			   if(l[i][j] == 'A'){
				   dx = j;
				   dy = i;
			   }
		   }
	   }
	   
	   char c = 'A';
	   while(1){
		   if(c == 'Z') return "YES";
		   c++;

		   if(l[dy-1][dx] == c){dy = dy -1; continue;}
		   if(l[dy+1][dx] == c){dy = dy +1; continue;}
		   if(l[dy][dx-1] == c){dx = dx -1; continue;}
		   if(l[dy][dx+1] == c){dx = dx +1; continue;}

		   return "NO";
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
			string letterMaze[]       = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string letterMaze[]       = {"ADEHI..Z",
 "BCFGJK.Y",
 ".PONML.X",
 ".QRSTUVW"}
;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string letterMaze[]       = {"ACBDEFGHIJKLMNOPQRSTUVWXYZ"};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string letterMaze[]       = {"ABC.......",
 "...DEFGHIJ",
 "TSRQPONMLK",
 "UVWXYZ...."};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string letterMaze[]       = {"..............",
 "..............",
 "..............",
 "...DEFGHIJK...",
 "...C......L...",
 "...B......M...",
 "...A......N...",
 "..........O...",
 "..ZY..TSRQP...",
 "...XWVU.......",
 ".............."};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string letterMaze[]       = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string letterMaze[]       = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string letterMaze[]       = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
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

/*
// PROBLEM STATEMENT
// You are given a 2-dimensional matrix of characters represented by the vector <string> letterMaze. The i-th character of the j-th element of letterMaze  represents the character at row i and column j. Each of the 26 letters from 'A' to 'Z' appears exactly once in letterMaze, the remaining characters are periods ('.').

An alphabet path is a sequence of 26 elements of the matrix such that:

The first element contains the letter 'A'.
The first element and the second element are (horizontally or vertically) adjacent.
The second element contains the letter 'B'.
The second element and the third element are (horizontally or vertically) adjacent.
...
The 25-th element and the 26-th element are (horizontally or vertically) adjacent.
The last, 26-th element contains the letter 'Z'.

Given letterMaze return string "YES" if the alphabet path exists in the matrix and "NO" otherwise.

DEFINITION
Class:AlphabetPath
Method:doesItExist
Parameters:vector <string>
Returns:string
Method signature:string doesItExist(vector <string> letterMaze)


NOTES
-Formally, elements (x1,y1) and (x2,y2) are horizontally or vertically adjacent if and only if abs(x1 - x2) + abs(y1 - y2) = 1. 


CONSTRAINTS
-letterMaze will contain between 1 and 50 elements, inclusive.
-Each element of letterMaze will contain between 1 and 50 characters, inclusive.
-All the elements of letterMaze will contain the same number of characters.
-Each element of letterMaze will only contain uppercase letters ('A'-'Z') and periods ('.').
-Each uppercase letter from 'A' to 'Z' will appear exactly once in letterMaze.


EXAMPLES

0)
{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}

Returns: "YES"

Simply go from left to right.

1)
{"ADEHI..Z",
 "BCFGJK.Y",
 ".PONML.X",
 ".QRSTUVW"}


Returns: "YES"



2)
{"ACBDEFGHIJKLMNOPQRSTUVWXYZ"}

Returns: "NO"



3)
{"ABC.......",
 "...DEFGHIJ",
 "TSRQPONMLK",
 "UVWXYZ...."}

Returns: "NO"

The cells marked with C and D are not adjacent, it is impossible to make an alphabet path in this case.

4)
{"..............",
 "..............",
 "..............",
 "...DEFGHIJK...",
 "...C......L...",
 "...B......M...",
 "...A......N...",
 "..........O...",
 "..ZY..TSRQP...",
 "...XWVU.......",
 ".............."}

Returns: "YES"



*/

// END CUT HERE
