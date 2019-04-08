#ifndef UNIT_H
#define UNIT_H
#include <string>

namespace ariel {	
		enum class Unit{
			 CM,M,KM,SEC,MIN,HOUR,G,KG,TON
		};
		const static double yahas[9] = {1,100,100000,1,60,3600,1,1000,1000000};
	    const static std::string type[9] = {"[cm]","[m]","[km]","[sec]","[min]","[hour]","[g]","[kg]","[ton]"};
}

#endif
