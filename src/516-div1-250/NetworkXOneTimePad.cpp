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

LL _2to10(string s){
    LL res = 0;
    REP (i, SZ(s)) {
        res <<= 1LL;
        if (s[i] == '1') res++;
    }
    return res;
}

class NetworkXOneTimePad {
    int n1, n2;
	public:
	int crack(vector <string> plaintexts, vector <string> ciphertexts) {
		n1 = SZ(plaintexts); n2 = SZ(ciphertexts);
        vector <LL> p, c; p.clear(); c.clear();
        REP(i, n1) p.push_back(_2to10(plaintexts[i]));
        REP(i, n2) c.push_back(_2to10(ciphertexts[i]));
        int res = 0;
        REP(i, n1){
            LL tmp = p[i]^c[0];
            bool ok = true;
            REP(k, n2){
                bool found = false;
                REP(l, n1) if((p[l]^tmp) == c[k]) found = true;
                if(!found) ok = false;
            }
            if(ok) res++;
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
			string plaintexts[]       = {"110", "001"};
			string ciphertexts[]      = {"101", "010"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = NetworkXOneTimePad().crack(vector <string>(plaintexts, plaintexts + (sizeof plaintexts / sizeof plaintexts[0])), vector <string>(ciphertexts, ciphertexts + (sizeof ciphertexts / sizeof ciphertexts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string plaintexts[]       = {"00", "01", "10", "11"};
			string ciphertexts[]      = {"00", "01", "10", "11"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = NetworkXOneTimePad().crack(vector <string>(plaintexts, plaintexts + (sizeof plaintexts / sizeof plaintexts[0])), vector <string>(ciphertexts, ciphertexts + (sizeof ciphertexts / sizeof ciphertexts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string plaintexts[]       = {"01", "10"};
			string ciphertexts[]      = {"00"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = NetworkXOneTimePad().crack(vector <string>(plaintexts, plaintexts + (sizeof plaintexts / sizeof plaintexts[0])), vector <string>(ciphertexts, ciphertexts + (sizeof ciphertexts / sizeof ciphertexts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string plaintexts[]       = {"000", "111", "010", "101", "110", "001"};
			string ciphertexts[]      = {"011", "100"};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = NetworkXOneTimePad().crack(vector <string>(plaintexts, plaintexts + (sizeof plaintexts / sizeof plaintexts[0])), vector <string>(ciphertexts, ciphertexts + (sizeof ciphertexts / sizeof ciphertexts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			string plaintexts[]       = 	{"01011010011101000011001", "00001001010101100010001", "00111001110000011001100", "00010100111110000001010", "01100001001011010101010", "01000101000111000101110", "11000111010011110101010", "10110000001011000001011", "01111010011100011001010", "00000011110001001110110", "11101101110001001111011", "01111101011100000011110", "10101010011011100001000", "01101001100101111110000", "11111000010100010111000", "01110101010111100100001", "01000010000110111100011", "11001011011000010011101", "11110111111011001100011", "00101000101010001010111", "00000101010000000101110", "01011001110010111110000", "10101010001010111100000", "11011100010000001001101", "10010010010000110000010", "00011010010000100101100", "10000110110100000101101", "01010110100011011101101", "11100010110110001010110", "01010110011001000010101", "00111010111110000110000", "01110101011010110000110", "11001011101001111100101", "11110100100110101001110", "10110110010011011010000", "10001100100000111000001", "00101100000111001110001", "00100010111010100110100", "00110010001011010000100", "11010011010000111000011", "00111110101111100100001", "01011010110100000001001", "01001100011111111011111", "11011011110010100101110", "00100101101010000110001", "11101000100111111101101", "01101110100000011101111", "11101100010100111010001", "00110011111110101101000"} ;
			string ciphertexts[]      = {"11100101010111010110111", "10010101010000110111000", "10110101101010110100111", "11001010110100110011111", "10100011111110011111110", "00000010010000000010100", "11101101011100110001000", "01100111111011111110101", "11000110011001110000011", "01001011110010010111000", "10110010111010010100010"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = NetworkXOneTimePad().crack(vector <string>(plaintexts, plaintexts + (sizeof plaintexts / sizeof plaintexts[0])), vector <string>(ciphertexts, ciphertexts + (sizeof ciphertexts / sizeof ciphertexts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 5: {
			string plaintexts[]       = ;
			string ciphertexts[]      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NetworkXOneTimePad().crack(vector <string>(plaintexts, plaintexts + (sizeof plaintexts / sizeof plaintexts[0])), vector <string>(ciphertexts, ciphertexts + (sizeof ciphertexts / sizeof ciphertexts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string plaintexts[]       = ;
			string ciphertexts[]      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NetworkXOneTimePad().crack(vector <string>(plaintexts, plaintexts + (sizeof plaintexts / sizeof plaintexts[0])), vector <string>(ciphertexts, ciphertexts + (sizeof ciphertexts / sizeof ciphertexts[0])));
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
// One-time pad (patented by Vernam in 1919) is one of the most widely known schemes to encrypt a binary string to achieve confidentiality. This scheme takes a binary string (a string consisting of only the digits 0 and 1) as input and outputs another binary string of the same length. The input is called the plaintext, and the output is called the ciphertext. The scheme uses a key which is another binary string of the same length as the input. The i-th bit of the ciphertext is defined as the XOR of the i-th bit of the plaintext and the key (see the notes for XOR definition). The ciphertext is sent to the receiving party.

In this problem, we will consider several messages, each of length N, encrypted using a single key of length N.


We would like to investigate how strong this cipher is. Suppose an adversary manages to find out the content of all the original messages (i.e., the plaintexts) and some of the encrypted messages (i.e., ciphertexts). These messages are given in the vector <string>s plaintexts and ciphertexts, respectively. Return the number of possible keys that are consistent with this data. The constraints will guarantee that there is at least one such key. A key is consistent if for all members of ciphertexts C, there exists a member of plaintexts P such that when P is encrypted using the specified key, it becomes C.

DEFINITION
Class:NetworkXOneTimePad
Method:crack
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int crack(vector <string> plaintexts, vector <string> ciphertexts)


NOTES
-XOR is a binary operation on bits defined as follows: 0 XOR 0 = 0, 0 XOR 1 = 1, 1 XOR 0 = 1, 1 XOR 1 = 0.


CONSTRAINTS
-plaintexts will contain between 1 and 50 elements, inclusive.
-Each element of plaintexts will contain between 1 and 50 characters, inclusive.
-All the elements of plaintexts will contain the same number of characters.
-All the characters in plaintexts will be either '0' (zero) or '1' (one).
-All the elements of plaintexts will be distinct.
-ciphertexts will contain between 1 and 50 elements, inclusive.
-All the elements of ciphertexts will contain the same number of characters as all the elements of plaintexts.
-All the characters in ciphertexts will be either '0' (zero) or '1' (one).
-All the elements of ciphertexts will be distinct.
-There will exist at least one key that is consistent with the given plaintexts and ciphertexts.


EXAMPLES

0)
{"110", "001"}
{"101", "010"}

Returns: 2

The two possible keys are "011" and "100".

1)
{"00", "01", "10", "11"}
{"00", "01", "10", "11"}

Returns: 4



2)
{"01", "10"}
{"00"}

Returns: 2



3)
{"000", "111", "010", "101", "110", "001"}
{"011", "100"}

Returns: 6



*/

// END CUT HERE
