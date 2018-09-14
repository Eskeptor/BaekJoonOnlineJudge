using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_10952_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            int num1, num2;
            string[] line;
            while (true)
            {
                line = Console.ReadLine().Split(' ');
                if (line[0] == "0" && line[1] == "0")
                    break;
                num1 = int.Parse(line[0]);
                num2 = int.Parse(line[1]);
                Console.WriteLine(num1 + num2);
            }
        }
    }
}
