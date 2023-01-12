#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(char c : s){
            switch (c){
            case '(': case '{': case '[':stack.push(c);break;
            case ')':if(stack.empty() || stack.top()!='(')return false;stack.pop();break;
            case '}':if(stack.empty() || stack.top()!='{')return false;stack.pop();break;
            default:if(stack.empty() || stack.top()!='[')return false;stack.pop();
            }
        }
        if(!stack.empty())return false;
        return true;
    }
};