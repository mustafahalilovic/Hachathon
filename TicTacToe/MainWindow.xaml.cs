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

namespace TicTacToe
{
    public partial class MainWindow : Window
    {

        #region Private Members

        /// <summary>
        /// Holds the current results of cells in the active game
        /// </summary>
        private MarkType[] Results;

        /// <summary>
        /// True if it's Player 1's turn (X) or false if it's Player 2's turn (O)
        /// </summary>
        private bool PlayerOneTurn;

        /// <summary>
        /// True if the game has endeed
        /// </summary>
        private bool GameEndeed;

        #endregion

        #region Constructor
        /// <summary>
        /// Default constructor
        /// </summary>
        public MainWindow()
        {
            InitializeComponent();
            NewGame();
        }


        #endregion

        #region Private Functions

        /// <summary>
        /// Starts a new game and clears all values back to the start
        /// </summary>
        private void NewGame()
        {
            // Create a new blank array of free cells
            Results = new MarkType[9];

            for (int i = 0; i < 9; i++)
                Results[i] = MarkType.Free;

            // Make sure it's Player 1's turn
            PlayerOneTurn = true;

            // Interate every button on the grid
            Container.Children.Cast<Button>().ToList().ForEach(button =>
            {
                // Set content, background and foreground to the default values
                button.Content = string.Empty;
                button.Background = Brushes.White;
                button.Foreground = Brushes.Blue;

            });

            // Make sure that game hasn't finish
            GameEndeed = false;

        }

        /// <summary>
        /// Handles a button click event
        /// </summary>
        /// <param name="sender">The button that was clicked</param>
        /// <param name="e">The events of the click</param>
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            // Starts new game on click after finishing game
            if(GameEndeed)
            {
                NewGame();
                return;
            }

            // Cast the sender to a button
            var button = (Button)sender;

            // Get column and row of button
            var column = Grid.GetColumn(button);
            var row = Grid.GetRow(button);

            // Get index of button
            var index = column + (row * 3);

            // Don't do anything if cell already has a value
            if (Results[index] != MarkType.Free)
                return;

            //Set the cell value base on which Players turn is
            if (PlayerOneTurn)
                Results[index] = MarkType.Cross;
            else
                Results[index] = MarkType.Nought;

            // Set button text
            if (PlayerOneTurn)
                button.Content = "X";
            else
                button.Content = "O";

            // If it is Player 2's turn, than O is black
            if (!PlayerOneTurn)
                button.Foreground = Brushes.Red;

            // Set Player turn
            /*if (PlayerOneTurn)
                 PlayerOneTurn = false;
             else
                 PlayerOneTurn = true;*/
            // Another way
            PlayerOneTurn ^= true;

            // Check for a winner
            CheckWinner();

        }

        /// <summary>
        /// Check if winner is O or X
        /// </summary>
        private void CheckWinner()
        {
            #region Horizontal Wins
            // Check for horizontal win
            // -- Row 0
            if (Results[0] != MarkType.Free && (Results[0] & Results[1] & Results[2]) == Results[0])
            {
                // Game ends
                GameEndeed = true;

                // Highlight winning cells in green
                Button0_0.Background = Button1_0.Background = Button2_0.Background = Brushes.Green;
            }
            // -- Row 1
            if (Results[3] != MarkType.Free && (Results[3] & Results[4] & Results[5]) == Results[3])
            {
                // Game ends
                GameEndeed = true;

                // Highlight winning cells in green
                Button0_1.Background = Button1_1.Background = Button2_1.Background = Brushes.Green;
            }
            // -- Row 2
            if (Results[6] != MarkType.Free && (Results[6] & Results[7] & Results[8]) == Results[6])
            {
                // Game ends
                GameEndeed = true;

                // Highlight winning cells in green
                Button0_1.Background = Button1_1.Background = Button2_1.Background = Brushes.Green;
            }

            #endregion

            #region Vertical Wins

            // Check for vertical win
            // -- Column 0
            if (Results[0] != MarkType.Free && (Results[0] & Results[3] & Results[6]) == Results[0])
            {
                // Game ends
                GameEndeed = true;

                // Highlight winning cells in green
                Button0_0.Background = Button0_1.Background = Button0_2.Background = Brushes.Green;
            }
            // -- Column 1
            if (Results[1] != MarkType.Free && (Results[1] & Results[4] & Results[7]) == Results[1])
            {
                // Game ends
                GameEndeed = true;

                // Highlight winning cells in green
                Button1_0.Background = Button1_1.Background = Button1_2.Background = Brushes.Green;
            }
            // -- Column 2
            if (Results[2] != MarkType.Free && (Results[2] & Results[5] & Results[8]) == Results[2])
            {
                // Game ends
                GameEndeed = true;

                // Highlight winning cells in green
                Button2_0.Background = Button2_1.Background = Button2_2.Background = Brushes.Green;
            }

            #endregion

            #region Diagonal Wins

            // Check for diagonal win
            // -- Diagonal 1
            if (Results[0] != MarkType.Free && (Results[0] & Results[4] & Results[8]) == Results[0])
            {
                // Game ends
                GameEndeed = true;

                // Highlight winning cells in green
                Button0_0.Background = Button1_1.Background = Button2_2.Background = Brushes.Green;
            }
            // -- Diagonal 2
            if (Results[6] != MarkType.Free && (Results[6] & Results[4] & Results[2]) == Results[6])
            {
                // Game ends
                GameEndeed = true;

                // Highlight winning cells in green
                Button0_2.Background = Button1_1.Background = Button2_0.Background = Brushes.Green;
            }

            #endregion

            #region No Wins

            // If there is no free cell
            if (!Results.Any(result => result == MarkType.Free) && GameEndeed!=true) // if there is no member in array that have value Free
            {
                // Game ended
                GameEndeed = true;

                //Higlight cells in orange
                Container.Children.Cast<Button>().ToList().ForEach(button =>
                {
                    // Set background 
                    button.Background = Brushes.Orange;
                });

            }

            #endregion
        }

        #endregion

    }
}
