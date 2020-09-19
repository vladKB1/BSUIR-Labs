using System;
using System.Collections.Generic;

namespace first
{
    class Program
    {
        static uint ReadUint(string str)
        {
            uint uInteger;

            while (!UInt32.TryParse(str, out uInteger) || uInteger == 0)
            {
                Console.Write("The data is invalid. Try again and enter the positive integer: ");              
                str = Console.ReadLine();
            }
                
            return uInteger;
        }

        static void Main(string[] args)
        {           
            Console.Write("Enter the number of items: ");
            uint numberItems = ReadUint(Console.ReadLine());

            Console.Write("Enter the backpack capacity: ");
            uint maxWeight = ReadUint(Console.ReadLine());


            uint[] price = new uint[numberItems];
            uint[] weight = new uint[numberItems];
           
            Console.WriteLine($"Enter the price and weight (separated by a space) of each of the {numberItems} item(s):");
            for (uint i = 0; i < numberItems; i++)
            {
                uint x, y;

                while (true) 
                {
                    string[] str = Console.ReadLine().Split();

                    if (!UInt32.TryParse(str[0], out x) || !UInt32.TryParse(str[1], out y) || x == 0 || y == 0)
                    {
                        Console.Write("The data is invalid. Try again and enter 2 the positive integers separated by a space: ");
                    } 
                    else
                    {
                        price[i] = x;
                        weight[i] = y;
                        break;
                    }
                }               
            }

            int[] dp = new int[maxWeight + 1];          
            uint[] p = new uint[maxWeight + 1];

            for (uint i = 1; i <= maxWeight; i++)
            {
                dp[i] = Int32.MinValue;
            }

            uint answer = 0;
            uint index = 0;
            List<uint> usingItems = new List<uint>();
      
            for (uint i = 0; i < numberItems; i++)
            {         
                for (uint j = maxWeight; j >= 1; j--)
                {
                    int x = (int)j - (int)weight[i];

                    if (x >= 0)
                    {
                        if (dp[x] + price[i] > dp[j])
                        {
                            dp[j] = dp[x] + (int)price[i];
                            p[j] = i;

                            if (dp[j] > answer)
                            {
                                answer = (uint)dp[j];
                                index = j;
                            }
                        }
                    }
                }
            }

            if (index == 0)
            {
                Console.WriteLine("None of the items fit. :(");
                return;
            }

            uint count = 0;
            uint ansWeight = index;

            while (index != 0)
            {
                usingItems.Add(p[index] + 1);
                count++;             
                index -= weight[p[index]];
            }
            usingItems.Reverse();            

            Console.Write($"{count} item(s) were taken with the following numbers: ");
            foreach (var i in usingItems)
            {
                Console.Write(i + " ");
            }
            Console.WriteLine($"\nThe cost of all items: {answer}");
            Console.WriteLine($"The Weight of all items: {ansWeight}");
        }
    }
}
