using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Numerics;

namespace task_2
{
    class Program
    {
        static bool IsHex(ref string str)
        {
            str = '0' + str;

            if (str.Length >= 3)
            {
                if (str[1] == '0' && str[2] == 'X')
                {
                    str = str.Remove(2, 1);
                }
            }           

            for (int i = 0; i < str.Length; i++)
            {              
                if ((str[i] < 'A' || str[i] > 'F') && (str[i] < '0' || str[i] > '9'))
                {
                    return false;
                }
            }

            return true;
        }

        static void Main(string[] args)
        {
            string[] str = Console.ReadLine().ToUpper().Split();
            int count = str.Count();
            List<BigInteger> numbers = new List<BigInteger>();
            

            for (int i = 0; i < count; i++)
            {
                if (IsHex(ref str[i]))
                {                   
                    numbers.Add(BigInteger.Parse(str[i], NumberStyles.HexNumber));
                }
            }

            count = numbers.Count();

            if (count == 0)
            {
                Console.WriteLine("\nThere is no hexadecimal numbers :(");
            } else
            {
                Console.WriteLine($"\nThere is {count} hexadecimal number(s): ");
            }

            foreach (var i in numbers)
            {
                Console.WriteLine(i);
            }
        }       
    }
}
