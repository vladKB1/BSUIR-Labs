using System;
using System.Collections.Specialized;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Security.Cryptography;
using System.Threading;
using System.Threading.Tasks.Dataflow;

namespace TransportProject
{
    public abstract class Auto : Transport, IEngine, IComparable<Auto>
    {       
        public uint Seats { get; private set; }
        public uint Doors { get; private set; }
        public TransmissionType Transmission { get; private set; }
        public DriveType DriveTrain { get; private set; }
        public double Tank { get; private set; }
        public double FuelConsumption { get; private set; }

        public delegate void ChipTune(ref double a, ref double b);
        public delegate void EngineTune(ref double a, ref double b,
                                        double c, double d);
        public delegate void Situation(string message);

        public event Situation Crashed;
        public event Situation Survived;

        public enum TransmissionType
        {
            Manual = 1, Automatic, CVT              //3 - Continuously Variable Transmission
        }
        
        public enum DriveType
        {
            RWD = 1, FWD, AWD                       //Rear Wheel Drive, Front Wheel Drive, All-Wheel Drive
        }



        //Constructors
        public Auto()
        {
        }
      
        public Auto(string registrPlate, uint year, ConsoleColor color, double cost, 
                    double mileage, double maxSpeed, double weight, uint seats, uint doors, 
                    TransmissionType transmission, DriveType driveTrain, double tank, double fuelConsumption,
                    string engineName, IEngine.EngineType type, double volume, double power, bool isChipTuning)
            : base(registrPlate, year, color, cost, mileage, maxSpeed, weight)
        {            
            Seats = seats;
            Doors = doors;
            Transmission = transmission;
            DriveTrain = driveTrain;
            Tank = tank;
            FuelConsumption = fuelConsumption;

            EngineName = engineName;
            Type = type;
            Volume = volume;
            Power = power;
            IsChipTuning = isChipTuning;
        }



        //Info
        public override void MainInfo()
        {
            base.MainInfo();
            Console.WriteLine("\tCost: {0} $", Cost.ToString("#.##"));
            Console.WriteLine("\tMileage: {0} km", Mileage.ToString("#.##"));
        }

        public override void AdditionalInfo()
        {
            Console.ForegroundColor = ConsoleColor.DarkGray;
            Console.WriteLine("\t-----  Additional information -----");
            Console.ResetColor();

            Console.WriteLine($"\tSeats: {Seats}");
            Console.WriteLine($"\tDoors: {Doors}");
            Console.WriteLine("\tWeight: {0} kg", Weight.ToString("#.###"));
            Console.WriteLine("\tMax speed: {0} km/h", MaxSpeed.ToString("#.##"));
            Console.WriteLine($"\tType of transmission: {Transmission}");
            Console.WriteLine($"\tType of drivetrain: {DriveTrain}");
            Console.WriteLine("\tTank: {0} L", Tank.ToString("#.##"));
            Console.WriteLine("\tFuel consumption: {0} L/100km", FuelConsumption.ToString("#.##"));

            Console.ForegroundColor = ConsoleColor.DarkGray;
            Console.WriteLine("\t-----  Engine specifications -----");
            Console.ResetColor();
            ((IEngine)this).EngineInfo();
        }



        //functions
        public abstract TimeSpan FuelUp();

        public abstract TimeSpan TestDrive(double distance, out double averageSpeed,
                                           out double fuelings);
        


        //IEngine
        public string EngineName { get; set; }
        public IEngine.EngineType Type { get; set; }
        public double Volume { get; set; }
        public double Power { get; set; }
        public bool IsChipTuning { get; set; }

        //Setter
        public double SetDouble(double newDouble)
        {
            if (!(newDouble >= 0 && newDouble <= double.MaxValue))
            {
                throw new ArgumentException("ERROR: New double is out of range.");
            }
            return newDouble;
        }

        //IEngine functions
        public virtual bool ChipTuning(ChipTune setChip)
        {
            if (IsChipTuning)
            {
                return false;
            }
            
            double newMaxSpeed = MaxSpeed;
            double newPower = Power;
            setChip(ref newMaxSpeed, ref newPower);

            IsChipTuning = true;
            MaxSpeed = newMaxSpeed;
            Power = newPower;
            return true;
        }
            
        public void ChangeEngine(string newEngineName, IEngine.EngineType newType, double newVolume,
                                 double newPower, bool newIsChipTuning, EngineTune setEngine)   
        {
            double newMileage = Mileage;
            double newMaxSpeed = MaxSpeed;
            setEngine(ref newMileage, ref newMaxSpeed, Power, newPower);      
            
            Mileage = newMileage;
            MaxSpeed = newMaxSpeed;
            EngineName = newEngineName;
            Type = newType;
            Volume = SetDouble(newVolume);
            Power = SetDouble(newPower);
            IsChipTuning = newIsChipTuning;           
        }
        

        
        //event function
        public void Crash(double distance, TimeSpan time, double place)
        {            
            string? model = this is Porsche ? ((Porsche)this).Model.ToString().Replace("_", " ") : null;
            model ??= this is Lamborghini ? ((Lamborghini)this).Model.ToString().Replace("_", " ") : null;
            model ??= this is Bugatti ? ((Bugatti)this).Model.ToString().Replace("_", " ") : null;            

            TestDrive(distance, out double averageSpeed, out double fuelings);
            double traveld = averageSpeed * (time.TotalSeconds / 3600.0);                

            if (Math.Abs(traveld - place) < 10)
            {
                Crashed?.Invoke($"{model} with car number {RegistrPlate} crashed :(");
            } 
            else
            {
                Survived?.Invoke($"{model} with car number {RegistrPlate} did not have an accident and survived!");
            }
        }



        //IComparable
        public int CompareTo(Auto auto)
            => TestDrive(100, out _, out _).CompareTo(auto.TestDrive(100, out _, out _));        
    }
}