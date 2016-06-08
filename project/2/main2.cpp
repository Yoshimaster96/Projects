#include <iostream>
#include <fstream>
#include <complex>

using namespace std;

int main()
{
	ofstream out;
	out.open("output.ppm",ios::out|ios::trunc);
	out << "P3 \n256 256 \n255 \n";
	for(int y=0; y<256; y++)
	{
		for(int x=0; x<256; x++)
		{
			float a = ((float)x-128.0)/32.0;
			float b = (128.0-(float)y)/32.0;
			complex<float> z (a,b);
			complex<float> res = sin(z);
			float red = 0.5 + atan(real(res))*0.318309886183791;
			float green = 0.5 + atan(imag(res))*0.318309886183791;
			int r = (int)(red*255.0);
			int g = (int)(green*255.0);
			out << r << " " << g << " 0   ";
		}
	}
	out.close();
	return 0;
}
