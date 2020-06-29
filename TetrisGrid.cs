using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;

namespace Tetris
{
    class TetrisGrid
    {
        private List<Square> _squares;
        private int _height;
        private int _width;
        public TetrisGrid()
        {
            _squares = new List<Square>();
            _height = 15;
            _width = 10;
            int Count = 0;
            for (int i = 0; i < _width; i++)
            {
                for (int j = 0; j < _height; j++)
                {
                    _squares.Add(new Square());
                    _squares[Count].Position = new Vector2(i * 32.0f, j * 32.0f);
                    _squares[Count].TextureToDraw = TextureStore.WhiteSquare;
                    Count++;
                }
            }
        }

        public Square[] GetArraySquares()
        {
            return _squares.ToArray();
        }
    }
}
