using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_11053_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            int size = int.Parse(Console.ReadLine());
            string[] lines = Console.ReadLine().Split(' ');

            Solution(lines, size);
        }
        static void Solution(string[] lines, int size)
        {
            if (size == 1)
            {
                Console.WriteLine("1");
                return;
            }

            int[] arr = new int[lines.Length];
            for (int i = 0; i < lines.Length; i++)
                arr[i] = int.Parse(lines[i]);
            ArrayList list = new ArrayList();
            bool isIn = false;

            list.Add(int.Parse(lines[0]));

            for (int i = 1; i < size; i++)
            {
                isIn = false;
                for (int j = 0; j < list.Count; j++)
                {
                    if ((int)list[j] >= arr[i])
                    {
                        list[j] = arr[i];
                        isIn = true;
                        break;
                    }
                }
                if (!isIn)
                    list.Add(arr[i]);
            }

            Console.WriteLine(list.Count);
        }
    }
}
