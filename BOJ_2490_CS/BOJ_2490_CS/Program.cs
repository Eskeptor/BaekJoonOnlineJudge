using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_2490_CS
{
    class Program
    {
        const int LINE = 3;
        const int YOOT = 4;
        static void Main(string[] args)
        {
            string[] yoot;
            for (int i = 0; i < LINE; i++)
            {
                yoot = Console.ReadLine().Split(' ');
                Solution(yoot);
            }
        }
        static void Solution(string[] yoot)
        {
            int total = 0;
            for (int i = 0; i < YOOT; i++)
                total += int.Parse(yoot[i]);

            switch (total)
            {
                case 0:
                    Console.WriteLine("D");
                    break;
                case 1:
                    Console.WriteLine("C");
                    break;
                case 2:
                    Console.WriteLine("B");
                    break;
                case 3:
                    Console.WriteLine("A");
                    break;
                case 4:
                    Console.WriteLine("E");
                    break;
            }
        }
    }
}
