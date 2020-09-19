using System;
using System.Reflection.Metadata;

namespace TransportProject
{
    public interface IEngine
    {   
        string EngineName { get; set; } 
        EngineType Type { get; set; }
        double Volume { get; set; }
        double Power { get; set; }    
        bool IsChipTuning { get; set; }
        
        enum EngineType
        {
            Gas = 1, Diesel
        }



        //Info
        void EngineInfo()
        {                        
            Console.WriteLine($"\tName: {EngineName}");
            Console.WriteLine($"\tType: {Type}");
            Console.WriteLine("\tVolume: {0} L", Volume.ToString("#.##"));
            Console.WriteLine("\tPower: {0} hp", Power.ToString("#.##"));            
        }



        //functions
        void ChangeEngine(string newEngineName, IEngine.EngineType newType, double newVolume,
                          double newPower, bool newIsChipTuning, Auto.EngineTune setEngine);        

        bool ChipTuning(Auto.ChipTune setChip);
    }
}