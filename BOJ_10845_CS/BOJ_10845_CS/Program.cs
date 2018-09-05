using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ_10845_CS
{
    class Queue
    {
        private int[] arr;
        private int front;
        private int back;
        private int size;

        public Queue()
        {
            arr = new int[10001];
            front = -1;
            back = -1;
            size = 0;
        }

        public void Push(int value)
        {
            if (size < 10001)
            {
                if (size == 0)
                    front = 0;
                arr[++back] = value;
                size++;
            }
        }

        public int Pop()
        {
            if (size == 0)
                return -1;

            int tmp = arr[front];
            front++;
            size--;
            if (size == 0)
            {
                front = -1;
                back = -1;
            }
                
            return tmp;
        }

        public int Size()
        {
            return size;
        }

        public int Empty()
        {
            return size == 0 ? 1 : 0;
        }

        public int Front()
        {
            return front == -1 ? -1 : arr[front];
        }

        public int Back()
        {
            return back == -1 ? -1 : arr[back];
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            int lines = Int32.Parse(Console.ReadLine());

            Queue queue = new Queue();
            string str;
            string[] strs = new string[2];
            for (int i = 0; i < lines; i++)
            {
                str = Console.ReadLine();
                if (str != string.Empty && str != null)
                {
                    strs = str.Split(' ');
                    switch (strs[0])
                    {
                        case "push":
                            queue.Push(Int32.Parse(strs[1]));
                            break;
                        case "pop":
                            System.Console.WriteLine(queue.Pop());
                            break;
                        case "front":
                            System.Console.WriteLine(queue.Front());
                            break;
                        case "back":
                            System.Console.WriteLine(queue.Back());
                            break;
                        case "empty":
                            System.Console.WriteLine(queue.Empty());
                            break;
                        case "size":
                            System.Console.WriteLine(queue.Size());
                            break;
                    }
                }
            }
        }
    }
}
