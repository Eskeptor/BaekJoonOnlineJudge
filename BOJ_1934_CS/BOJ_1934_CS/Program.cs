using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_1934_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            int lines = int.Parse(Console.ReadLine());
            string[] nums;
            for (int i = 0; i < lines; i++)
            {
                nums = Console.ReadLine().Split(' ');
                LCM(int.Parse(nums[0]), int.Parse(nums[1]));
            }
        }
        static void LCM(int num1, int num2)
        {
            int gcd = GCD(num1, num2);
            Console.WriteLine(num1 * num2 / gcd);
        }
        static int GCD(int num1, int num2)
        {
            int num3 = 0;
            while (num2 != 0)
            {
                num3 = num1 % num2;
                num1 = num2;
                num2 = num3;
            }
            return num1;
        }
    }
}
