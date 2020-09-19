using System;
using System.Collections.Generic;
using System.Security.Cryptography;

namespace TransportProject
{
    public class Race
    {
        public delegate void CrashSutiation(double distance, TimeSpan time, double place);

        event CrashSutiation Crash;


        public Race(List<Auto> cars)
        {
            if (cars.Count < 2)
            {
                throw new ArgumentException("At least 2 cars must take part in the race.");
            }

            foreach (Auto car in cars)
            {
                Crash += car.Crash;               
            }
        }


        public void Accident()
        {
            Random random = new Random();
            double distance = random.NextDouble() * 100;            
            double place = Math.Min(distance, random.NextDouble() * 100);
            TimeSpan time = new TimeSpan(0, 0, (int) place * 1000 / 40);

            Crash?.Invoke(distance, time, place);
        }

    }
}