using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_11727_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            Solution(n);
        }
        static void Solution(int n)
        {
            if (n == 1)
            {
                Console.WriteLine("1");
                return;
            }

            int[] dp = new int[n + 1];
            dp[0] = 1;
            dp[1] = 1;

            for (int i = 2; i <= n; i++)
                dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;

            Console.WriteLine(dp[n]);
        }
    }
}
