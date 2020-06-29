using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tetris
{
    class Square : IActor
    {
        public Square()
        {
        }

        public Square(Texture2D texture, Vector2 position)
        {
            TextureToDraw = texture;
            Position = position;
        }
        public Texture2D TextureToDraw { get; set; }
        public Vector2 Position { get; set; }
    }
}
