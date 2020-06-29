using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace Tetris
{
    static class TextureStore
    {
        public static Texture2D WhiteSquare { get; private set;  }
        public static Texture2D BlueSquare { get; private set;  }
        public static Texture2D GreenSquare { get; private set;  }
        public static Texture2D OrangeSquare { get; private set;  }
        public static Texture2D PurpleSquare { get; private set;  }
        public static Texture2D RedSquare { get; private set;  }
        public static Texture2D TealSquare { get; private set;  }
        public static Texture2D YellowSquare { get; private set;  }
        public static SpriteBatch SpriteBatch { get; set; }

        public static void LoadContent(Microsoft.Xna.Framework.Content.ContentManager content)
        {
            WhiteSquare = content.Load<Texture2D>("Squares/WhiteSquare");
            BlueSquare = content.Load<Texture2D>("Squares/BlueSquare");
            GreenSquare = content.Load<Texture2D>("Squares/GreenSquare");
            OrangeSquare = content.Load<Texture2D>("Squares/OrangeSquare");
            PurpleSquare = content.Load<Texture2D>("Squares/PurpleSquare");
            RedSquare = content.Load<Texture2D>("Squares/RedSquare");
            TealSquare = content.Load<Texture2D>("Squares/TealSquare");
            YellowSquare = content.Load<Texture2D>("Squares/YellowSquare");
        }
    }
}
