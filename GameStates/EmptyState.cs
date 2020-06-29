using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace Tetris.GameStates
{
    class EmptyState : IState
    {
        private GameDrawer _gameDrawer;
        private TetrisGrid _grid;
        public EmptyState()
        {
            _gameDrawer = new GameDrawer();
            _grid = new TetrisGrid();
        }
        public void Execute(GameTime gameTime)
        {
            
        }

        public void Draw(GameTime gameTime)
        {
            _gameDrawer.Draw(_grid.GetArraySquares());
        }
    }
}
