using System;
using System.Globalization;

namespace task_1
{ 
    class Program
    {
        static int[] CountDigits(string str)
        {
            int[] cnt = new int[10];

            for (int i = 0; i < str.Length; i++)
            {
                if (char.IsDigit(str[i]))
                {
                    cnt[str[i] - '0']++;
                }
            }

            return cnt;
        }
        static void Main(string[] args)
        {
            var currentTime = DateTime.Now;
            string firstFormat = currentTime.ToString("F", new CultureInfo("en-EN"));
            string secondFormat = currentTime.ToString("g", new CultureInfo("en-EN"));
            int[] countNumbers = new int[10];

            Console.WriteLine("The first format of date: " + firstFormat);
            Console.WriteLine("The number of each digits:");
            countNumbers = CountDigits(firstFormat);
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine(i + " - " + countNumbers[i]);
            }

            Console.WriteLine();

            Console.WriteLine("The second format of date: " + secondFormat);
            Console.WriteLine("The number of each digits:");
            countNumbers = CountDigits(secondFormat);
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine(i + " - " + countNumbers[i]);
            }
        }
    }
}
