using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_2609_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] nums = System.Console.ReadLine().Split(' ');
            int num1 = int.Parse(nums[0]);
            int num2 = int.Parse(nums[1]);
            int resultGCD = GCD(num1, num2);
            int resultLCM = LCM(num1, num2, resultGCD);

            System.Console.WriteLine(resultGCD);
            System.Console.WriteLine(resultLCM);
        }

        static int GCD(int num1, int num2)
        {
            int mod;
            while (num2 != 0)
            {
                mod = num1 % num2;
                num1 = num2;
                num2 = mod;
            }
            return num1;
        }

        static int LCM(int num1, int num2, int gcdV)
        {
            return num1 * num2 / gcdV;
        }
    }
}
