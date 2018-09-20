using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_2293_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = Console.ReadLine().Split(' ');
            int coin = int.Parse(lines[0]);
            int target = int.Parse(lines[1]);
            int[] won = new int[coin];
            for (int i = 0; i < coin; i++)
                won[i] = int.Parse(Console.ReadLine());
            Solution(won, target);
        }
        static void Solution(int[] won, int target)
        {
            int[] arr = new int[target + 1];
            arr[0] = 1;

            for (int i = 0; i < won.Length; i++)
                for (int j = 1; j <= target; j++)
                    if (j - won[i] >= 0)
                        arr[j] += arr[j - won[i]];
            
            Console.WriteLine(arr[target]);
        }
    }
}
