using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Minesweeper
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        #region Private Members

        /// <summary>
        /// Holds current results of cells in active game
        /// </summary>
        private CellType[] CellType;

        /// <summary>
        /// True if game has endeed
        /// </summary>
        private bool GameEndeed;

        /// <summary>
        /// Holds index of bomb places when new game starts
        /// </summary>
        private int[] randomBombIndexes;

        /// <summary>
        /// How many numbers have one bomb
        /// </summary>
        private int[] numberOfNumbers;

        /// <summary>
        /// Hold index of numbers that we have on board
        /// </summary>
        private int[] numberOfIndexes;

        /// <summary>
        /// Hold values of bomb numbers(1,2, 3, ...)
        /// </summary>
        private int[] valueOfIndexes;

        /// <summary>
        /// TODO:
        /// FINISH COMMENTING
        /// </summary>
        private int counter
		private int n1;
		private int n;
		private int c;


        #endregion

        #region Constructor
        /// <summary>
        /// Default constructor
        /// </summary>
        public MainWindow()
        {
            InitializeComponent();
			//NewGame();
        }

        #endregion

        #region Private Functions

        /// <summary>
        /// Starts a new game and clears all values back to the start
        /// </summary>
        private void NewGame()
        {
            // Create new blank array of free cells
            Results = new CellType[100];

            // Game hasn't endeed
            GameEndeed = false;

			// Interate every button on the grid
			Container.Children.Cast<Button>().ToList().ForEach(button =>
			{
				// Set content, background and foreground to the default values
				button.Content = string.Empty;
				button.Background = Brushes.LightGreen;
				button.BorderBrush = Brushes.Green;

			});

			// Find 10 random numbers and store them to array
			// This numbers represent indexes on board where we want to have bombs
			/*Random rnd = new Random();
            for(int i = 0; i < 10; i++)
            {
                randomBombIndexes[i] = rnd.Next(0, 100);
            }

			/*
			//---------------------------------------------------------------------
			counter = 0;
			n = 11;
			n1 = 9;
			for (int i = 0; i < 10; i++)
			{
				if ((randomBombIndexes[i] % 10 == 0) || ((randomBombIndexes[i] - 9) % 10 == 0))
					numberOfNumbers[i] = 5;
				else
					numberOfNumbers[i] = 8;
			}
			for (int i = 0; i < 10; i++)
			{
				c += numberOfNumbers[i];
			}
			int numberOfIndexes[c], valueOfIndexes[99];
			for (int i = 0; i < 100; i++)
				valueOfIndexes[i] = 0;

			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 100; j++)
				{
					if (randomBombIndexes[i] == j)
						valueOfIndexes[j] = 9;
				}
			}
			//-------------------------
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < numberOfNumbers[i]; j++)
				{
					// Hand settings
					if (randomBombIndexes[i] == 0)
					{
						numberOfIndexes[counter] = 1;
						numberOfIndexes[counter + 1] = 10;
						numberOfIndexes[counter + 2] = 11;
						numberOfIndexes[counter + 3] = 20;
						numberOfIndexes[counter + 4] = 21;
						counter += 5;
						j = numberOfNumbers[i];
					}
					if (randomBombIndexes[i] == 9)
					{
						numberOfIndexes[counter] = 8;
						numberOfIndexes[counter + 1] = 18;
						numberOfIndexes[counter + 2] = 19;
						numberOfIndexes[counter + 3] = 28;
						numberOfIndexes[counter + 4] = 29;
						counter += 5;
						j = numberOfNumbers[i];
					}
					if (randomBombIndexes[i] == 90)
					{
						numberOfIndexes[counter] = 70;
						numberOfIndexes[counter + 1] = 71;
						numberOfIndexes[counter + 2] = 80;
						numberOfIndexes[counter + 3] = 81;
						numberOfIndexes[counter + 4] = 91;
						counter += 5;
						j = numberOfNumbers[i];
					}
					if (randomBombIndexes[i] == 99)
					{
						numberOfIndexes[counter] = 78;
						numberOfIndexes[counter + 1] = 79;
						numberOfIndexes[counter + 2] = 88;
						numberOfIndexes[counter + 3] = 89;
						numberOfIndexes[counter + 4] = 98;
						counter += 5;
						j = numberOfNumbers[i];
					}
					//---------------------------------------------

					if (randomBombIndexes[i] != 99 && randomBombIndexes[i] != 9 && randomBombIndexes[i] != 0 && randomBombIndexes[i] != 90)
					{
						// Somewhere in bottom
						if (numberOfNumbers[i] == 8)
						{
							if (j == 0) n = 11;
							if (j == 5) n1 = 9;

							if (j < 3)
							{
								numberOfIndexes[counter] = randomBombIndexes[i] - n;
								n--;
							}
							else if (j == 3)
							{
								numberOfIndexes[counter] = randomBombIndexes[i] - 1;
							}
							else if (j == 4)
							{
								numberOfIndexes[counter] = randomBombIndexes[i] + 1;
							}
							else
							{
								numberOfIndexes[counter] = randomBombIndexes[i] + n1;
								n1++;
							}
						}
						//---------------------------------------------------------------

						// 5 right
						if (numberOfNumbers[i] == 5 && randomBombIndexes[i] % 10 == 0)
						{
							if (j == 0) n = 10;
							if (j == 3) n1 = 10;

							if (j < 2)
							{
								numberOfIndexes[counter] = randomBombIndexes[i] - n;
								n--;
							}
							else if (j == 2)
							{
								numberOfIndexes[counter] = randomBombIndexes[i] + 1;
							}
							else
							{
								numberOfIndexes[counter] = randomBombIndexes[i] + n1;
								n1++; // 9
							}
						}
						//------------------------------------------------------------

						// 5 - left
						if (i == 4 && randomBombIndexes[i] % 10 != 0)
						{
							if (j == 0) n = 11;
							if (j == 3) n1 = 9;

							if (j < 2)
							{
								numberOfIndexes[counter] = randomBombIndexes[i] - n;
								n--; // 11
							}
							else if (j == 2)
							{
								numberOfIndexes[counter] = randomBombIndexes[i] - 1;
							}
							else
							{
								numberOfIndexes[counter] = randomBombIndexes[i] + n1;
								n1++; // 9
							}
						}
						//----------------------------------------------------------------

						counter++;
					}
				}
			}

			int br = 0;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < numberOfNumbers[i]; j++)
				{
					for (int k = 0; k < 100; k++)
					{
						if (numberOfIndexes[br] == k && valueOfIndexes[k] != 9)
							valueOfIndexes[k]++;
					}
					br++;
				}
			}*/



		}

        #endregion

    }
}
