import java.util.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int test_case = 1; test_case <= T; test_case++) {
            int[] box = new int[3];
            int res = 0;
            for(int i = 0; i < 3; i++) {
                box[i] = sc.nextInt();
            }
            if(box[1] >= 2 && box[2] >= 3) {
                if(box[1] >= box[2]) {
                    res += box[1] - box[2] + 1;
                    box[1] = box[2] - 1;
                }

                if(box[0] >= box[1]) {
                    res += box[0] - box[1] + 1;
                    box[0] = box[1] - 1;
                }
            }else {
                res = -1;
            }
            System.out.println("#" + test_case + " " + res);
        }
    }
}