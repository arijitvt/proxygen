
#ifndef INCLUDE_SERVER_STAT
#define INCLUDE_SERVER_STAT

/***
 * @Author : Arijit Chattopadhyay
 ***/



#include <stdint.h>

class ServerStat {
	public:
		void incrementStat();
		uint64_t getStat();

	private:
		uint64_t d_stat{0};

};

#endif
