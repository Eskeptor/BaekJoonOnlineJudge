using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_11399_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            int line = int.Parse(Console.ReadLine());
            string[] str = Console.ReadLine().Split(' ');
            Array.Sort(str);

            int total = 0;
            for (int i = 0; i < str.Length; i++)
            {
                for (int j = 0; j < str.Length - i; j++)
                    total += int.Parse(str[i]);
            }
            Console.WriteLine(total);
        }
    }
}
