using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_1427_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            char[] c_str = str.ToCharArray();
            Array.Sort(c_str);
            Array.Reverse(c_str);
            Console.WriteLine(c_str);
        }
    }
}
