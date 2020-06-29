using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace Tetris
{
    interface IActor
    {
        Texture2D TextureToDraw { get; set; }
        Vector2 Position { get; set; }
    }
}
