using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_1929_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] line = Console.ReadLine().Split(' ');
            int start = int.Parse(line[0]);
            int end = int.Parse(line[1]);
            Solution(start, end);
        }
        static void Solution(int start, int end)
        {
            bool[] arr = new bool[end + 1];
            arr[0] = true;

            for (int i = 2; i * i <= end; i++)
                if (!arr[i])
                    for (int j = 2; j * i <= end; j++)
                        arr[j * i] = true;
                    
            for (int i = start; i <= end; i++)
                if (!arr[i])
                    Console.WriteLine(i);
        }
    }
}
