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

int No, Nk;

class TomekPhone {
	public:
	int minKeystrokes(vector <int> occurences, vector <int> keySizes) {
		No = SZ(occurences);
        Nk = SZ(keySizes);
        
        int cnum = 0;
        REP(i, Nk) cnum += keySizes[i];
        if(cnum < No) return -1;
        
        int res = 0;
        sort(ALL(occurences), greater<int>());
        
        int nowst = 0;
        int canuse = 0;
        REP(i, No){
            if(canuse == 0){
                nowst++;
                REP(j, Nk){
                    if(keySizes[j] >= nowst) canuse++;
                }
            }
            res += occurences[i]*nowst;
            canuse--;
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
			int occurences[]          = {7,3,4,1};
			int keySizes[]            = {2,2};
			int expected__            = 19;

			clock_t start__           = clock();
			int received__            = TomekPhone().minKeystrokes(vector <int>(occurences, occurences + (sizeof occurences / sizeof occurences[0])), vector <int>(keySizes, keySizes + (sizeof keySizes / sizeof keySizes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int occurences[]          = {13,7,4,20};
			int keySizes[]            = {2,1};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = TomekPhone().minKeystrokes(vector <int>(occurences, occurences + (sizeof occurences / sizeof occurences[0])), vector <int>(keySizes, keySizes + (sizeof keySizes / sizeof keySizes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int occurences[]          = {11,23,4,50,1000,7,18};
			int keySizes[]            = {3,1,4};
			int expected__            = 1164;

			clock_t start__           = clock();
			int received__            = TomekPhone().minKeystrokes(vector <int>(occurences, occurences + (sizeof occurences / sizeof occurences[0])), vector <int>(keySizes, keySizes + (sizeof keySizes / sizeof keySizes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int occurences[]          = {100,1000,1,10};
			int keySizes[]            = {50};
			int expected__            = 1234;

			clock_t start__           = clock();
			int received__            = TomekPhone().minKeystrokes(vector <int>(occurences, occurences + (sizeof occurences / sizeof occurences[0])), vector <int>(keySizes, keySizes + (sizeof keySizes / sizeof keySizes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int occurences[]          = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
			int keySizes[]            = {10,10,10,10,9};
			int expected__            = 3353;

			clock_t start__           = clock();
			int received__            = TomekPhone().minKeystrokes(vector <int>(occurences, occurences + (sizeof occurences / sizeof occurences[0])), vector <int>(keySizes, keySizes + (sizeof keySizes / sizeof keySizes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int occurences[]          = ;
			int keySizes[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TomekPhone().minKeystrokes(vector <int>(occurences, occurences + (sizeof occurences / sizeof occurences[0])), vector <int>(keySizes, keySizes + (sizeof keySizes / sizeof keySizes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int occurences[]          = ;
			int keySizes[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TomekPhone().minKeystrokes(vector <int>(occurences, occurences + (sizeof occurences / sizeof occurences[0])), vector <int>(keySizes, keySizes + (sizeof keySizes / sizeof keySizes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int occurences[]          = ;
			int keySizes[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TomekPhone().minKeystrokes(vector <int>(occurences, occurences + (sizeof occurences / sizeof occurences[0])), vector <int>(keySizes, keySizes + (sizeof keySizes / sizeof keySizes[0])));
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
// 
Tomek thinks that smartphones are overrated.
He plans to release a new cellphone with an old-school keyboard, which may require you to tap a key multiple times to type a single letter.
For example, if the keyboard has two keys, one with the letters "adef" and the other one with the letters "zyx", then typing 'a' requires one keystroke, typing 'f' requires four keystrokes, typing 'y' requires two keystrokes, and so on.



Tomek has already designed the keyboard's layout.
That is, he already knows the number of keys on the keyboard, and for each key he knows the maximum number of letters it may hold.
He now wants to create a specific keyboard for a language that uses N different letters.
He has a large body of text in this language, and he already analyzed it to find the frequencies of all N letters of its alphabet.



You are given a vector <int> frequencies with N elements.
Each element of frequencies is the number of times one of the letters in Tomek's alphabet appears in the text he has.
Each element of frequencies will be strictly positive.
(I.e., each of the N letters occurs at least once in Tomek's text.)



You are also given a vector <int> keySize.
The number of elements of keySize is the number of keys on Tomek's keyboard.
Each element of keySize gives the maximal number of letters on one of the keys.



Find an assignment of letters to keys that minimizes the number of keystrokes needed to type Tomek's entire text.
Return that minimum number of keystrokes.
If there is not enough room on the keys and some letters of the alphabet won't fit, return -1 instead.


DEFINITION
Class:TomekPhone
Method:minKeystrokes
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minKeystrokes(vector <int> occurences, vector <int> keySizes)


CONSTRAINTS
-frequencies will contain between 1 and 50 elements, inclusive.
-Each element of frequencies will be between 1 and 1,000, inclusive.
-keySizes will contain between 1 and 50 elements, inclusive.
-Each element of keySizes will be between 1 and 50, inclusive.


EXAMPLES

0)
{7,3,4,1}
{2,2}

Returns: 19

Tomek's language has four letters.
Let us call them A, B, C, and D.
Tomek's text contains seven As, three Bs, four Cs, and one D.
The keyboard has two keys, each of them may contain at most two letters.
One optimal solution is to use the keys "AD" and "CB".
We can then type each A and each C using a single keystroke, and we need two keystrokes for each B and each D.
Therefore, the total number of keystrokes when typing the entire text will be 7*1 + 3*2 + 4*1 + 1*2 = 19.


1)
{13,7,4,20}
{2,1}

Returns: -1

There is not enough space on the keys to fit all four letters.

2)
{11,23,4,50,1000,7,18}
{3,1,4}

Returns: 1164



3)
{100,1000,1,10}
{50}

Returns: 1234



4)
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50}
{10,10,10,10,10,10,10,10}

Returns: 3353



*/

// END CUT HERE
