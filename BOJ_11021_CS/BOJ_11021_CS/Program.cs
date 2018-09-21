using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_11021_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            int line = int.Parse(Console.ReadLine());
            string[] lines;
            for (int i = 0; i < line; i++)
            {
                lines = Console.ReadLine().Split(' ');
                Console.WriteLine("Case #{0}: {1}", i + 1, int.Parse(lines[0]) + int.Parse(lines[1]));
            }
        }
    }
}
