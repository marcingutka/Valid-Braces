#include <stack>
#include <vector>
#include <algorithm>

bool same_pair(char begin, char end)
{
  if (begin == '(' && end == ')') return true;
  if (begin == '[' && end == ']') return true;
  if (begin == '{' && end == '}') return true;
  return false;
}

bool valid_braces(std::string braces)
{
   std::stack<char> s;
   std::vector<char> ends{')', '}', ']'};

   for(int i = 0; i < braces.size(); ++i)
   {
     if (std::any_of(ends.cbegin(), ends.cend(),
       [&](char c){return c == braces[i];}))
     {
       if (s.empty() || !(same_pair(s.top(),braces[i]))) return false;
       s.pop();
     }
     else s.push(braces[i]);
   }
   if (s.empty()) return true;
   else return false;
}
