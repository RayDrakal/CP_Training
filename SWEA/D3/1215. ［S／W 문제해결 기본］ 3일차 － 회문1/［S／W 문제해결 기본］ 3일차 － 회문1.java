import java.util.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        for(int test=1;test<11;test++) {
            int findCnt = sc.nextInt();

            int cnt = 0;
            boolean chk = true;

            char[][] arr = new char[8][8];

            for(int i = 0; i < arr.length; i++) {
                String str = sc.next();
                for(int j = 0; j < arr[i].length; j++)
                    arr[i][j] = str.charAt(j);
            }

            for(int i = 0; i < arr.length; i++) {
                for(int j = 0; j < arr.length - findCnt + 1; j++) {
                    chk = true;
                    for(int h = 0; h < findCnt / 2; h++)
                        if(arr[i][j + h] != arr[i][j + findCnt - h - 1])
                            chk = false;
                    if(chk) cnt++;
                    chk = true;
                    for(int h = 0; h < findCnt / 2; h++)
                        if(arr[j + h][i] != arr[j + findCnt - h - 1][i])
                            chk = false;
                    if(chk) cnt++;
                }
            }
            System.out.println("#"+test+" "+cnt);
        }
    }
}