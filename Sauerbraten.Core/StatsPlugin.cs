using System;
using System.Globalization;
using Sauerbraten.Core.Utils;
using Sauerbraten.Interfaces;

namespace Sauerbraten.Core
{
    public class StatsPlugin : BasePlugin
    {
        public override string Name { get { return "Stats"; } }

        public override bool OnText(int clientNumber, string text)
        {
            string arg;
            if (text.IsCommand("stats", out arg))
            {
                Server.SendPrivateMessage(clientNumber, "stats!");
                return false;
            }

            return base.OnText(clientNumber, text);
        }

        //TODO record stats
    }

}
