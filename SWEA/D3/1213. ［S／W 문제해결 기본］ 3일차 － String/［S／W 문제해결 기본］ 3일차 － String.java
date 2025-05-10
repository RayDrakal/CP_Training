import java.util.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for(int test = 0; test < 10; test++) {
            int t = Integer.parseInt(br.readLine());
            String target = br.readLine();
            String str = br.readLine();
            int cnt = 0;

            for(int i=0; i <= str.length() - target.length(); i++) {
                if(target.equals(str.substring(i, i+target.length())))
                    cnt++;
            }
            System.out.println("#" + t + ' ' + cnt);
        }
        br.close();
    }
}