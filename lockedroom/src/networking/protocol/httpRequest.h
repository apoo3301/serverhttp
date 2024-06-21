#ifndef httpRequest_h
#define httpRequest_h

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../datastructures/dictionary/dictionary.h"

struct httpRequest {
	struct Dictionary request_line;
	struct Dictionary header_fields;
	struct Dictionary body;
};

struct httpRequest http_request_constructor(char *request_string);
void http_request_destructor(struct httpRequest *request);

#endif /* httpRequest_h */