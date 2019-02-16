using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PAW___Curs_3_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            this.sqlDataAdapter1.Fill(dataSet1);
            dataGridView1.DataSource = dataSet1;
            dataGridView1.DataMember = dataSet1.Tables[0].TableName;
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            DataSet schimbat = dataSet1.GetChanges();
            if (schimbat != null) this.sqlDataAdapter1.Update(schimbat);
        }
    }
}
