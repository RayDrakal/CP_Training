import java.util.*;
import java.io.*;

class Solution
{
    static Stack<Character> stk;
	public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for(int test=1;test<11;test++) {
            int len = Integer.parseInt(br.readLine());
            stk = new Stack<Character>();
            int ans = 1;

            String str = br.readLine();

            for (int i = 0; i < len; i++) {
                char ch = str.charAt(i);
                if(ch == '(' || ch == '{' || ch == '[' || ch == '<')
                    stk.push(ch);
                else {
                    if(!pairCheck(ch, stk.pop())) {
                        ans = 0;
                        break;
                    }
                }
            }
            System.out.println("#" + test + " " + ans);
        }
        br.close();
    }
    public static boolean pairCheck(char toStack, char inStack) {
        if(toStack == ')' && inStack == '(') return true;
        else if(toStack == '}' && inStack == '{') return true;
        else if(toStack == ']' && inStack == '[') return true;
        else if(toStack == '>' && inStack == '<') return true;
        else return false;
    }
}