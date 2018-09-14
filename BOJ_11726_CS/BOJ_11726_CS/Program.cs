using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_11726_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            int block = int.Parse(Console.ReadLine());
            Solution(block);
        }
        static void Solution(int block)
        {
            if (block == 1)
            {
                Console.WriteLine("1");
                return;
            }

            int[] dp = new int[block + 1];
            dp[0] = 1;
            dp[1] = 1;

            for (int i = 2; i <= block; i++)
                dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

            Console.WriteLine(dp[block]);
        }
    }
}
