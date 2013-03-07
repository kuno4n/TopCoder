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
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
//#include "cout.h"

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset((x), (a), (int)sizeof(x))
#define VI vector < int >
#define LL long long 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = " << A << endl



vector <string> s1, s2;
int n, n1, n2, N;


long long _Pow(long long x, long long y){
    long long r=1, a=x;
    while(y > 0){
        if((y&1) == 1) r = r*a;
        a = a*a;
        y /= 2;
    }
    return r;
}


string int2str(int a, int len){
    stringstream ss;
    ss << a;
    string res;
    ss >> res;
    while(SZ(res) < len) res = "0"+res;
    return res;
}

int match(string str1, string str2){
    int res = 0;
    int m = SZ(str1);
    REP(i, m) if(str1[i] == str2[i]) res++;
    return res;
}


class EllysBulls {
	public:
	string getNumber(vector <string> guesses, vector <int> bulls) {
		s1.clear();
        s2.clear();
        N = SZ(guesses);
        n = SZ(guesses[0]);
        n1 = n/2; n2 = n-n1;
        
        REP(i, N){
            s1.push_back(guesses[i].substr(0, n1));
            s2.push_back(guesses[i].substr(n1, n2));
        }
        
        map < VI , int > m; // < 残りのmatch数 , 前半の候補数>
        map < VI , string > m2; // < 残りのmatch数 , 前半の候補のひとつ>
        
        int k1 = _Pow(10, n1);
        REP(cand, k1){
            VI tmp = bulls;
            bool NG = false;
            string _cand = int2str(cand, n1);
            REP(i, N){
                REP(j, n1) if(s1[i][j] == _cand[j]) tmp[i]--;
            }
            if(NG) continue;
            m[tmp]++;
            m2[tmp] = _cand;
        }
        
        int rescnt = 0;
        string res = "";
        
        int k2 = _Pow(10, n2);
        REP(cand2, k2){
            VI tmp(N);
            string _cand2 = int2str(cand2, n2);
            REP(i, N){
                REP(j, n2) if(s2[i][j] == _cand2[j]) tmp[i]++;
            }
            int mat = m[tmp];
            rescnt += mat;
            if(mat == 1) res = m2[tmp] + _cand2;
        }
        
        if(rescnt == 0) return "Liar";
        else if(rescnt > 1) return "Ambiguity";
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
			string guesses[]          = {"1234", "4321", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"};
			int bulls[]               = {2, 1, 1, 0, 2, 0, 0, 0, 1, 0, 0};
			string expected__         = "1337";

			clock_t start__           = clock();
			string received__         = EllysBulls().getNumber(vector <string>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(bulls, bulls + (sizeof bulls / sizeof bulls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string guesses[]          = {"0000", "1111", "2222"};
			int bulls[]               = {2, 2, 2};
			string expected__         = "Liar";

			clock_t start__           = clock();
			string received__         = EllysBulls().getNumber(vector <string>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(bulls, bulls + (sizeof bulls / sizeof bulls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string guesses[]          = {"666666", "666677", "777777", "999999"};
			int bulls[]               = {2, 3, 1, 0};
			string expected__         = "Ambiguity";

			clock_t start__           = clock();
			string received__         = EllysBulls().getNumber(vector <string>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(bulls, bulls + (sizeof bulls / sizeof bulls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string guesses[]          = {"000", "987", "654", "321", "100", "010"};
			int bulls[]               = {2, 1, 0, 0, 1, 1};
			string expected__         = "007";

			clock_t start__           = clock();
			string received__         = EllysBulls().getNumber(vector <string>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(bulls, bulls + (sizeof bulls / sizeof bulls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string guesses[]          = {"28", "92", "70", "30", "67", "63", "06", "65",
 "11", "06", "88", "48", "09", "65", "48", "08"};
			int bulls[]               = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			string expected__         = "54";

			clock_t start__           = clock();
			string received__         = EllysBulls().getNumber(vector <string>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(bulls, bulls + (sizeof bulls / sizeof bulls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string guesses[]          = {"0294884", "1711527", "2362216", "7666148", "7295642",
 "4166623", "1166638", "2767693", "8650248", "2486509",
 "6138934", "4018642", "6236742", "2961643", "8407361",
 "2097376", "6575410", "6071777", "3569948", "2606380"};
			int bulls[]               = {1, 0, 1, 3, 4, 4, 3, 2, 1, 1, 0, 4, 4, 3, 0, 0, 0, 0, 2, 1};
			string expected__         = "4266642";

			clock_t start__           = clock();
			string received__         = EllysBulls().getNumber(vector <string>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(bulls, bulls + (sizeof bulls / sizeof bulls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string guesses[]          = ;
			int bulls[]               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EllysBulls().getNumber(vector <string>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(bulls, bulls + (sizeof bulls / sizeof bulls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string guesses[]          = ;
			int bulls[]               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EllysBulls().getNumber(vector <string>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(bulls, bulls + (sizeof bulls / sizeof bulls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string guesses[]          = ;
			int bulls[]               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EllysBulls().getNumber(vector <string>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(bulls, bulls + (sizeof bulls / sizeof bulls[0])));
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
// Elly and Kristina play a game called "Bulls". Initially each of them thinks of a non-negative integer with K digits, possibly containing leading zeroes. Then they take alternating turns, trying to guess the opponent's number. After each guess, the other person says how many positions were guessed correctly. For example if Kristina's number was "1337" and Elly's guess was "1738", Kristina should answer 2, since the digits at positions 0 and 2 (zero-based indices from the left) are correct. A guessed position is called "bull's hit", or simply a "bull", thus the name of the game.

Elly has already made several guesses. She wonders if the information she has is enough to uniquely determine Kristina's number.

You are given the guesses so far in a vector <string> guesses and the corresponding number of bull's hits in vector <int> bulls. If a unique number satisfies the given information, return it as a string. If there is more than one number that is valid according to the current guesses, return "Ambiguity" (quotes for clarity only). If no number satisfies the given information, then Kristina has lied and you should return "Liar" instead.

DEFINITION
Class:EllysBulls
Method:getNumber
Parameters:vector <string>, vector <int>
Returns:string
Method signature:string getNumber(vector <string> guesses, vector <int> bulls)


NOTES
-The game "Bulls" is a simplification of a game played in Bulgaria, called "Kravi & Bikove" ("Cows & Bulls").


CONSTRAINTS
-guesses will contain between 1 and 50 elements, inclusive.
-Each element of guesses will contain between 2 and 9 characters, inclusive.
-All elements of guesses will contain the same number of characters.
-All elements of guesses will consist only of digits ('0'-'9').
-bulls will contain the same number of elements as guesses.
-Each element of bulls will be between 0 and K-1, inclusive, where K is the length of each element of guesses.


EXAMPLES

0)
{"1234", "4321", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"}
{2, 1, 1, 0, 2, 0, 0, 0, 1, 0, 0}

Returns: "1337"

From {1234->2, 2222->0, 4444->0} it follows that the number is {1?3?}. The additional information {4321->1} tells us that either the digit at position 1 (0-indexed) is 3, or that the one at position 3 is 1. However, since {1111->1} and we already know that the 0-th digit is 1, then the third digit cannot be 1. Now we know that the number is {133?}. When trying {7777->1} we see that Kristina's number contains a 7, which cannot be anywhere else except in the last position. Thus, her number is 1337.


1)
{"0000", "1111", "2222"}
{2, 2, 2}

Returns: "Liar"

There are supposed to be two 0s, two 1s and two 2s in a four-digit number. Thus, Kristina is clearly a liar.


2)
{"666666", "666677", "777777", "999999"}
{2, 3, 1, 0}

Returns: "Ambiguity"

Some of the possible configurations that satisfy the current results are the numbers 636172, 336617, 660007. Thus, the answer is ambiguous.


3)
{"000", "987", "654", "321", "100", "010"}
{2, 1, 0, 0, 1, 1}

Returns: "007"

The guesses, as well as the answer, can have leading zeroes.

4)
{"28", "92", "70", "30", "67", "63", "06", "65",
 "11", "06", "88", "48", "09", "65", "48", "08"}
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

Returns: "54"



5)
{"0294884", "1711527", "2362216", "7666148", "7295642",
 "4166623", "1166638", "2767693", "8650248", "2486509",
 "6138934", "4018642", "6236742", "2961643", "8407361",
 "2097376", "6575410", "6071777", "3569948", "2606380"}
{1, 0, 1, 3, 4, 4, 3, 2, 1, 1, 0, 4, 4, 3, 0, 0, 0, 0, 2, 1}

Returns: "4266642"



*/

// END CUT HERE
