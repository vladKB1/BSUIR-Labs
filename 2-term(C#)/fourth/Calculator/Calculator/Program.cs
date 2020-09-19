using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace Calculator
{
    class Program
    {
        [DllImport("Dll.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern int Add(int a, int b);

        [DllImport("Dll.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern int Subtract(int a, int b);

        [DllImport("Dll.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern int Multiply(int a, int b);

        [DllImport("Dll.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern int Division(int a, int b);

        [DllImport("Dll.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern int Gcd(int a, int b);

        [DllImport("Dll.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern int BinPow(int a, int b);

        static void Main(string[] args)
        {
            int a = 12;
            int b = 4;

            Console.WriteLine($"{a} + {b} = {Add(a, b)}");
            Console.WriteLine($"{a} - {b} = {Subtract(a, b)}");
            Console.WriteLine($"{a} * {b} = {Multiply(a, b)}");
            Console.WriteLine($"{a} / {b} = {Division(a, b)}");
            Console.WriteLine($"GCD({a},{b}) = {Gcd(a, b)}");
            Console.WriteLine($"{a}^{b} = {BinPow(a, b)}");
            Console.ReadKey();            
        }
    }
}
