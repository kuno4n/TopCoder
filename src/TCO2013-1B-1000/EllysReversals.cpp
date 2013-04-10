
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
#include <queue>
//#include "cout.h"

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

vector <string> ws1[51];
vector < vector <string> > ws2[51];
bool remain[51][51];


vector<string> chstr(string s){
	vector<string> res;
	for(int i=0; i<SZ(s); i+=2){
		if(i == SZ(s)-1){
			res.PB(s.substr(i, 1));
		}
		else{
			string ss = s.substr(i, 2);
			sort(ALL(ss));
			res.PB(ss);
		}
	}
	sort(ALL(res));
	return res;
}

class EllysReversals {
public:
   int getMin( vector <string> words ) {
	   REP(i, 51) ws1[i].clear();
	   REP(i, 51) ws2[i].clear();
	   REP(i, 51) REP(j, 51) remain[i][j] = false;
	   REP(i, SZ(words)) ws1[SZ(words[i])].PB(words[i]);
	   REP(i, 51) REP(j, SZ(ws1[i])) remain[i][j] = true;
	   REP(i, 51) REP(j, SZ(ws1[i])) ws2[i].PB(chstr(ws1[i][j]));

	   REP(i, 51) REP(j, SZ(ws2[i])-1){
		   for(int k = j+1; k < SZ(ws2[i]); k++){
				if(!remain[i][j]) continue;
				if(!remain[i][k]) continue;
				if(ws2[i][j] == ws2[i][k]){
					remain[i][j] = false;
					remain[i][k] = false;
				}
		   }
	   }
	   int res = 0;
	   REP(i, 51) REP(j, 51) if(remain[i][j]) res++;
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
			string words[]            = {"esprit", "god", "redotopc", "odcpoter", "dog"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string words[]            = {"no", "zaphod", "just", "very", "improbable"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string words[]            = {"rats", "live", "stressed", "to", "act", "as", "star", "desserts", "of", "evil", "cat", "sa", "fo", "ot"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string words[]            = {"topcoder", "redocpot", "doretopc", "cpotdoer", "harlemshake"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string words[]            = {"iprlzgukfggzg", "bmhxvjbrtkbxy", "khapjiabbny", "nqlwgmcyvdikt",
 "nxromtvtpug", "leealcapovm", "ushnxwjczczbmd", "bwhykzupcux",
 "xrlboyuwlnsp", "bbjoketeheezfs", "dxfztrldomjqkv", "dkbktqdtgfujcut",
 "zfybzyuxgpnt", "ffmsldrdftode", "vopuufksxd", "pqhbsiujwda",
 "yhwbkzupcux", "hkbabnapjiy", "zqsqefrrzehtxn", "yovinyguyudmv"};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string words[]            = {"topcoder", "redocpot", "doretopc", "cpotdoer", "topcoder"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string words[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string words[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string words[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
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
// Elly has a list of several distinct strings given in the vector <string> words. She can apply the following operation as many times as she wants (including zero times):

Choose one of the words and call it S.
Choose an even number k between 2 and |S|, inclusive, where |S| is the length of S (thus, chose a prefix with even length).
Reverse the order of the first k characters of S (thus, reverse the chosen prefix without the rest of the word).

For example, if she has the word "topcoder", she can reverse its first 2, 4, 6, or all 8 characters. If she chooses to reverse its first 4 characters, the change will be: "topcoder" -> "cpotoder". If at a later time she decides to chose the same string and reverse all of its characters (which is also a valid prefix with even length), she would get "cpotoder"->"redotopc".

After performing some operations two strings might become equal. If that happens, Elly crosses them out and continues playing her game with the remaining strings only, i.e. they "disappear" from the list. The girl wonders what is the minimal number of strings she can end up with.

For example, suppose she has the strings {"esprit", "god", "redotopc", "odcpoter", "dog"}. The word "redotopc" can be converted to "topcoder" by first reversing all 8 characters and then reversing the first 4. The word "odcpoter" can also be converted to "topcoder" by performing "odcpoter" -> "docpoter" -> "topcoder". At that point the words become equal and disappear, leaving Elly only with {"esprit", "god", "dog"}. This is where she gets stuck: The words "god" and "dog" cannot become equal, because she can only reverse prefixes with even length. Thus, the minimal number of words she can get is 3.

Given her initial strings in vector <string> words, return an int indicating the minimal number of strings she can be left with.

DEFINITION
Class:EllysReversals
Method:getMin
Parameters:vector <string>
Returns:int
Method signature:int getMin(vector <string> words)


CONSTRAINTS
-words will contain between 1 and 50 elements, inclusive.
-Each element of words will contain between 1 and 50 characters, inclusive.
-Each element of words will consist only of lowercase letters of the English alphabet ('a'-'z').
-All elements of words will be distinct.


EXAMPLES

0)
{"esprit", "god", "redotopc", "odcpoter", "dog"}

Returns: 3

The example from the problem statement.

1)
{"no", "zaphod", "just", "very", "improbable"}

Returns: 5

It is possible that she cannot get rid of any of the words.

2)
{"rats", "live", "stressed", "to", "act", "as", "star", "desserts", "of", "evil", "cat", "sa", "fo", "ot"}

Returns: 0

It is possible that she ends up with zero words.

3)
{"topcoder", "redocpot", "doretopc", "cpotdoer", "harlemshake"}

Returns: 1

Sometimes it is possible to match different words when using a different sequence of operations.

4)
{"iprlzgukfggzg", "bmhxvjbrtkbxy", "khapjiabbny", "nqlwgmcyvdikt",
 "nxromtvtpug", "leealcapovm", "ushnxwjczczbmd", "bwhykzupcux",
 "xrlboyuwlnsp", "bbjoketeheezfs", "dxfztrldomjqkv", "dkbktqdtgfujcut",
 "zfybzyuxgpnt", "ffmsldrdftode", "vopuufksxd", "pqhbsiujwda",
 "yhwbkzupcux", "hkbabnapjiy", "zqsqefrrzehtxn", "yovinyguyudmv"}

Returns: 16



*/

// END CUT HERE
