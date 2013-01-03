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
#define OUT(A) cout << #A << " = " << (A) << endl

map <char, int> key;
map <vector<int>, vector<string> > dic;

VI strtokey(string str){
    VI res;
    REP(i, SZ(str)) res.push_back(key[str[i]]);
    return res;
}

class T9 {
	public:
	string message(vector <string> part, vector <string> dict, vector <string> keystr) {
        key.clear();
        REP(i, SZ(part)) REP(j, SZ(part[i])) key[part[i][j]] = i+1;

        dic.clear();
        sort(ALL(dict));
        REP(i, SZ(dict)) dic[strtokey(dict[i])].push_back(dict[i]);
        
        string ks = "";
        REP(i, SZ(keystr)){
            REP(j, SZ(keystr[i])){
                if(keystr[i][j] == '*') ks += "#####";
                else ks += keystr[i][j];
            }
        }
        string res = "";
        for(int ptr = 0; ptr < SZ(ks); ptr++){
            if(ks[ptr] == '0'){
                res += ' ';
                continue;
            }
            
            VI k;
            ptr--;
            do{
                ptr++;
                k.push_back(ks[ptr]-'0');
            }while(ptr+1<SZ(ks) && ks[ptr+1]!='0' && ks[ptr+1]!='#') ;
            
            int cnt = 0;
            while(ptr+1<SZ(ks) && ks[ptr+1]=='#'){
                cnt++;
                ptr++;
            }
            res += dic[k][cnt%(SZ(dic[k]))];
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
			string part[]             = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
			string dict[]             = {"bad"};
			string keystr[]           = {"2230223"};
			string expected__         = "bad bad";

			clock_t start__           = clock();
			string received__         = T9().message(vector <string>(part, part + (sizeof part / sizeof part[0])), vector <string>(dict, dict + (sizeof dict / sizeof dict[0])), vector <string>(keystr, keystr + (sizeof keystr / sizeof keystr[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string part[]             = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
			string dict[]             = {"the", "tie"};
			string keystr[]           = {"0843#000843#000"};
			string expected__         = " tie   tie   ";

			clock_t start__           = clock();
			string received__         = T9().message(vector <string>(part, part + (sizeof part / sizeof part[0])), vector <string>(dict, dict + (sizeof dict / sizeof dict[0])), vector <string>(keystr, keystr + (sizeof keystr / sizeof keystr[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string part[]             = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
			string dict[]             = {"bad", "ace", "aad", "aae", "aaf", "acf", "acd", "the", "tie"};
			string keystr[]           = {"223#02", "23*#00843#0"};
			string expected__         = "aae bad  tie ";

			clock_t start__           = clock();
			string received__         = T9().message(vector <string>(part, part + (sizeof part / sizeof part[0])), vector <string>(dict, dict + (sizeof dict / sizeof dict[0])), vector <string>(keystr, keystr + (sizeof keystr / sizeof keystr[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string part[]             = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
			string dict[]             = {"the", "tie", "bad", "ace", "aad", "aae", "aaf", "acf", "acd"};
			string keystr[]           = {"84300223#02", "23#*"};
			string expected__         = "the  aae bad";

			clock_t start__           = clock();
			string received__         = T9().message(vector <string>(part, part + (sizeof part / sizeof part[0])), vector <string>(dict, dict + (sizeof dict / sizeof dict[0])), vector <string>(keystr, keystr + (sizeof keystr / sizeof keystr[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string part[]             = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
			string dict[]             = {"bad", "ace", "aad", "aae", "tie", "aaf", "acf", "acd", "the"};
			string keystr[]           = {"223#02", "23######"};
			string expected__         = "aae bad";

			clock_t start__           = clock();
			string received__         = T9().message(vector <string>(part, part + (sizeof part / sizeof part[0])), vector <string>(dict, dict + (sizeof dict / sizeof dict[0])), vector <string>(keystr, keystr + (sizeof keystr / sizeof keystr[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string part[]             = {"", "rq", "lde", "yoauz", "cbfgn", "tjkpx", "wvs", "ih", "m"};
			string dict[]             = {"xktgmfmoqlmivm", 
 "hmthr", 
 "tpjgmnmaremiwm", 
 "tpjcmnmyrlmhvm", 
 "xkpnmgmzqdmhsm", 
 "wqopvvmiig", 
 "melbcbqeeg", 
 "jkxnmbmardmhwm", 
 "kpxnmcmyqlmism", 
 "wrztvsmhhf", 
 "srztssmiic", 
 "pxtgmfmyrdmhwm", 
 "vqoxswmiin", 
 "wryksvmihb", 
 "ptjfmbmoremhvm"};
			string keystr[]           = {"00", 
 "7246779885##00000089682000007246779885##0000724677", 
 "9885#000089682000093355523350066659594239879###000"};
			string expected__         = "  wqopvvmiig      hmthr     wqopvvmiig    vqoxswmiin    hmthr    melbcbqeeg  pxtgmfmyrdmhwm   ";

			clock_t start__           = clock();
			string received__         = T9().message(vector <string>(part, part + (sizeof part / sizeof part[0])), vector <string>(dict, dict + (sizeof dict / sizeof dict[0])), vector <string>(keystr, keystr + (sizeof keystr / sizeof keystr[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string part[]             = ;
			string dict[]             = ;
			string keystr[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = T9().message(vector <string>(part, part + (sizeof part / sizeof part[0])), vector <string>(dict, dict + (sizeof dict / sizeof dict[0])), vector <string>(keystr, keystr + (sizeof keystr / sizeof keystr[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string part[]             = ;
			string dict[]             = ;
			string keystr[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = T9().message(vector <string>(part, part + (sizeof part / sizeof part[0])), vector <string>(dict, dict + (sizeof dict / sizeof dict[0])), vector <string>(keystr, keystr + (sizeof keystr / sizeof keystr[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string part[]             = ;
			string dict[]             = ;
			string keystr[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = T9().message(vector <string>(part, part + (sizeof part / sizeof part[0])), vector <string>(dict, dict + (sizeof dict / sizeof dict[0])), vector <string>(keystr, keystr + (sizeof keystr / sizeof keystr[0])));
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
// The old fashioned king does not know how to SMS and thus he is having problems sending messages to the queen. In particular, he is having a problem with a feature called T9.

In T9, the set of alphabets are partitioned into 9 sets, where the i-th set of characters (1-based) denotes the possible characters that may be typed by pressing digit i. For this problem, we will use strings to denote a set of characters. On a standard modern cell phone, the following partition is used

	{"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}

For the partition above, pressing 2 may output 'a', 'b' or 'c'; pressing 3 may output 'd', 'e' or 'f'; and so on. Pressing 223 can give you various outputs of the form "(abc)(abc)(def)" where (XYZ) means that the letter can be either X or Y or Z. For example, a few possible outputs are "ace", "bad" and "bbe".

However, not all possible outputs are dictionary words (like "bbe" is not a dictionary word), and thus these outputs do not make sense. The cell phone considers only those outputs which correspond to dictionary words. Suppose that there are only two possible dictionary words from "(abc)(abc)(def)" - namely, "ace" and "bad". Then, the keystrokes 223 gives the output "ace", and the keystrokes 223# gives the output "bad". In general if a certain number (like 223) corresponds to multiple dictionary words, then the number followed by n hashes ('#') is used to type the n-th dictionary word (0-based) from the lexographically sorted list of dictionary words corresponding to the number. Sometimes the number of hashes typed can be quite large. Hence, we have a special character star ('*') which is equivalent to 5 contiguous hashes. The digit 0 is used to type a space.

The king needs to type a text using T9. The text is a string that consists of lowercase letters ('a'-'z') and space characters (' '). A word is a maximal contiguous substring of the text that contains only lowercase letters ('a'-'z'). The only way the king can type a word is by first pressing a non-empty sequence of digits ('1'-'9') followed by a (possibly emtpy) sequence of characters '#' and/or '*'.

You will be given a vector <string> part whose i-th element (1-based) is the set of alphabets which correspond to the digit i. You will also be given a vector <string> dict that represents a set of all dictionary words, where each element is a single word. Finally, you will be given a vector <string> keystr. Concatenate the elements of keystr in the same order as they are given to obtain a string. This string represents the keystrokes pressed by the king. To help the king, return the text that will result when the given keystrokes are pressed. You may assume that the given keystrokes are valid, i.e. each maximal contiguous substring that doesn't contain '0' characters starts from non-empty sequence of digits ('1'-'9') and then is optionally continued with a sequence of '#' and/or '*' characters. You may also assume that each such substring corresponds to a word from dict.

DEFINITION
Class:T9
Method:message
Parameters:vector <string>, vector <string>, vector <string>
Returns:string
Method signature:string message(vector <string> part, vector <string> dict, vector <string> keystr)


NOTES
-A substring of a string is called maximal with respect to some property if it can't be extended to the left or to the right while maintaining the property.
-A string A is lexicographically less than another string B of the same length if there exists a position i such that each character of A before the i-th position is equal to the character at the corresponding position in B, and A[i] is less than B[i].
-For the purpose of this problem, a partition of alphabets into 9 sets may contain any number of empty sets.


CONSTRAINTS
-part will represent a valid partition of the 26 english alphabets into 9 sets, i.e. it will consist of exactly 9 elements and every letter from 'a' to 'z' will appear exactly once in exactly one of the elements of part.
-dict will contain between 1 and 50 elements, inclusive.
-Each element of dict will contain between 1 and 50 characters, inclusive.
-Each character in dict will be a lowercase letter 'a'-'z'.
-All elements of dict will be distinct.
-keystr will contain between 1 and 50 elements, inclusive.
-Each element of keystr will contain between 1 and 50 characters, inclusive.
-Each character in keystr will be one of '0'-'9', '#', '*'.
-The length of the resulting text will be between 1 and 1000, inclusive.
-The string obtained by concatenating the elements of keystr will represent a valid sequence of keystrokes (as explained in the statement).


EXAMPLES

0)
{"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
{"bad"}
{"2230223"}

Returns: "bad bad"

1)
{"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
{"the", "tie"}
{"0843#000843#000"}

Returns: " tie   tie   "

There may be leading, trailing and contiguous spaces.

2)
{"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
{"bad", "ace", "aad", "aae", "aaf", "acf", "acd", "the", "tie"}
{"223#02", "23*#00843#0"}

Returns: "aae bad  tie "

Don't forget to concatenate the elements of keystr. Also, "*" is equivalent to "#####".

3)
{"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
{"the", "tie", "bad", "ace", "aad", "aae", "aaf", "acf", "acd"}
{"84300223#02", "23#*"}

Returns: "the  aae bad"

'*' may also appear after the '#'. All that matters is, it is equivalent to "#####".

4)
{"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
{"bad", "ace", "aad", "aae", "tie", "aaf", "acf", "acd", "the"}
{"223#02", "23######"}

Returns: "aae bad"

The king may use '*'. But it is not necessary that he uses it everytime he is allowed to use it. 

5)
{"", "rq", "lde", "yoauz", "cbfgn", "tjkpx", "wvs", "ih", "m"}
{"xktgmfmoqlmivm", 
 "hmthr", 
 "tpjgmnmaremiwm", 
 "tpjcmnmyrlmhvm", 
 "xkpnmgmzqdmhsm", 
 "wqopvvmiig", 
 "melbcbqeeg", 
 "jkxnmbmardmhwm", 
 "kpxnmcmyqlmism", 
 "wrztvsmhhf", 
 "srztssmiic", 
 "pxtgmfmyrdmhwm", 
 "vqoxswmiin", 
 "wryksvmihb", 
 "ptjfmbmoremhvm"}
{"00", 
 "7246779885##00000089682000007246779885##0000724677", 
 "9885#000089682000093355523350066659594239879###000"}

Returns: "  wqopvvmiig      hmthr     wqopvvmiig    vqoxswmiin    hmthr    melbcbqeeg  pxtgmfmyrdmhwm   "



*/

// END CUT HERE
