using System;
using System.Globalization;

namespace Sauerbraten.Core.Utils
{
    public class ColouredFormatter : IFormatProvider, ICustomFormatter
    {
        public object GetFormat(Type formatType)
        {
            return formatType == typeof(ICustomFormatter) ? this : null;
        }

        public string Format(string fmt, object arg, IFormatProvider formatProvider)
        {
            switch (fmt.ToUpper())
            {
                case "GREEN": return string.Format("\fs\f{0}{1}\fr", 0, arg);
                case "BLUE": return string.Format("\fs\f{0}{1}\fr", 1, arg);
                case "YELLOW": return string.Format("\fs\f{0}{1}\fr", 2, arg);
                case "RED": return string.Format("\fs\f{0}{1}\fr", 3, arg);
                case "GREY": return string.Format("\fs\f{0}{1}\fr", 4, arg);
                case "MAGENTA": return string.Format("\fs\f{0}{1}\fr", 5, arg);
                case "ORANGE": return string.Format("\fs\f{0}{1}\fr", 6, arg);
                case "WHITE": return string.Format("\fs\f{0}{1}\fr", 7, arg);
                default:
                    return HandleDefault(fmt, arg);
            }
        }

        private string HandleDefault(string fmt, object arg)
        {
            var formattable = arg as IFormattable;
            if (formattable != null)
                return formattable.ToString(fmt, CultureInfo.CurrentCulture);

            return arg != null ? arg.ToString() : String.Empty;
        }
    }
}