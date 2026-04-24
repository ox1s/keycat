#!/usr/bin/dotnet run
#:package System.IO.Ports@10.*

using System.IO.Ports;
using System.Runtime.InteropServices;

namespace Serial;

class Program
{

    // Source - https://stackoverflow.com/a/45638416
    // Posted by David Heffernan
    // Retrieved 2026-04-25, License - CC BY-SA 3.0

    [DllImport("user32.dll")]
    public static extern short GetAsyncKeyState(int vKey);

    static SerialPort port;
    static void Main(string[] args)
    {
        port = new SerialPort("COM3", 115200);
        port.Open();

        if (port.IsOpen)
        {
            Console.WriteLine("Running... Press Enter to stop.");

            Task.Run(() =>
            {
                while (port.IsOpen)
                {
                    if ((GetAsyncKeyState(0x20) & 0x8000) > 0)
                    {
                        port.Write("1");
                    }
                    Thread.Sleep(10);
                }
            });

            Console.ReadLine();
            port.Close();
        }
        else
        {
            Console.WriteLine("Port is unvailable");
        }
    }
}