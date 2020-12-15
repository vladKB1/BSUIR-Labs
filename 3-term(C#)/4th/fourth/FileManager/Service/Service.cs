using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Linq;
using System.ServiceProcess;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace FileManager
{
    public partial class Service : ServiceBase
    {
        FileManager fileManager;        

        public Service()
        {
            InitializeComponent();
            this.CanStop = true;
            this.CanPauseAndContinue = true;
            this.AutoLog = true;
        }

        protected override void OnStart(string[] args)
        {
            fileManager = new FileManager();                      
            Thread fileManagerThread = new Thread(new ThreadStart(fileManager.Start));
            fileManagerThread.Start();            
        }

        protected override void OnStop()
        {
            fileManager.Stop();
            Thread.Sleep(1000);           
        }
    }
}
