using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace Tetris
{
    class GameDrawer
    {
        private SpriteBatch _spriteBatch;
        public GameDrawer()
        {
        }

        public void SetSpriteBatch()
        {
            _spriteBatch = TextureStore.SpriteBatch;
        }
        public void Draw(params IActor[] objectsToDraw)
        {
            if (_spriteBatch == null) SetSpriteBatch();

            foreach (IActor actor in objectsToDraw)
            {
                if (actor.TextureToDraw == null) actor.TextureToDraw = TextureStore.WhiteSquare;
                _spriteBatch.Draw(actor.TextureToDraw, actor.Position, Color.White);
            }
        }
    }
}
