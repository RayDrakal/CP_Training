import java.util.Scanner;
class Solution
{
	public static void main(String args[]) throws Exception
	{
        Scanner sc = new Scanner(System.in);

        for(int test=1;test<11;test++) {
            int T = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();
            int ans = sq(a, b);
            System.out.println("#"+T+" "+ans);
        }
	}
    public static int sq(int n, int r) {
        if(r == 1) return n;
        return n * sq(n, r - 1);
    }
}