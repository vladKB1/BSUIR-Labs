using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Runtime.CompilerServices;
using System.Security.Cryptography;
using System.Text.RegularExpressions;

namespace TransportProject
{
	public abstract class Transport : ICloneable
	{		
		public uint ListId { get; protected set; }						//unchangeable		
		public string RegistrPlate { get; private set; }				//changeable via SetRegistrPlate
		public uint Year { get; private set; }							//unchangeable
		public ConsoleColor Color { get; private set; }					//changeable via SetColor
		public double Cost { get; protected set; }						//changeable via SetCost
		public double Mileage { get; protected set; }					//changeable via RolledBackMileage
		public double MaxSpeed { get; protected set; }					//unchangeable
		public double Weight { get; protected set; }					//unchangeable

		public static uint CurrentObj = 0;
		public static uint AllObj = 0;

		public delegate double CalcMileage(double average);



		//Constructors
		public Transport()
		{
		}

		public Transport(string registrPlate, uint year, ConsoleColor color)
		{
			CurrentObj++;
			AllObj++;
			ListId = AllObj;

			RegistrPlate = registrPlate;
			Year = year;
			Color = color;			
		}

		public Transport(string registrPlate, uint year, ConsoleColor color,
						 double cost, double mileage, double maxSpeed, double weight)
			: this(registrPlate, year, color)
		{
			Cost = cost;
			Mileage = mileage;
			MaxSpeed = maxSpeed;
			Weight = weight;
		}



		//Info
		public virtual void MainInfo()
		{			
			Console.WriteLine($"\tIdentification number: {RegistrPlate}");
			Console.WriteLine($"\tYear of manufacture: {Year}");

			Console.Write("\tColor: ");
			Console.ForegroundColor = Color;
			Console.WriteLine(Color);
			Console.ResetColor();
		}

		public virtual void AdditionalInfo() 
		{
			Console.WriteLine("\tCost: {0} $", Cost.ToString("#.##"));
			Console.WriteLine("\tMileage: {0} km", Mileage.ToString("#.##"));
			Console.WriteLine("\tWeight: {0} kg", Weight.ToString("#.###"));
			Console.WriteLine("\tMax speed: {0} km/h", MaxSpeed.ToString("#.##"));
		}

		public virtual void FullInfo()
		{
			MainInfo();
			AdditionalInfo();
		}



		//Setters
		public void SetRegistrPlate(string newRegistrPlate)
		{
			if (newRegistrPlate.Length > 17)
			{				
				throw new ArgumentException("ERROR: The length is too large.");			
			}

			foreach (var ch in newRegistrPlate)
			{
				if (!((ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')))
				{		
					throw new Exception($"ERROR: Incorrect symbol \"{ch}\".");					
				}
			}

			RegistrPlate = newRegistrPlate;		
		}

		public void SetColor(ConsoleColor newColor)
			=> Color = newColor;
		
		public void SetCost(double newCost)
		{
			if (!(newCost >= 0 && newCost <= double.MaxValue))
			{
				throw new ArgumentException("ERROR: New cost is out of range.");
			}
			Cost = newCost;			
		}

		public void SetMileage(double newMileage)
		{
			if (newMileage < 0)
			{
				throw new ArgumentException("ERROR: Mileage can not be less than zero.");
			} 
			else if (newMileage < Mileage)
			{
				throw new Exception("DENIED: Reduce mileage is not legal operation!");
			}
			Mileage = newMileage;			
		}


		
		//functions
		public void RolledBackMileage(double average, CalcMileage calc)
		{
			if (Mileage < average)
			{
				throw new Exception("DENIED: Your mileage is less than average annual mileage.");			
			}
			Mileage = calc(average);			
		}



		//ICloneable
		public object Clone()
		{	
			Transport clone = (Transport)MemberwiseClone();
			CurrentObj++;
			AllObj++;
			clone.ListId = AllObj;
			return clone;
		}
	}
}