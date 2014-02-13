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
            if (!text.IsCommand("stats", out arg))
                return base.OnText(clientNumber, text);

            Server.SendPrivateMessage(clientNumber, string.Format(new ColouredFormatter(), "stats! {0:red} {1:blue}", "hello", string.IsNullOrEmpty(arg) ? "world" : arg));
            return false;
        }

        //TODO record stats
    }
}
