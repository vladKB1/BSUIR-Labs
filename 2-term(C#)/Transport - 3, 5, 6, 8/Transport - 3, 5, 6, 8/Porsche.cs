using System;
using System.Security.Cryptography;

namespace TransportProject
{
    public class Porsche : Auto
    {        
        public PorscheModels Model { get; private set; }
       
        public enum PorscheModels
        {
            Porsche_911_Turbo_S = 1, Porsche_Panamera_Turbo
        }



        //Constructors
        public Porsche()
        {
        }

        public Porsche(PorscheModels model, string registrPlate, uint year, ConsoleColor color,
                       double cost, double mileage, double maxSpeed, double weight, uint seats, 
                       uint doors, TransmissionType transmission, DriveType driveTrain, double tank, double fuelConsumption,
                       string engineName, IEngine.EngineType type, double volume, double power, bool isChipTuning)
            : base(registrPlate, year, color, cost, mileage, maxSpeed, weight, seats, doors, transmission,
                   driveTrain, tank, fuelConsumption, engineName, type, volume, power, isChipTuning)      
        {
            Model = model;            
        }



        //Info
        public override void MainInfo()
        {
            Console.ForegroundColor = ConsoleColor.White;
            Console.WriteLine($"Information about the element at number {ListId} in the list:");
            Console.ResetColor();
            Console.WriteLine("\tModel: " + Model.ToString().Replace('_',' '));
            base.MainInfo();
        }



        //Auto
        public override TimeSpan FuelUp()
        {
            const double filingSpeed = 6.5;
            return TimeSpan.FromSeconds((Tank / filingSpeed));
        }

        public override TimeSpan TestDrive(double distance, out double averageSpeed, out double fuelings)
        {
            averageSpeed = MaxSpeed * (1 - Math.Min(0.6, Mileage * 0.0000009));            
            averageSpeed = Math.Max(MaxSpeed * 0.3, averageSpeed * (1 - RandomNumberGenerator.GetInt32(10000, 50000) / 100000.0));
            fuelings = distance / (Tank / FuelConsumption * 100.0);

            if (Seats != Doors)
            {
                averageSpeed *= 1.001;
            }
            if (Year > 2016)
            {
                averageSpeed *= 1.005;
            }

            TimeSpan time = TimeSpan.FromHours(distance / averageSpeed);
            time += fuelings * FuelUp();

            return time;
        }
    }
}