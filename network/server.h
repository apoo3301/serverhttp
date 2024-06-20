#ifnedf server_h
#define server_h

#include <sys/socket.h>
#include <netinet/in.h>


struct Server {
	int domains;
	int service;
	int protocol;
	u_long interface;
	int port;
	int backlog;
	struct sockadd_in address;
	void (*launch)(void);
};

struct Server server_constructor(int domain, int service, int protocol, u_long interface, int port, int backlog, void(*launch)(void));

#endif