#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <sstream>
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

int month;
int snum;

class StockHistory {
	public:
	int maximumEarnings(int initialInvestment, int monthlyContribution, vector <string> stockPrices) {
		
        month = SZ(stockPrices);
        vector <vector <double> > sP;
        REP(i, month){
            vector <double> tmp;
            stringstream ss(stockPrices[i]);
            double tmp2;
            while(ss >> tmp2) tmp.push_back(tmp2);
            sP.push_back(tmp);
        }
        snum = SZ(sP[0]);
        
        REP(i, month-1) REP(j, snum) sP[i][j] = sP[month-1][j] / sP[i][j];
        for(int i=month-3; i>=0; i--) REP(j, snum) sP[i][j] = max(sP[i][j], sP[i+1][j]);
        
        double totalsal = 0.0;
        double totalinv = 0.0;
        REP(i, month-1){
            double maxper = 0.0;
            REP(j, snum) maxper = max(maxper, sP[i][j]);
            if(i==0){
                if(maxper < 1.0) totalsal += initialInvestment;
                else totalsal += initialInvestment*maxper;
                totalinv += initialInvestment;
            }
            else{
                if(maxper < 1.0) totalsal += monthlyContribution;
                else totalsal += monthlyContribution*maxper;
                totalinv += monthlyContribution;
            }
        }        
//        REP(i, month){
//            REP(j, snum){
//                cout << sP[i][j] << " ";
//            }
//            cout << endl;
//        }
        
        return (int)(round)(totalsal-totalinv);
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
			int initialInvestment     = 1000;
			int monthlyContribution   = 0;
			string stockPrices[]      = {"10 20 30", "15 24 32"};
			int expected__            = 500;

			clock_t start__           = clock();
			int received__            = StockHistory().maximumEarnings(initialInvestment, monthlyContribution, vector <string>(stockPrices, stockPrices + (sizeof stockPrices / sizeof stockPrices[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int initialInvestment     = 1000;
			int monthlyContribution   = 0;
			string stockPrices[]      = {"10", "9"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = StockHistory().maximumEarnings(initialInvestment, monthlyContribution, vector <string>(stockPrices, stockPrices + (sizeof stockPrices / sizeof stockPrices[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int initialInvestment     = 100;
			int monthlyContribution   = 20;
			string stockPrices[]      = {"40 50 60",
 "37 48 55",
 "100 48 50",
 "105 48 47",
 "110 50 52",
 "110 50 52",
 "110 51 54",
 "109 49 53"};
			int expected__            = 239;

			clock_t start__           = clock();
			int received__            = StockHistory().maximumEarnings(initialInvestment, monthlyContribution, vector <string>(stockPrices, stockPrices + (sizeof stockPrices / sizeof stockPrices[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int initialInvestment     = ;
			int monthlyContribution   = ;
			string stockPrices[]      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = StockHistory().maximumEarnings(initialInvestment, monthlyContribution, vector <string>(stockPrices, stockPrices + (sizeof stockPrices / sizeof stockPrices[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int initialInvestment     = ;
			int monthlyContribution   = ;
			string stockPrices[]      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = StockHistory().maximumEarnings(initialInvestment, monthlyContribution, vector <string>(stockPrices, stockPrices + (sizeof stockPrices / sizeof stockPrices[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int initialInvestment     = ;
			int monthlyContribution   = ;
			string stockPrices[]      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = StockHistory().maximumEarnings(initialInvestment, monthlyContribution, vector <string>(stockPrices, stockPrices + (sizeof stockPrices / sizeof stockPrices[0])));
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
// You have recently been given a one-time bonus at work, along with a pay raise.  In the interest of putting your new found money to good use, you have decided to invest in the stock market.  To learn about recent market history, you have acquired historical data on several stocks you might be interested in purchasing.

For experiment's sake, you want to evaluate the potential performance of your selected stocks.  What you are wondering is how much money you could have made if, at the beginning, you had an initial investment of int initialInvestment dollars, and each month thereafter you had an additional int monthlyContribution dollars.  Assume that you may buy any number of shares of stocks at the beginning of each month (including fractional numbers of shares), and that at the end of the timeframe (at the beginning of the last month) represented in the data, you sell all of your holdings.  You may not sell stocks in the intermediate period.  (See examples for clarification.)

You are given a vector <string>, stockPrices, in which each element lists the prices
of each stock at the beginning of a month.  Each element of stockPrices is in the form "stock0 stock1 ..." (quotes added for clarity), where each stocki is a positive integer with no leading zeroes.  The first element of stockPrices gives the initial prices, the second element gives the prices at the beginning of the first month after you start investing, and so on.

You are to return an int indicating the maximum earnings (profit) you could make by the end of the timeframe.  You should round your result to the nearest integer.






DEFINITION
Class:StockHistory
Method:maximumEarnings
Parameters:int, int, vector <string>
Returns:int
Method signature:int maximumEarnings(int initialInvestment, int monthlyContribution, vector <string> stockPrices)


CONSTRAINTS
-initialInvestment will be between 0 and 10000, inclusive.
-monthlyContributon will be between 0 and 1000, inclusive.
-stockPrices will contain between 2 and 50 elements, inclusive.
-Each element of stockPrices will contain between 1 and 50 characters, inclusive.
-Each element of stockPrices will be formatted as a space delimited list of positive integers.
-Each integer represented in an element of stockPrices will be between 1 and 999, inclusive.
-Each element of stockPrices will represent the same number of integers.
-The result prior to rounding will not be within 0.01 of x.5, where x is an integer.


EXAMPLES

0)
1000
0
{"10 20 30", "15 24 32"}

Returns: 500

Clearly the first stock is a bigger gain than either of the others.  We go all in on it.

1)
1000
0
{"10", "9"}

Returns: 0

We're best off not buying any shares, rather than buying and losing money.

2)
100
20
{"40 50 60",
 "37 48 55",
 "100 48 50",
 "105 48 47",
 "110 50 52",
 "110 50 52",
 "110 51 54",
 "109 49 53"}

Returns: 239

Remember that we can't sell any shares until the beginning of the last month.  So, let's work backwards, and figure out what the best way to invest our money is.  During the second to last month (month 6), the stock prices are 110, 51 and 54, all higher than the prices that we would sell at, so we don't buy anything during that month.
At the beginning of month 5, the price of the third stock is a little lower than its final price, so we invest our 20 in that, and make a meager 20*((53/52)-1).  The prices are the same at the beginning of month 4, so we do the same thing.
At the beginning of month 3, the prices have changed, but it is still best to invest in the third stock.  Note that the profit we make investing in the third stock during month 3 is larger than it is if we save our money and invest later.  Hence, we make a profit of 20*((53/47)-1) on our 20 from month 3.
At the beginning of month 2, it is best to save all of our money, and then invest in the third stock during the next month when the price is lower.  At the beginning of month 1, you should clearly invest in the first stock.  You should save all of your money from the initial investment until the price of the first stock goes down a little.  So, to summarize:

month | action
------+-------
    0 | save
    1 | buy stock 0 (120/37 shares)
    2 | save
    3 | buy stock 2 (40/47 shares)
    4 | buy stock 2 (20/52 shares)
    5 | buy stock 2 (20/52 shares)
    6 | save
    7 | sell (3.243 shares of stock 0, 1.620 shares of stock 2)
Total sales price : 439.389
Total investment  : 200
Profit            : 239.389


Notice that you always either invest all of your money at the beginning of a month, or else save all of it.  When you know the future prices, there is no reason to invest only some of your money.

*/

// END CUT HERE
