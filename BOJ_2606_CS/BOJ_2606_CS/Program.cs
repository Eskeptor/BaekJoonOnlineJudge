using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_2606_CS
{
    class Program
    {
        static int[,] arr;
        static void Main(string[] args)
        {
            int com = int.Parse(Console.ReadLine());
            arr = new int[com, com];

            int line = int.Parse(Console.ReadLine());
            string[] link;

            int v1, v2;
            for (int i = 0; i < line; i++)
            {
                link = Console.ReadLine().Split(' ');
                v1 = int.Parse(link[0]) - 1;
                v2 = int.Parse(link[1]) - 1;
                arr[v1, v2] = 1;
                arr[v2, v1] = 1;
            }
            Solution(com);
        }
        static void Solution(int com)
        {
            bool[] arrEntered = new bool[com];
            int curPos = 0;
            int counter = 0;
            Queue<int> queue = new Queue<int>();

            queue.Enqueue(curPos);
            arrEntered[curPos] = true;

            while (queue.Count != 0)
            {
                curPos = queue.Dequeue();

                for (int i = 0; i < com; i++)
                {
                    if (arr[curPos, i] == 1 && !arrEntered[i])
                    {
                        arrEntered[i] = true;
                        queue.Enqueue(i);
                        counter++;
                    }
                }
            }
            Console.WriteLine(counter);
        }
    }
}
