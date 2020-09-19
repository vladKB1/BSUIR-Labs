using System;
using System.Collections.Generic;
using System.Linq;

namespace Fraction
{
    class Program
    {
        static void Main(string[] args)
        {
            //different constructors and string formats
            List<Fraction> fractions = new List<Fraction>()
            {                
                new Fraction(5),
                new Fraction(2, 3),
                new Fraction(1.45),
                Fraction.GetFraction("5/3"),
                Fraction.GetFraction("-3(1/2)"),
                Fraction.GetFraction("15,69"),
                Fraction.GetFraction("21")
            };

            Console.WriteLine("YES");

            //overload operations
            fractions.Add(fractions[0] + fractions[2]);
            fractions.Add(fractions[3] - fractions[1]);
            fractions.Add(fractions[6] * fractions[4]);
            fractions.Add(fractions[5] / fractions[7]);

            //use Clone
            fractions.Add(fractions[3].Clone() as Fraction);


            Fraction testFraction = new Fraction(-42, 13);

            Console.WriteLine("Try to convert fraction to unsuported format: ");
            try
            {
                testFraction.ToString("The string");
            }
            catch (FormatException ex)
            {
                Console.WriteLine(ex.Message);
            }

            Console.WriteLine("\nTry get fraction using unssuported format:");
            try
            {
                fractions.Add(Fraction.GetFraction("The string"));
            }
            catch (FormatException ex)
            {
                Console.WriteLine(ex.Message);
            }

            Console.WriteLine("\nTry to add fraction with denominator = 0 :");
            try
            {
                fractions.Add(new Fraction(12, 0));
            }
            catch (ArgumentException ex)
            {
                Console.WriteLine(ex.Message);
            }

            Console.WriteLine("\nTry to add fraction with denominator < 0 :");
            try
            {
                fractions.Add(new Fraction(12, -3));
            }
            catch (ArgumentException ex)
            {
                Console.WriteLine(ex.Message);
            }


            Console.WriteLine("\nList of all fractions:");
            fractions.ForEach(i => Console.WriteLine("{0:S}", i));


            Console.WriteLine("\noutput fraction in different formats:");
            Console.WriteLine("{0:S}", testFraction);
            Console.WriteLine("{0:M}", testFraction);
            Console.WriteLine("{0:D}", testFraction);
            Console.WriteLine("{0:I}", testFraction);


            Console.WriteLine("\nCoversion:");
            Console.WriteLine((short)testFraction);
            Console.WriteLine((int)testFraction);
            Console.WriteLine((long)testFraction);
            Console.WriteLine((float)testFraction);
            Console.WriteLine((double)testFraction);
            Console.WriteLine(Convert.ToBoolean(testFraction));
            Console.WriteLine(Convert.ToString(testFraction));

            Console.WriteLine("\nComparison:");
            Console.WriteLine(fractions[0] == fractions[9]);
            Console.WriteLine(fractions[3] != fractions[5]);
            Console.WriteLine(fractions[6] < fractions[8]);
            Console.WriteLine(fractions[1] >= fractions[7]);
           
        }
    }
}