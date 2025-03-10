#include "httpRequest.h"

int method_select(char *method) {
	if (strcmp(method, "GET") == 0) {
		return GET;
	}
	else if (strcmp(method, "POST") == 0) {
		return POST;
	}
	else if (strcmp(method, "PUT") == 0) {
		return PUT;
	}
	else if (strcmp(method, "HEAD") == 0) {
		return HEAD;
	}
	else if (strcmp(method, "PATCH") == 0) {
		return PATCH;
	}
	else if (strcmp(method, "DELETE") == 0) {
		return DELETE;
	}
	else if (strcmp(method, "CONNECT") == 0) {
		return CONNECT;
	}
	else if (strcmp(method, "OPTIONS") == 0) {
		return OPTIONS;
	}
	else if (strcmp(method, "TRACE") == 0) {
		return TRACE;
	}
}

struct httpRequest http_request_constructor(char *request_string) {
	struct httpRequest request;
	char requested[strlen(request_string)];
	strcpy(requested, request_string);
	for (int i = 0; i < strlen(requested) - 1; i++) {
		if (requested[i] == '\n' && requested[i + 1] == '\n') {
			printf("a/n");
			requested[i + 1] = '|';
		}
	}

	char* request_line = strtok(requested, "\n");
	char* header_fields = strtok(NULL, "|");
	char* body = strtok(NULL, "|");
	char* method = strtok(request_line, " ");
	request.Method = method_select(method);
	char* path = strtok(NULL, " ");
	request.Path = path;
	char* httpVersion = strtok(NULL, " ");
	httpVersion = strtok(httpVersion, "/");
	httpVersion = strtok(NULL, "/");
	request.httpVersion = (float)atof(httpVersion);

	return request;
}