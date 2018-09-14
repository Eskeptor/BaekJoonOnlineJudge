using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_2455_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            int total = 0;
            int max = 0;
            int inP, outP;
            string[] line;

            for (int i = 0; i < 4; i++)
            {
                line = Console.ReadLine().Split(' ');
                outP = int.Parse(line[0]);
                inP = int.Parse(line[1]);

                total -= outP;

                total += inP;
                if (max < total)
                    max = total;
            }

            Console.WriteLine(max);
        }
    }
}
