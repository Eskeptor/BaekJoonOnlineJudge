using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_2748_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            int pibo = int.Parse(Console.ReadLine());
            Solution(pibo);
        }
        static void Solution(int pibo)
        {
            long[] arr = new long[pibo + 1];
            arr[0] = 0;
            arr[1] = 1;

            for (int i = 2; i < pibo + 1; i++)
                arr[i] = arr[i - 1] + arr[i - 2];

            Console.WriteLine(arr[pibo]);
        }
    }
}
