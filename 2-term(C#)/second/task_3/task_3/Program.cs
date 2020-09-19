using System;
using System.Text;

namespace task_3
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            StringBuilder sb = new StringBuilder(' ' + str + ' ', str.Length * 2 + 2);            

            int l = 0;
            int r = 0;

            for (int i = 1; i < sb.Length - 1; i++)
            {
                if (l == -1 && sb[i - 1] == ' ')
                {
                    l = i;
                }
                if (l != -1 && sb[i + 1] == ' ')
                {
                    r = i;

                    if (!((sb[r] >= 'a' && sb[r] <= 'z') || (sb[r] >= 'A' && sb[r] <= 'Z'))) {
                        sb.Insert(l, sb[r]);
                        i++;
                    }

                    l = -1;
                }
            }

            sb.Remove(0, 1);
            sb.Remove(sb.Length - 1, 1);
            str = sb.ToString();

            Console.WriteLine(str);
        }
    }
}
