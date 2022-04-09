#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>
using namespace sol616;
using namespace std;

/*takeaways
  - use s = "aaabbcc" dict = ["aaa","aab","bc"] as an example
    - the longest pattern you can find start with s[0]
      is s[0]..s[2] = "aaa", so we know s[0]..s[2] are the
      candidates to be marked as bold
    - next, start with s[1] and the longest pattern you can
      find is s[1]..s[3] = "aab", so s[1]..s[3] should be
      bold as well
    - by combining the above two cases we know s[0]..s[3]
      = "aaab" should be bold
    - we will keeping scanning through the remaining chars
      to see if we can further expand the array of chars that
      need to be marked as bold

*/

string Solution::addBoldTag(string s, vector<string> &dict)
{
  const int n = s.length();
  auto result = string("");
  auto bold = vector<bool>(n);
  /* we will try to extend "end" every
     time we find a match between
     a substring from the s and an
     entry from the dict
  */
  auto end = -1;

  for (auto i = 0; i < n; i++)
  {
    for (auto e : dict)
      /* if we find a match between a substring
         starting at position s[i] with an entry
         from the dictionary, record the
         longest pattern you can find
      */
      if (s.substr(i).find(e) == 0)
        /*record the longest one by
          further extending the "end"
        */
        end = max(end, i + (int)e.length());
    /*mark s[i]..s[end-1] as bold */
    bold[i] = end > i;
  }

  auto i = 0;
  while (i < n)
    if (bold[i])
    {
      auto start = i;
      /* start with the next pos to see if
         it's still a bold char
      */
      while (++i < n && bold[i])
        ;
      /* i will be pointing at a non-bold char now */
      result += "<b>" + s.substr(start, i - start) + "</b>";
    }
    else
      result += s[i++];

  return result;
}