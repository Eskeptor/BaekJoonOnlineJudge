using System;
using System.Collections.Generic;

namespace BOJ_1697_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] line = Console.ReadLine().Split(' ');
            BFS(int.Parse(line[0]), int.Parse(line[1]));
        }
        static void BFS(int n, int k)
        {
            if (n == k)
            {
                Console.WriteLine("0");
                return;
            }

            int max;
            if (n > k)
                max = n;
            else
                max = k;
            int[] arr = new int[max + 2];
            int[] next = new int[3];
            Queue<int> queue = new Queue<int>();
            int curPos;

            queue.Enqueue(n);
            arr[n] = 1;

            while (queue.Count > 0)
            {
                curPos = queue.Dequeue();
                if (curPos == k)
                    break;

                next[0] = curPos * 2;
                next[1] = curPos + 1;
                next[2] = curPos - 1;

                for (int i = 0; i < 3; i++)
                {
                    if (next[i] >= 0 && next[i] < max + 2 && arr[next[i]] == 0)
                    {
                        arr[next[i]] = arr[curPos] + 1;
                        queue.Enqueue(next[i]);
                    }
                }
            }

            Console.WriteLine(arr[k] - 1);
        }
    }
}
