#include <server_stat.h>

void ServerStat::incrementStat() {
	++d_stat;
}

uint64_t ServerStat::getStat() {
	return d_stat;
}
