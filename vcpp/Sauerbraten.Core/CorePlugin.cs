using System;
using Sauerbraten.Interfaces;

namespace Sauerbraten.Core
{
    public class CorePlugin : BasePlugin
    {
        public override string Name
        {
            get { return "Core"; }
        }

        public override bool OnInit()
        {
            Console.WriteLine("init (from C#!)");

            return base.OnInit();
        }
    }
}
