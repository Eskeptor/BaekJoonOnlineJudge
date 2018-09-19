using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_2667_CS
{
    class Program
    {
        static int[,] map;
        static readonly int[] moveX = { 0, 1, 0, -1 };
        static readonly int[] moveY = { -1, 0, 1, 0 };
        static int total = 0;
        static void Main(string[] args)
        {
            int size = int.Parse(Console.ReadLine());
            map = new int[size, size];

            string mapLine;
            for (int i = 0; i < size; i++)
            {
                mapLine = Console.ReadLine();
                for (int j = 0; j < size; j++)
                    map[i, j] = mapLine[j] - '0';
            }

            Solution(size);
        }
        static void Solution(int size)
        {
            List<int> list = new List<int>();
            for (int y = 0; y < size; y++)
            {
                for (int x = 0; x < size; x++)
                {
                    Selector(x, y, size);
                    if (total != 0)
                        list.Add(total);
                    total = 0;
                }
            }

            list.Sort();
            Console.WriteLine(list.Count);
            list.ForEach(delegate (int a) { Console.WriteLine(a); });
        }
        static void Selector(int x, int y, int size)
        {

            int sideX, sideY;

            if (x >= 0 && x < size && y >= 0 && y < size
                && map[y, x] == 1)
            {
                total++;
                map[y, x] = 0;

                for (int i = 0; i < 4; i++)
                {
                    sideX = x + moveX[i];
                    sideY = y + moveY[i];

                    Selector(sideX, sideY, size);
                }
            }
        }
    }
}
