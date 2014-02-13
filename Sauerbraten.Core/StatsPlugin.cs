using System;
using Sauerbraten.Core.Utils;
using Sauerbraten.Interfaces;

namespace Sauerbraten.Core
{
    public class StatsPlugin : BasePlugin
    {
        public override string Name { get { return "Stats"; } }

        public override bool OnInit()
        {
            //TODO setup db connection + schedule saving
            return base.OnInit();
        }

        public override bool OnText(int clientNumber, string text)
        {
            string arg;
            if (!text.IsCommand("stats", out arg))
                return base.OnText(clientNumber, text);

            Server.SendPrivateMessage(clientNumber, string.Format(new ColouredFormatter(), "stats! {0:red} {1:blue}", "hello", string.IsNullOrEmpty(arg) ? "world" : arg));
            return false;
        }

        public override bool OnTeamkill(int actorClientNumber, int targetClientNumber)
        {
            throw new NotImplementedException();
        }
        public override bool OnFrag(int actorClientNumber, int targetClientNumber)
        {
            throw new NotImplementedException();
        }
        public override bool OnShot(int clientNumber, int weapon, int hits)
        {
            throw new NotImplementedException();
        }
        public override bool OnSuicide(int clientNumber)
        {
            throw new NotImplementedException();
        }
        public override bool OnSpawn(int clientNumber)
        {
            throw new NotImplementedException();
        }
        public override bool OnDamage(int actorClientNumber, int targetClientNumber, int damage, int weapon)
        {
            throw new NotImplementedException();
        }
        public override bool OnTakeFlag(int clientNumber, string team)
        {
            throw new NotImplementedException();
        }
        public override bool OnDropFlag(int clientNumber, string team)
        {
            throw new NotImplementedException();
        }
        public override bool OnScoreFlag(int clientNumber, string team, int score)
        {
            throw new NotImplementedException();
        }
        public override bool OnReturnFlag(int clientNumber, string team)
        {
            throw new NotImplementedException();
        }


        //TODO record stats
    }
}
