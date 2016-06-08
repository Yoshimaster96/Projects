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
			float a = ((float)x-128.0)/16.0;
			float b = (128.0-(float)y)/16.0;
			complex<float> z (a,b);
			complex<float> res = sin(z);
			float hue = 0.954929658551373*arg(res);
			if(hue<0.0) hue+=6.0;
			float lightness = atan(abs(res))*0.636619772367582;
			int r=0, g=0; b=0;
			float c = 1.0-abs(complex<float>(2.0*lightness-1.0,0.0));
			float m = lightness-(0.5*c);
			if(hue>=-0.01 && hue<1.0) {r=(int)((m+c)*255.0); g=(int)((m+c*hue)*255.0); b=(int)(m*255.0);}
			else if(hue>=1.0 && hue<2.0) {r=(int)((m+c*(2.0-hue))*255.0); g=(int)((m+c)*255.0); b=(int)(m*255.0);}
			else if(hue>=2.0 && hue<3.0) {g=(int)((m+c)*255.0); b=(int)((m+c*(-2.0+hue))*255.0); r=(int)(m*255.0);}
			else if(hue>=3.0 && hue<4.0) {g=(int)((m+c*(4.0-hue))*255.0); b=(int)((m+c)*255.0); r=(int)(m*255.0);}
			else if(hue>=4.0 && hue<5.0) {b=(int)((m+c)*255.0); r=(int)((m+c*(-4.0+hue))*255.0); g=(int)(m*255.0);}
			else if(hue>=5.0 && hue<6.01) {b=(int)((m+c*(6.0-hue))*255.0); r=(int)((m+c)*255.0); g=(int)(m*255.0);}
			out << r << " " << g << " " << b << "   ";
		}
	}
	out.close();
	return 0;
}
