using System;

namespace Sauerbraten.Core.Utils
{
    public static class StringUtils
    {
        public static bool IsCommand(this string text, string command)
        {
            string arg;
            return IsCommand(text, command, out arg);
        }

        public static bool IsCommand(this string text, string command, out string arg)
        {
            if (text[0] != '#')
            {
                arg = null;
                return false;
            }

            var start = text.Substring(1).TrimStart(new[] { ' ' });
            if (!start.StartsWith(command, StringComparison.InvariantCultureIgnoreCase))
            {
                arg = null;
                return false;
            }

            arg = start.Substring(command.Length).TrimStart(new[] { ' ' });
            return true;
        }
    }
}