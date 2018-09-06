using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_2579_CS
{
    class Program
    {
        static int[] arr;
        static void Main(string[] args)
        {
            int length = int.Parse(System.Console.ReadLine());
            arr = new int[length];
            for (int i = 0; i < length; i++)
            {
                arr[i] = int.Parse(System.Console.ReadLine());
            }
            Solution();
        }

        static void Solution()
        {
            int[] dp = new int[arr.Length];
            dp[0] = arr[0];
            dp[1] = Math.Max(arr[0], arr[0] + arr[1]);
            dp[2] = Math.Max(arr[0] + arr[2], arr[1] + arr[2]);

            for (int i = 3; i < arr.Length; i++)
            {
                dp[i] = Math.Max(arr[i] + dp[i - 2], arr[i] + dp[i - 3] + arr[i - 1]);
            }

            System.Console.WriteLine(dp[arr.Length - 1]);
        }
    }
}
