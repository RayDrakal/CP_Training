import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        int[] start = new int[2];
        int[] end = new int[2];
        int[] circle = new int[3];

        for(int t = 0; t < T; t++) {
            StringTokenizer stk = new StringTokenizer(br.readLine(), " ");
            start[0] = Integer.parseInt(stk.nextToken());
            start[1] = Integer.parseInt(stk.nextToken());
            end[0] = Integer.parseInt(stk.nextToken());
            end[1] = Integer.parseInt(stk.nextToken());
            int N = Integer.parseInt(br.readLine());
            int ans = 0;
            for(int n = 0; n < N; n++) {
                boolean startPoint = false;
                boolean endPoint = false;
                stk = new StringTokenizer(br.readLine(), " ");
                circle[0] = Integer.parseInt(stk.nextToken());
                circle[1] = Integer.parseInt(stk.nextToken());
                circle[2] = Integer.parseInt(stk.nextToken());

                if(Math.pow(start[0]-circle[0],2) + Math.pow(start[1]-circle[1],2) <= Math.pow(circle[2],2)) {
                    startPoint = true;
                    ans++;
                }
                if(Math.pow(end[0]-circle[0],2) + Math.pow(end[1]-circle[1],2) <= Math.pow(circle[2],2)) {
                    endPoint = true;
                    ans++;
                }
                if(startPoint && endPoint) ans -= 2;
            }
            sb.append(ans + "\n");
        }
        System.out.println(sb);
        br.close();
    }
}