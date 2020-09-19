using System;
using System.Collections.Generic;
using System.Security.Cryptography;

namespace TransportProject
{
    public class Program
    {     
        static void NewChip(ref double maxSpeed, ref double power)
        {
            maxSpeed *= 1.05;
            power *= 1.03;
        }

        static void NewEngine(ref double mileage, ref double maxSpeed,
                              double oldPower, double newPower)
        {
            mileage = 1;
            if (oldPower < newPower)
            {
                maxSpeed *= 1.0 + newPower / oldPower / 10.0;
            }
            else
            {
                maxSpeed *= 1.0 - oldPower / newPower / 10.0;
            }
        }

        static void Main(string[] args)
        {
            Console.Clear();

            //Add 6 new cars 
            List<Auto> cars = new List<Auto>()
            {
                new Porsche((Porsche.PorscheModels)1, "7687ZPRU", 2020, ConsoleColor.Blue, 167000, 5432.21,
                            330, 2020, 4, 2, (Auto.TransmissionType)3, (Auto.DriveType)3, 64, 11.5,
                            "H6", (IEngine.EngineType)1, 3.745, 650, false),
                new Porsche((Porsche.PorscheModels)2, "8945ZFAU", 2010, ConsoleColor.Red, 108340, 21340.41,
                            304, 2690, 4, 4, (Auto.TransmissionType)3, (Auto.DriveType)3, 75, 9.5,
                            "V8", (IEngine.EngineType)1, 3.996, 550, false),
                new Lamborghini((Lamborghini.LamborghiniModels)1, "2781VCRU", 2015, ConsoleColor.DarkGreen,
                                540000, 10243, 350, 1575, 2, 2, (Auto.TransmissionType)3, (Auto.DriveType)3,
                                85, 16.9, "V12", (IEngine.EngineType)1, 6.498, 740, false),
                new Lamborghini((Lamborghini.LamborghiniModels)2, "7722SYAU", 2016, ConsoleColor.Yellow,
                                86740, 260432, 325, 1542, 2, 2, (Auto.TransmissionType)3, (Auto.DriveType)3,
                                80, 13.7, "V10", (IEngine.EngineType)1, 5.204, 640, false),
                new Bugatti((Bugatti.BugattiModels)1, "9387JFUS", 2019, ConsoleColor.DarkMagenta, 3456300,
                            1002.1, 420, 1977, 2, 2, (Auto.TransmissionType)3, (Auto.DriveType)3, 100, 22.2,
                            "W16", (IEngine.EngineType)1, 7.993, 1500, false),
                new Bugatti((Bugatti.BugattiModels)2, "9473ZIBY", 2003, ConsoleColor.DarkBlue, 5601050,
                            1, 415, 2200, 2, 2, (Auto.TransmissionType)3, (Auto.DriveType)3, 100, 23.1,
                            "W16", (IEngine.EngineType)1, 7.993, 1200, false)

                //https://www.guideautoweb.com/
                //https://auto.ru/catalog/cars/                
            };


            Console.WriteLine("------------------\t LIST OF CARS \t------------------");
            foreach (var i in cars)
            {
                i.MainInfo();
                Console.WriteLine("______________________________________________________");
            }


            //Change info
            cars[0].SetRegistrPlate("4458TCAU");
            cars[1].SetColor(ConsoleColor.Green);
            cars[2].SetCost(440000);
            cars[5].SetMileage(3655.31);


            //Clone
            cars.Add(cars[3].Clone() as Auto);

            //RolledBackMileage
            cars[3].RolledBackMileage(17500,
                average => average + RandomNumberGenerator.GetInt32((int)1e7) / 1e7 * 3000 - 1500);

            Console.WriteLine();

            Console.WriteLine("------------------    LIST OF CARS WITH FULL INFO    ------------------");
            foreach (var i in cars)
            {
                i.FullInfo();
                Console.WriteLine("______________________________________________________");
            }


            Console.WriteLine("Make a test drive: ");
            TimeSpan time = cars[5].TestDrive(1000, out double averageSpeed, out double fuelings);
            Console.WriteLine($"Total test drive time - {time.Hours}h:{time.Minutes}m:{time.Seconds}s");
            Console.WriteLine("Average speed: {0}", averageSpeed.ToString("#.##"));
            Console.WriteLine("Number of fuelings: {0}", (int)fuelings);
            Console.WriteLine();

            Console.WriteLine("Make a test drive with higer mileage car: ");
            time = cars[6].TestDrive(1000, out averageSpeed, out fuelings);
            Console.WriteLine($"Total test drive time - {time.Hours}h:{time.Minutes}m:{time.Seconds}s");
            Console.WriteLine("Average speed: {0}", averageSpeed.ToString("#.##"));
            Console.WriteLine("Number of fuelings: {0}", (int)fuelings);
            Console.WriteLine();


            //ChipTuning
            cars[2].ChipTuning(new Auto.ChipTune(NewChip));

            Console.WriteLine("After chipTuning:");
            cars[2].FullInfo();

            Console.Write("\nTry to chip tuning once again: ");
            Console.WriteLine(cars[2].ChipTuning(new Auto.ChipTune(NewChip)));
            Console.WriteLine();


            //Change engine
            cars[6].ChangeEngine("W16", (IEngine.EngineType)1, 7.993, 1500,
                                 false, new Auto.EngineTune(NewEngine));

            Console.WriteLine("Make a 100 km sprint race between 2 cars:");
            int result = cars[6].CompareTo(cars[1]);
            Console.WriteLine(result == 1 ? "First one wins!" : (result == 0 ? "Draw!" : "Second one wins!"));
            Console.WriteLine();


            //testings some exceptions           
            try
            {
                cars[5].SetRegistrPlate("veeeeeeeeeeeeeeeeeeeryyyyyyyyyyy looooooooonnnnnngggg");
            }
            catch (ArgumentException ex)
            {
                Console.WriteLine(ex.Message);
            }

            try
            {
                cars[5].SetRegistrPlate("*-)abd((8d");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

            try
            {
                cars[0].SetCost(-14311.1212);
            }
            catch (ArgumentException ex)
            {
                Console.WriteLine(ex.Message);
            }

            try
            {
                cars[3].SetMileage(1);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

            try
            {
                cars[4].ChangeEngine("W16", (IEngine.EngineType)1, -7.993, 1500,
                                 false, new Auto.EngineTune(NewEngine));
            }
            catch (ArgumentException ex)
            {
                Console.WriteLine(ex.Message);
            }


            Console.WriteLine("\nEvent test:");

            for (int i = 0; i < 4; i++)
            {
                cars[i].Crashed += (message) => Console.WriteLine(message);
                cars[i].Survived += (message) => Console.WriteLine(message);
            }

            for (int i = 4; i < cars.Count; i++)
            {
                cars[i].Crashed += delegate (string message) { Console.WriteLine(message); };
                cars[i].Survived += delegate (string message) { Console.WriteLine(message); };
            }

            Race race = new Race(cars);

            race.Accident();
        }
    }
}