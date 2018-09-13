using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_10951_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            string input;
            string[] inputs;
            while (true)
            {
                input = Console.ReadLine();
                if (input == string.Empty || input == "" || input == " ")
                    break;
                inputs = input.Split(' ');
                Console.WriteLine(int.Parse(inputs[0]) + int.Parse(inputs[1]));
            }
        }
    }
}
