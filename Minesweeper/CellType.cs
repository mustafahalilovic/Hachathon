using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Minesweeper
{
    public enum CellType
    {
        /// <summary>
        /// Cell is free
        /// </summary>
        Free,
        
        /// <summary>
        /// Cell has a flag
        /// </summary>
        Flag,

        /// <summary>
        /// Cell has a bomb
        /// </summary>
        Bomb

    }
}
