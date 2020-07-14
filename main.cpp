// STD
#include <iostream>
#include <string>

// UNIX & Linux
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

// ZCM
//#include <zcm/zcm.h>
#include <zcm/zcm-cpp.hpp>
#include "include/zcm_types/service/cpp_types/ZcmService.hpp"
//#include <msg_t.h>

//=======================================================================================
int main( int argc, char **argv )
{
	std::cout << " --- Star timer zcm" << std::endl;

	std::string channel_name = argv[1];

	float fps = atof( argv[2] );
	std::cout << fps << "\n";
	int delay = 1000000/fps;
	std::cout << delay << "\n";

	zcm::ZCM zcm_ipc("ipc");
	ZcmService msg;
	msg.u_timestamp = 0;
	msg.processing_time = 0;

	while(1)
	{
		msg.u_timestamp ++;
		msg.processing_time ++; 
		zcm_ipc.publish( channel_name, &msg );
		usleep(delay); // sleep for a second
	}

	return 0;
}
//=======================================================================================
