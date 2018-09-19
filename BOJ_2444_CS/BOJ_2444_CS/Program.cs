using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_2444_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            int star = int.Parse(Console.ReadLine());
            Solution(star);
        }
        static void Solution(int star)
        {
            for (int i = 0; i < star; i++)
            {
                for (int j = (star - i) - 1; j > 0; j--)
                    Console.Write(" ");
                for (int j = 0; j < 2 * i + 1; j++)
                    Console.Write("*");
                Console.WriteLine();
            }
            star--;
            for (int i = 0; i < star; i++)
            {
                for (int j = 0; j <= i; j++)
                    Console.Write(" ");
                for (int j = (star - i) * 2 - 1; j > 0; j--)
                    Console.Write("*");
                Console.WriteLine();
            }
        }
    }
}
