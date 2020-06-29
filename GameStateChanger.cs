using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tetris
{
    class GameStateChanger
    {
        private IState _currentState;
        public GameStateChanger(IState initCurrentState)
        {
            _currentState = initCurrentState;
        }

        public void SetState(IState state) => _currentState = state;

        public IState GetCurrentState() => _currentState;
    }
}
