#ifndef httpRequest_h
#define httpRequest_h

#include <string.h>
#include "../../datastructures/dictionary/dictionary.h"

enum httpMethod {
	GET,
	POST,
	PUT,
	HEAD,
	PATCH,
	DELETE,
	CONNECT,
	OPTIONS,
	TRACE
};

struct httpRequest {
	int Method;
	char* Path;
	float httpVersion;
};

struct httpRequest http_request_constructor(char *request_string);

#endif /* httpRequest_h */