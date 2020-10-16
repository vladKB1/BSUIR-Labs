using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Linq;

namespace FileExplorer
{
    public partial class Form1 : Form
    {
        List<string> directoryListWay = new List<string>();
        List<(string, string)> copyListFiles = new System.Collections.Generic.List<(string, string)>();

        public Form1()
        {
            InitializeComponent();
            ChooseDrive();
        }

     

        //functions
        private string GetSize(long size)
        {
            if (size < 1024)
            {
                return $"{size} byte";
            }
            else if (size < 1024 * 1024)
            {
                return (size / 1024.0).ToString("#.##") + " KB";
            }
            else if (size < 1024 * 1024 * 1024)
            {
                return (size / 1024.0 / 1024.0).ToString("#.##") + " MB";
            }
            else
            {
                return (size / 1024.0 / 1024.0 / 1024.0).ToString("#.##") + " GB";
            }
        }
       
        private void Error(string message)
        {
            MessageBox.Show(message, "", MessageBoxButtons.OK, MessageBoxIcon.Error);
            return;
        }



        //moving through directories
        void ChooseDrive()
        {
            pathBox.Text = "";
            listView1.Items.Clear();

            DriveInfo[] drives = DriveInfo.GetDrives();

            foreach (DriveInfo drive in drives)
            {
                ListViewItem listViewItem = new ListViewItem(drive.Name);
                listViewItem.SubItems.Add("");
                listViewItem.SubItems.Add(drive.DriveType.ToString());
                listViewItem.SubItems.Add(((drive.TotalSize - drive.AvailableFreeSpace) / 1073741824.0).ToString("#.##") + " / " + (drive.AvailableFreeSpace / 1073741824.0).ToString("#.##") + " GB");
                listView1.Items.Add(listViewItem);
            }
        }

        private void ChooseDir(string path)
        {
            if (path == null)
            {
                ChooseDrive();
                return;
            }

            if (!Directory.Exists(path))
            {
                Error($"Windows can't find \'{path}\'. Check the spelling and try again.");
                return;
            }

            DirectoryInfo directoryInfo = new DirectoryInfo(path);
            try
            {
                directoryInfo.GetDirectories();
            }
            catch (UnauthorizedAccessException)
            {

                Error($"Access to the path '{path}' is denied.");
                return;
            }

            pathBox.Text = path;
            listView1.Items.Clear();

            foreach (DirectoryInfo dir in directoryInfo.GetDirectories())
            {
                ListViewItem listViewItem = new ListViewItem(dir.Name);
                listViewItem.SubItems.Add(dir.LastWriteTime.ToString("dd.mm.yyy HH:MM"));
                listViewItem.SubItems.Add("File folder");
                listViewItem.SubItems.Add("");
                listView1.Items.Add(listViewItem);
            }

            foreach (FileInfo file in directoryInfo.GetFiles())
            {
                ListViewItem listViewItem = new ListViewItem(file.Name);
                listViewItem.SubItems.Add(file.LastWriteTime.ToString("dd.mm.yyy HH:MM"));
                listViewItem.SubItems.Add($"{file.Extension.Trim('.')} file");
                listViewItem.SubItems.Add(GetSize(file.Length));
                listView1.Items.Add(listViewItem);
            }
        }

        private void listView1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            if (listView1.SelectedItems[0].SubItems[2].Text != "File folder"
                && listView1.SelectedItems[0].SubItems[2].Text != "Fixed")
            {
                Form2 f2 = new Form2();
                f2.Start(Path.Combine(pathBox.Text, listView1.SelectedItems[0].Text), this);
                ChooseDir(pathBox.Text);
                return;
            }

            directoryListWay.Clear();
            ChooseDir(Path.Combine(pathBox.Text, listView1.SelectedItems[0].Text).ToString());
        }

        private void goPathButton_Click(object sender, EventArgs e)
        {
            if (!Directory.Exists(pathBox.Text))
            {
                Error($"Windows can't find \'{pathBox.Text}\'. Check the spelling and try again.");
                return;
            }
            directoryListWay.Clear();
            ChooseDir(pathBox.Text);
        }

