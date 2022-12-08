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
		XDocument doc = new XDocument(
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
						new XElement("tbody", null)
					)
				)
			)
		);
		Dictionary<string, Tuple<int, long>> fileInfo = new Dictionary<string, Tuple<int, long>>();
		foreach (string file in files) {
			FileInfo info = new FileInfo(file);
			string fileExt = info.Extension.ToLower();
			if (fileInfo.ContainsKey(fileExt)) {
				int count = fileInfo[fileExt].Item1 + 1;
				long size = fileInfo[fileExt].Item2 + info.Length;
				fileInfo.Remove(fileExt);
				fileInfo.Add(fileExt, new Tuple<int, long>(count, size));
				continue;
			}
			fileInfo.Add(fileExt, new Tuple<int, long>(1, info.Length));
		}
		foreach (string key in fileInfo.Keys) {
			doc.Element("html").Element("body").Element("table").Element("tbody").Add(
				new XElement("tr", 
					new XElement("td", key),
					new XElement("td", fileInfo[key].Item1),
					new XElement("td", FormatByteSize(fileInfo[key].Item2))
				)
			);
		}
		return doc;
	}

}