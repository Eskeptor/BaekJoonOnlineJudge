using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_2309_CS
{
    class Program
    {
        private const int MAX = 9;
        static int[] arr = new int[MAX];
        static void Main(string[] args)
        {
            for (int i = 0; i < MAX; i++)
            {
                arr[i] = int.Parse(System.Console.ReadLine());
            }
            Array.Sort(arr);
            Solution();
        }

        static void Solution()
        {
            int total = 0;
            for (int i = 0; i < MAX; i++)
                total += arr[i];

            int decValue = total - 100;
            int dec1 = 0, dec2 = 0;
            bool breakFlag = false;

            for (int i = 0; i < MAX; i++)
            {
                dec1 = i;
                for (int j = 0; j < MAX; j++)
                {
                    if (i == j)
                        continue;
                    dec2 = j;

                    if (arr[dec1] + arr[dec2] == decValue)
                    {
                        breakFlag = true;
                        break;
                    }
                }
                if (breakFlag)
                    break;
            }

            for (int i = 0; i < MAX; i++)
            {
                if (i != dec1 && i != dec2)
                    System.Console.WriteLine(arr[i]);
            }
        }
    }
}