        private void pathBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                if (!Directory.Exists(pathBox.Text))
                {
                    Error($"Windows can't find \'{pathBox.Text}\'. Check the spelling and try again.");
                    return;
                }
                directoryListWay.Clear();
                ChooseDir(pathBox.Text);
            }
        }

        private void BackButton_Click(object sender, EventArgs e)
        {
            if (pathBox.Text == "")
            {
                return;
            }
            string parent = Directory.GetParent(pathBox.Text)?.ToString();
            directoryListWay.Add(pathBox.Text);
            ChooseDir(parent);
        }

        private void ForwardButton_Click(object sender, EventArgs e)
        {
            if (directoryListWay.Count == 0)
            {
                return;
            }

            string path = directoryListWay[directoryListWay.Count - 1];
            directoryListWay.RemoveAt(directoryListWay.Count - 1);
            ChooseDir(path);
        }



        //Context menu strips
        private void listView1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right && listView1.SelectedItems.Count != 0)
            {
                contextMenuStrip2.Show(Cursor.Position);
            } 
            else
            if (e.Button == MouseButtons.Right)
            {
                contextMenuStrip1.Show(Cursor.Position);
            }
        }



        //Rename
        private void listView1_AfterLabelEdit(object sender, LabelEditEventArgs e)
        {     
            if (e.Label == null)
            {
                return;
            }

            if (e.Label == "")
            {
                Error("The name of the file can't be empty.");
                e.CancelEdit = true;
                return;
            }

            string type = listView1.Items[e.Item].SubItems[2].Text;
            string sourceName = Path.Combine(pathBox.Text, listView1.Items[e.Item].Text).ToString();
            string distName = Path.Combine(pathBox.Text, e.Label).ToString();

            if (type == "File folder")
            {
                if (Directory.Exists(distName))
                {
                    Error($"This destination already contains a folder named '{e.Label}'.");
                    e.CancelEdit = true;
                    return;
                }
                Directory.Move(sourceName, distName);
            }
            else
            {
                if (File.Exists(distName))
                {
                    Error($"There is already a file with the same name in this location.");
                    e.CancelEdit = true;
                    return;
                }
                File.Move(sourceName, distName);
            }

            listView1.Items.Clear();
            ChooseDir(pathBox.Text);            
        }
     
        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {
            listView1.SelectedItems[0].BeginEdit();
        }



        //Create new files
        private void toolStripMenuItem6_Click(object sender, EventArgs e)
        {
            if (pathBox.Text == "")
            {
                Error("You can't create any file in the window of disk viewer.");
                return;
            }

            string folderName = "New folder";
            string fullPath = Path.Combine(pathBox.Text, folderName).ToString();
            int i = 2;
            while (Directory.Exists(fullPath)) 
            {
                folderName = $"New folder ({i})";
                fullPath = Path.Combine(pathBox.Text, folderName).ToString();
                i++;
            }

            Directory.CreateDirectory(fullPath);
            DirectoryInfo dir = new DirectoryInfo(fullPath);
            ListViewItem listViewItem = new ListViewItem(dir.Name);
            listViewItem.SubItems.Add(dir.LastWriteTime.ToString("dd.mm.yyy hh:mm"));
            listViewItem.SubItems.Add("File folder");
            listViewItem.SubItems.Add("");
            listView1.Items.Add(listViewItem);

            listView1.Items[listView1.Items.Count - 1].BeginEdit();
            
        }

        private void toolStripMenuItem7_Click(object sender, EventArgs e)
        {
            if (pathBox.Text == "")
            {
                Error("You can't create any file in the window of disk viewer.");
                return;
            }

            string fileName = "New file.txt";
            string fullPath = Path.Combine(pathBox.Text, fileName).ToString();
            int i = 2;
            while (File.Exists(fullPath))
            {
                fileName = $"New file ({i}).txt";
                fullPath = Path.Combine(pathBox.Text, fileName).ToString();
                i++;
            }

            File.Create(fullPath).Close();
            FileInfo file = new FileInfo(fullPath);
            ListViewItem listViewItem = new ListViewItem(file.Name);
            listViewItem.SubItems.Add(file.LastWriteTime.ToString("dd.mm.yyy hh:mm"));
            listViewItem.SubItems.Add($"{file.Extension.Trim('.')} file");
            listViewItem.SubItems.Add(GetSize(file.Length));
            listView1.Items.Add(listViewItem);

            listView1.Items[listView1.Items.Count - 1].BeginEdit();
            
        }


        
        //delete files
        private void toolStripMenuItem2_Click(object sender, EventArgs e)
        {
            if (pathBox.Text == "")
            {
                Error("You can't delete any file in the window of disk viewer.");
                return;
            }

            foreach (ListViewItem viewItem in listView1.SelectedItems)
            {
                if (viewItem.SubItems[2].Text == "File folder")
                {
                    Directory.Delete(Path.Combine(pathBox.Text, viewItem.Text).ToString(), true);
                } 
                else
                {
                    File.Delete(Path.Combine(pathBox.Text, viewItem.Text).ToString());
                }
            }

            ChooseDir(pathBox.Text);
        }



        //copy files
        private void toolStripMenuItem4_Click(object sender, EventArgs e)
        {
            if (pathBox.Text == "")
            {
                Error("You can't copy any file in the window of disk viewer.");
                return;
            }

            copyListFiles.Clear();

            foreach (ListViewItem viewItem in listView1.SelectedItems)
            {
                copyListFiles.Add((viewItem.SubItems[2].Text, Path.Combine(pathBox.Text, viewItem.Text).ToString()));
            }            
        }



        //paste files
        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (pathBox.Text == "")
            {
                Error("You can't paste any file in the window of disk viewer.");
                return;
            }

            foreach ((string, string) copies in copyListFiles)
            {
                string path = pathBox.Text + "\\" + copies.Item2.Trim('\\').Split('\\').Last();

                if (copies.Item1 == "File folder")
                {
                    while (Directory.Exists(path))
                    {
                        path = path + " - Copy";
                    }

                    DirectoryInfo sourceDir = new DirectoryInfo(copies.Item2);
                    DirectoryInfo distDir = new DirectoryInfo(path);
                    Directory.CreateDirectory(path);

                    Paste(sourceDir, distDir);
                }
                else
                {                       
                    string ext = "." + path.Split('.').Last();
                    while (Directory.Exists(path))
                    {
                        path = path + " - Copy";
                    }

                    File.Copy(copies.Item2, path + ext);
                }

                ChooseDir(pathBox.Text);
            }

            void Paste(DirectoryInfo sourseDir, DirectoryInfo distDir)
            {
                foreach(DirectoryInfo dir in sourseDir.GetDirectories()) 
                {
                    Paste(dir, distDir.CreateSubdirectory(dir.Name));
                }
                foreach(FileInfo file in sourseDir.GetFiles())
                {
                    file.CopyTo(Path.Combine(distDir.FullName, file.Name));
                }
            }
        }



        //Archive
        private void toolStripMenuItem9_Click(object sender, EventArgs e)
        {
            foreach (ListViewItem viewItem in listView1.SelectedItems)
            {
                if (viewItem.SubItems[2].Text == "File folder")
                {
                    ZipFile.CreateFromDirectory(Path.Combine(pathBox.Text, viewItem.Text).ToString(),
                                Path.Combine(pathBox.Text, viewItem.Text).ToString() + ".zip");
                }
            }

            ChooseDir(pathBox.Text);
        }



        //Extract
        private void toolStripMenuItem8_Click(object sender, EventArgs e)
        {
            foreach (ListViewItem viewItem in listView1.SelectedItems)
            {

                if (viewItem.SubItems[2].Text == "zip file")
                {
                    string path = Path.Combine(pathBox.Text, viewItem.Text).ToString();
                    string extractPath = path.Substring(0, path.Length - 4);
                    try
                    {
                        ZipFile.ExtractToDirectory(path, extractPath + " - ext");
                    }
                    catch
                    {
                        Error("The process was interrupted. Archive is damaged.");
                    }
                }
            }

            ChooseDir(pathBox.Text);
        }

        private void toolStripMenuItem5_Click(object sender, EventArgs e)
        {

        }
    }
}

/*
BackgroundColor = #191919
ListViewer/ListBox Color = #202020
*/
