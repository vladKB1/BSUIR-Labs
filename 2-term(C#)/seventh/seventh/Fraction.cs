using System;
using System.Collections.Generic;
using System.Data.Common;
using System.Text.RegularExpressions;

namespace Fraction
{
    public class Fraction : ICloneable, IComparable<Fraction>, IFormattable, IConvertible
    {
        private long num;
        private long den;

        public long Num { get => num; set => SetNum(value); }
        public long Den { get => den; set => SetDen(value); }



        //constructors
        public Fraction()
        {
        }

        public Fraction(long num)
        {
            Num = num;
            Den = 1;
        }

        public Fraction(long num, long den)            
        {
            Num = num;
            Den = den;
        }

        public Fraction(double x)
        {
            Fraction fraction = GetFraction(x.ToString());
            Num = fraction.num;
            Den = fraction.den;
            Reduce();
        }


        //Setters
        public void SetNum(long NewNum)
        {
            num = NewNum;
            if (num != 0 && den != 0)
            {
                Reduce();
            }
        }

        public void SetDen(long NewDen)
        {
            if (NewDen == 0)
            {
                throw new ArgumentException("Denominator can't be equal to zero.");
            }
            else if (NewDen < 0)
            {
                throw new ArgumentException("Denominator must be a natural number.");
            }
            den = NewDen;
            if (num != 0)
            {
                Reduce();
            }
        }



        //utility methods
        private double GetDouble() => (double)num / den;

        private static long Gcd(long a, long b)
        {
            while (a != 0 && b != 0)
            {
                if (a > b)
                {
                    a %= b;
                }
                else
                {
                    b %= a;
                }
            }
            return a + b;
        }

        private void Reduce()
        {
            long gcd = Gcd(Math.Abs(num), den);
            num /= gcd;
            den /= gcd;
        }

        public static Fraction GetFraction(string s)
        {
            if (TryParse(s, out Fraction fraction))
            {
                return fraction;
            }
            else
            {
                throw new FormatException("Unsupported input string format.");
            }
        }



        //From some format to Fraction
        //1 - standart, 2 - mixed fraction, 3 - double, 4 - integer
        public static bool TryParse(string s, out Fraction fraction)
        {
            fraction = null;

            Regex reg1 = new Regex(@"^(-?\d+)/(\d+)$");
            Regex reg2 = new Regex(@"^(-?\d+)\((\d+)/(\d+)\)$");
            Regex reg3 = new Regex(@"^(-?\d+)[,\.](\d+)$");
            Regex reg4 = new Regex(@"^(-?\d+)$");

            if (reg1.IsMatch(s))
            {
                Match match = reg1.Match(s);
                long num = long.Parse(match.Groups[1].Value);
                long den = long.Parse(match.Groups[2].Value);
                fraction = new Fraction(num, den);
                return true;
            } 
            else if (reg2.IsMatch(s))
            {
                Match match = reg2.Match(s);
                long integer = long.Parse(match.Groups[1].Value);
                long num = long.Parse(match.Groups[2].Value);
                long den = long.Parse(match.Groups[3].Value);
                int sign = integer >= 0 ? 1 : -1;
                fraction = new Fraction(sign * (Math.Abs(integer) * den + num), den);
                return true;               
            }
            else if (reg3.IsMatch(s))
            {
                Match match = reg3.Match(s);
                long integer = long.Parse(match.Groups[1].Value);
                int sign = integer >= 0 ? 1 : -1;
                string dec = match.Groups[2].Value;
                long den = (long)Math.Pow(10, dec.Length);
                long num = (Math.Abs(integer) * den + long.Parse(dec)) * sign;
                fraction = new Fraction(num, den);
                return true;
            }
            else if (reg4.IsMatch(s))
            {
                Match match = reg4.Match(s);
                fraction = new Fraction(long.Parse(match.Groups[1].Value));
                return true;
            }
            return false;
        }



        //System.Object
        public override bool Equals(object obj)
        {
            if (obj.GetType() != GetType())
            {
                return false;
            }
            return CompareTo((Fraction)obj) == 0;
        }

        public override int GetHashCode()
        {
            return HashCode.Combine(num, den);
        }

        public override string ToString()
            => ToString("S");



        //ICloneable, IComparable<Fraction>
        public object Clone()
        {
            return new Fraction(num, den);
        }

        public int CompareTo(Fraction fraction)
        {
            long lcm = den * fraction.den / Gcd(Math.Abs(den), fraction.den);
            long num1 = num * (lcm / den);
            long num2 = fraction.num * (lcm / fraction.den);
            return num1.CompareTo(num2);
        }



        //IFormattable
        public string ToString(string format)
            => ToString(format, null);

        //S - standart, M - mixed fraction, D - double, I - integer
        public string ToString(string format, IFormatProvider formatProvider)               
        {
            if (string.IsNullOrEmpty(format))
            {
                format = "S";
            }

            if (format == "S")
            {
                return $"{num}/{den}";
            } 
            else if (format == "M")
            {
                if (Math.Abs(num) > den && den != 1)
                {
                    long integer = num / den;
                    return $"{integer}({Math.Abs(num) % den}/{den})";
                } else
                {
                    return ToString("I");
                }
            }
            else if (format == "D")
            {
                return GetDouble().ToString();
            }
            else if (format == "I")
            {
                if (Math.Abs(num) > den)
                {
                    long integer = num / den;
                    return integer.ToString();
                }
                else
                {
                    return ToString("S");
                }
            }
            else
            {
                throw new FormatException($"The \"{format}\" format is not supported.");
            }
        }



        //IConvertible
        public TypeCode GetTypeCode()
            => TypeCode.Object;

        public bool ToBoolean(IFormatProvider provider) => num != 0;

        public byte ToByte(IFormatProvider provider)
            => Convert.ToByte(GetDouble(), provider);

        public char ToChar(IFormatProvider provider)
            => Convert.ToChar(GetDouble(), provider);

        public DateTime ToDateTime(IFormatProvider provider)
            => Convert.ToDateTime(GetDouble(), provider);

        public decimal ToDecimal(IFormatProvider provider)
            => Convert.ToDecimal(GetDouble(), provider);

        public double ToDouble(IFormatProvider provider)
            => GetDouble();

        public short ToInt16(IFormatProvider provider)
            => Convert.ToInt16(GetDouble(), provider);

        public int ToInt32(IFormatProvider provider)
            => Convert.ToInt32(GetDouble(), provider);

        public long ToInt64(IFormatProvider provider)
            => Convert.ToInt64(GetDouble(), provider);

        public SByte ToSByte(IFormatProvider provider)
            => Convert.ToSByte(GetDouble(), provider);

        public float ToSingle(IFormatProvider provider)
            => Convert.ToSingle(GetDouble(), provider);

        public string ToString(IFormatProvider provider)
            => ToString("S", provider);

        public object ToType(Type conversionType, IFormatProvider provider)
            => Convert.ChangeType(GetDouble(), conversionType);

        public UInt16 ToUInt16(IFormatProvider provider)
            => Convert.ToUInt16(GetDouble(), provider);

        public UInt32 ToUInt32(IFormatProvider provider)
            => Convert.ToUInt32(GetDouble(), provider);

        public UInt64 ToUInt64(IFormatProvider provider)
            => Convert.ToUInt64(GetDouble(), provider);



        //conversions
        public static explicit operator sbyte(Fraction x)
            => x.ToSByte(null);
        public static explicit operator short(Fraction x)
            => x.ToInt16(null);

        public static explicit operator int(Fraction x)
            => x.ToInt32(null);

        public static explicit operator long(Fraction x)
            => x.ToInt64(null);

        public static explicit operator float(Fraction x)
            => x.ToSingle(null);

        public static explicit operator double(Fraction x)
            => x.ToDouble(null);

        public static explicit operator decimal(Fraction x)
            => x.ToDecimal(null);



        //unary operations
        public static Fraction operator +(Fraction x) => x;
        public static Fraction operator -(Fraction x) => new Fraction(-x.num, x.den);



        //binary operations
        public static Fraction operator +(Fraction a, Fraction b)
            => new Fraction(a.num * b.den + b.num * a.den, a.den * b.den);

        public static Fraction operator -(Fraction a, Fraction b)
            => a + (-b);

        public static Fraction operator *(Fraction a, Fraction b)
            => new Fraction(a.num * b.num, a.den * b.den);

        public static Fraction operator *(Fraction a, long b)
            => new Fraction(a.num * b, a.den);

        public static Fraction operator /(Fraction a, Fraction b)
        {
            if (b.num == 0)
            {
                throw new DivideByZeroException();
            }
            return new Fraction(a.num * b.den, a.den * b.num);
        }

        public static Fraction operator /(Fraction a, long b)
        {
            if (b == 0)
            {
                throw new DivideByZeroException();
            }
            return new Fraction(a.num, a.den * b);
        }



        //comparison operators
        public static bool operator ==(Fraction a, Fraction b) => a.CompareTo(b) == 0;

        public static bool operator !=(Fraction a, Fraction b) => a.CompareTo(b) != 0;

        public static bool operator >(Fraction a, Fraction b) => a.CompareTo(b) == 1;

        public static bool operator <(Fraction a, Fraction b) => a.CompareTo(b) == -1;

        public static bool operator >=(Fraction a, Fraction b) => a.CompareTo(b) != -1;

        public static bool operator <=(Fraction a, Fraction b) => a.CompareTo(b) != 1;
    }
}