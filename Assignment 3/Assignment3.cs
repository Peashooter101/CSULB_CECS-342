using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Xml.Linq;

class Assignment3 {
	public static void Main(string[] args) {
		if (args.Length > 1) {
			CreateReport(EnumerateFilesRecursively(args[0])).Save(args[1]);
		} else {
			Console.Write("Not enough command line arguments provided.");
		}
	}

	static IEnumerable<string> EnumerateFilesRecursively(string path) {
		foreach (string dir in Directory.GetDirectories(path)) {
			foreach (string file in EnumerateFilesRecursively(dir)) {
				yield return file;
			}
		}
		foreach (string file in Directory.GetFiles(path)) {
			yield return file;
		}
	}

	static string FormatByteSize(long byteSize) {
		if (byteSize == 0) return "0B";
		string[] units = {"B", "kB", "MB", "GB", "TB", "PB", "EB"};
		int unitMultiplier = 0;
		double size = byteSize;
		while ((size/1000.0 > 1) && unitMultiplier < units.Length-1) {
			size /= 1000.0;
			unitMultiplier++;
		}
		return size.ToString("#.##") + units[unitMultiplier];
	}

	static XDocument CreateReport(IEnumerable<string> files) {
		return new XDocument(
			new XElement ("html",
				new XElement("head",
					new XElement("title", "File Report"),
					new XElement("style", "table, th, td { border: 1px solid black; }")
				),
				new XElement("body",
					new XElement("table",
						new XElement("thead",
							new XElement("tr",
								new XElement("th", "Type"),
								new XElement("th", "Count"),
								new XElement("th", "Total Size")
							)
						),
						new XElement("tbody", 
							from ext in files.GroupBy(
								file => Path.GetExtension(file).ToLower())
									.OrderByDescending(
										grouping => grouping.Sum(file => new FileInfo(file).Length)
									)
							select new XElement("tr",
								new XElement("td", ext.Key),
								new XElement("td", ext.Count()),
								new XElement("td", FormatByteSize(
										files.Where(file => Path.GetExtension(file) == ext.Key)
										.Sum(file => new FileInfo(file).Length)
									)
								)
							)
						)
					)
				)
			)
		);
	}
}