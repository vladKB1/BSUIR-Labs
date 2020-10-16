using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FileExplorer
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();            
        }

        Form sender;
        StreamReader sr;
        StreamWriter sw;
        string path;

        public void Start(string path, Form sender)
        {
            Visible = true;
            this.sender = sender;
            sender.Enabled = false;
            this.path = path;

            using (sr = new StreamReader(path))
            {
                richTextBox1.Text = sr.ReadToEnd();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            using (sw = new StreamWriter(path))
            {
                sw.Write(richTextBox1.Text);
            }
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            Close();
        }

        private void Exit(object sender, FormClosedEventArgs e)
        {
            this.sender.Enabled = true;
        }       
    }
}
