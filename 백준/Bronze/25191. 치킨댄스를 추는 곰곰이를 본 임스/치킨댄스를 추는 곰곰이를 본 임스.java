import java.util.*;
import java.io.*;

public class Main {
    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int result = Math.min(n,Integer.parseInt(st.nextToken()) / 2 + Integer.parseInt(st.nextToken()));

        bw.write(String.valueOf(result));
        bw.flush();
        bw.close();
        br.close();
    }
    public static void main(String[] args) throws IOException {
        solution();
    }
}