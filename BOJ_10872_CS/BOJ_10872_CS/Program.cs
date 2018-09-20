using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_10872_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            int input = int.Parse(Console.ReadLine());
            Console.WriteLine(Facto(input));
        }
        static int Facto(int input)
        {
            int total = 1;
            for (int i = 1; i <= input; i++)
                total *= i;
            return total;
        }
    }
}
