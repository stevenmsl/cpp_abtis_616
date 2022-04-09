#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol616;

/*
Input:
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"
*/

tuple<string, vector<string>, string> testFixture1()
{
  return make_tuple("abcxyz123",
                    vector<string>{"abc", "123"},
                    "<b>abc</b>xyz<b>123</b>");
}

/*
Input:
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"
*/

tuple<string, vector<string>, string> testFixture2()
{
  return make_tuple("aaabbcc",
                    vector<string>{"aaa", "aab", "bc"},
                    "<b>aaabbc</b>c");
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - expect to see " << get<2>(f) << endl;
  Solution sol;
  cout << "result: " << sol.addBoldTag(get<0>(f), get<1>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - expect to see " << get<2>(f) << endl;
  Solution sol;
  cout << "result: " << sol.addBoldTag(get<0>(f), get<1>(f)) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}